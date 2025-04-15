class Solution {
public:
    string smallestPalindrome(string s) {
    vector<int>v(26,0);
    for(auto it:s){
        v[it-'a']++;
    }
    int n=s.size();
    string ans;
    char c;
    for(int i=0;i<26;i++){
        if(v[i]%2==0){
          ans=ans.append(v[i]/2,i+'a');
        }
        else {
            ans=ans.append(v[i]/2,i+'a');
            c=i+'a';
        }
    }
     string res=ans;
    if(n%2) ans+=c;
     reverse(ans.begin(),ans.end());
     return res+ans;
    }
};