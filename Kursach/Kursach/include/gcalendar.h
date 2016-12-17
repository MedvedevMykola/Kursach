/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GCALENDAR_H_
#define _INGOOGLE_GCALENDAR_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//GCalACLRole
#define GCAR_NONE                                          0
#define GCAR_FREE_BUSY_READER                              1
#define GCAR_READER                                        2
#define GCAR_WRITER                                        3
#define GCAR_OWNER                                         4

//GCalACLScopeType
#define GCAST_DEFAULT                                      0
#define GCAST_USER                                         1
#define GCAST_GROUP                                        2
#define GCAST_DOMAIN                                       3

//GCalAccessRole
#define GCACR_FREE_BUSY_READER                             0
#define GCACR_READER                                       1
#define GCACR_WRITER                                       2
#define GCACR_OWNER                                        3

//GEventReminderMethod
#define GERM_EMAIL                                         0
#define GERM_SMS                                           1
#define GERM_POPUP                                         2

//GCalOperationScope
#define GCOS_CALENDARS                                     0
#define GCOS_CALENDAR_LIST                                 1

//GATTStatuses
#define GAS_NEEDS_ACTION                                   0
#define GAS_DECLINED                                       1
#define GAS_TENTATIVE                                      2
#define GAS_ACCEPTED                                       3

//GCalStatuses
#define GCS_CONFIRMED                                      0
#define GCS_TENTATIVE                                      1
#define GCS_CANCELED                                       2

//FirewallTypes
#define FW_NONE                                            0
#define FW_TUNNEL                                          1
#define FW_SOCKS4                                          2
#define FW_SOCKS5                                          3

//AuthSchemes
#define AUTH_BASIC                                         0
#define AUTH_DIGEST                                        1
#define AUTH_PROPRIETARY                                   2
#define AUTH_NONE                                          3
#define AUTH_NTLM                                          4
#define AUTH_NEGOTIATE                                     5

//ProxySSLTypes
#define PS_AUTOMATIC                                       0
#define PS_ALWAYS                                          1
#define PS_NEVER                                           2
#define PS_TUNNEL                                          3

//CertStoreTypes
#define CST_USER                                           0
#define CST_MACHINE                                        1
#define CST_PFXFILE                                        2
#define CST_PFXBLOB                                        3
#define CST_JKSFILE                                        4
#define CST_JKSBLOB                                        5
#define CST_PEMKEY_FILE                                    6
#define CST_PEMKEY_BLOB                                    7
#define CST_PUBLIC_KEY_FILE                                8
#define CST_PUBLIC_KEY_BLOB                                9
#define CST_SSHPUBLIC_KEY_BLOB                             10
#define CST_P7BFILE                                        11
#define CST_P7BBLOB                                        12
#define CST_SSHPUBLIC_KEY_FILE                             13
#define CST_PPKFILE                                        14
#define CST_PPKBLOB                                        15
#define CST_XMLFILE                                        16
#define CST_XMLBLOB                                        17


extern "C" void* INGOOGLE_CALL InGoogle_GCalendar_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GCalendar_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GCalendar_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GCalendar_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* Id;
  const char* ETag;
  int ScopeType;
  const char* ScopeValue;
  int Role;
  int reserved;
} GCalendarACLRuleListEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* Summary;
  const char* Description;
  const char* Location;
  const char* TimeZone;
  int reserved;
} GCalendarCalendarListEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GCalendarConnectedEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GCalendarDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GCalendarEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GCalendarErrorEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* Summary;
  const char* Description;
  const char* Location;
  const char* StartTime;
  const char* EndTime;
  int reserved;
} GCalendarEventListEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GCalendarHeaderEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GCalendarSetCookieEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GCalendarSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GCalendarSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GCalendarStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GCalendarStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GCalendarTransferEventParams;



class GCalendar {
  
  public: //events
  
