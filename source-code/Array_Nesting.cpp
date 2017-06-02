class Solution {
    int dfs(int indx, vector<int>& arr, vector<bool>& visited) {
        if(visited[indx]) { return 0; }
        visited[indx] = true;
        return 1 + dfs(arr[indx], arr, visited);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n = (int) nums.size();
        vector<bool> visited(n, false);
        int result = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                result = max(result, dfs(i, nums, visited));
            }
        }
        return result;
    }
};