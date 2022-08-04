#pragma once
#include <vector>
#include "Node.h"
class Grid
{
private:
	std::vector<std::vector<Node*>> m_grid;
	std::vector<Node*> m_openList;
	std::vector<Node*> m_closedList;

	int m_sRow = 10;
	int m_sCol = 10;

	int m_startRow = 0;
	int m_startCol = 0;
	int m_endRow = 0;
	int m_endCol = 0;

	Node* m_start;
	Node* m_end;

	bool m_pathFound = false;

public:
	// Size of the grid, max rows, max cols
	Grid(int row, int col);
	virtual ~Grid();
	void GenerateGrid();
	void PrintGrid();
	void Update();

	void SetStartPoint(int startR, int startC);
	void SetEndPoint(int endR, int endC);
};

