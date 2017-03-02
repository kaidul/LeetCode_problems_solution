// There must be some problem in OJ. Got TLE with Linkedlist, unordered_set for no reason :/
class PhoneDirectory {
    int indx;
    vector<int> available;
    vector<bool> isAvailable;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        indx = maxNumbers;
        available = vector<int>(maxNumbers);
        isAvailable = vector<bool>(maxNumbers);
        for (int i = 0; i< maxNumbers; i++) {
            available[i] = i;
            isAvailable[i] = true;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!indx) return -1;
        int number = available[--indx];
        isAvailable[number] = false;
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return isAvailable[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (!isAvailable[number]) {
            isAvailable[number] = true;
            available[indx++] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */