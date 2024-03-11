#include <string>
#include <vector>
#include <bitset>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector <int> tmp;

    for (int i = 0; i < n; i++) {
        string ans = "";
        arr1[i] = arr1[i] | arr2[i];

        for(int j=0;j<n;j++) {
            if (arr1[i]%2 ==0)
                ans = " " + ans;
            else
                ans = "#" + ans;
            arr1[i] /= 2;
        }
        answer.push_back(ans);
    }
    return answer;
}