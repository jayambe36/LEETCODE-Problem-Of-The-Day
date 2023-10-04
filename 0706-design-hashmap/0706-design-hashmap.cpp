class MyHashMap {
public:
    vector<int> hashmap;
    MyHashMap() {
        for(int i=0;i<1e6+1;i++)
        {
            hashmap.push_back(-1);
        }
    }
    
    void put(int key, int value) {
        this->hashmap[key]=value;
    }
    
    int get(int key) {
        return this->hashmap[key];
    }
    
    void remove(int key) {
       this->hashmap[key]=-1;
    }
};
