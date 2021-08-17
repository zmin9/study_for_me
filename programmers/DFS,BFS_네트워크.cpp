#include <string>
#include <vector>

using namespace std;

bool visit[200]={false};

void dfs(int n, vector<vector<int>> com, int cur)
{
    if(visit[cur])
        return;
    
    visit[cur]=true;
    
    for(int i = 0; i < n; i++)
    {
        if(com[cur][i]==1)
            dfs(n, com, i);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            answer++;
            dfs(n, computers, i);
        }
    }
    return answer;
}