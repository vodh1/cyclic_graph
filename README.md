# Graph Cycle Detection Program

This C++ program determines if a given graph (represented as a 2D adjacency matrix) is cyclic or not, and displays the vertices in the cycle if one exists.

## Features

- **Two Implementation Approaches:**
  1. **DFS (Depth-First Search):** Uses recursive depth-first search with recursion stack to detect cycles
  2. **BFS (Breadth-First Search):** Uses topological sorting approach with in-degree counting to detect cycles

- **Cycle Detection:** Both methods can detect cycles in directed graphs
- **Cycle Path Display:** When a cycle is found, the program displays the vertices that form the cycle
- **Multiple Test Cases:** Includes various test scenarios to demonstrate the functionality

## Algorithm Details

### DFS Approach
- Uses a recursive depth-first search with two arrays:
  - `visited[]`: tracks visited vertices
  - `recStack[]`: tracks vertices in the current recursion stack
- Detects back edges to identify cycles
- Time Complexity: O(V + E) where V is vertices and E is edges
- Space Complexity: O(V) for recursion stack

### BFS Approach
- Uses topological sorting with in-degree counting
- Processes vertices with in-degree 0 first
- If not all vertices can be processed, a cycle exists
- When a cycle is detected, uses DFS to find the actual cycle path
- Time Complexity: O(V + E)
- Space Complexity: O(V)

## Compilation and Execution

### Using Makefile (Recommended)
```bash
# Compile the program
make

# Run the program
make run

# Clean compiled files
make clean
```

### Manual Compilation
```bash
# Compile with g++
g++ -std=c++11 -Wall -Wextra -O2 -o cyclic_graph cyclic_graph.cpp

# Run the program
./cyclic_graph
```

## Test Cases Included

1. **Cyclic Graph:** A 5-vertex graph with a cycle (0→1→2→3→4→0)
2. **Acyclic Graph:** A 5-vertex directed acyclic graph
3. **Self-loop Graph:** A 3-vertex graph with a self-loop at vertex 0

## Output Format

For each test case, the program displays:
- The adjacency matrix representation
- Results from both DFS and BFS approaches
- Whether a cycle is detected
- If a cycle exists, the vertices forming the cycle

## Example Output

```
=== Graph Cycle Detection Program ===

Test Case 1: Cyclic Graph
Adjacency Matrix:
0 1 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
1 0 0 0 0 

Using DFS:
Cycle detected!
Cycle vertices: 0 1 2 3 4 0

Using BFS:
Cycle detected!
Cycle vertices: 0 1 2 3 4 0
```

## Graph Representation

The program uses a 2D adjacency matrix where:
- `matrix[i][j] = 1` indicates an edge from vertex i to vertex j
- `matrix[i][j] = 0` indicates no edge from vertex i to vertex j

## Requirements

- C++11 compatible compiler (g++, clang++, or MSVC)
- Standard C++ libraries (no external dependencies)

## Notes

- The program handles directed graphs
- Self-loops are considered cycles
- Both implementations are deterministic and will find the same cycles
- The cycle path may vary slightly between DFS and BFS due to different traversal orders 