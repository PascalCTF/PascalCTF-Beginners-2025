#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#include "util.h"

void setupbuf(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void clear_screen(void)
{
    printf("\033[H\033[J");
}

struct Pair
{
    int x;
    int y;
};

struct Pair player_position = {5, 2};

struct Collectable
{
    struct Pair position;
    char name[5];
};

struct Collectable collectables[10] = {
    {{5, 6}, "up   "},
    {{18, 2}, "up   "},
    {{48, 6}, "down "},
    {{27, 2}, "down "},
    {{50, 2}, "left "},
    {{24, 10}, "right"},
    {{15, 14}, "left "},
    {{9, 2}, "right"},
    {{35, 14}, "B    "},
    {{56, 14}, "A    "},
};

char menu(void)
{
    char choice;
    printf("1. Play\n");
    printf("2. Contact support\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);
    return choice;
}

char progress[50];

char strings[][200] = {
    "╔════════════════════════════════════════════════════════╗\n",
    "║ ###################################################### ║\n",
    "║ #o    #  #  #  #        #        #     #     #     # # ║\n",
    "║ ###   #  #  #  #  #######  #  ####  ####  #######  # # ║\n",
    "║ #     #  #     #           #  #           #     #    # ║\n",
    "║ ####  #  #  ####  ##########  #######  #######  #  ### ║\n",
    "║ #  #              #        #        #        #     # # ║\n",
    "║ #  ####  ####  #  ####  #######  ####  ##########  # # ║\n",
    "║ #  #        #  #           #  #           #          # ║\n",
    "║ #  #  ##########  ##########  #  #######  ####  #### # ║\n",
    "║ #              #  #  #  #  #        #              # # ║\n",
    "║ #  ####  #  #######  #  #  #  #  #############  ###### ║\n",
    "║ #  #     #     #  #     #     #        #     #       # ║\n",
    "║ ####  #######  #  #  ####  ##########  #  #######  ### ║\n",
    "║ #           #  #              #              #       # ║\n",
    "║ ###################################################### ║\n",
    "╠════════════════════════════════════════════════════════╣\n",
    "║                                                        ║\n",
    "║         ╔═════╗                             o  o       ║\n",
    "║         ║     ║                          o        o    ║\n",
    "║         ║     ║                         o          o   ║\n",
    "║   ╔═════╝     ╚═════╗                   o          o   ║\n",
    "║   ║                 ║                    o        o    ║\n",
    "║   ║                 ║           o  o        o  o       ║\n",
    "║   ╚═════╗     ╔═════╝        o        o                ║\n",
    "║         ║     ║             o          o               ║\n",
    "║         ║     ║             o          o               ║\n",
    "║         ╚═════╝              o        o                ║\n",
    "║                                 o  o                   ║\n",
    "║                                                        ║\n",
    "║                                                        ║\n",
    "║                     □□□□          □□□□                 ║\n",
    "║                  □□□□          □□□□                    ║\n",
    "║               □□□□          □□□□                       ║\n",
    "║            □□□□          □□□□                          ║\n",
    "║                                                        ║\n",
    "╚════════════════════════════════════════════════════════╝\n\n"};

void setup_collectables()
{
    for (int i = 0; i < 10; i++)
    {
        strings[collectables[i].position.y][collectables[i].position.x] = 'x';
    }
}

void print_map()
{
    struct Pair player_position = get_position();

    for (int i = 0; i < 37; i++)
    {
        printf("%s", strings[i]);
    }
    printf("Progress: %s\n", progress);
    return;
}

struct Pair get_position()
{
    struct Pair position = {
        player_position.x,
        player_position.y};
    return position;
}

void get_collectable(struct Pair position)
{
    for (int i = 0; i < 10; i++)
    {
        if (collectables[i].position.x == position.x && collectables[i].position.y == position.y)
        {
            strings[position.y][position.x] = ' ';
            for (int j = 0; j < 46; j++)
            {
                if (progress[j] == '\0')
                {
                    for (int k = 0; k < 5; k++)
                    {
                        progress[j + k] = collectables[i].name[k];
                    }
                    return;
                }
            }
        }
    }
    return;
}

bool check_movement(int x_movement, int y_movement)
{
    struct Pair current_position = get_position();
    return strings[current_position.y + y_movement][current_position.x + x_movement] != '#';
}

void update_position(int x_movement, int y_movement)
{
    if (check_movement(x_movement, y_movement))
    {
        strings[player_position.y][player_position.x] = ' ';
        player_position.x += x_movement;
        player_position.y += y_movement;
        if (strings[player_position.y][player_position.x] == 'x')
        {
            get_collectable(player_position);
        }
        strings[player_position.y][player_position.x] = 'o';
    }
    return;
}

void contact_support(void)
{
    printf("%s", "***** Contact support *****\n\n\n");
    printf("%s", "Would you like to send your progress to support? (Y/n): ");
    char choice = getchar();
    getchar();
    if (choice != 'n' || choice != 'N')
    {
        printf("%s", "\nSending progress to support...\n");
        CURL *curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5000/adminSupport");
            char *json_data = "{\"code\":\"%s\"}", progress;

            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);

            sleep(2);
            res = curl_easy_perform(curl); //TODO: check response == code and finish challenge

            printf("%u\n", res);

            // Cleanup
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            curl_global_cleanup();
        }
        else
            printf("%s", "Something really bad happened");
    }

    return;
}