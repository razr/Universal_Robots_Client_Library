// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// Copyright 2022 FZI Forschungszentrum Informatik
// Created on behalf of Universal Robots A/S
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Felix Exner exner@fzi.de
 * \date    2022-12-15
 *
 */
//----------------------------------------------------------------------

#ifndef UR_CLIENT_LIBRARY_HELPERS_H_INCLUDED
#define UR_CLIENT_LIBRARY_HELPERS_H_INCLUDED

#ifdef _WIN32

#  define NOMINMAX
#  define WIN32_LEAN_AND_MEAN
#  include <Windows.h>

#  ifdef ERROR
#    undef ERROR
#  endif  // ERROR

#  define SCHED_FIFO (1)

typedef HANDLE pthread_t;

static inline pthread_t pthread_self()
{
  return ::GetCurrentThread();
}

static inline int sched_get_priority_max(int policy)
{
  (void)policy;
  return THREAD_PRIORITY_TIME_CRITICAL;
}

#else  // _WIN32

#  include <pthread.h>

#endif  // _WIN32

namespace urcl
{
bool setFiFoScheduling(pthread_t& thread, const int priority);
}
#endif  // ifndef UR_CLIENT_LIBRARY_HELPERS_H_INCLUDED
