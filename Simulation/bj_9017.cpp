#include <iostream>
#include <vector>
#include <algorithm>

int T, N;
int MAX = 201;

std::vector <std::vector<int>> data_list(MAX);
std::vector <std::vector<int>> result_list(MAX);
std::vector <std::vector<int>> score_list(MAX);

int solve() {
  int max = 0;
  int score = 0;

  for (int i = 0; i < data_list.size(); i++) {
    if (data_list[i].size() < 6)
      result_list[i] = { -1, -1, -1 };

    else {
      score++;
      score_list[i].push_back(score);
    }
  }

  int sum = 0;
  for (int i = 0; i < score_list.size(); i++) {
    for (int j = 0; j < score_list[i].size(); j++) {
      sum += score_list[i][j];
      result_list[i] = { sum, score_list[i][4], i };
    }
  }


  int min = 9999;
  int win_team = 0;

  for (int i = 0; i < result_list.size(); i++) {
    if (result_list[i].size() == 0)
      continue;

    if (min > result_list[i][0]) {
      min = result_list[i][0];
      win_team = result_list[i][2];
    }
    else if (min == result_list[i][0]) {
      if (data_list[win_team][4] < result_list[i][1])
        win_team = win_team;
      else
        win_team = result_list[i][2];
    }
  }
  return win_team;
}



void init() {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < data_list[i].size(); i++)
      data_list[i][j] = 0;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < result_list[i].size(); j++)
      result_list[i][j] = 0;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < score_list[i].size(); j++)
      score_list[i][j] = 0;
}

int main() {
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    init();
    std::cin >> N;
    int grade = 1;

    for (int j = 0; j < N; j++) {
      int data;
      std::cin >> data;
      data_list[data].push_back(grade);
    }
    std::cout << solve();
  }


  return 0;
}