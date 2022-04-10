//Isentropic.c
#include "Header.h"

/*Computes the Speed of Sound using static Temperature*/
double SoundSpeed(double T){return pow((gam * R * T),0.5);}

/*Computes a recurring part of the isentropic flow relation expressions*/
double IseCon(double M){return 1. + (gam-1.)/2.*pow(M,2.);}

/*Takes in Static Temperature, Mach Number, and Gives Stagnation Temperature*/
double Ts2T0(double T,double M){return T*IseCon(M);}

/*Takes in Stagnation Temperature, Mach Number, and Gives Static Temperature*/
double T02Ts(double T0,double M){return T0*pow(IseCon(M),-1.);}

/*Takes Static Pressure, Mach Number, and Gives Stagnation Pressure*/
double Ps2P0(double P,double M){return P*pow(IseCon(M), gam/(gam-1.));}

/*Takes in Stagnation Pressure, Mach Number and Gives Static Pressure*/
double P02Ps(double P0,double M){return P0*pow(IseCon(M),-gam/(gam-1.));}

/*Takes in Static Density, Mach Number, and Gives Stagnation Density*/
double Ds2D0(double rho, double M){return rho*pow((IseCon(M)),(1./(gam-1.)));}

/*Takes in Stagnation Density, Mach Number, Gives Static Density*/
double D02Ds(double rho0, double M){return rho0*pow((IseCon(M)),(-1./(gam-1.)));}

/*Takes in Stagnation Pressure, Static Pressure and Gives Mach Number*/
//double P0Ps2M(double P_0, double P){
//    return (2./(gam-1.)*((P_0/P)**((gam-1.)/gam)-1.))**(0.5);}

/*Computes the Area/ Area at throat Ratio using Mach Number*/
double AAstarRatio(double M){
    return (1./M)*pow(2./(gam+1.)*(1.+(gam-1.)/2.* pow(M,2.)), (gam+1.)/(2.*(gam-1.)));}
