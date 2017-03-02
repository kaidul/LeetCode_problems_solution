class Solution {
    void findAllSubsequences(int prev, int indx, vector<int>& arr, vector<int>& subsequence, vector<vector<int>>& result) {
        if(subsequence.size() > 1) {
           result.push_back(subsequence);    
        }
        unordered_set<int> taken;
        for(int i = indx; i < (int)arr.size(); i++) {
            if(arr[i] < prev) continue;
            if(taken.find(arr[i]) != taken.end()) continue;
            taken.insert(arr[i]);
            subsequence.push_back(arr[i]);
            findAllSubsequences(arr[i], i + 1, arr, subsequence, result);
            subsequence.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& arr) {
        vector<vector<int>> result;
        int n = (int)arr.size();
        vector<int> subsequence;
        findAllSubsequences(INT_MIN, 0, arr, subsequence, result);
        return result;
    }
};




// find all 'longest' subsequences
class Solution {
    void findAllLongestSubsequences(int k, vector<vector<int>>& prevIndx, vector<int>& subsequence, vector<int>& arr, vector<vector<int>>& result) {
        if(prevIndx[k].empty()) {
            reverse(subsequence.begin(), subsequence.end());
            result.push_back(subsequence);
        }
        for(int i = 0; i < prevIndx[k].size(); i++) {
            subsequence.push_back(arr[prevIndx[k][i]]);
            findAllLongestSubsequences(prevIndx[k][i], prevIndx, subsequence, arr, result);
            subsequence.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& arr) {
        vector<vector<int>> result;
        int n = (int)arr.size();
        vector<int> dp(n);
        vector<vector<int>> prevIndx(n, vector<int>());
        int maxLen = 0;
        vector<int> lastIndx;
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    if(dp[j] + 1 >= dp[i]) {
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            prevIndx[i].clear();
                        }
                        prevIndx[i].push_back(j);
                    }
                }
            }
            if(dp[i] >= maxLen) {
                if(maxLen < dp[i]) {
                    maxLen = dp[i];
                    lastIndx.clear();
                }
                lastIndx.push_back(i);
            }
        }
        for(int i = 0; i < lastIndx.size(); i++) {
            vector<int> subsequence;
            subsequence.push_back(arr[lastIndx[i]]);
            findAllLongestSubsequences(lastIndx[i], prevIndx, subsequence, arr, result);  
        }
        
        return result;
    }
};