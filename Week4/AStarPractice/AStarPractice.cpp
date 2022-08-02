// AStarPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

/*Sample map to traverse :

(a, b, 5)
(b, c, 1)
(a, d, 7)
(c, d, 1)
Sample path request :

(a, d)*/
constexpr int ROW = 8;
constexpr int COL = 8;

struct Node {
    bool m_canTraverse = true;
    int m_x = 0;
    int m_y = 0;
    int m_gCost = 0;  //dist from this node to start
    int m_hCost = 0;  //dist from this node to end
    int m_fCost = 0;  //g + h cost

    Node* parent = nullptr;

    Node() {

    }

    Node(int y, int x, bool canTraverse) {
        m_x = x;
        m_y = y;
        m_canTraverse = canTraverse;
    }
};

void AStar(Node arr[][COL], Node start, Node end);
bool checkValidStep(int x, int y);

int main()
{
    bool myArray[ROW][COL] = {
        1, 1, 1, 0, 0, 1, 1, 1,
        1, 1, 1, 0, 1, 1, 1, 0,
        0, 1, 1, 0, 1, 1, 0, 0,
        0, 1, 1, 0, 1, 1, 0, 0,
        0, 1, 1, 0, 0, 1, 0, 0,
        0, 1, 1, 1, 1, 1, 0, 0,
        0, 1, 1, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    };

    Node endPoint(0, COL-1, 1);     // end point is at the top-right corner
    Node startPoint(0, 0, 1);

    Node nodeArray[ROW][COL];

    // Create array of nodes based on myArray
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            nodeArray[i][j].m_x = i;    // set xy location based on row and col
            nodeArray[i][j].m_y = j;
            nodeArray[i][j].m_canTraverse = myArray[i][j];  // set can traverse from other array
            //nodeArray[i][j].m_gCost = (i + j);              // cost from the start
            //nodeArray[i][j].m_hCost = (abs(0 - i) + abs((COL - 1) - j));  // cost from the end4

            //nodeArray[i][j].m_fCost = nodeArray[i][j].m_gCost + nodeArray[i][j].m_hCost;    // g+h cost
        }
    }

    AStar(nodeArray, startPoint, endPoint);

}

void AStar(Node arr[][COL], Node start, Node end)
{
    /*for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << arr[i][j].m_fCost << '\t';
        }
        std::cout << std::endl << std::endl;
    }*/

    std::vector<Node> openList;
    std::vector<Node> closedList;

    openList.push_back(arr[0][0]);

    while (openList.size() > 0) {
        Node q = openList[0];

        for (int i = 0; i < openList.size(); i++) {
            if (openList[i].m_fCost < q.m_fCost)
                q = openList[i];

            openList.erase(openList.begin()+i);
        }

        std::vector<Node> successors;
        int x = 0; 
        int y = 0;
        // Top part of the square
        x = q.m_x - 1; y = q.m_y - 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // top left

        x = q.m_x - 0; y = q.m_y - 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // top

        x = q.m_x + 1; y = q.m_y - 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // top right

        // Right part of the square
        x = q.m_x + 1; y = q.m_y - 0;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // right

        x = q.m_x + 1; y = q.m_y + 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // bottom right

        // Bottom part of the square
        x = q.m_x + 0; y = q.m_y + 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // bottom

        x = q.m_x - 1; y = q.m_y + 1;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // bottom left

        // Left part of the square
        x = q.m_x - 1; y = q.m_y + 0;
        if (checkValidStep(x, y))
            successors.push_back(arr[x][y]); // left

        for (Node& i : successors) {
            // found end goal
            if (i.m_x == end.m_x && i.m_y == end.m_y)
                return;
            // get gCost (dist from i to q) and hCost (dist from i to end) and fCost (g + h)
            else {
                i.m_gCost = q.m_gCost + (abs(i.m_x - q.m_x) + abs(i.m_y - q.m_y));
                i.m_hCost = (abs(i.m_x - end.m_x) + abs(i.m_y - end.m_y));
                i.m_fCost = i.m_gCost + i.m_hCost;
            }

            // Check open list for successor
            bool skip = false;
            for (Node& j : openList) {
                if (j.m_x == i.m_x && j.m_y == i.m_y) {
                    if (j.m_fCost < i.m_fCost){
                        skip = true;
                        break;
                    }
                }
            }
            if (skip) continue;

            // Check closed list for successor
            skip = false;
            for (Node& j : closedList) {
                if (j.m_x == i.m_x && j.m_y == i.m_y) {
                    if (j.m_fCost < i.m_fCost) {
                        skip = true;
                        break;
                    }
                }
            }
            if (skip) 
                continue;
            else
                openList.push_back(i);
        }

        closedList.push_back(q);
    }
}

bool checkValidStep(int x, int y)
{
    if (x > ROW || y > COL) {
        return false;
    }
    else if (x < 0 || y < 0) {
        return false;
    }
    else {
        return true;
    }
}
