#include "main_header.h"

/*
D(1): Destroyer (2)
S(2): Submarine (3)
c(3): Cruiser (3)
B(4): Battle ship (4)
C(5): Carrrier (5)
*/

//computer
int field[row][col] = { 0 };
int ship_cor[2][6] = { 0 };
int ship_ok[6] = { 1,0,0,0,0,0 };
int com_rader[row][col] = { 0 };
int com_hp = 17;
//user
int user_field[row][col] = { 0 };
int user_rader[row][col] = { 0 };
int user_ship_ok[7] = { 0,0,0,0,0,0,1 };
int user_ship_size[6] = { 0,2,3,3,4,5 };
int user_hp = 17;
int already_atk[row][col] = { 0 };

cord cordinate;

int main() {	
	system("mode con cols=90 lines=40");
	int game_over = 0;
	char retry = 1;

	while (retry) {
		init_all();
		setting_ship();
		print_field();
		Sleep(1000);
		user_input();

		while (1) {
			game_over = battle_attack();
			if (game_over == 1) break;
			system("cls");
			print_user2();
			game_over = be_attacked();
			if (game_over == 1) break;
			system("cls");
			print_user2();
		}
		retry = regame();		
	}
	return 0;
}
