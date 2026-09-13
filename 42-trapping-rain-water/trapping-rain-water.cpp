class Solution {
public:
    int trap(vector<int>& nums2) {
        int n = nums2.size();

        vector<int> left(n);
        vector<int> right(n);

        
        left[0] = nums2[0];

        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], nums2[i]);
        }

        
        right[n-1] = nums2[n-1];

        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], nums2[i]);
        }

        int sum = 0;

        for(int i = 0; i < n; i++) {
            int waterLevel = min(left[i], right[i]);

            sum += waterLevel - nums2[i];
        }

        return sum;
    }
};