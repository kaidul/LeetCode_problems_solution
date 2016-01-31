class Solution {
public:
    string getHint(string secret, string guess) {
        int freq[10] = {0};
        for(int i = 0; i < secret.length(); ++i) {
            freq[secret[i] - '0']++;
        }
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.length(); ++i) {
            if(secret[i] == guess[i]) {
                bulls++;
                freq[secret[i] - '0']--;
            }
        }
        for(int i = 0; i < guess.length(); ++i) {
            if(secret[i] != guess[i] and freq[guess[i] - '0']) {
                cows++;
                freq[guess[i] - '0']--;
            }
        }
        string result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};