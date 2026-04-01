class Solution {
public:
    int reverse(int x) {
        int n = 0;
       while (x != 0) {
            int pop = x % 10;   // get the last digit (works for negative numbers too)
            x /= 10;            // remove the last digit
            
            // Check for overflow before multiplying by 10 and adding the digit
            if (n > INT_MAX / 10 || (n == INT_MAX / 10 && pop > 7))
                return 0;       // positive overflow
            if (n < INT_MIN / 10 || (n == INT_MIN / 10 && pop < -8))
                return 0;       // negative overflow
            
            n = n * 10 + pop;
        }
        
        return n;
    }
};