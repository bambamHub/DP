
class Solution {
public:
    int n;
    int dp[21][10003];
    int solve(int ind, int diff, vector<int>& rods){

        if(ind>=n){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }

        if(dp[ind][diff + 5000]!=-1) return dp[ind][diff + 5000];

        int nothingAdd = solve(ind+1, diff, rods);
        int in_left_rod = rods[ind] + solve(ind+1, diff+rods[ind], rods);
        int in_right_rod = rods[ind] +  solve(ind+1, diff-rods[ind], rods);

        return dp[ind][diff + 5000] = max({nothingAdd, in_left_rod, in_right_rod });

    }
    int tallestBillboard(vector<int>& rods) {
        
        n = rods.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0,rods)/2;;
    }
};
