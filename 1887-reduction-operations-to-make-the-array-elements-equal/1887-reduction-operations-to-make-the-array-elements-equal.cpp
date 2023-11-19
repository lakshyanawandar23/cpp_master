class Solution {
public:
    int reductionOperations(vector<int>& num) {
        int ans=0;
        priority_queue<pair<int,int>>q;
        unordered_map<int,int>m;
        for(auto it:num){
            m[it]++;
        }
        for(auto it:m){
            q.push({it.first,it.second});
        }
        int res=0;
        while(q.size()>1){
         auto p=q.top();
            q.pop();
             res=p.second+res;
            ans+=res;
        }
        return ans;
    }
};