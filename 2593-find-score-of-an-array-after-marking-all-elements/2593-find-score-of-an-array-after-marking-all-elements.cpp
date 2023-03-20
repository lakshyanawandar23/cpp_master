class Solution {
public:
    long long findScore(vector<int>& num) {
        long long int cnt=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<num.size();i++){
            q.push({num[i],i});
        }
        set<int>s;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(s.find(p.second)==s.end()){
                s.insert(p.second);
                cnt+=p.first;
                s.insert(p.second-1);
                s.insert(p.second+1);
            }
        }
        return cnt;
    }
};