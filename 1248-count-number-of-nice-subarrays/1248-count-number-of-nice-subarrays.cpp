class Solution {
public:
    int numberOfSubarrays(vector<int>& num, int k) {
        int cnt=0,odd=0,j=0,i=0,n=num.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            if(num[i]%2!=0){
                m[i]=1;
            }
        }
        m[n]=1;
        auto it=m.begin();
        while(i<n){
          if(num[i]%2!=0){
              odd++;
              m.erase(i);
              it++;
          }
            if(odd==k){
                while(odd==k&&j<n){
                    cnt+=(it->first-i);
                    if(num[j]%2!=0){
                        odd--;
                    }
                    j++;
                }
            }
            i++;
        }
        return cnt;
    }
};