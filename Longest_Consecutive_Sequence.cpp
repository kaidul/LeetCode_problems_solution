class Solution {
public:
 
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> mp;
        for (int i = 0; i < num.size(); i++) {
            mp[num[i]] = true;
        }
         
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            int mx = 1;
            int fd = num[i];
             
            mp.erase(num[i]);
            while (mp.find(fd + 1) != mp.end()) {
                mx++;
                mp.erase(fd + 1);
                fd++;
            }
             
            fd = num[i];
            while (mp.find(fd - 1) != mp.end()) {
                mx++;
                mp.erase(fd - 1);
                fd--;
            }
             
            res = max(res, mx);
        }
         
        return res;
    }
};