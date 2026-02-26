#include <iostream>
#include <climits>
using namespace std;

long long steps = 0;

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {
        steps++;
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMSTPath(int parent[], int v) {
    steps++;
    if (parent[v] == -1) {
        cout << (char)('A' + v);
        return;
    }
    printMSTPath(parent, parent[v]);
    cout << " -> " << (char)('A' + v);
}

void primMST(int graph[100][100], int V) {
    int parent[100];
    int key[100];
    bool mstSet[100];

    for (int i = 0; i < V; i++) {
        steps++;
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;        // Start from vertex A (0)

    for (int count = 0; count < V - 1; count++) {
        steps++;
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            steps++;
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "\nEdges in MST:\n";
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++) {
        steps++;
        cout << (char)('A' + parent[i]) << " - "
             << (char)('A' + i) << "\t"
             << graph[i][parent[i]] << endl;
    }

    cout << "\nPaths in MST (from A):\n";
    for (int i = 0; i < V; i++) {
        steps++;
        cout << "A -> " << (char)('A' + i) << " : ";
        printMSTPath(parent, i);
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

    primMST(graph, V);

    cout << "\nTotal Steps:" << steps << endl;
    return 0;
}
