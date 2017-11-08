#include "collision.h"

bool collision::iscollision(int lane, vector<double> car_state)
{
  bool collision = false;
  double car_s = car_state[2];

  for(int i=0;i<sensor_fusion.size();i++)
  {
      float check_car_d = sensor_fusion[i][6];
      if(check_car_d<(2+4*lane+2) && check_car_d>(2+4*lane-2))
      {
          double vx = sensor_fusion[i][3];
          double vy = sensor_fusion[i][4];
          double check_speed = sqrt(vx*vx+vy*vy);
          double check_car_s = sensor_fusion[i][5];

          check_car_s += ((double)prev_size*0.02*check_speed);

          if(((check_car_s > car_s) && ((check_car_s - car_s) < 30.0)) || (car_s - check_car_s) < 6.0)
          {
              collision = true;
              cout << "collision true" << endl;
              break;
          }
      }
  }
  return collision;
}
