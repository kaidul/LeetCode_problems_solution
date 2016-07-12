class Solution {
public:
	string rearrangeString(string str, int k) {
		if(k == 0) return str;
		int length = (int)str.size();
		
		string result;
		unordered_map<char, int> dict;
		priority_queue<pair<int, char>> pq;
		
		for(char ch : str) dict[ch]++;
		for(auto it = dict.begin(); it != dict.end(); it++){
			pq.push(make_pair(it->second, it->first));
		}
		
		while(!pq.empty()) {
			vector<pair<int, char>> cache;
			int count = min(k, length);
			for(int i = 0; i < count; i++) {
				if(pq.empty()) return "";
				auto tmp = pq.top();
				pq.pop();
				result.push_back(tmp.second);
				if(--tmp.first > 0) cache.push_back(tmp);
				length--;
			}
			for(auto p : cache) {
			    pq.push(p);
			}
		}
		return result;
	}
};

// Complete search (TLE)
/*
class Solution {
    void rearrangeStringUtil(int k, int indx, vector<int>& freq, vector<int>& lastPos, string& sol, string& result, bool& found) {
        if(indx == (int)sol.length()) {
            found = true;
            result = sol;
            return;
        }
        for(int i = 0; i < 26; ++i) {
            if(found) { return; }
            if(freq[i] > 0 and (lastPos[i] == -1 or lastPos[i] + k <= indx)) {
                sol[indx] = (char)('a' + i);
                int tmp = lastPos[i];
                lastPos[i] = indx;
                freq[i]--;
                rearrangeStringUtil(k, indx + 1, freq, lastPos, sol, result, found);
                lastPos[i] = tmp;
                freq[i]++;
            }
        }
    }
    
public:
    string rearrangeString(string str, int k) {
        if(str.length() < 2) {
            return str;
        }
        string result = "";
        string sol;
        sol.resize((int)str.length());
        vector<int> freq(30, 0);
        for(int i = 0; i < str.length(); ++i) {
            freq[str[i] - 'a']++;
        }
        bool found = false;
        vector<int> lastPos(30, -1);
        rearrangeStringUtil(k, 0, freq, lastPos, sol, result, found);
        
        return result;
    }
};
*/