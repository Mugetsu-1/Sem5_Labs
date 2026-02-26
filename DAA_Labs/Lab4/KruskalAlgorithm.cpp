#include <iostream>
#include <algorithm>
using namespace std;

long long steps = 0;

struct Edge {
    int u, v, w;
};

int parent[100];

bool cmp(Edge a, Edge b) {
    steps++;
    return a.w < b.w;
}

int findSet(int x) {
    while (parent[x] != x) {
        steps++;
        x = parent[x];
    }
    steps++;
    return x;
}

void kruskal(Edge edge[], int V, int E) {

    sort(edge, edge + E, cmp);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        steps++;
    }

    int total = 0, cnt = 0;

    cout << "\nEdges in MST:\n";

    for (int i = 0; i < E && cnt < V - 1; i++) {
        steps++;

        int u = findSet(edge[i].u);
        int v = findSet(edge[i].v);

        if (u != v) {
            parent[u] = v;
            cout << (char)('A' + edge[i].u) << " - "
                 << (char)('A' + edge[i].v)
                 << " : " << edge[i].w << endl;

            total += edge[i].w;
            cnt++;
        }
    }

    cout << "Total MST Weight: " << total << endl;
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    Edge edge[100];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        steps++;
    }

    kruskal(edge, V, E);

    cout << "\nTotal Steps: " << steps << endl;
    return 0;
}