#include <stdio.h>

#define V 6

void bfs(int graph[V][V], int start) {
  int visited[V] = {0};

  int queue[V];
  int front = 0;
  int rear = 0;

  // Add starting vertex to queue
  queue[rear++] = start;
  visited[start] = 1;

  while (front < rear) {
    // Remove from queue
    int current = queue[front++];

    printf("%d ", current);

    // Find all neighbors
    for (int i = 0; i < V; i++) {
      if (graph[current][i] == 1 && !visited[i]) {
        queue[rear++] = i;
        visited[i] = 1;
      }
    }
  }
}

int main() {
  int graph[V][V] = {
      // 0  1  2  3  4  5
      {0, 1, 1, 0, 0, 0}, // 0
      {1, 0, 0, 1, 1, 0}, // 1
      {1, 0, 0, 0, 0, 1}, // 2
      {0, 1, 0, 0, 0, 0}, // 3
      {0, 1, 0, 0, 0, 0}, // 4
      {0, 0, 1, 0, 0, 0}  // 5
  };

  printf("BFS: ");
  bfs(graph, 0);

  return 0;
}
