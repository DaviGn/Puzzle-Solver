#include "Node.h"
#include "List.h"

//Esta classe � respons�vel por representar um estado do puzzle

//Construtor. Recebe um vetor representando o puzzle.
Node::Node(int* p) {
	parent = NULL;
	puzzle = p;

	setHolePosition();

	setManDist();
	setOutOfPlace();
}

//Destrutor
Node::~Node() {
	delete puzzle;
}

//M�todo respons�vel por comparar e verificar se 
//o estado representado por este Node � o estado final
bool Node::IsGoal(int* goal) {
	for (int i = 0; i < size; i++) {
		if (puzzle[i] != goal[i])
			return false;
	}

	return true;
}

//M�todo respons�vel por verificar se dois puzzles s�o id�nticos
bool Node::ComparePuzzles(int* p) {
	for (int i = 0; i < size; i++) {
		if (p[i] != puzzle[i])
			return false;
	}

	return true;
}

//Retorna o Node pai
Node* Node::getParent() {
	return this->parent;
}

//Retorna o puzzle deste estado
int* Node::getPuzzle() {
	return this->puzzle;
}

//Retorna a soma das dist�ncias de Manhattan 
//das pe�as fora do lugar deste estado
int Node::getManDist() {
	return manDist;
}

//Retorna a soma da quantidade de pe�as fora do lugar deste estado
int Node::getOutOfPlace() {
	return outOfPlace;
}

//Retorna o valor da fun��o heur�stica do A* onde f(n) = g(n) + h(n)
int Node::getFCost() {
	return getGCost() + getHCost();
}

//Retorna o valor do custo para chegar a este estado - g(n)
int Node::getGCost() {
	return gCost;
}

//Retorna o valor heur�stico deste estado - h(n)
//Troque entre getManDist ou getOutOfPlace, dependendo da heur�stica desejada
int Node::getHCost() {
	/*return getOutOfPlace();*/
	return getManDist();
}

//M�todo respons�vel por definir o custo para chegar a  este estado
void Node::setGCost(int GCost) {
	this->gCost = GCost;
}

//M�todo respons�vel por verificar onde se encontra o valor 0 no puzzle
void Node::setHolePosition() {
	for (int i = 0; i < size; i++) {
		if (puzzle[i] == 0) {
			holePosition = i;
			break;
		}
	}
}

//M�todo respons�vel por calcular as somas das dist�ncias de Manhattan
void Node::setManDist() {
	int index = -1;

	for (int y = 0; y < columns; y++) {
		for (int x = 0; x < columns; x++) {
			index++;

			int val = (puzzle[index] - 1);

			if (val != -1) {
				int horiz = val % columns;
				int vert = val / columns;

				manDist += abs(vert - (y)) + abs(horiz - (x));
			}
		}
	}
}

//M�todo respons�vel por calcular a soma das pe�as fora do lugar
void Node::setOutOfPlace() {
	for (int y = 0; y < size; y++) {
		if (puzzle[y] != y)
			outOfPlace++;
	}
}

//M�todo respons�vel por gerar os filhos deste estado, que s�o no m�ximo 4
List<Node>* Node::ExpandNodes() {
	//Lista dos estados filhos gerados
	List<Node>* children = new List<Node>();

	//Gerando o estado filho quando movemos o 0 para a direita
	MoveToRight(puzzle, holePosition, children);

	//Gerando o estado filho quando movemos o 0 para a baixo
	MoveToDown(puzzle, holePosition, children);

	//Gerando o estado filho quando movemos o 0 para a esquerda
	MoveToLeft(puzzle, holePosition, children);

	//Gerando o estado filho quando movemos o 0 para a cima
	MoveToUp(puzzle, holePosition, children);

	return children;
}

//M�todo respons�vel por gerar estado o filho quando movemos o 0 para a direita a partir do estado atual
void Node::MoveToRight(int* puzzle, int i, List<Node>* children) {
	//Verificando se � poss�vel realizar o movimento
	if (i % columns < columns - 1) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posi��o onde estava o 0 e a pe�a ao lado direito
		int temp = p[i + 1];
		p[i + 1] = p[i];
		p[i] = temp;

		//Instanciando o novo estado
		Node* child;
		child = new Node(p);
		child->parent = this;
		children->Add(child);
	}
}

//M�todo respons�vel por gerar estado o filho quando movemos o 0 para a esquerda a partir do estado atual
void Node::MoveToLeft(int* puzzle, int i, List<Node>* children) {
	//Verificando se � poss�vel realizar o movimento
	if (i % columns > 0) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posi��o onde estava o 0 e a pe�a ao lado esquerdo
		int temp = p[i - 1];
		p[i - 1] = p[i];
		p[i] = temp;

		//Instanciando o novo estado
		Node* child;
		child = new Node(p);
		child->parent = this;
		children->Add(child);
	}
}

//M�todo respons�vel por gerar estado o filho quando movemos o 0 para cima a partir do estado atual
void Node::MoveToUp(int* puzzle, int i, List<Node>* children) {
	//Verificando se � poss�vel realizar o movimento
	if (i - columns >= 0) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posi��o onde estava o 0 e a pe�a de cima
		int temp = p[i - 3];
		p[i - 3] = p[i];
		p[i] = temp;

		//Instanciando o novo estado
		Node* child;
		child = new Node(p);
		child->parent = this;
		children->Add(child);
	}
}

//M�todo respons�vel por gerar estado o filho quando movemos o 0 para baixo a partir do estado atual
void Node::MoveToDown(int* puzzle, int i, List<Node>* children) {
	//Verificando se � poss�vel realizar o movimento
	if (i + columns < size) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posi��o onde estava o 0 e a pe�a abaixo
		int temp = p[i + 3];
		p[i + 3] = p[i];
		p[i] = temp;

		//Instanciando o novo estado
		Node* child;
		child = new Node(p);
		child->parent = this;
		children->Add(child);
	}
}

//M�todo respons�vel por copiar um puzzle para outro vetor
void Node::CopyArray(int* source, int* destiny) {
	for (int i = 0; i < size; i++)
		destiny[i] = source[i];
}

//M�todo respons�vel por exibir no console os valores do puzzle do estado atual
void Node::PrintPuzzle() {
	int m = 0;
	for (int i = 0; i < columns; i++)
	{
		for (int x = 0; x < columns; x++)
		{
			std::cout << puzzle[m] << " ";
			m++;
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}