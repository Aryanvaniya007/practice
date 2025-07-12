class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracket_map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (st.empty()) {
                    return false;
                } else if (st.top() == bracket_map[c]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};