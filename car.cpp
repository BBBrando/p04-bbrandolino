#include "car.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>


void car::setPower(){
  std::cout<<"Please enter the power of the car in horsepower."<<std::endl;
  std::cout<<"Numbers between 100 and 400 are common."<<std::endl;
  std::cin>>power;
  if (power < 1) {
    std::cout<<"Please enter a number greater than 1."<<std::endl;
    std::cin>>power;
  }
}
void car::setTorque(){
  std::cout<<"Please enter the torque of the car in ft/lb."<<std::endl;
  std::cout<<"Numbers between 80 and 600 are common."<<std::endl;
  std::cin>>torque;
  if (torque < 1) {
    std::cout<<"Please enter a number greater than 1."<<std::endl;
    std::cin>>torque;
  }
}
void car::setWeight(){
  std::cout<<"Please enter the weight of the car in lbs."<<std::endl;
  std::cout<<"Weight between 1500 and 6000 are common."<<std::endl;
  std::cin>>weight;
  if (weight < 1) {
    std::cout<<"Please enter a number greater than 1."<<std::endl;
    std::cin>>weight;
  }
}
void car::setRearEnd(){
  std::cout<<"Please enter the rear end ratio."<<std::endl;
  std::cout<<"Common ratios are: 4.10, 3.73, 3.08, 2.73."<<std::endl;
  std::cin>>rearEnd;
  if (rearEnd <= 0) {
    std::cout<<"Please enter a number greater than 0."<<std::endl;
    std::cin>>weight;
  }
}
void car::setTireHeight(){
  std::cout<<"Please enter the tire height in inches."<<std::endl;
  std::cout<<"Common sizes are between 21 inches and 32 inches."<<std::endl;
  std::cin>>tireHeight;
  if (tireHeight <= 0) {
    std::cout<<"Please enter a number greater than 0."<<std::endl;
    std::cin>>tireHeight;
  }
}
void car::setGearNum(){
  std::cout<<"Please enter the number of gears."<<std::endl;
  std::cout<<"Common transmissions have between 3 and 6 gears."<<std::endl;
  std::cin>>gearNum;
  if (gearNum < 1) {
    std::cout<<"Please enter a number greater than 0."<<std::endl;
    std::cin>>gearNum;
  }
}
void car::setMaxRPM(){
  std::cout<<"Please enter the maximum engine RPM."<<std::endl;
  std::cout<<"Common limits are between 5500 and 7000 RPM."<<std::endl;
  std::cin>>maxRPM;
  if (maxRPM < 1) {
    std::cout<<"Please enter a number greater than 1."<<std::endl;
    std::cin>>maxRPM;
  }
}
void car::setGears(){
  std::cout<<"Please enter the gear ratios for the transmission."<<std::endl;
  std::cout<<"Enter the ratios in descending order"<<std::endl;
  std::cout<<"EX: a Chevrolet 4 speed 700r4 has the ratios 3.06, 1.63, 1.00, .70"<<std::endl;
  std::cout<<"EX: a Ford 3 speed C6 has the ratios 2.72. 1.54, 1.00"<<std::endl;
  std::cout<<"EX: a Toyota 5 speed 3.830, 2.062, 1.436, 1.00, .838"<<std::endl;
  gears.resize(getGearNum());
  for (int x = 0; x < gears.size(); x++) {
    double gear;
    std::cin>>gear;
    gears[x]=gear;
  }
}
void car::setName(){
  std::cout<<"Please enter the vehicle name."<<std::endl;
  std::cin>>name;
}

void car::buildCar(){
  setName();
  setPower();
  setTorque();
  setWeight();
  setRearEnd();
  setTireHeight();
  setMaxRPM();
  setGearNum();
  setGears();
}

double car::getPower(){
  return power;
}
double car::getTorque(){
  return torque;
}
double car::getWeight(){
  return weight;
}
double car::getRearEnd(){
  return rearEnd;
}
double car::getTireHeight(){
  return tireHeight;
}
int car::getGearNum(){
  return gearNum;
}
double car::getMaxRPM(){
  return maxRPM;
}
std::vector<double> car::getGears(){
  return gears;
}
std::string car::getName(){
  return name;
}



double car::getQuarterSpeed(){
  return quarterSpeed=(pow((getPower()/getWeight()),quarter_time_calc_1))*quarter_speed_calc_1;
}
double car::getQuarterMile(){
  return quarterMile=(pow((getWeight()/getPower()),quarter_time_calc_1))*quarter_time_calc_2;

}
double car::getSixtyTime(){
  return sixtyTime=((getQuarterMile()/getQuarterSpeed())/sixty_speed_calc_1)*sixty_speed_calc_2;
}
std::vector<double> car::getGearSpeed(std::vector<double> &){
  gearSpeed.resize(gears.size());
  for (int counter = 0; counter < gears.size(); counter++) {
    gearSpeed[counter]= MPHconversion*(getMaxRPM()*(getTireHeight()/2))/(gears[counter]*getRearEnd());
  }
  return gearSpeed;
}
double car::getTheoreticalMax(){
  double P = getPower()*WATTSconversion;

  theoreticalMax = pow((2*P/(c*D*A)),.333);
  theoreticalMax = theoreticalMax/MPSconversion;
  if (theoreticalMax > gearSpeed[gearNum-1]) {
    theoreticalMax = gearSpeed[gearNum-1];
  } else if (theoreticalMax = gearSpeed[gearNum-1]) {
    return theoreticalMax;
  }
    else{
    return theoreticalMax;
  }
}
void car::buildStats(){
  std::cout<<"Estimated quarter mile speed is: "<<getQuarterSpeed()<<" miles per hour."<<std::endl;
  std::cout<<"Estimated quarter mile time is: "<<getQuarterMile()<<" seconds."<<std::endl;
  std::cout<<"Estimated 0 to 60 time is: "<<getSixtyTime()<<" seconds."<<std::endl;
  getGearSpeed(gears);
  std::cout << "Maximum speed for each gear is: " <<std::endl;
  for (int i = 0; i < gearSpeed.size(); i++) {
    std::cout<<gearSpeed[i]<<" MPH, ";
    }
    std::cout<<std::endl;
  std::cout<<"That calculated theoretical top speed of your car is "<<getTheoreticalMax()<<" miles per hour."<<std::endl;

}
