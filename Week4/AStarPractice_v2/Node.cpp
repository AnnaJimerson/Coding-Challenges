#include "Node.h"

Node::Node(int row, int col)
{
	m_row = row;
	m_col = col;
}

void Node::SetIsWall()
{
	m_wall = true;
	m_icon = '#';
}

void Node::SetNeighbors(Node* up, Node* down, Node* left, Node* right)
{
	if(up && !up->m_wall)
		m_adjacent[Up] = up;
	if(down && !down->m_wall)
		m_adjacent[Down] = down;
	if(left && !left->m_wall)
		m_adjacent[Left] = left;
	if(right && !right->m_wall)
		m_adjacent[Right] = right;
}

void Node::VisitNeighbors()
{
	for (auto i : m_adjacent) {
		if (i && !i->m_visited) {
			i->SetVisited();
			i->m_parent = this;
		}
	}
}

void Node::SetVisited()
{
	m_open = true;
	m_visited = true;
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
