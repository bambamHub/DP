Approach 1 -> {TLE}
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> dp(n, 1);

        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(arr[ind]>=arr[prev] && 1+dp[prev]>dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
        }
        return dp;
    }
};


Approach 2 -> [Binary Search]
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        
        int n = arr.size();

        vector<int> LIS;
        vector<int> res(n);

        for(int i=0; i<n; i++){
            int ind = upper_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();

            if(ind==LIS.size()){
                LIS.push_back(arr[i]);
            }
            else{
                LIS[ind] = arr[i];
            }
            res[i] = ind+1;
        }
        return res;

        
    }
};
