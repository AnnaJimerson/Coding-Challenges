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

	int m_gVal = 0;	// the distance/weight from the node we start at
	int m_hVal = 0;	// the distance/weight from the end node

	int m_row;
	int m_col;
	int m_id;

public:
	Node(int row, int col);

	int GetRow() { return m_row; }
	int GetCol() { return m_col; }
	int GetID()  { return m_id; }
	void SetID(int id);

	bool GetOpen() { return m_open; }
	bool GetVisited() { return m_visited; }
	Node* GetParentNode() { return m_parent; }

	int GetFValue() { return m_gVal + m_hVal; }
	int GetGValue() { return m_gVal; }
	int GetHValue() { return m_hVal; }
	void SetGValue(int gVal);
	void SetHValue(int hVal);

	void SetIsWall();
	Node* GetNeighbor(int index) { return m_adjacent[index]; }
	void SetNeighbors(Node* up, Node* down, Node* left, Node* right);
	void SetVisited(Node* parent);

	char GetIcon() { return m_icon; }
	void SetIconVisited();
	void SetIconStart();
	void SetIconEnd();
	void SetIconPath();
};

