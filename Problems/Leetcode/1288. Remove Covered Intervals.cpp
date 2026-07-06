class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<bool> covered(n, false);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(i == j)
                    continue;

                if(intervals[j][0] <= intervals[i][0] &&
                   intervals[i][1] <= intervals[j][1]) {

                    covered[i] = true;
                    break;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!covered[i])
                count++;
        }

        return count;
    }
};
