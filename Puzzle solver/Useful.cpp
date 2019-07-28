#pragma once
#include "Useful.h"

//Construtor
//Aqui podemos definir qual será o objetivo do puzzle
Useful::Useful() {
	goal = new int[9];
	goal[0] = 1;
	goal[1] = 2;
	goal[2] = 3;
	goal[3] = 4;
	goal[4] = 5;
	goal[5] = 6;
	goal[6] = 7;
	goal[7] = 8;
	goal[8] = 0;
}

//Método responsável por calcular o número de inverções que podemos fazer com um puzzle
int Useful::getInvertCount(int* array) {
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			if (array[j] && array[i] && array[i] > array[j])
				inv_count++;

	return inv_count;
}

//Método responsável por verificar se um puzzle tem solução
bool Useful::isSolvable(int* array) {
	return getInvertCount(array) % 2 == 0;
}

//Método responsável por gerar uma lista com os estados para a solução do puzzle
void Useful::PathTrace(List<Node>* path, Node* n) {
	Node* current = n;
	path->Insert(current);

	while (current->getParent() != NULL) {
		current = current->getParent();
		path->Insert(current);
	}
}

//Método responsável por verificar se uma lista já possui um puzzle
bool Useful::Contains(List<Node>* list, Node* n) {
	Element<Node>* aux = list->First();

	while (aux != NULL) {
		if (aux->object->ComparePuzzles(n->getPuzzle()))
			return true;

		aux = aux->next;
	}

	return false;
}

//Método responsável por retornar o estado com menor função heurística
Node* Useful::GetMin(List<Node>* list) {
	Element<Node>* aux = list->First();
	Element<Node>* lessCost = list->First();

	while (aux != NULL) {
		if (lessCost->object->getFCost() > aux->object->getFCost()) {
			lessCost = aux;
		}

		aux = aux->next;
	}

	return list->Remove(lessCost);
}

//Método responsável por retornar o estado com menor valor heurístico
Node* Useful::GetMinH(List<Node>* list) {
	Element<Node>* aux = list->First();
	Element<Node>* lessCost = list->First();

	while (aux != NULL) {
		if (lessCost->object->getHCost() > aux->object->getHCost()) {
			lessCost = aux;
		}

		aux = aux->next;
	}

	return list->Remove(lessCost);
}

//Este método procura a posição de um estado em uma lista de estados
Element<Node>* Useful::getFrontierPosition(List<Node>* list, Node* node) {
	Element<Node>* temp = list->First();

	while (temp != NULL) {
		if (temp->object->ComparePuzzles(node->getPuzzle()))
			return temp;

		temp = temp->next;
	}

	return NULL;
}