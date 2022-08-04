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
	Node* m_parent;

	bool m_visited = false;
	bool m_open = false;
	bool m_wall = false;
	char m_icon = '0';

public:
	Node(int row, int col);

	int m_row;
	int m_col;
	bool GetOpen() { return m_open; }
	bool GetVisited() { return m_visited; }
	Node* GetParentNode() { return m_parent; }

	void SetIsWall();
	void SetNeighbors(Node* up, Node* down, Node* left, Node* right);
	void VisitNeighbors();
	void SetVisited();

	char GetIcon() { return m_icon; }
	void SetIconVisited();
	void SetIconStart();
	void SetIconEnd();
	void SetIconPath();
};

