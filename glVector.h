#include <iostream>

using namespace std;

class GLvector
{
private:
  float       x;
  float       y;
  float       z;
public:
	GLvector()
	{
		x=0;
		y=0;
		z=0;
	}
	GLvector(int a, int b, int c)
	{
		x=a;
		y=b;
		z=c;
	}
	~GLvector ();

};