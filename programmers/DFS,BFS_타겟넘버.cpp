#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int depth, int n, int tn)
{
    if(depth==numbers.size())
    {
        if(tn==n)
        {
            answer++;
        }
        return;
    }
    DFS(numbers,depth+1,n-numbers[depth],tn);
    DFS(numbers,depth+1,n+numbers[depth],tn);
}

int solution(vector<int> numbers, int target) {

    DFS(numbers,0,0,target);

    return answer;
}