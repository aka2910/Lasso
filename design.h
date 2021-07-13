
void squarepinski(double s, double t, Turtle t1)
{
    if(s < t)return;
    double delta = s / 3;
    squarepinski(s/3, t,t1);
    t1.penUp();
    t1.forward(delta);
    t1.left(90);
    t1.forward(delta);
    t1.right(90);
    t1.penDown();

    squarepinski(s/3, t,t1);

    t1.penUp();
    t1.left(180);
    t1.forward(2 * delta);
    t1.right(180);
    t1.penDown();

    squarepinski(s/3, t,t1);

    t1.penUp();
    t1.right(90);
    t1.forward(2 * delta);
    t1.left(90);
    t1.penDown();

    squarepinski(s/3, t,t1);

    t1.penUp();
    t1.forward(2 * delta);
    t1.penDown();

    squarepinski(s/3, t,t1);

    t1.penUp();
    t1.left(90);
    t1.forward(delta);
    t1.left(90);
    t1.forward(delta);
    t1.left(180);

    t1.left(90);
    t1.forward(s/2);
    t1.right(90);
    t1.penDown();

    t1.forward(s/2);
    t1.right(90);
    t1.forward(s);
    t1.right(90);
    t1.forward(s);
    t1.right(90);
    t1.forward(s);
    t1.right(90);
    t1.forward(s/2);

    t1.penUp();
    t1.right(90);
    t1.forward(s/2);
    t1.left(90);
    t1.penDown();
}
void sierpinski(double s, double t,Turtle t1)
{
    double l = (s * sqrt(3)) / 8;
    l = (s / (sqrt(3) * 2));
    if(s >= t)
    {
        t1.penUp();
        t1.left(90);
        t1.forward(l);
        t1.right(90);
        t1.penDown();

        sierpinski(s/2, t,t1);

        t1.penUp();
        t1.right(90);
        t1.forward(l);
        t1.left(90);

        t1.right(30);
        t1.forward(l);
        t1.left(30);
        t1.penDown();

        sierpinski(s/2, t,t1);

        t1.penUp();
        t1.left(150);
        t1.forward(l);
        t1.right(150);
        t1.right(150);
        t1.forward(l);
        t1.left(150);
        t1.penDown();

        sierpinski(s/2, t,t1);

        t1.penUp();
        t1.left(30);
        t1.forward(l);
        t1.right(30);
    }

    t1.penUp();
    t1.left(90);
    t1.forward(2 * l);
    t1.right(90);

    t1.penDown();
    t1.right(60);
    t1.forward(s);
    t1.right(120);
    t1.forward(s);
    t1.right(120);
    t1.forward(s);
    t1.right(120);
    t1.left(60);


    t1.penUp();
    t1.right(90);
    t1.forward(2 * l);
    t1.left(90);
    t1.penDown();
}
void drawdesign()
{
    Turtle T1;
    //T1.hide();
    T1.penUp();
    T1.moveTo(700,100);
    T1.penDown();
    beginFrame();
    squarepinski(150,2,T1);
    endFrame();
    T1.penUp();
    T1.moveTo(150,500);
    T1.penDown();
    beginFrame();
    sierpinski(200, 20,T1);
    T1.hide();
    endFrame();
}

