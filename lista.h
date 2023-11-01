#include <iostream>

using namespace std;


template<class T>
class C_Lista;

template<class T>
class C_No_lst_encadeada_simples {
  T dado;
  C_No_lst_encadeada_simples *prox;
  friend class C_Lista<T>;

public:
  C_No_lst_encadeada_simples(T p_dado) {
    dado = p_dado;
    prox = nullptr;
  }
};

template<class T>
class C_Lista {
  C_No_lst_encadeada_simples<T> *inicio;

public:
	void cp(C_Lista<T> &p);
  C_Lista() : inicio(nullptr){}
	~C_Lista();
  void insere_no_inicio(T p_dado);
	void insere_no_final(T p_dado);
  void percorre_lista(void);
	T pop();
	T at(unsigned);
};

template <class T>
C_Lista<T>::~C_Lista() {
	C_No_lst_encadeada_simples<T> *aux;
	while (inicio){
		aux = inicio;
		inicio = inicio->prox;
		delete aux;
	}
}

template <class T>
void C_Lista<T>::cp(C_Lista<T> &p) {
	inicio = nullptr;
	C_No_lst_encadeada_simples<T> *aux = p.inicio;
	while (aux) {
		insere_no_final(aux->dado);
		aux = aux->prox;
	}
}

template<class T>
T C_Lista<T>::at(unsigned idx){
	C_No_lst_encadeada_simples<T> *aux = inicio;
	for (unsigned i = 0; i < idx; i++) {
		aux = aux->prox;
	}
	return aux->dado;
}

template<class T>
T C_Lista<T>::pop() {
	C_No_lst_encadeada_simples<T> *aux = inicio;
	T dado = aux->dado;
	inicio = inicio->prox;
	delete aux;
	return dado;
}

template<class T>
void C_Lista<T>::insere_no_final(T p_dado){
	if (inicio == nullptr) {
		inicio = new C_No_lst_encadeada_simples<T>(p_dado);
		return;
	}
	C_No_lst_encadeada_simples<T> *novo_no = new C_No_lst_encadeada_simples<T>(p_dado);
	C_No_lst_encadeada_simples<T> *aux = inicio;
	while (aux->prox) {
		aux = aux->prox;
	}
	aux->prox = novo_no;
}

template<class T>
void C_Lista<T>::insere_no_inicio(T p_dado) {
  C_No_lst_encadeada_simples<T> *novo_no;
  novo_no = new C_No_lst_encadeada_simples<T>(p_dado);
  if (inicio != nullptr)
    novo_no->prox = inicio;
  inicio = novo_no;
}

template<class T>
void C_Lista<T>::percorre_lista(void) {
  C_No_lst_encadeada_simples<T> *aux = inicio;
  while (aux)
  {
    cout << aux->dado << endl;
    aux = aux->prox;
  }
}
