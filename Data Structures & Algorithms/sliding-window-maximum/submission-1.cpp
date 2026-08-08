class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int curr = 0;
        vector<int> ans;
        set <pair<int , int>> st; //{number , index};

        for(int i = 0 ; i < k ; i++){
            st.insert({nums[i] , i});
        }
        curr = st.rbegin()->first;
        ans.push_back(curr);

        for(int i = k ; i < nums.size() ; i++){
            st.erase({nums[i-k] , i-k});
            st.insert({nums[i] , i});
            curr = st.rbegin()->first;
            ans.push_back(curr);
        }
        return ans;
    }
};
