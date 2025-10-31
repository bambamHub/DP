Approach 1 -> Recursion + Memoization
class Solution {
public:
    int n;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(i==n-1){
            return grid[i][j];
        }

        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int nextCol=0; nextCol<n; nextCol++){
            if(nextCol!=j){
                ans = min(ans, solve(i+1, nextCol, grid, dp));
            }
        }
        return dp[i][j] = ans + grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid){

        n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            mini = min(mini, solve(0, j, grid, dp));
        }
        return mini;
    }
};
Approach 2 -> Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid){

        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            dp[n-1][j] = grid[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int ans = INT_MAX;
                for(int nextCol=0; nextCol<n; nextCol++){
                    if(nextCol!=j){
                      ans = min(ans, dp[i+1][nextCol]);
                    }
                }
                dp[i][j] = ans + grid[i][j];
            }
        }

        int mini = INT_MAX;
        for(int j=0; j<n; j++){
            mini = min(mini, dp[0][j]);
        }
        return mini;
    }
};
