#include "game.h"
#include <iostream>

using namespace std;

game::game()
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			a[i][j] = false;
			b[i][j] = false;
		}
	}
}

bool game::setChess(int team, int x, int y)
{
	int i, j;
	i = (x - 13) / 51;
	j = (y - 11) / 52;
	if (team == 1)
	{
		if (a[i][j] || b[i][j])
		{
			cout << "This point is occupied" << endl;
			return false;
		}
		else
		{
			a[i][j] = true;
		}
	}
	else
	{
		if (a[i][j] || b[i][j])
		{
			cout << "This point is occupied" << endl;
			return false;
		}
		else
		{
			b[i][j] = true;
		}
	}
	if (checkWin(team, i, j))
	{
		cout << "team " << team << " win the game" << endl;
	}
	else
	{
		cout << "team " << team << "has not won the game" << endl;
	}
}

bool game::checkWin(int team, int i, int j)
{
	bool flag;
	if (team == 1)
	{
		if (NorthSouthCount(a, i, j) >= 5 || EastWestCount(a, i, j) >= 5 || NortheastToSouthwestCount(a, i, j) >= 5 || NorthwestToSoutheastCount(a, i, j) >= 5)
			flag = true;
		else
			flag = false;
	}
	else
	{
		if (NorthSouthCount(b, i, j) >= 5 || EastWestCount(b, i, j) >= 5 || NortheastToSouthwestCount(b, i, j) >= 5 || NorthwestToSoutheastCount(b, i, j) >= 5)
			flag = true;
		else
			flag = false;
	}
	if (flag)
		win = flag;
	return flag;
}

int game::NorthSouthCount(bool t[15][15], int i, int j)
{
	int count = 0;

	int k = j;

	while (t[i][j])
	{
		count++;
		j--;
	}

	j = k;

	while (t[i][j])
	{
		count++;
		j++;
	}
	return count - 1;
}

int game::EastWestCount(bool t[15][15], int i, int j)
{
	int count = 0;

	int k = i;

	while (t[i][j])
	{
		count++;
		i--;
	}

	i = k;

	while (t[i][j])
	{
		count++;
		i++;
	}
	return count - 1;
}

int game::NortheastToSouthwestCount(bool t[15][15], int i, int j)
{
	int count = 0;

	int k = i;
	int l = j;

	while (t[i][j])
	{
		count++;
		i++;
		j--;
	}

	i = k;
	j = l;

	while (t[i][j])
	{
		count++;
		i--;
		j++;
	}
	return count - 1;
}

int game::NorthwestToSoutheastCount(bool t[15][15], int i, int j)
{
	int count = 0;

	int k = i;
	int l = j;
	while (t[i][j])
	{
		count++;
		i--;
		j++;
	}

	i = k;
	j = l;

	while (t[i][j])
	{
		count++;
		i++;
		j--;
	}
	return count - 1;
}
