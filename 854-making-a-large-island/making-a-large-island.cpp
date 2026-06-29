class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                int node = i * n + j;

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    continue;

                unordered_set<int> st;

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int parent = ds.findUPar(nr * n + nc);
                        st.insert(parent);
                    }
                }

                int sizeTotal = 1;

                for (auto parent : st)
                    sizeTotal += ds.size[parent];

                ans = max(ans, sizeTotal);
            }
        }

        
        for (int i = 0; i < n * n; i++) {
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }

        return ans;
    }
};