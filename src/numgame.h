void randomnum(int arr[],int maxn,int n)
{
    int i,j;
    std::srand(time(0));
    for( i=0; i<n; i++)
    {
        int temp=rand()%maxn+1;
        for( j=0; j<=i-1; j++)
        {
            if(temp==arr[j])break;
        }
        if(j==i)arr[i]=temp;
        else i--;
    }
}
int randomxcord()
{
    std::srand(time(0));
    int temp=rand()%400+370;
    return temp;
}

void resetnumgame(int arr[],string &equn,int wrans[],int brr[],int &correctind)
{
    randomnum(arr,20,4);
    int ans=arr[0]*arr[1]+arr[2]*arr[3];
    char a1[20],a2[20],a3[20],a4[20];
    sprintf(a1,"%d",arr[0]);
    sprintf(a2,"%d",arr[1]);
    sprintf(a3,"%d",arr[2]);
    sprintf(a4,"%d",arr[3]);
    string x="x";
    string pls="+";
    equn=a1+x+a2+pls+a3+x+a4;
    randomnum(wrans,ans-1,4);
    wrans[3]=ans;
    randomnum(brr,4,4);
    for(int i=0; i<4; i++)
    {
        brr[i]-=1;
        if(brr[i]==3)correctind=i;
    }
}

void resetoptions(char n1[],char n2[],char n3[],char n4[],string &ncorekt,int wrans[],int brr[],int correctind)
{
    char ncorr[20];
    sprintf(n1,"%d",wrans[brr[0]]);
    sprintf(n2,"%d",wrans[brr[1]]);
    sprintf(n3,"%d",wrans[brr[2]]);
    sprintf(n4,"%d",wrans[brr[3]]);
    sprintf(ncorr,"%d",wrans[brr[correctind]]);
    string vo="";
    ncorekt=ncorr+vo;
}
