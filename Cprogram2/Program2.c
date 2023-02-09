#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TD 6 //touchdown
#define FG  3 //field goal
#define SAFETY  2
#define TDC 8 //touchdown + 2pt conversion
#define TDFG 7 //touchdown + 1 pt fg


int main() {
    int userInput = 2;

    while (userInput != 1 && userInput != 0) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &userInput);

        printf("Possible combinations of scoring plays:\n");
        for (int i=0; i < userInput; i++) {
          for (int j = 0; j < userInput; j++) {
            for (int k = 0; k < userInput; k++) {
              for (int l = 0; l < userInput; l++) {
                for (int m = 0; m < userInput; m++) {
                  if ( (i * TD) + (j * FG) + (k * SAFETY) + (l * TDC) + (m * TDFG) == userInput) {
                    printf("%d TD + 2pt Conversion, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", l, m, i, j, k);
                  }
                }
              }
            }
          }
        }

    }

    return 0;
}