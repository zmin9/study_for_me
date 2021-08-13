#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> onBridge;
    
    for(int i=0;i<bridge_length;i++)
        onBridge.push(0);
    
    int second = 0, bw = 0;
    
    for(int i=0;i<truck_weights.size();)
    {
        second++;
        if(bw-onBridge.front()+truck_weights[i] > weight)
        {
            bw -= onBridge.front();
            onBridge.pop();
            onBridge.push(0);
            continue;
        }
        else
        {
            bw = bw - onBridge.front() + truck_weights[i];
            onBridge.pop();
            onBridge.push(truck_weights[i]);
            i++;
        }
        
        
    }
    return second + bridge_length;
}