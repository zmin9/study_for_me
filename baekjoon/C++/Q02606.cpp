#include <stdio.h>

bool map[101][101] = {false};
bool visit[101] = {false};

void DFS(int cur, int* virus ,int computerN)
{
	if (visit[cur])
		return;

	(*virus)++;
	visit[cur] = true;

	for (int i = 1; i <= computerN; i++)
		if (map[cur][i])
			DFS(i, virus, computerN);
}

int main()
{
	int virus = 0, N, line;

	scanf("%d", &N);
	scanf("%d", &line);
	for (int i = 0; i < line; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = true;
	}

	DFS(1, &virus, N);

	printf("%d", virus - 1);
}