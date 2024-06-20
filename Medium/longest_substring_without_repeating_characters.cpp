#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> char_index_map;
    int longest_length = 0;
    int left_pointer = 0;

    for(int right = 0; right < s.length(); right++) {
        char current_char = s[right];

        if(char_index_map.find(current_char) != char_index_map.end() && char_index_map[current_char] >= left_pointer) {
            left_pointer = char_index_map[current_char] + 1;
        }

        char_index_map[current_char] = right;
        
        longest_length = std::max(longest_length, right - left_pointer + 1);
    }

    return longest_length;
}