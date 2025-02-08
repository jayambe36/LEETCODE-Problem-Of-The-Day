#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> store;
    unordered_map<int, set<int>> rec;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (store.find(index) != store.end()) {
            int oldNumber = store[index];
            rec[oldNumber].erase(index);
            if (rec[oldNumber].empty()) {
                rec.erase(oldNumber);
            }
        }
        store[index] = number;
        rec[number].insert(index);
    }

    int find(int number) {
        return (rec.find(number) != rec.end() && !rec[number].empty()) ? *rec[number].begin() : -1;
    }
};