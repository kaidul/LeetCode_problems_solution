class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = (int)arr.size() - k;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(&arr[left], &arr[left + k]);
    }
};

// longer solution
class Solution {
    int lowerBound(vector<int>& arr, int x) {
        int left = 0, right = (int)arr.size() - 1;
        int lBound = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] >= x) {
                if(arr[mid] == x) {
                    lBound = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        lBound = (lBound == -1) ? left - 1 : lBound;

        return max(lBound, 0);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if(k == 0) { return result; }
        int lbIndx = lowerBound(arr, x);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(arr[lbIndx]);
        k--;
        int left = lbIndx - 1, right = lbIndx + 1;
        while(left >= 0 and right < (int)arr.size() and k) { 
            if(x - arr[left] <= arr[right] - x) {
                minHeap.push(arr[left]);
                left--;
            } else {
                minHeap.push(arr[right]);
                right++;
            }
            k--;
        }
        while(left >= 0 and k) {
            minHeap.push(arr[left]);
            left--;
            k--;
        }
        while(right < (int)arr.size() and k) {
            minHeap.push(arr[right]);
            right++;
            k--;
        }
        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return result;
    }
};