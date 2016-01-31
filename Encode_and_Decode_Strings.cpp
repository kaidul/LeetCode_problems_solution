class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString;
        for(string str: strs) {
            encodedString += to_string(str.length()) + '$' + str;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        size_t n = s.length();
        size_t pos = 0;
        while(pos < n) {
            size_t p = s.find('$', pos);
            if(p == string::npos) {
                break;
            }
            size_t len = stoi(s.substr(pos, p - pos));
            strs.push_back(s.substr(p + 1, len));    
            pos = p + 1 + len;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));