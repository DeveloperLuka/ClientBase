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
	if (!player) return 0;
	
	jclass playerClass = akira::instance->getEnv()->GetObjectClass(player);

	jfieldID fid = akira::instance->getEnv()->GetFieldID(playerClass, "bA", "Lwl;");
	jobject ret = akira::instance->getEnv()->GetObjectField(player, fid);

	akira::instance->getEnv()->DeleteLocalRef(playerClass);

	return ret;
}

void c_player::setFlying(bool state)
{
	jobject capabilities = getCapabilities();
	if (!capabilities)
	{ 
		akira::instance->getEnv()->DeleteLocalRef(capabilities);
		return;
	}
		
	jclass capabilitiesClass = akira::instance->getEnv()->GetObjectClass(capabilities);

	jfieldID fid = akira::instance->getEnv()->GetFieldID(capabilitiesClass, "b", "Z");
	akira::instance->getEnv()->SetBooleanField(capabilities, fid, state);
	
	akira::instance->getEnv()->DeleteLocalRef(capabilitiesClass);
	akira::instance->getEnv()->DeleteLocalRef(capabilities);
}