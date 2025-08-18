class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        vector<vector<int>> v1;
        vector<int> v;

        // Find overlapping intervals
        for (int i = 0; i < in.size(); i++) {
            if (!(n[1] < in[i][0] || n[0] > in[i][1])) {
                v.push_back(i);
            }
        }

        // If there's no overlap, insert in correct position
        if (v.empty()) {
            bool inserted = false;
            for (int i = 0; i < in.size(); i++) {
                if (!inserted && n[0] < in[i][0]) {
                    v1.push_back(n);
                    inserted = true;
                }
                v1.push_back(in[i]);
            }
            if (!inserted) {
                v1.push_back(n);
            }
            return v1;
        }

        // Add intervals before the merged section
        for (int i = 0; i < v[0]; i++) {
            v1.push_back(in[i]);
        }

        // Merge overlapping intervals with n
        vector<int> b;
        int c = min(in[v[0]][0], n[0]);
        int d = max(in[v[v.size() - 1]][1], n[1]);
        b.push_back(c);
        b.push_back(d);
        v1.push_back(b);

        // Add intervals after the merged section
        for (int i = v[v.size() - 1] + 1; i < in.size(); i++) {
            v1.push_back(in[i]);
        }

        return v1;
    }
};
