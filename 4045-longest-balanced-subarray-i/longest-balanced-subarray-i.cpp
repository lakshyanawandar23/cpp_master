class Solution {
public:
    int longestBalanced(vector<int>& num) {
        int cnt=0;
        for(int i=0;i<num.size();i++){
            set<int>e,o;
            for(int j=i;j<num.size();j++){
                if(num[j]%2==0){
                    e.insert(num[j]);
                }
                else {
                    o.insert(num[j]);
                }
                if(e.size()==o.size()) cnt=max(cnt,j-i+1);
            }
        }
        return cnt;
           }
};