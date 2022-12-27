class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& s, int a) {
          priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<c.size();i++){
            q.push(c[i]-s[i]);
        }
        int cnt=0;
        while(!q.empty()&&a>0){
            auto p=q.top();
            q.pop();
            if(a>=p){
                a-=p;
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};