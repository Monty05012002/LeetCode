class StockSpanner {
public:
    StockSpanner() {
        
    }
     stack<pair<int,int>>s;
    int next(int price) {
        int count = 1;
        while (s.size()>0 && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */