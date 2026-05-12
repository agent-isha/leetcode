class Solution {
public:
    vector<int>left(vector<int>A){
        vector<int>ans(A.size());
        for(int i=0;i<A.size();i++){
            if(i!=0)ans[i-1]=A[i];
            else ans[A.size()-1]=A[0];
        }
        return ans;

    }
    vector<int>right(vector<int>A){
        vector<int>ans(A.size());
        for(int i=0;i<A.size();i++){
            ans[(i+1)%A.size()]=A[i];
        }
        return ans;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>matrix=mat;
        for(int i=0;i<k;i++){
            for(int j=0;j<mat.size();j++){
                if(j%2==0)matrix[j]=left(matrix[j]);
                else matrix[j]=right(matrix[j]);
            }
        }
        return (mat==matrix);
    }
};