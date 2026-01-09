class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        
        int maxi1=height[n-1];
        for(int i=n-1;i>=0;i--){
            rightmax[i]=maxi1;
            if(height[i]>maxi1){
                maxi1=height[i];
            }
            

        }
        int maxi2=height[0];
        for(int i=0;i<n-1;i++){
            leftmax[i]=maxi2;
            if(height[i]>maxi2){
                maxi2=height[i];
            }
            
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(leftmax[i]>height[i] && rightmax[i]>height[i])
            total+=min(leftmax[i],rightmax[i])-height[i];

        }
        return total;
        
    }
};