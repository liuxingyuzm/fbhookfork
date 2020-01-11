/**
 * Copyright 2004-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "../fb/fbassert.h"

// The verify_dummy function stops GCC complaining about values
// computed and not used in VERIFY.
static inline void verify_dummy(bool b) {}
#ifdef NDEBUG
#define VERIFY(e) (verify_dummy(e), true)
#else
#define VERIFY(e) (assert((e)), verify_dummy(true))
#endif