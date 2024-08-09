/**
 * @file main.c
 * @author Marco Balducci, Alan Davide Bovo
 * @date 2024-08-09
 * Compile with: gcc main.c util.c -lcurl -o kontactmi
 */
#include "util.h"

struct player{
    char name[20];
    int score;
};

void play_game(){
    while(1){
        print_map();
        char choice = getchar();
        getchar();
        if(choice == 'w')
            update_position(0, -1);
        else if(choice == 's')
            update_position(0, 1);
        else if(choice == 'a')
            update_position(-1, 0);
        else if(choice == 'd')
            update_position(1, 0);
        else if(choice == 'q')
            break;

        clear_screen();
    }
    return;
}

int main(){
    setupbuf();
    setup_collectables();

    while(1){
        char choice = menu();
        if(choice == '1')
            play_game();
        else if(choice == '2')
            contact_support();
        else if(choice == '3')
            break;
    }
    return 0;
}