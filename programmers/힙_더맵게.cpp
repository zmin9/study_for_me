#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> scov;
    
    
    for(int i = 0;i<scoville.size();i++)
    {
        scov.push(scoville[i]);
    }
    
    int count=0,new_scov,top;
    
    while(scov.top()<K)
    {
        if(scov.size()==1)
        {
            count = -1;
            break;
        }
        top=scov.top(); scov.pop();
        new_scov = top + (scov.top() * 2);
        scov.pop();
        count++;
        scov.push(new_scov);
    }
    
    return count;    
}