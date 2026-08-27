class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count,
               string& target, int i, bool greater) {

        // We have constructed the complete permutation
        if (i == target.length()) {
            if (greater) {
                result = curr;
                return true;
            }
            return false;
        }

        // Try characters from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++) {

            // Character not available in s
            if (count[ch - 'a'] == 0)
                continue;

            // If we are still equal to target,
            // we cannot choose a character smaller than target[i]
            if (greater == false && ch < target[i])
                continue;

            // Choose character
            curr.push_back(ch);
            count[ch - 'a']--;

            // Once we choose a bigger character,
            // the whole string is already greater
            bool isGreater = greater || ch > target[i];

            // Recursively build the rest
            if (solve(curr, count, target, i + 1, isGreater)) {
                return true;
            }

            // Undo choice (backtracking)
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            count[ch - 'a']++;
        }

        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};
