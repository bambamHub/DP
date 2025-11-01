Approach 1 ->
  class Solution {
public:
    int solve(int ind, vector<int> &arr, vector<int> &dp){

        if(ind==0){
            return arr[ind];
        }

        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int take = arr[ind] + solve(ind-2, arr, dp);
        int notTake = 0 + solve(ind-1, arr, dp);

        return dp[ind] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr(10001, 0);

        for(int i=0; i<n; i++){
            arr[nums[i]] += nums[i];
        }

        vector<int> dp(arr.size(), -1);
        return solve(arr.size()-1, arr, dp);
        
    }
};

Approach 2 -> 
  class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr(10001, 0);

        for(int i=0; i<n; i++){
            arr[nums[i]] += nums[i];
        }

        vector<int> dp(arr.size(), 0);

        dp[0] = arr[0];
        for(int ind=1; ind<arr.size(); ind++){
            int notTake = 0 + dp[ind-1];
            int take = arr[ind];
            if(ind>1){
                take += dp[ind-2];
            }
            dp[ind] = max(take, notTake);
        }
        return dp[arr.size()-1];
    }
};
