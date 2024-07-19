/**
 * @file pwn1.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-07-19
 * Compile with: gcc pwn1.c -o pwn1
 */
#include <stdio.h>
#include <stdlib.h>

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

void win(){
    char data[40];
    FILE *flag = fopen("flag.txt", "r");

    if (flag == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    if (fgets(data, 38, flag) == NULL){
        printf("Error: Flag file is empty\n");
        return 1;
    }
    fclose(flag);
    printf("Here's your prize: %s", &data);
}

int main(){
    int number = 69;
    char data[40];
    
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