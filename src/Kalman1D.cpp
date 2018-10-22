/**
    @autor: AMOUSSOU Z. Kenneth
    @date: 22-10-2018
*/
#include <Kalman1D.h>

/**
    @function: Constructor
    @parameter: none
**/
Kalman1D::Kalman1D(){
    _p = 1.0;
    _q = 1.0;
    _r = 1.0;
}

/**
    @function: Constructor
    @parameter:
        P: estimate error covariance
        Q: Process noise
        R: measurement noise
**/
Kalman1D::Kalman1D(float P, float Q, float R){
    _p = P;
    _q = Q;
    _r = R;
}

/**
    function: setA
    @summary: set the state transition parameter
    @parameter:
        A: scalar value to update the state transition parameter
    @return: none
*/
void Kalman1D::setA(float A){
    _A = A; return;
}

/**
    function: setB
    @summary: set the input transition parameter
    @parameter:
        B: scalar value to update the input transition parameter
    @return: none
*/
void Kalman1D::setB(float B){
    _B = B; return;
}

/**
    function: setC
    @summary: set the observer parameter
    @parameter:
        C: scalar value to update the observer parameter
    @return: none
*/
void Kalman1D::setC(float C){
    _C = C; return;
}
