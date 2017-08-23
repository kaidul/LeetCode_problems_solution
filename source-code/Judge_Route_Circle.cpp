class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char ch : moves) {
            y += (ch == 'U');
            y -= (ch == 'D');
            x += (ch == 'R');
            x -= (ch == 'L');
        }
        return (x == 0 and y == 0);   
    }
};