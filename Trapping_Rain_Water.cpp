class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if(height.empty()) return result;
        int Max;
        stack<int> bars;
        Max = height[0];
        bars.push(height[0]);
        for(int i = 1; i < height.size(); ++i) {
            if(height[i] >= Max) {
                while(!bars.empty()) {
                    result += (Max - bars.top());
                    bars.pop();
                }
                Max = height[i];
                bars.push(Max);
            } else {
                bars.push(height[i]);
            }
        }
        if(!bars.empty()) {
            Max = bars.top();
        }
        while(!bars.empty()) {
            Max = max(bars.top(), Max);
            result += (Max - bars.top());
            bars.pop();
        }
        return result;
    }
};