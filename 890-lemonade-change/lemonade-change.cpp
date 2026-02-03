class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0;
        int ten=0;
        bool lemo=true;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five=five+1;
            }else if(bills[i]==10){
                ten+=1;
                if(five>=1){
                    five=five-1;

                }else{
                    lemo=false;
                }

            }else{
                if(ten>=1 && five>=1){
                    ten=ten-1;
                    five=five-1;
                }else if(five>=3){
                    five=five-3;
                }else{
                    lemo=false;
                }
            }
        }
        return lemo;
        
    }
};