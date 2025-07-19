class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        int n=f.size();
        sort(f.begin(),f.end());
        vector<string>v;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            string t=f[i];
            int j=0;
            string s="";
            bool flag=false;
        
           
            while(j<t.size()){
             
               s+=t[j];
               if(j==t.size()-1&&mp[s]){
                   flag=true;
                   break;
               }
                 // cout<<j<<endl;
              else  if(t[j+1]=='/'&&(mp.find(s)!=mp.end())){
                  //  cout<<s<<endl;
                    flag=true;
                    break;
                }
                j++;
            }
           // cout<<s<<endl;
            if(!flag) {
                v.push_back(t);
            mp[s]++;
            }
        }
        return v;
    }
};