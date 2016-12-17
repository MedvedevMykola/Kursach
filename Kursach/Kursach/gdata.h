/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GDATA_H_
#define _INGOOGLE_GDATA_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//GACLOperations
#define GAO_NONE                                           0
#define GAO_ADD                                            1
#define GAO_DELETE                                         2
#define GAO_QUERY                                          3
#define GAO_UPDATE                                         4

//GACLRoles
#define GAR_OWNER                                          0
#define GAR_WRITER                                         1
#define GAR_READER                                         2

//GACLScopeTypes
#define GAS_USER                                           0
#define GAS_GROUP                                          1
#define GAS_DOMAIN                                         2
#define GAS_DEFAULT                                        3

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


extern "C" void* INGOOGLE_CALL InGoogle_GData_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GData_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GData_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GData_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GData_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GData_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GData_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GData_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GData_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GData_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GDataConnectedEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GDataDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GDataEndTransferEventParams;

typedef struct {
  const char* Id;
  const char* Title;
  const char* ETag;
  int reserved;
} GDataEntryEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GDataErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GDataHeaderEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GDataSetCookieEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GDataSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GDataSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GDataStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GDataStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GDataTransferEventParams;

typedef struct {
  int Role;
  int ScopeType;
  const char* ScopeValue;
  int Success;
  const char* StatusCode;
  const char* StatusReason;
  int Operation;
  const char* LastUpdated;
  const char* RawEntryXML;
  int reserved;
} GDataUpdateACLResponseEventParams;



class GData {
  
  public: //events
  
