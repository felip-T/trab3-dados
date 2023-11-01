#ifndef HANOI_H
#define HANOI_H

#include "pilha.h"
#include <string>
#include <iostream>

class hanoi {
public:
  hanoi(unsigned);
  ~hanoi();
  void solve();

private:
  void print();
	Pilha<unsigned> *p[3];
	void move(unsigned, unsigned);
	void solver(unsigned, unsigned, unsigned, unsigned);
	std::string printP(unsigned);
};

#endif
