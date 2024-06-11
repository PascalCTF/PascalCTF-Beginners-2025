/**
 * @file emulator.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-06-11
 * Compile with: gcc emulator.c -o emulator
 * Comment: this is not part of the challenge
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 3000

int main() {
    FILE *bf = fopen("reverse2.bf", "r");
    if (bf == NULL) {
        printf("Error: File not found\n");
        return 1;
    }
    unsigned char *mem = calloc(MAX_LENGTH * 2, sizeof(unsigned char));
    
    if (mem == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    unsigned char c;
    int len = 0, pos = MAX_LENGTH, rip = 0;
    while (len < MAX_LENGTH && (c = fgetc(bf)) != EOF) {
        if (c != '<' && c != '>' && c != '+' && c != '-' &&
            c != '.' && c != ',' && c != '[' && c != ']') {
            break;
        }
        
        *(mem + len) = c;
        len++;
    }

    while (MAX_LENGTH < pos < MAX_LENGTH * 2 && rip < len){
        switch (*(mem + rip)){
            case '>':
                assert(pos + 1 < len + MAX_LENGTH);
                pos++;
                break;
            
            case '<':
                assert(pos - 1 >= MAX_LENGTH);
                pos--;
                break;
            
            case '+':
                *(mem + pos) += 1;
                break;
            
            case '-':
                *(mem + pos) -= 1;
                break;
            
            case '.':
                putchar(*(mem + pos));
                break;
            
            case ',':
                *(mem + pos) = getchar();
                break;

            case '[':
                if (*(mem + pos) == 0) {
                    while (*(mem + rip) != ']') {
                        rip++;
                        assert(rip < len);
                    }
                }
                break;
            
            case ']':
                if (*(mem + pos) != 0) {
                    while (*(mem + rip) != '[') {
                        rip--;
                        assert(rip > 0);
                    }
                }
                break;
        }
        rip++;
    }
    return 0;
}