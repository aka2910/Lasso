#include <simplecpp>
#include<bits/stdc++.h>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include "MovingObject.h"
#include "lasso.h"
#include "coin&num.h"
#include "highscore.h"
#include "numgame.h"
#include "design.h"
using namespace std;

// When t is pressed, throw lasso
// If lasso within range, make coin stick
// When y is pressed, yank lasso
// When l is pressed, loop lasso
// when - is pressed decrease speed
// when = is pressed increase speed
// when ],[ add and subtract angle
// When q is pressed, quit

int main()
{
    initCanvas("Lasso by Aka", WINDOW_X, WINDOW_Y);
    Text welcome(400,300,"WELCOME TO LASSO GAME");
    Rectangle wcome(400,300,textWidth("WELCOME TO LASSO GAME")+4,20);//create welcome box
    drawdesign();
    wait(3);
    Rectangle canvaswcome(400,300,800,600);
    canvaswcome.setColor(COLOR(255,255,255));
    canvaswcome.setFill(true);
    Text menu(400,200,"MAIN MENU");
    Text coingame(400,280,"Coin Game");
    Text numbergame(400,310,"Number Game");
    Text quit(400,340,"Quit");

    Rectangle r1(400,280,textWidth("Coin Game")+4, 20);//create buttons on main menu
    Rectangle r2(400,310,textWidth("Number Game")+4,20);
    Rectangle r3(400,340,textWidth("Quit")+4,20);
    while(true)
    {
        int w=getClick();
        int x=w/65536, y=w%65536;
        int choice; //used to store choice
        if(270<=y&&y<=290&&(400-0.5*(textWidth("Coin Game")+4))<=x&&x<=(400+0.5*(textWidth("Coin Game")+4)))choice=1;
        else if(300<=y&&y<=320&&(400-0.5*(textWidth("Number Game")+4))<=x&&x<=(400+0.5*(textWidth("Number Game")+4)))choice=2;
        else if(330<=y&&y<=350&&(400-0.5*(textWidth("Quit")+4))<=x&&x<=(400+0.5*(textWidth("Quit")+4)))choice=3;
        else choice=4;  //end of choice making
        if(choice==3)exit(0);
        else if(choice==4)//if click is outside any button
        {
            Text warn(x,y," Click! on a button :) ");
            wait(0.5);
        }
        else if(choice==1)//coin game starts
        {
            int scr[3];    //stores score
            string name[3]; //strors name
            cout<<"**Initial leaderboard**\n";//prints on the terminal
            display(scr,name); //displays initial leaderboard called from highscore.h
            int min_curr_score=minscore();//minimum score in initial leaderboard
            while(true)
            {
                bool flag=0;
                Rectangle canvas1(400,300,800,600);
                canvas1.setColor(COLOR(255,255,255));
                canvas1.setFill(true);//clears canvas by overlaying with white
                Text coingame(400,280,"Dark Mode");
                Text numbergame(400,310,"Light Mode");
                Rectangle r1(400,280,textWidth("Dark Mode")+4, 20);
                Rectangle r2(400,310,textWidth("Light Mode")+4,20);
                int w=getClick();
                int x=w/65536, y=w%65536;
                int choice;//choice for light/dark mode
                if(270<=y&&y<=290&&(400-0.5*(textWidth("Dark Mode")+4))<=x&&x<=(400+0.5*(textWidth("Dark Mode")+4)))choice=1;
                else if(300<=y&&y<=320&&(400-0.5*(textWidth("Light Mode")+4))<=x&&x<=(400+0.5*(textWidth("Light Mode")+4)))choice=2;
                else choice =3;
                if(choice==3)
                {
                    Text warn(x,y," Click! on a button :)");
                    wait(0.5);
                }
                else
                {

                    Rectangle canvas(400,300,800,600);
                    if(choice==2)  canvas.setColor(COLOR(144,238,144));
                    canvas.setFill(true);
                    Text control(740,20,"CONTROLS ");
                    Text t(740,40,"T - throw lasso ");
                    Text y(740,60,"Y - yank lasso ");
                    Text l(740,80,"L - loop lasso ");
                    Text q(740,100,"Q - exit :-(   ");
                    Text finalmsg(4000,3000,"Hey!Also check the terminal");
                    control.setColor(COLOR(144,238,144));
                    if(choice==2) t.setColor(COLOR(144,238,144));
                    if(choice==2) y.setColor(COLOR(144,238,144));
                    if(choice==2) l.setColor(COLOR(144,238,144));
                    if(choice==2) q.setColor(COLOR(144,238,144));

                    //Text more(740,120,"check comments for more");
                    Rectangle cont(740,60,100,98);
                    //int level=1; //  used to add more levels to game at interval of 3 points
                    char lev[256]; //use to store level
                    char liv[256];
                    char tym[256];
                    // Draw lasso at start position
                    double release_speed = INIT_RELEASE_SPEED; // m/s
                    double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
                    double lasso_ax = 0;
                    double lasso_ay = LASSO_G;
                    bool paused = true;
                    bool rtheta = true;
                    Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
                    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
                    b1.setColor(COLOR("blue"));
                    Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
                    b2.setColor(COLOR("blue"));

                    string msg("Cmd :   ");
                    Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
                    char coinScoreStr[256];
                    charPressed.setColor(COLOR(144,238,144));
                    sprintf(coinScoreStr, "Score: %d ", lasso.getNumCoins());
                    Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);
                    if(choice==2)coinScore.setColor(COLOR(144,238,144));
                    Text lev1(130, 42,lev);
                    if(choice==2) lev1.setColor(COLOR(144,238,144));
                    Text tyme(130,61,tym);
                    if(choice==2) tyme.setColor(COLOR(144,238,144));
                    int time=90;
                    //   Text liv1(PLAY_X_START+50, PLAY_Y_HEIGHT-470,lev);
                    if(choice==2)lev1.setColor(COLOR(144,238,144));
                    //   if(choice==2)liv1.setColor(COLOR(144,238,144));
                    // Text disp(400,300,"");
                    int lvl=0;

                    /*paused = true;
                    rtheta = true;*/

                    double coin_speed = COIN_SPEED;
                    double coin_angle_deg = COIN_ANGLE_DEG;
                    double coin_ax = 0;
                    double coin_ay = COIN_G;
                    Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
                    Coin coin2(coin_speed+10, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
                    Coin bomb(coin_speed+20, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
                    bomb.changetobomb();
                    coin2.throwxout();
                    int lives=5;
                    bool k=0;

                    Text over(400,3000,"");
                    Text lev2(122, 23,"Lives:");
                    if(choice==2) lev2.setColor(COLOR(144,238,144));
                    Circle l1(150,23,5);
                    Circle l2(165,23,5);
                    Circle l3(180,23,5);
                    Circle l4(195,23,5);
                    Circle l5(210,23,5);
                    l1.setColor(COLOR(255,0,0));
                    l2.setColor(COLOR(255,0,0));
                    l3.setColor(COLOR(255,0,0));
                    l4.setColor(COLOR(255,0,0));
                    l5.setColor(COLOR(255,0,0));
                    l1.setFill(true);
                    l2.setFill(true);
                    l3.setFill(true);
                    l4.setFill(true);
                    l5.setFill(true);

                    int stepCount = 0;
                    float stepTime = STEP_TIME;
                    float runTime = -1; // sec; -ve means infinite
                    float currTime = 0;
                    // After every COIN_GAP sec, make the coin jump
                    double last_coin_jump_end = 0;
                    for(;;)
                    {
                        XEvent e;
                        if(lives==0)
                        {
                            flag=1;
                            finalmsg.moveTo(400,300);
                            over.setMessage("Game over buddy :) Press Enter to go back to main menu ");
                            over.moveTo(400,200);
                            if(lasso.getNumCoins()>min_curr_score)update(lasso.getNumCoins());
                            else cout<<"\nScore too low for the leaderboard.Pls try next time \n";

                            nextEvent(e);

                        }
                        if(lives==5)
                        {
                            l5.setFill(false);
                            wait(stepTime);
                            currTime += stepTime;
                            l5.setFill(true);
                        }
                        if(lives==4)
                        {
                            l5.setFill(false);
                            l4.setFill(false);
                            wait(stepTime);
                            currTime += stepTime;
                            l4.setFill(true);
                        }
                        if(lives==3)
                        {
                            l4.setFill(false);
                            l3.setFill(false);
                            wait(stepTime);
                            currTime += stepTime;
                            l3.setFill(true);
                        }
                        if(lives==2)
                        {
                            l3.setFill(false);
                            l2.setFill(false);
                            wait(stepTime);
                            currTime += stepTime;
                            l2.setFill(true);
                        }
                        if(lives==1)
                        {
                            l2.setFill(false);
                            l1.setFill(false);
                            wait(stepTime);
                            currTime += stepTime;
                            l1.setFill(true);
                        }

                        if((runTime > 0) && (currTime > runTime))
                        {
                            break;
                        }
                        lvl=lasso.getLevel();

                        bool pendingEv = checkEvent(e);
                        if(pendingEv)
                        {
                            char c = charFromEvent(e);
                            msg[msg.length()-2] = c;
                            charPressed.setMessage(msg);
                            switch(c)
                            {
                            case 't':
                                lasso.unpause();
                                break;
                            case 'y':

                                lasso.yank();
                                if(lvl%3==0||lvl%3==1)  lasso.isCoinAttatched(&coin,lvl,1);
                                if(lvl%3==2)
                                {
                                    lasso.isCoinAttatched(&coin,lvl,1);
                                    lasso.isCoinAttatched(&coin2,lvl,2);
                                }
                                break;
                            case 'l':
                                lasso.loopit();
                                k=lasso.check_for_bomb(&bomb);
                                if(k)
                                {
                                    lives--;
                                    lasso.yank();
                                    bomb.resetCoin(randomxcord());
                                    if(lvl%3==0)coin.resetCoin(450);
                                    if(lvl%3==1)coin.resetxCoin();
                                    if(lvl%3==2)coin.resetCoin(750);
                                    if(lvl%3==2)coin2.resetCoin(700);
                                    canvas.setColor(COLOR(255,0,0));
                                    wait(2*stepTime);
                                    canvas.setColor(COLOR(144,238,144));
                                    wait(2*stepTime);
                                    canvas.setColor(COLOR(255,255,0));
                                    wait(2*stepTime);
                                    if(choice==1) canvas.setColor(COLOR(0,0,0));
                                    if(choice==2)canvas.setColor(COLOR(144,238,144));
                                    currTime+=6*stepTime;

                                    break;

                                }
                                if(lvl%3==1||lvl%3==0)
                                {
                                    lasso.check_for_coin(&coin);
                                    break;
                                }
                                if(lvl%3==2)
                                {
                                    lasso.check_for_twocoins(&coin,&coin2);
                                    break;
                                }
                                // if(lasso.getLevel()%3==0)coin2.throwxout();
                                //  wait(STEP_TIME*5);
                                break;
                            case '[':
                                if(lasso.isPaused())
                                {
                                    lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);
                                }
                                break;
                            case ']':
                                if(lasso.isPaused())
                                {
                                    lasso.addAngle(+RELEASE_ANGLE_STEP_DEG);
                                }
                                break;
                            case '-':
                                if(lasso.isPaused())
                                {
                                    lasso.addSpeed(-RELEASE_SPEED_STEP);
                                }
                                break;
                            case '=':
                                if(lasso.isPaused())
                                {
                                    lasso.addSpeed(+RELEASE_SPEED_STEP);
                                }
                                break;
                            case 'q':
                                flag=1;
                                finalmsg.moveTo(400,300);
                                over.setMessage("Press Enter to go back to main menu ");
                                over.moveTo(400,200);
                                if(lasso.getNumCoins()>min_curr_score)update(lasso.getNumCoins());
                                else cout<<"\nScore too low for the leaderboard.Pls try next time \n";
                                nextEvent(e);
                                // wait(3);
                                break;
                            // exit(0);
                            default:
                                break;
                            }
                        }



                        if(lasso.getYPos() > PLAY_Y_HEIGHT)
                        {
                            lives--;
                            lasso.yank();
                        }
                        beginFrame();
                        lasso.nextStep(stepTime);
                        bomb.nextStep(stepTime);
                        coin.nextStep(stepTime);
                        if(lvl%3==2) coin2.nextStep(stepTime);
                        endFrame();

                        if(coin.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >=0)
                            {
                                coin.unpause();
                            }
                        }
                        if(lvl%3!=2)
                        {
                            coin2.throwxout();
                        }
                        if(coin2.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= COIN_GAP-0.5)
                            {
                                if(lvl%3==2)coin2.bringxin();
                                if(lvl%3==2)coin2.unpause();
                            }
                        }
                        if(bomb.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= 0)
                            {
                                bomb.unpause();
                            }
                        }

                        if(coin.getYPos() > PLAY_Y_HEIGHT)
                        {
                            if(lvl%3==0)coin.resetCoin(450);
                            if(lvl%3==1)coin.resetxCoin();
                            if(lvl%3==2)coin.resetCoin(750);
                            last_coin_jump_end = currTime;

                        }
                        if(coin2.getYPos() > PLAY_Y_HEIGHT)
                        {
                            if(lvl%3==2)
                            {
                                coin2.resetCoin(700);
                            }
                            last_coin_jump_end = currTime;
                        }
                        if(bomb.getYPos() > PLAY_Y_HEIGHT)
                        {
                            bomb.resetCoin(randomxcord());
                            last_coin_jump_end = currTime;
                        }

                        sprintf(coinScoreStr, "Score: %d ", lasso.getNumCoins());
                        coinScore.setMessage(coinScoreStr);
                        sprintf(liv,"Lives: %d ",lives);
                        sprintf(tym,"Timer: %d",time);
                        tyme.setMessage(tym);
                        sprintf(lev,"Level: %d ",lasso.getLevel());
                        lev1.setMessage(lev);
                        stepCount++;
                        double time_=2.5254*currTime;
                        time=150-time_;
                        if(time%9==0)bomb.resetCoin(randomxcord());
                        if(time==-1)
                        {
                            flag=1;
                            finalmsg.moveTo(400,300);
                            over.setMessage("Time over buddy :) Press Enter to go back to main menu ");
                            over.moveTo(400,200);
                            if(lasso.getNumCoins()>min_curr_score)update(lasso.getNumCoins());
                            else cout<<"\nScore too low for the leaderboard.Pls try next time \n";
                            nextEvent(e);
                        }
                        if(flag==1)break;
                    } // End for(;;)
                }
                if(flag==1)break;
            }
        }//coin game over


        else if(choice==2) //number game
        {

            int scr[3];
            string name[3];
            cout<<"**Initial leaderboard**\n";
            displaynum(scr,name);
            int min_curr_score=minscorenum();
            while(true)
            {
                bool flag=0;
                Rectangle canvas1(400,300,800,600);
                canvas1.setColor(COLOR(255,255,255));
                canvas1.setFill(true);
                Text coingame(400,280,"Dark Mode");
                Text numbergame(400,310,"Light Mode");
                Rectangle r1(400,280,textWidth("Dark Mode")+4, 20);
                Rectangle r2(400,310,textWidth("Light Mode")+4,20);
                int w=getClick();
                int x=w/65536, y=w%65536;
                int choice;
                if(270<=y&&y<=290&&(400-0.5*(textWidth("Dark Mode")+4))<=x&&x<=(400+0.5*(textWidth("Dark Mode")+4)))choice=1;
                else if(300<=y&&y<=320&&(400-0.5*(textWidth("Dark Mode")+4))<=x&&x<=(400+0.5*(textWidth("Light Mode")+4)))choice=2;
                else choice =3;
                if(choice==3)
                {
                    Text warn(x,y," Click! on a button :) ");
                    wait(0.5);
                }
                else
                {
                    Rectangle canvas(400,300,800,600); //creates rectangle of canvas size to color it
                    if(choice==2)  canvas.setColor(COLOR(144,238,144));
                    canvas.setFill(true);


                    Text control(740,20,"CONTROLS ");
                    Text t(740,40,"T - throw lasso ");
                    Text y(740,60,"Y - yank lasso ");
                    Text l(740,80,"L - loop lasso ");
                    Text q(740,100,"Q - exit :-(   ");
                    Text over(4000,2000,"GAME OVER!PLS TRY AGAIN");
                    Text finalmsg(4000,3000,"Hey!Also check the terminal");
                    if(choice==2)  control.setColor(COLOR(144,238,144));
                    if(choice==2) t.setColor(COLOR(144,238,144));
                    if(choice==2) y.setColor(COLOR(144,238,144));
                    if(choice==2)l.setColor(COLOR(144,238,144));
                    if(choice==2) q.setColor(COLOR(144,238,144));

                    //Text more(740,120,"check comments for more");
                    Rectangle cont(740,60,100,98);
                    char eqn[256];//use to display eqn
                    char tym[256];
                    // Draw lasso at start position
                    double release_speed = INIT_RELEASE_SPEED; // m/s
                    double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
                    double lasso_ax = 0;
                    double lasso_ay = LASSO_G;
                    bool paused = true;
                    bool rtheta = true;
                    Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
                    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
                    b1.setColor(COLOR("blue"));
                    Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
                    b2.setColor(COLOR("blue"));

                    string msg("Cmd :   ");
                    Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
                    char coinScoreStr[256];
                    if(choice==2) charPressed.setColor(COLOR(144,238,144));
                    sprintf(coinScoreStr, "Score: %d ", lasso.getNumCoins());
                    Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);
                    if(choice==2) coinScore.setColor(COLOR(144,238,144));


                    Text eqn1(400,50,eqn);

                    int arr[4],brr[4],wrans[4],correctind;
                    string equn;
                    resetnumgame(arr,equn,wrans,brr,correctind);

                    eqn1.setMessage(equn);

                    double num_speed = COIN_SPEED;
                    double num_angle_deg = COIN_ANGLE_DEG;
                    double num_ax = 0;
                    double num_ay = COIN_G;
                    Num num1(num_speed, num_angle_deg-10, num_ax, num_ay, paused, rtheta);
                    Num num2(num_speed, num_angle_deg+10, num_ax, num_ay, paused, rtheta);
                    Num num3(num_speed, num_angle_deg-10, num_ax, num_ay, paused, rtheta);
                    Num num4(num_speed, num_angle_deg+10, num_ax, num_ay, paused, rtheta);
                    char n1[20],n2[20],n3[20],n4[20];
                    string ncorekt;
                    resetoptions(n1,n2,n3,n4,ncorekt,wrans,brr,correctind);
                    num1.initNum(n1,310);
                    num2.initNum(n2,460);
                    num3.initNum(n3,610);
                    num4.initNum(n4,760);

                    bool bo1=0,bo2=0,bo3=0,bo4=0;
                    string s1,s2,s3,s4;

                    int score=0;
                    int lives=5;
                    // Text radius(132,61,rad);
                    // if(choice==2) radius.setColor(COLOR(144,238,144));
                    Text timer(132,42,tym);
                    Text lev1(122, 23,"Lives:");
                    if(choice==2) lev1.setColor(COLOR(144,238,144));
                    if(choice==2) timer.setColor(COLOR(144,238,144));
                    Circle l1(150,23,5);
                    Circle l2(165,23,5);
                    Circle l3(180,23,5);
                    Circle l4(195,23,5);
                    Circle l5(210,23,5);
                    l1.setColor(COLOR(255,0,0));
                    l2.setColor(COLOR(255,0,0));
                    l3.setColor(COLOR(255,0,0));
                    l4.setColor(COLOR(255,0,0));
                    l5.setColor(COLOR(255,0,0));
                    l1.setFill(true);
                    l2.setFill(true);
                    l3.setFill(true);
                    l4.setFill(true);
                    l5.setFill(true);
                    // int k=0;
                    int time=90;
                    int stepCount = 0;
                    float stepTime = STEP_TIME;
                    float runTime = -1; // sec; -ve means infinite
                    float currTime = 0;

                    // After every COIN_GAP sec, make the coin jump
                    double last_coin_jump_end = 0;
                    for(;;)
                    {
                        XEvent e;
                        if(lives==0)
                        {
                            flag=1;
                            finalmsg.moveTo(400,300);
                            over.setMessage("Game over buddy :) Press Enter to go back to main menu");
                            over.moveTo(400,200);
                            if(score>min_curr_score)updatenum(score);
                            else cout<<"\nScore too low for the leaderboard.Pls try next time \n";
                            nextEvent(e);
                        }
                        if(lives==5)
                        {
                            l5.setFill(false);
                            wait(stepTime);
                            currTime+=stepTime;
                            l5.setFill(true);
                        }
                        if(lives==4)
                        {
                            l5.setFill(false);
                            l4.setFill(false);
                            wait(stepTime);
                            currTime+=stepTime;
                            l4.setFill(true);
                        }
                        if(lives==3)
                        {
                            l4.setFill(false);
                            l3.setFill(false);
                            wait(stepTime);
                            currTime+=stepTime;
                            l3.setFill(true);
                        }
                        if(lives==2)
                        {
                            l3.setFill(false);
                            l2.setFill(false);
                            currTime+=stepTime;
                            wait(stepTime);
                            l2.setFill(true);
                        }
                        if(lives==1)
                        {
                            l2.setFill(false);
                            l1.setFill(false);
                            wait(stepTime);
                            currTime+=stepTime;
                            l1.setFill(true);
                        }

                        if((runTime > 0) && (currTime > runTime))
                        {
                            break;
                        }


                        char c;
                        bool pendingEv = checkEvent(e);
                        if(pendingEv)
                        {
                            c = charFromEvent(e);
                            msg[msg.length()-2] = c;
                            charPressed.setMessage(msg);
                            switch(c)
                            {
                            case 't':
                                lasso.unpause();
                                break;
                            case 'y':
                                lasso.yank();
                                bo1=lasso.isNumAttatched(1);
                                bo2=lasso.isNumAttatched(2);
                                bo3=lasso.isNumAttatched(3);
                                bo4=lasso.isNumAttatched(4);
                                if(bo1||bo2||bo3||bo4)
                                {
                                    resetnumgame(arr,equn,wrans,brr,correctind);
                                    eqn1.setMessage(equn);
                                    resetoptions(n1,n2,n3,n4,ncorekt,wrans,brr,correctind);
                                    num1.resetxnum(n1,310,num_speed,num_angle_deg-10);
                                    num2.resetxnum(n2,460,num_speed,num_angle_deg+10);
                                    num3.resetxnum(n3,610,num_speed,num_angle_deg-10);
                                    num4.resetxnum(n4,760,num_speed,num_angle_deg+10);
                                }



                                break;
                            case 'l'://  correct answer in string ncorekt
                                lasso.loopit();
                                bo1=lasso.check_for_num(&num1,1);
                                s1=num1.getnum();
                                if(bo1)
                                {
                                    if(s1==ncorekt)
                                    {
                                        score++;
                                    }
                                    else lives--;
                                    break;
                                }
                                bo2= lasso.check_for_num(&num2,2);
                                s2=num2.getnum();
                                if(bo2)
                                {
                                    if(s2==ncorekt)score++;
                                    else lives--;
                                    break;

                                }
                                bo3=  lasso.check_for_num(&num3,3);
                                s3=num3.getnum();
                                if(bo3)
                                {
                                    if(s3==ncorekt)score++;
                                    else lives--;
                                    break;
                                }
                                bo4= lasso.check_for_num(&num4,4);
                                s4=num4.getnum();
                                if(bo4)
                                {
                                    if(s4==ncorekt)score++;
                                    else lives--;
                                    break;

                                }


                                // wait(STEP_TIME*5);
                                break;
                            case '[':
                                if(lasso.isPaused())
                                {
                                    lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);
                                }
                                break;
                            case ']':
                                if(lasso.isPaused())
                                {
                                    lasso.addAngle(+RELEASE_ANGLE_STEP_DEG);
                                }
                                break;
                            case '-':
                                if(lasso.isPaused())
                                {
                                    lasso.addSpeed(-RELEASE_SPEED_STEP);
                                }
                                break;
                            case '=':
                                if(lasso.isPaused())
                                {
                                    lasso.addSpeed(+RELEASE_SPEED_STEP);
                                }
                                break;
                            case 'q':
                                flag=1;
                                finalmsg.moveTo(400,300);
                                over.setMessage("Press Enter to go back to main menu");
                                over.moveTo(400,200);
                                if(score>min_curr_score)updatenum(score);
                                else cout<<"\nScore too low for the leaderboard.Pls try next time \n";
                                // wait(3);

                                nextEvent(e);
                                c='w';
                                break;

                            //exit(0);
                            default:
                                break;
                            }
                        }
                        if(flag==1)break;



                        if(lasso.getYPos() > PLAY_Y_HEIGHT)
                        {
                            lasso.yank();
                            lives--;
                            resetnumgame(arr,equn,wrans,brr,correctind);
                            eqn1.setMessage(equn);
                            resetoptions(n1,n2,n3,n4,ncorekt,wrans,brr,correctind);
                            num1.resetxnum(n1,310,num_speed,num_angle_deg-10);
                            num2.resetxnum(n2,460,num_speed,num_angle_deg+10);
                            num3.resetxnum(n3,610,num_speed,num_angle_deg-10);
                            num4.resetxnum(n4,760,num_speed,num_angle_deg+10);
                            //  resetnumgame();
                        }
                        beginFrame();
                        lasso.nextStep(stepTime);
                        num1.nextStep(stepTime);
                        num2.nextStep(stepTime);
                        num3.nextStep(stepTime);
                        num4.nextStep(stepTime);
                        endFrame();
                        if(num1.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= 0.05)
                            {

                                num1.setx(310);
                                num1.unpause();
                            }
                        }
                        if(num2.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= 0.05)
                            {
                                num2.setx(460);
                                num2.unpause();
                            }
                        }
                        if(num3.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= 0.05)
                            {
                                num3.setx(610);
                                num3.unpause();
                            }
                        }
                        if(num4.isPaused())
                        {
                            if((currTime-last_coin_jump_end) >= 0.05)
                            {
                                num4.setx(760);
                                num4.unpause();
                            }
                        }


                        if(num1.getYPos() > PLAY_Y_HEIGHT)
                        {
                            num1.resetNum(310,num_angle_deg-10);
                            last_coin_jump_end = currTime;

                        }
                        if(num2.getYPos() > PLAY_Y_HEIGHT)
                        {
                            num2.resetNum(460,num_angle_deg+10);
                            last_coin_jump_end = currTime;
                        }
                        if(num3.getYPos() > PLAY_Y_HEIGHT)
                        {
                            num3.resetNum(610,num_angle_deg-10);
                            last_coin_jump_end = currTime;
                        }
                        if(num4.getYPos() > PLAY_Y_HEIGHT)
                        {
                            num4.resetNum(760,num_angle_deg+10);
                            last_coin_jump_end = currTime;
                        }
                        sprintf(tym,"Timer: %d ",time);
                        sprintf(coinScoreStr, "Score: %d ", score);
                        coinScore.setMessage(coinScoreStr);
                        timer.setMessage(tym);
                        stepCount++;
                        double time_=2.1818*currTime;
                        time=150-time_;
                        if(time==-1)
                        {
                            flag=1;
                            finalmsg.moveTo(400,300);
                            over.setMessage("Time over buddy :) Press Enter to go back to main menu");
                            over.moveTo(400,200);
                            if(score>min_curr_score)updatenum(score);
                            else cout<<"\nScore too low for the leaderboard.Pls try next time \n";
                            nextEvent(e);
                        }

                    } // End for(;;)
                    if(flag==1)break;

                }
            }


        }
    }

    wait(3);
    return 0;

} // End main_program
