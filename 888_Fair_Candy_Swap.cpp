// Runtime 26.75%, Memory 10.58%

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        // Get sum difference between alice and bob
        int alice_size = 0;
        int bob_size = 0;
        for (int i = 0; i < aliceSizes.size(); i++) {
            alice_size += aliceSizes[i];
        }
        for (int i = 0; i < bobSizes.size(); i++) {
            bob_size += bobSizes[i];
        }
        int diff = (alice_size - bob_size) / 2;

        // Make set of alice - diff and bob + diff
        set<int> total;
        for (int i = 0; i < aliceSizes.size(); i++) {
            total.insert(aliceSizes[i] - diff);
        }
        for (int i = 0; i < bobSizes.size(); i++) {
            std::set<int>::iterator iter = total.find(bobSizes[i]);
            if (iter != total.end()) return {bobSizes[i] + diff, bobSizes[i]};
        }

        return {};
    }
};
