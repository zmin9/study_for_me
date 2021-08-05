#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day=1;  //작업 일 수
    int n=0;    //해당 일자 배포 가능한 기능의 수

    while(!progresses.empty())
    {
        if(progresses.front()+day*speeds.front()>=100)
        {
            n++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
        else
        {
            if(n!=0)
            {
                answer.push_back(n);
                n=0;
            }
            day++;
        }
    }
    answer.push_back(n);
    return answer;
}