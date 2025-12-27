class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;

        if (dividend == divisor) {
            return 1;
        }

        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        if (dividend < 0 && divisor >= 0) sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            n = n - (d << cnt);
        }

        if (ans > INT_MAX && sign == true) return INT_MAX;
        if (ans > INT_MAX && sign == false) return INT_MIN;

        if (!sign) return -ans;
        return ans;
    }
};