    virtual int FireACLRuleList(GCalendarACLRuleListEventParams *e) {return 0;}
    virtual int FireCalendarList(GCalendarCalendarListEventParams *e) {return 0;}
    virtual int FireConnected(GCalendarConnectedEventParams *e) {return 0;}
    virtual int FireDisconnected(GCalendarDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GCalendarEndTransferEventParams *e) {return 0;}
    virtual int FireError(GCalendarErrorEventParams *e) {return 0;}
    virtual int FireEventList(GCalendarEventListEventParams *e) {return 0;}
    virtual int FireHeader(GCalendarHeaderEventParams *e) {return 0;}
    virtual int FireSetCookie(GCalendarSetCookieEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GCalendarSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GCalendarSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GCalendarStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GCalendarStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GCalendarTransferEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GCalendarEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GCalendar*)lpObj)->GCalendarEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GCalendarACLRuleListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]),  0};
            ret_code = ((GCalendar*)lpObj)->FireACLRuleList(&e);
            break;
         }
         case 2: {
            GCalendarCalendarListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]),  0};
            ret_code = ((GCalendar*)lpObj)->FireCalendarList(&e);
            break;
         }
         case 3: {
            GCalendarConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GCalendar*)lpObj)->FireConnected(&e);
            break;
         }
         case 4: {
            GCalendarDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GCalendar*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 5: {
            GCalendarEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GCalendar*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 6: {
            GCalendarErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GCalendar*)lpObj)->FireError(&e);
            break;
         }
         case 7: {
            GCalendarEventListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]),  0};
            ret_code = ((GCalendar*)lpObj)->FireEventList(&e);
            break;
         }
         case 8: {
            GCalendarHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GCalendar*)lpObj)->FireHeader(&e);
            break;
         }
         case 9: {
            GCalendarSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GCalendar*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 10: {
            GCalendarSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GCalendar*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 11: {
            GCalendarSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GCalendar*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 12: {
            GCalendarStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GCalendar*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 13: {
            GCalendarStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GCalendar*)lpObj)->FireStatus(&e);
            break;
         }
         case 14: {
            GCalendarTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GCalendar*)lpObj)->FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GCalendarEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GCalendar(char *lpOemKey = (char*)INGOOGLE_OEMKEY_40) {
      m_pObj = InGoogle_GCalendar_Create(GCalendarEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GCalendar() {
      InGoogle_GCalendar_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GCalendar_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GCalendar_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GCalendar_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline int GetACLRuleCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 1, 0, 0);
      return (int)(long)val;
    }

    inline char* GetACLRuleETag() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }


    inline char* GetACLRuleId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 3, 0, 0);
      return (char*)val;
    }

    inline int SetACLRuleId(const char *lpACLRuleId) {
      return InGoogle_GCalendar_Set(m_pObj, 3, 0, (void*)lpACLRuleId, 0);
    }

    inline int GetACLRuleIndex() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 4, 0, 0);
      return (int)(long)val;
    }
    inline int SetACLRuleIndex(int iACLRuleIndex) {
      void* val = (void*)IBG64CAST(iACLRuleIndex);
      return InGoogle_GCalendar_Set(m_pObj, 4, 0, val, 0);
    }
    inline char* GetACLRuleMarker() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 5, 0, 0);
      return (char*)val;
    }


    inline int GetACLRuleRole() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 6, 0, 0);
      return (int)(long)val;
    }
    inline int SetACLRuleRole(int iACLRuleRole) {
      void* val = (void*)IBG64CAST(iACLRuleRole);
      return InGoogle_GCalendar_Set(m_pObj, 6, 0, val, 0);
    }
    inline int GetACLRuleScopeType() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 7, 0, 0);
      return (int)(long)val;
    }
    inline int SetACLRuleScopeType(int iACLRuleScopeType) {
      void* val = (void*)IBG64CAST(iACLRuleScopeType);
      return InGoogle_GCalendar_Set(m_pObj, 7, 0, val, 0);
    }
    inline char* GetACLRuleScopeValue() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 8, 0, 0);
      return (char*)val;
    }

    inline int SetACLRuleScopeValue(const char *lpACLRuleScopeValue) {
      return InGoogle_GCalendar_Set(m_pObj, 8, 0, (void*)lpACLRuleScopeValue, 0);
    }

    inline char* GetAuthorization() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 9, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GCalendar_Set(m_pObj, 9, 0, (void*)lpAuthorization, 0);
    }

    inline int GetCalendarAccessRole() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 10, 0, 0);
      return (int)(long)val;
    }

    inline int GetCalendarCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 11, 0, 0);
      return (int)(long)val;
    }

    inline int GetCalendarDefaultReminderCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 12, 0, 0);
      return (int)(long)val;
    }
    inline int SetCalendarDefaultReminderCount(int iCalendarDefaultReminderCount) {
      void* val = (void*)IBG64CAST(iCalendarDefaultReminderCount);
      return InGoogle_GCalendar_Set(m_pObj, 12, 0, val, 0);
    }
    inline int GetCalendarDefaultReminderMethod(int iCalendarDefaultReminderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 13, iCalendarDefaultReminderIndex, 0);
      return (int)(long)val;
    }
    inline int SetCalendarDefaultReminderMethod(int iCalendarDefaultReminderIndex, int iCalendarDefaultReminderMethod) {
      void* val = (void*)IBG64CAST(iCalendarDefaultReminderMethod);
      return InGoogle_GCalendar_Set(m_pObj, 13, iCalendarDefaultReminderIndex, val, 0);
    }
    inline int GetCalendarDefaultReminderMinutes(int iCalendarDefaultReminderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 14, iCalendarDefaultReminderIndex, 0);
      return (int)(long)val;
    }
    inline int SetCalendarDefaultReminderMinutes(int iCalendarDefaultReminderIndex, int iCalendarDefaultReminderMinutes) {
      void* val = (void*)IBG64CAST(iCalendarDefaultReminderMinutes);
      return InGoogle_GCalendar_Set(m_pObj, 14, iCalendarDefaultReminderIndex, val, 0);
    }
    inline char* GetCalendarDescription() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 15, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarDescription(const char *lpCalendarDescription) {
      return InGoogle_GCalendar_Set(m_pObj, 15, 0, (void*)lpCalendarDescription, 0);
    }

    inline char* GetCalendarETag() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 16, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarETag(const char *lpCalendarETag) {
      return InGoogle_GCalendar_Set(m_pObj, 16, 0, (void*)lpCalendarETag, 0);
    }

    inline char* GetCalendarId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 17, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarId(const char *lpCalendarId) {
      return InGoogle_GCalendar_Set(m_pObj, 17, 0, (void*)lpCalendarId, 0);
    }

    inline int GetCalendarIndex() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 18, 0, 0);
      return (int)(long)val;
    }
    inline int SetCalendarIndex(int iCalendarIndex) {
      void* val = (void*)IBG64CAST(iCalendarIndex);
      return InGoogle_GCalendar_Set(m_pObj, 18, 0, val, 0);
    }
    inline char* GetCalendarLocation() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 19, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarLocation(const char *lpCalendarLocation) {
      return InGoogle_GCalendar_Set(m_pObj, 19, 0, (void*)lpCalendarLocation, 0);
    }

    inline char* GetCalendarMarker() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 20, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarMarker(const char *lpCalendarMarker) {
      return InGoogle_GCalendar_Set(m_pObj, 20, 0, (void*)lpCalendarMarker, 0);
    }

    inline int GetCalendarOperationScope() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 21, 0, 0);
      return (int)(long)val;
    }
    inline int SetCalendarOperationScope(int iCalendarOperationScope) {
      void* val = (void*)IBG64CAST(iCalendarOperationScope);
      return InGoogle_GCalendar_Set(m_pObj, 21, 0, val, 0);
    }
    inline int GetCalendarPrimary() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 22, 0, 0);
      return (int)(long)val;
    }

    inline char* GetCalendarSummary() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 23, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarSummary(const char *lpCalendarSummary) {
      return InGoogle_GCalendar_Set(m_pObj, 23, 0, (void*)lpCalendarSummary, 0);
    }

    inline char* GetCalendarTimezone() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }

    inline int SetCalendarTimezone(const char *lpCalendarTimezone) {
      return InGoogle_GCalendar_Set(m_pObj, 24, 0, (void*)lpCalendarTimezone, 0);
    }

    inline int GetCookieCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 25, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GCalendar_Set(m_pObj, 25, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 26, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 27, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 28, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GCalendar_Set(m_pObj, 28, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 29, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 30, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 31, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GCalendar_Set(m_pObj, 31, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline int GetEventAttendeeCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 32, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeCount(int iEventAttendeeCount) {
      void* val = (void*)IBG64CAST(iEventAttendeeCount);
      return InGoogle_GCalendar_Set(m_pObj, 32, 0, val, 0);
    }
    inline int GetEventAttendeeAdditionalGuests(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 33, iEventAttendeeIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeAdditionalGuests(int iEventAttendeeIndex, int iEventAttendeeAdditionalGuests) {
      void* val = (void*)IBG64CAST(iEventAttendeeAdditionalGuests);
      return InGoogle_GCalendar_Set(m_pObj, 33, iEventAttendeeIndex, val, 0);
    }
    inline char* GetEventAttendeeComment(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 34, iEventAttendeeIndex, 0);
      return (char*)val;
    }

    inline int SetEventAttendeeComment(int iEventAttendeeIndex, const char *lpEventAttendeeComment) {
      return InGoogle_GCalendar_Set(m_pObj, 34, iEventAttendeeIndex, (void*)lpEventAttendeeComment, 0);
    }

    inline char* GetEventAttendeeDisplayName(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 35, iEventAttendeeIndex, 0);
      return (char*)val;
    }

    inline int SetEventAttendeeDisplayName(int iEventAttendeeIndex, const char *lpEventAttendeeDisplayName) {
      return InGoogle_GCalendar_Set(m_pObj, 35, iEventAttendeeIndex, (void*)lpEventAttendeeDisplayName, 0);
    }

    inline char* GetEventAttendeeEmail(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 36, iEventAttendeeIndex, 0);
      return (char*)val;
    }

    inline int SetEventAttendeeEmail(int iEventAttendeeIndex, const char *lpEventAttendeeEmail) {
      return InGoogle_GCalendar_Set(m_pObj, 36, iEventAttendeeIndex, (void*)lpEventAttendeeEmail, 0);
    }

    inline char* GetEventAttendeeId(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 37, iEventAttendeeIndex, 0);
      return (char*)val;
    }

    inline int SetEventAttendeeId(int iEventAttendeeIndex, const char *lpEventAttendeeId) {
      return InGoogle_GCalendar_Set(m_pObj, 37, iEventAttendeeIndex, (void*)lpEventAttendeeId, 0);
    }

    inline int GetEventAttendeeOptional(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 38, iEventAttendeeIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeOptional(int iEventAttendeeIndex, int bEventAttendeeOptional) {
      void* val = (void*)IBG64CAST(bEventAttendeeOptional);
      return InGoogle_GCalendar_Set(m_pObj, 38, iEventAttendeeIndex, val, 0);
    }
    inline int GetEventAttendeeOrganizer(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 39, iEventAttendeeIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeOrganizer(int iEventAttendeeIndex, int bEventAttendeeOrganizer) {
      void* val = (void*)IBG64CAST(bEventAttendeeOrganizer);
      return InGoogle_GCalendar_Set(m_pObj, 39, iEventAttendeeIndex, val, 0);
    }
    inline int GetEventAttendeeResource(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 40, iEventAttendeeIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeResource(int iEventAttendeeIndex, int bEventAttendeeResource) {
      void* val = (void*)IBG64CAST(bEventAttendeeResource);
      return InGoogle_GCalendar_Set(m_pObj, 40, iEventAttendeeIndex, val, 0);
    }
    inline int GetEventAttendeeStatus(int iEventAttendeeIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 41, iEventAttendeeIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventAttendeeStatus(int iEventAttendeeIndex, int iEventAttendeeStatus) {
      void* val = (void*)IBG64CAST(iEventAttendeeStatus);
      return InGoogle_GCalendar_Set(m_pObj, 41, iEventAttendeeIndex, val, 0);
    }
    inline int GetEventBusy() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 42, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventBusy(int bEventBusy) {
      void* val = (void*)IBG64CAST(bEventBusy);
      return InGoogle_GCalendar_Set(m_pObj, 42, 0, val, 0);
    }
    inline int GetEventCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 43, 0, 0);
      return (int)(long)val;
    }

    inline char* GetEventCreatorEmail() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 44, 0, 0);
      return (char*)val;
    }


    inline char* GetEventCreatorId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }


    inline char* GetEventCreatorName() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 46, 0, 0);
      return (char*)val;
    }


    inline int GetEventCustomReminderCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 47, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventCustomReminderCount(int iEventCustomReminderCount) {
      void* val = (void*)IBG64CAST(iEventCustomReminderCount);
      return InGoogle_GCalendar_Set(m_pObj, 47, 0, val, 0);
    }
    inline int GetEventCustomReminderMethod(int iEventCustomReminderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 48, iEventCustomReminderIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventCustomReminderMethod(int iEventCustomReminderIndex, int iEventCustomReminderMethod) {
      void* val = (void*)IBG64CAST(iEventCustomReminderMethod);
      return InGoogle_GCalendar_Set(m_pObj, 48, iEventCustomReminderIndex, val, 0);
    }
    inline int GetEventCustomReminderMinutes(int iEventCustomReminderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 49, iEventCustomReminderIndex, 0);
      return (int)(long)val;
    }
    inline int SetEventCustomReminderMinutes(int iEventCustomReminderIndex, int iEventCustomReminderMinutes) {
      void* val = (void*)IBG64CAST(iEventCustomReminderMinutes);
      return InGoogle_GCalendar_Set(m_pObj, 49, iEventCustomReminderIndex, val, 0);
    }
    inline char* GetEventDateCreated() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 50, 0, 0);
      return (char*)val;
    }


    inline char* GetEventDateUpdated() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 51, 0, 0);
      return (char*)val;
    }


    inline char* GetEventDescription() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 52, 0, 0);
      return (char*)val;
    }

    inline int SetEventDescription(const char *lpEventDescription) {
      return InGoogle_GCalendar_Set(m_pObj, 52, 0, (void*)lpEventDescription, 0);
    }

    inline char* GetEventEndDate() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }

    inline int SetEventEndDate(const char *lpEventEndDate) {
      return InGoogle_GCalendar_Set(m_pObj, 53, 0, (void*)lpEventEndDate, 0);
    }

    inline char* GetEventEndDateTime() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 54, 0, 0);
      return (char*)val;
    }

    inline int SetEventEndDateTime(const char *lpEventEndDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 54, 0, (void*)lpEventEndDateTime, 0);
    }

    inline char* GetEventEndTimeZone() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 55, 0, 0);
      return (char*)val;
    }

    inline int SetEventEndTimeZone(const char *lpEventEndTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 55, 0, (void*)lpEventEndTimeZone, 0);
    }

    inline char* GetEventETag() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 56, 0, 0);
      return (char*)val;
    }

    inline int SetEventETag(const char *lpEventETag) {
      return InGoogle_GCalendar_Set(m_pObj, 56, 0, (void*)lpEventETag, 0);
    }

    inline char* GetEventICalUID() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 57, 0, 0);
      return (char*)val;
    }

    inline int SetEventICalUID(const char *lpEventICalUID) {
      return InGoogle_GCalendar_Set(m_pObj, 57, 0, (void*)lpEventICalUID, 0);
    }

    inline char* GetEventId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }

    inline int SetEventId(const char *lpEventId) {
      return InGoogle_GCalendar_Set(m_pObj, 58, 0, (void*)lpEventId, 0);
    }

    inline int GetEventIndex() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 59, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventIndex(int iEventIndex) {
      void* val = (void*)IBG64CAST(iEventIndex);
      return InGoogle_GCalendar_Set(m_pObj, 59, 0, val, 0);
    }
    inline char* GetEventLocation() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 60, 0, 0);
      return (char*)val;
    }

    inline int SetEventLocation(const char *lpEventLocation) {
      return InGoogle_GCalendar_Set(m_pObj, 60, 0, (void*)lpEventLocation, 0);
    }

    inline int GetEventLocked() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 61, 0, 0);
      return (int)(long)val;
    }

    inline char* GetEventMarker() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 62, 0, 0);
      return (char*)val;
    }

    inline int SetEventMarker(const char *lpEventMarker) {
      return InGoogle_GCalendar_Set(m_pObj, 62, 0, (void*)lpEventMarker, 0);
    }

    inline char* GetEventOrganizerEmail() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 63, 0, 0);
      return (char*)val;
    }


    inline char* GetEventOrganizerId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 64, 0, 0);
      return (char*)val;
    }


    inline char* GetEventOrganizerName() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 65, 0, 0);
      return (char*)val;
    }


    inline char* GetEventOriginalStartDate() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 66, 0, 0);
      return (char*)val;
    }

    inline int SetEventOriginalStartDate(const char *lpEventOriginalStartDate) {
      return InGoogle_GCalendar_Set(m_pObj, 66, 0, (void*)lpEventOriginalStartDate, 0);
    }

    inline char* GetEventOriginalStartDateTime() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 67, 0, 0);
      return (char*)val;
    }

    inline int SetEventOriginalStartDateTime(const char *lpEventOriginalStartDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 67, 0, (void*)lpEventOriginalStartDateTime, 0);
    }

    inline char* GetEventOriginalStartTimeZone() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 68, 0, 0);
      return (char*)val;
    }

    inline int SetEventOriginalStartTimeZone(const char *lpEventOriginalStartTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 68, 0, (void*)lpEventOriginalStartTimeZone, 0);
    }

    inline char* GetEventRecurrenceDates() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 69, 0, 0);
      return (char*)val;
    }

    inline int SetEventRecurrenceDates(const char *lpEventRecurrenceDates) {
      return InGoogle_GCalendar_Set(m_pObj, 69, 0, (void*)lpEventRecurrenceDates, 0);
    }

    inline char* GetEventRecurrenceExceptionDates() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 70, 0, 0);
      return (char*)val;
    }

    inline int SetEventRecurrenceExceptionDates(const char *lpEventRecurrenceExceptionDates) {
      return InGoogle_GCalendar_Set(m_pObj, 70, 0, (void*)lpEventRecurrenceExceptionDates, 0);
    }

    inline char* GetEventRecurrenceExceptionRule() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 71, 0, 0);
      return (char*)val;
    }

    inline int SetEventRecurrenceExceptionRule(const char *lpEventRecurrenceExceptionRule) {
      return InGoogle_GCalendar_Set(m_pObj, 71, 0, (void*)lpEventRecurrenceExceptionRule, 0);
    }

    inline char* GetEventRecurrenceRule() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 72, 0, 0);
      return (char*)val;
    }

    inline int SetEventRecurrenceRule(const char *lpEventRecurrenceRule) {
      return InGoogle_GCalendar_Set(m_pObj, 72, 0, (void*)lpEventRecurrenceRule, 0);
    }

    inline char* GetEventRecurringId() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 73, 0, 0);
      return (char*)val;
    }


    inline char* GetEventStartDate() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 74, 0, 0);
      return (char*)val;
    }

    inline int SetEventStartDate(const char *lpEventStartDate) {
      return InGoogle_GCalendar_Set(m_pObj, 74, 0, (void*)lpEventStartDate, 0);
    }

    inline char* GetEventStartDateTime() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 75, 0, 0);
      return (char*)val;
    }

    inline int SetEventStartDateTime(const char *lpEventStartDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 75, 0, (void*)lpEventStartDateTime, 0);
    }

    inline char* GetEventStartTimeZone() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 76, 0, 0);
      return (char*)val;
    }

    inline int SetEventStartTimeZone(const char *lpEventStartTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 76, 0, (void*)lpEventStartTimeZone, 0);
    }

    inline int GetEventStatus() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 77, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventStatus(int iEventStatus) {
      void* val = (void*)IBG64CAST(iEventStatus);
      return InGoogle_GCalendar_Set(m_pObj, 77, 0, val, 0);
    }
    inline char* GetEventSummary() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 78, 0, 0);
      return (char*)val;
    }

    inline int SetEventSummary(const char *lpEventSummary) {
      return InGoogle_GCalendar_Set(m_pObj, 78, 0, (void*)lpEventSummary, 0);
    }

    inline int GetEventUseDefaultReminders() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 79, 0, 0);
      return (int)(long)val;
    }
    inline int SetEventUseDefaultReminders(int bEventUseDefaultReminders) {
      void* val = (void*)IBG64CAST(bEventUseDefaultReminders);
      return InGoogle_GCalendar_Set(m_pObj, 79, 0, val, 0);
    }
    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 80, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GCalendar_Set(m_pObj, 80, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 81, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GCalendar_Set(m_pObj, 81, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 82, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GCalendar_Set(m_pObj, 82, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 83, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GCalendar_Set(m_pObj, 83, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 84, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GCalendar_Set(m_pObj, 84, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 85, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GCalendar_Set(m_pObj, 85, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 86, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 87, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GCalendar_Set(m_pObj, 87, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 88, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GCalendar_Set(m_pObj, 88, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 89, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 90, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 91, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 92, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GCalendar_Set(m_pObj, 92, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 93, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GCalendar_Set(m_pObj, 93, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 94, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GCalendar_Set(m_pObj, 94, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 95, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GCalendar_Set(m_pObj, 95, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 96, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GCalendar_Set(m_pObj, 96, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 97, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GCalendar_Set(m_pObj, 97, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 98, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GCalendar_Set(m_pObj, 98, 0, (void*)lpProxyUser, 0);
    }

    inline int GetQueryParamsCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 99, 0, 0);
      return (int)(long)val;
    }
    inline int SetQueryParamsCount(int iQueryParamsCount) {
      void* val = (void*)IBG64CAST(iQueryParamsCount);
      return InGoogle_GCalendar_Set(m_pObj, 99, 0, val, 0);
    }
    inline char* GetQueryParamsName(int iQueryParamsIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 100, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, const char *lpQueryParamsName) {
      return InGoogle_GCalendar_Set(m_pObj, 100, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline char* GetQueryParamsValue(int iQueryParamsIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 101, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, const char *lpQueryParamsValue) {
      return InGoogle_GCalendar_Set(m_pObj, 101, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 102, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 102, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 103, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 103, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GCalendar_Get(m_pObj, 104, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GCalendar_Set(m_pObj, 104, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 105, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GCalendar_Set(m_pObj, 105, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 106, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GCalendar_Set(m_pObj, 106, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 107, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GCalendar_Set(m_pObj, 107, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 108, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 109, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GCalendar_Set(m_pObj, 109, 0, val, 0);
    }
    inline int GetXChildrenCount() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 110, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 111, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GCalendar_Get(m_pObj, 112, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 113, 0, 0);
      return (char*)val;
    }


    inline char* GetXParent() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 114, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 115, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GCalendar_Set(m_pObj, 115, 0, (void*)lpXPath, 0);
    }

    inline char* GetXSubTree() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 116, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GCalendar_Get(m_pObj, 117, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline int AddQueryParam(const char* lpszname, const char* lpszvalue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszname), (void*)IBG64CAST(lpszvalue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline int ClearCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 3, 0, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GCalendar_Do(m_pObj, 4, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline char* CreateACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 5, 0, param, cbparam);
      
      return (char*)IBG64CAST(param[0]);
    }
    inline char* CreateCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 6, 0, param, cbparam);
      
      return (char*)IBG64CAST(param[0]);
    }
    inline char* CreateEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 7, 0, param, cbparam);
      
      return (char*)IBG64CAST(param[0]);
    }
    inline int DeleteACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 8, 0, param, cbparam);
      
      
    }
    inline int DeleteCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline int DeleteEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10, 0, param, cbparam);
      
      
    }
    inline int GetACLRule(const char* lpszruleId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszruleId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 11, 1, param, cbparam);
      
      
    }
    inline int GetCalendar(const char* lpszcalendarId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszcalendarId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 12, 1, param, cbparam);
      
      
    }
    inline int GetEvent(const char* lpszeventId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszeventId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 13, 1, param, cbparam);
      
      
    }
    inline int ImportEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 14, 0, param, cbparam);
      
      
    }
    inline int ListACLRules() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 15, 0, param, cbparam);
      
      
    }
    inline int ListCalendars() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 16, 0, param, cbparam);
      
      
    }
    inline int ListEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 17, 0, param, cbparam);
      
      
    }
    inline int ListRecurringEventInstances() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 18, 0, param, cbparam);
      
      
    }
    inline int MoveEvent(const char* lpszdestinationCalendarId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszdestinationCalendarId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 19, 1, param, cbparam);
      
      
    }
    inline char* QuickAdd(const char* lpszeventDetails) {
      void *param[1+1] = {(void*)IBG64CAST(lpszeventDetails), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GCalendar_Do(m_pObj, 20, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int UpdateACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 21, 0, param, cbparam);
      
      
    }
    inline int UpdateCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 22, 0, param, cbparam);
      
      
    }
    inline int UpdateEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 23, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  int ScopeType;
  LPWSTR ScopeValue;
  int Role;
  int reserved;
} GCalendarACLRuleListEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR Summary;
  LPWSTR Description;
  LPWSTR Location;
  LPWSTR TimeZone;
  int reserved;
} GCalendarCalendarListEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GCalendarConnectedEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GCalendarDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GCalendarEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GCalendarErrorEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR Summary;
  LPWSTR Description;
  LPWSTR Location;
  LPWSTR StartTime;
  LPWSTR EndTime;
  int reserved;
} GCalendarEventListEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GCalendarHeaderEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GCalendarSetCookieEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GCalendarSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GCalendarSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GCalendarStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GCalendarStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GCalendarTransferEventParamsW;



