class MyCalendar {
public:
  vector<pair<int,int>>v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int st, int e) {
        for(int i=0;i<v.size();i++){
            if(v[i].second<=st||v[i].first>=e) continue;
             return false;
        }
        v.push_back({st,e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */