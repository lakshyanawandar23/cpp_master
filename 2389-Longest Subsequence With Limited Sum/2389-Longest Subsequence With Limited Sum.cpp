class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(auto it:queries){
            int sze=0;
            int sum=0;
            for(auto it2:nums){
                if(sum+it2>it){
                    break;
                }
                sum+=it2;
                sze++;
            }
            ans.push_back(sze);
        }
        return ans;
    }
};
