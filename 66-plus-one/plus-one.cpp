class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    // Traverse the array in reverse
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;  // No carry needed, return directly
        }
        digits[i] = 0;  // Set current digit to 0 and carry over
    }
    
    // If we reach here, all digits were 9 (e.g., 999 -> 1000)
    digits.insert(digits.begin(), 1);
    return digits;
}
        
    
};