class Solution {
    
    bool tokenize(string const& s, char delimeter, vector<string>& tokens) {
        int found = 0;
        int offset = 0;
        int delims = 0;
        while(offset < s.length()) {
            found = s.find(delimeter, offset);
            delims += (found != string::npos);
            int lastPos = (found == string::npos) ? s.length() : found;
            string token = s.substr(offset, lastPos - offset);
            if(token.empty()) {
                return false;
            }
            tokens.push_back(token);
            offset = lastPos + 1;
        }
        if( (delimeter == ':' and delims != 7) or ((delimeter == '.' and delims != 3))) {
            return false;
        }
        return true;
    }
    
    int toInt(string s) {
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if(!isdigit(s[i])) {
                return -1;
            }
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    
    bool isIPv4Candidate(string const& addr) {
        return (addr.find('.') != string::npos);
    }
    
    bool isIPv6Candidate(string const& addr) {
        return (addr.find(':') != string::npos);
    }
    
    bool isValidIPv4(string const& addr) {
        if(!isIPv4Candidate(addr)) {
            return false;
        }
        vector<string> ipBlocks;
        bool valid = tokenize(addr, '.', ipBlocks);
        if(!valid or ipBlocks.size() != 4) {
            return false;
        }
        for(int i = 0; i < ipBlocks.size(); i++) {
            string sBlock = ipBlocks[i];
            if(sBlock.length() > 1 and sBlock.front() == '0') {
                return false;
            }
            int block = toInt(sBlock);
            if(block < 0 or block > 255) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidIPv6(string const& addr) {
        if(!isIPv6Candidate(addr)) {
            return false;
        }
        vector<string> ipBlocks;
        bool valid = tokenize(addr, ':', ipBlocks);
        if(!valid or ipBlocks.size() != 8) {
            return false;
        }
        for(int i = 0; i < ipBlocks.size(); i++) {
            string sBlock = ipBlocks[i];
            if(sBlock.length() > 4) {
                return false;
            }
            for(int k = 0; k < sBlock.size(); k++) {
                bool isDigit = isdigit(sBlock[k]);
                if(isDigit) continue;
                bool isAlpha = isalpha(sBlock[k]);
                if(isAlpha) {
                    bool isLowercase = (sBlock[k] >= 'a' and sBlock[k] <= 'f');
                    bool isUppercase = (sBlock[k] >= 'A' and sBlock[k] <= 'F');
                    if(!isLowercase and !isUppercase) {
                        return false;
                    }
                }
                if(!isAlpha and !isDigit) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        if(isValidIPv4(IP)) {
            return "IPv4";
        }
        if(isValidIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};