#include<iostream>
#include"CricketMatch.h"
int main()
{
    CricketMatch team[2];
    setValues(&team[0], &team[1]);
    system("cls");
    batFirst(team[0]);
    team[0].startInnings();
    system("cls");
    batFirst(team[1]);
    team[1].startInnings();
    system("cls");
    displayWinner(team[0], team[1]);
    displaySummary(team[0], team[1]);
    return 0;
}