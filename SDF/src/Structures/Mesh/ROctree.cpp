// ROctree.cpp : subor obsahujuci zakladnu ROctree strukturu
#include "stdafx.h"
#include "ROctree.h"
#include "MathHelper.h"

namespace MeshStructures
{
	enum Flags
	{
		FLAG0 = 0x0,
		FLAG1 = 0x1,
		FLAG2 = 0x2,
		FLAG4 = 0x4,
		FLAG8 = 0x8
	};
	ROctree::ROctree(const int dep, const float siz, Vector4 ori)
	{
		// Front half			Back half (viewed from front)
		// -----------------	-----------------
		// |       |       |	|       |       |
		// |   2   |   6   |	|   3   |   7   |
		// |       |       |	|       |       |
		// -----------------	-----------------
		// |       |       |	|       |       |
		// |   0   |   4   |	|   1   |   5   |
		// |       |       |	|       |       |
		// -----------------	-----------------
		// x smeruje doprava, y smeruje hore, z ODOMNA!! - bacha opengl ma Z inak
		// tabulka offsetov
		depth = dep;	// root ma 1, najnizsi list ma Nastavenia->OCTREE_Depth
		size = siz;
		origin = ori;
		value = 0.0f;
		value_center = Vector4();
		count = 0;

		son = new ROctree* [8];
		sons = 0;
	}

	ROctree::~ROctree()
	{
		if(!isLeaf())
		{
			for(int i = 0; i < 8; i++)
			{
					delete son[i];
			}
		}
		delete [] son;
	}

