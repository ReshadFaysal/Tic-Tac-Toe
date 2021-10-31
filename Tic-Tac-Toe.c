/************************************************
Project Name:   Tic-Tac-Toe.
Created By:     The White Walkers

Group Members:

**Fuad Hassan
**Moonwar Al Wardiful Nishan
**Reshad Faysal
*************************************************/

#include<conio.h>
#include<stdlib.h>
#include <windows.h> //Declarations for all of the functions in the Windows API

// Declaring Variables
int board_value[10] = {2,2,2,2,2,2,2,2,2,2};
int turn=1,flag=0,player,computer;
char name[100],xh;

void game_menu();
void player_first();
void create_board();
void start_game();
void put_X_O(char ch,int pos);
void go(int n);
void check_draw();
void about();
COORD coord={0,0}; //Center of axis is set to the top left corner of the screen

void main() //Main Function
{
    game_menu(); //Calling Function game_menu()
    getch();
}

void game_menu()
{
    int choice,start;
    gotoxy(34,02);
    printf("Tic-Tac-Toe");
    gotoxy(36,04);
    printf("Welcome");
    gotoxy(29,06);
    printf("Tap Enter To Play......\n");
    gotoxy(56,06);
    getchar(xh);
    system("cls");
    gotoxy(34,02);
    printf("Tic-Tac-Toe");
    gotoxy(28,04);
    printf("Enter Player Name: ");
    scanf("%s",name);
    system("cls");
    gotoxy(34,02);
    printf("Tic-Tac-Toe");
    gotoxy(31,04);
    printf("Player Name: %s",name);
    gotoxy(28,05);
    printf("Enter 1 to Play with 'X'");
    gotoxy(28,06);
    printf("Enter 2 to Play with 'O'");
    gotoxy(25,07);
    printf("Enter 3 to Know About The Game!");
    gotoxy(32,10);
    printf("To Exit Enter 0");
    gotoxy(25,12);
    printf("Waiting for user response : ");
    gotoxy(56,12);
    scanf("%d",&choice);
    system("cls");
    turn = 1;
    switch (choice)
    {
        case 1: //The mark of Player is X
            gotoxy(34,01);
            printf("Tic-Tac-Toe");
            player = 1;
            computer = 0;
            player_first();
            break;
        case 2: //The mark of Olayer is O
            gotoxy(34,01);
            printf("Tic-Tac-Toe");
            player = 0;
            computer = 1;
            start_game();
            break;
        case 3:
            gotoxy(34,01);
            printf("Tic-Tac-Toe");
            about();
        case 0: //Program exit
            exit(1);
        default:
            game_menu();
    }
}

void player_first()
{
    int pos,a;

    check_draw();
    create_board(); //Printing game board in console
    gotoxy(30,22);
    printf("%s's Turn :  ",name);
    scanf("%d",&pos);

    if(board_value[pos] != 2) //Take the input from user & places mark to that position
        player_first();

    if(pos == check_result(player)) //Checking if the winner is player
    {
        go(pos);
        create_board();
        system("cls");
        gotoxy(34,01);
        printf("Tic-Tac-Toe");
        gotoxy(34,10);
        printf("%s Wins",name);
        gotoxy(29,12);
        printf("Thanks You For Playing.");
        gotoxy(14,13);
        printf("To Know About Us Enter '0' or Press Any Key to Exit.");
        scanf("%d",&a);
        system("cls");
        if (a==0)
            about();
        else
            exit(0);
    }

    go(pos);
    create_board();
    start_game();
}

void start_game()
{
    int a;
    if(check_result(computer))
    {
        go(check_result(computer));
        flag = 1;
    }
    else if(check_result(player))
            go(check_result(player));
    else if(counter_move2())
        go(counter_move2());
    else
        go(counter_move4());
    create_board();

    if(flag)
    {
        system("cls");
        gotoxy(34,01);
        printf("Tic-Tac-Toe");
        gotoxy(34,10);
        printf("Computer wins");
        gotoxy(29,12);
        printf("Thanks You For Playing.");
        gotoxy(16,13);
        printf("To Know About Us Enter '0' or Press Any Key to Exit.");
        scanf("%d",&a);
        system("cls");
        if (a==0)
            about();
        else
            exit(0);
    }
    else
        player_first();
}

