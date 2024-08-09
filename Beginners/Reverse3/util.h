#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

void setupbuf(void);
void clear_screen(void);
char menu(void);
void print_map();
void update_position(int x, int y);
struct Pair get_position();
void contact_support(void);
void setup_collectables(void);

#endif