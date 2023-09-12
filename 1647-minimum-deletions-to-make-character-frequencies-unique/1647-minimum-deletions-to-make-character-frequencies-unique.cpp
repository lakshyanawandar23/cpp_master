class Solution {
public:
    int minDeletions(string s) {
        set<int>p;
        vector<int>v;
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        for(auto it:m){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        int cnt=0;
        p.insert(v[0]);
        for(int i=1;i<v.size();i++){
            if(p.find(v[i])!=p.end()){
                auto q=p.end();
                q--;
                int res=0,val=*q;
                while(p.find(val)!=p.end()){
                    val--;
                    res++;
                }
                if(val!=0){
                p.insert(val);
                }
                cnt+=res;
            }
            else{
                p.insert(v[i]);
            }
        }
        return cnt;
    }
};