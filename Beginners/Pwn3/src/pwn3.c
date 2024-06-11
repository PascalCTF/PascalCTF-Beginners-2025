/**
 * @file pwn3.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-06-11
 * Compile with: gcc pwn3.c -o pwn3
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *flag = fopen("flag.txt", "r");

    if (flag == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    char data[40], input[40];
    if (fgets(data, 38, flag) == NULL){
        printf("Error: Flag file is empty\n");
        return 1;
    }
    fclose(flag);
    data[38] = '\0';

    puts("Wow, it actually compiled!");
    fgets(input, 20, stdin);
    printf(input);
    return 0;
}