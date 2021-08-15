#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[27][27];
vector<int> apartments;

void DFS(int row, int col, int* count)
{
	if (map[row][col] == 0)
		return;

	(*count)++;
	map[row][col] = 0;

	DFS(row + 1, col, count);
	DFS(row - 1, col, count);
	DFS(row, col + 1, count);
	DFS(row, col - 1, count);
}


int main()
{
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1)
			{
				int count = 0;
				DFS(i, j, &count);
				apartments.push_back(count);
			}
		}
	}

	sort(apartments.begin(), apartments.end());

	printf("%d\n", apartments.size());

	for (int i = 0; i < apartments.size(); i++)
		printf("%d\n", apartments[i]);
}