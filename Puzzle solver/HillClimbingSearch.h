#pragma once
#include "Useful.h"
#include "Stack.h"

//Esta classe � respons�vel por implementar o algoritmo Subida de encosta para buscar a solu��o de um puzzle
class HillClimbingSearch {
public:
	//M�todo respons�vel por realizar a busca de acordo com o algoritmo Subida de Encosta
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe cont�m m�todos �teis para os algoritmos de busca
	Useful useful;
};