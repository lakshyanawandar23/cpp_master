class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string>v;
        stack<int>s;
        set<int>p;
        int j=1;
        for(int i=0;i<t.size();){
            p.insert(t[i]);
          if(!s.empty()&&s.top()==t[i]){
             // cout<<s.top()<<endl;
             i++;
              //j++;
            // continue;
          }
           else if(!s.empty()&&p.find(s.top())==p.end()){
                v.push_back("Pop");
            //   cout<<s.top()<<endl;
                s.pop();
            //    j++;
            }
            else{
                v.push_back("Push");
               // cout<<j<<endl;
                s.push(j);
                j++;
            }
        }
        return v;
    }
};