class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end()); // Sort characters in the word
            anagramGroups[sortedWord].push_back(word);  // Use sorted string as key
        }

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second); // Collect grouped anagrams
        }

        return result;
    }
};