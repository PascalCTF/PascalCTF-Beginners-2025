/**
 * @file pwn2.c
 * @author Marco Balducci
 * @date 2024-08-12
 * Compile with: gcc -fno-stack-protector -no-pie pwn2.c -o unpwnable
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void win(){
    execve("/bin/sh", 0, 0);
}

void init(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void handle_alarm(int sig) {
    puts("Timeout reached. Bye!");
    exit(0);
}

void printMenu(){
    puts(" █    ██  ███▄    █  ██▓███   █     █░███▄    █  ▄▄▄       ▄▄▄▄    ██▓    ▓█████      ██████  ██░ ██  ▒█████   ██▓███  ");
    puts(" ██  ▓██▒ ██ ▀█   █ ▓██░  ██▒▓█░ █ ░█░██ ▀█   █ ▒████▄    ▓█████▄ ▓██▒    ▓█   ▀    ▒██    ▒ ▓██░ ██▒▒██▒  ██▒▓██░  ██▒");
    puts("▓██  ▒██░▓██  ▀█ ██▒▓██░ ██▓▒▒█░ █ ░█▓██  ▀█ ██▒▒██  ▀█▄  ▒██▒ ▄██▒██░    ▒███      ░ ▓██▄   ▒██▀▀██░▒██░  ██▒▓██░ ██▓▒");
    puts("▓▓█  ░██░▓██▒  ▐▌██▒▒██▄█▓▒ ▒░█░ █ ░█▓██▒  ▐▌██▒░██▄▄▄▄██ ▒██░█▀  ▒██░    ▒▓█  ▄      ▒   ██▒░▓█ ░██ ▒██   ██░▒██▄█▓▒ ▒");
    puts("▒▒█████▓ ▒██░   ▓██░▒██▒ ░  ░░░██▒██▓▒██░   ▓██░ ▓█   ▓██▒░▓█  ▀█▓░██████▒░▒████▒   ▒██████▒▒░▓█▒░██▓░ ████▓▒░▒██▒ ░  ░");
    puts("░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒ ▒▓▒░ ░  ░░ ▓░▒ ▒ ░ ▒░   ▒ ▒  ▒▒   ▓▒█░░▒▓███▀▒░ ▒░▓  ░░░ ▒░ ░   ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░ ▒░▒░▒░ ▒▓▒░ ░  ░");
    puts("░░▒░ ░ ░ ░ ░░   ░ ▒░░▒ ░       ▒ ░ ░ ░ ░░   ░ ▒░  ▒   ▒▒ ░▒░▒   ░ ░ ░ ▒  ░ ░ ░  ░   ░ ░▒  ░ ░ ▒ ░▒░ ░  ░ ▒ ▒░ ░▒ ░     ");
    puts(" ░░░ ░ ░    ░   ░ ░ ░░         ░   ░    ░   ░ ░   ░   ▒    ░    ░   ░ ░      ░      ░  ░  ░   ░  ░░ ░░ ░ ░ ▒  ░░       ");
    puts("   ░              ░              ░            ░       ░  ░ ░          ░  ░   ░  ░         ░   ░  ░  ░    ░ ░           ");
    puts("                                                                ░                                                      ");

    puts("\n\n\n");
    puts("Market menu:");
    puts("[0] Exit");
    puts("[1] Buy amazing stuff");
}

int main(){
    signal(SIGALRM, handle_alarm);
    alarm(30);
    init();

    char username[76];
    int limit = 81;
    int choice;

    puts("Welcome to Unpwnable shop!\n***Now with support for abnormally long usernames!!1!***");
    puts("To continue insert your name (don't even think about overwriting some return addresses, you can't lmao) :");
    fgets(username, limit, stdin);

    printf("Welcome to the shop %s\n\n\n", username);
    printMenu();

    scanf("%d", &choice);
    getchar();

    if (choice){
        puts("finding stuff to sell...");
        sleep(1);
        if (choice == 69){
            puts("What was your name again? I forgot it.");
            fgets(username, limit, stdin);
            puts("Ok, just hold on while i finish searching.");
            sleep(2);
        }

        puts("didn't find anything :(");
    }

    puts("Bye!");
    return 0;
}
