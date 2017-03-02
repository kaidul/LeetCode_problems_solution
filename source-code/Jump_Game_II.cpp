class Solution {
public:
    /* BFS style (Accepted)
    int jump(int A[], int n) {
        if(n < 2) return 0;
        int source = 0;
        queue < pair<int, int> > Queue;
        Queue.push(make_pair(source, 0));
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while(!Queue.empty()) {
            int indx = Queue.front().first;
            int steps = Queue.front().second;
            if(indx >= n - 1) return steps;
            for(int i = A[indx]; i > 0; --i) {
                int idx = indx + i;
                if(idx >= n - 1) return steps + 1;
                if(!visited[idx]) {
                    visited[idx] = true;
                    Queue.push(make_pair(idx, steps + 1));
                }
            }
            Queue.pop();
        }
        return -1;
    }
    */
    int jump(int A[], int n) {
        if(n < 2) return 0;
        int curr = 0;
        int steps = 0;
        for(int i = 0; i < n; ) {
            curr = max(curr, A[i] + i);
            if (curr > 0) steps++;

            if (curr >= n - 1) return steps;
            int tmp = 0;
            for (int j = i + 1; j <= curr; j++) {
                if (j + A[j] > tmp) {
                    tmp = A[j] + j;
                    i = j;
                }
            }
             
        }
        return steps;
    }
};