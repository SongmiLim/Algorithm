#include <iostream>
#include <vector>

int switch_num;
int student_num;

std::vector <int> switch_status;
std::vector <std::pair<int, int>> student_status;

void operate_switch() {
  for (int i = 0; i < student_status.size(); i++) {
    if (student_status[i].first == 1) {
      int new_switch = student_status[i].second;

      int j = 1;
      while (1) {
        if (new_switch * j > switch_num)
          break;
        if (switch_status[new_switch * j] == 0)
          switch_status[new_switch * j] = 1;
        else if (switch_status[new_switch * j] == 1)
          switch_status[new_switch * j] = 0;
        j++;
      }
    }
    else if (student_status[i].first == 2) {
      int new_switch = student_status[i].second;
      switch_status[new_switch]==1 ? switch_status[new_switch] = 0: switch_status[new_switch] = 1;
      int j = 1;

      while (1) {
        if (new_switch - j <= 0 || new_switch + j > switch_num)
          break;

        if (switch_status[new_switch + j] == switch_status[new_switch - j]) {
          if (switch_status[new_switch + j] == 1) {
            switch_status[new_switch + j] = 0;
            switch_status[new_switch - j] = 0;
          }
          else if (switch_status[new_switch + j] == 0) {
            switch_status[new_switch + j] = 1;
            switch_status[new_switch - j] = 1;
          }
          j++;
        }
        else 
          break;

      }
    }
  }
}


int main() {
  switch_status.push_back(-1);

  std::cin >> switch_num;
  for (int i = 0; i < switch_num; i++) {
    int status;
    std::cin >> status;
    switch_status.push_back(status);
  }

  std::cin >> student_num;
  for (int i = 0; i < student_num; i++) {
    int student_sex, student_switch;
    std::cin >> student_sex >> student_switch;
    student_status.push_back({ student_sex, student_switch });

  operate_switch();

  for (int i = 1; i < switch_status.size(); i++) {
    std::cout << switch_status[i] << " ";
    if (i % 20 == 0)
      std::cout << std::endl;
  }


  return 0;

}