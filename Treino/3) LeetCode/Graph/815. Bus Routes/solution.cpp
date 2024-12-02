class Solution {
private:
    int bfs(vector<vector<int>>& routes, unordered_map<int, vector<int>>& graph, int source, int target) {
        unordered_set<int> used;
        used.insert(source);

        queue<int> next;
        next.push(source);

        int buses = 1;
        while (!next.empty()) {
            int top = next.front();
            next.pop();

            if (top == target) {
                return buses;
            }

            for (int stop : graph[get<0>(top)]) {
                if (used.contains(stop)) {
                    continue;
                }
                used.insert(stop);
                next.push(stop);
            }

            buses++;
        }

        return -1;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); i++) {
            for (int j1 = 0; j1 < routes[i].size(); j1++) {
                for (int j2 = j1 + 1; j2 < routes[i].size(); j2++) {
                    graph[routes[i][j1]].push_back(routes[i][j2]);
                    graph[routes[i][j2]].push_back(routes[i][j1]);
                }
            }
        }

        return bfs(routes, graph, source, target);
    }
};
