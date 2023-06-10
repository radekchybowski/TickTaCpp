#include <iostream>
#include <stdio.h>

class Game {
public:
    char board[3][3] = {0};
    char p1 = 'x', p2 = 'o';
    int x, y;
    int won;

    Game() {
        x = 0, y = 0;
        won = 0;
    }

    void printBoard() {
        for (int y = 0; y < 3; y++ ) {
            for (int x = 0; x < 3; x++ ) {
                printf("%c", board[y][x]);
            }
            printf("\n");
        }
        return;
    };

    void aiMove() {
        char comp = p2, human = p1;

        if(0 == board[1][1]) {
            board[1][1] = comp;
            return;
        }

        //arrays containing weight of each row, col and diagonal for each player
        int outcomesHuman[8] = {0};
        int outcomesComp[8] = {0};

        //horizontal
        for (int y = 0; y < 3; y++ ) {
            for (int x = 0; x < 3; x++ ) {
                if (board[y][x] == human) outcomesHuman[y]++;
                if (board[y][x] == comp) outcomesComp[y]++;
            }
        }

        //vertical
        for (int x = 0; x < 3; x++ ) {
            for (int y = 0; y < 3; y++ ) {
                if (board[y][x] == human) outcomesHuman[3+x]++;
                if (board[y][x] == comp) outcomesComp[3+x]++;
            }
        }

        //diagonal
        int j = 2;
        for (int i = 0; i < 3; i++) {

            //first diagonal
            if (board[i][i] == human) outcomesHuman[6]++;
            if (board[i][i] == comp) outcomesComp[6]++;

            //second diagonal
            if (board[j][i] == human) outcomesHuman[7]++;
            if (board[j][i] == comp) outcomesComp[7]++;
            j--;
        }

        for (int i = 0; i < 8; i++) {
            printf("%d ", outcomesHuman[i]);
        }
        printf("\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", outcomesComp[i]);
        }
        printf("\n");

        //check if game has been won
        for(int i = 0; i < 8; i++) {
            if (outcomesHuman[i] == 3) {
                won = 1;
                return;
            }
            if (outcomesComp[i] == 3) {
                won = 2;
                return;
            }
        }
        int counter = 0;
        for (int y = 0; y < 3; y++ ) {
            for (int x = 0; x < 3; x++ ) {
                if (board[y][x] == 0) counter++;
            }
        }
        if (0 == counter) {
            won = 3;
            return;
        }


        for(int i = 0; i < 8; i++) {
            if(outcomesComp[i] == 2) {

                //first diagonal
                if (i == 6) {
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[n][n]) {
                            board[n][n] = comp;
                            return;
                        }
                    }
                }


                //second diagonal
                if(i == 7) {
                    int j = 2;
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[j][n]) {
                            board[j][n] = comp;
                            return;
                        }
                        j--;
                    }
                }

                //horizontal
                if(i < 3) {
                    for (int x = 0; x < 3; x++ ) {
                        if (0 == board[i][x]) {
                            board[i][x] = comp;
                            return;
                        }
                    }
                }

                    //vertical
                else {
                    for (int y = 0; y < 3; y++ ) {
                        if (0 == board[y][i]) {
                            board[y][i] = comp;
                            return;
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 8; i++) {
            if(outcomesHuman[i] == 2) {

                //first diagonal
                if (i == 6) {
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[n][n]) {
                            board[n][n] = comp;
                            return;
                        }
                    }
                }


                //second diagonal
                if(i == 7) {
                    int j = 2;
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[j][n]) {
                            board[j][n] = comp;
                            return;
                        }
                        j--;
                    }
                }

                //horizontal
                if(i < 3) {
                    for (int x = 0; x < 3; x++ ) {
                        if (0 == board[i][x]) {
                            board[i][x] = comp;
                            return;
                        }
                    }
                }

                    //vertical
                else {
                    for (int y = 0; y < 3; y++ ) {
                        if (0 == board[y][i]) {
                            board[y][i] = comp;
                            return;
                        }
                    }
                }
            }
        }


        for(int i = 0; i < 8; i++) {
            if(outcomesComp[i] == 1) {

                //first diagonal
                if (i == 6) {
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[n][n]) {
                            board[n][n] = comp;
                            return;
                        }
                    }
                }


                //second diagonal
                if(i == 7) {
                    int j = 2;
                    for (int n = 0; n < 3; n++) {
                        if (0 == board[j][n]) {
                            board[j][n] = comp;
                            return;
                        }
                        j--;
                    }
                }

                //horizontal
                if(i < 3) {
                    for (int x = 0; x < 3; x++ ) {
                        if (0 == board[i][x]) {
                            board[i][x] = comp;
                            return;
                        }
                    }
                }

                    //vertical
                else {
                    for (int y = 0; y < 3; y++ ) {
                        if (0 == board[y][i]) {
                            board[y][i] = comp;
                            return;
                        }
                    }
                }
            }
        }

        for(int y = 0; y < 3; y++) {
            for(int x = 0; x < 3; x++) {
                if(0 == board[y][x]) {
                    board[y][x] = comp;
                    return;
                }
            }
        }

    };

};



void makeMove(char (*board)[3], char human, char comp, int outcomes[8], int weight) {

}



int main(void) {

    Game game;

    game.printBoard();
    //game loop
    while(1)
    {
        if(1 == game.won) {
            printf("Gracz 1 wygrał");
            return 0;
        }

        if(2 == game.won) {
            printf("Gracz 1 wygrał");
            return 0;
        }
        if(3 == game.won) {
            printf("Remis!");
            return 0;
        }

        scanf("%d %d", &game.y, &game.x);
        game.board[game.y][game.x] = game.p1;
        game.aiMove();
        game.printBoard();
    }


}



