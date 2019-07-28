#pragma once
#include "HillClimbingSearch.h"

//Método responsável por realizar a busca de acordo com o algoritmo Subida de Encosta
List<Node> HillClimbingSearch::PerformSearch(Node* root) {
	List<Node>* pathSolution = new List<Node>();

	//Verificando se o puzzle tem solução
	if (!useful.isSolvable(root->getPuzzle())) {
		std::cout << "Este puzzle nao tem solucao!";
		std::cout << std::endl;
		return *pathSolution;
	}

	//Lista de estados a serem explorados
	List<Node>* openList = new List<Node>();
	//Lista de estados já explorados
	List<Node>* explored = new List<Node>();

	std::cout << "Fazendo a busca com Hill Climbing Search...";
	std::cout << std::endl;

	bool goalFound = false;
	int searchCount = 0;
	openList->Add(root);

	while (!openList->IsEmpty() && !goalFound) {
		Node* current = useful.GetMinH(openList);

		while (current != NULL) {
			if (current->IsGoal(useful.goal)) {
				goalFound = true;
				std::cout << "Estados explorados: " << searchCount;
				std::cout << std::endl;
				std::cout << "Estados gerados: " << openList->getCount() + explored->getCount();
				std::cout << std::endl;
				useful.PathTrace(pathSolution, current);
				return *pathSolution;
			}

			//Gerando os estados filhos do estado atual
			List<Node>* children = current->ExpandNodes();

			Node* aux = useful.GetMinH(children);

			explored->Insert(current);

			for (int i = 0; i < children->getCount(); i++) {
				Node* temp = children->GetPosition(i)->object;

				//Verificando se o estado atual vai ser ou já foi explorado
				bool openContains = useful.Contains(openList, temp);
				bool openClosed = useful.Contains(explored, temp);

				if (!openClosed && !openContains)
					openList->Add(temp);
			}

			//Se o valor heurístico do filho de menor custo for maior que do pai
			//sai do laço e procura o estado de menor custo dentro todos (Best first)
			if (aux->getHCost() > current->getHCost())
				break;

			current = aux;

			searchCount++;
		}
	}

	return *pathSolution;
}