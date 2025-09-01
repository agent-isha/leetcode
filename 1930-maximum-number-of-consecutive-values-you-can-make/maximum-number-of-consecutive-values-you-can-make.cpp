class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int sum=0;
        sort(coins.begin(),coins.end());
        for(int i=0;i<coins.size();i++){
            
            if(sum+1<coins[i]){
                break;
                return sum+1;
            }else{
                sum+=coins[i];
            }

        }
        return sum+1;
        
    }
};