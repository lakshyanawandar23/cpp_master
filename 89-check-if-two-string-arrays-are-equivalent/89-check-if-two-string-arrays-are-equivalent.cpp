class Solution { // T.C. O(3n) and O(2n)
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="";
        string str2="";
        for(auto str:word1){
            str1+=str;
        }
        for(auto str:word2){
            str2+=str;
        }
        return str1==str2;
    }
};
