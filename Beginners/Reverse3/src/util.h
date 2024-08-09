#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void print_map();
void update_position(int x_movement, int y_movement);
void clear_screen(void);
void setupbuf(void);
void setup_collectables();
char menu(void);
void contact_support(void);

#endif