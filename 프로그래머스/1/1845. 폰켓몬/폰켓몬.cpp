#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = nums.size() / 2;
    
    set <int> num_set(nums.begin(), nums.end());

    if (num_set.size() < cnt) {
        answer = num_set.size();
    }
    else {
        answer = cnt;
    }


    return answer;
}
