class Solution {
public:
    int countPairs(vector<int>& num) {
        int cnt=0;
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                string a=to_string(num[i]);
                string b=to_string(num[j]);
                int x=0,y=-1,prev=-1,res=0;
                while(a.size()<b.size()) a="0"+a;
                while(b.size()<a.size()) b="0"+b;
                while(x<a.size()){
                    if(a[x]!=b[x]){
                        res++;
                      //  cout<<res<<endl;
                      if(res==1) {
                          y=x;
                          x++;}
                    else if(res==2){
                       //   cout<<x<<endl;
                          prev=x;
                          x++;
                      }
                        else break ;
                }
                    else {
                 x++;   
                    }
                }
             //   cout<<b.size()<<endl;
//                 while(y<b.size()){
//                //   cout<<b[y]<<endl;
//                     if(b[y]=='0'){
//                         res++;
//                        // cout<<res<<endl;
//                     }
                
//                     y++;
//                 }
                if(a==b) {
                    cnt++;
                    continue;
                }
                if(prev!=-1&&y!=-1) {
                  //  cout<<prev<<" "<<y<<endl;
                    swap(b[prev],b[y]);
                 if(a==b)   cnt++;
            }
            }
        }
        return cnt;
    }
};