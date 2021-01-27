class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        string substring = "";
        
        // 时间复杂度O(n^2)
        /*
        if(s.size() != 0) {
            for(int i=0; i<s.size(); i++) {
                int temp = 1;
                substring = "";
                substring += s[i];
                for(int j=i+1; j<s.size(); j++) {
                    if(substring.find(s[j]) == string::npos) {
                        substring += s[j];
                        temp++;
                    }
                    else {
                        break;
                    }
                }
                if(temp > result) {
                    result = temp;
                }
            }
        }
        */

        // 队列头指针
        int head = 0;
        // 队列尾指针
        int tail = 0;
        for(; tail<s.size(); tail++) {
            if(substring.size() == 0) {
                substring += s[tail];
                result = 1;
            }
            else {
                if(substring.find(s[tail]) == string::npos) {
                    substring += s[tail];
                    if(substring.size() > result) {
                        result = substring.size();
                    }
                }
                else {
                    int newhead = substring.find(s[tail]);
                    string newstring = "";
                    for(newhead+=1;newhead<substring.size();newhead++) {
                        newstring += substring[newhead];
                    }
                    substring = newstring;
                    substring += s[tail];
                    if(substring.size() > result) {
                        result = substring.size();
                    }
                }
            }
        }
        return result;
    }
};