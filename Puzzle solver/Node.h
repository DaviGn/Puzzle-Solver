#pragma once
#include "List.h"

//Esta classe é responsável por representar um estado do puzzle
//Os métodos estão comentados no arquivo Node.cpp
class Node {
public:
	Node(int* p);
	~Node();
	bool IsGoal(int* goal);
	bool ComparePuzzles(int* p);
	List<Node>* ExpandNodes();
	void PrintPuzzle();
	Node* getParent();
	int* getPuzzle();
	int getManDist();
	int getOutOfPlace();
	int getFCost();
	int getGCost();
	void setGCost(int GCost);
	int getHCost();

	//Constante responsável por representar o custo fixo para chegar a este estado a partir do estado pai
	const int CurrentCost = 1;

private:
	//Ponteiro que aponta para o Node pai deste estado
	Node* parent;
	//Representa o puzzle do estado atual
	int* puzzle;
	//Armazena o valor do custo para cheagr a este g(n)
	int gCost = 0;
	//Armazena o valor das somas das distâncias de Manhattan do puzzle deste estado
	int manDist = 0;
	//Armazena a quantidade de peças fora do lugar deste estado
	int outOfPlace = 0;
	//Constante que representa o número de colunas do puzzle
	const int columns = 3;
	//Constante que representa o número de blocos do puzzle
	const int size = 9;
	//Armazena a posição do valor 0 no puzzle
	int holePosition = 0;

	void setHolePosition();
	void setManDist();
	void setOutOfPlace();
	void MoveToRight(int* puzzle, int i, List<Node>* childrens);
	void MoveToLeft(int* puzzle, int i, List<Node>* childrens);
	void MoveToUp(int* puzzle, int i, List<Node>* childrens);
	void MoveToDown(int* puzzle, int i, List<Node>* childrens);
	void CopyArray(int* source, int* destiny);
};