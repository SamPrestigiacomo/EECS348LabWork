#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (enter 0 or 1 to stop): ");
        scanf("%d", &score);


        if (score <= 1) {
        break;
    }
    
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    for (int td_plus2 = 0; td_plus2 <= score/8; td_plus2++) {
        for (int td_plus1 = 0; td_plus1 <= score/7; td_plus1++) {
            for (int td = 0; td <= score/6; td++) {
                for (int fg = 0; fg <= score/3; fg++) {
                    for (int safety = 0; safety <= score/2; safety++) {
                        int total = (td_plus2*8)+(td_plus1*7)+(td*6)+(fg*3)+(safety*2);

                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + 1pt, %d TD, %d 3pt FG, %d Safety\n", td_plus2, td_plus1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
    }
    

    return 0;

}