	void ROctree::Build(PPoint** pointiky, unsigned int length)
	{
		if(length == 0)
			return;

		count = length;
		if((depth >= Nastavenia->OCTREE_Depth) || (length <= Nastavenia->OCTREE_Threshold))
		{
			value = 0.0f;
			value_center = Vector4();
			for(unsigned int i = 0; i < length; i++)
			{
				value += pointiky[i]->diameter;
				value_center = value_center + pointiky[i]->P;
			}
			value = value / (float)length;
			value_center = value_center / (float)length;
		}
		else
		{
			float Table[8][3] =
			{
				{-1.0, -1.0, -1.0},
				{-1.0, -1.0, +1.0},
				{-1.0, +1.0, -1.0},
				{-1.0, +1.0, +1.0},
				{+1.0, -1.0, -1.0},
				{+1.0, -1.0, +1.0},
				{+1.0, +1.0, -1.0},
				{+1.0, +1.0, +1.0}
			};
			int new_depth = depth + 1;
			float new_size = size / 2.0f;

			LinkedList<PPoint>** son_pointiky = new LinkedList<PPoint>* [8];
			for(unsigned int i = 0; i < 8; i++)
				son_pointiky[i] = NULL; // preistotu

			// zisti kam papointiky trojuholniky
			for(unsigned int i = 0; i < length; i++)
			{
				byte code = GetCode(pointiky[i]->P);

				if(son_pointiky[code] == NULL)
					son_pointiky[code] = new LinkedList<PPoint>(pointiky[i]);
				else
					son_pointiky[code]->InsertToEnd(pointiky[i]);
			}


			// vytvor ROctree a uloz ich tam
			for(int i = 0; i < 8; i++)
			{
				Vector4 tmpv = Vector4(origin.X + new_size*Table[i][0],
									   origin.Y + new_size*Table[i][1],
									   origin.Z + new_size*Table[i][2]);
				son[i] = new ROctree(new_depth, new_size, tmpv);

				unsigned int velkost = (son_pointiky[i] == NULL ? 0 : son_pointiky[i]->GetSize());
				PPoint** tmp_zoznam = NULL;
				if(velkost > 0)
				{
					tmp_zoznam = new PPoint* [velkost];

					LinkedList<PPoint>::Cell<PPoint>* tmp = son_pointiky[i]->start;
					for(unsigned int j = 0; j < velkost; j++)
					{
						tmp_zoznam[j] = tmp->data;
						tmp = tmp->next;
					}
				}
				son[i]->Build(tmp_zoznam, velkost);
				if(velkost > 0)
					sons |= (unsigned char)(1 << i);
			}

			// zmazanie pola, kedze vytvaram vlastne
			delete [] pointiky;

			// zmazanie pomocnych poli kedze som urobil vlastne
			for(unsigned int i = 0; i < 8; i++)
			{
				delete son_pointiky[i];
				son_pointiky[i] = NULL;		// preistotu
			}
			delete [] son_pointiky;
		}
	}
	#define SQRT_THREE 1.7320508075f
	void ROctree::Build2(PPoint** pointiky, unsigned int start, unsigned int length, unsigned int &NodeCount, unsigned int &PointCount, unsigned int &LeafCount)
	{
		NodeCount = 0;
		PointCount = 0;
		LeafCount = 0;

		if(length == 0)
			return;

		value = 0.0f;
		value_center = Vector4();
		for(unsigned int i = 0; i < length; i++)
		{
			value += pointiky[start+i]->diameter;
			value_center = value_center + pointiky[start+i]->P;
		}
		value = value / (float)length;
		value_center = value_center / (float)length;
		count = length;
		if((depth >= Nastavenia->OCTREE_Depth) || (length <= Nastavenia->OCTREE_Threshold) || ((value * 0.5) >= size * SQRT_THREE))
		{
			/*value = 0.0f;
			for(unsigned int i = 0; i < length; i++)
				value += pointiky[start+i]->diameter;
			value = value / (float)length;*/

			PointCount = count;
			NodeCount = 1;
			LeafCount = 1;
		}
		else
		{
			float Table[8][3] =
			{
				{-1.0, -1.0, -1.0},
				{-1.0, -1.0, +1.0},
				{-1.0, +1.0, -1.0},
				{-1.0, +1.0, +1.0},
				{+1.0, -1.0, -1.0},
				{+1.0, -1.0, +1.0},
				{+1.0, +1.0, -1.0},
				{+1.0, +1.0, +1.0}
			};
			unsigned int nodeCount = 1;
			unsigned int pointCount = 0;
			unsigned int leafCount = 0;
			int new_depth = depth + 1;
			float new_size = size / 2.0f;

			int tabulka[8][2];			// start, size
			for(unsigned int i = 0; i < 8; i++)
			{
				tabulka[i][0] = start;
				tabulka[i][1] = 0;
			}
			// zisti kam papointiky trojuholniky
			unsigned int cislo = (unsigned int)pow((long double)2, (int)depth);
			for(unsigned int i = start; i < start+length; i++)
			{
				byte code = GetCode(pointiky[i]->P);
				InserToEnd(pointiky, i, code, tabulka);
			}

			// vytvor ROctree a uloz ich tam
			for(unsigned int i = 0; i < 8; i++)
			{
				Vector4 tmpv = Vector4(origin.X + new_size*Table[i][0],
									   origin.Y + new_size*Table[i][1],
									   origin.Z + new_size*Table[i][2]);
				son[i] = new ROctree(new_depth, new_size, tmpv);

				son[i]->Build2(pointiky, tabulka[i][0], tabulka[i][1], NodeCount, PointCount, LeafCount);
				if(tabulka[i][1] > 0)
					sons |= (unsigned char)(1 << i);
				nodeCount += NodeCount;
				pointCount += PointCount;
				leafCount += LeafCount;
			}
			NodeCount = nodeCount;
			PointCount = pointCount;
			LeafCount = leafCount;
		}
	}

	bool ROctree::CheckValid(int num)
	{
		return((sons >> num) & 1);
	}

	void ROctree::DoValueSmoothing()
	{
		if(isLeaf())
			return;

		/*unsigned int weight = 0;
		value = 0.0f;
		for(int i = 0; i < 8; i++)
		{
			if(CheckValid(i) == true)
			{
				son[i]->DoValueSmoothing();
				value += son[i]->value * son[i]->count;
				weight += son[i]->count;
			}
		}
		value = value / (float)weight;*/
		for(int i = 0; i < 8; i++)
		{
			if(CheckValid(i) == true)
			{
				son[i]->value = son[i]->value * 4.0f + value;
				son[i]->value = son[i]->value * 0.20f;
			}
		}
	}

