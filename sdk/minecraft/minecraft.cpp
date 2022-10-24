#include <akira/akira.h>
#include "minecraft.h"

std::unique_ptr<sdk::c_minecraft> sdk::instance;

jclass sdk::c_minecraft::klass()
{
	return akira::instance->getEnv()->FindClass("ave");
}

jobject sdk::c_minecraft::getMinecraft()
{
	jclass minecraftClass = klass();
	
	jfieldID fid = akira::instance->getEnv()->GetStaticFieldID(minecraftClass, "S", "Lave;");
	jobject ret = akira::instance->getEnv()->GetStaticObjectField(minecraftClass, fid);

	akira::instance->getEnv()->DeleteLocalRef(minecraftClass);

	return ret;
}

jobject sdk::c_minecraft::getPlayer()
{
	jclass minecraftClass = klass();
	jobject minecraft = getMinecraft();

	jfieldID fid = akira::instance->getEnv()->GetFieldID(minecraftClass, "h", "Lbew;");
	jobject ret = akira::instance->getEnv()->GetObjectField(minecraft, fid);

	akira::instance->getEnv()->DeleteLocalRef(minecraftClass);
	akira::instance->getEnv()->DeleteLocalRef(minecraft);

	return ret;
}

jobject sdk::c_minecraft::getWorld()
{
	jclass minecraftClass = klass();
	jobject minecraft = getMinecraft();

	jfieldID fid = akira::instance->getEnv()->GetFieldID(minecraftClass, "f", "Ldbd;");
	jobject ret = akira::instance->getEnv()->GetObjectField(minecraft, fid);

	akira::instance->getEnv()->DeleteLocalRef(minecraftClass);
	akira::instance->getEnv()->DeleteLocalRef(minecraft);

	return ret;
}