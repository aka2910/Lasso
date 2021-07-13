#include "coin&num.h"
#include "lasso.h"

void Coin::initCoin()
{
    coin_start_x = (PLAY_X_START+WINDOW_X)/2;//450
    coin_start_y = PLAY_Y_HEIGHT;
    coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
    coin_circle.setColor(COLOR(255,255,0));
    coin_circle.setFill(true);
    addPart(&coin_circle);
}

void Coin::resetCoin(double coin_start_x)
{
// coin_start_x = (PLAY_X_START+WINDOW_X)/2;
    double coin_speed = COIN_SPEED;
    double coin_angle_deg = COIN_ANGLE_DEG;
    coin_ax = 0;
    coin_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::resetxCoin()
{
    coin_start_x = 750;
    double coin_speed = COIN_SPEED+10;
    double coin_angle_deg = 135;
    coin_ax = 0;
    coin_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
}
void Coin::throwxout()
{
    coin_start_x=900;
    resetxy(coin_start_x,coin_start_y);
}
void Coin::bringxin()
{
    coin_start_x=700;//(PLAY_X_START+WINDOW_X)/2;
    resetxy(coin_start_x,coin_start_y);
}
void Coin::changetobomb()
{
    coin_start_x = 500;//450
    coin_start_y = PLAY_Y_HEIGHT;
    coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE*1.5);
    coin_circle.setColor(COLOR(75,83,32));
    coin_circle.setFill(true);

}
void Num::initNum(string num,double num_start_x)
{
    //num_start_x = (PLAY_X_START+WINDOW_X)/2;//450
    num_start_y = PLAY_Y_HEIGHT;
    num_text.reset(num_start_x, num_start_y,num);
    numit=num;
// coin_circle.setColor(COLOR(75,83,32));
    num_text.setColor(COLOR(0,0,255));
    num_text.setFill(true);
    addPart(&num_text);
}

void Num::resetNum(double num_start_x,double num_angle_deg)
{
// coin_start_x = (PLAY_X_START+WINDOW_X)/2;
    double num_speed = COIN_SPEED;
    //  double num_angle_deg = COIN_ANGLE_DEG;
    num_ax = 0;
    num_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(num_start_x, num_start_y, num_speed, num_angle_deg, num_ax, num_ay, paused, rtheta);
}
void Num::setx(double coin_start_x)
{
    //(PLAY_X_START+WINDOW_X)/2;
    resetxy(coin_start_x,PLAY_Y_HEIGHT);

}
void Num::resetxnum(string num,double num_start_x,double speed,double num_angle_deg)
{
    num_text.reset(num_start_x, PLAY_Y_HEIGHT,num);
    numit=num;
    double num_speed = COIN_SPEED;
    num_ax = 0;
    num_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(num_start_x, num_start_y, num_speed, num_angle_deg, num_ax, num_ay, paused, rtheta);
    release_speed=speed;
}


