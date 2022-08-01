/**************SPACESHIP FLY******************/

// My First C++ Game
// AJA 1st console game

 
 
 #include<iostream>
 #include<conio.h>
 #include<time.h>
 #include<windows.h>

 #define spaceshipPos 4
 #define flyPos 75

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;   //setup coordinates in console

int spaceshipY;
int speed = 50;
int gameover = 0;

void gotoxy(int x, int y)
{
  // setup coordinates in console -COORD
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible,DWORD size)  //DWORD- unsigned int
{
  if(size == 0)
  {
    size = 20;
  }
  CONSOLE_CURSOR_INFO lpCursor;
  lpCursor.bVisible = visible;
  lpCursor.dwSize = size;
  SetConsoleCursorInfo(console, &lpCursor);
}


// Score keeper function
void init()
{
  system("cls");
  gameover = 0;
  gotoxy(3, 2);
  cout << "SCORE : ";
  for (int i = 0; i < 79;i++)
  {
    gotoxy(1 + i, 1);
    cout << "#";
    gotoxy(1 + i, 25);
    cout << "#";
  }
}

// Spaceship moving function
void movespaceship(int fly = 0)
{
  static int ground = 0;

  if (fly == 0)
    spaceshipY = 0;
  else if (fly == 2)
    spaceshipY--;
  else
    spaceshipY++;


  gotoxy(spaceshipPos, 15 - spaceshipY);
  cout << "                           ";
  gotoxy(spaceshipPos, 16 - spaceshipY);
  cout << "          ##AJA##          ";
  gotoxy(spaceshipPos, 17 - spaceshipY);
  cout << "         ##########        ";
  gotoxy(spaceshipPos, 18 - spaceshipY);
  cout << "        ############       ";
  gotoxy(spaceshipPos, 19 - spaceshipY);
  cout << "  ######################## ";
  gotoxy(spaceshipPos, 20 - spaceshipY);
  cout << "   #####  ########  #####  ";
  gotoxy(spaceshipPos, 21 - spaceshipY);
  cout << "      ######     ######    ";
  gotoxy(spaceshipPos, 22 - spaceshipY);
  cout << "       ####      ####      "; 
  gotoxy(spaceshipPos, 23 - spaceshipY);

  if (fly == 1 || fly == 2)
  {
    cout << "    ####          ####     ";
    gotoxy(2, 24 - spaceshipY);
    cout << "                           ";
  }
  else if (ground == 0)
  {
    cout << "    ####           ####    ";
    gotoxy(2, 24 - spaceshipY);
    cout << "    ####           ####    ";
    ground = !ground;
  }
  else if (ground == 1)
  {
    cout << "     #               #     "; 
    gotoxy(2, 24 - spaceshipY); 
    cout << "                           ";
    ground = !ground;
  }

  gotoxy(2, 24 - spaceshipY);
  if (fly == 0)
  {
    cout << "############################";
  }
  else
  {
    cout << "                            ";
  }
  Sleep(speed);
}

// Spaceship flying initialization function
void fly()
{
  static int plantX = 0;
  static int score = 0;
  if (plantX == 56 && spaceshipY < 4)
  {
    score = 0;
    speed = 50;
    gotoxy(36, 8);
    cout << "Game Over";
    getch();
    gameover = 1;
  }

  gotoxy(flyPos - plantX, 20);
  cout << "| | ";
  gotoxy(flyPos - plantX, 21);
  cout << "| | ";
  gotoxy(flyPos - plantX, 22);
  cout << "|_| ";
  gotoxy(flyPos - plantX, 23);
  cout << " |  ";
  gotoxy(flyPos - plantX, 24);
  cout << " |  ";

  plantX++;

  if (plantX == 73)
  {
    plantX = 0;
    score++;
    gotoxy(11, 2);
    cout << "     ";
    gotoxy(11, 2);
    cout << score;
    if (speed > 20)
      speed--;
  }
}


// Algorithm for flyying the space ship
void play()
{
  system("cls");
  char ch;
  int i;
  init();
  while (true)
  {
    while (!kbhit())
    {
      if (gameover == 1)
      {
        return;
      }
      movespaceship();
      fly();
    }
    ch = getch();
    if (ch == 32)
    {
      i = 0;
      while (i < 12)
      {
        movespaceship(1);
        fly();
        i++;
      }
      while (i > 0)
      {
        movespaceship(2);
        fly();
        i--;
      }
    }
    else if (ch == 'p' || ch == 'P')
      getch();
    else if (ch == 27)
      break;
  }
}



// Instructiom guide for playing game 
void instructions()  
{
  system("cls"); //To pause and clear the screen
  cout << "Instructions";
  cout << "\n--------------------------------";
  cout << "\n1. Avoid hurdles by jumping";
  cout << "\n2. Press 'Spacebar' to jump ";
  cout << "\n3. Press 'p' to pause game ";
  cout << "\n4. Press 'Escape' to exit from game";
  cout << "\n\n Press any key to go back to menu";
  getch();
}

// Front screen by do-while loop
int main()
{

  setcursor(0, 0);
// gotoxy - To set the cursor positon on the screen 
  do
  {
    system("cls");
    gotoxy(10, 5);
    cout << " ------------------------------- ";
    gotoxy(10, 6);
    cout << " |        SPACESHIP FLY        | ";
    gotoxy(10, 7);
    cout << " ------------------------------- ";
    gotoxy(10, 9);
    cout << "1. Start Game";
    gotoxy(10, 10);
    cout << "2. Instructions";
    gotoxy(10, 11);
    cout << "3. Quit";
    gotoxy(10, 13);
    cout << "Select option: ";
    char op = getche();

    if (op == '1')
      play();           //call play function
    else if (op == '2')
      instructions();   //call instruction function
    else if (op == '3')
      exit(0);

  } while (1);

  return 0;
}
