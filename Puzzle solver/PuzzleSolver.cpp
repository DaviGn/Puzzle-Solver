#pragma once
#include <iostream>
#include "Node.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "AStarSearch.h"
#include "HillClimbingSearch.h"
using namespace std;

int main() {
	//Estado inicial
	int* puzzle;
	puzzle = new int[9];
	puzzle[0] = 8;
	puzzle[1] = 6;
	puzzle[2] = 7;
	puzzle[3] = 2;
	puzzle[4] = 5;
	puzzle[5] = 4;
	puzzle[6] = 3;
	puzzle[7] = 0;
	puzzle[8] = 1;

	//Fazendo a busca em largura
	Node initBFS(puzzle);
	BreadthFirstSearch bfs;
	List<Node> pathBFS = bfs.PerformSearch(&initBFS);

	for (int i = 0; i < pathBFS.getCount(); i++) {
		Node* node = pathBFS.GetPosition(i)->object;
		node->PrintPuzzle();
	}

	std::cout << "Numero de passos para resolver: " << pathBFS.getCount();
	std::cout << std::endl;
	std::cout << std::endl;

	//Fazendo a busca em profundidade
	Node initDFS(puzzle);
	DepthFirstSearch dfs;
	List<Node> pathDFS = dfs.PerformSearch(&initDFS);

	for (int i = 0; i < pathDFS.getCount(); i++) {
		Node* node = pathDFS.GetPosition(i)->object;
		node->PrintPuzzle();
	}

	std::cout << "Numero de passos para resolver: " << pathDFS.getCount();
	std::cout << std::endl;
	std::cout << std::endl;

	//Fazendo a busca A estrela
	Node initAS(puzzle);
	AStarSearch as;
	List<Node> pathAS = as.PerformSearch(&initAS);
	int totalCostAS = 0;

	for (int i = 0; i < pathAS.getCount(); i++) {
		Node* node = pathAS.GetPosition(i)->object;
		node->PrintPuzzle();
		totalCostAS += node->getFCost();
	}

	std::cout << "Numero de passos para resolver: " << pathAS.getCount();
	std::cout << std::endl;
	std::cout << "Custo total: " << totalCostAS;
	std::cout << std::endl;
	std::cout << std::endl;

	//Fazendo a busca subida de encosta
	Node initHC(puzzle);
	HillClimbingSearch hc;
	List<Node> pathHC = hc.PerformSearch(&initHC);
	int totalCostHC = 0;

	for (int i = 0; i < pathHC.getCount(); i++) {
		Node* node = pathHC.GetPosition(i)->object;
		node->PrintPuzzle();
		totalCostHC += node->getHCost();
	}

	std::cout << "Numero de passos para resolver: " << pathHC.getCount();
	std::cout << std::endl;
	std::cout << "Custo total: " << totalCostHC;
	
	cin.get();
	return 0;
}