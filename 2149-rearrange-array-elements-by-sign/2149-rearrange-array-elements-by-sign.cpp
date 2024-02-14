class Solution {
public:
    vector<int> rearrangeArray(vector<int>& n) {
        vector<int>v;
        vector<int>p;
     for(int i=0;i<n.size();++i){
         if(n[i]>0){
             v.push_back(n[i]);
             }
       else {
           p.push_back(n[i]);
           }
         }
   int i=0,j=0,k=0;
        while(i<v.size()||j<p.size()){
     if(i<v.size()){
         n[k]=v[i];
         k++;
         i++;
     }
       if(j<v.size()){
           n[k]=p[j];
           k++;
           j++;}
        }
        return n;
               
            

    }
};