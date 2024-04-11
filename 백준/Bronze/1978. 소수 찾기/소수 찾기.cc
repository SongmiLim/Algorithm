#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector <int> num_list;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num_list.push_back(num);
    }
    int cnt = 0;

    for (auto& a : num_list) {
        bool flag = true;
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                flag = false;
            }
        }
        if (flag && a!=1)
            cnt++;
    }
    cout << cnt;
    return 0;
}