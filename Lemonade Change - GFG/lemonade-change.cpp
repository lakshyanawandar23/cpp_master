//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &v) {
        // code here
        long long int a=0,b=0,c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==5){
                a++;
            }
            else if(v[i]==10){
                if(a!=0){
                    a--;
                    b++;
                }
                else{
                    return false;
                }
            }
            else{
                if(a!=0&&b!=0){
                    a--;
                    b--;
                    c++;
                }
            else    if(a>=3){
                    a-=3;
                    c++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends