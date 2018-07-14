class Solution {
public:
    int compress(vector<char>& chars) {
        int n = (int)chars.size();
        if(chars.empty()) return 0;
        int left = 0, right = 0, currCharIndx = left;
        while(right < n) {
            if(chars[currCharIndx] != chars[right]) {
                int len = right - currCharIndx;
                chars[left++] = chars[currCharIndx];
                if(len > 1) {
                    string freq = to_string(len);
                    for(int i = 0; i < (int)freq.length(); i++) {
                        chars[left++] = freq[i];
                    }
                }
                currCharIndx = right;
            }
            right++;
        }
        
        int len = right - currCharIndx;
        chars[left++] = chars[currCharIndx];
        if(len > 1) {
            string freq = to_string(len);
            for(int i = 0; i < freq.length(); i++) {
                chars[left++] = freq[i];
            }
        }
        return left;
    }
};