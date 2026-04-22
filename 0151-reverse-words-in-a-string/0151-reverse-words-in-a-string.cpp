class Solution {
public:

    string trim(const string &s){
        int start = 0, end = s.size() - 1;
        while(start <= end && isspace(s[start])) start++;
        while(end >= start && isspace(s[end])) end--;
        return s.substr(start, end - start + 1);
    }

    vector<string> split(const string &s) {
        vector<string> res;
        string word = "";
        
        for(char c : s){
            if(c == ' '){
                if(!word.empty()){
                    res.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if(!word.empty()) res.push_back(word);
        return res;
    }

    string join(vector<string> &v) {
        string res = "";
        for(int i = 0; i < v.size(); i++){
            if(i > 0) res += " ";
            res += v[i];
        }
        return res;
    }

    string reverseWords(string s) {
        string trimmed = trim(s);
        vector<string> arr = split(trimmed);

        int i = 0, j = arr.size() - 1;
        while(i < j){
            swap(arr[i], arr[j]);
            i++; j--;
        }

        return join(arr);
    }
};