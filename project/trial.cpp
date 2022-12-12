#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;

int main(){
    int gd=DETECT,gm;
    initgraph(&gd, &gm, (char*)"");
    int x,y;

    while (true)
    {
    cleardevice();
    
    char player = getch();

    if (player == 'w') y-=20;
    if (player == 'a') x-=20;
    if (player == 's') y+=20;
    if (player == 'd') x+=20;

    }
}