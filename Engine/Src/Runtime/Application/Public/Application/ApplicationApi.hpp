#pragma once

#ifdef FADE_APPLICATION_EXPORT
#define FADE_APPLICATION_API __declspec(dllexport)
#else
#define FADE_APPLICATION_API __declspec(dllimport)
#endif