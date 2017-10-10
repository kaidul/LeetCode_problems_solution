// using BST
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloom;
        for(int i = 0; i < flowers.size(); i++) {
            auto it = bloom.insert(flowers[i]).first;
            if (it != bloom.begin()) {
                if (flowers[i] - *(--it) == k + 1) {
                    return i + 1;
                }
                it++;
            }
            if (++it != bloom.end() and *it - flowers[i] == k + 1) {
                return i + 1;
            } 
        }
        return -1;
    }
};

// using segment tree
class Solution {
    vector <int> segmentTree;
    int n;
 
    void initSegmentTree(int N) {
        int length = 2 * pow(2.0, floor(log((double) N) / log(2.0)) + 1 );
        segmentTree.resize(length, 0);
    }
    
    int query(int node, int left, int right, const int lower, const int upper) {
        if(lower > right or upper < left) {
            return 0;
        }

        if(left >= lower and right <= upper) {
            return segmentTree[node];
        }

        int mid = left + (right - left) / 2;
        int leftIndx = node << 1, rightIndx = leftIndx | 1;
        
        return query(leftIndx, left, mid, lower, upper) + query(rightIndx, mid + 1, right, lower, upper);
    }

    int query(int lower, int upper) {
        return query(1, 0, n - 1, lower, upper);
    }

    int update(int node, int left, int right, const int indx) {
        if(indx < left or indx > right or left > right) {
            return 0;
        }

        if(left == right) {
            return ++segmentTree[node];
        }
        int mid = left + (right - left) / 2;
        int leftIndx = node << 1, rightIndx = leftIndx | 1;

        return segmentTree[node] = update(leftIndx, left, mid, indx) + update(rightIndx, mid + 1, right, indx);
    }

    void update(int indx) {
        update(1, 0, n - 1, indx);
    }
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        n = flowers.size();
        initSegmentTree(n);
        vector<bool> bloom(n, false);
        for(int i = 0; i < n; i++) {
            flowers[i]--;
            bloom[flowers[i]] = true;
            update(flowers[i]);
            
            int left = max(flowers[i] - k, 0);
            int right = max(flowers[i] - 1, 0);
            if(left > 0 and query(left, right) == 0 and bloom[left - 1]) {
                return i + 1;
            }
            
            left = min(flowers[i] + 1, n - 1);
            right = min(flowers[i] + k, n - 1);
            if(right < n - 1 and query(left, right) == 0 and bloom[right + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};