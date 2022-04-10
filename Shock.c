//Shock.cpp
#include "Header.h"

/*First Commonly Recurring Constant in Shocks*/
double ShoCon1(double Mach){return (1 + (2.*gam)/(gam+1)*(pow(Mach,2.)-1));}

/*Second Commonly Recurring Constant in Shocks*/
double ShoCon2(double Mach){return ((2+(gam-1)*pow(Mach,2))/((gam+1)*pow(Mach,2)));}

/*Computes the Normal Component of Mach number on an Oblique Shock*/
double MachNormal(double Mach, double beta){return Mach*sin(beta);}

/*Computes Mach Number after Normal Shock*/
double ShockMach(double Mach){
    return sqrt((1.+(gam-1.)/2.*pow(Mach,2))/(gam*pow(Mach,2)-(gam-1.)/2.));}

/*Computes turn angle theta from shock angle beta*/
double beta2theta(double Mach, double beta){
    return atan(2./tan(beta)*(pow(Mach,2)*pow(sin(beta),2)-1.)/(pow(Mach,2)*(gam+cos(2*beta))+2.));}

/*Computes the True Mach Number from Normal Mach number, shock angle and turn angle*/
double MachTrue(double NMach, double beta, double theta){
    return NMach/sin(beta-theta);}

/*Computes the Static Pressure after a normal Shock Using Static Pressure*/
double PAftNShock(double Mach, double Pressure){
    return Pressure*(1. + (2.*gam)/(gam+1.)*(pow(Mach,2.) - 1.));}

/*Computes the Static Temperature afer a Normal Shock using static temperature before shock*/
double TAftNShock(double Mach, double Temperature){
    return Temperature*ShoCon1(Mach)*ShoCon2(Mach);}

/*Computes the Stagnation Pressure After a Normal Shock using Stagnation Pressure Before shock*/
double P0AftNShock(double Mach, double Pressure){
    return Pressure*pow((ShoCon1(Mach)),(-1./(gam-1.))) * pow((ShoCon2(Mach)),(-gam/(gam-1.)));}

/*Computes the value of the Prandlt-Meyer Expansion Function*/
double PMfunc(double Mach){
return pow(((gam+1.)/(gam-1.)),0.5) * atan(pow(((gam-1.)/(gam+1.)*(pow(Mach,2.)-1.)),0.5)) - atan(pow((pow(Mach,2.)-1.),0.5));}

/*Solves for the Mach number after Expansion due to PM Wave*/
double MAftExpansion(double Mach, double theta){
    double PMValue; PMValue = PMfunc(Mach) + theta; return PMInverse_Newton(PMValue, 4);}
