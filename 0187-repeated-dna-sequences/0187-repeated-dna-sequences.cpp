class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
//fixed window k =10
        set<int> seen;
        set<int> result;
        int K =10;
         if(s.size() < K) return {};

        int rep = 0; //val of a sequence of 10 chars initially
        //A =0
        //C =1;
        //G =2;
        //T=3;
        map<char, int> map;
        map.insert({'A', 0});
        map.insert({'C', 1});
        map.insert({'G', 2});
        map.insert({'T', 3});
        //AAAAACCCCCAAAAACCCCCGGGTTT
        //i
        //0123456789 -indices
        //9876543210 - powers
        for(int i = 0; i <= K; i++) {
            int power = K -i-1;
            rep = rep + pow(4, power) * map[s[i]];
        }

        seen.insert(rep);

        //AAAAACCCCCAAAAACCCCCGGGTTT
        //          i
        //0123456789 -indices
        //9876543210 - powers
        //rep = 4^9 * 0 + ... + 4^0*1
        //new rep = (rep- 4^9 * 0) *4 + 0
        for(int i = K; i<s.size(); i++){
            rep = rep - pow(4, K-1) * map[s[i-K]];
            rep = rep*4;
            rep = rep + map[s[i]];
        
            if(seen.contains(rep)) {
                result.insert(rep);
            }

            seen.insert(rep);
        }

        // Decode result into DNA strings
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