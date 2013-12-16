/*******************************************************************************
 * syspovconfig_osx.h
 *
 * This file contains Unix flavor-specific defines for compiling the VFE
 * on MAC OS X systems.
 *
 * ---------------------------------------------------------------------------
 * Persistence of Vision Ray Tracer ('POV-Ray') version 3.7.
 * Copyright 1991-2013 Persistence of Vision Raytracer Pty. Ltd.
 *
 * POV-Ray is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * POV-Ray is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ---------------------------------------------------------------------------
 * POV-Ray is based on the popular DKB raytracer version 2.12.
 * DKBTrace was originally written by David K. Buck.
 * DKBTrace Ver 2.0-2.12 were written by David K. Buck & Aaron A. Collins.
 * ---------------------------------------------------------------------------
 * $File: //depot/povray/smp/vfe/unix/syspovconfig_osx.h $
 * $Revision: #3 $
 * $Change: 6148 $
 * $DateTime: 2013/11/30 04:25:45 $
 * $Author: clipka $
 *******************************************************************************/

#ifndef __SYSPOVCONFIG_OSX_H__
#define __SYSPOVCONFIG_OSX_H__

#include <unistd.h>

// TODO - someone needs to verify that off_t is indeed always 64 bit on Mac OS X
#define lseek64(handle,offset,whence) lseek(handle,offset,whence)

// TODO - the POV_LONG stuff is just copied from the Posix settings; someone needs to test this on OS X.
#if defined(_POSIX_V6_LPBIG_OFFBIG) || defined(_POSIX_V6_LP64_OFF64)
	// long is at least 64 bits.
	#define POV_LONG long
#elif defined(_POSIX_V6_ILP32_OFFBIG) || defined(_POSIX_V6_ILP32_OFF32)
	// long is 32 bits.
	#define POV_LONG long long
#else
	// Unable to detect long size at compile-time, assuming less than 64 bits.
	#define POV_LONG long long
#endif

// The following macros are deliberately left undefined; POV-Ray will use boost as a fallback there:
//  DECLARE_THREAD_LOCAL_PTR(ptrType, ptrName)
//  IMPLEMENT_THREAD_LOCAL_PTR(ptrType, ptrName, ignore)
//  GET_THREAD_LOCAL_PTR(ptrName)
//  SET_THREAD_LOCAL_PTR(ptrName, ptrValue)

#endif
