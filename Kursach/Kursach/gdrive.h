/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GDRIVE_H_
#define _INGOOGLE_GDRIVE_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//FirewallTypes
#define FW_NONE                                            0
#define FW_TUNNEL                                          1
#define FW_SOCKS4                                          2
#define FW_SOCKS5                                          3

//GDrivePermissionRole
#define GDPR_READER                                        0
#define GDPR_WRITER                                        1
#define GDPR_OWNER                                         2

//GDrivePermissionType
#define GDPT_USER                                          0
#define GDPT_GROUP                                         1
#define GDPT_DOMAIN                                        2
#define GDPT_ANYONE                                        3

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

//GDriveResourceType
#define GDRT_FILE                                          0
#define GDRT_FOLDER                                        1

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


extern "C" void* INGOOGLE_CALL InGoogle_GDrive_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GDrive_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GDrive_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GDrive_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* Id;
  const char* FileId;
  int Deleted;
  int reserved;
} GDriveChangeListEventParams;

typedef struct {
  const char* Id;
  const char* Link;
  int reserved;
} GDriveChildListEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GDriveConnectedEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GDriveDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GDriveEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GDriveErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GDriveHeaderEventParams;

typedef struct {
  const char* Id;
  int Root;
  int reserved;
} GDriveParentListEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  int Role;
  int PermissionType;
  const char* Value;
  int reserved;
} GDrivePermissionListEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* Title;
  const char* Description;
  int ResourceType;
  const char* Extension;
  int reserved;
} GDriveResourceListEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GDriveSetCookieEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GDriveSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GDriveSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GDriveStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GDriveStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GDriveTransferEventParams;



class GDrive {
  
  public: //events
  
