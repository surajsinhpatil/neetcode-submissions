class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        vector<double> res;
        for(auto& p: cars){
            res.push_back((double)(target - p.first) / p.second);
        
        if (res.size() >= 2 && res.back() <= res[res.size() - 2]){
            res.pop_back();
        }
        }
        return res.size();
    
    }
};
