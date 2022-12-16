#include <conio.h>
#include <vector>
#include <graphics.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int lenght = 1;
int lenghtmax = 2; 

int x1 = 30;
int y = 170; 

char direc = '-';
char last = '-';
int l=2;
bool playing = true; 

int fruitx;
int fruity;

bool eaten = false;
 

vector<int> snakex;
vector<int> snakey; 
int SnakeColor=15;

int i = 1;
int imax = 0; 

char score[50];
int score1; 
int speed_control=0;

void fruit();
void graphic();
void move();
void start();
void update(); 

class dfruit{
public:
    bool beaten = false;
    int bfruitx;
    int bfruity;
    void bfruit();
};
dfruit bf[20];

void start()
{
    sprintf(score, "SCORE : %d ", score1);

    srand(time(NULL));
    initwindow(350, 354, "Snake");

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 0, 340, 10);
    floodfill(5, 5, GREEN);

    setcolor(WHITE);
    outtextxy(10, 0, score);

    fruitx = rand() % 34;
    fruity = rand() % 34;
    fruity = fruity * 10;
    fruitx = fruitx * 10;
    
    if(fruity == 0){
        fruity = fruity+10;
    }
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 10, fruity + 10);
    floodfill(fruitx + 5, fruity + 5, RED);

    bf[1].bfruitx = rand() % 34;
    bf[1].bfruity = rand() % 34;
    bf[1].bfruity = bf[1].bfruity * 10;
    bf[1].bfruitx = bf[1].bfruitx * 10;
    
    if(bf[1].bfruity == 0){
        bf[1].bfruity = bf[1].bfruity+10;
    }
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    rectangle(bf[1].bfruitx, bf[1].bfruity, bf[1].bfruitx + 10, bf[1].bfruity + 10);
    floodfill(bf[1].bfruitx + 5, bf[1].bfruity + 5, CYAN);
    

}

void update() 
{   

    sprintf(score, "SCORE : %d ", score1);
    if (speed_control<50)
    {
        speed_control=score1*2;
    }
    
    Sleep(80-speed_control);
    snakex.push_back(x1);
    snakey.push_back(y); 
    fruit();
    while (l<10){
        bf[l];
        l++;
    }
    move();
    graphic();

}

void move() 
{
    if (kbhit())    direc = getch();

    if (direc == 'w' && last == 's' || direc == 'W' && last == 'S' || direc == 38 && last == 40) direc = last;

    if (direc == 'a' && last == 'd' || direc == 'A' && last == 'D' || direc == 37 && last == 39) direc = last;

    if (direc == 's' && last == 'w' || direc == 'S' && last == 'W' || direc == 40 && last == 38 ) direc = last;

    if (direc == 'd' && last == 'a' || direc == 'D' && last == 'A' || direc == 39 && last == 37) direc = last;

    last = direc;

    if (direc == 's' || direc == 'S' || direc == 40)   y = y + 10;
    if (direc == 'a' || direc == 'A' || direc == 37)   x1 = x1 - 10;
    if (direc == 'w' || direc == 'W' || direc == 38)   y = y - 10;
    if (direc == 'd' || direc == 'D' || direc == 39)   x1 = x1 + 10;
}

void graphic() 
{
    cleardevice();

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(0, 0, 350, 10);			
    floodfill(5, 5, BLUE);

    setcolor(WHITE);
    outtextxy(10, 0, score); 

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 10, fruity + 10); 
    floodfill(fruitx + 5, fruity + 5, RED);

    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    rectangle(bf[1].bfruitx, bf[1].bfruity, bf[1].bfruitx + 10, bf[1].bfruity + 10); 
    floodfill(bf[1].bfruitx + 5, bf[1].bfruity + 5, CYAN);
    
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x1, y, x1 + 10, y + 10); 
    floodfill(x1 + 5, y + 5, WHITE);


    for (int lenght = lenghtmax; lenght > 0; lenght--)
    {
        setcolor(SnakeColor);
        setfillstyle(SOLID_FILL, SnakeColor);
        rectangle(snakex[i], snakey[i], snakex[i] + 10, snakey[i] + 10); 
        floodfill(snakex[i] + 5, snakey[i] + 5, SnakeColor);
        i--;
    }

    imax++;
    i = imax;

}