class GCalendarW : public GCalendar {

  public: //properties
  


    inline LPWSTR GetACLRuleETag() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+2, 0, 0);
    }



    inline LPWSTR GetACLRuleId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+3, 0, 0);
    }

    inline int SetACLRuleId(LPWSTR lpACLRuleId) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+3, 0, (void*)lpACLRuleId, 0);
    }



    inline LPWSTR GetACLRuleMarker() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+5, 0, 0);
    }







    inline LPWSTR GetACLRuleScopeValue() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+8, 0, 0);
    }

    inline int SetACLRuleScopeValue(LPWSTR lpACLRuleScopeValue) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+8, 0, (void*)lpACLRuleScopeValue, 0);
    }

    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+9, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+9, 0, (void*)lpAuthorization, 0);
    }











    inline LPWSTR GetCalendarDescription() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+15, 0, 0);
    }

    inline int SetCalendarDescription(LPWSTR lpCalendarDescription) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+15, 0, (void*)lpCalendarDescription, 0);
    }

    inline LPWSTR GetCalendarETag() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+16, 0, 0);
    }

    inline int SetCalendarETag(LPWSTR lpCalendarETag) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+16, 0, (void*)lpCalendarETag, 0);
    }

    inline LPWSTR GetCalendarId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+17, 0, 0);
    }

    inline int SetCalendarId(LPWSTR lpCalendarId) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+17, 0, (void*)lpCalendarId, 0);
    }



    inline LPWSTR GetCalendarLocation() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+19, 0, 0);
    }

    inline int SetCalendarLocation(LPWSTR lpCalendarLocation) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+19, 0, (void*)lpCalendarLocation, 0);
    }

    inline LPWSTR GetCalendarMarker() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+20, 0, 0);
    }

    inline int SetCalendarMarker(LPWSTR lpCalendarMarker) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+20, 0, (void*)lpCalendarMarker, 0);
    }





    inline LPWSTR GetCalendarSummary() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+23, 0, 0);
    }

    inline int SetCalendarSummary(LPWSTR lpCalendarSummary) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+23, 0, (void*)lpCalendarSummary, 0);
    }

    inline LPWSTR GetCalendarTimezone() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+24, 0, 0);
    }

    inline int SetCalendarTimezone(LPWSTR lpCalendarTimezone) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+24, 0, (void*)lpCalendarTimezone, 0);
    }



    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+26, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+27, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+28, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+28, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+29, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+31, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+31, iCookieIndex, (void*)lpCookieValue, 0);
    }





    inline LPWSTR GetEventAttendeeComment(int iEventAttendeeIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+34, iEventAttendeeIndex, 0);
    }

    inline int SetEventAttendeeComment(int iEventAttendeeIndex, LPWSTR lpEventAttendeeComment) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+34, iEventAttendeeIndex, (void*)lpEventAttendeeComment, 0);
    }

    inline LPWSTR GetEventAttendeeDisplayName(int iEventAttendeeIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+35, iEventAttendeeIndex, 0);
    }

    inline int SetEventAttendeeDisplayName(int iEventAttendeeIndex, LPWSTR lpEventAttendeeDisplayName) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+35, iEventAttendeeIndex, (void*)lpEventAttendeeDisplayName, 0);
    }

    inline LPWSTR GetEventAttendeeEmail(int iEventAttendeeIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+36, iEventAttendeeIndex, 0);
    }

    inline int SetEventAttendeeEmail(int iEventAttendeeIndex, LPWSTR lpEventAttendeeEmail) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+36, iEventAttendeeIndex, (void*)lpEventAttendeeEmail, 0);
    }

    inline LPWSTR GetEventAttendeeId(int iEventAttendeeIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+37, iEventAttendeeIndex, 0);
    }

    inline int SetEventAttendeeId(int iEventAttendeeIndex, LPWSTR lpEventAttendeeId) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+37, iEventAttendeeIndex, (void*)lpEventAttendeeId, 0);
    }













    inline LPWSTR GetEventCreatorEmail() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+44, 0, 0);
    }



    inline LPWSTR GetEventCreatorId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+45, 0, 0);
    }



    inline LPWSTR GetEventCreatorName() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+46, 0, 0);
    }









    inline LPWSTR GetEventDateCreated() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+50, 0, 0);
    }



    inline LPWSTR GetEventDateUpdated() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+51, 0, 0);
    }



    inline LPWSTR GetEventDescription() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+52, 0, 0);
    }

    inline int SetEventDescription(LPWSTR lpEventDescription) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+52, 0, (void*)lpEventDescription, 0);
    }

    inline LPWSTR GetEventEndDate() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+53, 0, 0);
    }

    inline int SetEventEndDate(LPWSTR lpEventEndDate) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+53, 0, (void*)lpEventEndDate, 0);
    }

    inline LPWSTR GetEventEndDateTime() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+54, 0, 0);
    }

    inline int SetEventEndDateTime(LPWSTR lpEventEndDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+54, 0, (void*)lpEventEndDateTime, 0);
    }

    inline LPWSTR GetEventEndTimeZone() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+55, 0, 0);
    }

    inline int SetEventEndTimeZone(LPWSTR lpEventEndTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+55, 0, (void*)lpEventEndTimeZone, 0);
    }

    inline LPWSTR GetEventETag() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+56, 0, 0);
    }

    inline int SetEventETag(LPWSTR lpEventETag) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+56, 0, (void*)lpEventETag, 0);
    }

    inline LPWSTR GetEventICalUID() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+57, 0, 0);
    }

    inline int SetEventICalUID(LPWSTR lpEventICalUID) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+57, 0, (void*)lpEventICalUID, 0);
    }

    inline LPWSTR GetEventId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+58, 0, 0);
    }

    inline int SetEventId(LPWSTR lpEventId) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+58, 0, (void*)lpEventId, 0);
    }



    inline LPWSTR GetEventLocation() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+60, 0, 0);
    }

    inline int SetEventLocation(LPWSTR lpEventLocation) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+60, 0, (void*)lpEventLocation, 0);
    }



    inline LPWSTR GetEventMarker() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+62, 0, 0);
    }

    inline int SetEventMarker(LPWSTR lpEventMarker) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+62, 0, (void*)lpEventMarker, 0);
    }

    inline LPWSTR GetEventOrganizerEmail() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+63, 0, 0);
    }



    inline LPWSTR GetEventOrganizerId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+64, 0, 0);
    }



    inline LPWSTR GetEventOrganizerName() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+65, 0, 0);
    }



    inline LPWSTR GetEventOriginalStartDate() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+66, 0, 0);
    }

    inline int SetEventOriginalStartDate(LPWSTR lpEventOriginalStartDate) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+66, 0, (void*)lpEventOriginalStartDate, 0);
    }

    inline LPWSTR GetEventOriginalStartDateTime() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+67, 0, 0);
    }

    inline int SetEventOriginalStartDateTime(LPWSTR lpEventOriginalStartDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+67, 0, (void*)lpEventOriginalStartDateTime, 0);
    }

    inline LPWSTR GetEventOriginalStartTimeZone() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+68, 0, 0);
    }

    inline int SetEventOriginalStartTimeZone(LPWSTR lpEventOriginalStartTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+68, 0, (void*)lpEventOriginalStartTimeZone, 0);
    }

    inline LPWSTR GetEventRecurrenceDates() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+69, 0, 0);
    }

    inline int SetEventRecurrenceDates(LPWSTR lpEventRecurrenceDates) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+69, 0, (void*)lpEventRecurrenceDates, 0);
    }

    inline LPWSTR GetEventRecurrenceExceptionDates() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+70, 0, 0);
    }

    inline int SetEventRecurrenceExceptionDates(LPWSTR lpEventRecurrenceExceptionDates) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+70, 0, (void*)lpEventRecurrenceExceptionDates, 0);
    }

    inline LPWSTR GetEventRecurrenceExceptionRule() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+71, 0, 0);
    }

    inline int SetEventRecurrenceExceptionRule(LPWSTR lpEventRecurrenceExceptionRule) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+71, 0, (void*)lpEventRecurrenceExceptionRule, 0);
    }

    inline LPWSTR GetEventRecurrenceRule() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+72, 0, 0);
    }

    inline int SetEventRecurrenceRule(LPWSTR lpEventRecurrenceRule) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+72, 0, (void*)lpEventRecurrenceRule, 0);
    }

    inline LPWSTR GetEventRecurringId() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+73, 0, 0);
    }



    inline LPWSTR GetEventStartDate() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+74, 0, 0);
    }

    inline int SetEventStartDate(LPWSTR lpEventStartDate) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+74, 0, (void*)lpEventStartDate, 0);
    }

    inline LPWSTR GetEventStartDateTime() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+75, 0, 0);
    }

    inline int SetEventStartDateTime(LPWSTR lpEventStartDateTime) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+75, 0, (void*)lpEventStartDateTime, 0);
    }

    inline LPWSTR GetEventStartTimeZone() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+76, 0, 0);
    }

    inline int SetEventStartTimeZone(LPWSTR lpEventStartTimeZone) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+76, 0, (void*)lpEventStartTimeZone, 0);
    }



    inline LPWSTR GetEventSummary() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+78, 0, 0);
    }

    inline int SetEventSummary(LPWSTR lpEventSummary) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+78, 0, (void*)lpEventSummary, 0);
    }







    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+82, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+82, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+83, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+83, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+85, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+85, 0, (void*)lpFirewallUser, 0);
    }



    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+87, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+87, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+88, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+88, 0, (void*)lpOtherHeaders, 0);
    }



    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+90, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+91, iParsedHeaderIndex, 0);
    }







    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+94, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+94, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+96, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+96, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+98, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+98, 0, (void*)lpProxyUser, 0);
    }



    inline LPWSTR GetQueryParamsName(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+100, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, LPWSTR lpQueryParamsName) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+100, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline LPWSTR GetQueryParamsValue(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+101, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, LPWSTR lpQueryParamsValue) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+101, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+102, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+102, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 102, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 102, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+103, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+103, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 103, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GCalendar_Set(m_pObj, 103, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+104, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+104, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GCalendar_Get(m_pObj, 104, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GCalendar_Set(m_pObj, 104, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+105, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+105, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+107, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+107, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+108, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GCalendar_Get(m_pObj, 108, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }





    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+111, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+112, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+113, 0, 0);
    }



    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+114, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+115, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GCalendar_Set(m_pObj, 10000+115, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+116, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GCalendar_Get(m_pObj, 10000+117, 0, 0);
    }





  public: //events
  
    virtual int FireACLRuleList(GCalendarACLRuleListEventParamsW *e) {return 0;}
    virtual int FireCalendarList(GCalendarCalendarListEventParamsW *e) {return 0;}
    virtual int FireConnected(GCalendarConnectedEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GCalendarDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GCalendarEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GCalendarErrorEventParamsW *e) {return 0;}
    virtual int FireEventList(GCalendarEventListEventParamsW *e) {return 0;}
    virtual int FireHeader(GCalendarHeaderEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GCalendarSetCookieEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GCalendarSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GCalendarSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GCalendarStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GCalendarStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GCalendarTransferEventParamsW *e) {return 0;}


  protected:
  
    virtual int GCalendarEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GCalendarACLRuleListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]),  0};
            ret_code = FireACLRuleList(&e);
            break;
         }
         case 2: {
            GCalendarCalendarListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]),  0};
            ret_code = FireCalendarList(&e);
            break;
         }
         case 3: {
            GCalendarConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 4: {
            GCalendarDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 5: {
            GCalendarEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 6: {
            GCalendarErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 7: {
            GCalendarEventListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]),  0};
            ret_code = FireEventList(&e);
            break;
         }
         case 8: {
            GCalendarHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 9: {
            GCalendarSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 10: {
            GCalendarSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 11: {
            GCalendarSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 12: {
            GCalendarStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 13: {
            GCalendarStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 14: {
            GCalendarTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireACLRuleList(GCalendarACLRuleListEventParams *e) {return -10000;}
    virtual int FireCalendarList(GCalendarCalendarListEventParams *e) {return -10000;}
    virtual int FireConnected(GCalendarConnectedEventParams *e) {return -10000;}
    virtual int FireDisconnected(GCalendarDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GCalendarEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GCalendarErrorEventParams *e) {return -10000;}
    virtual int FireEventList(GCalendarEventListEventParams *e) {return -10000;}
    virtual int FireHeader(GCalendarHeaderEventParams *e) {return -10000;}
    virtual int FireSetCookie(GCalendarSetCookieEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GCalendarSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GCalendarSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GCalendarStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GCalendarStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GCalendarTransferEventParams *e) {return -10000;}

  public: //methods

    inline int AddQueryParam(LPWSTR lpszname, LPWSTR lpszvalue) {
      void *param[2+1] = {(void*)lpszname, (void*)lpszvalue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline int ClearCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+3, 0, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GCalendar_Do(m_pObj, 10000+4, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline LPWSTR CreateACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 10000+5, 0, param, cbparam);
      return (LPWSTR)IBG64CAST(param[0]);
    }
    inline LPWSTR CreateCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 10000+6, 0, param, cbparam);
      return (LPWSTR)IBG64CAST(param[0]);
    }
    inline LPWSTR CreateEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GCalendar_Do(m_pObj, 10000+7, 0, param, cbparam);
      return (LPWSTR)IBG64CAST(param[0]);
    }
    inline int DeleteACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+8, 0, param, cbparam);
      
    }
    inline int DeleteCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline int DeleteEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+10, 0, param, cbparam);
      
    }
    inline int GetACLRule(LPWSTR lpszruleId) {
      void *param[1+1] = {(void*)lpszruleId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+11, 1, param, cbparam);
      
    }
    inline int GetCalendar(LPWSTR lpszcalendarId) {
      void *param[1+1] = {(void*)lpszcalendarId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+12, 1, param, cbparam);
      
    }
    inline int GetEvent(LPWSTR lpszeventId) {
      void *param[1+1] = {(void*)lpszeventId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+13, 1, param, cbparam);
      
    }
    inline int ImportEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+14, 0, param, cbparam);
      
    }
    inline int ListACLRules() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+15, 0, param, cbparam);
      
    }
    inline int ListCalendars() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+16, 0, param, cbparam);
      
    }
    inline int ListEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+17, 0, param, cbparam);
      
    }
    inline int ListRecurringEventInstances() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+18, 0, param, cbparam);
      
    }
    inline int MoveEvent(LPWSTR lpszdestinationCalendarId) {
      void *param[1+1] = {(void*)lpszdestinationCalendarId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+19, 1, param, cbparam);
      
    }
    inline LPWSTR QuickAdd(LPWSTR lpszeventDetails) {
      void *param[1+1] = {(void*)lpszeventDetails, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GCalendar_Do(m_pObj, 10000+20, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int UpdateACLRule() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+21, 0, param, cbparam);
      
    }
    inline int UpdateCalendar() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+22, 0, param, cbparam);
      
    }
    inline int UpdateEvent() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GCalendar_Do(m_pObj, 10000+23, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GCALENDAR_H_




