class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& s, int k) {
        vector<int>v;
        priority_queue<int>q;
        for(int i=0;i<s.size();i++){
            int dist=abs(s[i][0])+abs(s[i][1]);
            q.push(dist);
            while(q.size()>k){
                q.pop();
            }
            if(q.size()==k) v.push_back(q.top());
            else v.push_back(-1);
        }
        return v;
    }
};