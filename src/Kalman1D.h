/**
    @autor: AMOUSSOU Z. Kenneth
    @date: 22-10-2018
*/
#ifndef H_KALMAN1D
#define H_KALMAN1D

class Kalman1D{
    public:
        Kalman1D();
        Kalman1D(float P, float Q, float R);
        
        void setA(float A);
        void setB(float B);
        void setC(float C);
        void setP(float P);
        void setQ(float Q);
        void setR(float R);
        
        float getK();
        float getEstimate();
        
    private:
        // private functions
        void _predicte();
        void _update();
        
        //
        float _x;   // state
        float _p;   // error covariance
        float _q;   // process covariance
        float _r;   // measurement noise
        
        float _k;    // Kalman gain
        
        float _a;
        float _b;
        float _c;        
};

#endif
