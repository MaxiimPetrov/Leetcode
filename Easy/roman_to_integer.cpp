#include <iostream>

int romanToInt(std::string s) {
    int new_int = 0;
    bool num_added_already = false;

    for(int i = 0; i < s.length(); i++) {

        if(!num_added_already) {
            if(s[i] == 'I') {
                if(s[i+1] == 'V') {
                    new_int += 4;
                    i++;
                }
                else if(s[i+1] == 'X') {
                    new_int += 9;
                    i++;
                }
                else {
                    new_int += 1;
                }
                num_added_already = true;
            }            
        }
       
        if(!num_added_already) {
            if(s[i] == 'V') {
                new_int += 5;
                num_added_already = true;
            }
        }
        
        if(!num_added_already) {
            if(s[i] == 'X') {
                if(s[i+1] == 'L') {
                    new_int += 40;
                    i++;
                }
                else if(s[i+1] == 'C') {
                    new_int += 90;
                    i++;
                }
                else {
                    new_int += 10;
                }
                num_added_already = true;
            }
        }

        if(!num_added_already) {
            if(s[i] == 'L') {
                new_int += 50;
                num_added_already = true;
            }
        }

        if(!num_added_already) {
            if(s[i] == 'C') {
                if(s[i+1] == 'D') {
                    new_int += 400;
                    i++;
                }
                else if(s[i + 1] == 'M') {
                    new_int += 900;
                    i++;
                }
                else {
                    new_int += 100;
                }
                num_added_already = true;
            }
        }

        if(!num_added_already) {
            if(s[i] == 'D') {
                new_int += 500;
                num_added_already = true;
            }
        }

        if(!num_added_already) {
            if(s[i] == 'M') {
                new_int += 1000;
                num_added_already = true;
            }
        }

        num_added_already = false;
    }

    

    return new_int;
}
