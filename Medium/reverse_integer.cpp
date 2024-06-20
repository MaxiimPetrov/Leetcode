#include <functional>
#include <string>




int reverse(int x) {

    std::function<bool(int, int)> willAdditionOverflow = [](int a, int b) {
        if(b > ((std::pow(2, 31) - 1) - a)) {
            return true;
        }
        return false;
    };

    std::function<bool(int, int)> willMultiplicationOverflow = [](int a, int b) {
        if(a == 0 || b == 0) {
            return false;
        }
        if(a > ((std::pow(2, 31) - 1) / b)) {
            return true;
        }
        return false;
    };


    std::string int_string = std::to_string(x);
    int reverse_int = 0;
    int individual_int;
    bool is_negative = false;
    int ten_exponent = 1;

    if(int_string[0] ==  '-') {
        is_negative = true;
    }

    if(is_negative) {
        for(int i = int_string.length() - 1; i > 0; i--) {
            for(int x = 0; x < i - 1; x++) {
                if(willMultiplicationOverflow(ten_exponent, 10)) {
                    return 0;
                }
                else {
                    ten_exponent *= 10;
                }
                
            }
            individual_int = std::stoi(std::string(1, int_string[i]));

            if(willMultiplicationOverflow(individual_int, ten_exponent)) {
                return 0;
            }
            else {
                if(willAdditionOverflow(reverse_int, individual_int * ten_exponent)) {
                    return 0;
                }
                else {
                    reverse_int += individual_int * ten_exponent;
                }
            }

            ten_exponent = 1;
        }    
    }
    else {
            for(int i = int_string.length() - 1; i >= 0; i--) {
            for(int x = 0; x < i; x++) {
                if(willMultiplicationOverflow(ten_exponent, 10)) {
                    return 0;
                }
                else {
                    ten_exponent *= 10;
                }
                
            }
            individual_int = std::stoi(std::string(1, int_string[i]));

            if(willMultiplicationOverflow(individual_int, ten_exponent)) {
                return 0;
            }
            else {
                if(willAdditionOverflow(reverse_int, individual_int * ten_exponent)) {
                    return 0;
                }
                else {
                    reverse_int += individual_int * ten_exponent;
                }
            }

            ten_exponent = 1;
        }    
    }



    if(is_negative) {
        reverse_int *= -1;
    }


    return reverse_int;
}