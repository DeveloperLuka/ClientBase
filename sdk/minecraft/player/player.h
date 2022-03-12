#pragma once

#include <sdk/includes.h>

class c_player
{
private:
	jobject player;
public:
	c_player();
	c_player(jobject player);
	~c_player();

	jobject getCapabilities();
	void setFlying(bool state);

	jobject getPlayer() { return player; }
};