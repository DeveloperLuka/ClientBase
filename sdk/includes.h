#pragma once

#define DEBUG TRUE

#include <Windows.h>
#include <vector>
#include <memory>
#include <jni.h>
#include <thread>
#include <iostream>
#include <mutex>
#include <gl/GL.h>

#include "hook/MinHook.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl2.h"
#include "imgui/imgui_impl_win32.h"