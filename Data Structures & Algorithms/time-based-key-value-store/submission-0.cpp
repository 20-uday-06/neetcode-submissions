class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp; // {key , {time , value}}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(mp.find(key) == mp.end()) return "";

        auto& arr = mp[key];
        int left = 0;
        int right = arr.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            // if(arr[mid].first == timestamp) return arr[mid].second;

            if(arr[mid].first <= timestamp){
                ans = arr[mid].second;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return ans;
    }
};
