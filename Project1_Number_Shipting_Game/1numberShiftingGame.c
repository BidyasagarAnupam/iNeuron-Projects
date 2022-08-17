// Number Shifting Game
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

// function declaration
int random_array(int[][4], int[]);
// functions which are called in while loop
void down_update_array(int[][4], int*, int*, int*);
void right_update_array(int[][4], int*, int*, int*);
void up_update_array(int[][4], int*, int*, int*);
void left_update_array(int[][4], int*, int*, int*);
int check_sort(int[][4]);
void display(int[][4], int*, int*);


//  Function for Only Colors.......................
void red() {
    printf("\033[1;31;1m");
}
void yellow() {
    printf("\033[1;33m");
}
void white() {
    printf("\033[0;37m");
}
void green() {
    printf("\033[0;32m");
}
void blue() {
    printf("\033[0;34m");
}
void orange() {
    printf("\033[38;2;255;165;0m");
}
void reset() {
    printf("\033[0m");
}
//  Color functinos END................

//  functino for Welcome Screen
void welcomeText(char userName[]) {
    int elements = 1;
    printf("Welcome, %s.....\n", userName);
    system("pause");
    system("cls");

    printf("\t\t\tNUMBER SHIPTING GAME\n\n");
    red();
    printf("\t\t\tRULE OF THIS GAME\n\n");
    printf("1. You can move only 1 step at a time by arrow key\n");
    reset();
    printf("\tMove Up    :  by Up arrow key\n");
    printf("\tMove Down  :  by Down arrow key\n");
    printf("\tMove Left  :  by Left arrow key\n");
    printf("\tMove Right :  by Right arrow key\n");
    red();
    printf("2. You Can move number at empty position only\n");
    printf("3. For each valid move : your total number of move will decrease by 1\n");
    printf("4. Winning situation : Number in a 4x4 matrix should be in order from 1 to 15\n\n");
    reset();
    printf("\t\tWinning Situation:\n");
    yellow();
    //  printing the winning matrix
    printf("---------------------\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (j == 3 && i == 3) {
                printf("|    |");
            }
            else {
                if (elements <= 9) {
                    if (j == 3) {
                        printf("|  %d |", elements);
                        elements++;
                    }
                    else {
                        printf("|  %d ", elements);
                        elements++;
                    }
                }
                else {
                    if (j == 3) {
                        printf("| %d |", elements);
                        elements++;
                    }
                    else {
                        printf("| %d ", elements);
                        elements++;
                    }
                }
            }
        }
        printf("\n");
    }
    printf("---------------------\n\n");
    red();
    printf("5. You can exit game at any time by pressing 'E' or 'e'\n");
    yellow();
    printf("So Try to win in minimum no of move");
    reset();
}



