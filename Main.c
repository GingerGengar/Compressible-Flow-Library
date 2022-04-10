//Main.c
#include "Header.h"

/*First Command Line Argument: Target value of implicit function
Second Command Line Argumnt: Initial guess*/
int main(int argc, char** argv){
    //Target value of y
    y_supposed = strtod(argv[1],NULL);
    
    //Initialize Guess
    guess = strtod(argv[2],NULL);
    
    //Print Result
    printf("%lf", guess);

return 0;}

