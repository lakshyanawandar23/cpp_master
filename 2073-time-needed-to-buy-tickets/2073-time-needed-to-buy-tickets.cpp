class Solution {
public:
    int timeRequiredToBuy(vector<int>& s, int idx) {
        queue<int>q;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            q.push(i);
        }
        while(!q.empty()){
            int k=q.size();
           if(k==1) return cnt+s[q.front()];
            while(k--){
                auto p=q.front();
                q.pop();
                s[p]--;
                cnt++;
                if(s[p]>0){
                    q.push(p);
                }
                if(s[p]==0&&p==idx) return cnt;
            }
        }
        return cnt;
    }
};