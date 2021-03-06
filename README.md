# CarND-Path-Planning-Project
Self-Driving Car Engineer Nanodegree Program
   
### Simulator.
You can download the Term3 Simulator which contains the Path Planning Project from the [releases tab (https://github.com/udacity/self-driving-car-sim/releases).

### Goals
In this project your goal is to safely navigate around a virtual highway with other traffic that is driving +-10 MPH of the 50 MPH speed limit. You will be provided the car's localization and sensor fusion data, there is also a sparse map list of waypoints around the highway. The car should try to go as close as possible to the 50 MPH speed limit, which means passing slower traffic when possible, note that other cars will try to change lanes too. The car should avoid hitting other cars at all cost as well as driving inside of the marked road lanes at all times, unless going from one lane to another. The car should be able to make one complete loop around the 6946m highway. Since the car is trying to go 50 MPH, it should take a little over 5 minutes to complete 1 loop. Also the car should not experience total acceleration over 10 m/s^2 and jerk that is greater than 50 m/s^3.

#### The map of the highway is in data/highway_map.txt
Each waypoint in the list contains  [x,y,s,dx,dy] values. x and y are the waypoint's map coordinate position, the s value is the distance along the road to get to that waypoint in meters, the dx and dy values define the unit normal vector pointing outward of the highway loop.

The highway's waypoints loop around so the frenet s value, distance along the road, goes from 0 to 6945.554.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./path_planning`.

Here is the data provided from the Simulator to the C++ Program

#### Main car's localization Data (No Noise)

["x"] The car's x position in map coordinates

["y"] The car's y position in map coordinates

["s"] The car's s position in frenet coordinates

["d"] The car's d position in frenet coordinates

["yaw"] The car's yaw angle in the map

["speed"] The car's speed in MPH

#### Previous path data given to the Planner

//Note: Return the previous list but with processed points removed, can be a nice tool to show how far along
the path has processed since last time. 

["previous_path_x"] The previous list of x points previously given to the simulator

["previous_path_y"] The previous list of y points previously given to the simulator

#### Previous path's end s and d values 

["end_path_s"] The previous list's last point's frenet s value

["end_path_d"] The previous list's last point's frenet d value

#### Sensor Fusion Data, a list of all other car's attributes on the same side of the road. (No Noise)

["sensor_fusion"] A 2d vector of cars and then that car's [car's unique ID, car's x position in map coordinates, car's y position in map coordinates, car's x velocity in m/s, car's y velocity in m/s, car's s position in frenet coordinates, car's d position in frenet coordinates. 

## Details

1. The car uses a perfect controller and will visit every (x,y) point it recieves in the list every .02 seconds. The units for the (x,y) points are in meters and the spacing of the points determines the speed of the car. The vector going from a point to the next point in the list dictates the angle of the car. Acceleration both in the tangential and normal directions is measured along with the jerk, the rate of change of total Acceleration. The (x,y) point paths that the planner recieves should not have a total acceleration that goes over 10 m/s^2, also the jerk should not go over 50 m/s^3. (NOTE: As this is BETA, these requirements might change. Also currently jerk is over a .02 second interval, it would probably be better to average total acceleration over 1 second and measure jerk from that.

2. There will be some latency between the simulator running and the path planner returning a path, with optimized code usually its not very long maybe just 1-3 time steps. During this delay the simulator will continue using points that it was last given, because of this its a good idea to store the last points you have used so you can have a smooth transition. previous_path_x, and previous_path_y can be helpful for this transition since they show the last points given to the simulator controller with the processed points already removed. You would either return a path that extends this previous path or make sure to create a new path that has a smooth transition with this last path.

## Tips

A really helpful resource for doing this project and creating smooth trajectories was using http://kluge.in-chemnitz.de/opensource/spline/, the spline function is in a single hearder file is really easy to use.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!


## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).







# Writeup 

## Path Planning Project

## Rubric Points The code compiles correctly.

### Code must compile without errors with cmake and make. Given that we've made CMakeLists.txt as general as possible, it's recommend that you do not change it unless you can guarantee that your changes will still compile on any platform.

Yes, Code is compileable and no errors encountered. 


## Rubric Points The car is able to drive at least 4.32 miles without incident..

### The top right screen of the simulator shows the current/best miles driven withoutincident. Incidents include exceeding acceleration/jerk/speed, collision, anddriving outside of the lanes. Each incident case is also listed below in more
detail.

Yes, 23.64 Miles achieved.  

## Rubric Points The car drives according to the speed limit.

### The car doesn’t drive faster than the speed limit. Also the car isn’t driving much slower than speed limit unless obstructed by traffic. 

Yes, the upper limit is constrained at 49.5 mph, and the car will slow down only if there is a traffic jam in all its adjacent lanes.  

## Rubric Points Max Acceleration and jerk are not Exceeded.

### The car does not exceed a total acceleration of 10 m/s^2 and a jerk of 10m/s^3.

Maximum acceleration and deceleration is constrained by a reasonable numerical value as introduced in the class. And double lane changing is prohibited so the lateral jerk is also under control. No warning message during the whole trip of 30 min. 

## Rubric Points Car dose not have collisions

### The car must not come into contact with any of the other cars on the road.

Yes, confirmed.

## Rubric Points The car stays in its lane for the time between changing lanes. 

### The car doesn’t spend more than a 3 second length out side the lane lines during changing lanes, and every other time the car stays inside one of the 3 lanes on the right hand side of the road. 

Yes, the lane changing manoeuvre is clear-cut. and is not slalom-like while driving straight. 

## Rubric Points The car is able to change lanes

### The car is able to smoothly change lanes when it makes sense to do so, such as when behind a slower moving car and an adjacent lane is clear of other traffic.  

the lane changing decision is just in time when there is open road available at a nearby lane. in this case no deceleration is expected. 

## Rubric Points There is a reflection on how to generate paths.

### the code model for generating paths is described in detail, This can be part of the README or a separate doc labelled “Model Documentation” 

My implementation is based on the walkthrough video presented in the class. 

Collision identifier was introduced in my code block. sensor fusion data was injected into the algorithm, inside which we calculate other vehicle’s speed, s coordinate from Frenet and lane number. and using them for the collision
detection. 

we split the collision detection into 2 categories, if there is a car drive in front of us less than a safety distance, then we activate the too_close flag, set it to ‘true’. 

 
```
 if((check_car_lane!=cur_lane) && (check_car_s-car_s)<10.0 && (check_car_s-car_s)<30.0){

  too_close = true;

} 
```


if a car drives in adjacent lane, either drives in front of me up to 30 meters or later behind less than 10 meters, will trigger a specific flag labeling the path free of impact, then preparing for lane change.  

```
if((check_car_lane==cur_lane) && (car_s-check_car_s)>0.0 && (check_car_s-car_s)<30.0){
    ...
}
```

a Boolean vector is used to labeling/activate the available adjacent lane/lanes. 

```
vector<bool> laneFlag = {true,true,true};

laneFlag[cur_lane] = false; '
```

in order to labeling dis-qualified lanes:


```
if((check_car_lane==cur_lane) && (car_s-check_car_s)>0.0 && (check_car_s-car_s)<30.0){

    laneFlag[check_car_lane] = false;

}
```


Freedom of Lane changing maneuver is constrained so double lane slalom is prohibited. 

 
```
bool oneLaneChange(int cur_lane, int target_lane)
{   
if (cur_lane == 0 && target_lane == 1) {

return true;  
}   
if (cur_lane == 1 && (target_lane == 0 || target_lane == 2)) {

return true;   
}
if (cur_lane == 2 && target_lane == 1) {

return true;  
}
    return false;
}
```

 
to trigger lane shifting. if too_close, meanwhile exists a qualified candidate lane labeled ‘ture’, then activate lane shifting.  

 
```
if (too_close) {
   
   for (int i = 0; i < 3; i++) {

      if (laneFlag[i] && oneLaneChange(lane, i) {

             cur_lane = i;        
      } 
   }
}
```

 
To ensure the car drives according to the speed limit at 50 mph, the car lunched at 0 mph with step size of velocity coefficient at 0.224, which results a reasonable acceleration without introducing any uncomfortable jerk. the maximum
velocity is also under monitoring, if we go beyond 49.5mph, no more speed up.
too_close label is activated to reduce the speed by the same rate to avoid jerk feeling while decelerating. 

 
```
if (too_close) {

    ref_vel -= 0.224;

} else if (ref_vel < 49.5) {

    ref_vel += 0.224;
}
```

 
as taught in the class, trajectory generation module yield a smooth cubic spine. this track interpolation method provided an outperformed result. the spline library header file is quoted, and we feed 5 points into the pipeline: 2 points from the trajectory generated in the last time step; 3 more waypoints at 30/60/90 meters ahead in a given lane. 


```
vector<double> next_wp0 = getXY(car_s + 30/60/90, (2 + 4 * cur_lane), map_waypoints_s,map_waypoints_x, map_waypoints_y);
```


Finally there is a counter introduced. the purpose is to moderate the lane changing response, to discourage an aggressive driving
behavior. 

 
```
num_units_in_current_lane += 1;
   ...
if ((laneFlag[i] && oneLaneChange(lane,i) && (num_units_in_current_lane > 10)){
   ...
num_units_in_current_lane = 0;
}
```

