class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            vector<int>temp;
            while(a>0){
                
                temp.push_back(a%10);
                a=a/10;
            }
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                v.push_back(temp[j]);
            }
        }
        return v;
     
    }
};