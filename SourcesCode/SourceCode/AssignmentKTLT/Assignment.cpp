#include <stdio.h>
#include <stdlib.h>
/*
board: 8x8

(0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7)
(1,0) (1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7)
.
.
.
(7,0) (7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7)

*/
// Black: 1
// White: 2
// board_state include integer: 1 (black), 2 (white), others (empty position).
struct position* generate_list_valid_moves(int**, int, int&);
struct position{
    int x;//row
    int y;//column
};

void print_position(struct position pos){
    printf("(%d, %d) ", pos.x, pos.y);
}

void print_lst_position(struct position* lst_pos, int size){
    int i = 0;
	if (size == 0)
	{
					
	printf (" ");
	goto exitf;
	}
    while(i < size)
    {
        print_position(lst_pos[i]);
        i++;
    }
	exitf: ;
}
/*
name: update_board_state
pre: current board state, and chosen position of player 1 or 2
post: new board state
Ex: in start state, player 1 moves first and choses position (2, 3) ­> new board state:
(3, 3) change to 1, other don't change
current board
. . . . . . . .
. . . . . . . .
. . . . . . . .
. . . 2 1 . . .
. . . 1 2 . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .
=>
new board
. . . . . . . .
. . . . . . . .
. . . 1 . . . .
. . . 1 1 . . .
. . . 1 2 . . .
. . . . . . . .
. . . . . . . .
. . . . . . . .
*/
void update_board_state(int** board, struct position pos, int player)
{
	struct position* lst_update;
	int size, dem = 0;
	int diemCanTim = 0;
	int diemXet = 0;
	if (player == 1)
	{
		diemCanTim = 1;
		diemXet = 2;
	}
	else if ( player == 2)
	{	
		diemCanTim = 2;
		diemXet = 1;
	}
	lst_update = generate_list_valid_moves( board, player, size);
	for (int i = 0; i < size; ++i)
	{
		if (pos.x == lst_update[i].x && pos.y == lst_update[i].y)
		{
			if (pos.x - 1 < 0 || pos.x - 1 < 0)
				goto thoat1;
			else
				if (board[pos.x - 1][pos.y - 1] == diemXet)
				{
					for (int k = 2; k <= 7 && pos.x - k >= 0 && pos.y - k >= 0; ++k)
						if ( board[pos.x - k][pos.y - k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x - k][pos.y - k] != diemCanTim && board[pos.x - k][pos.y - k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x - j >= 0 && pos.y - j >= 0; ++j)
							if ( board[pos.x - j][pos.y - j] == diemXet)
								board[pos.x - j][pos.y - j] = diemCanTim;
							else
								break;
					}
					dem = 0;
				}
thoat1:;
			if (pos.x - 1 < 0)
				goto thoat2;
			else
				if (board[pos.x - 1][pos.y] == diemXet)
				{	
					for (int k = 2; k <= 7 && pos.x - k >= 0; ++k)
						if ( board[pos.x - k][pos.y] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x - k][pos.y] != diemCanTim && board[pos.x - k][pos.y] != diemXet)
							break;
					if( dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x - j >= 0; ++j)
							if ( board[pos.x - j][pos.y] == diemXet)
								board[pos.x - j][pos.y] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat2:;
			if (pos.x - 1 < 0 || pos.y + 1 > 7)
				goto thoat3;
			else
				if (board[pos.x - 1][pos.y + 1] == diemXet)
				{	
					for (int k = 2; k <= 7 && pos.x - k >= 0 && pos.y + k <= 7; ++k)
						if ( board[pos.x - k][pos.y + k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x - k][pos.y + k] != diemCanTim && board[pos.x - k][pos.y + k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x - j >= 0 && pos.y + j <= 7; ++j)
							if ( board[pos.x - j][pos.y + j] == diemXet)
								board[pos.x - j][pos.y + j] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat3:;
			if (pos.y + 1 > 7)
				goto thoat4;
			else
				if (board[pos.x][pos.y + 1] == diemXet)
				{	
					for (int k = 2; k <= 7 && pos.y + k <= 7; ++k)
						if ( board[pos.x][pos.y + k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x][pos.y + k] != diemCanTim && board[pos.x][pos.y + k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.y + j <= 7; ++j)
							if ( board[pos.x][pos.y + j] == diemXet)
								board[pos.x][pos.y + j] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat4:;
			if (pos.x + 1 > 7 || pos.y + 1 > 7)
				goto thoat5;
			else
				if (board[pos.x + 1][pos.y + 1] == diemXet)
				{	
					for (int k = 2; k <= 7 && pos.x + k <= 7 && pos.y + k <= 7; ++k)
						if ( board[pos.x + k][pos.y + k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x + k][pos.y + k] != diemCanTim && board[pos.x + k][pos.y + k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x + j <= 7 && pos.y + j <= 7; ++j)
							if ( board[pos.x + j][pos.y + j] == diemXet)
								board[pos.x + j][pos.y + j] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat5:;
			if (pos.x + 1 > 7)
				goto thoat6;
			else
				if (board[pos.x + 1][pos.y] == diemXet)
				{
					for (int k = 2; k <= 7 && pos.x + k <= 7; ++k)
						if ( board[pos.x + k][pos.y] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x + k][pos.y] != diemCanTim && board[pos.x + k][pos.y] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x + j <= 7; ++j)
							if ( board[pos.x + j][pos.y] == diemXet)
								board[pos.x + j][pos.y] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat6:;
			if (pos.x + 1 > 7 || pos.y - 1 < 0)
				goto thoat7;
			else
				if (board[pos.x + 1][pos.y - 1] == diemXet)
				{
					for (int k = 2; k <= 7 && pos.x + k <= 7 && pos.y - k >= 0; ++k)
						if ( board[pos.x + k][pos.y - k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x + k][pos.y - k] != diemCanTim && board[pos.x + k][pos.y - k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.x + j <= 7 && pos.y - j >= 0; ++j)
							if ( board[pos.x + j][pos.y - j] == diemXet)
								board[pos.x + j][pos.y - j] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat7:;
			if (pos.y - 1 < 0)
				goto thoat8;
			else
				if (board[pos.x][pos.y - 1] == diemXet)
				{
					for (int k = 2; k <= 7 && pos.y - k >= 0; ++k)
						if ( board[pos.x][pos.y - k] == diemCanTim)
						{
							++dem;
							break;
						}
						else if (board[pos.x][pos.y - k] != diemCanTim && board[pos.x][pos.y - k] != diemXet)
							break;
					if (dem != 0)
					{
						board[pos.x][pos.y] = diemCanTim;
						for (int j = 1; j <= 7 && pos.y - j >= 0; ++j)
							if ( board[pos.x][pos.y - j] == diemXet)
								board[pos.x][pos.y - j] = diemCanTim;
							else 
								break;
					}
					dem = 0;
				}
thoat8:;
		}
	}
}
struct position* generate_list_valid_moves(int** board_state, int player, int &size)
/*
    pre: current board state, and player makes move (black or white)
    post: list of valid moves (list of position) for player
*/
{
    /*example for first move, black go first
    valid moves: {(2,3), (3,2), (4,5), (5,4)}
    */
	size = 0;
	struct position* lst = new position[50];
	//----------------------------------------------------------
	int diemCanTim = 0;
	int diemXet = 0;
	if (player == 1)
	{
			diemCanTim = 1;
			diemXet = 2;
	}
	else if ( player == 2)
	{	
		diemCanTim = 2;
		diemXet = 1;
	}
	//----------------------------------------------------------
	for (int hang = 0; hang < 8; hang++)
		for(int cot = 0; cot < 8; cot++)
		{		if ((hang == 0 && cot == 0) || (hang == 7 && cot == 7) || abs(hang - cot) == 7 )
					continue;
				else if (board_state[hang][cot] == diemXet)  // consider position white (2)...
				{
					//----------------------------------------------------------------------------
					if (hang != 0 && cot != 0)
						// on the left position white
						if (board_state[hang - 1][cot - 1] != 1 && board_state[hang - 1][cot - 1] != 2) 			
							for (int i = (hang > cot ? hang : cot) - (hang > cot ? hang : cot) + 1; i < 8 - (hang > cot ? hang : cot); i++)
							{																	// +1 None consider position current.
								loop0: ;
								while ((hang + i) >= 0 && (cot + i) >= 0 && (hang + i) <= 7 && (cot + i) <= 7)// control row and column negative.
								{
									if (board_state[hang + i][cot + i] == diemXet)
									{
										i++;
										goto loop0; // exit while loop and continue for loop, like "continue;" 
									}
									if (board_state[hang + i][cot + i] == diemCanTim)
									{
										lst[size].x = hang - 1;
										lst[size].y = cot - 1;
										size++;
										break;
									}
									else if (board_state[hang + i][cot + i] != 1 && board_state[hang + i][cot + i] != 2)
										break;
								}
								break;
							}
					
					//--------------------------------------------------------------------
					if (hang != 7 && cot != 7)	
						if (board_state[hang + 1][cot + 1] != 1 && board_state[hang + 1][cot + 1] != 2) // on the right
							for (int i = (hang > cot ? hang : cot) - (hang > cot ? hang : cot) - 1; i >= 0 - (hang > cot ? hang : cot); i--)
							{	
								loop1: ;	
								while ((hang + i >= 0) && (cot + i >= 0) && (hang + i <= 7) && (cot + i <= 7))
								{
									if (board_state[hang + i][cot + i] == diemXet)
									{
										i--;
										goto loop1;
									}
									if (board_state[hang + i][cot + i] == diemCanTim)
									{
										lst[size].x = hang + 1;
										lst[size].y = cot + 1;
										size++;
										break;
									}
									else if (board_state[hang + i][cot + i] != 1 && board_state[hang + i][cot + i] != 2)									
										break;
								}
								break;
							}
				
					//----------------------------------------------------------------------------
					if (hang != 0 && cot != 7)
						if (board_state[hang - 1][cot + 1] != 1 && board_state[hang - 1][cot + 1] != 2) // under the left
							for (int i = (hang > cot ? hang : cot) - (hang > cot ? hang : cot) + 1; i < 8 - (hang > cot ? hang : cot); i++)
							{	
								loop2: ;
								while ((hang + i >= 0) && (cot - i >= 0) && (hang + i <= 7) && (cot - i <= 7))
								{
									if (board_state[hang + i][cot - i] == diemXet)
									{	
										i++;
										goto loop2;
									}
									if (board_state[hang + i][cot - i] == diemCanTim)
									{
										lst[size].x = hang - 1;
										lst[size].y = cot + 1;
										size++;
										break;
									}
									else if (board_state[hang + i][cot - i] != 1 && board_state[hang + i][cot - i] != 2)
										break;
								}
								break;
							}
					
					//--------------------------------------------------------------------
					if (hang != 7 && cot != 0)
						if (board_state[hang + 1][cot - 1] != 1 && board_state[hang + 1][cot - 1] != 2) // under the right
							for (int i = (hang > cot ? hang : cot) - (hang > cot ? hang : cot) - 1; i >= 0 - (hang > cot ? hang : cot); i--)
							{	
								loop3: ;
								while (hang + i >= 0 && cot - i >= 0 && hang + i <= 7 && cot - i <= 7)
								{
									if (board_state[hang + i][cot - i] == diemXet)
									{
										i--;
										goto loop3;
									}
									if (board_state[hang + i][cot - i] == diemCanTim)
									{
										lst[size].x = hang + 1;
										lst[size].y = cot - 1;
										size++;
										break;
									}
									else if (board_state[hang + i][cot - i] != 1 && board_state[hang + i][cot - i] != 2)
										break;
									else 
										break;
								}
								break;
							}
					
					//--------------------------------------------------------------------
					if (hang != 7)
						if (board_state[hang + 1][cot] != 1 && board_state[hang + 1][cot] != 2) // above
							for (int i = hang - 1; i >= 0; i--)
							{
								if (board_state[i][cot] == diemXet)
									continue;
								if (board_state[i][cot] == diemCanTim)
								{
									lst[size].x = hang + 1;
									lst[size].y = cot;
									size++;
									break;
								}
								else if (board_state[i][cot] != 1 && board_state[i][cot] != 2)
									break;
							}
			
					//-------------------------------------------------------------------
					if (hang != 0)
						if (board_state[hang-1][cot] != 1 && board_state[hang-1][cot] != 2) // under
							for (int i = hang + 1; i < 8; i++)
							{
								if (board_state[i][cot] == diemXet)
								continue;
								if (board_state[i][cot] == diemCanTim)
								{
									lst[size].x = hang - 1;
									lst[size].y = cot;
									size++;
									break;
								}
								else if (board_state[i][cot] != 1 && board_state[i][cot] != 2)
									break;
							}
					//--------------------------------------------------------------------
					if (cot != 0)
						if (board_state[hang][cot - 1] != 1 && board_state[hang][cot - 1] != 2) // left
							for (int i = cot + 1; i < 8; i++)
							{
								if (board_state[hang][i] == diemXet)
									continue;
								if (board_state[hang][i] == diemCanTim)
								{
									lst[size].x = hang;
									lst[size].y = cot - 1;
									size++;
									break;
								}
								else if (board_state[hang][i] != 1 && board_state[hang][i] != 2)
									break;
							}
					//---------------------------------------------------------------------
					if (cot != 7)
						if (board_state[hang][cot + 1] != 1 && board_state[hang][cot + 1] != 2) // right
							for (int i = cot - 1; i >= 0; i--)
							{
								if (board_state[hang][i] == diemXet)
									continue;
								if (board_state[hang][i] == diemCanTim)
								{
									lst[size].x = hang;
									lst[size].y = cot + 1;
									size++;
									break;
								}
								else if (board_state[hang][i] != 1 && board_state[hang][i] != 2)
									break;
							}
				}
		}
		//-----------------------delete element same---------------------------------------
		
		//---------------------------------------------------------------------------------
		int i, j, k;
		for (i = 0; i<size - 1; i++) {
			j = i + 1;
			while (j<size)
				if (lst[i].x == lst[j].x && lst[i].y == lst[j].y) {
					for (k = j; k<size - 1; k++) lst[k] = lst[k + 1];
					size--;
				}
				else j = j + 1;
		}
		//----------------sort array-------------BubbleSort.... develop for lst.y????
		bool doiCho = true;
		position temp;
		for (int soLanQuet = 0; soLanQuet < size - 1; soLanQuet++)
		{
			doiCho = false;
			for (int i = 0; i < size - 1 - soLanQuet; i++)
				if (lst[i].x > lst[i + 1].x)
				{	
					doiCho = true;
					temp = lst[i];
					lst[i] = lst[i + 1];
					lst[i + 1] = temp;
				}
				else if (lst[i].x == lst[i + 1].x && lst[i].y >= lst[i + 1].y) //develop lst.y
				{
					doiCho = true;
					temp = lst[i];
					lst[i] = lst[i + 1];
					lst[i + 1] = temp;
				}
		} 
    return lst;
}
