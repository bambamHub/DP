class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs){

        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        vector<int> dp(n, 1);
        
        int maxi = 1;
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(pairs[ind][0]>pairs[prev][1] && 1+dp[prev]>dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};
