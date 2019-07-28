#pragma once
#include "Useful.h"
#include "Queue.h"

//Esta classe � respons�vel por implementar o algoritmo Busca em largura para buscar a solu��o de um puzzle
class BreadthFirstSearch {
public:
	//M�todo respons�vel por realizar a busca de acordo com o algoritmo Busca em largura
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe cont�m m�todos �teis para os algoritmos de busca
	Useful useful;
};