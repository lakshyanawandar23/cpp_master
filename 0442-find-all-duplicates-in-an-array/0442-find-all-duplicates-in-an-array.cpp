class Solution {
public:
    vector<int> findDuplicates(vector<int>& num) {
        vector<int>v;
        for(int i=0;i<num.size();i++){
            int idx=abs(num[i])-1;
            if(num[idx]<0){
                v.push_back(idx+1);
            }
            else {
                num[idx]*=-1;
            }
        }
        return v;
    }
};