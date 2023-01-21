//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int cnt=0,ans=0;
        while(b>0){
            cnt++;
            b=b&(b-1);
        }
        int bit[32],c[32];
        for(int i=0;i<32;i++){
            bit[i]=(a%2);
            a=a/2;
        }
        for(int i=31;i>=0&&cnt>0;i--){
            if(bit[i]==1){
                c[i]=1;
              cnt--;
            }
        }
        int i=0;
        while(cnt>0){
            if(c[i]!=1){
                c[i]=1;
              cnt--;
            }
        i++;
        }
        for(int i=0;i<32;i++){
            if(c[i]==1){
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends