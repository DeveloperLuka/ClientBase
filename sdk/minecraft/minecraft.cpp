#include <akira/akira.h>
#include "minecraft.h"

std::unique_ptr<sdk::c_minecraft> sdk::instance;

jclass sdk::c_minecraft::klass()
{
	return akira::instance->getEnv()->FindClass("ave");
}

jobject sdk::c_minecraft::getMinecraft()
{
	jfieldID fid = akira::instance->getEnv()->GetStaticFieldID(klass(), "S", "Lave;");
	jobject ret = akira::instance->getEnv()->GetStaticObjectField(klass(), fid);

	return ret;
}

jobject sdk::c_minecraft::getPlayer()
{
	jfieldID fid = akira::instance->getEnv()->GetFieldID(klass(), "h", "Lbew;");
	jobject ret = akira::instance->getEnv()->GetObjectField(getMinecraft(), fid);

	return ret;
}

jobject sdk::c_minecraft::getWorld()
{
	jfieldID fid = akira::instance->getEnv()->GetFieldID(klass(), "f", "Ldbd;");
	jobject ret = akira::instance->getEnv()->GetObjectField(getMinecraft(), fid);

	return ret;
}