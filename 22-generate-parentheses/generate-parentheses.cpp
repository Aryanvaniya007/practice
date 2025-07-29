class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string current_string, int open_count, int close_count, int n) {
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }

        if (open_count < n) {
            current_string.push_back('(');
            backtrack(result, current_string, open_count + 1, close_count, n);
            current_string.pop_back();
        }

        if (close_count < open_count) {
            current_string.push_back(')');
            backtrack(result, current_string, open_count, close_count + 1, n);
            current_string.pop_back();
        }
    }
};
