#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        if (!isPalindromePossible(cnt))
            return "";

        vector<int> halfCount(26, 0);
        string midLetter = "";

        getHalfCountAndMidLetter(cnt, halfCount, midLetter);

        int totalPerm = calculateTotalPermutations(halfCount);

        if (k > totalPerm)
            return "";

        vector<char> leftHalf = generateLeftHalf(halfCount, k);

        string ans = "";
        for (char c : leftHalf)
            ans += c;

        ans += midLetter;

        reverse(leftHalf.begin(), leftHalf.end());

        for (char c : leftHalf)
            ans += c;

        return ans;
    }

private:
    bool isPalindromePossible(vector<int>& cnt) {
        int odd = 0;

        for (int x : cnt)
            if (x % 2)
                odd++;

        return odd <= 1;
    }

    void getHalfCountAndMidLetter(vector<int>& cnt,
                                  vector<int>& halfCount,
                                  string& midLetter) {
        for (int i = 0; i < 26; i++) {
            halfCount[i] = cnt[i] / 2;

            if (cnt[i] % 2)
                midLetter = string(1, char('a' + i));
        }
    }

    int calculateTotalPermutations(vector<int>& halfCount) {
        return countArrangements(halfCount);
    }

    vector<char> generateLeftHalf(vector<int> halfCount, int k) {
        int halfLen = accumulate(halfCount.begin(), halfCount.end(), 0);

        vector<char> left;

        for (int pos = 0; pos < halfLen; pos++) {

            for (int i = 0; i < 26; i++) {

                if (halfCount[i] == 0)
                    continue;

                halfCount[i]--;

                int arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    left.push_back(char('a' + i));
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        return left;
    }

    int countArrangements(vector<int>& cnt) {
        int total = 0;

        for (int x : cnt)
            total += x;

        long long res = 1;

        for (int freq : cnt) {

            res *= nCk(total, freq);

            if (res >= MAX)
                return MAX;

            total -= freq;
        }

        return (int)res;
    }

    int nCk(int n, int k) {

        if (k > n)
            return 0;

        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {

            res = res * (n - i + 1) / i;

            if (res >= MAX)
                return MAX;
        }

        return (int)res;
    }
};
