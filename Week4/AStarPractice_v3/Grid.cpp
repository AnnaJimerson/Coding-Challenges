#include "Grid.h"
#include <iostream>

Grid::Grid(int row, int col)
{
	m_sRow = row;
	m_sCol = col;
}

Grid::~Grid()
{
	// Delete grid
	for (int i = 0; i < m_sRow; i++) {
		for (int j = 0; j < m_sCol; j++) {
			delete m_grid[i][j];
		}
	}

	m_grid.clear();
}

void Grid::GenerateGrid()
{
	// Generate our 2D vector of Nodes
	for (int i = 0; i < m_sRow; i++) {
		std::vector<Node*> rowVec;
		for (int j = 0; j < m_sCol; j++) {
			//Create new node
			Node* newNode = new Node(i, j);

			// Randomly generate some nodes as walls (Avoiding start or end node)
			if (i != m_startRow || j != m_startCol){
				if (i != m_endRow || j != m_endCol){
					if (rand() % 100 < 0){
						newNode->SetIsWall();
					}
				}
			}

			// Push Nodes into vector
			rowVec.push_back(newNode);

		}
		m_grid.push_back(rowVec);
	}

	// Set start and end points
	m_grid[m_startRow][m_startCol]->SetIconStart();
	m_grid[m_endRow][m_endCol]->SetIconEnd();

	m_openList[m_grid[m_startRow][m_startCol]->GetID()] = m_grid[m_startRow][m_startCol];
}

void Grid::PrintGrid()
{
	// Print our grid of nodes
	for (int i = 0; i < m_sRow; i++) {
		for (int j = 0; j < m_sCol; j++) {
			std::cout << m_grid[i][j]->GetIcon() << "   ";
		}
		std::cout << std::endl << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << std::endl;
}

bool Grid::Update()
{
	std::cout << m_closedList.size() << std::endl;
	PrintGrid();

	if (!m_pathFound || !m_openList.empty()) {
		Node* current = nullptr;

		// Init current node to beginning of open list
		auto it = m_openList.begin();

		if(it != m_openList.end())	// only assign if not end of map
			current = it->second;

		if (!current) return false;

		// Get the lowest f in the open list
		for (auto& i : m_openList) {
			if (i.second->GetFValue() < current->GetFValue())
				current = i.second;
		}

		m_openList.erase(current->GetID());

		// Once we find the end
		if (current == m_grid[m_endRow][m_endCol]) {
			m_pathFound = true;

			Node* currentNode = current->GetParentNode();

			// Loop back through each Node's parent, and get the path
			while (currentNode) {
				currentNode->SetIconPath();
				currentNode = currentNode->GetParentNode();
			}

			m_grid[m_startRow][m_startCol]->SetIconStart();
			m_grid[m_endRow][m_endCol]->SetIconEnd();
			return false;
		}

		// Get current node's neighbors
		int row = current->GetRow();
		int col = current->GetCol();
		current->SetNeighbors(
			(row - 1 >= 0)     ? m_grid[row - 1][col] : nullptr,	// Up
			(row + 1 < m_sRow) ? m_grid[row + 1][col] : nullptr,	// Down
			(col - 1 >= 0)     ? m_grid[row][col - 1] : nullptr,	// Left
			(col + 1 < m_sCol) ? m_grid[row][col + 1] : nullptr);	// Right

		// Visit each neighbor
		for (int i = 0; i < 4; i++) {
			// Init current neighbor
			Node* neighbor = current->GetNeighbor(i);
			if (!neighbor) continue;

			if (!neighbor->GetVisited())
				neighbor->SetVisited(current);
			else
				continue;

			// Set neighbor's g distance (from current to neighbor)
			neighbor->SetGValue(current->GetGValue() +
				(abs(current->GetRow() - neighbor->GetRow())) + abs(current->GetCol() - neighbor->GetCol()));

			// Set neighbor's h distance (from neighbor to end)
			neighbor->SetHValue((abs(m_endRow - neighbor->GetRow())) + abs(m_endCol - neighbor->GetCol()));

			// Find in open list
			if (m_openList.count(neighbor->GetID())) {
				if (neighbor->GetFValue() < m_openList[neighbor->GetID()]->GetFValue()) {
					continue;
				}
			}
			else if (m_closedList.count(neighbor->GetID())) {
				if (neighbor->GetFValue() < m_closedList[neighbor->GetID()]->GetFValue()) {
					continue;
				}
			}
			else {
				// Push to open list
				m_openList[neighbor->GetID()] = neighbor;
			}
		}

		// Push to closed list
		m_closedList[current->GetID()] = current;

		// keeps updating...
		return true;
	}

	// stops updating
	return false;
}

void Grid::SetStartPoint(int startR, int startC)
{
	m_startRow = startR;
	m_startCol = startC;
}

void Grid::SetEndPoint(int endR, int endC)
{
	m_endRow = endR;
	m_endCol = endC;
}
