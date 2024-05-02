#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

// Function prototypes
vector<pair<char, int>> get_neighbors(char v);
int heuristic(char n);
vector<char> aStarAlgo(char start_node, char stop_node);

// Graph definition
unordered_map<char, vector<pair<char, int>>> Graph_nodes = {
    {'A', {{'B', 2}, {'E', 3}}},
    {'B', {{'A', 2}, {'C', 1}, {'G', 9}}},
    {'C', {{'B', 1}}},
    {'D', {{'E', 6}, {'G', 1}}},
    {'E', {{'A', 3}, {'D', 6}}},
    {'G', {{'B', 9}, {'D', 1}}}
};

// A* algorithm function
vector<char> aStarAlgo(char start_node, char stop_node) {
    unordered_set<char> open_set{start_node};
    unordered_set<char> closed_set;
    unordered_map<char, int> g;
    unordered_map<char, char> parents;
    g[start_node] = 0;
    parents[start_node] = start_node;

    while (!open_set.empty()) {
        char n = '\0';
        for (char v : open_set) {
            if (n == '\0' || g[v] + heuristic(v) < g[n] + heuristic(n)) {
                n = v;
            }
        }
        if (n == stop_node || Graph_nodes[n].empty()) {
            // Pass
        } else {
            for (auto& [m, weight] : get_neighbors(n)) {
                if (open_set.find(m) == open_set.end() && closed_set.find(m) == closed_set.end()) {
                    open_set.insert(m);
                    parents[m] = n;
                    g[m] = g[n] + weight;
                } else {
                    if (g[m] > g[n] + weight) {
                        g[m] = g[n] + weight;
                        parents[m] = n;
                        if (closed_set.find(m) != closed_set.end()) {
                            closed_set.erase(m);
                            open_set.insert(m);
                        }
                    }
                }
            }
        }
        if (n == '\0') {
            cout << "Path does not exist!" << endl;
            return {};
        }
        if (n == stop_node) {
            vector<char> path;
            while (parents[n] != n) {
                path.push_back(n);
                n = parents[n];
            }
            path.push_back(start_node);
            reverse(path.begin(), path.end());
            cout << "Path found: ";
            for (char node : path) {
                cout << node << " ";
            }
            cout << endl;
            return path;
        }
        open_set.erase(n);
        closed_set.insert(n);
    }
    cout << "Path does not exist!" << endl;
    return {};
}

// Function to retrieve neighbors of a node
vector<pair<char, int>> get_neighbors(char v) {
    if (Graph_nodes.find(v) != Graph_nodes.end()) {
        return Graph_nodes[v];
    } else {
        return {};
    }
}

// Heuristic function
int heuristic(char n) {
    unordered_map<char, int> H_dist = {
        {'A', 11},
        {'B', 6},
        {'C', 99},
        {'D', 1},
        {'E', 7},
        {'G', 0}
    };
    return H_dist[n];
}

// Main function
int main() {
    aStarAlgo('A', 'G');
    return 0;
}
