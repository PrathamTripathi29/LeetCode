class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(token == "+") s.push(num2+num1);
                else if (token == "-") s.push(num2-num1);
                else if (token == "*") s.push(num2*num1);
                else s.push(num2/num1);
            }
            else{
                int num = stoi(token);
                s.push(num);
            }
        }
        return s.top();
    }
};
