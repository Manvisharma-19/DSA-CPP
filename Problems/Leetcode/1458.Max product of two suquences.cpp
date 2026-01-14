class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == m || j == n)
            return -1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        int take = nums1[i] * nums2[j];
        int takeBoth = take + solve(nums1, nums2, i + 1, j + 1);
        int skip1 = solve(nums1, nums2, i + 1, j);
        int skip2 = solve(nums1, nums2, i, j + 1);

        return dp[i][j] = max({take, takeBoth, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        dp.assign(m, vector<int>(n, -1));

        return solve(nums1, nums2, 0, 0);
    }
};
