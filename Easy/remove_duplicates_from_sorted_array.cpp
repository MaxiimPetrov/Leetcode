#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int unique_index = 0;
    int unique_numbers = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[unique_index] != nums[i]) {
            unique_index++;
            nums[unique_index] = nums[i];
            unique_numbers++;
        }
    }

    return unique_numbers;

}