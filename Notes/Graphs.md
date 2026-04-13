**Cycle Detection: Undirected vs Directed**
In *undirected graphs*, using BFS/DFS with a parent check works because edges are bidirectional. During traversal, the only already-visited node you should encounter is your parent (the node you came from). If you find any other visited node, it means there exists an alternate path to the same node, which automatically forms a cycle.
In *directed graphs*, this logic fails because edges have direction. You can reach the same node through different paths (cross edges) without forming a cycle, since there may be no way to return back to the original node. Therefore, encountering a visited node does not guarantee a cycle. Instead, cycles in directed graphs are detected using DFS with a recursion stack (to detect back edges) or BFS = Kahn’s Algorithm (using indegrees).
*Cycle Detection in Directed Graph (DFS + Path Array)*
<!-- In directed graphs, we use DFS with two arrays: visited[] and path[] (recursion stack). A cycle is detected only when we encounter a node that is already in the current path (path[] = true), because this represents a back edge (a loop back to an active node). If we reach a node that is already visited but not in the current path, we safely ignore it, because DFS would have already explored all possible paths starting from that node earlier and confirmed that no cycle exists through it. Hence, revisiting such a node cannot form a new cycle. This guarantees correctness. -->
*Kahn’s Algorithm (Cycle Detection Guarantee)*
<!-- Kahn’s algorithm works by repeatedly removing nodes with indegree = 0 (nodes with no dependencies) and reducing the indegree of their neighbors. In a DAG (no cycle), there will always be at least one node with indegree 0 at every step, so all nodes eventually get processed. However, in a graph with a cycle, the nodes in the cycle depend on each other (circular dependency), so none of them can ever reach indegree 0. As a result, the algorithm gets stuck before processing all nodes. Therefore, if the number of processed nodes is less than the total number of nodes, a cycle must exist. -->
Example:
Consider the directed graph:
```A → B , B → C , C → A gives a cycle (A → B → C → A)
but if we had: A → B  , B → D , A → C, C → D
There is no cycle, even though we can reach D from both C and B, because there is no way to return back to A or any other node.
```    
