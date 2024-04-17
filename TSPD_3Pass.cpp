//This program is to find a optimal path for drone using threepass algorithm
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate Euclidean distance between two points
double distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// Nearest Neighbor TSP heuristic
vector<int> nearestNeighborTSP(vector<pair<int, int>>& points) {
    int n = points.size();
    vector<int> tour;
    vector<bool> visited(n, false);
    tour.push_back(0); // Start from the first point

    for (int i = 0; i < n - 1; ++i) {
        visited[tour.back()] = true;
        int closest = -1;
        double minDist = numeric_limits<double>::max();
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance(points[tour.back()], points[j]) < minDist) {
                closest = j;
                minDist = distance(points[tour.back()], points[j]);
            }
        }
        tour.push_back(closest);
    }

    return tour;
}

// 2-opt swap for TSP tour optimization
void twoOpt(vector<int>& tour, vector<pair<int, int>>& points) {
    int n = tour.size();
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 1; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                double delta = distance(points[tour[i - 1]], points[tour[j]]) + distance(points[tour[i]], points[tour[j + 1]])
                             - distance(points[tour[i - 1]], points[tour[i]]) - distance(points[tour[j]], points[tour[j + 1]]);
                if (delta < 0) {
                    reverse(tour.begin() + i, tour.begin() + j + 1);
                    improved = true;
                }
            }
        }
    }
}

// Main 3-pass TSP algorithm
vector<int> tspDrone(vector<pair<int, int>>& points) {
    // Phase 1: Initial TSP tour using Nearest Neighbor heuristic
    vector<int> initialTour = nearestNeighborTSP(points);
    
    // Phase 2: Drone improvement phase (Not implemented in this basic example)
    // Here, you would implement logic to improve the tour using the drone.
    // You can use techniques like local search or nearest insertion.

    // Phase 3: Final optimization using 2-opt
    twoOpt(initialTour, points);

    return initialTour;
}

int main() {
    vector<pair<int, int>> points = {{0, 0}, {1, 2}, {3, 1}, {5, 2}, {6, 4}};
    vector<int> tour = tspDrone(points);

    cout << "TSP Tour: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
