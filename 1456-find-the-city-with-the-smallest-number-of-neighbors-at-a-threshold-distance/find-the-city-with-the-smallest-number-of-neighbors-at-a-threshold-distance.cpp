class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int minReachable = INT_MAX;
        int ans = -1;

        for(int src = 0; src < n; src++){

            vector<int> dist(n, INT_MAX);

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            dist[src] = 0;
            pq.push({0, src});

            while(!pq.empty()){

                auto [currDist, node] = pq.top();
                pq.pop();

                if(currDist > dist[node]) continue;

                for(auto &[adjNode, wt] : adj[node]){

                    if(currDist + wt < dist[adjNode]){

                        dist[adjNode] = currDist + wt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            int cnt = 0;

            for(int i = 0; i < n; i++){
                if(dist[i] <= distanceThreshold)
                    cnt++;
            }

            
            if(cnt <= minReachable){
                minReachable = cnt;
                ans = src;
            }
        }

        return ans;
    }
};