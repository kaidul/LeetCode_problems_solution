class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxProduct = 0;
        int n = words.size();
        if(n == 0) return maxProduct;
        int bitMask[n] = {0};
        for(int i = 0; i < n; ++i) {
            string word = words[i];
            for(int k = 0; k < word.length(); ++k) {
                int pos = int(word[k] - 'a');
                bitMask[i] |= (1 << pos);
            }
        }
        for(int i = 0; i < n - 1; ++i) {
            if(bitMask[i] > 0) {
                for(int j = i + 1; j < n; ++j) {
                    if(bitMask[j] > 0) {
                        bool overlap = (bool)(bitMask[i] & bitMask[j]);
                        if(!overlap) {
                            maxProduct = max(maxProduct, (int)(words[i].length() * words[j].length()));    
                        }
                    }
                }
            }
        }
        return maxProduct;
    }
};