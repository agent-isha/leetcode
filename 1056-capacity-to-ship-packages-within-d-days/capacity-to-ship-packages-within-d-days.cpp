class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int lo = *max_element(weights.begin(), weights.end());;
        int high=sum;
        int ans=0;
        while(lo<=high){
            int day=1;
            int weight=0;

            int mid=lo+(high-lo)/2;
            for(int i=0;i<weights.size();i++){
                if(weight+weights[i]<=mid){
                    weight+=weights[i];
                }else{
                    day++;
                    weight=weights[i];
                }
            }
            if(day<=days){
                ans=mid;
                high=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
};