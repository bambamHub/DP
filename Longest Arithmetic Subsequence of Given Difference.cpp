

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> mp;

        int maxi = 1;
        for(int num : arr){
            mp[num] = mp[num-difference] + 1;
            maxi = max(maxi, mp[num]);
        }
        return maxi;
    }
};
