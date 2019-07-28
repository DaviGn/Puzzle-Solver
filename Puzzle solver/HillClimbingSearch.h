#pragma once
#include "Useful.h"
#include "Stack.h"

//Esta classe é responsável por implementar o algoritmo Subida de encosta para buscar a solução de um puzzle
class HillClimbingSearch {
public:
	//Método responsável por realizar a busca de acordo com o algoritmo Subida de Encosta
	List<Node> PerformSearch(Node* root);

private:
	//Esta classe contém métodos úteis para os algoritmos de busca
	Useful useful;
};