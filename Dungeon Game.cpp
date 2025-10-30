Approach 1 -> Recursion + Memoization
class Solution {
public:
    int n;
    int m;
    int solve(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>> &dp){
        if(i>=n || j>=m){
            return 1e9;
        }

        if(i==n-1 && j==m-1){
            if(dungeon[i][j] > 0){
                return 1;
            }
            return abs(dungeon[i][j]) + 1;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(i, j+1, dungeon, dp);
        int down  = solve(i+1, j, dungeon, dp);

        int res = min(right, down) - dungeon[i][j];
        return dp[i][j] = (res > 0) ? res : 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        n = dungeon.size();
        m = dungeon[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, dungeon, dp);
    }
};

Approach 2 -> Tabulation

  class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1){
                    dp[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
                }
                else{
                    int down = (i+1 >= n) ? 1e9 : dp[i+1][j];
                    int right = (j+1 >= m) ? 1e9 : dp[i][j+1];
                    
                    int res = min(down, right) - dungeon[i][j];

                    dp[i][j] = (res > 0) ? res : 1;
                }
            }
        }
        return dp[0][0];
    }
};
