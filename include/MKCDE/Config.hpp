
// thanks to sfml for the sample config file code for the modular library
// https://github.com/SFML/SFML/blob/2.6.x/include/SFML/Config.hpp
// I changed their code for my library to avoid confusion in the names of objects


// from SFML about SFML:
// 
////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef MKCDE_CONFIG_HPP
#define MKCDE_CONFIG_HPP


////////////////////////////////////////////////////////////
// Define the MKCDE version
////////////////////////////////////////////////////////////
#define MKCDE_VERSION_MAJOR 1
#define MKCDE_VERSION_MINOR 0
#define MKCDE_VERSION_PATCH 0


////////////////////////////////////////////////////////////
// Identify the operating system
// see https://sourceforge.net/p/predef/wiki/Home/
////////////////////////////////////////////////////////////
#if defined(_WIN32)

// Windows
#define MKCDE_SYSTEM_WINDOWS
#ifndef NOMINMAX
#define NOMINMAX
#endif

#elif defined(__APPLE__) && defined(__MACH__)

// Apple platform, see which one it is
#include "TargetConditionals.h"

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR

// iOS
#define MKCDE_SYSTEM_IOS

#elif TARGET_OS_MAC

// MacOS
#define MKCDE_SYSTEM_MACOS

#else

// Unsupported Apple system
#error This Apple operating system is not supported by MKCDE library

#endif

#elif defined(__unix__)

// UNIX system, see which one it is
#if defined(__ANDROID__)

// Android
#define MKCDE_SYSTEM_ANDROID

#elif defined(__linux__)

// Linux
#define MKCDE_SYSTEM_LINUX

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

// FreeBSD
#define MKCDE_SYSTEM_FREEBSD

#elif defined(__OpenBSD__)

// OpenBSD
#define MKCDE_SYSTEM_OPENBSD

#elif defined(__NetBSD__)

// NetBSD
#define MKCDE_SYSTEM_NETBSD

#else

// Unsupported UNIX system
#error This UNIX operating system is not supported by MKCDE library

#endif

#else

// Unsupported system
#error This operating system is not supported by MKCDE library

#endif


////////////////////////////////////////////////////////////
// Define a portable debug macro
////////////////////////////////////////////////////////////
#if !defined(NDEBUG)

#define MKCDE_DEBUG

#endif


////////////////////////////////////////////////////////////
// Define helpers to create portable import / export macros for each module
////////////////////////////////////////////////////////////
#if !defined(MKCDE_STATIC)

#if defined(MKCDE_SYSTEM_WINDOWS)

// Windows compilers need specific (and different) keywords for export and import
#define MKCDE_API_EXPORT __declspec(dllexport)
#define MKCDE_API_IMPORT __declspec(dllimport)

// For Visual C++ compilers, we also need to turn off this annoying C4251 warning
#ifdef _MSC_VER

#pragma warning(disable: 4251)

#endif

#else // Linux, FreeBSD, Mac OS X

#if __GNUC__ >= 4

// GCC 4 has special keywords for showing/hidding symbols,
// the same keyword is used for both importing and exporting
#define MKCDE_API_EXPORT __attribute__ ((__visibility__ ("default")))
#define MKCDE_API_IMPORT __attribute__ ((__visibility__ ("default")))

#else

// GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
#define MKCDE_API_EXPORT
#define MKCDE_API_IMPORT

#endif

#endif

#else

// Static build doesn't need import/export macros
#define MKCDE_API_EXPORT
#define MKCDE_API_IMPORT

#endif


////////////////////////////////////////////////////////////
// Cross-platform warning for deprecated functions and classes
//
// Usage:
// class MKCDE_DEPRECATED MyClass
// {
//     MKCDE_DEPRECATED void memberFunc();
// };
//
// MKCDE_DEPRECATED void globalFunc();
////////////////////////////////////////////////////////////
#if defined(MKCDE_NO_DEPRECATED_WARNINGS)

// User explicitly requests to disable deprecation warnings
#define MKCDE_DEPRECATED

#elif defined(_MSC_VER)

// Microsoft C++ compiler
// Note: On newer MSVC versions, using deprecated functions causes a compiler error. In order to
// trigger a warning instead of an error, the compiler flag /sdl- (instead of /sdl) must be specified.
#define MKCDE_DEPRECATED __declspec(deprecated)

#elif defined(__GNUC__)

// g++ and Clang
#define MKCDE_DEPRECATED __attribute__ ((deprecated))

#else

// Other compilers are not supported, leave class or function as-is.
// With a bit of luck, the #pragma directive works, otherwise users get a warning (no error!) for unrecognized #pragma.
#pragma message("MKCDE_DEPRECATED is not supported for your compiler, please contact the Mister Mir")
#define MKCDE_DEPRECATED

#endif

#endif // MKCDE_CONFIG_HPP
