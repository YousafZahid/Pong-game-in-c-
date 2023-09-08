#pragma once
#include"mainmenu.h"
#include"gamedisplay.h"

class render : public intro, public display
{
	int play;
public:
	
	render()
	{
		play = intro1();
	}
	void option()
	{
		if (play == 0)
		{
			singleplayer();
		}
		else
		{
			twoplayer();
		}
	}
};