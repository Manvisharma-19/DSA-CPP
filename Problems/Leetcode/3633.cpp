class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Land -> Water
        for(int i=0;i<n;i++) {
            int landFinish =
                landStartTime[i] + landDuration[i];

            for(int j=0;j<m;j++) {
                int finish =
                    max(landFinish, waterStartTime[j])
                    + waterDuration[j];

                ans = min(ans, finish);
            }
        }

        // Water -> Land
        for(int j=0;j<m;j++) {
            int waterFinish =
                waterStartTime[j] + waterDuration[j];

            for(int i=0;i<n;i++) {
                int finish =
                    max(waterFinish, landStartTime[i])
                    + landDuration[i];

                ans = min(ans, finish);
            }
        }

        return ans;
    }
};
