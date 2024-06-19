#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string longest_prefix = "";
    int index = 0;

    std::sort(strs.begin(), strs.end());

    std::string first_string = strs[0];
    std::string last_string = strs[strs.size() - 1];

    while(first_string[index] == last_string[index] && index < last_string.length()) {
        longest_prefix += first_string[index];
        index++;
    }

    return longest_prefix;
        
}
