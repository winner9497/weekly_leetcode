// Runtime 95.72%, Memory 8.41%
// Runtime 67.84%, Memory 67.14%

/**
    Main idea: For middle index j, precompute
    - the max value on the left side of the index j
    - the max value on the right side of the index j
    - iterate through j index and find max triplet value
*/

/**
    To save more memory, how about changing the vector int map<int, pair<int, int>>
    Similar to the calendar problem, keys are maximum value changing points,
    and the values are the left right max value at the changing points
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int len = nums.size();
        vector<int> left_val(len);
        vector<int> right_val(len);
        int max_left_val = 0;
        int max_right_val = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] > max_left_val) max_left_val = nums[i];
            left_val[i] = max_left_val;
            if (nums[len-1-i] > max_right_val) max_right_val = nums[len-1-i];
            right_val[len-1-i] = max_right_val;
        }

        long long result = 0;
        for (int j = 1; j < len-1; j++) {
            const long long val = static_cast<long long>((left_val[j-1] - nums[j])) * static_cast<long long>(right_val[j+1]);
            if (val > result) result = val;
        }

        return result;
    }
};
