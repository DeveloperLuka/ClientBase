class moduleManager
{
private:
	std::vector<module*> modules;
public:
	moduleManager();
	std::vector<module*> getModules();
	module* getModuleByName(const char* name);
	std::vector<module*> getModulesByCategory(category category);
};