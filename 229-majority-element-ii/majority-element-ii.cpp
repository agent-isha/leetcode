class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }else if(ele1==nums[i]){
                cnt1++;
            }else if(ele2==nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int>list;
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]){
                a++;
            }if(ele2==nums[i]){
                b++;
            }
        }
        int mini=int(n/3)+1;
        if(a>=mini){
            list.push_back(ele1);

        }
        if(b>=mini){
            list.push_back(ele2);
        }
        return list;

        
    }
};