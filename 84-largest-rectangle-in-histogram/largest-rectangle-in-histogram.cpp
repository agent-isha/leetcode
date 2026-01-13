class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ns(n);
        vector<int>ps(n);
        vector<int>v;
        stack<int>s;
        stack<int>s1;
        for(int i=0;i<n;i++){
            while(!s.empty()&& heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty() && heights[s.top()]<heights[i]){
                ps[i]=s.top();

            }else{
                ps[i]=-1;
            }
            s.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s1.empty()&& heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(!s1.empty() && heights[s1.top()]<heights[i]){
                ns[i]= s1.top();

            }else{
                ns[i]= n;
            }
            s1.push(i);
        }
        for(int i=0;i<n;i++){
            int total=0;
            total=(ns[i]-ps[i]-1)*heights[i];
            v.push_back(total);
        }
        int b=*max_element(v.begin(),v.end());
        return b;
    }
};