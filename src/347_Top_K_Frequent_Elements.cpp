class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0; i<nums.size(); i++) {
            mymap[nums[i]]++;
        }
        vector<vector<int>> list(nums.size()+1); // WHY?
        for(auto i: mymap) {
            list[i.second].push_back(i.first);
        }
        vector<int> output;
        for(int i= list.size()-1; i>=0 && output.size()<=k; i--) {
            for(int j: list[i]) {
                output.push_back(j);
                if(output.size() >=k) {
                   return output;
                }
            }

        }
        return output;
        
    }
};

//Using priority_queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0; i<nums.size(); i++) {
            mymap[nums[i]]++;
        }
        priority_queue<pair<int,int>> myqueue; //The first element is always the greatest of the elements it contains 
        vector<int> output;
        for(auto i: mymap) {
            myqueue.push(make_pair(i.second,i.first));
        }
        while(output.size()<k) {
            output.push_back(myqueue.top().second);
            myqueue.pop();
        }
        return output;
    }
};