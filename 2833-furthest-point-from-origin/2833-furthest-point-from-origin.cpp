class Solution {
public:


int furthestDistanceFromOrigin(string moves) {
    int countL = 0, countR = 0, count_ = 0;

    for (char c : moves) {
        if (c == 'L') countL++;
        else if (c == 'R') countR++;
        else count_++;  // '_'
    }

    return abs(countR - countL) + count_;
}

};