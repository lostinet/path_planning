#ifndef PATH_PLANNING_JMTGENERATOR_H
#define PATH_PLANNING_JMTGENERATOR_H
#include <vector>

using namespace::std;

class TrajectoryGenerator{

public:
  vector<vector<double>> generateTrajectories(vector<double> car_state, vector<double> previous_path_x,
                                              vector<double> previous_path_y, int target_lane, double target_vel);

};


#endif
