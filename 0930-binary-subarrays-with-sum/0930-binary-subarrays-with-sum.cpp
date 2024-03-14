class Solution {
public:
    int numSubarraysWithSum(vector<int>& num, int k) {
        int cnt=0,s=0;
        unordered_map<int,int>m;
        for(int i=0;i<num.size();i++){
            s+=num[i];
            if(s==k){
                cnt++;
            }
            if(m.find(s-k)!=m.end()){
               cnt+=m[s-k];
            }
            m[s]++;
        }
        return cnt;
    }
};