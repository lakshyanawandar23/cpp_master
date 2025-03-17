class Solution {
public:
    bool divideArray(vector<int>& num) {
        unordered_map<int,int>mp;
        for(auto it:num){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second%2!=0) return false;
        }
        return true;
    }
};