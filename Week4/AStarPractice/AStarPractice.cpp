// AStarPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*Sample map to traverse :

(a, b, 5)
(b, c, 1)
(a, d, 7)
(c, d, 1)
Sample path request :

(a, d)*/

struct Node {
    bool m_canTraverse = true;
    int m_x = 0;
    int m_y = 0;
    int m_gCost = 0;  //dist from this node to start
    int m_hCost = 0;  //dist from this node to end
    int m_fCost = 0;  //g + h cost

    Node() {

    }

    Node(int y, int x, bool canTraverse) {
        m_x = x;
        m_y = y;
        m_canTraverse = canTraverse;
    }
};

int main()
{
    constexpr int ROW = 8;
    constexpr int COL = 8;

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
            nodeArray[i][j].m_gCost = (i + j);              // cost from the start
            nodeArray[i][j].m_hCost = (abs((COL-1) - i) + abs(0 - j));  // cost from the end4

            nodeArray[i][j].m_fCost = nodeArray[i][j].m_gCost + nodeArray[i][j].m_hCost;    // g+h cost
        }
    }


}