void go(int n)
{
    if(turn % 2)
    board_value[n] = 3;
    else
    board_value[n] = 5;
    turn++;
}

int counter_move2() //Calculating counter move for player's move
{
    if(board_value[4] == 2)
        return 4;
    if(board_value[8] == 2)
        return 8;
    if(board_value[2] == 2)
        return 2;
    if(board_value[6] == 2)
        return 6;
    if(board_value[5] == 2)
        return 5;
    return 0;
}

int counter_move4() //Calculating counter move for player's move
{
    if(board_value[7] == 2)
        return 7;
    if(board_value[1] == 2)
        return 1;
    if(board_value[9] == 2)
        return 9;
    if(board_value[3] == 2)
        return 3;
    return 0;
}

int check_result(int p) //Checking Winner
{
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)
    {
        if(board_value[i] * board_value[i+1] * board_value[i+2] == check_val)
        {
            if(board_value[i] == 2)
                return i;
            if(board_value[i+1] == 2)
                return i+1;
            if(board_value[i+2] == 2)
                return i+2;
    }
    i+=3;
    }
    i = 1;
    while(i<=3)
    {
        if(board_value[i] * board_value[i+3] * board_value[i+6] == check_val)
        {
            if(board_value[i] == 2)
            return i;
            if(board_value[i+3] == 2)
            return i+3;
            if(board_value[i+6] == 2)
            return i+6;
        }
    i++;
    }

    if(board_value[1] * board_value[5] * board_value[9] == check_val)
    {
        if(board_value[1] == 2)
        return 1;
        if(board_value[5] == 2)
        return 5;
        if(board_value[9] == 2)
        return 9;
    }

    if(board_value[3] * board_value[5] * board_value[7] == check_val)
    {
        if(board_value[3] == 2)
        return 3;
        if(board_value[5] == 2)
        return 5;
        if(board_value[7] == 2)
        return 7;
    }
    return 0;
}

void gotoxy(int x,int y) //Setting Cursor Position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void check_draw() //Checking if the game draw
{
    int a;
    if(turn > 9)
    {
        system("cls");
        gotoxy(34,01);
        printf("Tic-Tac-Toe");
        gotoxy(34,10);
        printf("Game Draw");
        gotoxy(29,12);
        printf("Thanks You For Playing.");
        gotoxy(16,13);
        printf("To Know About Us Enter '0' or Press Any Key to Exit.");
        scanf("%d",&a);
        system("cls");
        if (a==0)
            about();
        else
            exit(0);
    }
}

void create_board() //Printing board in the console
{
    int j;

    for(j=7;j<20;j++)
    {
        gotoxy(21,j);
        printf("*                                   *");
    }
    for(j=9;j<17;j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(21,6);
    printf("*************************************");
    gotoxy(21,19);
    printf("*************************************");
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1;j<10;j++)
    {
        if(board_value[j] == 3)
            put_X_O('X',j);
        else if(board_value[j] == 5)
            put_X_O('O',j);
    }
}

void put_X_O(char ch,int pos) //Placing Player's Mark
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}

void about()
{
    gotoxy(37,03);
    printf("About");
    printf("\n\nTic-Tac-Toe game version 2.0.6. Created by \"The White Walkers\". The group members");
    printf("\nare Fuad Hassan, Moonwar Al Wardiful Nishan, Reshad Faysal & Obviously Google :D");
    printf("\nThis game is result of 3 nights of no sleeping in a row. We actually had to design an");
    printf("\nAI for the computer to counter the player's moves. All the credit goes to Fuad Hassan,");
    printf("\nthe leader of \"The White Walkers\".");
    printf("\n\nThere is two good news.Version 3.0.0 of this game is in development. We are trying to ");
    printf("\nadd a multi-player mode. In the multi-player mode you'll be able to play with your ");
    printf("\nfriends. The second good news is there's an Android app coming too. ^_^ ");
    printf("\n\nContact us:");
    printf("\nFuad Hassan       fb.com/SirFuadHassan ");
    printf("\nNishan            fb.com/moonwar.nishan");
    printf("\nReshad Faysal     fb.com/reshad.faysal");
    printf("\n\nThe game is free but if you are satisfied with the game feel free to donate us some TEKA-POISHA.");
    printf("\nWell, we are GORIB. We won't mind taking your money.\n\n\n\n");
    exit(0);
}


/*********************************************************
End of Program
**********************************************************/

