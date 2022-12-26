class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> as;
        multimap<int,char> mp; 
        for(auto c:s){
            as[c]++;
        }
        for(auto it:as){
            int freq=it.second;
            int ch=it.first;
            mp.insert(pair<int, char>(freq, ch));
        }
        string tmp="";
        for(auto it:mp){
            int freq=it.first;
            char ch=it.second;
            string str="";
            for(int i=0;i<freq;i++){
                str+=ch;
            }
            tmp+=str;
        }
        s=tmp;
        reverse(s.begin(),s.end());
        return s;
    }
};
