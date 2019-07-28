#pragma once
#include "Element.h"
#include "EmptyListException.h"

//Esta classe representa uma lista de objetos e as poss�veis opera��es desta estrutura
template<typename T>
class List {
private:
	//Aponta para o primeiro elemento da lista
	Element<T>* first;

protected:
	//Armazena a quantidade de objetos na lista
	int Count;

public:
	List();
	~List();
	void Insert(T* object);
	void Add(T* object);
	T* TakeFirst();
	T* TakeLast();
	T* Remove(Element<T>* position);
	Element<T>* First();
	Element<T>* Last();
	Element<T>* GetPosition(int posicao);
	bool IsEmpty();
	int getCount();
};

//Construtor
template<typename T>
List<T>::List() {
	Count = 0;
	first = NULL;
}

//Destrutor
template<typename T>
List<T>::~List() {
	Element<T>* temp;

	//Deletando os objetos
	temp = first;
	while (temp != NULL) {
		first = first->next;
		temp = first;
	}
}

//M�todo respons�vel por inserir um elemento no in�cio da lista
template<typename T>
void List<T>::Insert(T* valor) {
	Element<T>* novo;
	novo = new Element<T>(valor);

	if (Count == 0)
		first = novo;
	else {
		novo->next = first;
		first->previous = novo;
		first = novo;
	}

	Count++;
}

//M�todo respons�vel por inserir elemento no final da lista
template<typename T>
void List<T>::Add(T* valor) {
	Element<T>* novo;
	novo = new Element<T>(valor);

	if (Count == 0)
		Insert(valor);
	else {
		Element<T>* aux = first;
		while (aux->next != NULL)
			aux = aux->next;

		novo->previous = aux;
		aux->next = novo;

		Count++;
	}
}

//M�todo respons�vel por remover elementos no in�cio da lista
template<typename T>
T* List<T>::TakeFirst() {
	if (IsEmpty())
		throw EmptyListException();

	T* aux = first->object;

	if (first->next != NULL)
		first->next->previous = NULL;

	first = first->next;

	Count--;

	return aux;
}

//M�todo respons�vel por remover elementos no final da lista
template<typename T>
T* List<T>::TakeLast() {
	if (IsEmpty())
		throw EmptyListException();

	Element<T>* aux = first;

	while (aux->next != NULL)
		aux = aux->next;

	T* valor = aux->object;

	if (aux->previous != NULL)
		aux->previous->next = NULL;

	Count--;

	return valor;
}

//M�todo respons�vel por remover uma posi��o da lista
template<typename T>
T* List<T>::Remove(Element<T>* position) {
	if (IsEmpty())
		throw EmptyListException();

	if (Count == 1)
		first = NULL;
	else {
		if (position->next != NULL)
			position->next->previous = position->previous;

		if (position->previous != NULL)
			position->previous->next = position->next;

		if (position == first)
			first = position->next;
	}

	Count--;

	position->next = NULL;
	position->previous = NULL;

	return position->object;
}

//M�todo respons�vel por retornar o valor do elemento que est� no in�cio da lista
template<typename T>
Element<T>* List<T>::First() {
	if (IsEmpty())
		return NULL;

	return first;
}

//M�todo respons�vel por retornar o valor do elemento que est� em �ltimo na lista
template<typename T>
Element<T>* List<T>::Last() {
	if (IsEmpty())
		return NULL;

	Element<T>* aux = first;
	while (aux->next != NULL)
		aux = aux->next;

	return aux;
}

//M�todo respons�vel por retorna uma posi��o da lista
template<typename T>
Element<T>* List<T>::GetPosition(int posicao) {
	Element<T>* aux = first;

	for (int i = 0; i < posicao; i++)
		aux = aux->next;

	return aux;
}

//M�todo respons�vel por verificar se a lista est� vazia
template<typename T>
bool List<T>::IsEmpty() {
	return Count == 0;
}

//M�todo respons�vel por informar a quantidade de elementos da lista
template<typename T>
int List<T>::getCount() {
	return this->Count;
}
