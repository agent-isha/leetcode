class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;

        for (int x : a) {
            bool destroyed = false;

            while (!s.empty() && s.top() > 0 && x < 0) {
                if (abs(s.top()) < abs(x)) {
                    s.pop();         
                    continue;
                } 
                else if (abs(s.top()) == abs(x)) {
                    s.pop();          
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; 
                    break;
                }
            }

            if (!destroyed) {
                s.push(x);
            }
        }

        vector<int> ans(s.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
