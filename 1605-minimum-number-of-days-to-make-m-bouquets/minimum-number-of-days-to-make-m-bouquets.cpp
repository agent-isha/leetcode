class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long required = 1LL * m * k;

        if (required > bloomDay.size())
            return -1;

        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                hi = mid - 1;   // try smaller day
            } else {
                lo = mid + 1;   // need more days
            }
        }

        return ans;
    }
};