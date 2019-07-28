#pragma once
#include "List.h"

//Esta classe representa uma pilha de objetos e as poss�veis opera��es desta estrutura
template<typename T>
class Stack : public List<T> {
public:
	Stack();
	~Stack();
	void Push(T* object);
	T* Pop();
	Element<T>* Top();
};

//Construtor
template<typename T>
Stack<T>::Stack() : List<T>::List() {
}

//Destrutor
template<typename T>
Stack<T>::~Stack() {
	this->~List();
}

//M�todo respons�vel por inserir um valor na pilha
template<typename T>
void Stack<T>::Push(T* object) {
	this->Insert(object);
}

//M�todo respons�vel por retirar o �ltimo elemento da pilha
template<typename T>
T* Stack<T>::Pop() {
	return this->TakeFirst();
}

//M�todos respons�vel por retorna o topo da pilha
template<typename T>
Element<T>* Stack<T>::Top() {
	if (this->IsEmpty())
		return NULL;

	return this->First();
}
