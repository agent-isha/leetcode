class Solution {
public:
    long long flowerGame(int n, int m) {
        long long e1;
        long long o1;
        long long e2;
        long long o2;
        if(n%2==0){
            e1=n/2;
            o1=n/2;
        }else{
            e1=n/2;
            o1=(n/2)+1;
        }
        if(m%2==0){
            e2=m/2;
            o2=m/2;
        }else{
            e2=m/2;
            o2=(m/2)+1;
        }
        long long a=e1*o2 +o1*e2;
        return a;
    }
};