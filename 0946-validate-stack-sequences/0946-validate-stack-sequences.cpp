class Solution {
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        stack<int>s;
        int j=0,n=b.size();
        for(int i=0;i<a.size();i++){
            s.push(a[i]);
            while(!s.empty()&&j<n&&s.top()==b[j]){
                 s.pop();
                j++;
            }
        }
        return s.size()==0;
    }
};