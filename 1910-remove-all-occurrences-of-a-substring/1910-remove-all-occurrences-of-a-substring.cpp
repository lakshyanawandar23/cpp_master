class Solution {
public:
    string removeOccurrences(string s, string t) {
        stack<char>p;
        int j=t.size()-1;
        for(int i=0;i<s.size();i++){
            p.push(s[i]);
            if(p.size()>=t.size()&&p.top()==t[j]){
                string r;
                while(j>=0&&p.top()==t[j]){
                    r=p.top()+r;
                      p.pop();
                    j--;
                }
                if(j>=0){
                    int k=0;
                    while(k<r.size()){
                        p.push(r[k]);
                        k++;
                    }
                }
            }
                j=t.size()-1;
            
        }
        string ans;
        while(p.size()>0){
            ans=p.top()+ans;
        p.pop();
        }
        return ans;
    }
};