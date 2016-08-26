class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result; 
        // result is refleshed to be empty every time this function is called, intermediate value will not be kept. 
        for (int i=0; i<input.size(); i++) {
            if (ispunct(input[i]) == 0) continue;
            for (int a: diffWaysToCompute(input.substr(0,i))) { //Take the string before that operator as input
                for (int b : diffWaysToCompute(input.substr(i+1))) { //Take the string aftar operator as input
                    if (input[i] == '+') result.push_back(a+b);
                    else if (input[i] == '-') result.push_back(a-b); 
                    else  result.push_back(a*b); // == "*"
                }
            }
        }
        if (result.empty()) { //Best case is there is no operator in input, only number, return int value
            return vector<int> {stoi(input)}; //stoi() convert string to number
        }
        return result;
        
    }
};