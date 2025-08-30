class Solution {
public:
  bool check(int i,int j,vector<vector<char>>&b){
        set<int>s;
        // start at correct 3x3 block
        int startRow = i - i%3;
        int startCol = j - j%3;

        for(int x=startRow;x<startRow+3;x++){
            for(int y=startCol;y<startCol+3;y++){
                if(b[x][y] != '.'){
                    int num = b[x][y]-'0';
                    if(s.find(num)!=s.end()){
                        return true; // duplicate in box
                    }
                    s.insert(num);
                }
            }
        }
        return false;
  }

   bool solve(int i,int j,vector<vector<char>>&b){
         bool f1 = check(i,j,b);
         bool f2 = false;
         bool f3 = false;

         // check row i
         set<int> r;
         for(int x=0;x<9;x++){
              if(b[i][x] != '.'){
                  int num = b[i][x]-'0';
                  if(r.find(num)!=r.end()){
                    f2=true;
                    break;
                  }
                  r.insert(num);
              }
         }

         // check column j
         set<int> c;
         for(int y=0;y<9;y++){
            if(b[y][j] != '.'){
                int num = b[y][j]-'0';
                if(c.find(num)!=c.end()){
                    f3=true;
                    break;
                }
                c.insert(num);
            }
         }
         return f1||f2||f3;
   }

    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j] != '.'){   // ✅ only check filled cells
                    if(solve(i,j,b)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
