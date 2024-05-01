#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << "currently on: " << current << endl;

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void DFS(int current, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[current] = true; // marking the active node as visited
    cout << "currently on: " << current << endl;
    for (auto node : graph[current])
    { // iterate through all of its neighbors
        if (!visited[node])
        {
            DFS(node, graph, visited); // send DFS if it's a new node
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    cout << "enter values";
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << "BFS Output:\n";
    BFS(0, graph, visited); // starting algorithm from node 1

    fill(visited.begin(), visited.end(), false);

    cout << "\nDFS Output:\n";
    DFS(0, graph, visited); // starting algorithm from node 1

    return 0;
}
