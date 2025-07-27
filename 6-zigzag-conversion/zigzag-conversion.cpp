#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currentRow].push_back(c);

            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }

            if (currentRow == numRows) {
                currentRow = numRows - 2;
                goingDown = false;
            } else if (currentRow == -1) {
                currentRow = 1;
                goingDown = true;
            }
        }

        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};
