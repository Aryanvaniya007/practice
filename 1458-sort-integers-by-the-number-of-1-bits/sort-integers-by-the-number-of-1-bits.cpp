class Solution {
public:
    // Helper function to count number of 1s in binary representation
    int countBits(int n) {
        int count = 0;
        while (n) {
            count += (n & 1); // add 1 if last bit is set
            n >>= 1;          // shift right
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int countA = countBits(a);
            int countB = countBits(b);
            if (countA == countB) {
                return a < b; // sort by value if same bit count
            }
            return countA < countB; // otherwise sort by bit count
        });
        return arr;
    }
};