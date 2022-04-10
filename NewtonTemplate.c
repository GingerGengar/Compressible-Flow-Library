
/*Function x*/
double y(double x){
return ;}

/*Function to find gradient*/
double gradient(double x){return (y(x+dx)-y(x))/dx;}

/*Function to guess where the solution might be*/
double newguess(double c, double m){return -c/m;}

/*Newton Method Solver*/
void NewtonMethod(){yval = y(guess); while(fabs(yval)> ERROR){
    m = gradient(guess); c = yval-m*guess;
    guess = newguess(c,m); yval = y(guess);}}
