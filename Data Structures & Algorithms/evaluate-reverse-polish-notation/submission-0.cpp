class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i = 0 ; i < tokens.size() ; i++){
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result;

                if(token == "+") result = a+b;
                else if(token == "-") result = a-b;
                else if(token =="*") result = a*b;
                else result = a/b;
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
