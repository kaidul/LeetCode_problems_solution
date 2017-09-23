// AC
class Solution {
    int countReversePair(vector<int>& A, int start, int mid, int end) {
        int j = mid + 1;
        int count = 0;
        for (int i = start; i <= mid; i++) {
            while (j <= end and A[i] > 2LL * A[j]) {
                j++;
            }
            count += j - (mid + 1);
        }
        return count;
    }
    
    void merge(vector<int>& A, int start, int mid, int end) {
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        int L[n1], R[n2];
        
        for (int i = 0; i < n1; i++) {
            L[i] = A[start + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = A[mid + 1 + j];    
        }
        int i = 0, j = 0, k = start;
        while(i < n1 and j < n2) {
            if(L[i] < R[j]) {
                A[k++] = L[i++];
            } else {
                A[k++] = R[j++];
            }
        }
        while(i < n1) {
            A[k++] = L[i++];
        }
        while(j < n2) {
            A[k++] = R[j++];
        }
    }

    int mergesortAndCount(vector<int>& A, int start, int end) {
        if (start > end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = mergesortAndCount(A, start, mid) + mergesortAndCount(A, mid + 1, end);
        count += countReversePair(A, start, mid, end);
        merge(A, start, mid, end);
        
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergesortAndCount(nums, 0, nums.size() - 1);
    }

};

// Segment Tree (AC)
class Solution {
    class SegmentTree {
        int n;
        vector<int> segmentNode;
        
        void insert(int node, int left, int right, const int indx) {
            if(indx < left or indx > right) {
                return;
            }
            if(left == right and indx == left) {
                segmentNode[node]++;
                return;
            }
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            insert(leftNode, left, mid, indx);
            insert(rightNode, mid + 1, right, indx);
            
            segmentNode[node] = segmentNode[leftNode] + segmentNode[rightNode];
        }
        
        int query(int node, int left, int right, const int L, const int R) {
            if(left > R or right < L) {
                return 0;
            }
            if(left >= L and right <= R) {
                return segmentNode[node];
            }
            
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            return query(leftNode, left, mid, L, R) + query(rightNode, mid + 1, right, L, R);
        }
        
    public:
        void init(int n) {
            this->n = n;
            int N = 2 * pow(2.0, floor(log((double) n) / log(2.0)) + 1);
            segmentNode.resize(N, 0);
        }

        int query(const int L, const int R) {
            return query(1, 0, n - 1, L, R);
        }
        
        void insert(int value) {
            insert(1, 0, n - 1, value);
        } 
        
    };
    
    int lowerBound(vector<int>& nums, long long key) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
public:
    /*
    // slower, need to find lower_bound
    int reversePairs(vector<int>& nums) {
        int result = 0;
        if(nums.empty()) {
            return result;
        }
        int n = (int)nums.size();
        vector<int> numsCopy(nums);
        sort(numsCopy.begin(), numsCopy.end());
        SegmentTree segmentTree;
        segmentTree.init(n);
        for(int i = 0; i < n; i++) {
            result += segmentTree.query(lowerBound(numsCopy, 2LL * nums[i] + 1), nums.size() - 1);
            segmentTree.insert(lowerBound(numsCopy, nums[i]));
        }
        return result;
    }
    */

    // faster
    int reversePairs(vector<int>& nums) {
        int result = 0;
        if(nums.empty()) {
            return result;
        }
        int n = (int)nums.size();
        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i++) {
            data[i] = {nums[i], i};
        }
        sort(data.begin(), data.end());
        SegmentTree segmentTree;
        segmentTree.init(n);
        for(int i = 0, k = 0; i < n; i++) {
            while(k < n and 2LL * data[k].first < data[i].first) {
                segmentTree.insert(data[k++].second);
            }
            result += segmentTree.query(data[i].second + 1, n - 1);
        }
        return result;
    }
};

// BIT (AC)
class Solution {
    vector<int> tree;
    int n;
    
    void update(int indx, int value) {
        while (indx <= n) {
            tree[indx] += value;
            indx += (indx & -indx);
        }
    }

    int query(int indx) {
        int sum = 0;
        while (indx > 0) {
            sum += tree[indx];
            indx -= (indx & -indx);
        }
        return sum;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        this->n = nums.size();
        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i++) {
            data[i] = {nums[i], i + 1};
        }
        sort(data.begin(), data.end());
        tree = vector<int>(n + 1, 0);
        int count = 0;
        for(int i = 0, k = 0; i < n; i++) {
            while(k < n and 2LL * data[k].first < data[i].first) {
                update(data[k++].second, 1);
            }
            count += query(n) - query(data[i].second);
        }
        return count;
    }
};

// TLE (for skewed binary tree)
class Solution {
    class BST {
    public:
        class BSTNode {
        public:
            BSTNode* left;
            BSTNode* right;
            int value;
            int largerElemCount;
            BSTNode(int value) {
                this->value = value;
                left = right = nullptr;
                largerElemCount = 1;
            }
        };
        BST(): root(nullptr) {}

        int search(long long const key, BSTNode* curr) {
            if(!curr) {
                return 0;
            }
            if(curr->value == key) {
                return curr->largerElemCount;
            }
            if(curr->value > key) {
                return curr->largerElemCount + search(key, curr->left);
            } else {
                return search(key, curr->right);
            }
        }

        BSTNode* insert(int const value, BSTNode* curr) {
            if(!curr) {
                return new BSTNode(value);
            }
            if(curr->value == value) {
                curr->largerElemCount++;
                return curr;
            }
            if(curr->value > value) {
                curr->left = insert(value, curr->left);
            }else {
                curr->largerElemCount++;
                curr->right = insert(value, curr->right);
            }
            return curr;
        }
        
        BSTNode* root;
    };
    
public:
    int reversePairs(vector<int>& nums) {
        int result = 0;
        BST* bst = new BST();
        for(int i = 0; i < nums.size(); i++) {
            result += bst->search(2LL * nums[i] + 1LL, bst->root);
            bst->root = bst->insert(nums[i], bst->root);
        }
        return result;
    }
};