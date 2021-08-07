#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> pad;
int width, len;

void square(int w,int x,int y)
{
				//printf("square %d %d %d\n",w,x,y);
				int i,j;
				for (i = x; i < x + w; i++)
				{
								for (j = y; j < y + w; j++)
								{
												pad[j][i] = 'X';
								}
				}
				return;
}
void triangle(int w, int x, int y, int faces)
{
				//printf("triangle %d %d %d %d\n", w, x, y,faces);
				int i=x, j=y, tempi, tempj;
				switch (faces)
				{
				case 0:
				{
								for (int temp = w,i = x; i >=x - w; i--,temp--)
								{
												for (j = y; j > y-temp; j--)
												{
																pad[j][i] = 'X';
												}
								}
								break;
				}
				case 1:
				{
								for (int temp = w,i = x; i >= x - w; i--,temp--)
								{
												for (j = y; j < y + temp; j++)
												{
																pad[j][i] = 'X';
												}
								}
								break;
				}
				case 2:
				{
								for (int temp = w,i = x; i <= x + w; i++,temp--)
								{
												for (j = y; j > y - temp; j--)
												{
																pad[j][i] = 'X';
												}
								}
								break;
				}
				case 3:
				{
								for (int temp = w,i = x; i <= x + w; i++,temp--)
								{
												for (j = y; j < y + temp; j++)
												{
																pad[j][i] = 'X';
												}
								}
								break;
				}
				}
				return;
}
void line(int x, int y, int x2, int y2)
{
				//printf("line %d %d %d %d\n",x,y,x2,y2);
				int i,j;
				int deltax=1,deltay=1;
				if (x > x2)
				{
								deltax = -1;
				}
				else if (x == x2)
								deltax = 0;
				if (y > y2)
				{
								deltay = -1;
				}
				else if (y == y2)
								deltay = 0;
				i = x;
				j = y;
				for (i = x, j = y; i != x2 || j != y2; i += deltax, j += deltay)
				{
								pad[j][i] = 'X';
				}
				pad[j][i] = 'X';
				return;
}
void show()
{
				unsigned i, j;
				for (i = 0; i < len; i++)
				{
								string tmp;
								for (j = 0; j < width; j++)
								{
												//tmp += pad[i][j];
												cout << pad[i][j];
								}
								cout << tmp<<endl;
				}
				//cout << endl;
}
bool oversize(const int x, const int y)
{
				if (x < 0 || y < 0 || x >= width || y >= len)
				{
								cout << "Out of range." << endl;
								return 0;
				}
				else
								return 1;
}
bool oversize(const char lr, const char ud)
{
				if ((lr == 'L' || lr == 'R') && (ud == 'U' || ud == 'D'))
				{
								return 1;
				}
				else 
								return 0;
}
int main()
{
				char shape,lr,ud;
				int w, x, y,x2,y2,i,faces;
				cin >> width >> len;
				pad.resize(len);
				for (i = 0; i < len; i++)
				{
								pad[i].resize(width,'*');
				}
				while (cin >> shape)
				{
								switch (shape)
								{
								case 'S':
								{
												cin >> w >> x >> y;
												if (oversize(x, y) == 1&&oversize(x+w-1,y+w-1))
												{
																square(w, x, y);
																show();
												}
												break;
								}
								case 'T':
								{
												cin >> w >> x >> y >>lr>>ud;
												if (oversize(x, y)==1&&oversize(lr,ud)==1)
												{
																if (lr == 'L')
																{
																				if (ud == 'U')//LU
																				{
																								faces = 0;
																								if (oversize(x+1 - w, y+1 - w) == 0)
																												break;
																				}
																				else//LD
																				{
																								faces = 1;
																								if (oversize(x+1 - w, y-1 + w) == 0)
																												break;
																				}
																}
																else
																{
																				if (ud == 'U')//RU
																				{
																								faces = 2;
																								if (oversize(x-1 + w, y+1 - w) == 0)
																												break;
																				}
																				else//RD
																				{
																								faces = 3;
																								if (oversize(x-1 + w, y+1 + w) == 0)
																												break;
																				}
																}
																triangle(w, x, y, faces);
																show();
												}
												break;
								}
								case 'L':
								{
												cin >> x >> y >> x2 >> y2;
												if (oversize(x, y)==1&& oversize(x2, y2)==1)
												{
																line(x, y, x2, y2);
																show();
												}
												break;
								}
								default:
												return 0;
												break;
								}
								cout << endl;
				}
				
}