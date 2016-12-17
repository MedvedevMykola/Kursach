// Google Integrator V2 C++ Edition - C++ Interface
//
// Copyright (c) 2016 /n software inc. - All rights reserved.
//

#ifndef _INGOOGLE_H_
#define _INGOOGLE_H_
  
#ifdef WIN32
#define INGOOGLE_CALL __stdcall
#else //UNIX
#define INGOOGLE_CALL
#endif

#if defined(_MSC_VER) || defined(__BORLANDC__)
  typedef __int64 ns_int64;
  typedef unsigned __int64 ns_uint64;
#else
  typedef long long int ns_int64;
  typedef unsigned long long int ns_uint64;
#endif


#ifdef UNIX
#if defined(__LP64__) || defined(__x86_64__) || defined(__ia64__) || defined(__amd64__) || defined(__ppc64__)
#ifndef UNIX64
#define UNIX64
#endif
#endif
#endif

#ifndef UNIX64
#define IBG64CAST
#else
#define IBG64CAST (ns_int64)
#endif

typedef int (INGOOGLE_CALL *PINGOOGLE_CALLBACK)
  (void *lpObj, int event_id, int cparam, void *param[], int cbparam[]);

#ifndef INGOOGLE_ONLY_TYPES
#ifdef WIN32

#include "gcalendar.h"
#include "gcontacts.h"
#include "gdata.h"
#include "gdrive.h"
#include "gmail.h"
#include "googlerequest.h"
#include "gspreadsheets.h"
#include "gstorage.h"
#include "oauth.h"


#else //UNIX

#include "gcalendar.h"
#include "gcontacts.h"
#include "gdata.h"
#include "gdrive.h"
#include "gmail.h"
#include "googlerequest.h"
#include "gspreadsheets.h"
#include "gstorage.h"
#include "oauth.h"


#endif
#endif //INGOOGLE_ONLY_TYPES

#endif //_INGOOGLE_H_


