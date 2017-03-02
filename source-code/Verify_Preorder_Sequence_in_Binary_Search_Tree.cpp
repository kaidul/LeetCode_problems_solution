class Solution {
    bool verifyPreorder(int left, int right, vector<int> const& preorder) {
        if(left >= right) { return true; }
        
        int root = preorder[left];
        int leftIndx = left + 1, rightIndx = right + 1;
        for(int k = left + 1; k <= right; ++k) {
            if(preorder[k] > root) {
                rightIndx = k;
                break;
            }
        }
        for(int k = rightIndx; k <= right; ++k) {
            if(preorder[k] < root) {
                return false;
            }
        }
        
        return verifyPreorder(left + 1, rightIndx - 1, preorder) and verifyPreorder(rightIndx, right, preorder);
    }
    
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty()) return true;
        
        // TLE
        // return verifyPreorder(0, (int)preorder.size() - 1, preorder);
        
        // O(n) stack based solution
        /*
        int Min = INT_MIN;
        int n = (int)preorder.size();
        stack<int> stk;
        stk.push(preorder[0]);
        
        for(int i = 1; i < n; ++i) {
            if(preorder[i] < Min) return false;
            while(!stk.empty() and preorder[i] > stk.top()) {
                Min = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
        
        return true;
        */
        
        int Min = INT_MIN;
        int n = (int)preorder.size();
        int i = 0, minIndx = -1;
        for(i = 1; i < n and preorder[i] > Min; ++i) {
            if(preorder[i] > preorder[i - 1]) { // we entered in right branch
                int k = i - 1;
                for(int j = i - 2; j > minIndx; --j) {
                    if(preorder[j] < preorder[i] and preorder[j] > preorder[k]) {
                        k = j;
                    }
                }
                minIndx = k;
                Min = preorder[k];
            }
        }
        return (i >= n); 
    }
};