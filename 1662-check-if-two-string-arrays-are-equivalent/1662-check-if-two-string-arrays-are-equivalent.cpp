class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string ans,res;
        for(auto it:w1){
            ans+=it;
        }
        for(auto it:w2){
            res+=it;
        }
        return ans==res;
    }
};