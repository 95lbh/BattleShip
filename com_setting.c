#include "main_header.h"

//computer
extern int field[row][col];
extern int ship_cor[2][6];
extern int ship_ok[6];
extern int com_rader[row][col];
extern int com_hp;
//user
extern int user_field[row][col];
extern int user_rader[row][col];
extern int user_ship_ok[7];
extern int user_ship_size[6];
extern cord cordinate;
extern int user_hp;


// 랜덤한 방향 설정
int rand_direct() {
	srand(time(NULL));
	Sleep(400);
	return rand() % 4;
}

// 필드 초기화
void init_field() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			field[i][j] = 0;
		}
	}
}

// 필트 출력
void print_field() {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 배 크기 반환
int ship_size(int ship_num) {
	int size = 0;
	if (ship_num == 1) return 2;
	else if (ship_num == 2) return 3;
	else if (ship_num == 3) return 3;
	else if (ship_num == 4) return 4;
	else if (ship_num == 5) return 5;
	else {
		printf("Ship size error!");
		return 0;
	}
}

// 배치 가능한 좌표인지 확인
int is_vaild_pos(int x, int y, int size, int dir) {
	int check = 1;
	if (dir == 0) {
		for (int i = 1; i < size; i++) {
			if ((field[y - i][x] != 0) || (y - i < 0)) return 0;
		}
		return 1;
	}
	else if (dir == 1) {
		for (int i = 1; i < size; i++) {
			if ((field[y][x + i] != 0) || (x + i > col)) return 0;
		}
		return 1;
	}
	else if (dir == 2) {
		for (int i = 1; i < size; i++) {
			if ((field[y + i][x] != 0) || (y + i > row)) return 0;
		}
		return 1;
	}
	else if (dir == 3) {
		for (int i = 1; i < size; i++) {
			if ((field[y][x - i] != 0) || (x - i < 0)) return 0;
		}
		return 1;
	}
	else {
		printf("position error!");
		return 0;
	}
}

// 유닛 배치
void drop_ship(int ship_num, int x, int y, int size, int dir) {

	if (dir == 0) {
		for (int i = 1; i < size; i++) {
			field[y - i][x] = ship_num;
		}
	}
	else if (dir == 1) {
		for (int i = 1; i < size; i++) {
			field[y][x + i] = ship_num;
		}
	}
	else if (dir == 2) {
		for (int i = 1; i < size; i++) {
			field[y + i][x] = ship_num;
		}
	}
	else if (dir == 3) {
		for (int i = 1; i < size; i++) {
			field[y][x - i] = ship_num;
		}
	}
	else {
		printf("drop ship error!\n");
	}
}

//배 배치하기
void setting_ship() {

	int ship_num, size;
	int x, y;
	printf("컴퓨터 전함 배치 중...\n");
	ship_num = 1;
	while (ship_num < 6) {
		srand(time(NULL));
		x = rand() % col;
		Sleep(10);
		srand(time(NULL));
		y = rand() % row;

		if (field[x][y] == 0) {
			ship_cor[0][ship_num] = x;
			ship_cor[1][ship_num] = y;
			field[y][x] = ship_num;
			ship_num++;
		}
	}

	ship_num = 5;
	while ((ship_num > 0) && !(ship_ok[ship_num])) {
		
		int d = rand_direct();

		size = ship_size(ship_num);

		if (is_vaild_pos(ship_cor[0][ship_num], ship_cor[1][ship_num], size, d)) {
			drop_ship(ship_num, ship_cor[0][ship_num], ship_cor[1][ship_num], size, d);
			ship_ok[ship_num] = 1;
			ship_num--;
		}
	}
	system("cls");
	printf("배치 완료!\n");
}