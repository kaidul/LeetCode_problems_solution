class Solution {
    #define real first
    #define img second
    pair<int, int> tokenize(string const& s) {
        int plus = s.find('+');
        assert(plus != string::npos);
        int real = atoi(s.substr(0, plus).c_str());
        int img = atoi(s.substr(plus + 1, s.length() - plus - 2).c_str());
        return {real, img};
    }
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> complexA = tokenize(a);
        pair<int, int> complexB = tokenize(b);
        int real = complexA.real * complexB.real + complexA.img * complexB.img * (-1);
        int img = complexA.real * complexB.img + complexA.img * complexB.real;
        return to_string(real) + "+" + to_string(img) + "i";
    }
};