//  main function
int main() {
    char direction;
    char while_conditio = 0;
    int while_condition_2 = 0;
    int temp[16] = { 0 };
    //  All variable for main game logic
    int rows = 4, columns = 4, cordinate_1 = 3, cordinate_2 = 3;
    int array[rows][columns];
    int remaining_moves = 10;
    do {
        reset();
        cordinate_1 = 3;
        cordinate_2 = 3;
        while_condition_2 = 0;
        remaining_moves = 10;
        system("cls");
        char userName[20];


        //  Code to get Uer's Name
        printf("Enter Player Name: \n");
        fflush(stdin);
        fgets(userName, 20, stdin);
        userName[strlen(userName) - 1] = '\0';
        system("cls");

        //  Code Welcome Screen
        welcomeText(userName);
        printf("\nPress Enter Key to playing game . . .");
        getchar();
        system("cls");

        // playGame();
        // Main game code
        random_array(array, temp);
        system("cls");
        display(array, &cordinate_1, &cordinate_2);

        blue();
        printf("\nPlayer Name:  ");
        yellow();
        printf("%s", userName);
        blue();
        printf(" Your remaining moves: ");
        red();
        printf("%d\n", remaining_moves);
        reset();

        // calling functions 

        while (remaining_moves > 0) {
            direction = getch();
            switch (direction)

            {
            case 72:
                system("cls");
                up_update_array(array, &cordinate_1, &cordinate_2, &remaining_moves);
                if (check_sort(array)) {
                    blue();
                    printf("YOu won the game\n");
                    reset();
                    break;
                }
                display(array, &cordinate_1, &cordinate_2);
                blue();
                printf("\nPlayer Name:  ");
                yellow();
                printf("%s", userName);
                blue();
                printf(" Your remaining moves: ");
                red();
                printf("%d\n", remaining_moves);
                reset();
                break;

            case 75:
                system("cls");
                left_update_array(array, &cordinate_1, &cordinate_2, &remaining_moves);
                if (check_sort(array)) {
                    blue();
                    printf("YOu won the game\n");
                    reset();
                    break;
                }
                display(array, &cordinate_1, &cordinate_2);
                blue();
                printf("\nPlayer Name:  ");
                yellow();
                printf("%s", userName);
                blue();
                printf(" Your remaining moves: ");
                red();
                printf("%d\n", remaining_moves);
                reset();
                break;

            case 80:
                system("cls");
                down_update_array(array, &cordinate_1, &cordinate_2, &remaining_moves);
                if (check_sort(array)) {
                    blue();
                    printf("YOu won the game\n");
                    reset();
                    break;
                }
                display(array, &cordinate_1, &cordinate_2);
                blue();
                printf("\nPlayer Name:  ");
                yellow();
                printf("%s", userName);
                blue();
                printf(" Your remaining moves: ");
                red();
                printf("%d\n", remaining_moves);
                reset();
                break;

            case 77:
                system("cls");
                right_update_array(array, &cordinate_1, &cordinate_2, &remaining_moves);
                if (check_sort(array)) {
                    blue();
                    printf("YOu won the game\n");
                    reset();
                    break;
                }
                display(array, &cordinate_1, &cordinate_2);
                blue();
                printf("\nPlayer Name:  ");
                yellow();
                printf("%s", userName);
                blue();
                printf(" Your remaining moves: ");
                red();
                printf("%d\n", remaining_moves);
                reset();
                break;
            case 'e':
                exit(0);
            case 'E':
                exit(0);
            }
        }
        //  Afetr user Lost the game
        if (remaining_moves == 0) {
            system("cls");
            red();
            printf("Oppss... You Lost the game !!!\n");
            reset();
            yellow();
            printf("if you want to exit press 'n' and if you want to play more press 'y'\n");
            scanf("%c", &while_conditio);
            if (while_conditio == 121) {
                while_condition_2 = 1;
            }
        }
    } while (while_condition_2);


    //  End of Main game code........
    printf("\n");
    system("pause");
    return 0;
}


//  ALL Function Defination

// function definition for Display an array
int random_array(int array[][4], int temp[]) {
    int rows, columns;
    int random, i;
    int randvalues[15], m = 0;
    int t, j;

    srand(time(NULL));
    for (i = 0;i < 16;i++)     //assigning values 1 to 36 
        randvalues[i] = i + 1;

    for (i = 0;i < 16;i++)      //shuffle logic
    {
        j = i + rand() / (RAND_MAX / (16 - i) + 1);
        t = randvalues[j];
        randvalues[j] = randvalues[i];
        randvalues[i] = t;
    }

    for (rows = 0;rows < 4;rows++) //conversion from 1-D to 2-D array and printning
    {
        for (columns = 0;columns < 4;columns++)
        {
            array[rows][columns] = randvalues[m++];
            printf("%d ", array[rows][columns]);
        }
        printf("\n");
    }
    return 0;
}


void display(int array[][4], int* cordinate_1, int* cordinate_2) {
    orange();
    printf("---------------------\n");
    reset();
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            orange();
        }
        else if (i == 3) {
            green();
        }
        else {
            white();
        }
        for (int j = 0; j < 4; j++) {
            if (i == *cordinate_1 && j == *cordinate_2) {
                array[i][j] = 32;
                if (j == 3) {
                    printf("|  %c |", array[i][j]);
                }
                else {
                    printf("| %c  ", array[i][j]);
                }
            }
            else {
                //  code for which numbers are less than 9
                if (array[i][j] <= 9) {
                    //  for last column
                    if (j == 3) {
                        printf("|  %d |", array[i][j]);
                    }
                    else {
                        printf("|  %d ", array[i][j]);
                    }
                }
                //  code for which numbers are greter than 9
                else {
                    //  for last column
                    if (j == 3) {
                        printf("| %d |", array[i][j]);
                    }
                    else {
                        printf("| %d ", array[i][j]);

                    }
                }
            }
        }

        printf("\n");
    }
    green();
    printf("---------------------");
    reset();
}

//  function for generate a Random Array

