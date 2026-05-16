#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	pair<int, vector<vector<pair<int,int>>>> spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int,pair<int,int>>,
		               vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

		vector<int> vis(V, 0);
		// {wt, node,parent_node}
		pq.push({0, {0, -1}});
		int sum = 0;
        vector<vector<pair<int,int>>> mst(V);
        while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second.first;
			int wt = it.first;
			int parent = it.second.second;
			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
            if(parent != -1) {
            mst[parent].push_back({node, wt});
            mst[node].push_back({parent, wt});}
            
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, {adjNode, node}});
				}
			}
		}
		return {sum, mst};
	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	auto result = obj.spanningTree(V, adj);
	int sum = result.first;
	vector<vector<pair<int,int>>> mst = result.second;
	cout << "The sum of all the edge weights: " << sum << endl;
	cout << "The Minimum Spanning Tree is:" << endl;
	for (int i = 0; i < V; i++) {
		for (auto it : mst[i]) {
			cout << i << " - " << it.first << " with weight " << it.second << endl;
		}
	}

	return 0;
}
