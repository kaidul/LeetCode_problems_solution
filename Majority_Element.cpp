class Solution {
private:
	unordered_map <int, int> count;
	int MajorityElement(vector<int> &num) {
		size_t n = num.size();
		// O(n)
		for(int i = 0; i < n; ++i) {
			count[num[i]]++;
			if(count[num[i]] > (n / 2)) {
				return num[i];
			}
		}
		/* O(nlogn)
		sort(num.begin(). num.end());
		return num[n / 2];
		*/
		
	}
}
// With constant space O(n) Moore voting algorithm
class Solution {
    int findCandidate(vector<int>& nums) {
        int n = nums.size();
        int majorityIndx = 0, count = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == nums[majorityIndx]) {
                ++count;
            } else {
                --count;
            }
            if(count == 0) {
                majorityIndx = i;
                count++;
            }
        }
        return majorityIndx;
    }
public:
    int majorityElement(vector<int>& nums) {
        int candidateIndx = findCandidate(nums);
        
        // no need to verify, as there is obvoiously one majority element
        
        return nums[candidateIndx];
    }
};