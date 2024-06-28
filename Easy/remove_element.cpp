#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int non_val_nums = 0;
    int last_position = nums.size() - 1;

    for(int i = 0; i < nums.size(); i++) {
        if(i > last_position) {
            return non_val_nums;
        }
        if(nums[i] == val) {
            while(nums[last_position] == val) {
                last_position--;
                if(last_position < 0 || last_position <= i) {
                    return non_val_nums;
                }
            }
            nums[i] = nums[last_position];
            last_position--;
            non_val_nums++;
        }
        else{
            non_val_nums++;
        }
    }
    

    return non_val_nums; 
}