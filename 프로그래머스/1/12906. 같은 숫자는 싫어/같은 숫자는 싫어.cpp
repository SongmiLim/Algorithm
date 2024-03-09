#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer = arr;
    vector<int>::iterator pos = unique(answer.begin(), answer.end());
    answer.erase(pos, answer.end());
    //answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}