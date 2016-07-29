class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> myque(nums.begin(), nums.end());
        for(int i=1; i<k; i++) {
            myque.pop();
        }
        return myque.top();
    }
};