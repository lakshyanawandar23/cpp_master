class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        vector<int>v;
        while(k>1){
          long long  int size=1,j;
            for(int i=0;i<op.size();i++){
                size=size*2;
                if(size>=k){
                    j=op[i];
                    break;
                }
            }
            v.push_back(j);
            k=k-size/2;
        }
        int x=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==1) x=x+1;
        }
        return 'a'+(x%26);
    }
};