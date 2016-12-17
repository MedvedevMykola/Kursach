/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GCONTACTS_H_
#define _INGOOGLE_GCONTACTS_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//EntryElementFormats
#define VF_TEXT                                            1
#define VF_FULL_XML                                        2

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


extern "C" void* INGOOGLE_CALL InGoogle_GContacts_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GContacts_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GContacts_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GContacts_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GContactsConnectedEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* FullName;
  const char* Gender;
  const char* WorkAddress;
  const char* WorkEmailAddress;
  const char* WorkPhoneNumber;
  int reserved;
} GContactsContactListEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GContactsDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GContactsEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GContactsErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GContactsHeaderEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GContactsSetCookieEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GContactsSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GContactsSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GContactsStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GContactsStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GContactsTransferEventParams;



class GContacts {
  
  public: //events
  
    virtual int FireConnected(GContactsConnectedEventParams *e) {return 0;}
    virtual int FireContactList(GContactsContactListEventParams *e) {return 0;}
    virtual int FireDisconnected(GContactsDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GContactsEndTransferEventParams *e) {return 0;}
    virtual int FireError(GContactsErrorEventParams *e) {return 0;}
    virtual int FireHeader(GContactsHeaderEventParams *e) {return 0;}
    virtual int FireSetCookie(GContactsSetCookieEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GContactsSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GContactsSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GContactsStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GContactsStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GContactsTransferEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GContactsEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GContacts*)lpObj)->GContactsEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GContactsConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GContacts*)lpObj)->FireConnected(&e);
            break;
         }
         case 2: {
            GContactsContactListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]),  0};
            ret_code = ((GContacts*)lpObj)->FireContactList(&e);
            break;
         }
         case 3: {
            GContactsDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GContacts*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 4: {
            GContactsEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GContacts*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 5: {
            GContactsErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GContacts*)lpObj)->FireError(&e);
            break;
         }
         case 6: {
            GContactsHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GContacts*)lpObj)->FireHeader(&e);
            break;
         }
         case 7: {
            GContactsSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GContacts*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 8: {
            GContactsSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GContacts*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 9: {
            GContactsSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GContacts*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 10: {
            GContactsStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GContacts*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 11: {
            GContactsStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GContacts*)lpObj)->FireStatus(&e);
            break;
         }
         case 12: {
            GContactsTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GContacts*)lpObj)->FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GContactsEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GContacts(char *lpOemKey = (char*)INGOOGLE_OEMKEY_20) {
      m_pObj = InGoogle_GContacts_Create(GContactsEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GContacts() {
      InGoogle_GContacts_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GContacts_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GContacts_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GContacts_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline char* GetAuthorization() {
      void* val = InGoogle_GContacts_Get(m_pObj, 1, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GContacts_Set(m_pObj, 1, 0, (void*)lpAuthorization, 0);
    }

    inline char* GetBirthday() {
      void* val = InGoogle_GContacts_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }

    inline int SetBirthday(const char *lpBirthday) {
      return InGoogle_GContacts_Set(m_pObj, 2, 0, (void*)lpBirthday, 0);
    }

    inline int GetContactCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 3, 0, 0);
      return (int)(long)val;
    }

    inline char* GetContactEditURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 4, 0, 0);
      return (char*)val;
    }

    inline int SetContactEditURL(const char *lpContactEditURL) {
      return InGoogle_GContacts_Set(m_pObj, 4, 0, (void*)lpContactEditURL, 0);
    }

    inline char* GetContactETag() {
      void* val = InGoogle_GContacts_Get(m_pObj, 5, 0, 0);
      return (char*)val;
    }

    inline int SetContactETag(const char *lpContactETag) {
      return InGoogle_GContacts_Set(m_pObj, 5, 0, (void*)lpContactETag, 0);
    }

    inline int GetContactIndex() {
      void* val = InGoogle_GContacts_Get(m_pObj, 6, 0, 0);
      return (int)(long)val;
    }
    inline int SetContactIndex(int iContactIndex) {
      void* val = (void*)IBG64CAST(iContactIndex);
      return InGoogle_GContacts_Set(m_pObj, 6, 0, val, 0);
    }
    inline int GetContactPropertiesCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 7, 0, 0);
      return (int)(long)val;
    }
    inline int SetContactPropertiesCount(int iContactPropertiesCount) {
      void* val = (void*)IBG64CAST(iContactPropertiesCount);
      return InGoogle_GContacts_Set(m_pObj, 7, 0, val, 0);
    }
    inline char* GetContactPropertiesAttributes(int iContactPropertiesIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 8, iContactPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetContactPropertiesAttributes(int iContactPropertiesIndex, const char *lpContactPropertiesAttributes) {
      return InGoogle_GContacts_Set(m_pObj, 8, iContactPropertiesIndex, (void*)lpContactPropertiesAttributes, 0);
    }

    inline char* GetContactPropertiesName(int iContactPropertiesIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 9, iContactPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetContactPropertiesName(int iContactPropertiesIndex, const char *lpContactPropertiesName) {
      return InGoogle_GContacts_Set(m_pObj, 9, iContactPropertiesIndex, (void*)lpContactPropertiesName, 0);
    }

    inline char* GetContactPropertiesValue(int iContactPropertiesIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 10, iContactPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetContactPropertiesValue(int iContactPropertiesIndex, const char *lpContactPropertiesValue) {
      return InGoogle_GContacts_Set(m_pObj, 10, iContactPropertiesIndex, (void*)lpContactPropertiesValue, 0);
    }

    inline int GetContactPropertiesValueFormat(int iContactPropertiesIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 11, iContactPropertiesIndex, 0);
      return (int)(long)val;
    }
    inline int SetContactPropertiesValueFormat(int iContactPropertiesIndex, int iContactPropertiesValueFormat) {
      void* val = (void*)IBG64CAST(iContactPropertiesValueFormat);
      return InGoogle_GContacts_Set(m_pObj, 11, iContactPropertiesIndex, val, 0);
    }
    inline char* GetContactPropertiesXPath(int iContactPropertiesIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 12, iContactPropertiesIndex, 0);
      return (char*)val;
    }


    inline int GetCookieCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 13, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GContacts_Set(m_pObj, 13, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 14, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 15, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 16, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GContacts_Set(m_pObj, 16, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 17, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 18, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 19, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GContacts_Set(m_pObj, 19, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline int GetDeleted() {
      void* val = InGoogle_GContacts_Get(m_pObj, 20, 0, 0);
      return (int)(long)val;
    }

    inline char* GetFeedAuthor() {
      void* val = InGoogle_GContacts_Get(m_pObj, 21, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedAuthorUri() {
      void* val = InGoogle_GContacts_Get(m_pObj, 22, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryLabel() {
      void* val = InGoogle_GContacts_Get(m_pObj, 23, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryScheme() {
      void* val = InGoogle_GContacts_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryTerm() {
      void* val = InGoogle_GContacts_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedEditURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedETag() {
      void* val = InGoogle_GContacts_Get(m_pObj, 27, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedGenerator() {
      void* val = InGoogle_GContacts_Get(m_pObj, 28, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedId() {
      void* val = InGoogle_GContacts_Get(m_pObj, 29, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedNextURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 30, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchItemsPerPage() {
      void* val = InGoogle_GContacts_Get(m_pObj, 31, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchStartIndex() {
      void* val = InGoogle_GContacts_Get(m_pObj, 32, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchTotalResults() {
      void* val = InGoogle_GContacts_Get(m_pObj, 33, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedPreviousURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 34, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedSelfURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedTitle() {
      void* val = InGoogle_GContacts_Get(m_pObj, 36, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedUpdated() {
      void* val = InGoogle_GContacts_Get(m_pObj, 37, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedURL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 38, 0, 0);
      return (char*)val;
    }

    inline int SetFeedURL(const char *lpFeedURL) {
      return InGoogle_GContacts_Set(m_pObj, 38, 0, (void*)lpFeedURL, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GContacts_Get(m_pObj, 39, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GContacts_Set(m_pObj, 39, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GContacts_Get(m_pObj, 40, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GContacts_Set(m_pObj, 40, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GContacts_Get(m_pObj, 41, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GContacts_Set(m_pObj, 41, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GContacts_Get(m_pObj, 42, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GContacts_Set(m_pObj, 42, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GContacts_Get(m_pObj, 43, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GContacts_Set(m_pObj, 43, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GContacts_Get(m_pObj, 44, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GContacts_Set(m_pObj, 44, 0, (void*)lpFirewallUser, 0);
    }

    inline char* GetFirstName() {
      void* val = InGoogle_GContacts_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }

    inline int SetFirstName(const char *lpFirstName) {
      return InGoogle_GContacts_Set(m_pObj, 45, 0, (void*)lpFirstName, 0);
    }

    inline char* GetFullName() {
      void* val = InGoogle_GContacts_Get(m_pObj, 46, 0, 0);
      return (char*)val;
    }

    inline int SetFullName(const char *lpFullName) {
      return InGoogle_GContacts_Set(m_pObj, 46, 0, (void*)lpFullName, 0);
    }

    inline char* GetGender() {
      void* val = InGoogle_GContacts_Get(m_pObj, 47, 0, 0);
      return (char*)val;
    }

    inline int SetGender(const char *lpGender) {
      return InGoogle_GContacts_Set(m_pObj, 47, 0, (void*)lpGender, 0);
    }

    inline char* GetHomeAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }

    inline int SetHomeAddress(const char *lpHomeAddress) {
      return InGoogle_GContacts_Set(m_pObj, 48, 0, (void*)lpHomeAddress, 0);
    }

    inline char* GetHomeEmailAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 49, 0, 0);
      return (char*)val;
    }

    inline int SetHomeEmailAddress(const char *lpHomeEmailAddress) {
      return InGoogle_GContacts_Set(m_pObj, 49, 0, (void*)lpHomeEmailAddress, 0);
    }

    inline char* GetHomeIMAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 50, 0, 0);
      return (char*)val;
    }

    inline int SetHomeIMAddress(const char *lpHomeIMAddress) {
      return InGoogle_GContacts_Set(m_pObj, 50, 0, (void*)lpHomeIMAddress, 0);
    }

    inline char* GetHomeIMProtocol() {
      void* val = InGoogle_GContacts_Get(m_pObj, 51, 0, 0);
      return (char*)val;
    }

    inline int SetHomeIMProtocol(const char *lpHomeIMProtocol) {
      return InGoogle_GContacts_Set(m_pObj, 51, 0, (void*)lpHomeIMProtocol, 0);
    }

    inline char* GetHomePhoneNumber() {
      void* val = InGoogle_GContacts_Get(m_pObj, 52, 0, 0);
      return (char*)val;
    }

    inline int SetHomePhoneNumber(const char *lpHomePhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 52, 0, (void*)lpHomePhoneNumber, 0);
    }

    inline char* GetHomeWebsite() {
      void* val = InGoogle_GContacts_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }

    inline int SetHomeWebsite(const char *lpHomeWebsite) {
      return InGoogle_GContacts_Set(m_pObj, 53, 0, (void*)lpHomeWebsite, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GContacts_Get(m_pObj, 54, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLastName() {
      void* val = InGoogle_GContacts_Get(m_pObj, 55, 0, 0);
      return (char*)val;
    }

    inline int SetLastName(const char *lpLastName) {
      return InGoogle_GContacts_Set(m_pObj, 55, 0, (void*)lpLastName, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GContacts_Get(m_pObj, 56, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GContacts_Set(m_pObj, 56, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetMobilePhoneNumber() {
      void* val = InGoogle_GContacts_Get(m_pObj, 57, 0, 0);
      return (char*)val;
    }

    inline int SetMobilePhoneNumber(const char *lpMobilePhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 57, 0, (void*)lpMobilePhoneNumber, 0);
    }

    inline char* GetNickname() {
      void* val = InGoogle_GContacts_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }

    inline int SetNickname(const char *lpNickname) {
      return InGoogle_GContacts_Set(m_pObj, 58, 0, (void*)lpNickname, 0);
    }

    inline char* GetNotes() {
      void* val = InGoogle_GContacts_Get(m_pObj, 59, 0, 0);
      return (char*)val;
    }

    inline int SetNotes(const char *lpNotes) {
      return InGoogle_GContacts_Set(m_pObj, 59, 0, (void*)lpNotes, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GContacts_Get(m_pObj, 60, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GContacts_Set(m_pObj, 60, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 61, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 62, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 63, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GContacts_Get(m_pObj, 64, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GContacts_Set(m_pObj, 64, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GContacts_Get(m_pObj, 65, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GContacts_Set(m_pObj, 65, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GContacts_Get(m_pObj, 66, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GContacts_Set(m_pObj, 66, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GContacts_Get(m_pObj, 67, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GContacts_Set(m_pObj, 67, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GContacts_Get(m_pObj, 68, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GContacts_Set(m_pObj, 68, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GContacts_Get(m_pObj, 69, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GContacts_Set(m_pObj, 69, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GContacts_Get(m_pObj, 70, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GContacts_Set(m_pObj, 70, 0, (void*)lpProxyUser, 0);
    }

    inline int GetQueryParamsCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 71, 0, 0);
      return (int)(long)val;
    }
    inline int SetQueryParamsCount(int iQueryParamsCount) {
      void* val = (void*)IBG64CAST(iQueryParamsCount);
      return InGoogle_GContacts_Set(m_pObj, 71, 0, val, 0);
    }
    inline char* GetQueryParamsName(int iQueryParamsIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 72, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, const char *lpQueryParamsName) {
      return InGoogle_GContacts_Set(m_pObj, 72, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline char* GetQueryParamsValue(int iQueryParamsIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 73, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, const char *lpQueryParamsValue) {
      return InGoogle_GContacts_Set(m_pObj, 73, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 74, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 74, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 75, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 75, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GContacts_Get(m_pObj, 76, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GContacts_Set(m_pObj, 76, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GContacts_Get(m_pObj, 77, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GContacts_Set(m_pObj, 77, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GContacts_Get(m_pObj, 78, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GContacts_Set(m_pObj, 78, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GContacts_Get(m_pObj, 79, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GContacts_Set(m_pObj, 79, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 80, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GContacts_Get(m_pObj, 81, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GContacts_Set(m_pObj, 81, 0, val, 0);
    }
    inline char* GetWorkAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 82, 0, 0);
      return (char*)val;
    }

    inline int SetWorkAddress(const char *lpWorkAddress) {
      return InGoogle_GContacts_Set(m_pObj, 82, 0, (void*)lpWorkAddress, 0);
    }

    inline char* GetWorkEmailAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 83, 0, 0);
      return (char*)val;
    }

    inline int SetWorkEmailAddress(const char *lpWorkEmailAddress) {
      return InGoogle_GContacts_Set(m_pObj, 83, 0, (void*)lpWorkEmailAddress, 0);
    }

    inline char* GetWorkIMAddress() {
      void* val = InGoogle_GContacts_Get(m_pObj, 84, 0, 0);
      return (char*)val;
    }

    inline int SetWorkIMAddress(const char *lpWorkIMAddress) {
      return InGoogle_GContacts_Set(m_pObj, 84, 0, (void*)lpWorkIMAddress, 0);
    }

    inline char* GetWorkIMProtocol() {
      void* val = InGoogle_GContacts_Get(m_pObj, 85, 0, 0);
      return (char*)val;
    }

    inline int SetWorkIMProtocol(const char *lpWorkIMProtocol) {
      return InGoogle_GContacts_Set(m_pObj, 85, 0, (void*)lpWorkIMProtocol, 0);
    }

    inline char* GetWorkPhoneNumber() {
      void* val = InGoogle_GContacts_Get(m_pObj, 86, 0, 0);
      return (char*)val;
    }

    inline int SetWorkPhoneNumber(const char *lpWorkPhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 86, 0, (void*)lpWorkPhoneNumber, 0);
    }

    inline char* GetWorkWebsite() {
      void* val = InGoogle_GContacts_Get(m_pObj, 87, 0, 0);
      return (char*)val;
    }

    inline int SetWorkWebsite(const char *lpWorkWebsite) {
      return InGoogle_GContacts_Set(m_pObj, 87, 0, (void*)lpWorkWebsite, 0);
    }

    inline int GetAttrCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 88, 0, 0);
      return (int)(long)val;
    }

    inline char* GetAttrName(int iAttrIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 89, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrNamespace(int iAttrIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 90, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrPrefix(int iAttrIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 91, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrValue(int iAttrIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 92, iAttrIndex, 0);
      return (char*)val;
    }


    inline int GetXChildrenCount() {
      void* val = InGoogle_GContacts_Get(m_pObj, 93, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 94, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildNamespace(int iXChildIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 95, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildPrefix(int iXChildIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 96, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GContacts_Get(m_pObj, 97, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GContacts_Get(m_pObj, 98, 0, 0);
      return (char*)val;
    }


    inline char* GetXNamespace() {
      void* val = InGoogle_GContacts_Get(m_pObj, 99, 0, 0);
      return (char*)val;
    }


    inline char* GetXParent() {
      void* val = InGoogle_GContacts_Get(m_pObj, 100, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GContacts_Get(m_pObj, 101, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GContacts_Set(m_pObj, 101, 0, (void*)lpXPath, 0);
    }

    inline char* GetXPrefix() {
      void* val = InGoogle_GContacts_Get(m_pObj, 102, 0, 0);
      return (char*)val;
    }


    inline char* GetXSubTree() {
      void* val = InGoogle_GContacts_Get(m_pObj, 103, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GContacts_Get(m_pObj, 104, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline int AddQueryParam(const char* lpszname, const char* lpszvalue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszname), (void*)IBG64CAST(lpszvalue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GContacts_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GContacts_Do(m_pObj, 3, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int CreateContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 4, 0, param, cbparam);
      
      
    }
    inline int DeleteContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline char* GetProperty(const char* lpszPropertyName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszPropertyName), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GContacts_Do(m_pObj, 6, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int QueryContacts() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 7, 0, param, cbparam);
      
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 8, 0, param, cbparam);
      
      
    }
    inline int UpdateContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GContactsConnectedEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR FullName;
  LPWSTR Gender;
  LPWSTR WorkAddress;
  LPWSTR WorkEmailAddress;
  LPWSTR WorkPhoneNumber;
  int reserved;
} GContactsContactListEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GContactsDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GContactsEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GContactsErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GContactsHeaderEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GContactsSetCookieEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GContactsSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GContactsSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GContactsStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GContactsStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GContactsTransferEventParamsW;



class GContactsW : public GContacts {

  public: //properties
  
    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+1, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GContacts_Set(m_pObj, 10000+1, 0, (void*)lpAuthorization, 0);
    }

    inline LPWSTR GetBirthday() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+2, 0, 0);
    }

    inline int SetBirthday(LPWSTR lpBirthday) {
      return InGoogle_GContacts_Set(m_pObj, 10000+2, 0, (void*)lpBirthday, 0);
    }



    inline LPWSTR GetContactEditURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+4, 0, 0);
    }

    inline int SetContactEditURL(LPWSTR lpContactEditURL) {
      return InGoogle_GContacts_Set(m_pObj, 10000+4, 0, (void*)lpContactEditURL, 0);
    }

    inline LPWSTR GetContactETag() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+5, 0, 0);
    }

    inline int SetContactETag(LPWSTR lpContactETag) {
      return InGoogle_GContacts_Set(m_pObj, 10000+5, 0, (void*)lpContactETag, 0);
    }





    inline LPWSTR GetContactPropertiesAttributes(int iContactPropertiesIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+8, iContactPropertiesIndex, 0);
    }

    inline int SetContactPropertiesAttributes(int iContactPropertiesIndex, LPWSTR lpContactPropertiesAttributes) {
      return InGoogle_GContacts_Set(m_pObj, 10000+8, iContactPropertiesIndex, (void*)lpContactPropertiesAttributes, 0);
    }

    inline LPWSTR GetContactPropertiesName(int iContactPropertiesIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+9, iContactPropertiesIndex, 0);
    }

    inline int SetContactPropertiesName(int iContactPropertiesIndex, LPWSTR lpContactPropertiesName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+9, iContactPropertiesIndex, (void*)lpContactPropertiesName, 0);
    }

    inline LPWSTR GetContactPropertiesValue(int iContactPropertiesIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+10, iContactPropertiesIndex, 0);
    }

    inline int SetContactPropertiesValue(int iContactPropertiesIndex, LPWSTR lpContactPropertiesValue) {
      return InGoogle_GContacts_Set(m_pObj, 10000+10, iContactPropertiesIndex, (void*)lpContactPropertiesValue, 0);
    }



    inline LPWSTR GetContactPropertiesXPath(int iContactPropertiesIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+12, iContactPropertiesIndex, 0);
    }





    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+14, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+15, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+16, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+16, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+17, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+19, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GContacts_Set(m_pObj, 10000+19, iCookieIndex, (void*)lpCookieValue, 0);
    }



    inline LPWSTR GetFeedAuthor() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+21, 0, 0);
    }



    inline LPWSTR GetFeedAuthorUri() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+22, 0, 0);
    }



    inline LPWSTR GetFeedCategoryLabel() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+23, 0, 0);
    }



    inline LPWSTR GetFeedCategoryScheme() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+24, 0, 0);
    }



    inline LPWSTR GetFeedCategoryTerm() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+25, 0, 0);
    }



    inline LPWSTR GetFeedEditURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+26, 0, 0);
    }



    inline LPWSTR GetFeedETag() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+27, 0, 0);
    }



    inline LPWSTR GetFeedGenerator() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+28, 0, 0);
    }



    inline LPWSTR GetFeedId() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+29, 0, 0);
    }



    inline LPWSTR GetFeedNextURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+30, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchItemsPerPage() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+31, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchStartIndex() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+32, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchTotalResults() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+33, 0, 0);
    }



    inline LPWSTR GetFeedPreviousURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+34, 0, 0);
    }



    inline LPWSTR GetFeedSelfURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+35, 0, 0);
    }



    inline LPWSTR GetFeedTitle() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+36, 0, 0);
    }



    inline LPWSTR GetFeedUpdated() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+37, 0, 0);
    }



    inline LPWSTR GetFeedURL() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+38, 0, 0);
    }

    inline int SetFeedURL(LPWSTR lpFeedURL) {
      return InGoogle_GContacts_Set(m_pObj, 10000+38, 0, (void*)lpFeedURL, 0);
    }





    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+41, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GContacts_Set(m_pObj, 10000+41, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+42, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GContacts_Set(m_pObj, 10000+42, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+44, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GContacts_Set(m_pObj, 10000+44, 0, (void*)lpFirewallUser, 0);
    }

    inline LPWSTR GetFirstName() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+45, 0, 0);
    }

    inline int SetFirstName(LPWSTR lpFirstName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+45, 0, (void*)lpFirstName, 0);
    }

    inline LPWSTR GetFullName() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+46, 0, 0);
    }

    inline int SetFullName(LPWSTR lpFullName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+46, 0, (void*)lpFullName, 0);
    }

    inline LPWSTR GetGender() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+47, 0, 0);
    }

    inline int SetGender(LPWSTR lpGender) {
      return InGoogle_GContacts_Set(m_pObj, 10000+47, 0, (void*)lpGender, 0);
    }

    inline LPWSTR GetHomeAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+48, 0, 0);
    }

    inline int SetHomeAddress(LPWSTR lpHomeAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+48, 0, (void*)lpHomeAddress, 0);
    }

    inline LPWSTR GetHomeEmailAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+49, 0, 0);
    }

    inline int SetHomeEmailAddress(LPWSTR lpHomeEmailAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+49, 0, (void*)lpHomeEmailAddress, 0);
    }

    inline LPWSTR GetHomeIMAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+50, 0, 0);
    }

    inline int SetHomeIMAddress(LPWSTR lpHomeIMAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+50, 0, (void*)lpHomeIMAddress, 0);
    }

    inline LPWSTR GetHomeIMProtocol() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+51, 0, 0);
    }

    inline int SetHomeIMProtocol(LPWSTR lpHomeIMProtocol) {
      return InGoogle_GContacts_Set(m_pObj, 10000+51, 0, (void*)lpHomeIMProtocol, 0);
    }

    inline LPWSTR GetHomePhoneNumber() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+52, 0, 0);
    }

    inline int SetHomePhoneNumber(LPWSTR lpHomePhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 10000+52, 0, (void*)lpHomePhoneNumber, 0);
    }

    inline LPWSTR GetHomeWebsite() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+53, 0, 0);
    }

    inline int SetHomeWebsite(LPWSTR lpHomeWebsite) {
      return InGoogle_GContacts_Set(m_pObj, 10000+53, 0, (void*)lpHomeWebsite, 0);
    }



    inline LPWSTR GetLastName() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+55, 0, 0);
    }

    inline int SetLastName(LPWSTR lpLastName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+55, 0, (void*)lpLastName, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+56, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GContacts_Set(m_pObj, 10000+56, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetMobilePhoneNumber() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+57, 0, 0);
    }

    inline int SetMobilePhoneNumber(LPWSTR lpMobilePhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 10000+57, 0, (void*)lpMobilePhoneNumber, 0);
    }

    inline LPWSTR GetNickname() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+58, 0, 0);
    }

    inline int SetNickname(LPWSTR lpNickname) {
      return InGoogle_GContacts_Set(m_pObj, 10000+58, 0, (void*)lpNickname, 0);
    }

    inline LPWSTR GetNotes() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+59, 0, 0);
    }

    inline int SetNotes(LPWSTR lpNotes) {
      return InGoogle_GContacts_Set(m_pObj, 10000+59, 0, (void*)lpNotes, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+60, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GContacts_Set(m_pObj, 10000+60, 0, (void*)lpOtherHeaders, 0);
    }



    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+62, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+63, iParsedHeaderIndex, 0);
    }







    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+66, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GContacts_Set(m_pObj, 10000+66, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+68, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GContacts_Set(m_pObj, 10000+68, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+70, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GContacts_Set(m_pObj, 10000+70, 0, (void*)lpProxyUser, 0);
    }



    inline LPWSTR GetQueryParamsName(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+72, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, LPWSTR lpQueryParamsName) {
      return InGoogle_GContacts_Set(m_pObj, 10000+72, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline LPWSTR GetQueryParamsValue(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+73, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, LPWSTR lpQueryParamsValue) {
      return InGoogle_GContacts_Set(m_pObj, 10000+73, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+74, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 10000+74, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 74, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 74, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+75, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 10000+75, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 75, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GContacts_Set(m_pObj, 75, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+76, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GContacts_Set(m_pObj, 10000+76, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GContacts_Get(m_pObj, 76, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GContacts_Set(m_pObj, 76, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+77, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GContacts_Set(m_pObj, 10000+77, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+79, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GContacts_Set(m_pObj, 10000+79, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+80, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GContacts_Get(m_pObj, 80, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }



    inline LPWSTR GetWorkAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+82, 0, 0);
    }

    inline int SetWorkAddress(LPWSTR lpWorkAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+82, 0, (void*)lpWorkAddress, 0);
    }

    inline LPWSTR GetWorkEmailAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+83, 0, 0);
    }

    inline int SetWorkEmailAddress(LPWSTR lpWorkEmailAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+83, 0, (void*)lpWorkEmailAddress, 0);
    }

    inline LPWSTR GetWorkIMAddress() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+84, 0, 0);
    }

    inline int SetWorkIMAddress(LPWSTR lpWorkIMAddress) {
      return InGoogle_GContacts_Set(m_pObj, 10000+84, 0, (void*)lpWorkIMAddress, 0);
    }

    inline LPWSTR GetWorkIMProtocol() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+85, 0, 0);
    }

    inline int SetWorkIMProtocol(LPWSTR lpWorkIMProtocol) {
      return InGoogle_GContacts_Set(m_pObj, 10000+85, 0, (void*)lpWorkIMProtocol, 0);
    }

    inline LPWSTR GetWorkPhoneNumber() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+86, 0, 0);
    }

    inline int SetWorkPhoneNumber(LPWSTR lpWorkPhoneNumber) {
      return InGoogle_GContacts_Set(m_pObj, 10000+86, 0, (void*)lpWorkPhoneNumber, 0);
    }

    inline LPWSTR GetWorkWebsite() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+87, 0, 0);
    }

    inline int SetWorkWebsite(LPWSTR lpWorkWebsite) {
      return InGoogle_GContacts_Set(m_pObj, 10000+87, 0, (void*)lpWorkWebsite, 0);
    }



    inline LPWSTR GetAttrName(int iAttrIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+89, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrNamespace(int iAttrIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+90, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrPrefix(int iAttrIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+91, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrValue(int iAttrIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+92, iAttrIndex, 0);
    }





    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+94, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildNamespace(int iXChildIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+95, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildPrefix(int iXChildIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+96, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+97, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+98, 0, 0);
    }



    inline LPWSTR GetXNamespace() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+99, 0, 0);
    }



    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+100, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+101, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GContacts_Set(m_pObj, 10000+101, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXPrefix() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+102, 0, 0);
    }



    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+103, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GContacts_Get(m_pObj, 10000+104, 0, 0);
    }





  public: //events
  
    virtual int FireConnected(GContactsConnectedEventParamsW *e) {return 0;}
    virtual int FireContactList(GContactsContactListEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GContactsDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GContactsEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GContactsErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GContactsHeaderEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GContactsSetCookieEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GContactsSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GContactsSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GContactsStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GContactsStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GContactsTransferEventParamsW *e) {return 0;}


  protected:
  
    virtual int GContactsEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GContactsConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 2: {
            GContactsContactListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]),  0};
            ret_code = FireContactList(&e);
            break;
         }
         case 3: {
            GContactsDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 4: {
            GContactsEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 5: {
            GContactsErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 6: {
            GContactsHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 7: {
            GContactsSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 8: {
            GContactsSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 9: {
            GContactsSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 10: {
            GContactsStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 11: {
            GContactsStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 12: {
            GContactsTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireConnected(GContactsConnectedEventParams *e) {return -10000;}
    virtual int FireContactList(GContactsContactListEventParams *e) {return -10000;}
    virtual int FireDisconnected(GContactsDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GContactsEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GContactsErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GContactsHeaderEventParams *e) {return -10000;}
    virtual int FireSetCookie(GContactsSetCookieEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GContactsSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GContactsSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GContactsStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GContactsStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GContactsTransferEventParams *e) {return -10000;}

  public: //methods

    inline int AddQueryParam(LPWSTR lpszname, LPWSTR lpszvalue) {
      void *param[2+1] = {(void*)lpszname, (void*)lpszvalue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GContacts_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GContacts_Do(m_pObj, 10000+3, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int CreateContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 10000+4, 0, param, cbparam);
      
    }
    inline int DeleteContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline LPWSTR GetProperty(LPWSTR lpszPropertyName) {
      void *param[1+1] = {(void*)lpszPropertyName, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GContacts_Do(m_pObj, 10000+6, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int QueryContacts() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 10000+7, 0, param, cbparam);
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 10000+8, 0, param, cbparam);
      
    }
    inline int UpdateContact() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GContacts_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GCONTACTS_H_




