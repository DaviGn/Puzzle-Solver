#pragma once
#include "BreadthFirstSearch.h"

//M�todo respons�vel por realizar a busca de acordo com o algoritmo Busca em largura
List<Node> BreadthFirstSearch::PerformSearch(Node* root) {
	List<Node>* pathSolution = new List<Node>();

	//Verificando se o puzzle tem solu��o
	if (!useful.isSolvable(root->getPuzzle())) {
		std::cout << "Este puzzle nao tem solucao!";
		std::cout << std::endl;
		return *pathSolution;
	}

	//Fila de estados a serem explorados
	Queue<Node>* frontier = new Queue<Node>();
	//Lista de estados j� explorados
	List<Node>* explored = new List<Node>();

	std::cout << "Fazendo a busca com Breadth First Search...";
	std::cout << std::endl;

	bool goalFound = false;
	int searchCount = 0;
	frontier->Enqueue(root);

	while (!frontier->IsEmpty() && !goalFound) {
		Node* current = frontier->Dequeue();
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

			//Verificando se o estado atual vai ser ou j� foi explorado
			bool openContains = useful.Contains(frontier, child);
			bool openClosed = useful.Contains(explored, child);

			if (!openContains && !openClosed)
				frontier->Enqueue(child);
		}

		searchCount++;
	}

	return *pathSolution;
}