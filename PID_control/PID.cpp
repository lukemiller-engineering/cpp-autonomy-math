/* 
pid_controller.cpp
Real-time PID control demo in C++
Author: Luke Miller
Date: July 29, 2025

*/

#include <iostream>
#include "pid_class.hpp"

int main(){
	PID pid(1.0, 0.1, 0.05);
	double pos = 0.0;
	double vel = 0.0;
	double dt = 0.01;
	double target = 10.0;

	for(double t=0; t<= 5.0; t += dt){
		double cmd = pid.update(target,pos,dt);
		vel += cmd*dt;
		pos += vel*dt;
		std::cout<< t << "," << target << "," << pos << "," << cmd <<"\n";
	}
	return 0;
} 
