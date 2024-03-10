#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;

    for (int i = 0; i < sizes.size(); i++) {
        w = max(w, min(sizes[i][0], sizes[i][1]));
        h = max(h, max(sizes[i][0], sizes[i][1]));
    }
    answer = w * h;

    return answer;
}


/* int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][1] > sizes[i][0]){
            int temp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = temp;
           }
    }
    int max_x = 0;
    for (int j = 0; j < sizes.size(); j++) {
        if (sizes[j][0] > max_x) {
            max_x = sizes[j][0];
        }
    }

    int max_y = 0;
    for (int k = 0; k < sizes.size(); k++) {
        if (sizes[k][1] > max_y) {
            max_y = sizes[k][1];
        }
    }
    answer = max_x * max_y;

    return answer;
}*/