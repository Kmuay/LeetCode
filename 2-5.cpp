class Solution {
public:
    string longestPalindrome(string s) {
        string result="";
        /*
        // 时间复杂度O(n^3)
        for(int i=1; i<=s.size(); i++) {
            for(int j=0; j<=s.size()-i; j++) {
                string temp = "";
                for(int k=j; k<j+i; k++) {
                    temp += s[k];
                }
                if(isPalindrome(temp)) {
                    result = temp;
                    break;
                }
            }
        }

        // 时间复杂度O(n^3)
        for(int i=0; i<s.size(); i++) {
            string temp = "";
            for(int j=i; j<s.size(); j++) {
                temp += s[j];
                if(isPalindrome(temp)) {
                    if(result.size() < temp.size())
                        result = temp;
                }
            }
        }

        // 时间复杂度O(n^2)
        string s1 = "";
        for(int i=0; i<s.size(); i++) {
            if(i!=s.size()-1) {
                s1 += s[i];
                s1 += "#";
            }
            else {
                s1 += s[i];
            }
        }
        for(int i=0; i<s1.size(); i++) {
            string temp = "";
            if(s1[i] != '#') {
                temp = s1[i];
                int j = i-2;
                int k = i+2;
                while(j>=0&&k<=s1.size()-1) {
                    if(s1[j]==s1[k]) {
                        temp = s1[j]+temp+s1[k];
                    }
                    else{
                        break;
                    }
                    j = j-2;
                    k = k+2;
                }
            }
            else {
                int j = i-1;
                int k = i+1;
                while(j>=0&&k<=s1.size()-1) {
                    if(s1[j]==s1[k]) {
                        temp = s1[j]+temp+s1[k];
                    }
                    else{
                        break;
                    }
                    j = j-2;
                    k = k+2;
                }
            }
            if(temp.size() > result.size()) {
                result = temp;
            }
        }
        */

        // Manacher算法 时间复杂度O(n)
        // 1-预处理
        string news = "";
        for(int i=0; i<s.size(); i++) {
            if(i != s.size()-1) {
                news += '#';
                news += s[i];
            }
            else {
                news += '#';
                news += s[i];
                news += '#';
            }
        }
        // 最长回文子串起始位置
        int begin = 0;
        // 最长回文子串长度
        int maxlength = 1;
        // 最远右边界
        int right = 0;
        // 最远右边界对应的回文中心
        int middle = 0;
        int *p = new int[news.size()];
        for(int i=0; i<news.size(); i++) {
            p[i] = 0;
        }
        for(int i=0; i<news.size(); i++) {
            if(i >= right){
                int length = 0;
                int j = i-1;
                int k = i+1;
                while(j>=0&&k<=news.size()-1) {
                    if(news[j] == news[k]) {
                        length++;
                        j--;
                        k++;
                    }
                    else {
                        break;
                    }
                }
                middle = i;
                right = i+length;
                p[i] = length;
                if(length*2+1 > maxlength) {
                    maxlength = length*2+1;
                    begin = i-length;
                }
            }
            else {
                int left_i = middle - (i-middle);
                int length_i = p[left_i];
                if(i+length_i < right) {
                    p[i] = length_i;
                }
                else {
                    int length = 0;
                    int j = i-1;
                    int k = i+1;
                    while(j>=0&&k<=news.size()-1) {
                        if(news[j] == news[k]) {
                            length++;
                            j--;
                            k++;
                        }
                        else {
                            break;
                        }
                    }
                    middle = i;
                    right = i+length;
                    p[i] = length;
                    if(length*2+1 > maxlength) {
                        maxlength = length*2+1;
                        begin = i-length;
                    }
                }
            }
        }
        for(int i=0; i<maxlength; i++) {
            if(news[begin+i]!='#') {
                result += news[begin+i];
            }
        }
        return result;
    }

    /*
    bool isPalindrome(string s) {
        bool result=true;
        for(int i=0; i<s.size()/2; i++) {
            if(s[i]!=s[s.size()-1-i]) {
                result = false;
                break;
            }
        }
        return result;
    }
    */
};