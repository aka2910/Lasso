#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"
#include "coin&num.h"

#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 90

#define LASSO_G 30
#define COIN_G 30

#define LASSO_SIZE 10
#define LASSO_RADIUS 50
#define COIN_SIZE 5
#define lives_y 20

class Lasso: public MovingObject
{
    double lasso_start_x;
    double lasso_start_y;
    double release_speed;
    double release_angle_deg;
    double lasso_ax;
    double lasso_ay;
    double lasso_radius=50;

    // Moving parts
    Circle lasso_circle;
    Circle lasso_loop;

    // Non-moving parts
    Line lasso_line;
    Line lasso_band;

    // State info
    bool lasso_looped;
    Coin *the_coin;
    Coin *the_coin1;
    Coin *the_coin2;
    Num *the_num;

    int num_coins;
    int level=0;
    bool flag=0;
    int lives=5;
    bool flagnum1=0;
    bool flagnum2=0;
    bool flagnum3=0;
    bool flagnum4=0;

    void initLasso();
public:
    Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta)
    {
        release_speed = speed;
        release_angle_deg = angle_deg;
        lasso_ax = argax;
        lasso_ay = argay;
        initLasso();
    }

    void draw_lasso_band();
    void yank();
    void loopit();
    void addAngle(double angle_deg);
    void addSpeed(double speed);
    void lassorad(double radius);
    void nextStep(double t);
    void check_for_coin(Coin *coin);
    bool check_for_bomb(Coin *coin);
    void check_for_twocoins(Coin *coin1,Coin *coin2);
    bool isCoinAttatched(Coin *coin,int lvl,int n);

    bool check_for_num(Num *num,int n);
    bool isNumAttatched(int n);
//    void resetflagnums(Num *num1,Num *num2,Num *3,Num *4);
    int getNumCoins()
    {
        return num_coins;
    }
    int getLevel()
    {
        return level;
    }

}; // End class Lasso

#endif
