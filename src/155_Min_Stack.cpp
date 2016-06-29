class MinStack {
public:
    vector<int> mystack; // define an empty vector
    vector<int> minstack;
    /** initialize your data structure here. */

    //MinStack() {
    //}
    
    void push(int x) {
        mystack.push_back(x);
        if (minstack.size()==0) {minstack.push_back(x);}
        else {
            int temp = minstack.back();
            if (x < temp) {minstack.push_back(x);}
            else {minstack.push_back(temp);}
        }
    }

    void pop() {
        mystack.pop_back();
        minstack.pop_back();
    }
    
    int top() {
        return mystack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */