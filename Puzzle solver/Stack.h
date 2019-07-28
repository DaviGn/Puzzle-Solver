#pragma once
#include "List.h"

//Esta classe representa uma pilha de objetos e as possíveis operações desta estrutura
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

//Método responsável por inserir um valor na pilha
template<typename T>
void Stack<T>::Push(T* object) {
	this->Insert(object);
}

//Método responsável por retirar o último elemento da pilha
template<typename T>
T* Stack<T>::Pop() {
	return this->TakeFirst();
}

//Métodos responsável por retorna o topo da pilha
template<typename T>
Element<T>* Stack<T>::Top() {
	if (this->IsEmpty())
		return NULL;

	return this->First();
}
