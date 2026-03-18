class Solution {
public:
    string sortSentence(string s) {
        string word;
        vector<string> v(10);  // enough slots for digits 0–9
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                v[s[i] - '0'] = word;  // store word only
                word = "";
                i++; // skip the digit
            } else {
                word += s[i];
            }
        }
        string ans;
        for (string x : v) {
            if (!x.empty()) {
                if (!ans.empty()) ans += " "; // add space between words
                ans += x;
            }
        }
        return ans;
    }
};