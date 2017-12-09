#ifndef _CAR_H_
#define _CAR_H
#include <string>
#include <vector>
#include <iostream>

const double quarter_time_calc_1 = .333;
const double quarter_time_calc_2 = 5.825;
const double quarter_speed_calc_1 = 234;
const double sixty_speed_calc_1 = 1.46;
const double sixty_speed_calc_2 = 60;
const double MPHconversion = .00595;
const double MPSconversion = .44707;
const double WATTSconversion = 745.7;
const double c = .33;
const double A = 3.5;
const double D = 1.25;

class car{
private:
  double power;
  double torque;
  double weight;
  double rearEnd;
  double tireHeight;
  int gearNum;
  double maxRPM;
  std::string name;
  std::vector<double> gears;

  double sixtyTime;
  double quarterMile;
  double quarterSpeed;
  double theoreticalMax;
  std::vector<double> gearSpeed;


public:


  void setPower();      //set functions
  void setTorque();
  void setWeight();
  void setRearEnd();
  void setTireHeight();
  void setGearNum();
  void setMaxRPM();
  void setGears();
  void setName();

  double getPower();      //get functions
  double getTorque();
  double getWeight();
  double getRearEnd();
  double getTireHeight();
  int getGearNum();
  double getMaxRPM();
  std::vector<double> getGears();
  std::string getName();
  double getSixtyTime();
  double getQuarterSpeed();
  double getQuarterMile();
  std::vector<double> getGearSpeed(std::vector<double> &);
  double getTheoreticalMax();

  void buildStats();      //master functions
  void buildCar();



};





#endif
