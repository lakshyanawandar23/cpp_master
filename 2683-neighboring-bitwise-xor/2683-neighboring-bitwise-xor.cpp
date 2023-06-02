class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int cnt=0;
        for(int i=0;i<d.size();i++){
            cnt=cnt^d[i];
        }
        return cnt==0;
    }
};