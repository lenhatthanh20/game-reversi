#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "console.h"
#include <math.h>
#include <Windows.h>

	

extern struct position* generate_list_valid_moves(int** board_state, int player, int &size);
extern void print_lst_position(struct position* lst_pos, int size);
extern void print_position(struct position pos);
extern void update_board_state(int** board, struct position pos, int player);
extern struct position;
struct position{
	int x;//row
	int y;//column
};
const int row = 8;
const int column = 8;
/*

*/
void veMotO(int iConsole, int jConsole, int colorCode)
{
	for (int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			gotoXY(jConsole + j, iConsole + i);
			TextColor(colorCode);
			printf(" ");
		}
	}
}
void veMotDiem (int** board_state, int boardRow, int boardColumn)
{
	if (board_state[boardRow][boardColumn] == 0)
		return;
	gotoXY(boardColumn * 5 + 6, boardRow * 3 + 1);
	if (board_state[boardRow][boardColumn] == 1)
	{
		TextColor(0);
		printf("   ");
	}
	else if (board_state[boardRow][boardColumn] == 2)
	{
		TextColor(127);
		printf("   ");
	}
}
void veBanCo(void)
{
	gotoXY(7, 24);
	TextColor(15);
	for (int i = 0; i < 8; ++i) //Draw column
		printf("%d    ", i);
	gotoXY(3, 1);
	for (int i = 0, j = 1; i < 8; ++i) //Draw row
	{
		printf("%d", i);
		j += 3;
		gotoXY(3, j);
	}
	//--------------------------------------------------------------
	for (int i = 0; i < row; ++i)
	{
		for (int j = 1; j < column + 1; ++j)
		{
			if ((i + j) % 2 == 0)
				veMotO(i * 3, j * 5, 16);
			else 
				veMotO(i * 3, j * 5, 60);
		}
	}
}
/* print matrix to ASCII
	player 1 (black): 1
	player 2 (white): 2
	*/
