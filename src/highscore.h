#include<fstream>

void display(int scr[],string name[])
{
    ifstream file("scores.txt");
    for(int i=0; i<3; i++)
    {
        file>>scr[i];
    }
    file.close();
    ifstream obj("playername.txt");
    for(int i=0; i<3; i++)
    {
        obj>>name[i];
    }
    cout<<"rank"<<"      "<<"score"<<"      "<<"name\n";
    for(int i=2; i>=0; i--)
        cout<<3-i<<"         "<<scr[i]<<"        "<<name[i]<<endl;
}
void displaynum(int scr[],string name[])
{
    ifstream file("scoresnum.txt");
    for(int i=0; i<3; i++)
    {
        file>>scr[i];
    }
    file.close();
    ifstream obj("playernamenum.txt");
    for(int i=0; i<3; i++)
    {
        obj>>name[i];
    }
    cout<<"rank"<<"      "<<"score"<<"      "<<"name\n";
    for(int i=2; i>=0; i--)
        cout<<3-i<<"         "<<scr[i]<<"        "<<name[i]<<endl;
}
int minscore()
{
    int scr[3];
    ifstream file("scores.txt");
    for(int i=0; i<3; i++)
    {
        file>>scr[i];
    }
    sort(scr,scr+3);
    return scr[0];
}
int minscorenum()
{
    int scr[3];
    ifstream file("scoresnum.txt");
    for(int i=0; i<3; i++)
    {
        file>>scr[i];
    }
    sort(scr,scr+3);
    return scr[0];
}
void update(int newscr)
{
    cout<<"\nBang!U r a top scorer. Pls enter ur name-\n";
    string s;
    cin>>s;
    int scr[3];
    ifstream file("scores.txt");
    for(int i=0; i<3; i++)
        file>>scr[i];
    file.close();
    string name[3];
    ifstream obj("playername.txt");
    string k;
    for(int i=0; i<3; i++)
        obj>>name[i];
    obj.close();

    int i;
    for(i=1; i<3; i++)
    {
        if(scr[i]>=newscr)
            break;
    }
    if(i==3)
    {
        scr[0]=scr[1];
        scr[1]=scr[2];
        scr[2]=newscr;
        name[0]=name[1];
        name[1]=name[2];
        name[2]=s;
    }
    else if(i==2)
    {
        scr[0]=scr[1];
        scr[1]=newscr;
        name[0]=name[1];
        name[1]=s;
    }
    else if(i==1)
    {
        scr[0]=newscr;
        name[0]=s;
    }
    ofstream obj1("scores.txt");
    for(int i=0; i<3; i++)
        obj1<<scr[i]<<endl;
    obj1.close();
    ofstream obj2("playername.txt");
    for(int i=0; i<3; i++)
        obj2<<name[i]<<endl;
    obj2.close();
    cout<<"**New Leaderboard**\n";
    display(scr,name );
}
void updatenum(int newscr)
{
    cout<<"\nBang!U r a top scorer. Pls enter ur name-\n";
    string s;
    cin>>s;
    int scr[3];
    ifstream file("scoresnum.txt");
    for(int i=0; i<3; i++)
        file>>scr[i];
    file.close();
    string name[3];
    ifstream obj("playernamenum.txt");
    string k;
    for(int i=0; i<3; i++)
        obj>>name[i];

    obj.close();

    int i;
    for(i=1; i<3; i++)
    {
        if(scr[i]>=newscr)
            break;
    }
    if(i==3)
    {
        scr[0]=scr[1];
        scr[1]=scr[2];
        scr[2]=newscr;
        name[0]=name[1];
        name[1]=name[2];
        name[2]=s;
    }
    else if(i==2)
    {
        scr[0]=scr[1];
        scr[1]=newscr;
        name[0]=name[1];
        name[1]=s;
    }
    else if(i==1)
    {
        scr[0]=newscr;
        name[0]=s;
    }
    ofstream obj1("scoresnum.txt");
    for(int i=0; i<3; i++)
        obj1<<scr[i]<<endl;
    obj1.close();
    ofstream obj2("playernamenum.txt");
    for(int i=0; i<3; i++)
        obj2<<name[i]<<endl;
    obj2.close();
    cout<<"**New Leaderboard**\n";
    displaynum(scr,name );
}

