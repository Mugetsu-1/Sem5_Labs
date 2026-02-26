#include <iostream>
#include <climits>
using namespace std;

long long steps = 0;
#define INF 1000000000

void floydWarshall(int graph[100][100], int V) {
    int dist[100][100];

    // Initialize distance matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            steps++;
            dist[i][j] = graph[i][j];
        }

    // Main algorithm
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                steps++;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }

    cout << "\nAll-Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            steps++;
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter adjacency matrix (1000000000 for INF):\n";

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            steps++;
            cin >> graph[i][j];
        }

    floydWarshall(graph, V);

    cout << "\nTotal Steps: " << steps << endl;
    return 0;
}