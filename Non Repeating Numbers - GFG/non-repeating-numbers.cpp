//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> num) 
    {
        // Code here.
        int s=0;
        for(auto it:num){
            s=s^it;
        }
        int bit=s&~(s-1);
      //  cout<<s<<" "<<bit<<endl;
        int f=0,sec=0;
        for(auto it:num){
            if(it&bit){
                f=f^it;
            }
            else{
                sec=sec^it;
            }
        }
        vector<int>v;
        v.push_back(sec);
        v.push_back(f);
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends