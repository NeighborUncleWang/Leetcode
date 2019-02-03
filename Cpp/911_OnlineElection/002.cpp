class TopVotedCandidate {
private:
    unordered_map<int, vector<int>> votesForCandidates;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        for (int i = 0; i < persons.size(); ++i) {
            votesForCandidates[persons[i]].push_back(times[i]);
        }
    }

    int q(int t) {
        int res = -1, maxVote = -0, mostRecent = -1;
        for (auto& it : votesForCandidates) {
            auto iter = upper_bound(it.second.begin(), it.second.end(), t);
            int vote = iter - it.second.begin();
            if (vote > maxVote || vote == maxVote && vote != 0 && *(iter - 1) > mostRecent) {
                res = it.first;
                maxVote = vote;
                mostRecent = *(iter - 1);
            }
        }
        return res;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
