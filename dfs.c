#include <stdio.h>

#define V 5

void dfs(int graph[V][V], int visited[V], int vertex) {
  // Visit the current vertex
  visited[vertex] = 1;
  printf("%d ", vertex);

  // Visit all adjacent vertices
  for (int i = 0; i < V; i++) {
    if (graph[vertex][i] == 1 && !visited[i]) {
      dfs(graph, visited, i);
    }
  }
}

int main() {
  int graph[V][V] = {
      // 0  1  2  3  4
      {0, 1, 1, 0, 0}, // 0
      {1, 0, 0, 1, 1}, // 1
      {1, 0, 0, 0, 0}, // 2
      {0, 1, 0, 0, 0}, // 3
      {0, 1, 0, 0, 0}  // 4
  };

  int visited[V] = {0};

  printf("DFS traversal: ");
  dfs(graph, visited, 0);

  return 0;
}
