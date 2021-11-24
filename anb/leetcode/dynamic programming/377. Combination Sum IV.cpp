const long long MOD = 1e14;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long dp[1001]={1}, i, j;
        
        sort(nums.begin(), nums.end());
        for(i=1;i<=target;i++){
            for(int& num : nums){
                if(num > i) break;
                dp[i] = (dp[i] + dp[i-num]) % MOD;
            }
        }
        return dp[target];
    }
};