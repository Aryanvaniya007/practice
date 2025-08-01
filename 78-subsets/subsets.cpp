class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_subset;
        
        function<void(int)> backtrack = [&](int start) {
            result.push_back(current_subset);
            
            for (int i = start; i < nums.size(); ++i) {
                current_subset.push_back(nums[i]);
                backtrack(i + 1);
                current_subset.pop_back();
            }
        };
        
        backtrack(0);
        return result;
    }
};