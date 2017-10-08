class Solution {
    bool isValid(string const& sticker, char ch) {
        for(int i = 0; i < sticker.length(); i++) {
            if(sticker[i] == ch) {
                return true;
            }
        }
        return false;
    }
    
    int minStickers(int indx, int mask, const int MAX, string const& target, vector<string> const& stickers, vector<vector<int>>& dp) {
        if(indx == target.length()) {
            if(mask == MAX) {
                return 0;
            }
            return INT_MAX;
        }
        if(dp[indx][mask] != -1) {
            return dp[indx][mask];
        }
        int ret = INT_MAX;
        if(mask & (1 << indx)) {
            return dp[indx][mask] = minStickers(indx + 1, mask, MAX, target, stickers, dp);
        }
        for(int j = 0;  j < stickers.size(); j++) {
            if(isValid(stickers[j], target[indx])) {
                
                unordered_map<int, int> freq;
                for(int k = 0; k < stickers[j].length(); k++) {
                    freq[stickers[j][k]]++;
                }
                int newMask = mask;
                for(int l = 0; l < target.length(); l++) {
                    if(!(mask & (1 << l))) {
                        if(freq[target[l]] > 0) {
                            freq[target[l]]--;
                            newMask ^= (1 << l);
                        }
                    }
                }
                
                int tmp = min(ret, minStickers(indx + 1, newMask, MAX, target, stickers, dp));
                if(tmp != INT_MAX) {
                    ret = min(ret, 1 + tmp);
                }
            }
        }
        return dp[indx][mask] = ret;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = (int) target.length();
        int maxMask = (1 << n) - 1;
        vector<vector<int>> dp(n, vector<int>(maxMask + 1, -1));
        int result = minStickers(0, 0, maxMask, target, stickers, dp);
        if(result == INT_MAX) {
            return -1;
        }
        return result;
    }
};