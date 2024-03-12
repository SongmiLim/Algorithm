#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<20>bit2(n);

    while (true) {
        if (bit2.count() == bitset<20>(++n).count()){
            answer = n;
            break;}
    }
    return answer;
}