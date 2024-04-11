#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 2;
    if (n == 1) {
        return 0;
    }

    while (n != 1) {
        while (n % i == 0 && n!=1) {
            n /= i;
            cout << i << "\n";
        }
        i++;
    }
    return 0;
}