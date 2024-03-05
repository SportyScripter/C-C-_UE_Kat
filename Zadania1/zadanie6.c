#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int generatedComputerMove(){
    return rand() % 3 ; // 0=rock, 1=paper, 2=scissors
}

void displayMove(int move){
    switch(move){
        case 0 : printf("Rock\n"); break;
        case 1: printf("Paper\n"); break;
        case 2: printf("Scissors\n"); break;
}
}


void displaymoves(int moves[100][100], int rounds,int game_result[100]){
    int p1 = 0;
    int computer = 0;
    for (int i = 1; i<=rounds; i++){
        printf("\nRound %d\n", i);
        printf("Player 1: ");
        displayMove(moves[i][0]);
        printf("Computer: ");
        displayMove(moves[0][i]);
        if (game_result[i] == 0){
            printf("Player 1 wins\n");
        }
        else if (game_result[i] == 1){
            printf("Computer wins\n");
        }
        else{
            printf("Draw\n");
        }
    }
}

int main(){
    int player1, computer;
    int scores[2] = {0,0};
    int rounds = 0;
    int moves[100][100] ;
    char choice[10];
    int game_result [100];
        while(1){
        printf("Menu:\n1.Play\n2.Write scores\n3.Exit\n");
        scanf("%s", choice);
            if (strcmp(choice, "1") == 0){
                rounds++;
                printf("Select move (0 - rock, 1 - paper, 2 - scissors): ");
                scanf("%d", &player1);
                computer = generatedComputerMove();
                printf("Computer move: ");
                displayMove(computer);
                moves[rounds][0] = player1;
                moves[0][rounds] = computer;
                    if (player1 == computer){
                        printf("Draw\n");
                        game_result[rounds] = 2;
                    }
                    else if (player1 == 0 && computer == 2 || player1 == 1 && computer == 0 || player1 == 2 && computer == 1){
                        printf("Player 1 wins\n");
                        scores[0]++;
                        game_result[rounds] = 0;

                        
                    }
                    else{
                        printf("Computer wins\n");
                        scores[1]++;
                        game_result[rounds] = 1;
                    }
            }
            else if (strcmp(choice,"scores") == 0){
                printf("\nPlayer 1: %d\nComputer: %d\n", scores[0], scores[1]);
                displaymoves(moves, rounds,game_result);
            }
            else if (strcmp(choice, "3") == 0){
                break;
            }
            else{
                printf("Invalid choice\n");
            }
        }
}
       
