Approach 1-> (Recursion + Memo);
class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i==0) return 0;
        if(j==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(nums1[i-1]==nums2[j-1]){
            return dp[i][j] = 1 + solve(i-1, j-1, nums1, nums2, dp);
        }
        return dp[i][j] = max(solve(i-1, j, nums1, nums2, dp), solve(i, j-1, nums1, nums2, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, nums1, nums2, dp);
    }
};

Approach 2 -> (Tabulation)
  class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
