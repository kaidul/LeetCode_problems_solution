class Solution {
    const double EPS = 0.0001;
    bool isPossible(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if(isPossible(a + b, c, d) 
           or isPossible(a - b, c, d) 
           or isPossible(a * b, c, d) 
           or (b and isPossible(a / b, c, d))) return true;
        
        if(isPossible(a, b + c, d) 
           or isPossible(a, b - c, d) 
           or isPossible(a, b * c, d) 
           or (c and isPossible(a, b / c, d))) return true;
        
        if(isPossible(a, b, c + d) 
           or isPossible(a, b, c - d) 
           or isPossible(a, b, c * d) 
           or (d and isPossible(a, b, c / d))) return true;
        
        return false;
    }
    
    bool isPossible(double a, double b, double c) {
        if(isPossible(a + b, c) 
           or isPossible(a - b, c) 
           or isPossible(a * b, c) 
           or (b and isPossible(a / b, c))) return true;
        
        if(isPossible(a, b + c) 
           or isPossible(a, b - c) 
           or isPossible(a, b * c) 
           or (c and isPossible(a, b / c))) return true;
        return false;
    }
    
    bool isPossible(double a, double b) {
        if (abs(a + b - 24.0) < EPS 
            or abs(a - b - 24.0) < EPS 
            or abs(a * b - 24.0) < EPS 
            or (b and abs(a / b - 24.0) < EPS)) 
            return true;
        
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            if(isPossible(nums)) {
                return true;
            }
        } while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
};