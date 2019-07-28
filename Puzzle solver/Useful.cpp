#pragma once
#include "Useful.h"

//Construtor
//Aqui podemos definir qual ser� o objetivo do puzzle
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

//M�todo respons�vel por calcular o n�mero de inver��es que podemos fazer com um puzzle
int Useful::getInvertCount(int* array) {
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			if (array[j] && array[i] && array[i] > array[j])
				inv_count++;

	return inv_count;
}

//M�todo respons�vel por verificar se um puzzle tem solu��o
bool Useful::isSolvable(int* array) {
	return getInvertCount(array) % 2 == 0;
}

//M�todo respons�vel por gerar uma lista com os estados para a solu��o do puzzle
void Useful::PathTrace(List<Node>* path, Node* n) {
	Node* current = n;
	path->Insert(current);

	while (current->getParent() != NULL) {
		current = current->getParent();
		path->Insert(current);
	}
}

//M�todo respons�vel por verificar se uma lista j� possui um puzzle
bool Useful::Contains(List<Node>* list, Node* n) {
	Element<Node>* aux = list->First();

	while (aux != NULL) {
		if (aux->object->ComparePuzzles(n->getPuzzle()))
			return true;

		aux = aux->next;
	}

	return false;
}

//M�todo respons�vel por retornar o estado com menor fun��o heur�stica
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

//M�todo respons�vel por retornar o estado com menor valor heur�stico
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

//Este m�todo procura a posi��o de um estado em uma lista de estados
Element<Node>* Useful::getFrontierPosition(List<Node>* list, Node* node) {
	Element<Node>* temp = list->First();

	while (temp != NULL) {
		if (temp->object->ComparePuzzles(node->getPuzzle()))
			return temp;

		temp = temp->next;
	}

	return NULL;
}