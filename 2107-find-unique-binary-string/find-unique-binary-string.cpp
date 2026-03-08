class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;
        
        for (int i = 0; i < n; i++) {
            // Flip the diagonal bit: if nums[i][i] == '0', make it '1'; otherwise '0'
            result.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        
        return result;
    }
};