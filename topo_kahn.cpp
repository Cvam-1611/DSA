#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
}

vector<int> topological_sort(vector<int> graph[], int size)
{
    queue<int>q;
    vector<int>result;
    vector<int>indegree(size,0);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            indegree[graph[i][j]]++;
        }
    }
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int v=q.front();
        result.push_back(v);
        q.pop();
        for(int i=0;i<graph[v].size();i++)
        {
            indegree[graph[v][i]]--;
            if(indegree[graph[v][i]]==0)
                q.push(graph[v][i]);

        }

    }
    return result;

}

int main() {
    int size = 5;
    vector<int> graph[size];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    vector<int> result = topological_sort(graph, size);
    if (result.size() != size)
       cout << "Topological sort not possible" << endl;
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i=0;i<result.size();i++)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}