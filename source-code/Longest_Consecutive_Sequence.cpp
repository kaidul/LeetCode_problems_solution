class Solution {
public:
 
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> Map;
        for (int i = 0; i < num.size(); i++) {
            Map[num[i]] = true;
        }
         
        int result = 0;
        for (int i = 0; i < num.size(); i++) {
            int seqLen = 1;
            int fd = num[i];
             
            Map.erase(num[i]);
            while (Map.find(fd + 1) != Map.end()) {
                seqLen++;
                Map.erase(fd + 1);
                fd++;
            }
             
            fd = num[i];
            while (Map.find(fd - 1) != Map.end()) {
                seqLen++;
                Map.erase(fd - 1);
                fd--;
            }
             
            result = max(result, seqLen);
        }
         
        return result;
    }
};
