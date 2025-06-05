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
};

CA Incremeneaza(CA x, CA& y, CA z, CA& t) //baaaaaa, se copiaza doar a si e pentru ca y si t au referinta si nu se copiaza
{//sa fi atent, pentru x si z si r se apeleaza deconstructor, prima data la obiectul local si dupa la parametru
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
};


CB::CB(int x0, int y0) :CA(x0 + 4) {
	y = y0 + 5; printf("\nCBE %d %d", x, y);
}

CA a, b(10); CB c, * i, d(11, 12);


int main()
{
	CA e(13), * f, g = d; CB h(14);
	printf("\nSTART");
	f = new CA(20); i = new CB(21, 22);
	g = Incremeneaza(a, b, e, g);
	printf("\nXYZT %d %d %d %d", a.x, b.x, e.x, g.x);
	printf("\nSTOP");
}