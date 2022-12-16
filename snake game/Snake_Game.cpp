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
int hi_score=1;

int x1 = 100;                    //snake spawn
int y = 100; 

char direc = '-';
char last = '-';

bool playing = true; 

int fruitx;
int fruity;

int fruit2x;
int fruit2y;

int bfruitx;
int bfruity;

bool eaten = false;
bool beaten = false; 

vector<int> snakex;
vector<int> snakey;

int SnakeColor=15;

int i = 1;
int imax = 0; 

char score[50];
int score1;
int speed_control=0;

void fruit();
void fruit2();
void bfruit();
void graphic();
void move();
void start();
void update(); 

void start()
{
    sprintf(score, "SCORE : %d ", score1);

    srand(time(NULL));
    initwindow(2*350, 2*354, "Snake");

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 0, 2*340, 2*10);
    floodfill(2*5, 2*5, GREEN);

    setcolor(WHITE);
    outtextxy(2*10, 0, score);

    fruitx = rand() % 13;
    fruity = rand() % 13;
    fruity = fruity * 20;
    fruitx = fruitx * 20;
    
    if(fruity == 0){
        fruity = fruity+20;
    }
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 20, fruity + 20);
    floodfill(fruitx + 5, fruity + 5, RED);

    fruit2x = rand() % 13;
    fruit2y = rand() % 13;
    fruit2y = fruit2y * 20;
    fruit2x = fruit2x * 20;
    
    if(fruit2y == 0){
        fruit2y = fruit2y+20;
    }

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruit2x, fruit2y, fruit2x + 20, fruit2y + 20);
    floodfill(fruit2x + 5, fruit2y + 5, RED);

    
    
    bfruitx = rand() % 13;
    bfruity = rand() % 13;
    bfruity = bfruity * 20;
    bfruitx = bfruitx * 20;
    
    if(bfruity == 0){
        bfruity = bfruity+20;
    }
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(bfruitx, bfruity, bfruitx + 20, bfruity + 20);
    floodfill(bfruitx + 5, bfruity + 5, RED);
    

}

void update() 
{
    sprintf(score, "SCORE : %d ", score1);

    if (speed_control<70)
    {
        speed_control=hi_score*3;
        if (score1>=hi_score){
            hi_score=score1;
        }
    }
    
    Sleep(80-speed_control);
    snakex.push_back(x1);
    snakey.push_back(y); 
    fruit();
    fruit2();
    bfruit();
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

    if (direc == 's' || direc == 'S' || direc == 40)   y = y + 20;
    if (direc == 'a' || direc == 'A' || direc == 37)   x1 = x1 - 20;
    if (direc == 'w' || direc == 'W' || direc == 38)   y = y - 20;
    if (direc == 'd' || direc == 'D' || direc == 39)   x1 = x1 + 20;
}

void graphic() 
{
    cleardevice();

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(0, 0, 700, 20);			
    floodfill(5, 5, BLUE);

    setcolor(WHITE);
    outtextxy(20, 0, score); 

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 20, fruity + 20); 
    floodfill(fruitx + 5, fruity + 5, RED);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(bfruitx, bfruity, bfruitx + 20, bfruity + 20); 
    floodfill(bfruitx + 5, bfruity + 5, RED);
    
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x1, y, x1 + 20, y + 20); 
    floodfill(x1 + 5, y + 5, WHITE);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruit2x, fruit2y, fruit2x + 20, fruit2y + 20);
    floodfill(fruit2x + 5, fruit2y + 5, RED);


    for (int lenght = lenghtmax; lenght > 0; lenght--)
    {
        setcolor(SnakeColor);
        setfillstyle(SOLID_FILL, SnakeColor);
        rectangle(snakex[i], snakey[i], snakex[i] + 20, snakey[i] + 20); 
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
  int hi_score=1;
  x1 = 100;
  y = 100;
  direc = '-';
  last = '-';
  playing = true;
  fruitx = 0;
  fruity = 0;
  bfruitx = 0;
  bfruity = 0;
  eaten = false;
  beaten = false;
  snakex.clear();
  snakey.clear();
  SnakeColor = 15;
  i = 1;
  imax = 0;
  score1 = 0;
  sprintf(score, "SCORE : %d ", score1);
  

  fruitx = rand() % 13;
  fruity = rand() % 13;
  fruity = fruity * 20;
  fruitx = fruitx * 20;
  
  if(fruity == 0)
  {
    fruity = fruity + 20;
  }
  
  bfruitx = rand() % 13;
  bfruity = rand() % 13;
  bfruity = bfruity * 20;
  bfruitx = bfruitx * 20;
  
  if(bfruity == 0)
  {
    bfruity = bfruity + 20;
  }

    fruit2x = rand() % 13;
    fruit2y = rand() % 13;
    fruit2y = fruit2y * 20;
    fruit2x = fruit2x * 20;
    
    if(fruit2y == 0){
        fruit2y = fruit2y+20;
    }
    
}

