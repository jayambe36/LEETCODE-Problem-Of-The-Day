class MyHashSet {
public:
    bool data[1000001]; // Array to simulate hash set
    
    // Constructor to initialize the hash set with default values (false)
    MyHashSet() {
        memset(data, false, sizeof data); // Initializing all elements with false using memset
    }
    
    // Function to add a key to the hash set
    void add(int key) {
        data[key] = true; // Setting the value at the index corresponding to the key to true
    }
    
    // Function to remove a key from the hash set
    void remove(int key) {
        data[key] = false; // Setting the value at the index corresponding to the key to false
    }
    
    // Function to check if a key exists in the hash set
    bool contains(int key) {
        return data[key]; // Returning the value at the index corresponding to the key
    }
};
