
#ifndef _game_h
#define _game_h


class game
{
public:
	game();
	bool win = false;
	bool a[15][15];
	bool b[15][15];
	bool setChess(int team,int x,int y);
private:

	bool checkWin(int team, int i, int j);
	int NorthSouthCount(bool t[15][15], int i, int j);
	int EastWestCount(bool t[15][15], int i, int j);
	int NortheastToSouthwestCount(bool t[15][15], int i, int j);
	int NorthwestToSoutheastCount(bool t[15][15], int i, int j);
};

#endif