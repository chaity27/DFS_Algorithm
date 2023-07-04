#include <iostream>
using namespace std;

const int V = 8; // Number of vertices

string node[V] = {"S", "A", "B", "C", "D", "E", "F", "G"};
int graph[V][V] = {
    {0, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0}
};

enum Color { WHITE, GREY, BLACK };
Color color[V];
int prv[V];
int d[V];
int f[V];
int time;

void DFS_Visit(int u) {
    color[u] = GREY;
    time = time + 1;
    d[u] = time;

    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1 && color[v] == WHITE) {
            prv[v] = u;
            DFS_Visit(v);
        }
    }

    color[u] = BLACK;
    time = time + 1;
    f[u] = time;
}

void DFS() {
    for (int u = 0; u < V; u++) {
        color[u] = WHITE;
        prv[u] = -1;
        f[u] = INT_MAX;
        d[u] = INT_MAX;
    }

    time = 0;
    for (int u = 0; u < V; u++) {
        if (color[u] == WHITE) {
            DFS_Visit(u);
        }
    }
}

int main() {
    DFS();

    // Print the results
    for (int u = 0; u < V; u++) {
        cout << "Node: " << node[u] << "\n";
        cout << "Discovery time (d): " << d[u] << "\n";
        cout << "Finishing time (f): " << f[u] << "\n";
        cout << "Previous vertex: ";
        if (prv[u] != -1) {
            cout << node[prv[u]] << "\n";
        } else {
            cout << "NIL\n";
        }
        cout << "\n";
    }

    return 0;
}

