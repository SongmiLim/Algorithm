#include <string>
#include <vector>

using namespace std;


int solution(string t, string p) {
    int answer = 0;

    for (int i = 0; i <= t.size() - p.size(); i++) {
        long long p_num = stoull(p);
        long long t_num = stoull(t.substr(i, p.size()));
        if (p_num >= t_num)
            answer++;
    }

    return answer;
}
