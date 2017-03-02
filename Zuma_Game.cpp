class Solution {
    const int MAX_STEP = 6;
    
    void shrink(string& board) {
        if(board.empty()) {
            return;
        }
        int left = 0;
        for(int i = 0; i <= board.size(); i++) {
            if (i == board.size() || board[i] != board[left]) {
                if(i - left >= 3) {
                    board = board.substr(0, left) + board.substr(i);
                    shrink(board);
                    return;
                }
                left = i;
            }
        }
    }
    
    int solve(string board, unordered_map<char, int>& handMap) {
        if (board.empty()) return 0;
        if (handMap.empty()) return MAX_STEP;
        int ret = MAX_STEP;
        int n = (int)board.size();
        int i = 0;
        while (i < n) {
            if(!handMap.count(board[i])) {
                i++;
                continue;
            }
            if(i + 1 < n and board[i] == board[i + 1]) {
                string nextBoard = board.substr(0, i) + board.substr(i + 2);
                shrink(nextBoard);
                handMap[board[i]]--;
                if(!handMap[board[i]]) {
                    handMap.erase(board[i]);
                }
                ret = min(ret, 1 + solve(nextBoard, handMap));
                handMap[board[i]]++;
                i++;
            } else if(handMap[board[i]] >= 2) {
                string nextBoard = board.substr(0, i) + board.substr(i + 1);
                shrink(nextBoard);
                handMap[board[i]] -= 2;
                if(!handMap[board[i]]) {
                    handMap.erase(board[i]);
                }
                ret = min(ret, 2 + solve(nextBoard, handMap));
                handMap[board[i]] += 2;
            }
            i++;
        }
        return ret;
    }
    
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> handMap;
        for(int i = 0; i < hand.size(); i++) {
            handMap[hand[i]]++;
        }
        int result = solve(board, handMap);
        return result >= MAX_STEP ? -1 : result;
    }
};