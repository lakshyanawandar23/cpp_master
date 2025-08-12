class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string (n);
        sort(s.begin(),s.end());
       do{
            int t=stoi(s);
         //   cout<<s<<endl;
            if(s[0]=='0') {
                next_permutation(s.begin(),s.end());
                continue;
            }
            
            int cnt=0;
            while(t>0){
                if(t%2) cnt++;
                t=t/2;
            }
            if(cnt==1) return true;
        } while(next_permutation(s.begin(),s.end()));
        return false;
    }
};