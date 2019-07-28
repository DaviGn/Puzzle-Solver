#pragma once
#include "Useful.h"

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

int Useful::getInvertCount(int* array) {
	int inv_count = 0;
	for (int i = 0; i < 9 - 1; i++)
		for (int j = i + 1; j < 9; j++)
			if (array[j] && array[i] && array[i] > array[j])
				inv_count++;

	return inv_count;
}

bool Useful::isSolvable(int* array) {
	return getInvertCount(array) % 2 == 0;
}

bool Useful::CheckRepeats(Node* n) {
	Node* checkNode = n;

	while (n->getParent() != NULL) {
		if (n->getParent()->ComparePuzzles(checkNode->getPuzzle()))
			return true;

		n = n->getParent();
	}

	return false;
}

void Useful::PathTrace(List<Node>* path, Node* n) {
	Node* current = n;
	path->Insert(current);

	while (current->getParent() != NULL) {
		current = current->getParent();
		path->Insert(current);
	}
}

bool Useful::Contains(List<Node>* list, Node* n) {
	Element<Node>* aux = list->First();

	while (aux != NULL) {
		if (aux->object->ComparePuzzles(n->getPuzzle()))
			return true;

		aux = aux->next;
	}

	return false;
}

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