	void ROctree::InserToEnd(PPoint** pointiky, unsigned int idx, byte code, int (&tabulka)[8][2])
	{
		bool added = tabulka[code][1] > 0 ? false : true;

		PPoint* ftmp = pointiky[tabulka[code][0]];

		pointiky[tabulka[code][0]] = pointiky[idx];

		pointiky[idx] = ftmp;

		tabulka[code][1] += 1;
		FwdMove(pointiky, idx, code+1, tabulka, added);
	}

	void ROctree::FwdMove(PPoint** pointiky, unsigned int idx, byte code, int (&tabulka)[8][2], bool added)
	{
		if(code >= 8)
			return;
		if(added == false)
		{
			if(tabulka[code][1] > 0)
			{
				PPoint* ftmp = pointiky[tabulka[code][0]];

				pointiky[tabulka[code][0]] = pointiky[idx];

				pointiky[idx] = ftmp;
			}
			tabulka[code][0] += 1;
		}
		else
		{
			if(tabulka[code][1] > 0)
			{
				PPoint* ftmp = pointiky[tabulka[code][0] + tabulka[code][1]];

				pointiky[tabulka[code][0] + tabulka[code][1]] = pointiky[idx];

				pointiky[idx] = ftmp;
			}
			tabulka[code][0] += 1;
		}
		FwdMove(pointiky, idx, code+1, tabulka, added);
	}

	// vrati poziciu v ROctree
	byte ROctree::GetCode(const Vector4 pt)
	{
		byte result = FLAG0;
		if (pt.X > origin.X) result |= FLAG4;
		if (pt.Y > origin.Y) result |= FLAG2;
		if (pt.Z > origin.Z) result |= FLAG1;

		return result;
	}

	void ROctree::GetBoundary(float &siz, float &x, float &y, float &z)
	{
		siz = size;
		x = origin.X;
		y = origin.Y;
		z = origin.Z;
	}

