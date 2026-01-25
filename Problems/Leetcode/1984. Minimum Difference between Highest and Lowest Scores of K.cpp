class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int minDiff = INT_MAX;

        sort(begin(nums),end(nums));
        int i =0;
        int j = k-1;
        while(j<n){
            int minEl = nums[i];
            int maxEl = nums[j];
            minDiff = min(minDiff, maxEl - minEl);

            i++;
            j++;
        }
        return minDiff;
    }
       
};
