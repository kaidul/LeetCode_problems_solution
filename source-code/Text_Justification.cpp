class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n =words.size();
        if(words.empty())
            return result;
        
        for(int left = 0, right = 0; right < n; left = right) {
            string line;
            line.reserve(maxWidth);
            int len = 0;
            while(right < n and ((left == right and 
                                len + words[right].length() <= maxWidth) or 
                                (right > left and len + words[right].length() + 1 <= maxWidth))) {
                                    
                len += (left ==right) ? words[right].length() : words[right].length() + 1;
                right++;
            }
            int taken = right - left;
            int whiteSpaces = maxWidth - (len - taken + 1);
            if(right == n or taken == 1) { // last line or just one word
                for(int k = left; k < right - 1; ++k) {
                    line += words[k];
                    line += " ";
                }
                line += words[right - 1];
                string gap;
                gap.reserve(whiteSpaces - taken + 1);
                for(int i = 0; i < whiteSpaces - taken + 1; ++i) {
                    gap += " ";
                }
                line += gap;
            }
            /*
            else if(taken == 1) {
                line = words[left];
                string gap;
                gap.reserve(whiteSpaces);
                for(int i = 0; i < whiteSpaces; ++i) {
                    gap += " ";
                }
                line += gap;
            }*/
            else {
                int spaces = whiteSpaces / (taken - 1);
                string gap;
                gap.reserve(spaces + 1);
                for(int i = 0; i < spaces; ++i) {
                    gap += " ";
                }
                int extra = whiteSpaces % (taken - 1);
                for(int k = left; k < right - 1; ++k) {
                    line += words[k];
                    line += gap;
                    if(k - left < extra) {
                        line += " ";
                    }
                }
                line += words[right - 1];
            }
            result.push_back(line);
        } 
    }
};