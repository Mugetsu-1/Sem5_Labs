#include <iostream>
#include <climits>
using namespace std;

long long steps = 0;

int minDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {
        steps++;
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    steps++;
    if (parent[j] == -1) {
        cout << (char)('A' + j);
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << (char)('A' + j);
}

void dijkstra(int graph[100][100], int V, int src) {
    int dist[100];
    bool visited[100];
    int parent[100];

    for (int i = 0; i < V; i++) {
        steps++;
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        steps++;
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            steps++;
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nVertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        steps++;
        cout << (char)('A' + src) << " -> " << (char)('A' + i)
             << "\t" << dist[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter adjacency matrix (0 if no edge):\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            steps++;
            cin >> graph[i][j];
        }
    }

    char srcChar;
    cout << "Enter source vertex (A, B, C...): ";
    cin >> srcChar;

    int src = srcChar - 'A';

    dijkstra(graph, V, src);

    cout << "\nTotal Steps:" << steps << endl;
    return 0;
}
