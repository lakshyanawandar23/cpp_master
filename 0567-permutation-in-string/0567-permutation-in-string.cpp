class Solution {
public:
    bool solve(vector<int>a,vector<int>b){
        for(int i=0;i<26;i++){
        //    cout<<a[i]<<' '<<b[i]<<endl;
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
      vector<int>a(26,0);
       vector<int>b(26,0);
        for(int i=0;i<s1.size();i++){
          a[s1[i]-'a']++;
        }
        int j=0;
        for(int i=0;i<s2.size();i++){
             b[s2[i]-'a']++;  
            if(i-j+1==s1.size()){
                  if(solve(a,b)){
                      return true;
                  }
                  b[s2[j]-'a']--;
                      j++;
                  }
        }
        return false;
    }
};