#ifndef PATH_PLANNING_PREDICTION_H
#define PATH_PLANNING_PREDICTION_H

#include <vector>

using namespace::std;

class collision {

public:
  bool iscollision(int lane, vector<double> car_state);

  bool all_lane_collision = false;
  // int path_size = 50;
  // double end_path_s;

};


#endif //PATH_PLANNING_PREDICTION_H
