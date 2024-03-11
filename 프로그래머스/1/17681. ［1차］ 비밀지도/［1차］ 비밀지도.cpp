#include <string>
#include <vector>
#include <bitset>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector <int> tmp_a;
    vector <int> tmp_b;

    for (int i = 0; i < n; i++) {
        string s = "";
        tmp_a.clear();
        tmp_b.clear();

        // arr1 2진수로 변환
        while (true) {
            tmp_a.push_back(arr1[i] % 2);
            arr1[i] = arr1[i] / 2;
            if (arr1[i] == 0)
                break;
        }

        // arr2 2진수로 변환
        while (true) {
            tmp_b.push_back(arr2[i] % 2);
            arr2[i] = arr2[i] / 2;
            if (arr2[i] == 0)
                break;
        }

        // arr1 | arr2
        while (tmp_a.size() < n) {
            tmp_a.push_back(0);
        }
        while (tmp_b.size() < n) {
            tmp_b.push_back(0);
        }

        for (int i = n-1; i >=0; i--) {
            if (tmp_a[i]==0 && tmp_b[i] == 0) {
                s += " ";
            }
            else
                s += "#";
        }
        answer.push_back(s);
    }
    return answer;
}