class SeatManager {
public:
    set<int> unreserved;
    SeatManager(int n) {
        
        for(int i=1;i<=n;i++){
            unreserved.insert(i);
        }
    }
    
    int reserve() {
        
        int val = *unreserved.begin();
        unreserved.erase(val);
        return val;
    }
    
    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */