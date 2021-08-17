#include <stdio.h>
#include <algorithm>

using namespace std;

int map[202][202] = { 1001 };
int tempMap[202][202];

void Infection(int S, int N)
{
	if (S == 0)
		return;

	copy(&map[0][0], &map[0][0] + 202 * 202, &tempMap[0][0]);

	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			if (map[row][col] == 0)
			{
				int virus = 1001;
				if (map[row + 1][col] != 0 && map[row + 1][col] < virus)
					virus = map[row + 1][col];
				if (map[row - 1][col] != 0 && map[row - 1][col] < virus)
					virus = map[row - 1][col];
				if (map[row][col - 1] != 0 && map[row][col - 1] < virus)
					virus = map[row][col - 1];
				if (map[row][col + 1] != 0 && map[row][col + 1] < virus)
					virus = map[row][col + 1];

				(virus == 1001 ? tempMap[row][col] = 0 : tempMap[row][col] = virus);
			}
		}
	}

	copy(&tempMap[0][0], &tempMap[0][0] + 202 * 202, &map[0][0]);

	Infection(S - 1, N);
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	int S, X, Y;
	scanf("%d %d %d", &S, &X, &Y);

	if (map[X][Y] != 0)
		printf("%d", map[X][Y]);
	else
	{
		Infection(S, N);
		printf("%d", map[X][Y]);
	}
}