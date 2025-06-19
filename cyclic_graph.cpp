#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int vertices;

public:
    Graph(const vector<vector<int>>& matrix) : adjacencyMatrix(matrix) {
        vertices = matrix.size();
    }

    // DFS implementation for cycle detection
    bool hasCycleDFS(vector<int>& cycleVertices) {
        vector<bool> visited(vertices, false);
        vector<bool> recStack(vertices, false);
        vector<int> parent(vertices, -1);
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (dfsUtil(i, visited, recStack, parent, cycleVertices)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfsUtil(int vertex, vector<bool>& visited, vector<bool>& recStack, 
                 vector<int>& parent, vector<int>& cycleVertices) {
        visited[vertex] = true;
        recStack[vertex] = true;
        
        for (int neighbor = 0; neighbor < vertices; neighbor++) {
            if (adjacencyMatrix[vertex][neighbor] == 1) {
                if (!visited[neighbor]) {
                    parent[neighbor] = vertex;
                    if (dfsUtil(neighbor, visited, recStack, parent, cycleVertices)) {
                        return true;
                    }
                } else if (recStack[neighbor]) {
                    // Found a back edge, cycle detected
                    cycleVertices.clear();
                    int current = vertex;
                    while (current != neighbor) {
                        cycleVertices.push_back(current);
                        current = parent[current];
                    }
                    cycleVertices.push_back(neighbor);
                    cycleVertices.push_back(vertex);
                    reverse(cycleVertices.begin(), cycleVertices.end());
                    return true;
                }
            }
        }
        
        recStack[vertex] = false;
        return false;
    }

public:
    // BFS implementation for cycle detection
    bool hasCycleBFS(vector<int>& cycleVertices) {
        vector<int> inDegree(vertices, 0);
        
        // Calculate in-degree for each vertex
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    inDegree[j]++;
                }
            }
        }
        
        queue<int> q;
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);
        
        // Add vertices with in-degree 0 to queue
        for (int i = 0; i < vertices; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        int visitedCount = 0;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visitedCount++;
            
            for (int neighbor = 0; neighbor < vertices; neighbor++) {
                if (adjacencyMatrix[current][neighbor] == 1) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0 && !visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                        parent[neighbor] = current;
                    }
                }
            }
        }
        
        // If not all vertices are visited, there's a cycle
        if (visitedCount != vertices) {
            // Find a vertex that's part of a cycle
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    // Use DFS to find the cycle starting from this vertex
                    vector<bool> dfsVisited(vertices, false);
                    vector<bool> dfsRecStack(vertices, false);
                    vector<int> dfsParent(vertices, -1);
                    if (dfsUtil(i, dfsVisited, dfsRecStack, dfsParent, cycleVertices)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    void printMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Graph Cycle Detection Program ===" << endl << endl;
    
    // Test case 1: Cyclic graph
    cout << "Test Case 1: Cyclic Graph" << endl;
    vector<vector<int>> cyclicMatrix = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}
    };
    
    Graph cyclicGraph(cyclicMatrix);
    cyclicGraph.printMatrix();
    
    vector<int> cycleVertices;
    
    // DFS approach
    cout << "Using DFS:" << endl;
    if (cyclicGraph.hasCycleDFS(cycleVertices)) {
        cout << "Cycle detected!" << endl;
        cout << "Cycle vertices: ";
        for (int vertex : cycleVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    cout << endl;
    
    // BFS approach
    cout << "Using BFS:" << endl;
    if (cyclicGraph.hasCycleBFS(cycleVertices)) {
        cout << "Cycle detected!" << endl;
        cout << "Cycle vertices: ";
        for (int vertex : cycleVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    cout << endl;
    
    return 0;
} 