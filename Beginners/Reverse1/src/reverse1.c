/**
 * @file reverse1.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-01-03
 * Compile with: gcc reverse1.c -o reverse1
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// deciphered flag: ReV3r53_1s_4w3s0m3
const char key[19] = "*7^tVr4FZ#7S4RFNd2\0"; // encryption key
const char encrypted[19] = "xR\x08G$G\x07\x19kPhgCa5~\t\x01\0"; // encrypted string

bool checkSignature(char *signature){
    if(strlen(signature) != strlen(key)){
        return false;
    }
    for(int i = 0; i < strlen(encrypted); i++){
        if((int)(signature[i] ^ key[i]) != encrypted[i]){
            return false;
        }
    }
    return true;
}

int main(){
    char buffer[50];
    int buflen = 0;
    fputs("Insert the secret code: ", stdout);
    fgets(buffer, 50, stdin);
    
    buflen = strlen(buffer);
    if(buflen > 0 && buffer[buflen - 1] == '\n') {
        buflen--;
        buffer[buflen] = '\0';
    }

    if(checkSignature(buffer))
        printf("Congrats! You have found the secret code, pascalCTF{%s}", buffer);
    else
        fputs("Sorry, the secret code is wrong!", stdout);
    return 0;
}
