class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& num, int k) {
        vector<vector<int>>ans;
        int i=0,j=2;
        sort(num.begin(),num.end());
        while(j<num.size()){
            if((num[j]-num[i])>k) {return {};}
            else {
                vector<int>v;
                while(i<=j){
                    v.push_back(num[i]);
                    i++;
                }
                j=j+3;
               // i++;
                ans.push_back(v);
            }
        }
        return ans;
    }
};