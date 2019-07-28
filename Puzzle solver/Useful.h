#pragma once
#include "Node.h"

//Esta classe cont�m m�todos �teis para os algoritmos de busca
class Useful {
public:
	//Armazena o vetor que representa o objetivo
	int* goal;

	//Construtor
	//Aqui podemos definir qual ser� o objetivo do puzzle
	Useful();
	//M�todo respons�vel por verificar se um puzzle tem solu��o
	bool isSolvable(int* array);
	//M�todo respons�vel por gerar uma lista com os estados para a solu��o do puzzle
	void PathTrace(List<Node>* path, Node* n);
	//M�todo respons�vel por verificar se uma lista j� possui um puzzle
	bool Contains(List<Node>* list, Node* n);
	//M�todo respons�vel por retornar o estado com menor fun��o heur�stica
	Node* GetMin(List<Node>* list);
	//M�todo respons�vel por retornar o estado com menor valor heur�stico
	Node* GetMinH(List<Node>* list);
	//Este m�todo procura a posi��o de um estado em uma lista de estados
	Element<Node>* getFrontierPosition(List<Node>* list, Node* node);

private:
	//M�todo respons�vel por calcular o n�mero de inver��es que podemos fazer com um puzzle
	int getInvertCount(int* array);
};