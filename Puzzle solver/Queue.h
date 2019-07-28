#pragma once
#include "List.h"

//Esta classe representa uma fila de objetos e as poss�veis opera��es desta estrutura
template<typename T>
class Queue : public List<T> {
public:
	Queue();
	~Queue();
	void Enqueue(T* object);
	T* Dequeue();
	T* Peek();
};

//Construtor
template<typename T>
Queue<T>::Queue() : List<T>::List() {
}

//Destrutor
template<typename T>
Queue<T>::~Queue() {
	this->~Lista();
}

//M�todo respons�vel por inserir um elemento no final da fila
template<typename T>
void Queue<T>::Enqueue(T* object) {
	this->Insert(object);
}

//M�todo respons�vel por remover o elemento que est� no in�cio da fila
template<typename T>
T* Queue<T>::Dequeue() {
	return this->TakeLast();
}

//M�todo respons�vel por retornar o valor do elemento que est� na frente da fila
template<typename T>
T* Queue<T>::Peek() {
	return this->First();
}