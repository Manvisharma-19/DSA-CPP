class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int mn = INT_MAX;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            int min_diff = arr[i] - arr[i - 1];

            if (min_diff < mn) {
                ans.clear();
                mn = min_diff;
                ans.push_back({arr[i - 1], arr[i]});
            }
            else if (min_diff == mn) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
