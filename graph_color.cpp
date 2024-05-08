#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size())
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; 
        }
    }
    return false;
}

void graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);

    if (graphColoringUtil(graph, m, color, 0)) {
        cout << "Graph coloring possible with at most " << m << " colors. Colors assigned to vertices are:" << endl;
        for (int i = 0; i < graph.size(); i++)
            cout << "Vertex " << i << ": Color " << color[i] << endl;
    } else {
        cout << "Graph coloring not possible with " << m << " colors." << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; 

    graphColoring(graph, m);

    return 0;
}