void respawn(){
    
        fruitx = rand() % 26;
        fruity = rand() % 26;
        fruity = fruity * 20;
        fruitx = fruitx * 20; 
        SnakeColor = rand() % 15 + 1;

        if (fruity == 0)
        {
            fruity = 2*10;
        }

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        rectangle(fruitx, fruity, fruitx + 20, fruity + 20); 
        floodfill(fruitx + 5, fruitx + 5, RED);

        bfruitx = rand() % 26;
        bfruity = rand() % 26;
        bfruity = bfruity * 20;
        bfruitx = bfruitx * 20;

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        rectangle(bfruitx, bfruity, bfruitx + 20, bfruity + 20); 
        floodfill(bfruitx + 5, bfruitx + 5, RED);

        if (bfruity == 0)
        {
            bfruity = 20;
        }

        fruit2x = rand() % 26;
        fruit2y = rand() % 26;
        fruit2y = fruit2y * 20;
        fruit2x = fruit2x * 20;
    
    if(fruit2y == 0){
        fruit2y = fruit2y+20;
    }
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruit2x, fruit2y, fruit2x + 20, fruit2y + 20);
    floodfill(fruit2x + 5, fruit2y + 5, RED);
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
        
        respawn();

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (fruitx == snakex[i] && fruity == snakey[i])
            {
                fruitx = rand() % 13;
                fruity = rand() % 13;
                fruity = fruity * 20;
                fruitx = fruitx * 20; 
            }

            i--;
        }

        i = imax;
    }
}

void fruit2() 
{
    if (x1 == fruit2x && y == fruit2y)
    eaten = true;

    if (eaten == true)
    {
        eaten = false;
        lenghtmax++;
        score1++;
        lenght = lenghtmax;
        
        respawn();

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (fruit2x == snakex[i] && fruit2y == snakey[i])
            {
                fruit2x = rand() % 13;
                fruit2y = rand() % 13;
                fruit2y = fruit2y * 20;
                fruit2x = fruit2x * 20; 
            }

            i--;
        }

        i = imax;
    }
}

void bfruit() 
{
    if (x1 == bfruitx && y == bfruity)
    beaten = true;

    if (beaten == true)
    {
        beaten = false;
        lenghtmax++;
        score1--;
        lenght = lenghtmax;
        respawn();

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (bfruitx == snakex[i] && bfruity == snakey[i])
            {
                bfruitx = rand() % 13;
                bfruity = rand() % 13;
                bfruity = bfruity * 20;
                bfruitx = bfruitx * 20; 
            }

            i--;
        }

        i = imax;
    }
}

int main()
{
    start();
    while(true){
        while (playing == true)
        {
            update();

            if (x1 >= 680 || x1 < 0 || y >= 680 || y < 20) 
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
            settextstyle(0,HORIZ_DIR,30);
            outtextxy(140, 340, "YOU LOST, FINAL ");
            outtextxy(376, 340, score);
            Sleep(500);
            getch();
            cleardevice();
            outtextxy(140,340,"Press any key to continue");
            Sleep(500);
            char re_start = getch();
            if (re_start) 
                restart();
            
        }
    }
    getch();
    return 0;
}