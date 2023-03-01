class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto val:nums){
            q.push(val);
        }
        int i=0;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            nums[i]=p;
            i++;
        }
        return nums;
    }
};