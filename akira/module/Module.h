#pragma once

#include <sdk/minecraft/player/player.h>

enum category
{
	COMBAT, PLAYER, VISUALS, GUI, WORLD
};

class module
{
private:
	category categor;
	const char* name;
	int key;
protected:
	class std::unique_ptr<c_player, std::default_delete<c_player>> localPlayer;
	// TODO Make pointers for entityplayer & world stuff
public:
	bool enabled;
	bool renderModule;

	const char* getName();
	void setName(const char* name);

	int getKey();
	void setKey(int key);
	
	bool isRenderModule();
	void setRenderModule(bool renderModule);

	bool isEnabled();
	void setEnabled(bool enabled);

	category getCategory();
	void setCategory(category category);

	void toggle();

	virtual void onTick();
	virtual void onEnable();
	virtual void onDisable();
	virtual void onRender();
};