
#include <stdio.h>
#include <stdlib.h>

char check_win(char xo[3][3]);
void display_xo_game(char xo[3][3]);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char xo[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int i = 0;
	while(1)
	{
		int row, column;
		if(i % 2 == 0)
		{
			printf("\nFirst Player turn: \nPlease choose row and column: ");
			scanf("%d %d", &row, &column);
			xo[row][column] = 'x';
		}
		else
		{
			printf("\nSecond Player turn: \nPlease choose row and column: ");
			scanf("%d %d", &row, &column);
			xo[row][column] = 'o';
		}

		display_xo_game(xo);


		char v = check_win(xo);
		if(v == 'x' || v == 'o' || v == 'b')
		{
			char answer;
			if(v == 'x')
			{
				printf("\nGameOver First Player win.. \n");

			}
			else if(v == 'o')
			{
				printf("\nGameOver Second Player win.. \n");
			}
			else
			{
				printf("\nGameOver No one won \n");
			}
			printf("Do you want to play again? Yes:y  , No: n \n");
			scanf("%c", &answer);

			if(answer == 'n')
				break;
			else if(answer == 'y')
			{
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						xo[i][j] = ' ';
					}
				}

				printf("New Game \n");
			}
		}

		i++;

	}

}

void display_xo_game(char xo[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%c", xo[i][j]);
			if(j != 2)
				printf(" | ");
		}
		if(i != 2)
			printf("\n----------\n");
	}
}

char check_win(char xo[3][3])
{
	int first_win = 0, second_win = 0, balance = 1;

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{

		}
	}

	if((xo[0][0] == xo[0][1]) && (xo[0][0] == xo[0][2]))
	{
		if(xo[0][0] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][0] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}


	if((xo[1][0] == xo[1][1]) && (xo[1][0] == xo[1][2]))
	{
		if(xo[1][0] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[1][0] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	if((xo[2][0] == xo[2][1]) && (xo[2][0] == xo[2][2]))
	{
		if(xo[2][0] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[2][0] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}


	if((xo[0][0] == xo[1][0]) && (xo[0][0] == xo[2][0]))
	{
		if(xo[0][0] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][0] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	if((xo[0][1] == xo[1][1]) && (xo[0][1] == xo[2][1]))
	{
		if(xo[0][1] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][1] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	if((xo[0][2] == xo[1][2]) && (xo[0][2] == xo[2][2]))
	{
		if(xo[0][2] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][2] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	if((xo[0][0] == xo[1][1]) && (xo[0][0] == xo[2][2]))
	{
		if(xo[0][0] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][0] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	if((xo[0][2] == xo[1][1]) && (xo[0][2] == xo[2][0]))
	{
		if(xo[0][2] == 'x')
		{
			first_win = 1;
			second_win = 0;
		}
		else if (xo[0][2] == 'o')
		{
			first_win = 0;
			second_win = 1;
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(xo[i][j] != 'x' && xo[i][j] != 'o')
				balance = 0;
		}
	}

	if(first_win == 1)
		return 'x';
	else if(second_win == 1)
		return 'o';
	else if(balance == 1)
		return 'b';
	else
		return 'n';
}
