/*
 *  practice.cp
 *  practice
 *
 *  Created by njindal on 9/26/15.
 *  Copyright (c) 2015 njindal. All rights reserved.
 *
 */

#include "practice.h"
#include "practicePriv.h"

CFStringRef practiceUUID(void)
{
	Cpractice* theObj = new Cpractice;
	return theObj->UUID();
}

CFStringRef Cpractice::UUID()
{
	return CFSTR("0001020304050607");
}
