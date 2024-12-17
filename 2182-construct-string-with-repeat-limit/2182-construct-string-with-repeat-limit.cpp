class Solution {
public:
    string repeatLimitedString(string s, int k) {
        string ans;
        vector<int>v(26,0);
        for(auto it:s){
            v[it-'a']++;
        }
        priority_queue<pair<int,int>>q;
        for(int i=0;i<26;i++){
            if(v[i]>0)
            q.push({i,v[i]});
        }
        while(q.size()>1){
            auto p=q.top();
            q.pop();
            auto r=q.top();
            q.pop();
            int cnt=0,i=ans.size();
            while(i>0&&ans[i-1]==p.first+'a'){
                cnt++;
                i--;
            }
            int val=min(p.second,k-cnt);
            ans.append(val,p.first+'a');
            if(p.second-val>0)q.push({p.first,p.second-val});
            ans.append(1,r.first+'a');
            if(r.second-1>0) q.push({r.first,r.second-1});
        }
        while(q.size()>0){
             auto p=q.top();
            q.pop();
             int cnt=0,i=ans.size()-1;
            while(i>0&&ans[i]==p.first+'a'){
                cnt++;
                i--;
            }
         //   cout<<"hi"<<endl;
         ans.append(min(p.second,k-cnt),p.first+'a');
        }
        return ans;
    }
};