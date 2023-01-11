class DataStream {
public:
    int value;
    int cnt;
    int ans;
    DataStream(int val, int k) {
       value=val;
        cnt=0;
        ans=k;
    }
    
    bool consec(int num) {
        if(num!=value){
            cnt=0;
            return false;
        }
        cnt++;
        if(cnt>=ans) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */