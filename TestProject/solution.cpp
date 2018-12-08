#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int r, c, ret = 2147483647;
char maze[1010][1010], temp[1001][1001];
int visit[1001][1001];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void spreadFire() {
	int j, k, i, ax, ay;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (temp[i][j] == 'F') {
				for (k = 0; k < 4; k++) {
					ax = i + dx[k];
					ay = j + dy[k];

					if (ax >= 0 && ax < r && ay >= 0 && ay < c && (maze[ax][ay] == '.' || maze[ax][ay] == 'J')) {
						maze[ax][ay] = 'F';
					}
				}
			}
		}
	}
}

void returnFire() {
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			maze[i][j] = temp[i][j];
	}
}


void dfs(int x, int y, int depth) {
	int ax, ay, i, j;
	printf("dfs : %d\n", depth);
	if (maze[x][y] == 'F')
		return;

	if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
		ret = min(ret, depth);
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				printf("%c", maze[i][j]);
			}
			printf("\n");
		}
		return;
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			temp[i][j] = maze[i][j];
	}

	for (i = 0; i < 4; i++) {
		ax = x + dx[i];
		ay = y + dy[i];

		if (ax >= 0 && ax < r && ay >= 0 && ay < c && (maze[ax][ay] == '.' || maze[ax][ay] == 'J') && visit[ax][ay] == 0) {
			spreadFire();
			visit[ax][ay] = 1;

			dfs(ax, ay, depth + 1);

			visit[ax][ay] = 0;
			returnFire();
		}
	}
}


int main(int argc, const char * argv[]) {
	int i, j;

	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", maze[i]);

	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (maze[i][j] == 'J')
				dfs(i, j, 1);
		}
	}

	if (ret == 2147483647)
		printf("IMPOSSIBLE");
	else
		printf("%d\n", ret);

	return 0;
}