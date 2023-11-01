#include "hanoi.h"

hanoi::hanoi(unsigned n) {
  for (unsigned i = 0; i < 3; i++)
    p[i] = new Pilha<unsigned>(n);
  for (unsigned i = n; i > 0; i--)
    p[0]->push(i);
}

hanoi::~hanoi() {
  for (unsigned i = 0; i < 3; i++)
    delete p[i];
}

void hanoi::move(unsigned a, unsigned b){
	p[b]->push(p[a]->pop());
}

void hanoi::solver(unsigned n, unsigned a, unsigned b, unsigned aux){
	if(n == 1){
		move(a, b);
		print();
	}else{
		solver(n-1, a, aux, b);
		move(a, b);
		print();
		solver(n-1, aux, b, a);
	}
}

void hanoi::solve(){
	print();
	solver(p[0]->size(), 0, 2, 1);
}

std::string hanoi::printP(unsigned n){
	std::string s = "";
	Pilha<unsigned> aux(*p[n]);
	unsigned tam = aux.capacity();

	for (unsigned i=0; i<(tam - aux.size()); i++)
		s += std::string(tam, ' ') + '|' + std::string(tam, ' ') + '\n';
	while(!aux.empty()){
		unsigned x = aux.pop();
		s += std::string((tam-x),' ') + std::string(x,'#') + "|" + std::string(x, '#') + std::string(tam-x, ' ') + "\n";
}

	return s;
}

void hanoi::print(){
	static int num=0;
	std::string s0, s1, s2;
	s0 = printP(0);
	s1 = printP(1);
	s2 = printP(2);
	unsigned pos = s0.find('\n');
	std::cout <<"\npasso "<< num++ << ":\n";
	for (unsigned i = 0; i < p[0]->capacity(); i++){
		std::cout << s0.substr(i*(pos)+i, pos) << ' ' << s1.substr(i*(pos)+i, pos) << " " <<  s2.substr(i*(pos)+i, pos) << std::endl;
	}
}
