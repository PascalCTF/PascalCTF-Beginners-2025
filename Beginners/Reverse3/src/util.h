#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void print_map();
void clearStdin(void);
void update_position(int x_movement, int y_movement);
struct Pair get_position();
void clear_screen(void);
void setupbuf(void);
void setup_collectables();
char menu(void);
void contact_support(void);

#endif