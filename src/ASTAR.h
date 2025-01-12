typedef struct Node {
    int *point;

    int startCost;

    int heuristic;

    int totalCost;

    struct Node *parent;
} Node;

typedef struct priorityQueue {
    Node *nodes;

    int size;
} priorityQueue;


int isValid(int **grid, int **visited, int row, int col, int rows, int cols);
int manhattanDistance(int start[], int end[]);
void queuePush(priorityQueue *queue, Node *node);
void reconstructPath(Node *currentNode);
void aStar(int **grid, int start[], int end[], int rows, int cols);
void printAStar(int **grid, int **visited, int rows, int cols);
Node *priorityQueuePop(priorityQueue *queue);