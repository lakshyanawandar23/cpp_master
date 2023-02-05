class Solution {
public:
    int maxCount(vector<int>& b, int n, int s) {
        unordered_map<int,int>m;
        for(auto it:b){
            m[it]++;
        }
        int cnt=0;
        for(int i=1;i<=n&&s>0;i++){
            if(m.find(i)==m.end()&&s-i>=0){
            s-=i;
                cnt++;
            }
        }
        return cnt;
    }
};