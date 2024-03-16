/**
 * @file pwn1.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-07-19
 * Compile with: gcc -fno-stack-protector -no-pie pwn1.c -o worm
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void init(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void handle_alarm(int sig) {
    puts("Timeout reached. Bye!");
    exit(0);
}

void win(){
    char data[50];
    FILE *flag = fopen("flag.txt", "r");

    if (flag == NULL) {
        printf("Error: File not found\n");
        return;
    }

    if (fgets(data, 50, flag) == NULL){
        printf("Error: Flag file is empty\n");
        return;
    }
    fclose(flag);
    printf("Here's your prize: %s\n", &data);
}

int main(){
    signal(SIGALRM, handle_alarm);
    alarm(30);
    init();
    
    char data[44];
    int number = 69;
    
    puts("Do you want to say something?");
    fgets(data, 1337, stdin);

    if(number == 1337){
        puts("Welcome back Kevin !");
        win();
        return 0;
    }
    puts("Bye");
    return 0;
}