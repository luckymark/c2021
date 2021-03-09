#include <stdio.h>
#include <stdlib.h>


void main() {
    int n = 0;
    const int right_border = 105, left_border = 0;
<<<<<<< HEAD
    char value = 1;//valueÎª1Ê±ÏòÓÒÒÆ¶¯£¬·ñÔòÏò×óÒÆ¶¯ 
=======
    char value = 1;//valueä¸º1æ—¶å‘å³ç§»åŠ¨ï¼Œå¦åˆ™å‘å·¦ç§»åŠ¨ 
>>>>>>> 7f12c2d69ad4da4c566302927252d24bb3cd2783
    while (1) {
        if (value) {
            for (int i = 0; i < n; i++) {
                printf(" ");
            }
            printf("Running Word");
            n++;
<<<<<<< HEAD
            system("cls");//ÇåÆÁ 
=======
            system("cls");//æ¸…å± 
>>>>>>> 7f12c2d69ad4da4c566302927252d24bb3cd2783
            if (n == right_border) {
                value = 0;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                printf(" ");
            }
            printf("Running Word");
            n--;
            system("cls");
            if (n == left_border) {
                value = 1;
            }
        }
    }
}

