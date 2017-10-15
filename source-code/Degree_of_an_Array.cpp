class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> startIndx;
        unordered_map<int, int> endIndx;
        int maxFreq = 0;
        for(int i = 0; i < (int)nums.size(); i++) {
            freq[nums[i]]++;
            if(startIndx.find(nums[i]) == startIndx.end()) {
                startIndx[nums[i]] = i;
            }
            endIndx[nums[i]] = i;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        int result = INT_MAX;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(it->second == maxFreq) {
                int value = it->first;
                result = min(result, endIndx[value] - startIndx[value] + 1);
            }
        }
        return result;
    }
};

// using tow pointers (complex)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int val : nums) {
            freq[val]++;
            maxFreq = max(maxFreq, freq[val]);
        }
        
        int start = 0;
        map<int, int> freq2;
        int maxFreq2 = 0;
        int curr = -1;
        
        int result = INT_MAX;
        for(int end = 0; end < nums.size(); end++) {
            freq2[nums[end]]++;
            if(freq2[nums[end]] > maxFreq2) {
                maxFreq2 = freq2[nums[end]];
                curr = nums[end];
            }
            if(maxFreq2 == maxFreq) {
                while(nums[start] != curr and start < end) {
                    freq2[nums[start]]--;
                    start++;
                }
                result = min(result, end - start + 1);
                freq2[nums[start]]--;
                start++;
                maxFreq2--;
                auto last = freq2.end();
                --last;
                if(last->second > maxFreq2) {
                    maxFreq2 = last->second;
                    curr = last->first;
                }
            }
        }
        
        return result;
    }
};