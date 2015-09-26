/*
 *  practice.h
 *  practice
 *
 *  Created by njindal on 9/26/15.
 *  Copyright (c) 2015 njindal. All rights reserved.
 *
 */

extern "C" {
#include <CoreFoundation/CoreFoundation.h>

#pragma GCC visibility push(default)

/* External interface to the practice, C-based */

CFStringRef practiceUUID(void);

#pragma GCC visibility pop
}
