#pragma once
#include "Useful.h"
#include "List.h"

//Esta classe � respons�vel por implementar o algoritmo A Estrela para buscar a solu��o de um puzzle
class AStarSearch {
public:
	//M�todo respons�vel por realizar a busca de acordo com o algoritmo A Estrela
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe cont�m m�todos �teis para os algoritmos de busca
	Useful useful;
};