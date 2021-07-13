#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"

class Coin : public MovingObject
{
    double coin_start_x;
    double coin_start_y;
    double release_speed;
    double release_angle_deg;
    double coin_ax;
    double coin_ay;

    // Moving parts
    Circle coin_circle;

public:
    Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta)
    {
        release_speed = speed;
        release_angle_deg = angle_deg;
        coin_ax = argax;
        coin_ay = argay;
        initCoin();
    }

    void initCoin();
    void changetobomb();
    void resetCoin(double coin_start_x);
    void resetxCoin();
    void resetx2Coin();
    void resetx3Coin();
    void throwxout();
    void bringxin();

}; // End class Coin

class Num : public MovingObject
{
    double num_start_x;
    double num_start_y;
    double release_speed;
    double release_angle_deg;
    double num_ax;
    double num_ay;
    string numit;
    // Moving parts
    Text num_text;

public:
    Num(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta)
    {
        release_speed = speed;
        release_angle_deg = angle_deg;
        num_ax = argax;
        num_ay = argay;
    }

    void initNum(string num,double num_start_x);
    void resetNum(double num_start_x,double num_angle_deg);
    void resetxnum(string num,double num_start_x,double release_speed,double num_angle_deg);
    void setx(double coin_start_x);
    string getnum()
    {
        return numit;
    }
};


#endif
