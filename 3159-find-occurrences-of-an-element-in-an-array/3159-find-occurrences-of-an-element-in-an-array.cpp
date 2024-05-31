class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& num, vector<int>& q, int x) {
        vector<int>v;
        for(int i=0;i<num.size();i++){
            if(num[i]==x){
                v.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<q.size();i++){
            if(q[i]>v.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(v[q[i]-1]);
            }
        }
        return ans;
    }
};