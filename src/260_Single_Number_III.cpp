class Solution { //(Ex. 121325)
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        vector<int> output(2,0);
        for (int i=0; i<nums.size(); i++) {
            r ^= nums[i];  // r is the xor of two single numbers (ex. 0011(3)^0101(5) = 0110)
        }
        int temp = r&(~(r-1));  
        // temp = 0010, shows the pos of the last bit of 1 in r, which means, the two single number have the last different bit at 1's position.
        for (int i=0; i<nums.size(); i++) {
            if (temp&nums[i]) { // distinct two single numbers (ex.0011(3)&0010 = 0010, 0101(5)&0010 = 0000)
                output[0] ^= nums[i];
            }
            else {
                output[1] ^= nums[i];
            }
        }
        return output;
    }
};