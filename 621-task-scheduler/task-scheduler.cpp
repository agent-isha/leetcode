class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char t : tasks) mp[t]++;

        priority_queue<int> pq;
        for(auto &p : mp) pq.push(p.second);

        int time = 0;

        while(!pq.empty()){
            int cycle = n + 1;
            vector<int> temp;

            while(cycle-- && !pq.empty()){
                int f = pq.top(); pq.pop();
                if(f - 1 > 0) temp.push_back(f - 1);
                time++;
            }
            for(int x : temp) pq.push(x);

            

            if(!pq.empty())
                time += cycle + 1;  
            
        }
        return time;
    }
};
