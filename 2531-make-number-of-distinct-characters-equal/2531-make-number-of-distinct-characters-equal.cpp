class Solution {
public:
    bool isItPossible(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        unordered_map<char,int>m;
        unordered_map<char,int>n;
        for(auto it:s){
            m[it]++;
            a[it-'a']++;
        }
        for(auto it:t){
            n[it]++;
            b[it-'a']++;
        }
       //  cout<<m.size()<<" "<<n.size()<<endl;
        bool flag=false;
        for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(a[i]>0&&b[j]>0){
                m['a'+i]--;
                if(m['a'+i]==0){
                    m.erase('a'+i);
                }
                n['a'+j]--;
                if(n['a'+j]==0){
                    n.erase('a'+j);
                }
                m['a'+j]++;
                n['a'+i]++;
               // cout<<m.size()<<" "<<n.size()<<endl;
                if(m.size()==n.size()){
                    return 1;
                }
                m['a'+j]--;
                if(m['a'+j]==0){
                    m.erase('a'+j);
                }
                n['a'+i]--;
                if(n['a'+i]==0){
                    n.erase('a'+i);
                }
                 m['a'+i]++;
                n['a'+j]++;
            }
        }
                }
        return 0;
    }
};