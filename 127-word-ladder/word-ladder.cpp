class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        vector<int> vis(n, 0);

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {

            string b = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(b == endWord)
                return steps;

            for(int i = 0; i < n; i++) {

                if(vis[i]) continue;

                string a = wordList[i];

                int cnt = 0;

                for(int j = 0; j < a.size(); j++) {
                    if(a[j] != b[j])
                        cnt++;
                }

                if(cnt == 1) {
                    vis[i] = 1;
                    q.push({a, steps + 1});
                }
            }
        }

        return 0;
    }
};