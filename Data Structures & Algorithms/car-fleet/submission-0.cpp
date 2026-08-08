class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> time (position.size());
        vector<pair<int,int>> cars;
        for(int i = 0 ; i < speed.size() ; i++){
            cars.push_back({position[i] , speed[i]});
        }
        sort(cars.rbegin() , cars.rend());

        for(int i = 0 ; i < speed.size() ; i++){
            time[i] = (double)(target - cars[i].first)/cars[i].second;
        }
        int fleet = 0;
        double currTime = 0;
        for(int i = 0 ; i < speed.size() ; i++){
            if(time[i] <= currTime){
                // number of fleet remains same
                // fleet size will increase
            }
            else{
                currTime = time[i];
                fleet++;
            }

        }
        return fleet;
        
    }
};
