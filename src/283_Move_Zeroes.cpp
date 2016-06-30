class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[j] == 0) {
                nums.erase (nums.begin()+j);
                nums.push_back(0);
            }
            else { j+=1;}
        }
        return;
    }
};


// Other solution 

class Solution {  // How to improve ?
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j+=1;
            }
        }
        while (j< nums.size()) {
            nums[j] = 0;
            j++;
        }
        return;
    }
};