#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>

using namespace std;

int maze[10][10];
int vis[10][10], dis[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct Node {
	int pre_x, pre_y;
	int cur_x, cur_y;
	int next_x, next_y;
	Node(int cur_x, int cur_y, int pre_x, int pre_y) :cur_x(cur_x), cur_y(cur_y), pre_x(pre_x), pre_y(pre_y) {}
	Node(int cur_x, int cur_y) :cur_x(cur_x), cur_y(cur_y) {};
	Node() {};
};

Node ans[10][10];
queue<Node> que;

void BFS() {
	while (!que.empty()) {
		que.pop();
	}
	que.push(Node(0, 0));
	dis[0][0] = 0;
	vis[0][0] = 1;
	while (!que.empty()) {
		Node node = que.front();
		que.pop();
		int cur_x = node.cur_x;
		int cur_y = node.cur_y;

		for (int i = 0; i <= 3; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5 && maze[next_x][next_y] == 0 && vis[next_x][next_y] == 0) {
				que.push(Node(next_x, next_y));
				dis[next_x][next_y] = dis[cur_x][cur_y] + 1;
				vis[next_x][next_y] = 1;
				ans[next_x][next_y] = Node(next_x,next_y,cur_x, cur_y);
				if (next_x == 4 && next_y == 4) {
					return;
				}
			}
		}
	}
}


int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
	BFS();
	stack<Node> S;
	int cur_x = 4;
	int cur_y = 4;
	while (true) {
		S.push(Node(cur_x, cur_y));
		if (cur_x == 0 && cur_y == 0) { break; }
		int x = ans[cur_x][cur_y].pre_x;
		int y = ans[cur_x][cur_y].pre_y;
		cur_x = x;
		cur_y = y;
	}
	while (!S.empty()) {
		Node node = S.top();
		S.pop();
		printf("(%d, %d)\n", node.cur_x, node.cur_y);

	}
	return 0;
}