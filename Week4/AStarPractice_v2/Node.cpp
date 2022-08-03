#include "Node.h"

Node::Node(int row, int col)
{
	m_row = row;
	m_col = col;
}

void Node::SetNeighbors(Node* up, Node* down, Node* left, Node* right)
{
	m_adjacent[Up] = up;
	m_adjacent[Down] = down;
	m_adjacent[Left] = left;
	m_adjacent[Right] = right;
}

void Node::SetVisited()
{
	m_visited = true;
}

void Node::SetIconVisited()
{
	m_icon = '@';
}

void Node::SetIconStart()
{
	m_icon = 'S';
}

void Node::SetIconEnd()
{
	m_icon = 'E';
}