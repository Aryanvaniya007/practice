class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  // sqrt(0) = 0, sqrt(1) = 1

        int left = 1, right = x, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;       // store the floor of sqrt
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
