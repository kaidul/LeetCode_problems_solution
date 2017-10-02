class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> Stack;
        int sum = 0;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                int a = Stack.top();
                Stack.pop();
                int b = Stack.top();
                Stack.pop();
                int c = a + b;
                Stack.push(b); Stack.push(a); Stack.push(c);
                sum += c;
            } else if(ops[i] == "D") {
                int top = Stack.top();
                top <<= 1;
                sum += top;
                Stack.push(top);
            } else if(ops[i] == "C") {
                int top = Stack.top();
                Stack.pop();
                sum -= top;
            } else {
                int value = atoi(ops[i].c_str());
                sum += value;
                Stack.push(value);
            }
        }
        return sum;
    }
};