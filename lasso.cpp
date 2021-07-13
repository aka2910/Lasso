#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin&num.h"

using namespace simplecpp;

void Lasso::draw_lasso_band()
{
    double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
    double arad = release_angle_deg*PI/180.0;
    double xlen = len*cos(arad);
    double ylen = len*sin(arad);
    lasso_band.reset(lasso_start_x, lasso_start_y, (lasso_start_x-xlen), (lasso_start_y+ylen));
    lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso()
{
    lasso_start_x = (PLAY_X_START+LASSO_X_OFFSET);
    lasso_start_y = (PLAY_Y_HEIGHT-LASSO_Y_HEIGHT);
    lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
    lasso_circle.setColor(COLOR("red"));
    lasso_circle.setFill(true);
    lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
    lasso_loop.setColor(COLOR(165,42,42));
    lasso_loop.setFill(true);
    addPart(&lasso_circle);
    addPart(&lasso_loop);
    lasso_looped = false;
    the_coin = NULL;
    num_coins = 0;

    lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
    lasso_line.setColor(COLOR(165,42,42));

    lasso_band.setColor(COLOR(138,43,226));
    draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank()
{
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
    lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
    lasso_loop.setFill(true);
    lasso_looped = false;
} // End Lasso::yank()

void Lasso::loopit()
{
    if(lasso_looped)
    {
        return;    // Already looped
    }
    lasso_loop.reset(getXPos(), getYPos(),lasso_radius);//LASSO_RADIUS=50
    lasso_loop.setFill(false);
    lasso_looped = true;

} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg)
{
    release_angle_deg += angle_deg;
    if(release_angle_deg < MIN_RELEASE_ANGLE_DEG)
    {
        release_angle_deg = MIN_RELEASE_ANGLE_DEG;
    }
    if(release_angle_deg > MAX_RELEASE_ANGLE_DEG)
    {
        release_angle_deg = MAX_RELEASE_ANGLE_DEG;
    }
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed)
{
    release_speed += speed;
    if(release_speed < MIN_RELEASE_SPEED)
    {
        release_speed = MIN_RELEASE_SPEED;
    }
    if(release_speed > MAX_RELEASE_SPEED)
    {
        release_speed = MAX_RELEASE_SPEED;
    }
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addSpeed()

void Lasso::lassorad(double radius)
{
    lasso_radius=radius;
}



void Lasso::nextStep(double stepTime)
{
    draw_lasso_band();
    MovingObject::nextStep(stepTime);

    lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

void Lasso::check_for_coin(Coin *coinPtr)
{
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double coin_x = coinPtr->getXPos();
    double coin_y = coinPtr->getYPos();
    double xdiff = (lasso_x - coin_x);
    double ydiff = (lasso_y - coin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS&&distance!=0)
    {
        flag=1;
        the_coin = coinPtr;
        the_coin->getAttachedTo(this);
        num_coins++;
        if (num_coins%3==0 && num_coins>0)level++;
    }
} // EndLasso::check_for_coin()
void Lasso::check_for_twocoins(Coin *coinPtr1,Coin *coinPtr2)
{
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double coin_x1 = coinPtr1->getXPos();
    double coin_y1 = coinPtr1->getYPos();
    double xdiff1 = (lasso_x - coin_x1);
    double ydiff1 = (lasso_y - coin_y1);
    double coin_x2 = coinPtr2->getXPos();
    double coin_y2 = coinPtr2->getYPos();
    double xdiff2 = (lasso_x - coin_x2);
    double ydiff2 = (lasso_y - coin_y2);
    double distance1 = sqrt((xdiff1*xdiff1)+(ydiff1*ydiff1));
    double distance2 = sqrt((xdiff2*xdiff2)+(ydiff2*ydiff2));
    if(distance1 <= LASSO_RADIUS&&distance1!=0&&distance2<= LASSO_RADIUS&&distance2!=0)
    {
        flag=1;
        the_coin1 = coinPtr1;
        the_coin1->getAttachedTo(this);
        the_coin2 = coinPtr2;
        the_coin2->getAttachedTo(this);
        num_coins++;
        if (num_coins%3==0&& num_coins>0)level++;
    }
}
bool Lasso::isCoinAttatched(Coin *coinPtr,int level,int n)
{
    if(flag)
    {
        the_coin=coinPtr;
        if(level%3==0&&n==1)the_coin->resetCoin(450);
        if(level%3==1&&n==1)the_coin->resetxCoin();
        if(level%3==2&&n==1)the_coin->resetCoin(750);
        if(level%3==2&&n==2)the_coin->resetCoin(700);
        // if(level>2&&level%3==1)the_coin->resetCoin(450);
        //  if(level>2&&level%3==0)the_coin->resetxCoin();
        if(level%3==2&&n==1)flag=1;
        else flag=0;
        return 1;
    }
    return 0;
}
bool Lasso::check_for_bomb(Coin *coinPtr)
{
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double coin_x = coinPtr->getXPos();
    double coin_y = coinPtr->getYPos();
    double xdiff = (lasso_x - coin_x);
    double ydiff = (lasso_y - coin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= lasso_radius&&distance!=0)
    {
        the_coin = coinPtr;
        the_coin->getAttachedTo(this);
        return 1;
    }
    return 0;
}

bool Lasso::check_for_num(Num *num,int n)
{
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double coin_x = num->getXPos();
    double coin_y = num->getYPos();
    double xdiff = (lasso_x - coin_x);
    double ydiff = (lasso_y - coin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= lasso_radius&&distance!=0)
    {
        if(n==1)flagnum1=1;
        if(n==2)flagnum2=1;
        if(n==3)flagnum3=1;
        if(n==4)flagnum4=1;
        the_num = num;
        the_num->getAttachedTo(this);
        return 1;
    }
    return 0;
}

bool Lasso::isNumAttatched(int n)
{

    if(n==1)
    {
        if(flagnum1)
        {
            flagnum1=0;
            return 1;
        }
    }
    if(n==2)
    {
        if(flagnum2)
        {
            flagnum2=0;
            return 1;
        }
    }
    if(n==3)
    {
        if(flagnum3)
        {
            flagnum3=0;
            return 1;
        }
    }
    if(n==4)
    {
        if(flagnum4)
        {
            flagnum4=0;
            return 1;
        }
    }
    return 0;
}

