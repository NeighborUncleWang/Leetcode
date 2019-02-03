class TopVotedCandidate {
private:
    map<int, int> leaders;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        unordered_map<int, int> count;
        int leader = persons.front();
        for (int i = 0; i < persons.size(); ++i) {
            if (++count[persons[i]] >= count[leader]) {
                leader = persons[i];
            }
            leaders[i] = leader;
        }
    }

    int q(int t) {
        return leaders.lower_bound(t)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
