class Solution {
public:
    int n;
    int m;
    int solveTab(vector<vector<char>>& matrix, int &maxi){

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

                if(matrix[i][j]=='1'){
                    dp[i][j] = 1 + min({right, down, diagonal});
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    int maximalSquare(vector<vector<char>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();
        
        int maxi = 0;
        solveTab(matrix, maxi);
        return maxi*maxi;
    
    }
};
