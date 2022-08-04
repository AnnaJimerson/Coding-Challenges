#include "Node.h"

Node::Node(int row, int col)
{
	m_row = row;
	m_col = col;
	m_id = m_row + m_col;
}

void Node::SetID(int id)
{
	m_id = id;
}

void Node::SetGValue(int gVal)
{
	m_gVal = gVal;
}

void Node::SetHValue(int hVal)
{
	m_hVal = hVal;
}

void Node::SetIsWall()
{
	m_wall = true;
	m_icon = '#';
}

void Node::SetNeighbors(Node* up, Node* down, Node* left, Node* right)
{
	// Neighbors for each direction
	if (up && !up->m_wall) {
		m_adjacent[Up] = up;
	}
	if (down && !down->m_wall) {
		m_adjacent[Down] = down;
	}
	if (left && !left->m_wall) {
		m_adjacent[Left] = left;
	}
	if (right && !right->m_wall) {
		m_adjacent[Right] = right;
	}
}

void Node::SetVisited(Node* parent)
{
	m_open = true;
	m_visited = true;
	m_parent = parent;
	SetIconVisited();
}

void Node::SetIconVisited()
{
	m_icon = '*';
}

void Node::SetIconStart()
{
	m_icon = 'S';
}

void Node::SetIconEnd()
{
	m_icon = 'E';
}

void Node::SetIconPath()
{
	m_icon = '@';
}
