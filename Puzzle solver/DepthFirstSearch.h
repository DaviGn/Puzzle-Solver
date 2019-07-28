#pragma once
#include "Useful.h"
#include "Stack.h"

//Esta classe � respons�vel por implementar o algoritmo Busca em profundaide para buscar a solu��o de um puzzle
class DepthFirstSearch {
public:
	//M�todo respons�vel por realizar a busca de acordo com o algoritmo Busca em profundidade
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe cont�m m�todos �teis para os algoritmos de busca
	Useful useful;
};