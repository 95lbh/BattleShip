#include "main_header.h"

//computer
extern int field[row][col];//
extern int ship_cor[2][6];
extern int ship_ok[6];
extern int com_rader[row][col];//
extern int com_hp;
//user
extern int user_field[row][col];
extern int user_rader[row][col];
extern int user_ship_ok[7];
extern int user_ship_size[6];
extern cord cordinate;
extern int user_hp;
extern int already_atk[row][col];
//computer

void init_all() {
	com_hp = 17;
	user_hp = 17;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			field[i][j] = 0;
			com_rader[i][j] = 0;
			user_field[i][j] = 0;
			user_rader[i][j] = 0;
			already_atk[i][j] = 0;
		}
	}

	for (int i = 0; i < 6; i++) {
		cordinate.x[i] = 0;
		cordinate.y[i] = 0;
		cordinate.direct[i] = 0;
		ship_ok[i] = 0;
		user_ship_ok[i] = 0;
	}
	ship_ok[0] = 1;
	user_ship_ok[6] = 1;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			ship_cor[i][j] = 0;
		}
	}
}

int regame() {
	char cmd;

	while (1) {
		system("cls");
		print_user2();

		printf("\n다시 시작하시겠습니까? (Y/N) \n");
		printf("입력 : ");
		scanf("%c", &cmd);
		while (getchar() != '\n');

		if (cmd == 'y' || cmd == 'Y') {
			printf("게임을 다시 시작합니다.\n");
			Sleep(2000);
			return 1;
		}
		else if (cmd == 'n' || cmd == 'N') {
			printf("게임을 종료합니다.\n");
			Sleep(1000);
			return 0;
		}
		else {
			printf("\n다시 입력해주세요");
			Sleep(500);
		}
	}
}