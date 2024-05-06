# TSP_Drone

This project presents an implementation of the Traveling Salesman Problem (TSP) with drones, utilizing the Three-Pass algorithm and the A* algorithm for route optimization. The TSP is a classic problem in combinatorial optimization, where the goal is to find the shortest possible route that visits each city exactly once and returns to the starting city.

# Three-Pass Algorithm:

-->The Three-Pass algorithm divides the TSP with drones problem into three distinct phases: initial TSP tour generation, drone improvement       phase, and final optimization phase.

-->Initial TSP tour generation: A basic TSP tour is generated using heuristics like Nearest Neighbor or Minimum Spanning Tree to create a       starting route for the drone.

-->Drone improvement phase: The drone optimizes the tour further by visiting additional nodes or performing other actions to minimize the       total distance traveled.

-->Final optimization phase: The tour undergoes final optimization techniques like 2-opt or 3-opt to further enhance the solution.

# A* Algorithm Integration:

-->A* algorithm is integrated into the drone improvement phase to find optimal paths between nodes.

-->A* utilizes heuristic functions to estimate the cost from the current node to the goal node, guiding the search towards the most              promising paths first.

-->Factors such as obstacles, wind conditions, and battery limitations are considered during pathfinding to ensure efficient drone               navigation.

#Implementation
--> Here we implemented A* and 3 pass algorithms C++ for understanding.
--> And then to include real time data we used python and to calculate murray formulaes one must need gurobi.

#How to execute
-->To run the code, use the syntax presented below:

Usage: gurobi.sh <formulation.py> <instance_file> [options]
    <formulation.py>     : formulation python file.
    <instance_file>      : path of instance input file(s).

Options:
    -e <drone_endurance> : specify drone battery endurance (default: 40).
    -m <big_m_value>     : specify maximum objective value (default: 5000).
    -murray              : use murray rules within formulation.
    -sol <solution_file> : read initial solution.
    -out <solution_file> : specify output solution file name.
    -time <time_limit>   : runtime limit in seconds (default: 900).
    -validate            : use formulation only to validate the initial solution.
    
Examples:
    python3 fstsp.py data/5a
    python3 murray_fstsp.py data/5b
    python3 fstsp.py data/5a -e 50 -m 100
    python3 fstsp.py data/20140810T123437v1 -e 20 -sol initial_solution.txt -out final_solution.txt -time 3600
