#include <sdk/includes.h>
#include "../../../akira.h"
#include "clickgui.h"

clickgui::clickgui()
{
	setName("ClickGUI");
	setKey(VK_INSERT);
	setRenderModule(true);
	setCategory(category::GUI);
	setEnabled(true);
}

void clickgui::onRender()
{
	module::onRender();

	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = true;

	ImGui::Begin(("Akira"), (bool*)true, ImGuiWindowFlags_AlwaysAutoResize);
	for (const auto m : akira::instance->moduleMngr->getModules())
	{
		bool state = m->isEnabled();

		char buffer[256];
		strncpy_s(buffer, m->getName(), sizeof(buffer));
		strncat_s(buffer, " enabled", sizeof(buffer));

		ImGui::Checkbox(buffer, &state);

		if (m->isEnabled() != state)
			m->setEnabled(state);
	}
	ImGui::End();
}