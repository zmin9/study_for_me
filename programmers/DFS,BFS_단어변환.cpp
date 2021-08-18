// DFS 이용

#include <string>
#include <vector>

using namespace std;

int answer = 51;

bool isChangeable(string a, string b)
{
    int count=0;
    for(int i = 0; i < a.size() && count < 2; i++)
        if(a[i]!=b[i])
            count++;
    
    return (count == 1 ? true : false);
}

void dfs(int cur, string target, vector<string> words, int depth, bool visit[])
{
    if(words[cur]==target)
    {        
        if(depth < answer)
            answer = depth;
        return;
    }
    else if(depth == words.size())
        return;
    
    visit[cur] = true;
    depth++;
    
    for(int i = 0; i < words.size(); i++)
        if(!visit[i] && isChangeable(words[cur], words[i]))
            dfs(i, target, words, depth, visit);
}


int solution(string begin, string target, vector<string> words) {
    answer = 51;
    bool visit[50]={false};
    
    for(int i = 0; i < words.size(); i++)
        if(isChangeable(begin, words[i]))
            dfs(i, target, words, 1, visit);

    return (answer == 51 ? 0 : answer);
}