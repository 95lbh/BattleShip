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

// 유저 화면 출력
void print_user() {
	char c = 'A';
	printf("   ");
	for (int i = 0; i < row; i++) {
		printf("%d   ", i + 1);
	}
	printf("\n\n");
	for (int i = 0; i < row; i++) {		
		printf("%c  ", c + i);
		for (int j = 0; j < col; j++) {
			printf("%d   ", user_rader[i][j]);
		}
		printf("\n");
	}
	printf("\n------------------------------------------------------------------------------\n");
	printf("   ");
	for (int i = 0; i < row; i++) {
		printf("%d   ", i + 1);
	}
	printf("\n\n");
	c = 'A';
	for (int i = 0; i < row; i++) {
		printf("%c  ", c + i);
		for (int j = 0; j < col; j++) {
			printf("%d   ", user_field[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 유저 필드 리셋
void user_reset() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			user_field[i][j] = 0;
		}
	}
}

// 유효한 형식의 좌표 방향인지 (A4u)
int is_valid_cor(int x, char y, char d, int size) {
	
	if (!(1 <= x && x <= col)) {
		printf("\nx좌표 오류. 1~%d 입력\n", col);
		Sleep(1000);
		return 0;
	}

	if ('A' <= d && d <= 'Z') d = d - 'A' + 'a';

	if (!(d == 'u' || d == 'd' || d == 'l' || d == 'r')) {
		printf("\n방향 오류. u(위) d(아래) l(왼쪽), r(오른쪽) 입력\n");
		Sleep(1000);		
		return 0;
	}
	
	if ('a' <= y && y <= 'z') y = y - 'a' + 'A';
	
	if (!('A' <= y && y < 'A' + row)) {
		printf("\ny좌표 오류. A~%c 입력\n", 'A' + row - 1);
		Sleep(1000);
		return 0;
	}
	int xx = x - 1;
	int yy = y - 'A';

	if (d == 'u') {
		for (int i = 0; i < size; i++) {
			if (!((user_field[yy - i][xx] == 0) && (yy - i >= 0))) {
				printf("\n위쪽 방향으로 배치할 수 없습니다.\n");
				Sleep(1000);
				return 0;
			}
		}
	}
	if (d == 'd') {
		for (int i = 0; i < size; i++) {
			if (!((user_field[yy + i][xx] == 0) && (yy + i < row))) {
				printf("\n아래쪽 방향으로 배치할 수 없습니다.\n");
				Sleep(1000);
				return 0;
			}
		}
	}
	if (d == 'l') {
		for (int i = 0; i < size; i++) {
			if (!((user_field[yy][xx - i] == 0) && (xx - i >= 0))) {
				printf("\n왼쪽 방향으로 배치할 수 없습니다.\n");
				Sleep(1000);
				return 0;
			}
		}
	}
	if (d == 'r') {
		for (int i = 0; i < size; i++) {
			if (!((user_field[yy][xx + i] == 0) && (xx + i < col))) {
				printf("\n오른쪽 방향으로 배치할 수 없습니다.\n");
				Sleep(1000);
				return 0;
			}
		}
	}
	return 1;	
}

// 유저 전함 배치
void user_ship_set(int x, char y, char d, int size, int ship_num) {
	if ('A' <= d && d <= 'Z') d = d - 'A' + 'a';
	if ('a' <= y && y <= 'z') y = y - 'a' + 'A';

	int xx = x - 1;
	int yy = y - 'A';

	if (d == 'u') {
		for (int i = 0; i < size; i++) {
			user_field[yy - i][xx] = ship_num;
		}
	}

	else if (d == 'd') {
		for (int i = 0; i < size; i++) {
			user_field[yy + i][xx] = ship_num;
		}
	}

	else if (d == 'l') {
		for (int i = 0; i < size; i++) {
			user_field[yy][xx - i] = ship_num;
		}
	}

	else if (d == 'r') {
		for (int i = 0; i < size; i++) {
			user_field[yy][xx + i] = ship_num;
		}
	}
}

// 유저 전함 정보 구조체 저장
void cord_rec(int x, char y, char d, int ship_num) {
	int xx = x - 1;
	if ('a' <= y && y <= 'z') y = y - 'a' + 'A';
	int yy = y - 'A';
	cordinate.x[ship_num] = xx;
	cordinate.y[ship_num] = yy;
	cordinate.direct[ship_num] = d;
}

// 유저 전함 입력
void user_input() {

	int ship_num = 1;
	char y, d;
	int x;
	int xx, yy;

	//1번 배
	while (TRUE) {
		system("cls");
		print_user2();
		printf("1. Destroyer(2칸) 를 배치시킬 좌표(A1)와 방향(u,d,l,r) 을 입력해주세요. ex. A1d \n");
		printf("입력 : ");
		scanf("%c%d%c", &y, &x, &d);
		while (getchar() != '\n');
		cord_rec(x, y, d, 1);
		
		if (!is_valid_cor(x, y, d, user_ship_size[ship_num])) {	
			system("cls");
			print_user2();
		}
		else {
			user_ship_set(x, y, d, user_ship_size[ship_num], ship_num);
			ship_num++;
			break;
		}
	}
	// 2번 배
	while (TRUE) {
		system("cls");
		print_user2();
		printf("2. Submarine(3칸) 를 배치시킬 좌표(A1)와 방향(u,d,l,r) 을 입력해주세요. ex. A1d \n");
		printf("입력 : ");
		scanf("%c%d%c", &y, &x, &d);
		while (getchar() != '\n');
		cord_rec(x, y, d, 2);
		
		if (!is_valid_cor(x, y, d, user_ship_size[ship_num])) {
			system("cls");
			print_user2();
		}
		else {
			user_ship_set(x, y, d, user_ship_size[ship_num], ship_num);
			ship_num++;
			break;
		}
	}

	// 3번 배
	while (TRUE) {
		system("cls");
		print_user2();
		printf("3. Cruiser(3칸) 를 배치시킬 좌표(A1)와 방향(u,d,l,r) 을 입력해주세요. ex. A1d \n");
		printf("입력 : ");
		scanf("%c%d%c", &y, &x, &d);
		while (getchar() != '\n');
		cord_rec(x, y, d, 3);
		
		if (!is_valid_cor(x, y, d, user_ship_size[ship_num])) {
			system("cls");
			print_user2();
		}
		else {
			user_ship_set(x, y, d, user_ship_size[ship_num], ship_num);
			ship_num++;
			break;
		}
	}

	// 4번 배
	while (TRUE) {
		system("cls");
		print_user2();
		printf("4. Battle Ship(4칸) 를 배치시킬 좌표(A1)와 방향(u,d,l,r) 을 입력해주세요. ex. A1d \n");
		printf("입력 : ");
		scanf("%c%d%c", &y, &x, &d);
		while (getchar() != '\n');
		cord_rec(x, y, d, 4);
		
		if (!is_valid_cor(x, y, d, user_ship_size[ship_num])) {
			system("cls");
			print_user2();
		}
		else {
			user_ship_set(x, y, d, user_ship_size[ship_num], ship_num);
			ship_num++;
			break;
		}
	}

	//5번 배
	while (TRUE) {
		system("cls");
		print_user2();
		printf("5. Carrier(5칸) 를 배치시킬 좌표(A1)와 방향(u,d,l,r) 을 입력해주세요. ex. A1d \n");
		printf("입력 : ");
		scanf("%c%d%c", &y, &x, &d);
		while (getchar() != '\n');
		cord_rec(x, y, d, 5);
		
		if (!is_valid_cor(x, y, d, user_ship_size[ship_num])) {
			system("cls");
			print_user2();
		}
		else {
			user_ship_set(x, y, d, user_ship_size[ship_num], ship_num);
			ship_num++;
			break;
		}
	}
	system("cls");
	print_user2();
	printf("배치 완료!\n");
	Sleep(1000);
	system("cls");
	print_user2();
}

void print_user2() {
	char c = 'A';
	printf("\t");
	for (int i = 0; i < row; i++) {
		printf("%d\t", i + 1);
	}
	printf("\n\n");
	for (int i = 0; i < row; i++) {
		printf("%c\t", c + i);
		for (int j = 0; j < col; j++) {
			if (user_rader[i][j] == -1) printf("X\t");
			else if (user_rader[i][j] > 0) printf("%d\t", user_rader[i][j]);
			else printf("□\t");			
		}
		printf("\n");
	}
	printf("\n------------------------------------------------------------------------------\n");
	printf("\t");
	for (int i = 0; i < row; i++) {
		printf("%d\t", i + 1);
	}
	printf("\n\n");
	c = 'A';
	for (int i = 0; i < row; i++) {
		printf("%c\t", c + i);
		for (int j = 0; j < col; j++) {
			if (com_rader[i][j] == -1) printf("X\t");
			else if (user_field[i][j] == 0) printf("□\t");
			else printf("%d\t", user_field[i][j]);			
		}
		printf("\n");
	}
	printf("\n");

}

