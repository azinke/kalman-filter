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
    _a    = A; return;
}

/**
    function: setB
    @summary: set the input transition parameter
    @parameter:
        B: scalar value to update the input transition parameter
    @return: none
*/
void Kalman1D::setB(float B){
    _b = B; return;
}

/**
    function: setC
    @summary: set the observer parameter
    @parameter:
        C: scalar value to update the observer parameter
    @return: none
*/
void Kalman1D::setC(float C){
    _c = C; return;
}

/**
    function: setP
    @summary: set the process covariance
    @parameter:
        P: scalar value to update the process covariance
    @return: none
*/
void Kalman1D::setP(float P){
    _p = P; return;
}

/**
    function: setQ
    @summary: set the process noise
    @parameter:
        Q: scalar value to update the process noise
    @return: none
*/
void Kalman1D::setQ(float Q){
    _q = Q; return;
}

/**
    function: setR
    @summary: set the measurement noise
    @parameter:
        R: scalar value to update the measurement noise
    @return: none
*/
void Kalman1D::setR(float R){
    _r = R; return;
}

/**
    function: _predicte
    @summary: compute de posterior estimate and the process covariance
    @parameter:
        P: scalar value to update the process covariance
    @return: none
*/
void Kalman1D::_predicte(){
    _x = _a * x + _b * u;
    _p = _a * _a * _p + _q;
    return;
}

/**
    function: _update
    @summary: compute de posterior estimate and the process covariance
    @parameter:
        z: new measurement or data from sensor (or file)
    @return: none
*/
void Kalman1D::_update(float z){
    float y = 0; // estimated output
    float s = 0;
    y = z - (_C * _x)
    _x = _A * x + _B * u;   // posterior estimate of the system's state
    _p = _A * _A * _p + _q; // compute the estimate's covariance
    
    s = _c * _c * _p +_r;   
    _k = (_p * _c) / s;     // compute new Kalman Gain
    _x += _k * y;           // compute new state
    _p = (1 - _k * _c)/_p;  // compute new process estimate's covariance
    return;
}

/**
    function: _update
    @summary: compute de posterior estimate and the process covariance
    @parameter:
        P: scalar value to update the process covariance
    @return: none
*/
void Kalman1D::getOutput(float data){
    _predicte();
    _update();
    return _x;  // new estimate
}
