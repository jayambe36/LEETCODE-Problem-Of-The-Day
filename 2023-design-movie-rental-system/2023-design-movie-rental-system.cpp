struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (static_cast<uint64_t>(static_cast<uint32_t>(p.first)) << 32)
             ^ static_cast<uint32_t>(p.second);
    }
};

class MovieRentingSystem {
    unordered_map<pair<int,int>, int, PairHash> price_;
    unordered_map<int, vector<pair<int,int>>> movieShops_;
    unordered_set<pair<int,int>, PairHash> rented_;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price_[{shop, movie}] = p;
            movieShops_[movie].push_back({p, shop});
        }
        for (auto& kv : movieShops_) {
            auto& v = kv.second;
            sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto it = movieShops_.find(movie);
        if (it == movieShops_.end()) return res;
        for (auto [p, shop] : it->second) {
            if (!rented_.count({shop, movie})) {
                res.push_back(shop);
                if (res.size() == 5) break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        rented_.insert({shop, movie});
    }
    
    void drop(int shop, int movie) {
        rented_.erase({shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<tuple<int,int,int>> tmp; // (price, shop, movie)
        tmp.reserve(rented_.size());
        for (const auto& sm : rented_) {
            int shop = sm.first, movie = sm.second;
            int p = price_[sm];
            tmp.emplace_back(p, shop, movie);
        }
        sort(tmp.begin(), tmp.end(), [](const auto& A, const auto& B){
            if (get<0>(A) != get<0>(B)) return get<0>(A) < get<0>(B); 
            if (get<1>(A) != get<1>(B)) return get<1>(A) < get<1>(B);
            return get<2>(A) < get<2>(B);                           
        });
        vector<vector<int>> res;
        for (int i = 0; i < (int)tmp.size() && i < 5; ++i) {
            auto [p, shop, movie] = tmp[i];
            res.push_back({shop, movie});
        }
        return res;
    }
};