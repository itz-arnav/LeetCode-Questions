class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        unordered_map<int, array<int, 2>> map;
        int start = 0;
        for(auto & station : stations){
            map[start] = {station[0], station[1]};
            start = station[0];
        }
        map[start] = {target, 0};
        priority_queue<int> maxFuelStation;
        int disCovered = 0;
        int fuelAvail = startFuel;
        int ans = 0;
        int currPos = 0;
        while(1){
            if(currPos == target){
                return ans;
                break;
            }
            auto [nextPos, nextFuel] = map[currPos];
            int distance = nextPos - currPos;
            if(fuelAvail >= distance){
                disCovered += distance;
                fuelAvail -= distance;
                maxFuelStation.push(nextFuel);
                currPos = nextPos;
            }
            else{
                while(!maxFuelStation.empty()){
                    int maxFuel = maxFuelStation.top();
                    maxFuelStation.pop();
                    ans++;
                    fuelAvail += maxFuel;
                    if(fuelAvail >= distance){
                        break;
                    }
                }
                if(fuelAvail < distance){
                    ans = -1;
                    break;
                }
                else{
                    disCovered += distance;
                    fuelAvail -= distance;
                    maxFuelStation.push(nextFuel);
                    currPos = nextPos;
                }
            }
        }
        return ans;
    }
};