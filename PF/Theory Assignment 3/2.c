#include <stdio.h>

typedef struct Players {
    int BallScore[12];
    char name[50];
    int totalscore;
} player;

int ValidScore(int score) {
    return (score >= 0 && score <= 6);
}

void playgame(player *p1, player *p2) {
    int i, score;
    p1->totalscore = 0;
    p2->totalscore = 0;

    printf("Enter Player 1's Name\n");
    scanf("%s", p1->name);
    printf("Enter score for each ball for player 1\n");
    for (i = 0; i < 12; i++) {
        scanf("%d", &score);
        if (ValidScore(score)) {
            p1->BallScore[i] = score;
            p1->totalscore += score;
        } else {
            p1->BallScore[i] = -1;
        }
    }

    printf("Enter Player 2's Name\n");
    scanf("%s", p2->name);
    printf("Enter score for each ball for player 2\n");
    for (i = 0; i < 12; i++) {
        scanf("%d", &score);
        if (ValidScore(score)) {
            p2->BallScore[i] = score;
            p2->totalscore += score;
        } else {
            p2->BallScore[i] = -1;
        }
    }
}

void findWinner(player p1, player p2) {
    if (p1.totalscore > p2.totalscore) {
        printf("The winner is %s with the score of %d\n", p1.name, p1.totalscore);
    } else if (p2.totalscore > p1.totalscore) {
        printf("The winner is %s with the score of %d\n", p2.name, p2.totalscore);
    } else {
        printf("It is a tie\n");
    }
}

void displayMatchScoreBoard(player p1, player p2) {
    printf("%s's scores: ", p1.name);
    for (int i = 0; i < 12; i++) {
        printf("%d ", p1.BallScore[i]);
    }
    printf("\nTotal: %d\n", p1.totalscore);

    printf("%s's scores: ", p2.name);
    for (int i = 0; i < 12; i++) {
        printf("%d ", p2.BallScore[i]);
    }
    printf("\nTotal: %d\n", p2.totalscore);
}

int main() {
    player p1, p2;
    playgame(&p1, &p2);
    displayMatchScoreBoard(p1, p2);
    findWinner(p1, p2);
}