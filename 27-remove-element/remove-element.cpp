class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer for the next position of a valid (not equal to val) number
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move the valid number to the front
                k++;
            }
        }
        return k;
    }
};
