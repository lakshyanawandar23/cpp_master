class Solution {
public:
    int maxIceCream(vector<int>& s, int n) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto v:s){
    q.push(v);
        }
        int cnt=0;
        while(!q.empty()&&q.top()<=n){
            auto it=q.top();
            q.pop();
            n-=it;
            cnt++;
        }
        return cnt;
    }
};