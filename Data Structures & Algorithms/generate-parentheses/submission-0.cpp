class Solution {
public:
    void back(int open ,int close ,int n ,vector<string> & ans ,string & curr){
        //base case
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        } 
        if(open > n || close > n) return;

        //choice 1 : open
        //if open < n && open > close-> valid?
        if(open < n){
            curr += "(";
            back(open +1 , close , n , ans , curr);
            curr.pop_back();
        }

        //choice 2 : close
        // if open > close
        if(open > close && close < n){
            curr+= ")";
            back(open , close +1 , n , ans , curr);
            curr.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        back(0 , 0 , n , ans , curr);
        return ans;
    }
};