	void ROctree::DrawOctree(bool recursive)
	{
		float Table[8][3] =
		{
			{-1.0, -1.0, -1.0},
			{-1.0, -1.0, +1.0},
			{-1.0, +1.0, -1.0},
			{-1.0, +1.0, +1.0},
			{+1.0, -1.0, -1.0},
			{+1.0, -1.0, +1.0},
			{+1.0, +1.0, -1.0},
			{+1.0, +1.0, +1.0}
		};

		/*if((recursive == true) && (depth > 5))
			return;*/
		if((count == 0) && (isLeaf() == true))
			return;
		if(isLeaf() == true)
		{
		GLubyte r = 0, g = 0, b = 0;
		float valu = log(((value) / (Nastavenia->DEBUG_Max_SDF)) * 4.0f + 1.0f) / log(4.0f + 1.0f);
		HLSToRGB(valu, r, g, b);
		glColor4ub(r, g, b, Nastavenia->VISUAL_Alpha);

		glBegin(GL_LINES);
			glVertex3f(origin.X + size*Table[0][0], origin.Y + size*Table[0][1], origin.Z + size*Table[0][2]);
			glVertex3f(origin.X + size*Table[1][0], origin.Y + size*Table[1][1], origin.Z + size*Table[1][2]);

			glVertex3f(origin.X + size*Table[0][0], origin.Y + size*Table[0][1], origin.Z + size*Table[0][2]);
			glVertex3f(origin.X + size*Table[2][0], origin.Y + size*Table[2][1], origin.Z + size*Table[2][2]);

			glVertex3f(origin.X + size*Table[0][0], origin.Y + size*Table[0][1], origin.Z + size*Table[0][2]);
			glVertex3f(origin.X + size*Table[4][0], origin.Y + size*Table[4][1], origin.Z + size*Table[4][2]);

			glVertex3f(origin.X + size*Table[3][0], origin.Y + size*Table[3][1], origin.Z + size*Table[3][2]);
			glVertex3f(origin.X + size*Table[7][0], origin.Y + size*Table[7][1], origin.Z + size*Table[7][2]);
			
			glVertex3f(origin.X + size*Table[3][0], origin.Y + size*Table[3][1], origin.Z + size*Table[3][2]);
			glVertex3f(origin.X + size*Table[2][0], origin.Y + size*Table[2][1], origin.Z + size*Table[2][2]);

			glVertex3f(origin.X + size*Table[3][0], origin.Y + size*Table[3][1], origin.Z + size*Table[3][2]);
			glVertex3f(origin.X + size*Table[1][0], origin.Y + size*Table[1][1], origin.Z + size*Table[1][2]);

			glVertex3f(origin.X + size*Table[6][0], origin.Y + size*Table[6][1], origin.Z + size*Table[6][2]);
			glVertex3f(origin.X + size*Table[7][0], origin.Y + size*Table[7][1], origin.Z + size*Table[7][2]);

			glVertex3f(origin.X + size*Table[6][0], origin.Y + size*Table[6][1], origin.Z + size*Table[6][2]);
			glVertex3f(origin.X + size*Table[2][0], origin.Y + size*Table[2][1], origin.Z + size*Table[2][2]);

			glVertex3f(origin.X + size*Table[6][0], origin.Y + size*Table[6][1], origin.Z + size*Table[6][2]);
			glVertex3f(origin.X + size*Table[4][0], origin.Y + size*Table[4][1], origin.Z + size*Table[4][2]);

			glVertex3f(origin.X + size*Table[5][0], origin.Y + size*Table[5][1], origin.Z + size*Table[5][2]);
			glVertex3f(origin.X + size*Table[7][0], origin.Y + size*Table[7][1], origin.Z + size*Table[7][2]);

			glVertex3f(origin.X + size*Table[5][0], origin.Y + size*Table[5][1], origin.Z + size*Table[5][2]);
			glVertex3f(origin.X + size*Table[1][0], origin.Y + size*Table[1][1], origin.Z + size*Table[1][2]);

			glVertex3f(origin.X + size*Table[5][0], origin.Y + size*Table[5][1], origin.Z + size*Table[5][2]);
			glVertex3f(origin.X + size*Table[4][0], origin.Y + size*Table[4][1], origin.Z + size*Table[4][2]);
		glEnd();
		}
		if((isLeaf() == false) && (recursive == true))
		{
			for(int i = 0; i < 8; i++)
			{
				son[i]->DrawOctree(recursive);
			}
		}
	}

	void ROctree::HLSToRGB(float SDF_value, GLubyte &R, GLubyte &G, GLubyte &B)
	{
		//#pragma comment( lib, "shlwapi.lib" )  // needed for the ColorHLSToRGB() function

		int hue, lum, sat;
		hue = int(SDF_value * 240.0);
		lum = 120; //int(SDF_value * 120.0);
		sat = 240;

		COLORREF rgbColor = ColorHLSToRGB( hue, lum, sat );
		R = GetRValue(rgbColor);
		G = GetGValue(rgbColor);
		B = GetBValue(rgbColor);
		//logInfo(MarshalString("value: " + SDF_value + ", R: " + R + ", G: "+G+", B: "+B));
	}

	void ROctree::DrawAxes()
	{
		glBegin(GL_LINES);
			glColor3f(1.0f,0.0f,0.0f);							// cervena farba
			glVertex3f(origin.X, origin.Y, origin.Z);
			glVertex3f(origin.X + 2.0f * size, origin.Y, origin.Z);

			glColor3f(0.0f,1.0f,0.0f);							// zelena farba
			glVertex3f(origin.X, origin.Y, origin.Z);
			glVertex3f(origin.X, origin.Y + 2.0f * size, origin.Z);

			glColor3f(0.0f,0.0f,1.0f);							// modra farba
			glVertex3f(origin.X, origin.Y, origin.Z);
			glVertex3f(origin.X, origin.Y, origin.Z + 2.0f * size);
		glEnd();
	}
}