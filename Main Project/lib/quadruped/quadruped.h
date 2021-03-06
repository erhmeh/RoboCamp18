#ifndef quadruped_H
#define quadruped_H

#include <Arduino.h>
#include <Servo.h>

typedef struct {
  double x, y, z;
} position_t;

class quadruped
{
public:
  void setPins(int pins[]);
  void attachServos();
  /* calculates required angle for servo, 0 for hip (gamma) and 1 for tib-fem (alpha) */
  double calculateAngle(position_t target_effector_coordinate, int servo_type, double z_off);
  void writeServos(double angle, int servo);
  /* Movement functions */
  void startingPosition();
  void standUp();
  void lowerDown();
  void moveForward(int steps);
  void moveBackward(int steps);

  double angles_[8];

private:
  /* 0-1=top-left, 2-3=top-right, 4-5=bottom-left, 6-7=bottom-right */
  /* even nums (including 0) are hip servos, odd nums are tib-fem servos */
  Servo servos_[8];
  /* stores angles of each servo */
  
  int pins_[8];
  /* dimensions of leg components in mm */
  const float femur_ = 49.5;
  const float tibia_ = 141.89;
  const float coxa_ = 27.85; 
};

#endif