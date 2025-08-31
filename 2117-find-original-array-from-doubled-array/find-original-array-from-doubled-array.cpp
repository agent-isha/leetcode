class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        int a = c.size();
        if (a % 2 != 0) {
            return {}; 
        }

        sort(c.begin(), c.end()); 

        vector<int> result;
        unordered_map<int, int> freq;

       
        for (int num : c) {
            freq[num]++;
        }

        for (int num : c) {
            if (freq[num] == 0) continue;

            if (freq[2 * num] == 0) {
                return {};
            }

            result.push_back(num);
            freq[num]--;
            freq[2 * num]--;
        }

        return result;
    }
};
