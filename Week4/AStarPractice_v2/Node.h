#pragma once
class Node
{
private:
	enum {
		Up,
		Down,
		Left,
		Right
	};

	Node* m_adjacent[4];
	bool m_visited = false;
	bool m_wall = false;
	char m_icon = '1';

public:
	Node(int row, int col);

	int m_row;
	int m_col;
	void SetNeighbors(Node* up, Node* down, Node* left, Node* right);
	void SetVisited();

	char GetIcon() { return m_icon; }
	void SetIconVisited();
	void SetIconStart();
	void SetIconEnd();
};

