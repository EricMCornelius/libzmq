/*
    Copyright (c) 2007-2014 Contributors as noted in the AUTHORS file

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_WINDOWS_HPP_INCLUDED__
#define __ZMQ_WINDOWS_HPP_INCLUDED__

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef NOMINMAX
#define NOMINMAX          // Macros min(a,b) and max(a,b)
#endif

//  Set target version to Windows Server 2003, Windows XP/SP1 or higher.
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#ifdef __MINGW32__
//  Require Windows XP or higher with MinGW for getaddrinfo().
#if(_WIN32_WINNT >= 0x0501)
#else
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#endif
 
#include <winsock2.h>
#include <windows.h>
#include <mswsock.h>

#if !defined __MINGW64_VERSION_MAJOR && !defined __MINGW64_VERSION_MINOR
#include <Mstcpip.h>
#endif

#include <ws2tcpip.h>
#include <ipexport.h>
#if !defined _WIN32_WCE
#include <process.h>
#endif

//  In MinGW environment AI_NUMERICSERV is not defined.
#ifndef AI_NUMERICSERV
#define AI_NUMERICSERV 0x0400
#endif
#endif
