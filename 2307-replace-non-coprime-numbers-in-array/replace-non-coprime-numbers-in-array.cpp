class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        s.push(nums[0]);
        for(int i=1;i<n;i++){
            int curr=nums[i];
            
            while(!s.empty() && gcd(s.top(),curr)>1){
                
                curr=lcm(s.top(),curr);
                s.pop();
            }
            s.push(curr);
                

        }
        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
        return v;

        
    }
};