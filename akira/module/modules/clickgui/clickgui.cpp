#include <sdk/includes.h>
#include "../../../akira.h"
#include "clickgui.h"

clickgui::clickgui()
{
	setName("ClickGUI");
	setKey(16);
	setCategory(category::GUI);
	setEnabled(true);
}

void clickgui::onRender()
{
	ImGui::Begin(("Akira"), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	for (module* m : akira::instance->moduleMngr->getModules())
	{
		char buffer[256];
		strncpy_s(buffer, m->getName(), sizeof(buffer));
		strncat_s(buffer, " enabled", sizeof(buffer));

		ImGui::Checkbox(buffer, &m->enabled);
	}
	ImGui::End();
}