#include <sdk/includes.h>
#include "../../Module.h"
#include "flight.h"

flight::flight()
{
	setName("Flight");
	setKey(70);
	setRenderModule(false);
	setCategory(category::PLAYER);
	setEnabled(true);
}

void flight::onEnable() 
{
	module::onEnable();
	if (localPlayer == nullptr) return;
	localPlayer->setFlying(true);
}

void flight::onDisable()
{
	module::onDisable();
	if (localPlayer == nullptr) return;
	localPlayer->setFlying(false);
}

void flight::onTick()
{
	module::onTick();
	if (localPlayer == nullptr) return;
	localPlayer->setFlying(true);
}