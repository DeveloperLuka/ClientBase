#include <sdk/includes.h>
#include "Module.h"

const char* module::getName()
{
	return name;
}

void module::setName(const char* name)
{
	this->name = name;
}


int module::getKey()
{
	return key;
}

void module::setKey(int key)
{
	this->key = key;
}


bool module::isEnabled()
{
	return enabled;
}

void module::setEnabled(bool enabled)
{
	this->enabled = enabled;

	if (this->enabled == true) onEnable();
	else onDisable();
}


category module::getCategory()
{
	return categor;
}

void module::setCategory(category category)
{
	this->categor = category;
}


void module::toggle()
{
	this->enabled = !this->enabled;

	if (this->enabled == true) onEnable();
	else onDisable();
}


void module::onTick()
{
	localPlayer = std::make_unique<c_player>();
}

void module::onEnable()
{

}

void module::onDisable()
{

}

void module::onRender()
{

}