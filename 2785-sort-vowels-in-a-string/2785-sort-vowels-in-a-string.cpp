class Solution {
public:
    string sortVowels(string s) {
    vector<int>l,u;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                l.push_back(s[i]-'a');
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            u.push_back(s[i]-'A');
            }
        }
        sort(l.begin(),l.end());
        sort(u.begin(),u.end());
        int j=0,i=0;
        for( i=0;i<s.size()&&j<u.size();i++){
             if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
               //  cout<<u[j]<<endl;
                s[i]=(u[j]+'A');
                 j++;
            }
             else if(s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='e'||s[i]=='u'){
           s[i]=(u[j]+'A');
                 j++;
            }
        }
        j=0;
          for(;i<s.size()&&j<l.size();i++){
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                s[i]=(l[j]+'a');
                 j++;
            }
                else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
               //  cout<<u[j]<<endl;
                s[i]=(l[j]+'a');
                 j++;
            }
    
        }
        return s;
    }
};