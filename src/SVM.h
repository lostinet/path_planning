

#ifndef PATH_PLANNING_STATEMACHINE_H
#define PATH_PLANNING_STATEMACHINE_H

class SVM {

public:
  enum State { KL, LCL, PLCL, PLCR, LCR };
  State evaluate_next_state(State cur_state, int target_lane, int cur_lane, bool all_collision, double vel);

};


#endif
