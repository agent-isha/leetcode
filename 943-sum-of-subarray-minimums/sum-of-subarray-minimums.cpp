class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        stack<int>s1;
        
        int mini=arr[0];
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
            s.push(i);


        }
        for(int i=n-1;i>=0;i--){
            


            while(!s1.empty() && arr[s1.top()]>=arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                right[i]=n;
            }else{
                right[i]=s1.top();
            }
            s1.push(i);


        }
        int total=0;
        const int MOD = 1e9 + 7;
        for(int i=0;i<n;i++){
            long long leftcount=i-left[i];
            long long rightcount=right[i]-i;
            long long contri=(arr[i]*leftcount)%MOD;
            contri=(contri*rightcount)%MOD;
            total=(total+contri)%MOD;
        }
        return total;
        
        
    }
};