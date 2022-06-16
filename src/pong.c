#include <stdio.h>
int main() {
    int w = 80;
    int h = 25;
    int ball_start_x = w/2;
    int ball_start_y = h/2;
    int ball_y = ball_start_y;
    int ball_x = ball_start_x;
    int scring_x = 33;
    int scring_y = 3;
    int ri_1 = 1;
    int ri_2 = w - 2;  // положение ракетки по оси x
    int rstart_1 = 12;
    int rstart_2 = 12;  // положение центра ракетки по оси y
    int vector_x = -1;
    int vector_y = 1;
    int win = 21;
    int player1 = 0;
    int player2 = 0;
    char key;
    char button;
    while (1) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((x == ri_1 && (y == rstart_1 - 1 || y == rstart_1 || y == rstart_1 + 1)) || (x == ri_2 && (y == rstart_2 - 1 || y == rstart_2 || y == rstart_2 + 1))) {
                printf("|");  // отрисовывается положение ракеток
            } else if (x == ball_x && y == ball_y) {
                printf("o");  // отрисовывается позиция мяча
            } else if ((y == 0 && x != 0 && x != w) || (y == h-1 && x != 0 && x != w-1)) {
                printf("-");  // отрисовывается нижняя и верхняя грань
            } else if ((x == 0 && y != 0 && y != h) || (x == w-1 && x != 0 && y != h-1 && y != 3) || ((x == w / 2) && (y != 3)) || (x == w-3 && y == 3)) {
                printf("|");  // отрисовывается левая и правая грань
            } else if ((x == w / 2 - 1 && y == 3)) {
                printf("|");  // отрисовывается середина
            } else if (x == scring_x && y == scring_y) {
                printf("%02d", player1);  // очки первого
            } else if (x == (w - scring_x - 2) && y == scring_y) {
                printf("%02d", player2);  // очки второго
            } else
                printf(" ");  // всё остальное заполняем пробелами
        }
        printf("\n");  // завершаем строку и переходим на следующую по оси y
    }
// тут начинаетя описание движения мяча
        if (ball_y == 1 || ball_y == h-2) {
                vector_y = -vector_y;  // смена траектории на противоположную по оси У при столконовении с верхней или нижней гранью
        }
        if (ball_x == ri_1 + 1 && (ball_y == rstart_1 - 1 || ball_y == rstart_1 || ball_y == rstart_1 + 1)) {
            vector_x = -vector_x;
        }  // смена траектории на противоположную по оси Х при столкновении с левой ракеткой
        if (ball_x == ri_2 - 1 && (ball_y == rstart_2 - 1 || ball_y == rstart_2 || ball_y == rstart_2 + 1)) {
        vector_x = -vector_x;  // смена траектории на противоположную по оси Х при столкновении с правой ракеткой
        }
        ball_y += vector_y;  // смещение по оси Х
        ball_x += vector_x;  // смещение по оси У
// тут заканчивается описание движения мяча
// табло начало
        if (ball_x < 2) {  // если положение мяча по Х меньше 2 (соприкасается с ракеткой), то засчитываются очки второму игроку
            player2 += 1;
            ball_x = ball_start_x;  // возвращает начальное положение мяча по центру
            ball_y = ball_start_y;
        }
        if (ball_x > w - 1) {  // при вылете мяча, засчитываются очки первому игроку
            player1 += 1;
            ball_x = ball_start_x;  // возвращает начальное положение мяча по центру
            ball_y = ball_start_y;
        }
        if (player1 == win) {
            printf("Победил первый игрок\n");
            break;
        }
        else if (player2 == win) {
            printf("Победил второй игрок\n");
            break;
        }
// табло конец
// тут логика двигжения ракеток
        key = getchar();
        if (key == 'a') {
            if (rstart_1 - 2 != 0)
                rstart_1--;
            else rstart_1;
        }
        if (key == 'z') {
            if (rstart_1 + 2 != h-1)
                    rstart_1++;
            else rstart_1;
        }
        if (key == 'k') {
            if (rstart_2 - 2 != 0)
                    rstart_2--;
            else rstart_2;
        }
        if (key == 'm') {
            if (rstart_2 + 2 != h-1)
                    rstart_2++;
            else rstart_2;
        }
        if (key == 'q') {
            return -1;
        }
// тут заканчивается логика движения ракеток
        printf("\33[0d\33[2J");
    }
}

