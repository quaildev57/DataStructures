//gpt AI answer for optimised as it uses unordered_set and no map use (instead direct character encoding)

class Solution {
public:

    int encode(char c) {
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3;
    }

    vector<string> findRepeatedDnaSequences(string s) {

        int K = 10;

        if(s.size() < K) return {};

        unordered_set<int> seen;
        unordered_set<int> result;

        seen.reserve(s.size());
        result.reserve(s.size());

        int highestPower = 1;

        for(int i = 1; i < K; i++) {
            highestPower *= 4;
        }

        int rep = 0;

        // Build first window
        for(int i = 0; i < K; i++) {
            rep = rep * 4 + encode(s[i]);
        }

        seen.insert(rep);

        // Sliding window
        for(int i = K; i < s.size(); i++) {

            // Remove outgoing character
            rep -= encode(s[i-K]) * highestPower;

            // Shift remaining characters
            rep *= 4;

            // Add incoming character
            rep += encode(s[i]);

            if(seen.count(rep)) {

                if(result.insert(rep).second) {

                    // Decode only when a sequence repeats
                    int val = rep;
                    string dna = "";

                    for(int j = 0; j < K; j++) {

                        int digit = val % 4;

                        if(digit == 0) dna += 'A';
                        else if(digit == 1) dna += 'C';
                        else if(digit == 2) dna += 'G';
                        else dna += 'T';

                        val /= 4;
                    }

                    reverse(dna.begin(), dna.end());

                    // Store decoded sequence
                    // (We can use a separate answer vector)
                    // See below.
                }
            }

            seen.insert(rep);
        }

        vector<string> ans;

        for(int val : result) {

            string dna = "";

            for(int j = 0; j < K; j++) {

                int digit = val % 4;

                if(digit == 0) dna += 'A';
                else if(digit == 1) dna += 'C';
                else if(digit == 2) dna += 'G';
                else dna += 'T';

                val /= 4;
            }

            reverse(dna.begin(), dna.end());
            ans.push_back(dna);
        }

        return ans;
    }
};