/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> Stack;
        int n = (int)s.length();
        int i = 0;
        while( i < n) {
            if(s[i] == '[') {
                Stack.push(NestedInteger());
            } 
            else if(s[i] == ']') {
                // assert(!Stack.empty());
                NestedInteger curr = Stack.top();
                Stack.pop();
                if(Stack.empty()) {
                    Stack.push(curr);
                } else {
                    Stack.top().add(curr);
                }
            } 
            else if(isdigit(s[i]) or s[i] == '-') {
                bool positive = true;
                if(s[i] == '-') {
                    positive = false;
                    i++;
                }
                int value = s[i] - '0';
                while(i + 1 < n and isdigit(s[i + 1])) {
                    value = value * 10 + (s[i + 1] - '0');
                    i++;
                }
                if(!positive) {
                    value = -value;
                }
                if(Stack.empty()) {
                    Stack.push(NestedInteger(value));
                } else {
                    Stack.top().add(NestedInteger(value));
                }
            }
            i++;
        }
        // assert(!Stack.empty());
        return Stack.top();
    }
};