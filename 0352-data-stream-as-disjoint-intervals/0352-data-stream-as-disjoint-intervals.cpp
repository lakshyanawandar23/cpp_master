class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
       auto start=-1,last=-1;
        for(auto val:s){
            if(start<0){
                start=last=val;
            }
            else if(val-last==1){
                last=val;
            }
            else{
               ans.push_back({start,last});
                start=val;
                last=val;
            }
        }
        ans.push_back({start,last});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */