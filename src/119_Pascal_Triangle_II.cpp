class Solution {  // What is O(k) extra space, how?
public:
    vector<int> getRow(int rowIndex) { //Input rowIndex, start from 0.
        vector<int> Row(rowIndex+1, 1);
        for (int i = 0; i<=rowIndex; i++){
            vector<int> temp=Row;
            for (int j = 1; j<i; j++){ 
                Row[j] = temp[j-1]+temp[j];
            }
        }
        return Row;
    }
};

// optimize to use only O(k) extra space
class Solution {  // What is O(k) extra space
public:
    vector<int> getRow(int rowIndex) { //Input rowIndex, start from 0.
        vector<int> Row(rowIndex+1, 1);
        long C = 1; //coeff may be greater than int_max
        for (int i = 1; i<rowIndex; i++){
            Row[i] = C*(rowIndex-i+1)/i; //Record this, for the Pascal tri coeff calculation 
            C = Row[i];
        }
        return Row;
    }
};