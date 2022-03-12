#include <akira/akira.h>
#include "../minecraft.h"
#include "player.h"

c_player::c_player()
{
	player = sdk::instance->getPlayer();
}

c_player::c_player(jobject player)
{
	this->player = player;
}

c_player::~c_player()
{
	akira::instance->getEnv()->DeleteLocalRef(player);
}

jobject c_player::getCapabilities()
{
	jfieldID fid = akira::instance->getEnv()->GetFieldID(akira::instance->getEnv()->GetObjectClass(player), "bA", "Lwl;");
	jobject ret = akira::instance->getEnv()->GetObjectField(player, fid);
	return ret;
}

void c_player::setFlying(bool state)
{
	jfieldID fid = akira::instance->getEnv()->GetFieldID(akira::instance->getEnv()->GetObjectClass(getCapabilities()), "b", "Z");
	akira::instance->getEnv()->SetBooleanField(getCapabilities(), fid, state);
}