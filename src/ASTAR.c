#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "ASTAR.h"

int isValid(int **grid, int **visited, int row, int col, int rows, int cols)
{
    return (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != 1 && !visited[row][col]);
}

int manhattanDistance(int start[], int end[])
{
    return abs(start[0] - end[0]) + abs(start[1] - end[1]);
}

void queuePush(priorityQueue *queue, Node *node)
{
    queue->nodes[queue->size++] = node;

    for (int i = queue->size - 1; i > 0; i--)
    {
        if ((queue->nodes[i]->totalCost) < (queue->nodes[i - 1]->totalCost))
        {
            Node *temp = queue->nodes[i];

            queue->nodes[i] = queue->nodes[i - 1];

            queue->nodes[i - 1] = temp;
        }
    }
}

Node *priorityQueuePop(priorityQueue *queue)
{
    return queue->nodes[--queue->size];
}

void reconstructPath(Node *currentNode, int **grid)
{
    while (currentNode != NULL)
    {

        grid[currentNode->point[0]][currentNode->point[1]] = 2;

        currentNode = currentNode->parent;
    }
}

void aStar(int **grid, int start[], int end[], int rows, int cols)
{

    printf("Start Node: %d %d\n", start[0], start[1]);
    printf("End Node: %d %d\n", end[0], end[1]);

    int **visited = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        visited[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            visited[i][j] = 0;
        }
    }

    priorityQueue *queue = malloc(sizeof(priorityQueue));

    queue->nodes = malloc(rows * cols * sizeof(Node *));

    queue->size = 0;

    Node *startNode = malloc(sizeof(Node));

    startNode->point = malloc(2 * sizeof(int));

    startNode->point[0] = start[0];
    startNode->point[1] = start[1];

    startNode->startCost = 0;

    startNode->heuristic = manhattanDistance(start, end);

    startNode->totalCost = startNode->startCost + startNode->heuristic;

    startNode->parent = NULL;

    queuePush(queue, startNode);

    while (queue->size > 0)
    {

        Node *currentNode = priorityQueuePop(queue);

        visited[currentNode->point[0]][currentNode->point[1]] = 1;

        if (currentNode->point[0] == end[0] && currentNode->point[1] == end[1])
        {

            reconstructPath(currentNode, grid);

            printAStar(grid, visited, rows, cols);

            free(queue->nodes);
            free(queue);
            queue = NULL;

            free(visited);
            visited = NULL;

            break;
        }

        int row = currentNode->point[0];

        int col = currentNode->point[1];

        int rowOffset[] = {-1, 0, 1, 0};

        int colOffset[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + rowOffset[i];

            int newCol = col + colOffset[i];

            if (isValid(grid, visited, newRow, newCol, rows, cols))
            {
                Node *newNode = malloc(sizeof(Node));

                newNode->point = malloc(2 * sizeof(int));

                newNode->point[0] = newRow;

                newNode->point[1] = newCol;

                newNode->startCost = currentNode->startCost + 1;

                newNode->heuristic = manhattanDistance(newNode->point, end);

                newNode->totalCost = newNode->startCost + newNode->heuristic;

                newNode->parent = currentNode;

                queuePush(queue, newNode);
            }
        }
    }
}

void printAStar(int **grid, int **visited, int rows, int cols)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (grid[i][j] == 2)
            {
                printf(". ");
            }
            else if (grid[i][j] == 0) {
                printf("  ");
            }

            else
            {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
}