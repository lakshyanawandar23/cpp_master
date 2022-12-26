class Solution {
public:
    bool closeStrings(string word1, string word2) {
       vector<int> num1(26,0);
       vector<int> num2(26,0);
       if(word1.size()!=word2.size()){
           return false;
       }
       for(int i=0;i<word1.size();i++){
           num1[word1[i]-'a']++;
       }
       for(int i=0;i<word2.size();i++){
           num2[word2[i]-'a']++;
           if(num1[word2[i]-'a']==0){
               return false;
           }
       }
       sort(num1.begin(),num1.end());
       sort(num2.begin(),num2.end());
       for(int i=0;i<26;i++){
           if(num1[i]!=num2[i]){
               return false;
           }
       }
       return true;
    }
};
