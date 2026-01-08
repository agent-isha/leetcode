class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>v(n);
        vector<int>p;
        
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                v[i]=-1;
            }else{
                v[i]=s.top();
            }
            s.push(nums2[i]);

        }
        int a=nums1.size();
        for(int i=0;i<a;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    p.push_back(v[j]);
                    break;

                }
            }
        }
        return p;
        
    }
};