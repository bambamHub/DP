class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n==0) return 0;

        vector<double> dp(amount + 1, 0);
        for (int target = 0; target <= amount; target++) {
            dp[target] = (target % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                double nt = dp[target];
                double t = 0;
                if (target >= coins[ind]) {
                    t = dp[target - coins[ind]];
                }
                dp[target] = nt + t;
            }
        }
        return (int)dp[amount];
    }
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> res;
        for(int i = 0;i<n;i++){
            int ways = change(i+1,res);
            if(ways+1==numWays[i]) res.push_back(i+1);
            else if(ways!=numWays[i]) return {};
        }
        return res;
    }
};
