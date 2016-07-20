class Solution {  //Ex.test 20,4,17,1
public:
    int maxArea(vector<int>& height) {
        int i=0, j = height.size()-1, h, vol=0;
        while(i<j) {
            h = min(height[i], height[j]);
            vol = max(vol, h*(j-i));
            while(height[i]<=h) i++; // In this test case, 20 keeps no change
            while(height[j]<=h) j--; // change as 1->17->4
        }
        return vol;
    }
};