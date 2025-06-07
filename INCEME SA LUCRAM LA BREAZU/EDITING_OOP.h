#pragma once
#include <iostream> 
#include <cstdio>

using namespace std;

class CA
{
public: int x;
	  CA() { x = 1;   printf("\nCAI %d", x); }
	  CA(int x0) { x = x0;  printf("\nCAE %d", x); }
	  ~CA() { printf("\nDA %d", x); }
	  void met1(int r) { printf("\nMTE1A %d %d", x, r); met2(r); met3(r); }
	  void met2(int r) { printf("\nMET2A %d %d", x, r); }
	  virtual	  void met3(int r) { printf("\nMET3A %d %d", x, r); }
};


class CB :public CA
{
public: int y;
	  CB() { y = 2; printf("\nCBI %d %d", x, y); }
	  ~CB() { printf("\nDB %d %d", x, y); }
	  CB(int x0, int y0 = 3); //parametru implicit
	  void met2(int r) { printf("\nMET2B %d %d", x, r); }
	  virtual void met3(int r) { printf("\nMET3B %d %d", x, r); }
};


CB::CB(int x0, int y0) :CA(x0 + 4) {
	y = y0 + 5; printf("\nCBE %d %d", x, y);
}

CA a, b(10); CB c, * i, d(11, 12);


int main()
{
	CA e(13), * f, g = d; CB h(14);


	b.met1(31); d.met1(32);

	printf("\nSTOP");
}