//  function for Down Arrow Key
void down_update_array(int array[][4], int* cordinate_1, int* cordinate_2, int* remaningMoves) {
    // printf("%d %d you enter down", *cordinate_1, *cordinate_2);
    int tempp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // printf("\n%d %d i am up wala (i = %d ,j = %d)\n",*cordinate_1,*cordinate_2,i,j);
            // user press down arrow key
            if ((i == *cordinate_1 && j == *cordinate_2) && (i > 0 && j < 4)) {
                // printf("\n%d %d\n",*cordinate_1,*cordinate_2);
                array[i][j] = array[i - 1][j];
                array[i - 1][j] = 32;
                // printf("\n%d %d i am above cordinates\n",*cordinate_1,*cordinate_2);
                *cordinate_1 = i - 1;
                *cordinate_2 = j;
                *remaningMoves = *remaningMoves - 1;//extra add for remaining moves
                if (i == 0) {
                    i = 1;
                }
                tempp = 1;
                // printf("\n%d %d i am down cordinates\n",*cordinate_1,*cordinate_2);
                break;
            }
        }
        if (tempp) {
            break;
        }
    }
}

//  function for Up Arrow Key
void up_update_array(int array[][4], int* cordinate_1, int* cordinate_2, int* remaningMoves) {
    // printf("\n%d %d\n you enter up", *cordinate_1, *cordinate_2);
    int tempp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // user press down arrow key
            //printf("\n%d %d i am up wala (i = %d ,j = %d)\n",*cordinate_1,*cordinate_2,i,j);
            if ((i == *cordinate_1 && j == *cordinate_2) && (i < 3 && j < 4)) {
                //printf("\n%d %d\n",*cordinate_1,*cordinate_2);
                //contain value
                array[i][j] = array[i + 1][j]; // transfer value and replace 0
                array[i + 1][j] = 32;
                //printf("\n%d %d i am above cordinates\n",*cordinate_1,*cordinate_2);
                *cordinate_1 = i + 1;
                *cordinate_2 = j;
                *remaningMoves = *remaningMoves - 1;//extra add for remaining moves
                tempp = 1;
                //printf("\n%d %d i am down cordinates\n",*cordinate_1,*cordinate_2);
                break;
            }
        }
        if (tempp) {
            break;
        }
    }
}

//  function for Right Arrow Key
void right_update_array(int array[][4], int* cordinate_1, int* cordinate_2, int* remaningMoves) {
    // printf("\n%d %d\n you enter right\n", *cordinate_1, *cordinate_2);
    int tempp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // user press down arrow key
            if ((i == *cordinate_1 && j == *cordinate_2) && (i < 4 && j > 0)) {
                //contain value
                array[i][j] = array[i][j - 1]; // transfer value and replace 0
                array[i][j - 1] = 32;
                *cordinate_1 = i;
                *cordinate_2 = j - 1;
                *remaningMoves = *remaningMoves - 1;//extra add for remaining moves
                tempp = 1;
                break;
            }
        }
        if (tempp) {
            break;
        }
    }
}

//  function for Left Arrow Key
void left_update_array(int array[][4], int* cordinate_1, int* cordinate_2, int* remaningMoves) {
    int tempp = 0;
    // printf("%d %d", *cordinate_1, *cordinate_2);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // user press down arrow key
            //printf("\n%d %d i am up wala (i = %d ,j = %d)\n",*cordinate_1,*cordinate_2,i,j);
            if ((i == *cordinate_1 && j == *cordinate_2) && (i < 4 && j < 3)) {
                //printf("\n%d %d\n",*cordinate_1,*cordinate_2);
                //contain value
                array[i][j] = array[i][j + 1]; // transfer value and replace 0
                array[i][j + 1] = 32;
                //printf("\n%d %d i am above cordinates\n",*cordinate_1,*cordinate_2);
                *cordinate_1 = i;
                *cordinate_2 = j + 1;
                *remaningMoves = *remaningMoves - 1;//extra add for remaining moves
                tempp = 1;
                //printf("\n%d %d i am down cordinates\n",*cordinate_1,*cordinate_2);
                break;
            }
        }
        if (tempp) {
            break;
        }
    }
}

int check_sort(int array[][4]) {
    // passing as variable for checking sorted or not
    int a[16] = { 0 };
    int i, j;
    int temp = 0;
    int temp_array[16];
    for (int w = 0; w < 4; w++) {
        for (int x = 0; x < 4; x++) {
            temp_array[temp] = array[w][x];
            temp++;
        }
    }
    int z = 0;
    for (i = 0; i < 16; i++) {
        for (j = i; j < 16; j++) {
            if (temp_array[i] > temp_array[j] && (i != j)) {
                a[z] = 1;
                z++;
            }
        }
    }
    for (int i = 0; i < 16; i++) {
        if (a[i] == 1) {
            return 0;
        }
        else {
            return 1;
        }
    }
}