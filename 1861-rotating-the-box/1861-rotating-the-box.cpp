class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size(),k=0;
        vector<vector<char>>g(m,vector<char>(n));
        for(int i=n-1;i>=0;i-- ){
            for(int j=0;j<m;j++){
                g[j][k]=box[i][j];
            }
            k++;
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(g[j][i]=='.'){
                    int stonerow=-1,t=j;
                    while(t>=0){
                        if(g[t][i]=='#'){
                            stonerow=t;
                            break;
                        }
                        else if(g[t][i]=='*'){
                            break;
                        }
                        t--;
                    }
                    if(stonerow!=-1){
                        g[stonerow][i]='.';
                        g[j][i]='#';
                    }
                }
            }
        }
        return g;
    }
};