class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lo = 0;
        int high = m - 1;

        while (lo <= high) {
            int mid = lo + (high - lo) / 2;

            int maxRow = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int left  = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid < m - 1) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > left &&
                mat[maxRow][mid] > right) {
                return {maxRow, mid};
            }
            else if (left > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return {-1, -1};
    }
};