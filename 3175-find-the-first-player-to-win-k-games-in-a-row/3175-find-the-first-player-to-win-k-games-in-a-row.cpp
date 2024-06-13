class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int maxi=0;
        deque<pair<int,int>>q;
        for(int i=0;i<s.size();i++){
            q.push_back({i,0});
            if(s[maxi]<s[i]){
                maxi=i;
            }
        }
        if(k>=s.size() )  return  maxi;
        while(!q.empty()){
            auto p=q.front();
            q.pop_front();
            auto m=q.front();
            q.pop_front();
            if(p.second==k) return p.first;
            if(s[p.first]>s[m.first]) {
                q.push_front({p.first,p.second+1});
                q.push_back({m.first,0});
            }
            else {
                q.push_front({m.first,m.second+1});
                q.push_back({p.first,0});
            }
        
        }
        return q.front().first;
        
    }
};