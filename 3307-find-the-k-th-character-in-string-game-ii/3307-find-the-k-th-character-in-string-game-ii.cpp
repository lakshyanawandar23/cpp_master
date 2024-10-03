class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
    int x=0;
        while(k>1){
          long long  int size=1,j;
            for(int i=0;i<op.size();i++){
                size=size*2;
                if(size>=k){
                    j=op[i];
                    break;
                }
            }
            if(j==1) x=x+1;
            k=k-size/2;
        }
        return 'a'+(x%26);
    }
};