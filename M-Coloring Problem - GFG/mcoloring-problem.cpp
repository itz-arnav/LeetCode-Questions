// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
const int N = 20;
int color[N];

bool check(int u, int n, int c, bool graph[101][101]) {
    for (int v = 0; v < n; v++) {
        if (u != v && graph[u][v] && color[v] == c)
            return true;
    }
    return false;
}

bool help(int u, int n, int m, bool graph[101][101]) {
    if (u == n)
        return true;
    for (int c = 0; c < m; c++) {
        if (check(u, n, c, graph))
            continue;
        color[u] = c;
        if (help(u + 1, n, m, graph))
            return true;
        color[u] = -1;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    memset(color, -1, sizeof(color));
    return help(0, n, m, graph);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends