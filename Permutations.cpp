class Solution {
public:
    // no extra space
    void permuteUtils(int idx, vector<int> &num, vector<vector<int> > &result) {
        if(idx == num.size() - 1) {
            result.push_back(num);
            return;
        }
        for(int i = idx; i < num.size(); ++i) {
            swap(num[idx], num[i]);
            permuteUtils(idx + 1, num, result);
            swap(num[idx], num[i]);
        }
    }
    
    // with extra space
    void permute(vector<int> &container, vector<bool> &visited, vector<int> &num, vector<vector<int> > &result) {
        if(container.size() == num.size()) {
            result.push_back(container);
            return;
        }
        for(int i = 0; i < num.size(); ++i) {
            if(!visited[i]) {
                visited[i] = true;
                container.push_back(num[i]);
                permute(container, visited, num, result);
                visited[i] = false;
                container.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 0) return result;
        /*
        vector<bool> visited(num.size() + 1, false);
        vector<int> container;
        permute(container, visited, num, result);
        */
        permuteUtils(0, num, result);
        return result;
    }
};