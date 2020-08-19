#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;

class Project
{
private:
    string name;
    char ch=219;
    int bet,res,n,money;
public:
     void intro(void);
    void game(void);
};
int main()
{
    Project obj;
    obj.game();
    return 0;
}
void Project::intro(void)
{

    for(int i=0;i<100;i++)
        cout<<"-";
    cout<<endl<<endl;
    cout<<"\t\t Welcome to the Casino Bet Challenge\t\t"<<endl<<endl;
    cout<<"   1.Tell Us How Many Money You Have To Play This Game."<<endl;
    cout<<"   2.Bet Some Of Your Money On One Specific Number."<<endl;
    cout<<"   3.Ten Players Will Be Play At One Time And Each Will Have One Number To Bet."<<endl;
    cout<<"   4.After Rolling The Dice The Player With Winning Number Will Be Awarded All The Money...!"<<endl;
    cout<<"   5.You Can Play Again As Many Time You Want If You Have Money To Bet...!"<<endl;
    cout<<"   6.Minimum Amounts For Your Money And Bet Are 500 And 250 Respectively..."<<endl;
    cout<<"\t\t   Good Luck !!!\t\t";
    cout<<endl<<endl;
    cout<<"   ";
    for(int i=0; i<100; i++)
        cout<<"-";
    cout<<endl<<endl;
}
void Project::game(void)
{
    srand(time(0));
    intro();
    cout<<"  Enter your name: ";
    cin>>name;
    cout<<"  Enter the total amount of money you have for the challenge: ";
    money:
    cin>>money;
    if(money<500)
    {
        cout<<"  You don't have enough money to place the bet..!"<<endl;
        cout<<"  Please enter a valid amount"<<endl;
        goto money;
    }
    again:
    system("cls");
    intro();
    cout<<"  Your current wallet balance is Rs "<<money<<endl;
    cout<<"  Enter the amount of money you want to place on bet: ";
    bet:
    cin>>bet;
    if(bet>money)
    {
        cout<<"  You don't have enough money for this bet..!"<<endl;
        cout<<"  Enter the bet amount again: ";
        goto bet;
    }
    else if(bet<250)
    {
        cout<<"  The bet amount should be Rs 250 or more..!"<<endl;
        cout<<" Please enter the bet amount once again: ";
        goto bet;
    }
    cout<<"  Now its time to choose a number between 1 to 10 : ";
    n:
    cin>>n;
    if(n<1||n>10)
    {
        cout<<"  Please enter a valid number between 1 to 10"<<endl;
        cout<<"  Enter the number once again"<<endl;
        goto n;
    }
    cout<<"Calculating Results..."<<endl;
    ch=219;
    for(int i=0;i<30;i++)
    {
        cout<<ch;
        Sleep(100);
    }

    res=rand()%10+1;

    if(res==n)
    {
        cout<<"   Congratulations..!"<<endl;
        cout<<"   You won "<<bet*10<<" Rupees.."<<endl;
        money=(money-bet)+bet*10;
        cout<<"   Your Updated Wallet balance is: "<<money<<endl;
        cout<<endl;
    }
    else{
        cout<<endl<<endl;
        cout<<"  Oops...!!"<<endl;
        cout<<"  You Lost..!"<<endl;
        cout<<"  The player with number "<<res<<" is the winner"<<endl;
        money=money-bet;
        cout<<"  You lost "<<bet<<" Rupees"<<endl;
        cout<<"  Your Updated Wallet Balance is: "<<money<<endl;
        cout<<endl;
    }
    if(money>250)
    {
        cout<<"  Your money is still enough to join the bet challenge once again"<<endl;
        cout<<"  Press \'Y\' if you are interested or \'N\' if you are not interested: ";
        label:
        ch=getch();
        if(ch=='Y'||ch=='y')
        {
            goto again;
        }
        else if(ch!='N'&& ch!='n')
            goto label;

    }
   else
        cout<<"  You don't have enough money to play again..."<<endl;
        cout<<endl<<endl;
        cout<<"  Thanks for Playing..!"<<endl;
        Sleep(2000);
        cout<<endl<<endl;

}