void veTrangThaiBanCo(int** board_state)
{
	TextColor(14);
	for(int row = 0; row < 8; row++) 
	{
		for(int column = 0; column < 8; column++)
		{
			veMotDiem(board_state, row, column);
		}
	}
}
int main()
{
    struct position *test;
	int size;
    int ** a = new int*[row];	// dynamic allocation two-dimensional array
	for (int i = 0; i < row; i++)
	{
		a[i] = new int[column]; 
	}
	
	for(int hang = 0; hang < 8; hang++) 
	{
		for(int cot = 0; cot < 8; cot++)
		{
			a[hang][cot] = 0;
		}
	}
	a[3][3] = 1;a[3][4] = 2;
	a[4][3] = 2;a[4][4] = 1;
	//---------------------------------------------------------------
	//---------------------------------------------------------------
    int player = 0;
	struct position state;
	int core1 = 2, core2 = 2;
	int chuyenLuotChoi = 0;
	do 
	{
		clrscr();
		gotoXY(43, 31);
		TextColor(15);
		printf("Score of player 1 (Black): %d", core1);
		gotoXY(43, 33);
		printf("Score of player 2 (White): %d", core2);
		core1 = 0; core2 = 0;
		veBanCo();
		veTrangThaiBanCo(a);
		gotoXY(0, 27);
		TextColor(2);
		printf("States of player %d:\n", abs(player) + 1);
		test = generate_list_valid_moves(a, abs(player) + 1, size);
		if (size == 0)
		{
			printf("State is not available! switch plays!");
			Sleep(2000);
			++chuyenLuotChoi;
			goto chuyenLuot;
		}
		chuyenLuotChoi = 0;
		print_lst_position(test, size);
chonLai:;
		printf("\n\nRow: ");
		std::cin >> state.x;
		printf("Column: ");
		std::cin >> state.y;
		for (int i = 0; i < size; ++i)
		{
			if (state.x == test[i].x && state.y == test[i].y)
			{
				break;
			}
			if (i == size - 1)
			{
				printf("\nYou choose wrong! then reselect! ");
				goto chonLai;
			}
		}
		update_board_state(a, state, abs(player) + 1);
chuyenLuot:;
		player = ~player;//Change player.
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
			{
				if (a[i][j] == 1)
					++core1;
				else if (a[i][j] == 2)
					++core2;
			}
	} while (2 - chuyenLuotChoi);
	gotoXY(38, 37);
	if (core1 > core2)
		printf ("\nBlack win");
	else if (core1 < core2)
		printf ("\nWhite win");
	else 
		printf("\nDraw");

	TextColor(30);
	gotoXY(2,41);printf("    ");gotoXY(12,41);printf("    ");gotoXY(20,41);printf("  ");gotoXY(26,41); printf("  ");gotoXY(30,41);printf("      ");
	gotoXY(0,42);printf("  ");gotoXY(10,42);printf("  ");gotoXY(16,42);printf("  ");gotoXY(20,42);printf("   ");gotoXY(25,42);printf("   ");gotoXY(30,42);printf("  ");
	gotoXY(0,43);printf("  ");gotoXY(4,43);printf("  ");gotoXY(10,43);printf("  ");gotoXY(16,43);printf("  ");gotoXY(20,43);printf("  ");gotoXY(23,43);printf("  ");gotoXY(26,43);printf("  ");gotoXY(30,43);printf("  ");
	gotoXY(0,44);printf("  ");gotoXY(6,44);printf("  ");gotoXY(10,44);printf("        ");gotoXY(20,44);printf("  ");gotoXY(0,44);printf("  ");gotoXY(26,44);printf("  ");gotoXY(30,44);printf("      ");
	gotoXY(0,45);printf("  ");gotoXY(6,45);printf("  ");gotoXY(10,45);printf("  ");gotoXY(16,45);printf("  ");gotoXY(0,45);printf("  ");gotoXY(20,45);printf("  ");gotoXY(26,45);printf("  ");gotoXY(30,45);printf("  ");
	gotoXY(2,46);printf("    ");gotoXY(10,46);printf("  ");gotoXY(16,46);printf("  ");gotoXY(20,46);printf("  ");gotoXY(26,46);printf("  ");gotoXY(30,46);printf("      ");
	
	gotoXY(41,41);printf("    ");gotoXY(49,41);printf("  ");gotoXY(55,41);printf("  ");gotoXY(59,41);printf("      ");gotoXY(67,41);printf("      ");
	gotoXY(39,42);printf("  ");gotoXY(45,42);printf("  ");gotoXY(49,42);printf("  ");gotoXY(55,42);printf("  ");gotoXY(59,42);printf("  ");gotoXY(67,42);printf("  ");gotoXY(72,42);printf("  ");
	gotoXY(39,43);printf("  ");gotoXY(45,43);printf("  ");gotoXY(49,43);printf("  ");gotoXY(55,43);printf("  ");gotoXY(59,43);printf("  ");gotoXY(67,43);printf("  ");gotoXY(71,43);printf("  ");
	gotoXY(39,44);printf("  ");gotoXY(45,44);printf("  ");gotoXY(49,44);printf("  ");gotoXY(55,44);printf("  ");gotoXY(59,44);printf("      ");gotoXY(67,44);printf("     ");
	gotoXY(39,45);printf("  ");gotoXY(45,45);printf("  ");gotoXY(51,45);printf(" ");gotoXY(54,45);printf(" ");gotoXY(59,45);printf("  ");gotoXY(67,45);printf("  ");gotoXY(71,45);printf("  ");
	gotoXY(41,46);printf("    ");gotoXY(52,46);printf("  ");gotoXY(59,46);printf("      ");gotoXY(67,46);printf("  ");gotoXY(72,46);printf("  ");
	

	for (int i = 0; i < row; i++)  // storage deallocation (giai phong bo nho)
	{
		delete []a[i];
	}
	delete []a;
	printf("\n");
	_getch();
    return 0;
}
