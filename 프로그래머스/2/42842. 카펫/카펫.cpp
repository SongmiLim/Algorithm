#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;


    for (int i = 1; i <= yellow; i++) {
        int w = i;
        int h = yellow / w;

        if (w * h != yellow)
            continue;

        if (brown == 2 * (w + h) + 4) {
            answer.push_back(max(w+2, h+2));
            answer.push_back(min(w+2, h+2));
            break;
        }
    }
    return answer;
}