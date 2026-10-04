//TC-O(N) //APPROACH-GREEDY
class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;  // range of possible open-paren counts
        for (char c : s) {
            if (c == '(') {
                lo++; hi++;
            } else if (c == ')') {
                lo--; hi--;
            } else {          // '*'
                lo--; hi++;
            }
            if (hi < 0) return false;   // too many ')'
            lo = max(lo, 0);            // can't go negative
        }
        return lo == 0;
    }
};
