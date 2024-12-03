class Solution {
public:
    string addSpaces(string s, vector<int>& space) {
        int i=0,j=0;
        string ans;
        for(int i=0;i<space.size();){
         if(space[i]==j){
        ans+=" ";
        i++;
         }
            else {
            ans+=s[j];
                j++;
            }
        }
        while(j<s.size()){
            ans+=s[j];
            j++;
        }
        return ans;
    }
};