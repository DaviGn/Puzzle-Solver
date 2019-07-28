#include "Node.h"
#include "List.h"

//Esta classe é responsável por representar um estado do puzzle

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

//Método responsável por comparar e verificar se 
//o estado representado por este Node é o estado final
bool Node::IsGoal(int* goal) {
	for (int i = 0; i < size; i++) {
		if (puzzle[i] != goal[i])
			return false;
	}

	return true;
}

//Método responsável por verificar se dois puzzles são idênticos
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

//Retorna a soma das distâncias de Manhattan 
//das peças fora do lugar deste estado
int Node::getManDist() {
	return manDist;
}

//Retorna a soma da quantidade de peças fora do lugar deste estado
int Node::getOutOfPlace() {
	return outOfPlace;
}

//Retorna o valor da função heurística do A* onde f(n) = g(n) + h(n)
int Node::getFCost() {
	return getGCost() + getHCost();
}

//Retorna o valor do custo para chegar a este estado - g(n)
int Node::getGCost() {
	return gCost;
}

//Retorna o valor heurístico deste estado - h(n)
//Troque entre getManDist ou getOutOfPlace, dependendo da heurística desejada
int Node::getHCost() {
	/*return getOutOfPlace();*/
	return getManDist();
}

//Método responsável por definir o custo para chegar a  este estado
void Node::setGCost(int GCost) {
	this->gCost = GCost;
}

//Método responsável por verificar onde se encontra o valor 0 no puzzle
void Node::setHolePosition() {
	for (int i = 0; i < size; i++) {
		if (puzzle[i] == 0) {
			holePosition = i;
			break;
		}
	}
}

//Método responsável por calcular as somas das distâncias de Manhattan
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

//Método responsável por calcular a soma das peças fora do lugar
void Node::setOutOfPlace() {
	for (int y = 0; y < size; y++) {
		if (puzzle[y] != y)
			outOfPlace++;
	}
}

//Método responsável por gerar os filhos deste estado, que são no máximo 4
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

//Método responsável por gerar estado o filho quando movemos o 0 para a direita a partir do estado atual
void Node::MoveToRight(int* puzzle, int i, List<Node>* children) {
	//Verificando se é possível realizar o movimento
	if (i % columns < columns - 1) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posição onde estava o 0 e a peça ao lado direito
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

//Método responsável por gerar estado o filho quando movemos o 0 para a esquerda a partir do estado atual
void Node::MoveToLeft(int* puzzle, int i, List<Node>* children) {
	//Verificando se é possível realizar o movimento
	if (i % columns > 0) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posição onde estava o 0 e a peça ao lado esquerdo
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

//Método responsável por gerar estado o filho quando movemos o 0 para cima a partir do estado atual
void Node::MoveToUp(int* puzzle, int i, List<Node>* children) {
	//Verificando se é possível realizar o movimento
	if (i - columns >= 0) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posição onde estava o 0 e a peça de cima
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

//Método responsável por gerar estado o filho quando movemos o 0 para baixo a partir do estado atual
void Node::MoveToDown(int* puzzle, int i, List<Node>* children) {
	//Verificando se é possível realizar o movimento
	if (i + columns < size) {
		int* p;
		p = new int[size];

		//Copiando o puzzle atual para outro vetor
		CopyArray(puzzle, p);

		//Trocando os valores da posição onde estava o 0 e a peça abaixo
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

//Método responsável por copiar um puzzle para outro vetor
void Node::CopyArray(int* source, int* destiny) {
	for (int i = 0; i < size; i++)
		destiny[i] = source[i];
}

//Método responsável por exibir no console os valores do puzzle do estado atual
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