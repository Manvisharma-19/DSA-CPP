class Solution {
public:
    typedef pair<int, int> P;  // {distance, node}

    int minCost(int n, vector<vector<int>>& edges) {

        // Adjacency list: node -> {neighbor, cost}
        unordered_map<int, vector<P>> adj;

        // Build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});        // original edge
            adj[v].push_back({u, 2 * wt});    // reversed edge with extra cost
        }

        // Min-heap priority queue
        priority_queue<P, vector<P>, greater<P>> pq;

        // Distance array
        vector<int> result(n, INT_MAX);
        result[0] = 0;

        // Start from node 0
        pq.push({0, 0});

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If destination reached
            if (node == n - 1) {
                return result[n - 1];
            }

            // Skip outdated entries
            if (d > result[node]) continue;

            // Relax edges
            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        return -1; // destination not reachable
    }
};
