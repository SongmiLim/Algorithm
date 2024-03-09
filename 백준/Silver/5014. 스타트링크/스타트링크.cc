#include <iostream>
#include <queue>
#include <string>
#include <string.h>

#define MAX 1000001

int visited[MAX];
int F, S, G, U, D;

std::string bfs() {
	std::queue <int> q;
	visited[S] = 1;
	q.push(S);

	while(!q.empty()){
		int x = q.front();
		q.pop();

		if (x == G)
			return std::to_string(visited[x]-1);

		for (int next : {U, -D}) {
			int next_floor = next + x;

			if (next_floor <= 0 || next_floor > F)
				continue;
		
			if (visited[next_floor] == 0) {
				q.push(next_floor);
				visited[next_floor] = visited[x] + 1;
			}
		}
	}
	return "use the stairs";
}

int main() {
	memset(visited, 0, sizeof(visited));
	std::cin >> F >> S >> G >> U >> D;
	std::cout<<bfs();

	return 0;
}