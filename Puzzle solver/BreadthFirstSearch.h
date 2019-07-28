#pragma once
#include "Useful.h"
#include "Queue.h"

//Esta classe é responsável por implementar o algoritmo Busca em largura para buscar a solução de um puzzle
class BreadthFirstSearch {
public:
	//Método responsável por realizar a busca de acordo com o algoritmo Busca em largura
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe contém métodos úteis para os algoritmos de busca
	Useful useful;
};