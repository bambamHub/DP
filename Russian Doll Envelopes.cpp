Approach 1 -> {TLE}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {

        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(arr[ind][0]>arr[prev][0] && arr[ind][1]>arr[prev][1] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};

Approach 2 -> {Binary Search}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {

        int n = arr.size();

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> heights;

        for(auto &h : arr){
            heights.push_back(h[1]);
        }
        
        vector<int> temp;
        temp.push_back(heights[0]);

        for(int i=1; i<n; i++){
            if(heights[i]>temp.back()){
                temp.push_back(heights[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), heights[i]) - temp.begin();
                temp[ind] = heights[i];
            }
        }
        return temp.size();
        
    }
};
