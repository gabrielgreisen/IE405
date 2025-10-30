#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;



bool isBipartite(int **G, int n) {
    vector<int> color(n, -1);

    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) continue;

        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (G[u][u] == 1) return false;

            for (int v = 0; v < n; ++v) {
                if (!G[u][v]) continue;

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input-graph.txt");
    if (!fin) {
        cerr << "Error: could not open input-graph.txt\n";
        return 1;
    }

    int n;
    if (!(fin >> n) || n <= 0) {
        cerr << "Error: invalid number of nodes.\n";
        return 1;
    }

    int **G = new int*[n];
    for (int i = 0; i < n; ++i) G[i] = new int[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(fin >> G[i][j])) {
                cerr << "Error: invalid or incomplete adjacency matrix.\n";
                for (int k = 0; k < n; ++k) delete[] G[k];
                delete[] G;
                return 1;
            }
        }
    }

    if (isBipartite(G, n)) {
        cout << "Graph is bipartite.\n";
    } else {
        cout << "Graph is not bipartite.\n";
    }

    for (int i = 0; i < n; ++i) delete[] G[i];
    delete[] G;
    return 0;
}
