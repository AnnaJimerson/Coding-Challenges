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
			rowVec.push_back(new Node(i, j));
		}
		m_grid.push_back(rowVec);
	}

	// Set neighbors for each tile
	for (int i = 0; i < m_sRow; i++) {
		for (int j = 0; j < m_sCol; j++) {
			m_grid[i][j]->SetNeighbors(
				(i-1 >= 0) ? m_grid[i-1][j] : nullptr, 
				(i+1 < m_sRow) ? m_grid[i+1][j] : nullptr,
				(j-1 >= 0) ? m_grid[i][j-1] : nullptr,
				(j + 1 >= 0) ? m_grid[i][j + 1] : nullptr);
		}
	}

	m_grid[m_startRow][m_startCol]->SetIconStart();
	m_grid[m_endRow][m_endCol]->SetIconEnd();
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

void Grid::Update()
{
	
	PrintGrid();
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
