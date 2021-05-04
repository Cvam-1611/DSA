#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void topological_sort(vector<int> graph[], vector<bool>& visited,vector<int>& result, int node)
{
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]])
           topological_sort(graph, visited, result, graph[node][i]);
    }
    result.push_back(node);
}

int main() {
    vector<int> graph[5];
    vector<bool> visited(5, false);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    
    vector<int> result ;
    cout << "Topological sort using DFS: " << endl;
    topological_sort(graph, visited, result, 0);
    for (int i=result.size()-1; i >= 0; i--)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}