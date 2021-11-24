class Solution {
private:
    int dp[300];
    int rec(string& s, vector<string>& wordDict, int p){
        if(p == s.length()) return 1;
        int& ret = dp[p];
        if(ret != -1) return ret;
        ret = 0;
        int valid, i;
        for(string& word : wordDict) 
            if(p + word.length() <= s.length()) {
                valid = 1;
                for(i=0;i<word.length();i++)
                    valid &= word[i] == s[p+i];
                if(valid && rec(s, wordDict, p + word.length()))
                    return ret = 1;
            }
        return ret;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        return rec(s, wordDict, 0);
    }
};