class Solution {
public:
    unordered_map<string, string> url2Code;
    unordered_map<string, string> code2Url;
    
    string alphaNums = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int ENCODE_LENGTH = 6; 
    
    string generateCode(string const& longUrl) {
        string code = "";
        for (int i = 0; i < ENCODE_LENGTH; i++) {
            code += alphaNums[rand() % alphaNums.length()];
        }
        
        return code;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2Code.find(longUrl) != url2Code.end()) {
            return "http://tinyurl.com/" + url2Code[longUrl];
        }
        string code;
        do {
            code = generateCode(longUrl);
        } while (code2Url.find(code) != code2Url.end());
        code2Url[code] = longUrl;
        url2Code[longUrl] = code; 
        
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(shortUrl.length() - ENCODE_LENGTH, ENCODE_LENGTH);
        return code2Url[code];
    }
};


// joke
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));