class Solution {
public:
    vector<int>v;
    void solve(int &n,int &digits,int num){
        if(num>n) return ;
        v.push_back(num);
        for(int j=0;j<=9;j++){
            int x=(num*10)+j;
            solve(n,digits,x);
        }
        return ;
    }
    vector<int> lexicalOrder(int n) {
        v.clear();
        
        int digits=log10(n)+1;
        for(int i=1;i<=9;i++){
     solve(n,digits,i);
        }
        return v;
    }
};