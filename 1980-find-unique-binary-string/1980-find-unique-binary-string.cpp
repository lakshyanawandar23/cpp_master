class Solution {
public:
    string ans;
    bool solve(vector<string>&num,set<string>&s,int n,string &res){
        if(n==0){
            if(s.find(res)==s.end()){
                ans=res;
                return true;
            }
            return false;
        }
        for(int i=0;i<2;i++){
            res+=(i+'0');
            if(solve(num,s,n-1,res)) return true;
            res.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& num) {
        int n=num.size();
        set<string>s;
        for(auto it:num){
            s.insert(it);
        }
        string res;
         solve(num,s,n,res);
        return ans;
    }
};