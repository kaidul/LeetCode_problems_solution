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