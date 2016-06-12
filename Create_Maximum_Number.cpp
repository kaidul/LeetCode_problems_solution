class Solution {
    void update(vector<int>& result, vector<int>& curr) {
        if(result.empty()) { swap(result, curr); return; }
        for(int i = 0; i < (int)result.size(); ++i) {
            if(result[i] > curr[i]) { return; }
            if(curr[i] > result[i]) { swap(result, curr); return; }
        }
    }
    
    void merge(vector<int> const& seq1, vector<int> const& seq2, vector<int>& merged) {
        int m = (int)seq1.size();
        int n = (int)seq2.size();
        
        int i = 0, j = 0, k = 0;
        while(i < m and j < n) {
            if(seq1[i] > seq2[j]) {
                merged[k++] = seq1[i++];
            }
            else if(seq2[j] == seq1[i]) {
                int k1 = i + 1, k2 = j + 1;
                bool flag = false;
                while(k1 < m or k2 < n) {
                    if(k1 >= m) {
                        flag = true;
                        merged[k++] = seq2[j++];
                        break;
                    }
                    if(k2 >= n) {
                        flag = true;
                        merged[k++] = seq1[i++];
                        break;
                    }
                    if(seq1[k1] > seq2[k2]) {
                        flag = true;
                        merged[k++] = seq1[i++];
                        break;
                    }
                    if(seq2[k2] > seq1[k1]) {
                        flag = true;
                        merged[k++] = seq2[j++];
                        break;
                    }
                    ++k1, ++k2;
                }
                if(!flag) {
                    merged[k++] = seq1[i++];
                }
            }
            else {
                merged[k++] = seq2[j++];
            }
        }
        while(i < m) {
            merged[k++] = seq1[i++];
        }
        while(j < n) {
            merged[k++] = seq2[j++];
        }
    }
    
    void getSeq(vector<int> const& nums, vector<int>& seq, int k) {
        if(k == 0) return;
        seq.resize(k);
        stack<int> stk;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i) {
            while(!stk.empty() and stk.top() < nums[i] and n - i - 1 >= k - (int)stk.size()) {
                stk.pop();
            }
            stk.push(nums[i]);
        }
        while((int)stk.size() > k) {
            stk.pop();
        }
        while(!stk.empty()) {
            seq[--k] = stk.top();
            stk.pop();
        }
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() > nums2.size()) return maxNumber(nums2, nums1, k);
        vector<int> result(k);
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();
        vector<int> merged(k);
        for(int i = 0; i <= min(n1, k); ++i) {
            if(k - i > n2) { continue; }
            
            vector<int> seq1;
            getSeq(nums1, seq1, i);
            
            vector<int> seq2;
            getSeq(nums2, seq2, k - i);
            
            merge(seq1, seq2, merged);
            
            update(result, merged);
        }
        
        return result;
    }
};