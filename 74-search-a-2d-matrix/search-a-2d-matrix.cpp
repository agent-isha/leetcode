class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool search=false;
        int row=matrix.size();
        int col=matrix[0].size();
        int lo=0;
        int high=row*col-1;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            int r=mid/col;
            int c=mid%col;
            if(matrix[r][c]==target){
                search=true;
                break;
            }else if(matrix[r][c]<target){
                lo=mid+1;
            }else{
                high=mid-1;
            }
        }
        return search;
        
    }
};