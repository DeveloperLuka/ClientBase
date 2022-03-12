class flight : public module
{
public:
	flight();
	void onEnable() override;
	void onDisable() override;
	void onTick() override;
};