// Runtime 14.42%, Memory 14.59%

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int minIndex = 0;
        int maxIndex = arr.size() - 1;
        while (true) {
            int p = (maxIndex + minIndex) / 2;
            if (arr[p] < arr[p - 1]) {
                maxIndex = p;
                continue;
            }
            if (arr[p] < arr[p + 1]) {
                minIndex = p;
                continue;
            }
            return p;
        }
        return 0;
    }
};
