#define f first
#define s second
class Solution {
private:
	int n;
	vector<string> board;
	vector<vector<string>> res;
	
	void solve(int row) {
		if (row == n) {
			res.push_back(board);
			return;
		}

		for (int col = 0; col < n; ++col)
		{
			board[row][col] = 'Q';
			if (valid(row, col)) {
				solve(row+1);
			} 
			board[row][col] = '.';
		}
	}

	bool valid(int ROW, int COL) {
		vector<pair<int,int>> dirs = 
                    {{-1,-1}, {-1,0}, {-1,1},
									   {0, -1}, 		     {0,1},
									   {1, -1}, {1, 0}, {1,1}};
		for (auto d: dirs) {
			int k = 1;
			int nr = ROW + k*d.f, nc = COL + k*d.s;
			while (nr < n && nc < n && nr >= 0 && nc >= 0) {
				if (board[nr][nc] == 'Q')
					return false;
				k++;
				nr = ROW + k*d.f;
				nc = COL + k*d.s;
			}
		}

		return true;
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		this->n = n;
		this->board = vector<string> (n, string (n, '.'));
		solve(0);
		return res;
	}
};