void restart()
{
  // Reset all relevant variables to their initial values
  lenght = 1;
  lenghtmax = 2;
  x1 = 30;
  y = 170;
  direc = '-';
  last = '-';
  playing = true;
  fruitx = 0;
  fruity = 0;
  bf[1].bfruitx = 0;
  bf[1].bfruity = 0;
  eaten = false;
  snakex.clear();
  snakey.clear();
  SnakeColor = 15;
  i = 1;
  imax = 0;
  score1 = 0;
  sprintf(score, "SCORE : %d ", score1);
  

  fruitx = rand() % 34;
  fruity = rand() % 34;
  fruity = fruity * 10;
  fruitx = fruitx * 10;
  
  if(fruity == 0)
  {
    fruity = fruity + 10;
  }
  
  bf[1].bfruitx = rand() % 34;
  bf[1].bfruity = rand() % 34;
  bf[1].bfruity = bf[1].bfruity * 10;
  bf[1].bfruitx = bf[1].bfruitx * 10;
  
  if(bf[1].bfruity == 0)
  {
    bf[1].bfruity = bf[1].bfruity + 10;
  }
}


void fruit() 
{
    if (x1 == fruitx && y == fruity)
    eaten = true;

    if (eaten == true)
    {
        eaten = false;
        lenghtmax++;
        score1++;
        lenght = lenghtmax;
        fruitx = rand() % 34;
        fruity = rand() % 34;
        fruity = fruity * 10;
        fruitx = fruitx * 10; 
        SnakeColor = rand() % 15 + 1;

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (fruitx == snakex[i] && fruity == snakey[i])
            {
                fruitx = rand() % 34;
                fruity = rand() % 34;
                fruity = fruity * 10;
                fruitx = fruitx * 10; 
            }

            i--;
        }

        if (fruity == 0)
        {
            fruity = 10;
        }

        i = imax;

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        rectangle(fruitx, fruity, fruitx + 10, fruity + 10); 
        floodfill(fruitx + 5, fruitx + 5, RED);
    }
}
void dfruit :: bfruit() 
{
    if (x1 == bfruitx && y == bfruity)
    beaten = true;

    if (beaten == true)
    {
        beaten = false;
        lenghtmax--;
        score1--;
        lenght = lenghtmax;
        bfruitx = rand() % 34;
        bfruity = rand() % 34;
        bfruity = bfruity * 10;
        bfruitx = bfruitx * 10; 
        SnakeColor = CYAN;

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (bfruitx == snakex[i] && bfruity == snakey[i])
            {
                bfruitx = rand() % 34;
                bfruity = rand() % 34;
                bfruity = bfruity * 10;
                bfruitx = bfruitx * 10; 
            }

            i--;
        }

        if (bfruity == 0)
        {
            bfruity = 10;
        }

        i = imax;

        setcolor(CYAN);
        setfillstyle(SOLID_FILL, CYAN);
        rectangle(bfruitx, bfruity, bfruitx + 10, bfruity + 10); 
        floodfill(bfruitx + 5, bfruitx + 5, CYAN);
    }
}

int main()
{
    start();
    while(true){
        while (playing == true)
        {
            update();

            if (x1 >= 340 || x1 < 0 || y >= 340 || y < 10) 
            {
                playing = false; 
            }

            if (lenghtmax > 3 || direc != '-' && direc != 'w' && direc != 'a' && direc != 's' && direc != 'd' && direc != 'W' && direc != 'A' && direc != 'S' && direc != 'D')
            {
                for (lenght = lenghtmax; lenght >= 0; lenght--)
                {
                    if (x1 == snakex[i] && y == snakey[i])
                    {
                        playing = false; 
                    }

                    i--;
                }

                i = imax;
            }
        }

        if (playing == false)
        {

            cleardevice();
            setcolor(WHITE);
            outtextxy(70, 170, "YOU LOST, FINAL ");
            outtextxy(188, 170, score);
            Sleep(500);
            getch();
            cleardevice();
            outtextxy(80,170,"Press any key to continue");
            Sleep(500);
            char re_start = getch();
            if (re_start) 
                restart();
            
        }
    }
    getch();
    return 0;
}