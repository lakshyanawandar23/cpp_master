class Solution {
public:
    int maxCount(vector<int>& b, int n, int s) {
        int cnt=0;
        set<int>st;
        for(auto it:b){
            st.insert(it);
        }
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                if(s-i>=0){
                    cnt++;
                    s=s-i;
                }
            }
        }
        return cnt;
    }
};