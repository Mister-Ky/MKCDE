
// thanks to sfml for the sample export file code for the modular library
// https://github.com/SFML/SFML/blob/2.6.x/include/SFML/System/Export.hpp
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

#ifndef MKCDE_SYSTEM_EXPORT_HPP
#define MKCDE_SYSTEM_EXPORT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <MKCDE/Config.hpp>


////////////////////////////////////////////////////////////
// Define portable import / export macros
////////////////////////////////////////////////////////////
#if defined(MKCDE_SYSTEM_EXPORTS)

#define MKCDE_SYSTEM_API MKCDE_API_EXPORT

#else

#define MKCDE_SYSTEM_API MKCDE_API_IMPORT

#endif


#endif // MKCDE_SYSTEM_EXPORT_HPP
