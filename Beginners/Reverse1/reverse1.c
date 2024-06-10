/**
 * @file main.c
 * @author Alan Davide Bovo (alandavide.bovo.stud@ispascalcomandini.it)
 * @date 2024-01-03
 * Compile with: gcc main.c -o main
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// firma decifrata: ReV3r53_1s_4w3s0m3
const char key[19] = "*7^tVr4FZ#7S4RFNd2\0"; // chiave di cifratura
const char encrypted[19] = "xR\x08G$G\x07\x19kPhgCa5~\t\x01\0"; // stringa cifrata

bool checkSignature(char *signature){
    if(strlen(signature) != strlen(key)){ // se la lunghezza della stringa inserita non è uguale a quella della chiave
        return false;
    }
    for(int i = 0; i < strlen(encrypted); i++){
        if((int)(signature[i] ^ key[i]) != encrypted[i]){ // se il carattere della stringa inserita XOR il carattere della chiave non è uguale al carattere della stringa cifrata
            return false;
        }
    }
    return true;
}

int main(){
    char buffer[50];                            // buffer per la stringa inserita dall'utente
    fputs("Insert the secret code: ", stdout);  // stampa a video la richiesta di inserimento della stringa
    fgets(buffer, 50, stdin);                   // prende in input la stringa inserita dall'utente

    if(buffer[strlen(buffer) - 1] == '\n')      // se l'ultimo carattere della stringa inserita è un carattere di newline
        buffer[strlen(buffer) - 1] = '\0';      // lo sostituisce con il carattere di terminazione della stringa

    if(checkSignature(buffer))                  // se la stringa inserita è corretta
        printf("Congrats! You have found the secret code, pascalCTF{%s}", buffer); // stampa a video il messaggio di congratulazioni
    else
        fputs("Sorry, the secret code is wrong!", stdout);
    return 0;
}