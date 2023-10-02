// Runtime 65.49%, Memory 48.94%

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxVote = 0;
        unordered_map<int, int> voteCount;
        for (int i = 0; i < persons.size(); i++) {
            voteCount[persons[i]]++;
            if (voteCount[persons[i]] >= maxVote) {
                maxVote = voteCount[persons[i]];
                leadingCand.insert(pair<int, int>(times[i], persons[i]));
            }
        }
    }
    
    int q(int t) {
        map<int, int>::const_iterator iter = leadingCand.upper_bound(t);
        return (--iter)->second;
    }

private:
    map<int, int> leadingCand;
};
