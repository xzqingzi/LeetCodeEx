class Solution {
public:
    static bool compareNum(pair<int, int> & l, pair<int, int> & r) { // what is & l and &r ?
        // Use & l, instead of l, to save extra memtory, avoid copy the value l during running 
        return l.first < r.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> output(2,0);
         vector<pair<int, int>> sort_num(nums.size(), make_pair(0,0));  // make_pair, size_t  ?
         for(size_t i = 0; i < nums.size(); i++){
             sort_num[i].first = nums[i];
             sort_num[i].second = i;
         }
         sort(sort_num.begin(),sort_num.end(),compareNum);   
         for(int i = 0; i < nums.size(); i++){ 
             for(int j = i+1; j < nums.size(); j++){ 
                 int total = sort_num[i].first+sort_num[j].first;
                 if (total == target){
                     output[0] = sort_num[i].second;
                     output[1] = sort_num[j].second;
                     //return output;
                 }
                 else if(total > target) // number is sorted, no need to continue once sum is greater than target
                 break;
             }
         }
        return output;
    }
};


// worst solution
class Solution {
public:
    static bool compareNum(pair<int, int> & l, pair<int, int> & r) { // what is & l and &r ?
        return l.first < r.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> output(2,0);
         vector<pair<int, int>> sort_num(nums.size(), make_pair(0,0));  // make_pair, size_t  ?
         for(size_t i = 0; i < nums.size(); i++){
             sort_num[i].first = nums[i];
             sort_num[i].second = i;
         }
         sort(sort_num.begin(),sort_num.end(),compareNum);   
         for(int i = 0; i < nums.size(); i++){ 
             for(int j = i+1; j < nums.size(); j++){ 
                 int total = sort_num[i].first+sort_num[j].first;
                 if (total == target){
                     output[0] = sort_num[i].second;
                     output[1] = sort_num[j].second;
                     //return output;
                 }
                 else if(total > target) // number is sorted, no need to continue once sum is greater than target
                 break;
             }
         }
        return output;
    }
};

//Optimal Solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap; 
        //create a hash table, include a key and a value
        //(in this case, key is the nums_value and, value is the nums_value index)
        for(int i = 0; i < nums.size(); i++) {
            if (myMap.count(nums[i])) return vector<int> {i, myMap[nums[i]]};//What is count used for??????
            myMap[target - nums[i]] = i; //input the index of diff=target - nums[i] into the table 
        }
        return vector<int> {};
    }
};