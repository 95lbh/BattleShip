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
extern int already_atk[row][col];

//��ȿ�� ��������
int invalid_attack(int x, char y) {
	int xx, yy;
	xx = x - 1;
	if (('a' <= y && y <= 'z')) y = y - 'a' + 'A';
	yy = y - 'A';

	if ((0 <= xx && xx < col) && (0 <= yy && yy < row)) return 1;
	else {
		printf("\n��ȿ�� �Է��� �ƴմϴ�.\n");
		Sleep(500);
		return 0;
	}
}

// ���� �Լ�
int battle_attack() {
	int x;
	char y;
	int xx, yy;
	int check = 1;

	while (check) {
		system("cls");
		print_user2();

		printf("\n ������ ��ǥ�� �Է��Ͻʽÿ�. (ex. A3)\n");
		printf("�Է� : ");
		scanf("%c%d", &y, &x);
		while (getchar() != '\n');

		if (invalid_attack(x, y)) {
			xx = x - 1;
			if (('a' <= y && y <= 'z')) y = y - 'a' + 'A';
			yy = y - 'A';
			int target = field[yy][xx];
			if (already_atk[yy][xx] != 0) {
				printf("\n�̹� ������ ��ǥ�Դϴ�. �ٽ� �Է����ּ���.\n");
				Sleep(1500);
			}
			else {
				already_atk[yy][xx] = 1;
				check = 0;
				if (target > 0) {
					printf("\n���� ����!\n");
					Sleep(1500);
					if (target == 1) {
						printf("\n���� Destroyer�� �����ϼ̽��ϴ�.\n");
						Sleep(1500);
						com_hp -= 1;
						field[yy][xx] = -1;
						user_rader[yy][xx] = 1;
						system("cls");
						print_user2();
					}
					else if (target == 2) {
						printf("\n���� Submarine�� �����ϼ̽��ϴ�.\n");
						Sleep(1500);
						com_hp -= 1;
						field[yy][xx] = -1;
						user_rader[yy][xx] = 2;
						system("cls");
						print_user2();
					}
					else if (target == 3) {
						printf("\n���� Cruiser�� �����ϼ̽��ϴ�.\n");
						Sleep(1500);
						com_hp -= 1;
						field[yy][xx] = -1;
						user_rader[yy][xx] = 3;
						system("cls");
						print_user2();
					}
					else if (target == 4) {
						printf("\n���� Battle Ship�� �����ϼ̽��ϴ�.\n");
						Sleep(1500);
						com_hp -= 1;
						field[yy][xx] = -1;
						user_rader[yy][xx] = 4;
						system("cls");
						print_user2();
					}
					else if (target == 5) {
						printf("\n���� Carrier�� �����ϼ̽��ϴ�.\n");
						Sleep(1500);
						com_hp -= 1;
						field[yy][xx] = -1;
						user_rader[yy][xx] = 5;
						system("cls");
						print_user2();
					}
					if (com_hp <= 0) {
						system("cls");
						print_user2();
						printf("\n��� ������ ���߽��׽��ϴ�!\n");
						printf("\n���� �¸�!\n");
						Sleep(3000);
						return 1;
					}
				}

				else {
					user_rader[yy][xx] = -1;
					printf("\n������ ���������ϴ�!\n");
					Sleep(1500);
					system("cls");
					print_user2();
				}
			}
			
		}
		else {
			printf("\n�ٽ� �Է����ּ���!\n");
			Sleep(1000);
		}
	}
	return 0;
}


// �ǰ� �Լ�
int be_attacked() {	

	srand(time(NULL));
	int pick = 1 + rand() % 5;
	int x = cordinate.x[pick], y = cordinate.y[pick];
	char d = cordinate.direct[pick];
	system("cls");
	print_user2();
	printf("\n��밡 ���� ��ǥ ���� ��...\n");

	if (d == 'u' || d == 'd') {
		while (1) {
			srand(time(NULL));		
			int y_rand = rand() % row;
			if (com_rader[y_rand][x] != 0) {
				while (y_rand < 9) {
					y_rand++;
					if (com_rader[y_rand][x] == 0) break;
				}
				while (y_rand > 0 && com_rader[y_rand][x] != 0) {
					y_rand--;
					if (com_rader[y_rand][x] == 0) break;
				}
			}
			printf("\n������ %c%d �� �����Ͽ����ϴ�.\n", y_rand + 'A', x + 1);
			Sleep(2000);

			if (user_field[y_rand][x] > 0) {
				int atk = user_field[y_rand][x];
				if (atk == 1) {
					printf("\n����� Destroyer�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y_rand][x] = -1;
					user_hp -= 1;
					system("cls");
					print_user2();
				}
				else if (atk == 2) {
					printf("\n����� Submarine�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y_rand][x] = -1;
					user_hp -= 1;
				}
				else if (atk == 3) {
					printf("\n����� Cruiser�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y_rand][x] = -1;
					user_hp -= 1;
				}
				else if (atk == 4) {
					printf("\n����� Battle Ship�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y_rand][x] = -1;
					user_hp -= 1;
				}
				else if (atk == 5) {
					printf("\n����� Carrier�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y_rand][x] = -1;
					user_hp -= 1;
				}
				system("cls");
				print_user2();
			}
			else {
				printf("\n���� ������ ���������ϴ�!\n");
				com_rader[y_rand][x] = -2;
				Sleep(1500);
			}			
			
			if (user_hp <= 0) {
				system("cls");
				print_user2();
				printf("\n����� ��� �Լ��� ���ߴ��Ͽ����ϴ�.\n");
				printf("\n���� �й�!\n");
				Sleep(2000);
				return 1;
			}
			break;
		}
	}

	else if (d == 'l' || d == 'r') {
		while (1) {			
			srand(time(NULL));
			int x_rand = rand() % col;
			if (com_rader[y][x_rand] != 0) {
				while (x_rand < 9) {
					x_rand++;
					if (com_rader[y][x_rand] == 0) break;
				}
				while (x_rand > 0 && com_rader[y][x_rand] != 0) {
					x_rand--;
					if (com_rader[y][x_rand] == 0) break;
				}
			}

			printf("\n������ %c%d �� �����Ͽ����ϴ�.\n", y + 'A', x_rand + 1);
			Sleep(1500);

			if (user_field[y][x_rand] > 0) {
				int atk = user_field[y][x_rand];
				if (atk == 1) {
					printf("\n����� Destroyer�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y][x_rand] = -1;
					user_hp -= 1;
				}
				else if (atk == 2) {
					printf("\n����� Submarine�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y][x_rand] = -1;
					user_hp -= 1;
				}
				else if (atk == 3) {
					printf("\n����� Cruiser�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y][x_rand] = -1;
					user_hp -= 1;
				}
				else if (atk == 4) {
					printf("\n����� Battle Ship�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y][x_rand] = -1;
					user_hp -= 1;
				}
				else if (atk == 5) {
					printf("\n����� Carrier�� ���ݴ��Ͽ����ϴ�!\n");
					Sleep(1500);
					com_rader[y][x_rand] = -1;
					user_hp -= 1;
				}
				system("cls");
				print_user2();
			}
			else {
				printf("\n���� ������ ���������ϴ�!\n");
				com_rader[y][x_rand] = -2;
				Sleep(1500);
			}

			if (user_hp <= 0) {
				system("cls");
				print_user2();
				printf("\n����� ��� �Լ��� ���ߴ��Ͽ����ϴ�.\n");
				printf("\n���� �й�!\n");
				Sleep(2000);
				return 1;
			}
			break;
		}
	}
	return 0;
}