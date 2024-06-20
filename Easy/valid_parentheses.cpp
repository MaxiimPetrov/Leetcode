#include <string>
#include <stack>


bool isValid(std::string s) {
    std::stack<char> stack;

    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else {
            if(stack.empty()) {
                return false;
            }
            char top_of_stack = stack.top();
            if(c == ')' && top_of_stack == '(' || c == ']' && top_of_stack == '[' || c == '}' && top_of_stack == '{') {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }

    return stack.empty();
}