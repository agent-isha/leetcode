class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        stack<int>s1;
        stack<int>s2;
        stack<int>s3;
        vector<int>left1(n);
        vector<int>right1(n);
        
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
        long long total=0;
        
        for(int i=0;i<n;i++){
            long long leftcount=i-left[i];
            long long rightcount=right[i]-i;
            long long contri=(arr[i]*leftcount);
            contri=(contri*rightcount);
            total=(total+contri);
        }
        
        int mini1=arr[0];
        for(int i=0;i<n;i++){
            while(!s2.empty() && arr[s2.top()]<arr[i]){
                s2.pop();
            }
            if(s2.empty()){
                left1[i]=-1;
            }else{
                left1[i]=s2.top();
            }
            s2.push(i);


        }
        for(int i=n-1;i>=0;i--){
            


            while(!s3.empty() && arr[s3.top()]<=arr[i]){
                s3.pop();
            }
            if(s3.empty()){
                right1[i]=n;
            }else{
                right1[i]=s3.top();
            }
            s3.push(i);


        }
        long long total1=0;
        
        for(int i=0;i<n;i++){
            long long leftcount=i-left1[i];
            long long rightcount=right1[i]-i;
            long long contri=(arr[i]*leftcount);
            contri=(contri*rightcount);
            total1=(total1+contri);
        }
        return total1-total;
        

        
    }
};