class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length() < 10) {
            return result;
        }
        unordered_map <int, int> Map;
        
        string substr = s.substr(0, 10);
        int hash = stringHash(substr);
        Map[hash]++;
        
        for(int i = 10; i < s.length(); ++i) {
            int newHash = updateHash(hash, s[i]);
            Map[newHash]++;
            hash = newHash;
        }
        
        for(auto it = Map.begin(); it != Map.end(); ++it) {
            if(it->second > 1) {
                string str = hashToStr(it->first);
                result.push_back(str);
            }
        }
        return result;
    }
    
    int stringHash(string &s) {
        int out = 0;
        for(int i = 0; i < 10; ++i) {
            char c = s[i];
            if(c == 'C') {
                out |= 1; 
            } else if(c == 'G') {
                out |= 2; 
            } else if(c == 'T') {
                out |= 3; 
            }
            out <<= 2;
        }
        out >>= 2;
        return out;
    }
    
    int updateHash(int oldHash, char newChar) {
        int mask = ~(3 << 18);
        oldHash &= mask;
        oldHash <<= 2;
        if(newChar == 'C') {
            oldHash |= 1;
        } else if(newChar == 'G') {
            oldHash |= 2;
        } else if(newChar == 'T') {
            oldHash |= 3;
        }
        return oldHash;
    }
    
    string hashToStr(int hash) {
        int mask = 3;
        string out = "";
        for(int i = 0; i < 10; ++i) {
            int code = hash & mask;
            if(code == 0) {
                out = 'A' + out;
            } else if(code == 1) {
                out = 'C' + out;
            } else if(code == 2) {
                out = 'G' + out;
            } else if(code == 3) {
                out = 'T' + out;
            }
            hash >>= 2;
        }
        return out;
    }
};