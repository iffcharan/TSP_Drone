//This program is the implementation of TSP Drone using A* algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Define structures for states and operations
struct State {
    vector<int> visited; // Visited locations
    int current; // Current location
    int cost; // Total cost so far
    int key; // Key for priority queue
    vector<int> path; // Backtrack path
};

struct Operation {
    int start; // Starting location
    int end; // Ending location
    int cost; // Cost of operation
    vector<int> coveringNodes; // Nodes covered by operation
};

// Comparator for priority queue
struct CompareState {
    bool operator()(const State& a, const State& b) const {
        return a.key > b.key;
    }
};

// Function to calculate lower bound key
int calculateKey(const State& s, const vector<int>& remaining) {
    // This is a placeholder function, replace with your own lower bound calculation
    return s.cost + remaining.size();
}

// Function to check if a state is valid
bool isValidState(const State& s, const Operation& o, const unordered_set<int>& truckOnlyNodes) {
    // Check if operation is valid (no truck-only nodes in visited locations)
    for (int node : o.coveringNodes) {
        if (truckOnlyNodes.count(node) && find(s.visited.begin(), s.visited.end(), node) == s.visited.end()) {
            return false;
        }
    }
    return true;
}

// A* algorithm
vector<int> aStar(const vector<int>& locations, const vector<Operation>& operations, int start, const unordered_set<int>& truckOnlyNodes) {
    // Initialize priority queue, set, and starting state
    priority_queue<State, vector<State>, CompareState> pq;
    unordered_set<int> visited;
    State initial;
    initial.visited.push_back(start);
    initial.current = start;
    initial.cost = 0;
    initial.key = calculateKey(initial, locations);
    pq.push(initial);

    // Main loop
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        // Check if goal state reached
        if (current.visited.size() == locations.size() && current.current == start) {
            return current.path;
        }

        // Generate successor states
        for (const Operation& op : operations) {
            if (op.start == current.current && isValidState(current, op, truckOnlyNodes)) {
                State successor = current;
                successor.visited.push_back(op.end);
                successor.current = op.end;
                successor.cost += op.cost;
                successor.key = calculateKey(successor, locations);
                successor.path.push_back(op.end);
                pq.push(successor);
            }
        }
    }

    // No solution found
    return {};
}

int main() {
    // Example data
    vector<int> locations = {1, 2, 3, 4};
    unordered_set<int> truckOnlyNodes = {2};
    vector<Operation> operations = {
        {1, 2, 10, {1, 2}},
        {1, 3, 15, {1, 3}},
        {1, 4, 20, {1, 4}},
        {2, 1, 10, {1, 2}},
        {2, 3, 35, {2, 3}},
        {2, 4, 25, {2, 4}},
        {3, 1, 15, {1, 3}},
        {3, 2, 35, {2, 3}},
        {3, 4, 30, {3, 4}},
        {4, 1, 20, {1, 4}},
        {4, 2, 25, {2, 4}},
        {4, 3, 30, {3, 4}}
    //we can give dynamic inputs also but to reduce implementatioin complexity we provided a static example
    };

    // Start A* algorithm
    vector<int> optimalPath = aStar(locations, operations, 1, truckOnlyNodes);

    // Output optimal path
    cout << "Optimal Path: ";
    for (int node : optimalPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
