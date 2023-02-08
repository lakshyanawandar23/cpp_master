class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>m;
     int cnt=0;
        for(int i=0;i<time.size();i++){
            int r=time[i]%60;
            if(m.find(60-r)!=m.end()&&r!=0){
                cnt+=m[60-r];
            }
            else if(r==0&&m[r]>=1){
                cnt+=m[r];
            }
            m[r]++;
        }
        return cnt;
    }
};