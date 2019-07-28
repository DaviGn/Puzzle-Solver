#pragma once
#include "AStarSearch.h"

//Método responsável por realizar a busca de acordo com o algoritmo A Estrela
List<Node> AStarSearch::PerformSearch(Node* root) {
	List<Node>* pathSolution = new List<Node>();

	//Verificando se o puzzle tem solução
	if (!useful.isSolvable(root->getPuzzle())) {
		std::cout << "Este puzzle nao tem solucao!";
		std::cout << std::endl;
		return *pathSolution;
	}

	//Lista de estados a serem explorados
	List<Node>* frontier = new List<Node>();
	//Lista de estados já explorados
	List<Node>* explored = new List<Node>();

	std::cout << "Fazendo a busca com A Star Search...";
	std::cout << std::endl;

	bool goalFound = false;
	int searchCount = 0;
	frontier->Add(root);

	while (!frontier->IsEmpty() && !goalFound) {
		Node* current = useful.GetMin(frontier);
		explored->Insert(current);

		if (current->IsGoal(useful.goal)) {
			goalFound = true;
			std::cout << "Estados explorados: " << searchCount;
			std::cout << std::endl;
			std::cout << "Estados gerados: " << frontier->getCount() + explored->getCount();
			std::cout << std::endl;
			useful.PathTrace(pathSolution, current);
			break;
		}

		//Gerando os estados filhos do estado atual
		List<Node>* children = current->ExpandNodes();

		for (int i = 0; i < children->getCount(); i++) {
			Node* child = children->GetPosition(i)->object;
			child->setGCost(current->getGCost() + child->CurrentCost);

			//Verificando se o estado atual vai ser ou já foi explorado
			bool openContains = useful.Contains(frontier, child);
			bool openClosed = useful.Contains(explored, child);

			if (!openContains && !openClosed)
				frontier->Add(child);
			else if (openContains)
				frontier->Remove(useful.getFrontierPosition(frontier, child));
		}
		
		searchCount++;
	}

	return *pathSolution;
}