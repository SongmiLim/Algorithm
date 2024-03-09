#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    vector<int> temp;
    temp = arr;
    temp.push_back(-1);

    for (int i = 0; i < temp.size()-1; i++) {
        if (temp[i] == temp[i + 1]) {
            continue;
        }
        answer.push_back(temp[i]);
    }

    return answer;
}