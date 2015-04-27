class Solution {
public:
    bool isHappy(int n) {
       unordered_map <int, bool> visited;
       while(n != 1) {
           if(visited[n]) return false;
           visited[n] = true;
           int tmp = n;
           n = 0;
           while(tmp) {
               n += pow((tmp % 10), 2);
               tmp /= 10;
           }
       }
       return true;
    }
};