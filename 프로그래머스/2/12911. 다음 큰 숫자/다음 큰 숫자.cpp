#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num1 = n;
    int num2 = n+1;
    int cpy_num2 = n + 1;
    int cnt_num1 = 0;
    int cnt_num2 = 0;

    vector <int> binary_num;

    while (num1 >0) {
        binary_num.push_back(num1 % 2);
        num1 = num1 / 2;
    }
    
    for (int i = 0; i < binary_num.size(); i++) {
        if (binary_num[i] == 1)
            cnt_num1++;
    }

    while (true) {
        cnt_num2 = 0;
        binary_num.clear();

        while (cpy_num2 > 0) {
            binary_num.push_back(cpy_num2 % 2);
            cpy_num2 = cpy_num2 / 2;
        }
        for (int i = 0; i < binary_num.size(); i++) {
            if (binary_num[i] == 1)
                cnt_num2++;
        }
        if (cnt_num1 == cnt_num2) {
            answer = num2;
            break;
        }
        num2+=1;
        cpy_num2 = num2;
    }

    return answer;
}