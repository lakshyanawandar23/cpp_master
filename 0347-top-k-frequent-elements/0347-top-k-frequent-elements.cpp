class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        unordered_map<int,int>m;
        for(auto it:nums){
            m[it]++;
        }
        for(auto it:m){
            q.push({it.second,it.first});
        }
        vector<int>v;
        while(k--){
            auto it=q.top();
            q.pop();
            v.push_back(it.second);
        }
        return v;
    }
};