    virtual int FireConnected(GDataConnectedEventParams *e) {return 0;}
    virtual int FireDisconnected(GDataDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GDataEndTransferEventParams *e) {return 0;}
    virtual int FireEntry(GDataEntryEventParams *e) {return 0;}
    virtual int FireError(GDataErrorEventParams *e) {return 0;}
    virtual int FireHeader(GDataHeaderEventParams *e) {return 0;}
    virtual int FireSetCookie(GDataSetCookieEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GDataSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GDataSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GDataStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GDataStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GDataTransferEventParams *e) {return 0;}
    virtual int FireUpdateACLResponse(GDataUpdateACLResponseEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GDataEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GData*)lpObj)->GDataEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GDataConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GData*)lpObj)->FireConnected(&e);
            break;
         }
         case 2: {
            GDataDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GData*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 3: {
            GDataEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GData*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 4: {
            GDataEntryEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GData*)lpObj)->FireEntry(&e);
            break;
         }
         case 5: {
            GDataErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GData*)lpObj)->FireError(&e);
            break;
         }
         case 6: {
            GDataHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GData*)lpObj)->FireHeader(&e);
            break;
         }
         case 7: {
            GDataSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GData*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 8: {
            GDataSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GData*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 9: {
            GDataSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GData*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 10: {
            GDataStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GData*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 11: {
            GDataStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GData*)lpObj)->FireStatus(&e);
            break;
         }
         case 12: {
            GDataTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GData*)lpObj)->FireTransfer(&e);
            break;
         }
         case 13: {
            GDataUpdateACLResponseEventParams e = {(int)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (int)IBG64CAST(param[6]), (char*)IBG64CAST(param[7]), (char*)IBG64CAST(param[8]),  0};
            ret_code = ((GData*)lpObj)->FireUpdateACLResponse(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GDataEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GData(char *lpOemKey = (char*)INGOOGLE_OEMKEY_10) {
      m_pObj = InGoogle_GData_Create(GDataEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GData() {
      InGoogle_GData_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GData_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GData_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GData_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline int GetACLCount() {
      void* val = InGoogle_GData_Get(m_pObj, 1, 0, 0);
      return (int)(long)val;
    }
    inline int SetACLCount(int iACLCount) {
      void* val = (void*)IBG64CAST(iACLCount);
      return InGoogle_GData_Set(m_pObj, 1, 0, val, 0);
    }
    inline int GetACLOperation(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 2, iACLIndex, 0);
      return (int)(long)val;
    }
    inline int SetACLOperation(int iACLIndex, int iACLOperation) {
      void* val = (void*)IBG64CAST(iACLOperation);
      return InGoogle_GData_Set(m_pObj, 2, iACLIndex, val, 0);
    }
    inline int GetACLRole(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 3, iACLIndex, 0);
      return (int)(long)val;
    }
    inline int SetACLRole(int iACLIndex, int iACLRole) {
      void* val = (void*)IBG64CAST(iACLRole);
      return InGoogle_GData_Set(m_pObj, 3, iACLIndex, val, 0);
    }
    inline int GetACLScopeType(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 4, iACLIndex, 0);
      return (int)(long)val;
    }
    inline int SetACLScopeType(int iACLIndex, int iACLScopeType) {
      void* val = (void*)IBG64CAST(iACLScopeType);
      return InGoogle_GData_Set(m_pObj, 4, iACLIndex, val, 0);
    }
    inline char* GetACLScopeValue(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 5, iACLIndex, 0);
      return (char*)val;
    }

    inline int SetACLScopeValue(int iACLIndex, const char *lpACLScopeValue) {
      return InGoogle_GData_Set(m_pObj, 5, iACLIndex, (void*)lpACLScopeValue, 0);
    }

    inline char* GetACLStatusCode(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 6, iACLIndex, 0);
      return (char*)val;
    }


    inline char* GetACLStatusReason(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 7, iACLIndex, 0);
      return (char*)val;
    }


    inline int GetACLSuccess(int iACLIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 8, iACLIndex, 0);
      return (int)(long)val;
    }

    inline char* GetAuthorization() {
      void* val = InGoogle_GData_Get(m_pObj, 9, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GData_Set(m_pObj, 9, 0, (void*)lpAuthorization, 0);
    }

    inline int GetCookieCount() {
      void* val = InGoogle_GData_Get(m_pObj, 10, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GData_Set(m_pObj, 10, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 11, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 12, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 13, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GData_Set(m_pObj, 13, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 14, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 15, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 16, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GData_Set(m_pObj, 16, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline char* GetEntryAclURL() {
      void* val = InGoogle_GData_Get(m_pObj, 17, 0, 0);
      return (char*)val;
    }

    inline int SetEntryAclURL(const char *lpEntryAclURL) {
      return InGoogle_GData_Set(m_pObj, 17, 0, (void*)lpEntryAclURL, 0);
    }

    inline int GetEntryCount() {
      void* val = InGoogle_GData_Get(m_pObj, 18, 0, 0);
      return (int)(long)val;
    }

    inline char* GetEntryEditURL() {
      void* val = InGoogle_GData_Get(m_pObj, 19, 0, 0);
      return (char*)val;
    }

    inline int SetEntryEditURL(const char *lpEntryEditURL) {
      return InGoogle_GData_Set(m_pObj, 19, 0, (void*)lpEntryEditURL, 0);
    }

    inline int GetEntryElementCount() {
      void* val = InGoogle_GData_Get(m_pObj, 20, 0, 0);
      return (int)(long)val;
    }
    inline int SetEntryElementCount(int iEntryElementCount) {
      void* val = (void*)IBG64CAST(iEntryElementCount);
      return InGoogle_GData_Set(m_pObj, 20, 0, val, 0);
    }
    inline char* GetEntryElementAttributes(int iEntryElementIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 21, iEntryElementIndex, 0);
      return (char*)val;
    }

    inline int SetEntryElementAttributes(int iEntryElementIndex, const char *lpEntryElementAttributes) {
      return InGoogle_GData_Set(m_pObj, 21, iEntryElementIndex, (void*)lpEntryElementAttributes, 0);
    }

    inline char* GetEntryElementName(int iEntryElementIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 22, iEntryElementIndex, 0);
      return (char*)val;
    }

    inline int SetEntryElementName(int iEntryElementIndex, const char *lpEntryElementName) {
      return InGoogle_GData_Set(m_pObj, 22, iEntryElementIndex, (void*)lpEntryElementName, 0);
    }

    inline char* GetEntryElementValue(int iEntryElementIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 23, iEntryElementIndex, 0);
      return (char*)val;
    }

    inline int SetEntryElementValue(int iEntryElementIndex, const char *lpEntryElementValue) {
      return InGoogle_GData_Set(m_pObj, 23, iEntryElementIndex, (void*)lpEntryElementValue, 0);
    }

    inline int GetEntryElementValueFormat(int iEntryElementIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 24, iEntryElementIndex, 0);
      return (int)(long)val;
    }
    inline int SetEntryElementValueFormat(int iEntryElementIndex, int iEntryElementValueFormat) {
      void* val = (void*)IBG64CAST(iEntryElementValueFormat);
      return InGoogle_GData_Set(m_pObj, 24, iEntryElementIndex, val, 0);
    }
    inline char* GetEntryElementXPath(int iEntryElementIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 25, iEntryElementIndex, 0);
      return (char*)val;
    }


    inline char* GetEntryETag() {
      void* val = InGoogle_GData_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }

    inline int SetEntryETag(const char *lpEntryETag) {
      return InGoogle_GData_Set(m_pObj, 26, 0, (void*)lpEntryETag, 0);
    }

    inline int GetEntryIndex() {
      void* val = InGoogle_GData_Get(m_pObj, 27, 0, 0);
      return (int)(long)val;
    }
    inline int SetEntryIndex(int iEntryIndex) {
      void* val = (void*)IBG64CAST(iEntryIndex);
      return InGoogle_GData_Set(m_pObj, 27, 0, val, 0);
    }
    inline char* GetFeedAuthor() {
      void* val = InGoogle_GData_Get(m_pObj, 28, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedAuthorUri() {
      void* val = InGoogle_GData_Get(m_pObj, 29, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryLabel() {
      void* val = InGoogle_GData_Get(m_pObj, 30, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryScheme() {
      void* val = InGoogle_GData_Get(m_pObj, 31, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryTerm() {
      void* val = InGoogle_GData_Get(m_pObj, 32, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedEditURL() {
      void* val = InGoogle_GData_Get(m_pObj, 33, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedETag() {
      void* val = InGoogle_GData_Get(m_pObj, 34, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedGenerator() {
      void* val = InGoogle_GData_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedId() {
      void* val = InGoogle_GData_Get(m_pObj, 36, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedNextURL() {
      void* val = InGoogle_GData_Get(m_pObj, 37, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchItemsPerPage() {
      void* val = InGoogle_GData_Get(m_pObj, 38, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchStartIndex() {
      void* val = InGoogle_GData_Get(m_pObj, 39, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchTotalResults() {
      void* val = InGoogle_GData_Get(m_pObj, 40, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedPreviousURL() {
      void* val = InGoogle_GData_Get(m_pObj, 41, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedSelfURL() {
      void* val = InGoogle_GData_Get(m_pObj, 42, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedTitle() {
      void* val = InGoogle_GData_Get(m_pObj, 43, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedUpdated() {
      void* val = InGoogle_GData_Get(m_pObj, 44, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedURL() {
      void* val = InGoogle_GData_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }

    inline int SetFeedURL(const char *lpFeedURL) {
      return InGoogle_GData_Set(m_pObj, 45, 0, (void*)lpFeedURL, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GData_Get(m_pObj, 46, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GData_Set(m_pObj, 46, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GData_Get(m_pObj, 47, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GData_Set(m_pObj, 47, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GData_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GData_Set(m_pObj, 48, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GData_Get(m_pObj, 49, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GData_Set(m_pObj, 49, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GData_Get(m_pObj, 50, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GData_Set(m_pObj, 50, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GData_Get(m_pObj, 51, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GData_Set(m_pObj, 51, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GData_Get(m_pObj, 52, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLocalFile() {
      void* val = InGoogle_GData_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }

    inline int SetLocalFile(const char *lpLocalFile) {
      return InGoogle_GData_Set(m_pObj, 53, 0, (void*)lpLocalFile, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GData_Get(m_pObj, 54, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GData_Set(m_pObj, 54, 0, (void*)lpLocalHost, 0);
    }

    inline int GetNamespaceCount() {
      void* val = InGoogle_GData_Get(m_pObj, 55, 0, 0);
      return (int)(long)val;
    }
    inline int SetNamespaceCount(int iNamespaceCount) {
      void* val = (void*)IBG64CAST(iNamespaceCount);
      return InGoogle_GData_Set(m_pObj, 55, 0, val, 0);
    }
    inline char* GetNamespacePrefix(int iNamespaceIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 56, iNamespaceIndex, 0);
      return (char*)val;
    }

    inline int SetNamespacePrefix(int iNamespaceIndex, const char *lpNamespacePrefix) {
      return InGoogle_GData_Set(m_pObj, 56, iNamespaceIndex, (void*)lpNamespacePrefix, 0);
    }

    inline char* GetNamespaceURI(int iNamespaceIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 57, iNamespaceIndex, 0);
      return (char*)val;
    }

    inline int SetNamespaceURI(int iNamespaceIndex, const char *lpNamespaceURI) {
      return InGoogle_GData_Set(m_pObj, 57, iNamespaceIndex, (void*)lpNamespaceURI, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GData_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GData_Set(m_pObj, 58, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GData_Get(m_pObj, 59, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 60, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 61, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GData_Get(m_pObj, 62, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GData_Set(m_pObj, 62, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GData_Get(m_pObj, 63, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GData_Set(m_pObj, 63, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GData_Get(m_pObj, 64, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GData_Set(m_pObj, 64, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GData_Get(m_pObj, 65, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GData_Set(m_pObj, 65, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GData_Get(m_pObj, 66, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GData_Set(m_pObj, 66, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GData_Get(m_pObj, 67, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GData_Set(m_pObj, 67, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GData_Get(m_pObj, 68, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GData_Set(m_pObj, 68, 0, (void*)lpProxyUser, 0);
    }

    inline int GetQueryParamsCount() {
      void* val = InGoogle_GData_Get(m_pObj, 69, 0, 0);
      return (int)(long)val;
    }
    inline int SetQueryParamsCount(int iQueryParamsCount) {
      void* val = (void*)IBG64CAST(iQueryParamsCount);
      return InGoogle_GData_Set(m_pObj, 69, 0, val, 0);
    }
    inline char* GetQueryParamsName(int iQueryParamsIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 70, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, const char *lpQueryParamsName) {
      return InGoogle_GData_Set(m_pObj, 70, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline char* GetQueryParamsValue(int iQueryParamsIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 71, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, const char *lpQueryParamsValue) {
      return InGoogle_GData_Set(m_pObj, 71, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 72, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 72, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 73, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 73, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GData_Get(m_pObj, 74, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GData_Set(m_pObj, 74, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GData_Get(m_pObj, 75, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GData_Set(m_pObj, 75, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GData_Get(m_pObj, 76, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GData_Set(m_pObj, 76, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GData_Get(m_pObj, 77, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GData_Set(m_pObj, 77, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 78, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GData_Get(m_pObj, 79, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GData_Set(m_pObj, 79, 0, val, 0);
    }
    inline int GetTransferredData(char *&lpTransferredData, int &lenTransferredData) {
      lpTransferredData = (char*)InGoogle_GData_Get(m_pObj, 80, 0, &lenTransferredData);
      return lpTransferredData ? 0 : lenTransferredData;
    }


    inline int GetAttrCount() {
      void* val = InGoogle_GData_Get(m_pObj, 81, 0, 0);
      return (int)(long)val;
    }

    inline char* GetAttrName(int iAttrIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 82, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrNamespace(int iAttrIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 83, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrPrefix(int iAttrIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 84, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrValue(int iAttrIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 85, iAttrIndex, 0);
      return (char*)val;
    }


    inline int GetXChildrenCount() {
      void* val = InGoogle_GData_Get(m_pObj, 86, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 87, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildNamespace(int iXChildIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 88, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildPrefix(int iXChildIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 89, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GData_Get(m_pObj, 90, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GData_Get(m_pObj, 91, 0, 0);
      return (char*)val;
    }


    inline char* GetXNamespace() {
      void* val = InGoogle_GData_Get(m_pObj, 92, 0, 0);
      return (char*)val;
    }


    inline char* GetXParent() {
      void* val = InGoogle_GData_Get(m_pObj, 93, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GData_Get(m_pObj, 94, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GData_Set(m_pObj, 94, 0, (void*)lpXPath, 0);
    }

    inline char* GetXPrefix() {
      void* val = InGoogle_GData_Get(m_pObj, 95, 0, 0);
      return (char*)val;
    }


    inline char* GetXSubTree() {
      void* val = InGoogle_GData_Get(m_pObj, 96, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GData_Get(m_pObj, 97, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline int AddNamespace(const char* lpszPrefix, const char* lpszNamespaceURI) {
      void *param[2+1] = {(void*)IBG64CAST(lpszPrefix), (void*)IBG64CAST(lpszNamespaceURI), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline int AddQueryParam(const char* lpszname, const char* lpszvalue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszname), (void*)IBG64CAST(lpszvalue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 3, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GData_Do(m_pObj, 4, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int CreateEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline int DeleteEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 6, 0, param, cbparam);
      
      
    }
    inline int GetACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 7, 0, param, cbparam);
      
      
    }
    inline char* GetProperty(const char* lpszPropertyName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszPropertyName), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GData_Do(m_pObj, 8, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int QueryFeed() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10, 0, param, cbparam);
      
      
    }
    inline int SendCustomRequest(const char* lpszHTTPMethod, const char* lpszURL, const char* lpszPostData) {
      void *param[3+1] = {(void*)IBG64CAST(lpszHTTPMethod), (void*)IBG64CAST(lpszURL), (void*)IBG64CAST(lpszPostData), 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 11, 3, param, cbparam);
      
      
    }
    inline int UpdateACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 14, 0, param, cbparam);
      
      
    }
    inline int UpdateEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 15, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDataConnectedEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDataDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GDataEndTransferEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR Title;
  LPWSTR ETag;
  int reserved;
} GDataEntryEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GDataErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GDataHeaderEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GDataSetCookieEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GDataSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GDataSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GDataStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDataStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GDataTransferEventParamsW;

typedef struct {
  int Role;
  int ScopeType;
  LPWSTR ScopeValue;
  int Success;
  LPWSTR StatusCode;
  LPWSTR StatusReason;
  int Operation;
  LPWSTR LastUpdated;
  LPWSTR RawEntryXML;
  int reserved;
} GDataUpdateACLResponseEventParamsW;



class GDataW : public GData {

  public: //properties
  








    inline LPWSTR GetACLScopeValue(int iACLIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+5, iACLIndex, 0);
    }

    inline int SetACLScopeValue(int iACLIndex, LPWSTR lpACLScopeValue) {
      return InGoogle_GData_Set(m_pObj, 10000+5, iACLIndex, (void*)lpACLScopeValue, 0);
    }

    inline LPWSTR GetACLStatusCode(int iACLIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+6, iACLIndex, 0);
    }



    inline LPWSTR GetACLStatusReason(int iACLIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+7, iACLIndex, 0);
    }





    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+9, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GData_Set(m_pObj, 10000+9, 0, (void*)lpAuthorization, 0);
    }



    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+11, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+12, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+13, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GData_Set(m_pObj, 10000+13, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+14, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+16, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GData_Set(m_pObj, 10000+16, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline LPWSTR GetEntryAclURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+17, 0, 0);
    }

    inline int SetEntryAclURL(LPWSTR lpEntryAclURL) {
      return InGoogle_GData_Set(m_pObj, 10000+17, 0, (void*)lpEntryAclURL, 0);
    }



    inline LPWSTR GetEntryEditURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+19, 0, 0);
    }

    inline int SetEntryEditURL(LPWSTR lpEntryEditURL) {
      return InGoogle_GData_Set(m_pObj, 10000+19, 0, (void*)lpEntryEditURL, 0);
    }



    inline LPWSTR GetEntryElementAttributes(int iEntryElementIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+21, iEntryElementIndex, 0);
    }

    inline int SetEntryElementAttributes(int iEntryElementIndex, LPWSTR lpEntryElementAttributes) {
      return InGoogle_GData_Set(m_pObj, 10000+21, iEntryElementIndex, (void*)lpEntryElementAttributes, 0);
    }

    inline LPWSTR GetEntryElementName(int iEntryElementIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+22, iEntryElementIndex, 0);
    }

    inline int SetEntryElementName(int iEntryElementIndex, LPWSTR lpEntryElementName) {
      return InGoogle_GData_Set(m_pObj, 10000+22, iEntryElementIndex, (void*)lpEntryElementName, 0);
    }

    inline LPWSTR GetEntryElementValue(int iEntryElementIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+23, iEntryElementIndex, 0);
    }

    inline int SetEntryElementValue(int iEntryElementIndex, LPWSTR lpEntryElementValue) {
      return InGoogle_GData_Set(m_pObj, 10000+23, iEntryElementIndex, (void*)lpEntryElementValue, 0);
    }



    inline LPWSTR GetEntryElementXPath(int iEntryElementIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+25, iEntryElementIndex, 0);
    }



    inline LPWSTR GetEntryETag() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+26, 0, 0);
    }

    inline int SetEntryETag(LPWSTR lpEntryETag) {
      return InGoogle_GData_Set(m_pObj, 10000+26, 0, (void*)lpEntryETag, 0);
    }



    inline LPWSTR GetFeedAuthor() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+28, 0, 0);
    }



    inline LPWSTR GetFeedAuthorUri() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+29, 0, 0);
    }



    inline LPWSTR GetFeedCategoryLabel() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+30, 0, 0);
    }



    inline LPWSTR GetFeedCategoryScheme() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+31, 0, 0);
    }



    inline LPWSTR GetFeedCategoryTerm() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+32, 0, 0);
    }



    inline LPWSTR GetFeedEditURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+33, 0, 0);
    }



    inline LPWSTR GetFeedETag() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+34, 0, 0);
    }



    inline LPWSTR GetFeedGenerator() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+35, 0, 0);
    }



    inline LPWSTR GetFeedId() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+36, 0, 0);
    }



    inline LPWSTR GetFeedNextURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+37, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchItemsPerPage() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+38, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchStartIndex() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+39, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchTotalResults() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+40, 0, 0);
    }



    inline LPWSTR GetFeedPreviousURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+41, 0, 0);
    }



    inline LPWSTR GetFeedSelfURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+42, 0, 0);
    }



    inline LPWSTR GetFeedTitle() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+43, 0, 0);
    }



    inline LPWSTR GetFeedUpdated() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+44, 0, 0);
    }



    inline LPWSTR GetFeedURL() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+45, 0, 0);
    }

    inline int SetFeedURL(LPWSTR lpFeedURL) {
      return InGoogle_GData_Set(m_pObj, 10000+45, 0, (void*)lpFeedURL, 0);
    }





    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+48, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GData_Set(m_pObj, 10000+48, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+49, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GData_Set(m_pObj, 10000+49, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+51, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GData_Set(m_pObj, 10000+51, 0, (void*)lpFirewallUser, 0);
    }



    inline LPWSTR GetLocalFile() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+10000+53, 0, 0);
    }

    inline int SetLocalFile(LPWSTR lpLocalFile) {
      return InGoogle_GData_Set(m_pObj, 10000+10000+53, 0, (void*)lpLocalFile, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+54, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GData_Set(m_pObj, 10000+54, 0, (void*)lpLocalHost, 0);
    }



    inline LPWSTR GetNamespacePrefix(int iNamespaceIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+56, iNamespaceIndex, 0);
    }

    inline int SetNamespacePrefix(int iNamespaceIndex, LPWSTR lpNamespacePrefix) {
      return InGoogle_GData_Set(m_pObj, 10000+56, iNamespaceIndex, (void*)lpNamespacePrefix, 0);
    }

    inline LPWSTR GetNamespaceURI(int iNamespaceIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+57, iNamespaceIndex, 0);
    }

    inline int SetNamespaceURI(int iNamespaceIndex, LPWSTR lpNamespaceURI) {
      return InGoogle_GData_Set(m_pObj, 10000+57, iNamespaceIndex, (void*)lpNamespaceURI, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+58, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GData_Set(m_pObj, 10000+58, 0, (void*)lpOtherHeaders, 0);
    }



    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+60, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+61, iParsedHeaderIndex, 0);
    }







    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+64, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GData_Set(m_pObj, 10000+64, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+66, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GData_Set(m_pObj, 10000+66, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+68, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GData_Set(m_pObj, 10000+68, 0, (void*)lpProxyUser, 0);
    }



    inline LPWSTR GetQueryParamsName(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+70, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, LPWSTR lpQueryParamsName) {
      return InGoogle_GData_Set(m_pObj, 10000+70, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline LPWSTR GetQueryParamsValue(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+71, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, LPWSTR lpQueryParamsValue) {
      return InGoogle_GData_Set(m_pObj, 10000+71, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+72, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 10000+72, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 72, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 72, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+73, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 10000+73, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 73, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GData_Set(m_pObj, 73, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+74, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GData_Set(m_pObj, 10000+74, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GData_Get(m_pObj, 74, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GData_Set(m_pObj, 74, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+75, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GData_Set(m_pObj, 10000+75, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+77, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GData_Set(m_pObj, 10000+77, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+78, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GData_Get(m_pObj, 78, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }



    inline LPWSTR GetTransferredData() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+80, 0, 0);
    }


    inline int GetTransferredDataB(char *&lpTransferredData, int &lenTransferredData) {
      lpTransferredData = (char*)InGoogle_GData_Get(m_pObj, 80, 0, &lenTransferredData);
      return lpTransferredData ? 0 : lenTransferredData;
    }



    inline LPWSTR GetAttrName(int iAttrIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+82, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrNamespace(int iAttrIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+83, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrPrefix(int iAttrIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+84, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrValue(int iAttrIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+85, iAttrIndex, 0);
    }





    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+87, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildNamespace(int iXChildIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+88, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildPrefix(int iXChildIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+89, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+90, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+91, 0, 0);
    }



    inline LPWSTR GetXNamespace() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+92, 0, 0);
    }



    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+93, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+94, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GData_Set(m_pObj, 10000+94, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXPrefix() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+95, 0, 0);
    }



    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+96, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GData_Get(m_pObj, 10000+97, 0, 0);
    }





  public: //events
  
    virtual int FireConnected(GDataConnectedEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GDataDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GDataEndTransferEventParamsW *e) {return 0;}
    virtual int FireEntry(GDataEntryEventParamsW *e) {return 0;}
    virtual int FireError(GDataErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GDataHeaderEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GDataSetCookieEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GDataSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GDataSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GDataStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GDataStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GDataTransferEventParamsW *e) {return 0;}
    virtual int FireUpdateACLResponse(GDataUpdateACLResponseEventParamsW *e) {return 0;}


  protected:
  
    virtual int GDataEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GDataConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 2: {
            GDataDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 3: {
            GDataEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 4: {
            GDataEntryEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireEntry(&e);
            break;
         }
         case 5: {
            GDataErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 6: {
            GDataHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 7: {
            GDataSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 8: {
            GDataSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 9: {
            GDataSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 10: {
            GDataStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 11: {
            GDataStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 12: {
            GDataTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }
         case 13: {
            GDataUpdateACLResponseEventParamsW e = {(int)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (int)IBG64CAST(param[6]), (LPWSTR)IBG64CAST(param[7]), (LPWSTR)IBG64CAST(param[8]),  0};
            ret_code = FireUpdateACLResponse(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireConnected(GDataConnectedEventParams *e) {return -10000;}
    virtual int FireDisconnected(GDataDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GDataEndTransferEventParams *e) {return -10000;}
    virtual int FireEntry(GDataEntryEventParams *e) {return -10000;}
    virtual int FireError(GDataErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GDataHeaderEventParams *e) {return -10000;}
    virtual int FireSetCookie(GDataSetCookieEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GDataSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GDataSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GDataStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GDataStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GDataTransferEventParams *e) {return -10000;}
    virtual int FireUpdateACLResponse(GDataUpdateACLResponseEventParams *e) {return -10000;}

  public: //methods

    inline int AddNamespace(LPWSTR lpszPrefix, LPWSTR lpszNamespaceURI) {
      void *param[2+1] = {(void*)lpszPrefix, (void*)lpszNamespaceURI, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline int AddQueryParam(LPWSTR lpszname, LPWSTR lpszvalue) {
      void *param[2+1] = {(void*)lpszname, (void*)lpszvalue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 10000+3, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GData_Do(m_pObj, 10000+4, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int CreateEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline int DeleteEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+6, 0, param, cbparam);
      
    }
    inline int GetACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+7, 0, param, cbparam);
      
    }
    inline LPWSTR GetProperty(LPWSTR lpszPropertyName) {
      void *param[1+1] = {(void*)lpszPropertyName, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GData_Do(m_pObj, 10000+8, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int QueryFeed() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+10, 0, param, cbparam);
      
    }
    inline int SendCustomRequest(LPWSTR lpszHTTPMethod, LPWSTR lpszURL, LPWSTR lpszPostData) {
      void *param[3+1] = {(void*)lpszHTTPMethod, (void*)lpszURL, (void*)lpszPostData, 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      return InGoogle_GData_Do(m_pObj, 10000+11, 3, param, cbparam);
      
    }
    inline int UpdateACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+14, 0, param, cbparam);
      
    }
    inline int UpdateEntry() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GData_Do(m_pObj, 10000+15, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GDATA_H_




