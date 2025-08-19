class Solution {
public:
    bool judgeSquareSum(int c) {
        int d;
       
        for(long long  i=0;i*i<=c;i++){
            long long b=c-i*i;
            double d=sqrt(b);
            if(d==(int)d){
                return true;
                break;
            }

        }
        
        return false;
        
        

        
    }
};