class BrowserHistory {
public:
    vector<string>v;
    int curr;
    BrowserHistory(string h) {
        v.clear();
        v.push_back(h);
      curr=0;
    }
    
    void visit(string url) {
        curr++;
        v.resize(curr);
        v.push_back(url);
 //       curr=v.size()-1;
    }
    
    string back(int steps) {
    curr=max(0,curr-steps);
        return v[curr];
    }
    
    string forward(int steps) {
        int n=v.size()-1;
        curr=min(n,curr+steps);
        return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */