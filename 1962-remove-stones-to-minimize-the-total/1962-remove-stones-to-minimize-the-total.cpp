class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
         priority_queue<int>q;
        for(auto v:p){
            q.push(v);
        }
        int sum=0;
        while(k--){
            auto p=q.top();
            q.pop();
            p-=(p/2);
            q.push(p);
        }
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            sum+=p;
        }
        return sum;
    }
};