class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int res = 0;

        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                int diff = nums[ind] - nums[prev] + 500;

                dp[ind][diff] = dp[prev][diff] > 0 ? 1 + dp[prev][diff] : 2;
                res = max(res, dp[ind][diff]);
            }
        }
        return res;
        
    }
};
