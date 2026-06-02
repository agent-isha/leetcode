class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        
        while(lo<=high){
            long long height=0;
            int mid=lo +(high-lo)/2;
            for(int x:piles){
                height+=(x+mid-1)/mid;

            }
            if(height<=h){
                ans=mid;
                high=mid-1;
            }
            if(height>h){
                lo=mid+1;

            }
        }
        return ans;
        
        
    }
};