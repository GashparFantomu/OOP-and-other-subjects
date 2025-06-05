#pragma once
#include <iostream> 
#include <cstdio>

using namespace std;

class CA
{
public: int x;
	  CA() { x = 1;   printf("\nCAI %d", x); }
	  CA(int x0) { x = x0;  printf("\nCAE %d", x); }
	  CA(CA& p) { x = p.x; printf("\nCAC %d", x); }
	  void operator+(CA& p) { x = p.x; printf("\nAOP= %d", x); }
	  ~CA() { printf("\nDA %d", x); }
	  void met1(int r) { printf("\nMTE1A %d %d", x, r); met2(r); met3(r); }
	  void met2(int r) { printf("\nMET2A %d %d", x, r); }
	  virtual	  void met3(int r) { printf("\nMET3A %d %d", x, r); }
};

CA Incremeneaza(CA x, CA& y, CA z, CA& t)
{
	CA r; printf("\n++++");
	x.x++; y.x++; z.x++; t.x++;		r.x = x.x + y.x + z.x + t.x;
	return r;
}

class CB :public CA
{
public: int y;
	  CB() { y = 2; printf("\nCBI %d %d", x, y); }
	  ~CB() { printf("\nDB %d %d", x, y); }
	  CB(int x0, int y0 = 3);
	  int operator+(int p) { printf("\n BOP + i"); return(x + p + 1); }
	  int operator+(CB& p) { printf("\nVOP + A");  return (x + p.x); }
	  friend   int operator+(CB& o1, CB& o2) { printf("\nBOP + B"); return(o1.x + o2.x); }
	  void operator=(CB& p) { y = p.x; printf("\nBOP= %d %d", x, y); }
	  void met2(int r) { printf("\nMET2B %d %d", x, r); }
	  virtual void met3(int r) { printf("\nMET3B %d %d", x, r); }
};

struct CC : public CA
{
	CA a;
	CC(int x0) { x = x0; printf("\nCCE %d %d", x, a.x); }
	~CC() { printf("\nDC %d %d", x, a.x); }
};

CB::CB(int x0, int y0) :CA(x0 + 4)
{
	y = y0 + 5; printf("\nCBE %d %d", x, y);
}

CA a, b(10); CB c, * i, d(11, 12);


int main()
{
	CA e(13), * f, g = d; CB h(14); CC* x;
	printf("\nSTART");
	f = new CA(20); i = new CB(21, 22);
	b.met1(31); d.met1(32);
	printf("\nOP %d %d %d %d"/*, d + b, h + d*/, h.x + 2, d + 1);
	printf("\nXYZT %d %d %d %d", a.x, b.x, e.x, g.x);
	g = Incremeneaza(a, b, e, g);
	printf("\nXYZT %d %d %d %d", a.x, b.x, e.x, g.x);
	delete f; delete i;
	d = h; printf("\nd=h %d %d %d %d", d.x, d.y, e.x, d.y, h.x, h.y);
	(cout << endl << c.x) << 2 << c.y << "<<" << (c.x << 2) << c.y;
	x = new CC(22); delete x;
	printf("\nSTOP");
}