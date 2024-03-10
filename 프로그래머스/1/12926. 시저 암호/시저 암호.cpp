#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {

    string answer = "";
    for (auto& a : s) {
        if (islower(a)) {
            if (!islower(a += (n % 26)))
                a -= 26;
        }
        else if (isupper(a)) {
            if (!isupper(a += (n % 26)))
                a -= 26;
        }
    }
    answer = s;

    return answer;
}

/*string solution(string s, int n) {
    
    string answer = "";

    for (int i = 0; i<s.size(); i++) {
        if (s[i] == ' ')
            continue;
        else if ('A' <= s[i] && s[i] <= 'Z') {
            if ((s[i] + n) > 'Z')
                s[i] += n - ('Z' - 'A') - 1;
            else
                s[i] += n;
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            if ((s[i] + n) > 'z')
                s[i] += n - ('z' - 'a') - 1;
            else
                s[i] += n;
        }
    }

    answer = s;
    return answer;
}*/