class Solution {
public:
    int solve(int n, vector<int> &dp){
        // Base Case
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];
        
        int minCnt = INT_MAX;
        for(int i=1; i*i<=n; i++){
            int res = 1 + solve(n - i*i, dp);
            minCnt = min(minCnt, res);
        }

        return dp[n] = minCnt;
    }
    int numSquares(int n){

        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
