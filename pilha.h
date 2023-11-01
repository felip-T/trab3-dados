#include "lista.h"

template <class T> class Pilha {
public:
  Pilha(unsigned n) : top(0), max(n) {}
  Pilha(Pilha<T> &p) : top(p.top), max(p.max) {
    arr.cp(p.arr);
  }
  void push(T x) {
    if (full())
      throw 2;
    top++;
		arr.insere_no_inicio(x);
  }
  T pop() {
    if (empty())
      throw 1;
		--top;
    return arr.pop();
  }
  void swap() {
    T aux = arr.pop();
		T aux2 = arr.pop();
		arr.insere_no_inicio(aux);
		arr.insere_no_inicio(aux2);
  }
  T &peak() {
    if (empty())
      throw 1;
    return arr.get(0);
  }
  bool empty() { return top == 0; }
  bool full() { return top == max; }
  unsigned size() { return top; }
  unsigned capacity() { return max; }

private:
  C_Lista<T> arr;
  unsigned top;
  unsigned max;
};
