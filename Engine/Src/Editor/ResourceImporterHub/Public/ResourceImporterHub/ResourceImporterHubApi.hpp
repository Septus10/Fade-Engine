#pragma once

#ifdef FADE_EXPORT
#define FADE_RESOURCEIMPORTERHUB_API __declspec(dllexport)
#else
#define FADE_RESOURCEIMPORTERHUB_API __declspec(dllimport)
#endif