    virtual int FireChangeList(GDriveChangeListEventParams *e) {return 0;}
    virtual int FireChildList(GDriveChildListEventParams *e) {return 0;}
    virtual int FireConnected(GDriveConnectedEventParams *e) {return 0;}
    virtual int FireDisconnected(GDriveDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GDriveEndTransferEventParams *e) {return 0;}
    virtual int FireError(GDriveErrorEventParams *e) {return 0;}
    virtual int FireHeader(GDriveHeaderEventParams *e) {return 0;}
    virtual int FireParentList(GDriveParentListEventParams *e) {return 0;}
    virtual int FirePermissionList(GDrivePermissionListEventParams *e) {return 0;}
    virtual int FireResourceList(GDriveResourceListEventParams *e) {return 0;}
    virtual int FireSetCookie(GDriveSetCookieEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GDriveSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GDriveSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GDriveStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GDriveStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GDriveTransferEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GDriveEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GDrive*)lpObj)->GDriveEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GDriveChangeListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]),  0};
            ret_code = ((GDrive*)lpObj)->FireChangeList(&e);
            break;
         }
         case 2: {
            GDriveChildListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireChildList(&e);
            break;
         }
         case 3: {
            GDriveConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireConnected(&e);
            break;
         }
         case 4: {
            GDriveDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 5: {
            GDriveEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GDrive*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 6: {
            GDriveErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireError(&e);
            break;
         }
         case 7: {
            GDriveHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireHeader(&e);
            break;
         }
         case 8: {
            GDriveParentListEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]),  0};
            ret_code = ((GDrive*)lpObj)->FireParentList(&e);
            break;
         }
         case 9: {
            GDrivePermissionListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]),  0};
            ret_code = ((GDrive*)lpObj)->FirePermissionList(&e);
            break;
         }
         case 10: {
            GDriveResourceListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]),  0};
            ret_code = ((GDrive*)lpObj)->FireResourceList(&e);
            break;
         }
         case 11: {
            GDriveSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GDrive*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 12: {
            GDriveSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GDrive*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 13: {
            GDriveSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GDrive*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 14: {
            GDriveStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GDrive*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 15: {
            GDriveStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GDrive*)lpObj)->FireStatus(&e);
            break;
         }
         case 16: {
            GDriveTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GDrive*)lpObj)->FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GDriveEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GDrive(char *lpOemKey = (char*)INGOOGLE_OEMKEY_80) {
      m_pObj = InGoogle_GDrive_Create(GDriveEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GDrive() {
      InGoogle_GDrive_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GDrive_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GDrive_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GDrive_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline char* GetAuthorization() {
      void* val = InGoogle_GDrive_Get(m_pObj, 1, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GDrive_Set(m_pObj, 1, 0, (void*)lpAuthorization, 0);
    }

    inline char* GetChangeMarker() {
      void* val = InGoogle_GDrive_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }

    inline int SetChangeMarker(const char *lpChangeMarker) {
      return InGoogle_GDrive_Set(m_pObj, 2, 0, (void*)lpChangeMarker, 0);
    }

    inline int GetChangeCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 3, 0, 0);
      return (int)(long)val;
    }
    inline int SetChangeCount(int iChangeCount) {
      void* val = (void*)IBG64CAST(iChangeCount);
      return InGoogle_GDrive_Set(m_pObj, 3, 0, val, 0);
    }
    inline int GetChangeDeleted(int iChangeIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 4, iChangeIndex, 0);
      return (int)(long)val;
    }
    inline int SetChangeDeleted(int iChangeIndex, int bChangeDeleted) {
      void* val = (void*)IBG64CAST(bChangeDeleted);
      return InGoogle_GDrive_Set(m_pObj, 4, iChangeIndex, val, 0);
    }
    inline char* GetChangeId(int iChangeIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 5, iChangeIndex, 0);
      return (char*)val;
    }

    inline int SetChangeId(int iChangeIndex, const char *lpChangeId) {
      return InGoogle_GDrive_Set(m_pObj, 5, iChangeIndex, (void*)lpChangeId, 0);
    }

    inline char* GetChangeResourceId(int iChangeIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 6, iChangeIndex, 0);
      return (char*)val;
    }

    inline int SetChangeResourceId(int iChangeIndex, const char *lpChangeResourceId) {
      return InGoogle_GDrive_Set(m_pObj, 6, iChangeIndex, (void*)lpChangeResourceId, 0);
    }

    inline char* GetChildMarker() {
      void* val = InGoogle_GDrive_Get(m_pObj, 7, 0, 0);
      return (char*)val;
    }

    inline int SetChildMarker(const char *lpChildMarker) {
      return InGoogle_GDrive_Set(m_pObj, 7, 0, (void*)lpChildMarker, 0);
    }

    inline int GetConvertDocument() {
      void* val = InGoogle_GDrive_Get(m_pObj, 8, 0, 0);
      return (int)(long)val;
    }
    inline int SetConvertDocument(int bConvertDocument) {
      void* val = (void*)IBG64CAST(bConvertDocument);
      return InGoogle_GDrive_Set(m_pObj, 8, 0, val, 0);
    }
    inline int GetCookieCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 9, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GDrive_Set(m_pObj, 9, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 10, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 11, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 12, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GDrive_Set(m_pObj, 12, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 13, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 14, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 15, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GDrive_Set(m_pObj, 15, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GDrive_Get(m_pObj, 16, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GDrive_Set(m_pObj, 16, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GDrive_Get(m_pObj, 17, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GDrive_Set(m_pObj, 17, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GDrive_Get(m_pObj, 18, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GDrive_Set(m_pObj, 18, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GDrive_Get(m_pObj, 19, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GDrive_Set(m_pObj, 19, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GDrive_Get(m_pObj, 20, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GDrive_Set(m_pObj, 20, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GDrive_Get(m_pObj, 21, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GDrive_Set(m_pObj, 21, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GDrive_Get(m_pObj, 22, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLocalFile() {
      void* val = InGoogle_GDrive_Get(m_pObj, 23, 0, 0);
      return (char*)val;
    }

    inline int SetLocalFile(const char *lpLocalFile) {
      return InGoogle_GDrive_Set(m_pObj, 23, 0, (void*)lpLocalFile, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GDrive_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GDrive_Set(m_pObj, 24, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GDrive_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GDrive_Set(m_pObj, 25, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetOverwrite() {
      void* val = InGoogle_GDrive_Get(m_pObj, 26, 0, 0);
      return (int)(long)val;
    }
    inline int SetOverwrite(int bOverwrite) {
      void* val = (void*)IBG64CAST(bOverwrite);
      return InGoogle_GDrive_Set(m_pObj, 26, 0, val, 0);
    }
    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 27, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 28, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 29, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetPermissionAdditionalRoles() {
      void* val = InGoogle_GDrive_Get(m_pObj, 30, 0, 0);
      return (char*)val;
    }

    inline int SetPermissionAdditionalRoles(const char *lpPermissionAdditionalRoles) {
      return InGoogle_GDrive_Set(m_pObj, 30, 0, (void*)lpPermissionAdditionalRoles, 0);
    }

    inline int GetPermissionCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 31, 0, 0);
      return (int)(long)val;
    }

    inline char* GetPermissionETag() {
      void* val = InGoogle_GDrive_Get(m_pObj, 32, 0, 0);
      return (char*)val;
    }


    inline char* GetPermissionId() {
      void* val = InGoogle_GDrive_Get(m_pObj, 33, 0, 0);
      return (char*)val;
    }

    inline int SetPermissionId(const char *lpPermissionId) {
      return InGoogle_GDrive_Set(m_pObj, 33, 0, (void*)lpPermissionId, 0);
    }

    inline int GetPermissionIndex() {
      void* val = InGoogle_GDrive_Get(m_pObj, 34, 0, 0);
      return (int)(long)val;
    }
    inline int SetPermissionIndex(int iPermissionIndex) {
      void* val = (void*)IBG64CAST(iPermissionIndex);
      return InGoogle_GDrive_Set(m_pObj, 34, 0, val, 0);
    }
    inline char* GetPermissionMarker() {
      void* val = InGoogle_GDrive_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }

    inline int SetPermissionMarker(const char *lpPermissionMarker) {
      return InGoogle_GDrive_Set(m_pObj, 35, 0, (void*)lpPermissionMarker, 0);
    }

    inline int GetPermissionRole() {
      void* val = InGoogle_GDrive_Get(m_pObj, 36, 0, 0);
      return (int)(long)val;
    }
    inline int SetPermissionRole(int iPermissionRole) {
      void* val = (void*)IBG64CAST(iPermissionRole);
      return InGoogle_GDrive_Set(m_pObj, 36, 0, val, 0);
    }
    inline int GetPermissionType() {
      void* val = InGoogle_GDrive_Get(m_pObj, 37, 0, 0);
      return (int)(long)val;
    }
    inline int SetPermissionType(int iPermissionType) {
      void* val = (void*)IBG64CAST(iPermissionType);
      return InGoogle_GDrive_Set(m_pObj, 37, 0, val, 0);
    }
    inline char* GetPermissionValue() {
      void* val = InGoogle_GDrive_Get(m_pObj, 38, 0, 0);
      return (char*)val;
    }

    inline int SetPermissionValue(const char *lpPermissionValue) {
      return InGoogle_GDrive_Set(m_pObj, 38, 0, (void*)lpPermissionValue, 0);
    }

    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GDrive_Get(m_pObj, 39, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GDrive_Set(m_pObj, 39, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GDrive_Get(m_pObj, 40, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GDrive_Set(m_pObj, 40, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GDrive_Get(m_pObj, 41, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GDrive_Set(m_pObj, 41, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GDrive_Get(m_pObj, 42, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GDrive_Set(m_pObj, 42, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GDrive_Get(m_pObj, 43, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GDrive_Set(m_pObj, 43, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GDrive_Get(m_pObj, 44, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GDrive_Set(m_pObj, 44, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GDrive_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GDrive_Set(m_pObj, 45, 0, (void*)lpProxyUser, 0);
    }

    inline int GetQueryParamsCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 46, 0, 0);
      return (int)(long)val;
    }
    inline int SetQueryParamsCount(int iQueryParamsCount) {
      void* val = (void*)IBG64CAST(iQueryParamsCount);
      return InGoogle_GDrive_Set(m_pObj, 46, 0, val, 0);
    }
    inline char* GetQueryParamsName(int iQueryParamsIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 47, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, const char *lpQueryParamsName) {
      return InGoogle_GDrive_Set(m_pObj, 47, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline char* GetQueryParamsValue(int iQueryParamsIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 48, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, const char *lpQueryParamsValue) {
      return InGoogle_GDrive_Set(m_pObj, 48, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline int GetResourceChildCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 49, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceChildCount(int iResourceChildCount) {
      void* val = (void*)IBG64CAST(iResourceChildCount);
      return InGoogle_GDrive_Set(m_pObj, 49, 0, val, 0);
    }
    inline char* GetResourceChildId(int iResourceChildIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 50, iResourceChildIndex, 0);
      return (char*)val;
    }

    inline int SetResourceChildId(int iResourceChildIndex, const char *lpResourceChildId) {
      return InGoogle_GDrive_Set(m_pObj, 50, iResourceChildIndex, (void*)lpResourceChildId, 0);
    }

    inline char* GetResourceChildLink(int iResourceChildIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 51, iResourceChildIndex, 0);
      return (char*)val;
    }

    inline int SetResourceChildLink(int iResourceChildIndex, const char *lpResourceChildLink) {
      return InGoogle_GDrive_Set(m_pObj, 51, iResourceChildIndex, (void*)lpResourceChildLink, 0);
    }

    inline int GetResourceCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 52, 0, 0);
      return (int)(long)val;
    }

    inline char* GetResourceCreatedDate() {
      void* val = InGoogle_GDrive_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }


    inline int GetResourceData(char *&lpResourceData, int &lenResourceData) {
      lpResourceData = (char*)InGoogle_GDrive_Get(m_pObj, 54, 0, &lenResourceData);
      return lpResourceData ? 0 : lenResourceData;
    }

    inline int SetResourceData(const char *lpResourceData, int lenResourceData) {
      return InGoogle_GDrive_Set(m_pObj, 54, 0, (void*)lpResourceData, lenResourceData);
    }

    inline char* GetResourceDescription() {
      void* val = InGoogle_GDrive_Get(m_pObj, 55, 0, 0);
      return (char*)val;
    }

    inline int SetResourceDescription(const char *lpResourceDescription) {
      return InGoogle_GDrive_Set(m_pObj, 55, 0, (void*)lpResourceDescription, 0);
    }

    inline char* GetResourceETag() {
      void* val = InGoogle_GDrive_Get(m_pObj, 56, 0, 0);
      return (char*)val;
    }


    inline char* GetResourceExtension() {
      void* val = InGoogle_GDrive_Get(m_pObj, 57, 0, 0);
      return (char*)val;
    }


    inline char* GetResourceFormats() {
      void* val = InGoogle_GDrive_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }


    inline int GetResourceHidden() {
      void* val = InGoogle_GDrive_Get(m_pObj, 59, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceHidden(int bResourceHidden) {
      void* val = (void*)IBG64CAST(bResourceHidden);
      return InGoogle_GDrive_Set(m_pObj, 59, 0, val, 0);
    }
    inline char* GetResourceId() {
      void* val = InGoogle_GDrive_Get(m_pObj, 60, 0, 0);
      return (char*)val;
    }

    inline int SetResourceId(const char *lpResourceId) {
      return InGoogle_GDrive_Set(m_pObj, 60, 0, (void*)lpResourceId, 0);
    }

    inline int GetResourceIndex() {
      void* val = InGoogle_GDrive_Get(m_pObj, 61, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceIndex(int iResourceIndex) {
      void* val = (void*)IBG64CAST(iResourceIndex);
      return InGoogle_GDrive_Set(m_pObj, 61, 0, val, 0);
    }
    inline char* GetResourceMarker() {
      void* val = InGoogle_GDrive_Get(m_pObj, 62, 0, 0);
      return (char*)val;
    }

    inline int SetResourceMarker(const char *lpResourceMarker) {
      return InGoogle_GDrive_Set(m_pObj, 62, 0, (void*)lpResourceMarker, 0);
    }

    inline char* GetResourceMD5Checksum() {
      void* val = InGoogle_GDrive_Get(m_pObj, 63, 0, 0);
      return (char*)val;
    }


    inline char* GetResourceMIMEType() {
      void* val = InGoogle_GDrive_Get(m_pObj, 64, 0, 0);
      return (char*)val;
    }

    inline int SetResourceMIMEType(const char *lpResourceMIMEType) {
      return InGoogle_GDrive_Set(m_pObj, 64, 0, (void*)lpResourceMIMEType, 0);
    }

    inline char* GetResourceModifiedDate() {
      void* val = InGoogle_GDrive_Get(m_pObj, 65, 0, 0);
      return (char*)val;
    }


    inline char* GetResourceOriginalName() {
      void* val = InGoogle_GDrive_Get(m_pObj, 66, 0, 0);
      return (char*)val;
    }


    inline char* GetResourceOwners() {
      void* val = InGoogle_GDrive_Get(m_pObj, 67, 0, 0);
      return (char*)val;
    }


    inline int GetResourceParentCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 68, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceParentCount(int iResourceParentCount) {
      void* val = (void*)IBG64CAST(iResourceParentCount);
      return InGoogle_GDrive_Set(m_pObj, 68, 0, val, 0);
    }
    inline char* GetResourceParentId(int iResourceParentIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 69, iResourceParentIndex, 0);
      return (char*)val;
    }

    inline int SetResourceParentId(int iResourceParentIndex, const char *lpResourceParentId) {
      return InGoogle_GDrive_Set(m_pObj, 69, iResourceParentIndex, (void*)lpResourceParentId, 0);
    }

    inline int GetResourceParentRoot(int iResourceParentIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 70, iResourceParentIndex, 0);
      return (int)(long)val;
    }
    inline int SetResourceParentRoot(int iResourceParentIndex, int bResourceParentRoot) {
      void* val = (void*)IBG64CAST(bResourceParentRoot);
      return InGoogle_GDrive_Set(m_pObj, 70, iResourceParentIndex, val, 0);
    }
    inline int GetResourceRestricted() {
      void* val = InGoogle_GDrive_Get(m_pObj, 71, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceRestricted(int bResourceRestricted) {
      void* val = (void*)IBG64CAST(bResourceRestricted);
      return InGoogle_GDrive_Set(m_pObj, 71, 0, val, 0);
    }
    inline ns_int64 GetResourceSize() {
      ns_int64 *pval = (ns_int64*)InGoogle_GDrive_Get(m_pObj, 72, 0, 0);
      return *pval;
    }


    inline int GetResourceStarred() {
      void* val = InGoogle_GDrive_Get(m_pObj, 73, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceStarred(int bResourceStarred) {
      void* val = (void*)IBG64CAST(bResourceStarred);
      return InGoogle_GDrive_Set(m_pObj, 73, 0, val, 0);
    }
    inline char* GetResourceTitle() {
      void* val = InGoogle_GDrive_Get(m_pObj, 74, 0, 0);
      return (char*)val;
    }

    inline int SetResourceTitle(const char *lpResourceTitle) {
      return InGoogle_GDrive_Set(m_pObj, 74, 0, (void*)lpResourceTitle, 0);
    }

    inline int GetResourceTrashed() {
      void* val = InGoogle_GDrive_Get(m_pObj, 75, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceTrashed(int bResourceTrashed) {
      void* val = (void*)IBG64CAST(bResourceTrashed);
      return InGoogle_GDrive_Set(m_pObj, 75, 0, val, 0);
    }
    inline int GetResourceType() {
      void* val = InGoogle_GDrive_Get(m_pObj, 76, 0, 0);
      return (int)(long)val;
    }

    inline int GetResourceViewed() {
      void* val = InGoogle_GDrive_Get(m_pObj, 77, 0, 0);
      return (int)(long)val;
    }
    inline int SetResourceViewed(int bResourceViewed) {
      void* val = (void*)IBG64CAST(bResourceViewed);
      return InGoogle_GDrive_Set(m_pObj, 77, 0, val, 0);
    }
    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 78, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 78, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 79, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 79, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GDrive_Get(m_pObj, 80, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GDrive_Set(m_pObj, 80, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GDrive_Get(m_pObj, 81, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GDrive_Set(m_pObj, 81, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GDrive_Get(m_pObj, 82, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GDrive_Set(m_pObj, 82, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GDrive_Get(m_pObj, 83, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GDrive_Set(m_pObj, 83, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 84, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GDrive_Get(m_pObj, 85, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GDrive_Set(m_pObj, 85, 0, val, 0);
    }
    inline int GetXChildrenCount() {
      void* val = InGoogle_GDrive_Get(m_pObj, 86, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 87, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GDrive_Get(m_pObj, 88, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GDrive_Get(m_pObj, 89, 0, 0);
      return (char*)val;
    }


    inline char* GetXParent() {
      void* val = InGoogle_GDrive_Get(m_pObj, 90, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GDrive_Get(m_pObj, 91, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GDrive_Set(m_pObj, 91, 0, (void*)lpXPath, 0);
    }

    inline char* GetXSubTree() {
      void* val = InGoogle_GDrive_Get(m_pObj, 92, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GDrive_Get(m_pObj, 93, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline char* AddChild(const char* lpszChildId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszChildId), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 2, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline char* AddParent(const char* lpszparentId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszparentId), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 3, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline char* AddPermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GDrive_Do(m_pObj, 4, 0, param, cbparam);
      
      return (char*)IBG64CAST(param[0]);
    }
    inline int AddQueryParam(const char* lpszname, const char* lpszvalue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszname), (void*)IBG64CAST(lpszvalue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GDrive_Do(m_pObj, 5, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 6, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline char* CopyResource(const char* lpszresourceTitle) {
      void *param[1+1] = {(void*)IBG64CAST(lpszresourceTitle), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 7, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline char* CreateFolder(const char* lpszfolderTitle) {
      void *param[1+1] = {(void*)IBG64CAST(lpszfolderTitle), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 8, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int DeleteChild(const char* lpszchildId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszchildId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 9, 1, param, cbparam);
      
      
    }
    inline int DeleteParent(const char* lpszparentId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszparentId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10, 1, param, cbparam);
      
      
    }
    inline int DeletePermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 11, 0, param, cbparam);
      
      
    }
    inline int DeleteResource() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 12, 0, param, cbparam);
      
      
    }
    inline int DownloadFile(const char* lpszfileFormat) {
      void *param[1+1] = {(void*)IBG64CAST(lpszfileFormat), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 13, 1, param, cbparam);
      
      
    }
    inline int GetResourceInfo(const char* lpszResourceId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszResourceId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 14, 1, param, cbparam);
      
      
    }
    inline int ListChanges(const char* lpszStartChangeId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszStartChangeId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 15, 1, param, cbparam);
      
      
    }
    inline int ListChildren() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 16, 0, param, cbparam);
      
      
    }
    inline int ListParents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 17, 0, param, cbparam);
      
      
    }
    inline int ListPermissions() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 18, 0, param, cbparam);
      
      
    }
    inline int ListResources() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 19, 0, param, cbparam);
      
      
    }
    inline int MoveToTrash() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 20, 0, param, cbparam);
      
      
    }
    inline int RestoreFromTrash() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 21, 0, param, cbparam);
      
      
    }
    inline int UpdatePermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 24, 0, param, cbparam);
      
      
    }
    inline int UpdateResource() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 25, 0, param, cbparam);
      
      
    }
    inline char* UploadFile(const char* lpszfileTitle) {
      void *param[1+1] = {(void*)IBG64CAST(lpszfileTitle), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 26, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR Id;
  LPWSTR FileId;
  int Deleted;
  int reserved;
} GDriveChangeListEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR Link;
  int reserved;
} GDriveChildListEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDriveConnectedEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDriveDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GDriveEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GDriveErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GDriveHeaderEventParamsW;

typedef struct {
  LPWSTR Id;
  int Root;
  int reserved;
} GDriveParentListEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  int Role;
  int PermissionType;
  LPWSTR Value;
  int reserved;
} GDrivePermissionListEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR Title;
  LPWSTR Description;
  int ResourceType;
  LPWSTR Extension;
  int reserved;
} GDriveResourceListEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GDriveSetCookieEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GDriveSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GDriveSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GDriveStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GDriveStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GDriveTransferEventParamsW;



class GDriveW : public GDrive {

  public: //properties
  
    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+1, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GDrive_Set(m_pObj, 10000+1, 0, (void*)lpAuthorization, 0);
    }

    inline LPWSTR GetChangeMarker() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+2, 0, 0);
    }

    inline int SetChangeMarker(LPWSTR lpChangeMarker) {
      return InGoogle_GDrive_Set(m_pObj, 10000+2, 0, (void*)lpChangeMarker, 0);
    }





    inline LPWSTR GetChangeId(int iChangeIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+5, iChangeIndex, 0);
    }

    inline int SetChangeId(int iChangeIndex, LPWSTR lpChangeId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+5, iChangeIndex, (void*)lpChangeId, 0);
    }

    inline LPWSTR GetChangeResourceId(int iChangeIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+6, iChangeIndex, 0);
    }

    inline int SetChangeResourceId(int iChangeIndex, LPWSTR lpChangeResourceId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+6, iChangeIndex, (void*)lpChangeResourceId, 0);
    }

    inline LPWSTR GetChildMarker() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+7, 0, 0);
    }

    inline int SetChildMarker(LPWSTR lpChildMarker) {
      return InGoogle_GDrive_Set(m_pObj, 10000+7, 0, (void*)lpChildMarker, 0);
    }





    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+10, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+11, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+12, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GDrive_Set(m_pObj, 10000+12, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+13, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+15, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GDrive_Set(m_pObj, 10000+15, iCookieIndex, (void*)lpCookieValue, 0);
    }





    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+18, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GDrive_Set(m_pObj, 10000+18, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+19, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GDrive_Set(m_pObj, 10000+19, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+21, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GDrive_Set(m_pObj, 10000+21, 0, (void*)lpFirewallUser, 0);
    }



    inline LPWSTR GetLocalFile() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+10000+23, 0, 0);
    }

    inline int SetLocalFile(LPWSTR lpLocalFile) {
      return InGoogle_GDrive_Set(m_pObj, 10000+10000+23, 0, (void*)lpLocalFile, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+24, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GDrive_Set(m_pObj, 10000+24, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+25, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GDrive_Set(m_pObj, 10000+25, 0, (void*)lpOtherHeaders, 0);
    }





    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+28, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+29, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetPermissionAdditionalRoles() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+30, 0, 0);
    }

    inline int SetPermissionAdditionalRoles(LPWSTR lpPermissionAdditionalRoles) {
      return InGoogle_GDrive_Set(m_pObj, 10000+30, 0, (void*)lpPermissionAdditionalRoles, 0);
    }



    inline LPWSTR GetPermissionETag() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+32, 0, 0);
    }



    inline LPWSTR GetPermissionId() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+33, 0, 0);
    }

    inline int SetPermissionId(LPWSTR lpPermissionId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+33, 0, (void*)lpPermissionId, 0);
    }



    inline LPWSTR GetPermissionMarker() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+35, 0, 0);
    }

    inline int SetPermissionMarker(LPWSTR lpPermissionMarker) {
      return InGoogle_GDrive_Set(m_pObj, 10000+35, 0, (void*)lpPermissionMarker, 0);
    }





    inline LPWSTR GetPermissionValue() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+38, 0, 0);
    }

    inline int SetPermissionValue(LPWSTR lpPermissionValue) {
      return InGoogle_GDrive_Set(m_pObj, 10000+38, 0, (void*)lpPermissionValue, 0);
    }





    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+41, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GDrive_Set(m_pObj, 10000+41, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+43, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GDrive_Set(m_pObj, 10000+43, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+45, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GDrive_Set(m_pObj, 10000+45, 0, (void*)lpProxyUser, 0);
    }



    inline LPWSTR GetQueryParamsName(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+47, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, LPWSTR lpQueryParamsName) {
      return InGoogle_GDrive_Set(m_pObj, 10000+47, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline LPWSTR GetQueryParamsValue(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+48, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, LPWSTR lpQueryParamsValue) {
      return InGoogle_GDrive_Set(m_pObj, 10000+48, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }



    inline LPWSTR GetResourceChildId(int iResourceChildIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+50, iResourceChildIndex, 0);
    }

    inline int SetResourceChildId(int iResourceChildIndex, LPWSTR lpResourceChildId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+50, iResourceChildIndex, (void*)lpResourceChildId, 0);
    }

    inline LPWSTR GetResourceChildLink(int iResourceChildIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+51, iResourceChildIndex, 0);
    }

    inline int SetResourceChildLink(int iResourceChildIndex, LPWSTR lpResourceChildLink) {
      return InGoogle_GDrive_Set(m_pObj, 10000+51, iResourceChildIndex, (void*)lpResourceChildLink, 0);
    }



    inline LPWSTR GetResourceCreatedDate() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+53, 0, 0);
    }



    inline LPWSTR GetResourceData() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+54, 0, 0);
    }

    inline int SetResourceData(LPWSTR lpResourceData) {
      return InGoogle_GDrive_Set(m_pObj, 10000+54, 0, (void*)lpResourceData, 0);
    }
    inline int GetResourceDataB(char *&lpResourceData, int &lenResourceData) {
      lpResourceData = (char*)InGoogle_GDrive_Get(m_pObj, 54, 0, &lenResourceData);
      return lpResourceData ? 0 : lenResourceData;
    }
    inline int SetResourceDataB(const char *lpResourceData, int lenResourceData) {
      return InGoogle_GDrive_Set(m_pObj, 54, 0, (void*)lpResourceData, lenResourceData);
    }
    inline LPWSTR GetResourceDescription() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+55, 0, 0);
    }

    inline int SetResourceDescription(LPWSTR lpResourceDescription) {
      return InGoogle_GDrive_Set(m_pObj, 10000+55, 0, (void*)lpResourceDescription, 0);
    }

    inline LPWSTR GetResourceETag() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+56, 0, 0);
    }



    inline LPWSTR GetResourceExtension() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+57, 0, 0);
    }



    inline LPWSTR GetResourceFormats() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+58, 0, 0);
    }





    inline LPWSTR GetResourceId() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+60, 0, 0);
    }

    inline int SetResourceId(LPWSTR lpResourceId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+60, 0, (void*)lpResourceId, 0);
    }



    inline LPWSTR GetResourceMarker() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+62, 0, 0);
    }

    inline int SetResourceMarker(LPWSTR lpResourceMarker) {
      return InGoogle_GDrive_Set(m_pObj, 10000+62, 0, (void*)lpResourceMarker, 0);
    }

    inline LPWSTR GetResourceMD5Checksum() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+63, 0, 0);
    }



    inline LPWSTR GetResourceMIMEType() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+64, 0, 0);
    }

    inline int SetResourceMIMEType(LPWSTR lpResourceMIMEType) {
      return InGoogle_GDrive_Set(m_pObj, 10000+64, 0, (void*)lpResourceMIMEType, 0);
    }

    inline LPWSTR GetResourceModifiedDate() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+65, 0, 0);
    }



    inline LPWSTR GetResourceOriginalName() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+66, 0, 0);
    }



    inline LPWSTR GetResourceOwners() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+67, 0, 0);
    }





    inline LPWSTR GetResourceParentId(int iResourceParentIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+69, iResourceParentIndex, 0);
    }

    inline int SetResourceParentId(int iResourceParentIndex, LPWSTR lpResourceParentId) {
      return InGoogle_GDrive_Set(m_pObj, 10000+69, iResourceParentIndex, (void*)lpResourceParentId, 0);
    }









    inline LPWSTR GetResourceTitle() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+74, 0, 0);
    }

    inline int SetResourceTitle(LPWSTR lpResourceTitle) {
      return InGoogle_GDrive_Set(m_pObj, 10000+74, 0, (void*)lpResourceTitle, 0);
    }







    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+78, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 10000+78, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 78, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 78, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+79, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 10000+79, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 79, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GDrive_Set(m_pObj, 79, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+80, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GDrive_Set(m_pObj, 10000+80, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GDrive_Get(m_pObj, 80, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GDrive_Set(m_pObj, 80, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+81, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GDrive_Set(m_pObj, 10000+81, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+83, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GDrive_Set(m_pObj, 10000+83, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+84, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GDrive_Get(m_pObj, 84, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }





    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+87, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+88, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+89, 0, 0);
    }



    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+90, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+91, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GDrive_Set(m_pObj, 10000+91, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+92, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GDrive_Get(m_pObj, 10000+93, 0, 0);
    }





  public: //events
  
    virtual int FireChangeList(GDriveChangeListEventParamsW *e) {return 0;}
    virtual int FireChildList(GDriveChildListEventParamsW *e) {return 0;}
    virtual int FireConnected(GDriveConnectedEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GDriveDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GDriveEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GDriveErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GDriveHeaderEventParamsW *e) {return 0;}
    virtual int FireParentList(GDriveParentListEventParamsW *e) {return 0;}
    virtual int FirePermissionList(GDrivePermissionListEventParamsW *e) {return 0;}
    virtual int FireResourceList(GDriveResourceListEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GDriveSetCookieEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GDriveSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GDriveSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GDriveStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GDriveStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GDriveTransferEventParamsW *e) {return 0;}


  protected:
  
    virtual int GDriveEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GDriveChangeListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (int)IBG64CAST(param[2]),  0};
            ret_code = FireChangeList(&e);
            break;
         }
         case 2: {
            GDriveChildListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireChildList(&e);
            break;
         }
         case 3: {
            GDriveConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 4: {
            GDriveDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 5: {
            GDriveEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 6: {
            GDriveErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 7: {
            GDriveHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 8: {
            GDriveParentListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]),  0};
            ret_code = FireParentList(&e);
            break;
         }
         case 9: {
            GDrivePermissionListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]),  0};
            ret_code = FirePermissionList(&e);
            break;
         }
         case 10: {
            GDriveResourceListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]),  0};
            ret_code = FireResourceList(&e);
            break;
         }
         case 11: {
            GDriveSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 12: {
            GDriveSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 13: {
            GDriveSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 14: {
            GDriveStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 15: {
            GDriveStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 16: {
            GDriveTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireChangeList(GDriveChangeListEventParams *e) {return -10000;}
    virtual int FireChildList(GDriveChildListEventParams *e) {return -10000;}
    virtual int FireConnected(GDriveConnectedEventParams *e) {return -10000;}
    virtual int FireDisconnected(GDriveDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GDriveEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GDriveErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GDriveHeaderEventParams *e) {return -10000;}
    virtual int FireParentList(GDriveParentListEventParams *e) {return -10000;}
    virtual int FirePermissionList(GDrivePermissionListEventParams *e) {return -10000;}
    virtual int FireResourceList(GDriveResourceListEventParams *e) {return -10000;}
    virtual int FireSetCookie(GDriveSetCookieEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GDriveSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GDriveSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GDriveStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GDriveStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GDriveTransferEventParams *e) {return -10000;}

  public: //methods

    inline LPWSTR AddChild(LPWSTR lpszChildId) {
      void *param[1+1] = {(void*)lpszChildId, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+2, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline LPWSTR AddParent(LPWSTR lpszparentId) {
      void *param[1+1] = {(void*)lpszparentId, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+3, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline LPWSTR AddPermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GDrive_Do(m_pObj, 10000+4, 0, param, cbparam);
      return (LPWSTR)IBG64CAST(param[0]);
    }
    inline int AddQueryParam(LPWSTR lpszname, LPWSTR lpszvalue) {
      void *param[2+1] = {(void*)lpszname, (void*)lpszvalue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+5, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+6, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline LPWSTR CopyResource(LPWSTR lpszresourceTitle) {
      void *param[1+1] = {(void*)lpszresourceTitle, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+7, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline LPWSTR CreateFolder(LPWSTR lpszfolderTitle) {
      void *param[1+1] = {(void*)lpszfolderTitle, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+8, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int DeleteChild(LPWSTR lpszchildId) {
      void *param[1+1] = {(void*)lpszchildId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+9, 1, param, cbparam);
      
    }
    inline int DeleteParent(LPWSTR lpszparentId) {
      void *param[1+1] = {(void*)lpszparentId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+10, 1, param, cbparam);
      
    }
    inline int DeletePermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+11, 0, param, cbparam);
      
    }
    inline int DeleteResource() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+12, 0, param, cbparam);
      
    }
    inline int DownloadFile(LPWSTR lpszfileFormat) {
      void *param[1+1] = {(void*)lpszfileFormat, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+13, 1, param, cbparam);
      
    }
    inline int GetResourceInfo(LPWSTR lpszResourceId) {
      void *param[1+1] = {(void*)lpszResourceId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+14, 1, param, cbparam);
      
    }
    inline int ListChanges(LPWSTR lpszStartChangeId) {
      void *param[1+1] = {(void*)lpszStartChangeId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GDrive_Do(m_pObj, 10000+15, 1, param, cbparam);
      
    }
    inline int ListChildren() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+16, 0, param, cbparam);
      
    }
    inline int ListParents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+17, 0, param, cbparam);
      
    }
    inline int ListPermissions() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+18, 0, param, cbparam);
      
    }
    inline int ListResources() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+19, 0, param, cbparam);
      
    }
    inline int MoveToTrash() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+20, 0, param, cbparam);
      
    }
    inline int RestoreFromTrash() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+21, 0, param, cbparam);
      
    }
    inline int UpdatePermission() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+24, 0, param, cbparam);
      
    }
    inline int UpdateResource() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GDrive_Do(m_pObj, 10000+25, 0, param, cbparam);
      
    }
    inline LPWSTR UploadFile(LPWSTR lpszfileTitle) {
      void *param[1+1] = {(void*)lpszfileTitle, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GDrive_Do(m_pObj, 10000+26, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }

};

#endif //WIN32

#endif //_INGOOGLE_GDRIVE_H_




