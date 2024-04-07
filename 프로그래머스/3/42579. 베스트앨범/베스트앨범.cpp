#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) {
        return a.first<b.first;
    }
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, vector<pair<int, int>>> genre_index_plays;
    vector<pair<int, string>> total_plays_genre;

    for (int i = 0; i < genres.size(); i++) {
        genre_index_plays[genres[i]].push_back({ i, plays[i] });
    }

    for (auto iter : genre_index_plays) {
        int total_plays = 0;
        for (int i = 0; i < iter.second.size(); i++) {
            total_plays += iter.second[i].second;
        }
        total_plays_genre.push_back({ total_plays, iter.first });
    }

    sort(total_plays_genre.rbegin(), total_plays_genre.rend());
    for (int i = 0; i < total_plays_genre.size(); i++) {
        string genre = total_plays_genre[i].second;
        vector<pair<int, int>> sort_map = genre_index_plays[genre];
        sort(sort_map.begin(), sort_map.end(), cmp);
        if (sort_map.size() == 1) {
            answer.push_back(sort_map.front().first);
            continue;
        }
        for (int j = 0; j < 2; j++) {
            answer.push_back(sort_map[j].first);
        }
    }

    return answer;
}
