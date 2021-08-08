#pragma once

//init
void init_all();
int regame();

//computer
int rand_direct();
void init_field();
void print_field();
int ship_size(int ship_num);
int is_vaild_pos(int x, int y, int size, int dir);
void drop_ship(int ship_num, int x, int y, int size, int dir);
void setting_ship();

//user
void print_user();
void user_reset();
int is_valid_cor(int x, char y, char d, int size);
void user_ship_set(int x, char y, char d, int size, int ship_num);
void user_input();
void cord_rec(int x, char y, char d, int ship_num);
void print_user2();

//battle
int invalid_attack(int x, char y);
int battle_attack();
int be_attacked();
