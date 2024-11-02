#include <stdio.h>

int main() {
    char matrix[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    char inp;
    int pr, pc;
	int itcount = 0, obcount =0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == 'P') {
                pr = i;
                pc = j;
                break;
            }
        }
    }

    do {
		
        for (int i = 0; i < 5; i++) {
        	//if(i==0)
        		printf("{");
            for (int j = 0; j < 5; j++) {
                printf("%c ", matrix[i][j]);
            }
            printf("}");
            printf("\n");
           // if(i==5)
           
        }

        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &inp);
		inp = toupper(inp);
        
        int nr = pr, nc = pc;

        switch (inp) 
		{
		    case 'W':
		        nr -= 1;
		        break;
		    case 'S':
		        nr += 1;
		        break;
		    case 'A':
		        nc -= 1;
		        break;
		    case 'D':
		        nc += 1;
		        break;
		    case 'Q':
		        printf("Game Over!\n");
		        printf("Results:\nItems Collected: %d\nObstacles Faced: %d\n", itcount, obcount);
		        break;
		    default:
		        printf("Invalid input\n");
		        continue;
		}

        if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
            if (matrix[nr][nc] == 'X') {
            	obcount++;
                printf("Cannot move to an obstacle!\n");
            } else {

                if (matrix[nr][nc] == 'I') {
                	itcount++;
                    printf("Item collected!\n");
                }

                matrix[pr][pc] = ' ';
                matrix[nr][nc] = 'P';
                pr = nr;
                pc = nc;
            }
        } else {
            printf("Move is out of bounds!\n");
        }
    } while (inp != 'Q');
}
