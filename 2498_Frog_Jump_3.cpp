// Runtime 46.70%, Memory 37.92%

class Solution {
public:
    int maxJump(vector<int>& stones) {
        const int stoneSize = stones.size();
        int maxVal = stones[1] - stones[0];
        for (int i = 0; i < stoneSize - 2; i++) {
            maxVal = max(maxVal, stones[i + 2] - stones[i]);
        }
        return max(maxVal, stones[stoneSize - 1] - stones[stoneSize - 2]);
    }
};
