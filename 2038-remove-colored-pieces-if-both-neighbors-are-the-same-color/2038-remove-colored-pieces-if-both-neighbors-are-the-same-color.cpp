class Solution {
public:
    bool winnerOfGame(string c) {
        int a=0,b=0,cnt=1;
        for(int i=1;i<c.size();i++){
            if(c[i]!=c[i-1]){
                if(c[i-1]=='A'&&cnt>2){
                    a+=(cnt-2);
                }
                else if(c[i-1]=='B'&&cnt>2){
                    b+=(cnt-2);
                }
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        if(cnt>2){
             if(c[c.size()-1]=='A'&&cnt>2){
                    a+=(cnt-2);
                }
                else if(c[c.size()-1]=='B'&&cnt>2){
                    b+=(cnt-2);
                }
        }
      //  cout<<a<<" "<<b<<endl;
        return a>b;
    
    }
};