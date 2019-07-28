#pragma once
#include "Node.h"

//Esta classe contém métodos úteis para os algoritmos de busca
class Useful {
public:
	//Armazena o vetor que representa o objetivo
	int* goal;

	//Construtor
	//Aqui podemos definir qual será o objetivo do puzzle
	Useful();
	//Método responsável por verificar se um puzzle tem solução
	bool isSolvable(int* array);
	//Método responsável por gerar uma lista com os estados para a solução do puzzle
	void PathTrace(List<Node>* path, Node* n);
	//Método responsável por verificar se uma lista já possui um puzzle
	bool Contains(List<Node>* list, Node* n);
	//Método responsável por retornar o estado com menor função heurística
	Node* GetMin(List<Node>* list);
	//Método responsável por retornar o estado com menor valor heurístico
	Node* GetMinH(List<Node>* list);
	//Este método procura a posição de um estado em uma lista de estados
	Element<Node>* getFrontierPosition(List<Node>* list, Node* node);

private:
	//Método responsável por calcular o número de inverções que podemos fazer com um puzzle
	int getInvertCount(int* array);
};