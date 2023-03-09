//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    bool safe(vector<vector<int>>& m,vector<vector<int>>& v,int x,int y,int &n)
    {
        if(x>=0&&x<=n-1&&y>=0&&y<=n-1&& v[x][y]==0&& m[x][y]==1)
        {
            return true;
        }
        return false;
    }
    void fun(vector<vector<int>> &m,vector<vector<int>> &v,int n,int x,int y,string &s,vector<string> &ans)
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(s);
            return ;
        }
        v[x][y]=1;
        
        // down
        int newx=x+1;
        int newy=y;
        if(safe(m,v,newx,newy,n))
        {
            s.push_back('D');
            fun(m,v,n,newx,newy,s,ans);
            s.pop_back();
        }
        
        // left
         newx=x;
         newy=y-1;
        if(safe(m,v,newx,newy,n))
        {
            s.push_back('L');
            fun(m,v,n,newx,newy,s,ans);
            s.pop_back();
        }
        
        // right
         newx=x;
         newy=y+1;
        if(safe(m,v,newx,newy,n))
        {
            s.push_back('R');
            fun(m,v,n,newx,newy,s,ans);
            s.pop_back();
        }
        
        // up
         newx=x-1;
         newy=y;
        if(safe(m,v,newx,newy,n))
        {
            s.push_back('U');
            fun(m,v,n,newx,newy,s,ans);
            s.pop_back();
        }
        v[x][y]=0;
    //    return ans;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int x=0;
        int y=0;
        if(m[0][0]==0||m[n-1][n-1]==0)
        {
            return ans;
        }
        vector<vector<int>>v(n,vector<int>(n,0));
        string s="";
         fun(m,v,n,x,y,s,ans);
         return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends