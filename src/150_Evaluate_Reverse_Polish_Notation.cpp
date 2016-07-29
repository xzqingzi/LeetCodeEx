class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        int val;
        for (string n: tokens) {
            val = 0;
            if (n == "+") {
                val += mystack.top();
                mystack.pop();
                val += mystack.top();
                mystack.pop();
                mystack.push(val);
            }
            else if (n == "-") {
                val -= mystack.top();
                mystack.pop();
                val += mystack.top();
                mystack.pop();
                mystack.push(val);
            }
            else if (n == "*") {
                val += mystack.top();
                mystack.pop();
                val *= mystack.top();
                mystack.pop();
                mystack.push(val);
            }
            else if (n == "/") {
                val += mystack.top();
                mystack.pop();
                val = mystack.top()/val;
                mystack.pop();
                mystack.push(val);
            }
            else {
                mystack.push(stoi(n));
            }
            
        }
        return mystack.top();
    }
};