// compile with gcc -fno-stack-protector -no-pie pwn2.c -o pwn2

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void win()
{
    char flag[41];
    FILE *file = fopen("flag.txt", "r");
    fgets(flag, 41, file);
    puts(flag);
    fclose(file);
}

void printMenu()
{

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

int main()
{
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

    if (choice)
    {
        puts("finding stuff to sell...");
        sleep(2);
        if (choice == 69)
        {
            puts("What was your name again? I forgot it.");
            fgets(username, limit, stdin);
            puts("Ok, just hold on while i finish searching.");
            sleep(5);
        }

        puts("didn't find anything :(");
    }

    puts("Bye!");

    return 0;
}
