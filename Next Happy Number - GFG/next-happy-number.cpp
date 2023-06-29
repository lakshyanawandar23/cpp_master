//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool solve(int i){
        set<int>s;
        while(1){
             i=sum(i);
            if(i==1){
                return true;
            }
            else  if(s.find(i)!=s.end()){
                return false;
            }
            else {
                s.insert(i);
            }
        }
    }
    int sum(int num){
        int s=0;
        while(num>0){
            int digit=(num%10);
            s+=(digit*digit);
            num=num/10;
        }
        return s;
    }
    int nextHappy(int n){
        // code here
        n++;
          while(solve(n)!=true){
              n++;
          }
          return n;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends