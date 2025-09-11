class Solution {
public:
    string sortVowels(string s) {
        vector<int>v;
       // set<int>s;
        for(auto it:s){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
              //  cout<<it-'a'<<endl;
                v.push_back(it);
            }
                 if(it=='A'||it=='E'||it=='I'||it=='O'||it=='U'){
                 ///   cout<<it-'A'<<endl;
                v.push_back(it);
            }

        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                if(v[j]>=65&&v[j]<=90){
                    s[i]='A'+(v[j++]-65);
                }
                else {
                    s[i]='a'+(v[j++]-97);
                }
            }
            else  if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                if(v[j]>=65&&v[j]<=90){
                    s[i]='A'+(v[j++]-65);
                }
                else {
                    s[i]='a'+(v[j++]-97);
                }
            }
        }
        return s;
    }
};