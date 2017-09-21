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