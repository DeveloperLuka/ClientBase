#include <sdk/includes.h>
#include "Module.h"
#include "ModuleManager.h"
#include "modules/flight/flight.h"
#include "modules/clickgui/clickgui.h"

moduleManager::moduleManager()
{
	modules.push_back(new clickgui());
	modules.push_back(new flight());
}

std::vector<module*> moduleManager::getModules()
{
	return modules;
}

module* moduleManager::getModuleByName(const char* name)
{
	for (const auto m : modules)
	{
		if (strcmp(m->getName(), name) == 0)
		{
			return m;
		}
	}

	return 0;
}

std::vector<module*> moduleManager::getModulesByCategory(category category)
{
	std::vector<module*> res;
	for (const auto m : modules)
	{
		if (m->getCategory() == category)
		{
			res.push_back(m);
		}
	}

	return res;
}