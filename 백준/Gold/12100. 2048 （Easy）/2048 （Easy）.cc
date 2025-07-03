#include <iostream>
#include <vector>
using namespace std;

int N, ANS;

vector<vector<int>> move(const vector<vector<int>>& board1, int dir) {
	bool update = false;
	auto board = board1;
	if (dir == 0) {
		for (int i = 0; i < N; ++i) {
			int block1 = 0, pos = 0;
			for (int j = 0; j < N; ++j) {
				int now = board[j][i];
				if (now != 0) {
					if (block1 == 0) {
						block1 = now;
					}
					else if (block1 == now) {
						board[pos][i] = now + block1;
						++pos;
						update = true;
						block1 = 0;
					}
					else {
						board[pos][i] = block1;
						block1 = now;
						++pos;
					}
				}
				board[j][i] = 0;
			}
			if (block1 != 0) {
				board[pos][i] = block1;
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; ++i) {
			int block1 = 0, pos = N - 1;
			for (int j = N - 1; j >= 0; --j) {
				int now = board[j][i];
				if (now != 0) {
					if (block1 == 0) {
						block1 = now;
					}
					else if (block1 == now) {
						board[pos][i] = now + block1;
						--pos;
						update = true;
						block1 = 0;
					}
					else {
						board[pos][i] = block1;
						block1 = now;
						--pos;
					}
				}
				board[j][i] = 0;
			}
			if (block1 != 0) {
				board[pos][i] = block1;
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; ++i) {
			int block1 = 0, pos = 0;
			for (int j = 0; j < N; ++j) {
				int now = board[i][j];
				if (now != 0) {
					if (block1 == 0) {
						block1 = now;
					}
					else if (block1 == now) {
						board[i][pos] = now + block1;
						++pos;
						update = true;
						block1 = 0;
					}
					else {
						board[i][pos] = block1;
						block1 = now;
						++pos;
					}
				}
				board[i][j] = 0;
			}
			if (block1 != 0) {
				board[i][pos] = block1;
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; ++i) {
			int block1 = 0, pos = N - 1;
			for (int j = N - 1; j >= 0; --j) {
				int now = board[i][j];
				if (now != 0) {
					if (block1 == 0) {
						block1 = now;
					}
					else if (block1 == now) {
						board[i][pos] = now + block1;
						--pos;
						update = true;
						block1 = 0;
					}
					else {
						board[i][pos] = block1;
						block1 = now;
						--pos;
					}
				}
				board[i][j] = 0;
			}
			if (block1 != 0) {
				board[i][pos] = block1;
			}
		}
	}
	return board;
}

void dfs(int depth, const vector<vector<int>>& board) {
	if (depth == 5) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				ANS = max(ANS, board[i][j]);
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		auto next = move(board, dir);
		
		dfs(depth + 1, next);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<vector<int>> board(N + 1, vector<int>(N + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	dfs(0, board);
	cout << ANS;

    return 0;
}