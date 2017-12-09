//Brendon Brandolino
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "car.h"
using namespace std;

int main() {
car automobile;
string word;
string fileName;
ofstream output;
char cont;

while (cont !='q' && cont !='Q') {
automobile.buildCar();
automobile.buildStats();

fileName=automobile.getName();
fileName = fileName+".txt";
output.open(fileName.c_str());
output<<automobile.getName()<<endl;
output<<"Horsepower: "<<automobile.getPower()<<"HP."<<endl;
output<<"Torque: "<<automobile.getTorque()<<"ft/lbs."<<endl;
output<<"Calculated top speed: "<<automobile.getTheoreticalMax()<<" MPH"<<endl;
output<<"Zero to sixty miles per hour time: "<<automobile.getSixtyTime()<<" seconds."<<endl;
output<<"Quarter mile time: "<<automobile.getQuarterMile()<<" seconds."<<endl;
output<<"Quarter mile trap Speed: "<<automobile.getQuarterSpeed()<<" MPH"<<endl;

output.close();
cout<<"Would you like to build another car?"<<endl;
cout<<"Enter Q or q to quit or Y to continue"<<endl;
cin>>cont;
}
  return 0;
}
