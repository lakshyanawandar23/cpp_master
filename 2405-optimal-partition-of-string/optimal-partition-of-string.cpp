class Solution {
public:
    int partitionString(string s) { // Brute Force O(n^2)
        string str="";
        int ans=1;
        for(auto c:s){
            bool flag=true;
           for(auto chr:str){
               if(chr==c){
                   ans++;
                   str=c;
                   flag=false;
                   break;
               }
           }
            if(flag){
                str+=c;
            }
        }
        return ans;
    }
};
