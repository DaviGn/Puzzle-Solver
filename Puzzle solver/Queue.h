#pragma once
#include "List.h"

//Esta classe representa uma fila de objetos e as possíveis operações desta estrutura
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

//Método responsável por inserir um elemento no final da fila
template<typename T>
void Queue<T>::Enqueue(T* object) {
	this->Insert(object);
}

//Método responsável por remover o elemento que está no início da fila
template<typename T>
T* Queue<T>::Dequeue() {
	return this->TakeLast();
}

//Método responsável por retornar o valor do elemento que está na frente da fila
template<typename T>
T* Queue<T>::Peek() {
	return this->First();
}