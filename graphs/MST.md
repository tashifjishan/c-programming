# Minimum Spanning Tree (MST)

- A spanning tree of a graph is a subgraph that:
    - Includes all vertices
    - Is connected
    - Has no cycles

If a graph has V vertices, a spanning tree has exactly V − 1 edges.

#  Minimum Spanning Tree (MST)

A Minimum Spanning Tree is a spanning tree of a connected, weighted, undirected graph such that:

- All vertices are connected
- No cycles are present
- The sum of edge weights is minimum

MST minimizes total cost, not distance between two specific nodes.

# Important Properties

- MST always has V − 1 edges
- MST is unique if all edge weights are distinct
- Multiple MSTs may exist if weights are same
- MST does not exist for disconnected graphs
- Removing any edge from MST → graph becomes disconnected
- Adding any extra edge → creates a cycle

# Steps to find MST:


- Sort all edges by increasing weight
- Pick the smallest edge
- Add it only if it does not form a cycle
- Repeat until V − 1 edges are selected