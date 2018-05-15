#include "update.h"
#include <iostream>

Update::Update()
{

}

void Update::UpdateGame(bool* menu, Player* player)
{
	if (player->health <= 0)
	{
		*menu = true;
	}
}