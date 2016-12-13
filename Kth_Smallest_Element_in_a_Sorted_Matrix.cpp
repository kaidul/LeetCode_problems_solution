class Compare{
public:
    bool operator()(tuple<int, int, int>& lhs, tuple<int, int, int>& rhs){
        return get<0>(lhs) > get<0>(rhs);
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> minHeap;
        for(int i = 0; i < matrix[0].size(); i++) {
            minHeap.push(make_tuple(matrix[0][i], 0, i));
        }
        tuple<int, int, int> result;
        for(int i = 0; i < k; i++) {
            result = minHeap.top();
            minHeap.pop();
            if(get<1>(result) == matrix.size() - 1) continue;
            int nextRow = get<1>(result) + 1;
            int nextCol = get<2>(result);
            minHeap.push(make_tuple(matrix[nextRow][nextCol], nextRow, nextCol));
        }
        
        return get<0>(result);
    }
};