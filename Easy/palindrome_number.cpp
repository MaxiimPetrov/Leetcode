#include <iostream>
#include <string>


bool isPalindrome(int x) {
    std::string num_string = std::to_string(x);
    std::string reversed_string = "";

    for(int i = num_string.length() - 1; i >= 0; i--) {
        reversed_string = reversed_string + num_string[i];
    }

    if(num_string == reversed_string) {
        return true;
    }
    else {
        return false;
    }
}
