#pragma once

//Esta classe representa um elemento de uma estrutura de dados
template<class T>
class Element {
public:
	//Objeto armazenado na estrutura
	T* object;
	//Aponta para o próximo objeto
	Element* next;
	//Aponta para o objeto anterior
	Element* previous;

	//Construtor
	Element(T* object) : object(object), previous(nullptr), next(nullptr)
	{
	}
};