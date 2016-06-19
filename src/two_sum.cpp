class Solution {
public:
    static bool myComp (const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; } // Why static?
    // & - pass by reference
    int bisearch(vector<pair<int,int>> array, int value, int left, int right){ // binary search
        while(left<=right){
            int mid = (left+right)/2;
            if(array[mid].first == value){
                return array[mid].second;
            }
            else if (array[mid].first>value){
                right = mid-1;
            }
            else{
                left = mid+1;
            } 
        }
            return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> sort_num(nums.size(),make_pair(0,0));
        for (int i=0;i<nums.size();i++){
            sort_num[i].first = nums[i];
            sort_num[i].second = i;
        }
        sort(sort_num.begin(), sort_num.end(), myComp);
        for (int i = 0;i < sort_num.size();i++){
            int a = sort_num[i].first;
            int diff = target - a;
            int out = bisearch(sort_num, diff, i+1, sort_num.size()-1);
            if (out != -1) {
                return vector<int> {sort_num[i].second, out};
            }
        }
        return vector<int> {};
    }
};