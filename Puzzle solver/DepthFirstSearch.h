#pragma once
#include "Useful.h"
#include "Stack.h"

//Esta classe é responsável por implementar o algoritmo Busca em profundaide para buscar a solução de um puzzle
class DepthFirstSearch {
public:
	//Método responsável por realizar a busca de acordo com o algoritmo Busca em profundidade
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe contém métodos úteis para os algoritmos de busca
	Useful useful;
};