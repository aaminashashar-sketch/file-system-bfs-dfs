
#include <stdio.h>
#include <string.h>

#define MAX 50

int graph[MAX][MAX];
int visited[MAX];
char files[MAX][50];
int n, found;

void BFS(int start, char target[]) {
    int queue[MAX], front = 0, rear = 0;
    int seen[MAX] = {0};

    queue[rear++] = start;
    seen[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%s ", files[current]);

        if (strcmp(files[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !seen[i]) {
                queue[rear++] = i;
                seen[i] = 1;
            }
        }
    }

    printf("\nFile %s using BFS: %s\n",
           target, found ? "FOUND" : "NOT FOUND");
}

void DFS(int current, char target[]) {
    visited[current] = 1;

    printf("%s ", files[current]);

    if (strcmp(files[current], target) == 0)
        found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] && !visited[i]) {
            DFS(i, target);
        }
    }
}

int main() {
    int start;
    char target[50];

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter file/directory names (no spaces):\n");
    for (int i = 0; i < n; i++) {
        scanf("%49s", files[i]);
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node index (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting node.\n");
        return 1;
    }

    printf("Enter file/directory to search: ");
    scanf("%49s", target);

    found = 0;
    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    found = 0;
    printf("DFS Traversal: ");
    DFS(start, target);

    printf("\nFile %s using DFS: %s\n",
           target, found ? "FOUND" : "NOT FOUND");

    return 0;
}
