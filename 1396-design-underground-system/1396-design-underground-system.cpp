class UndergroundSystem {
public:
    unordered_map<string,pair<int,int>>end;  //checkout
    unordered_map<int,pair<string,int>>st;  //checkin
    UndergroundSystem() {
        st.clear();
        end.clear();
    }
    
    void checkIn(int id, string s, int t) {
        st[id]={s,t};
    }
    
    void checkOut(int id, string s, int t) {
        string res=st[id].first+'-'+s;
        end[res].first+=t-st[id].second;
        end[res].second+=1;
    }
    
    double getAverageTime(string s, string e) {
        double sum=0,cnt=0;
      string res=s+'-'+e;
        sum=end[res].first;
        cnt=end[res].second;
        return (double)(sum/cnt);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */