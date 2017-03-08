class Solution {
public:
    int findMinMoves(vector<int>& machines) {
    	int n = (int)machines.size();
    	vector<int> sum(n + 1, 0);
    	for(int i = 0; i < n; i++) {
    		sum[i + 1] = sum[i] + machines[i];
    	}
    	if(sum[n] % n) {
    		return -1;
    	}
    	int avg = sum[n] / n;
    	int result = 0;
    	for(int i = 0; i < n; i++) {
    		int L = i * avg - sum[i]; // dress required in left side
    		int R = (n - i - 1) * avg - (sum[n] - sum[i + 1]);
    		if(L > 0 and R > 0) {
    			result = max(result, abs(L) + abs(R));
    		} else {
    			result = max(result, max(abs(L), abs(R)));
    		}
    	}
    
    	return result;
    }
};