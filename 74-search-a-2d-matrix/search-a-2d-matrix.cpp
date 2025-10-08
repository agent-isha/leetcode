class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int lo=0;
        int high=m*n-1;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            int row=mid/n;
            int col=mid%n;
            int midval=matrix[row][col];
            if(midval==target){
                return true;
            }else if(midval<target){
                lo=mid+1;

            }else{
                high=mid-1;
            }
        }
        return false;
        
    }
};