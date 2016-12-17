/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GOOGLEREQUEST_H_
#define _INGOOGLE_GOOGLEREQUEST_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//AuthSchemes
#define AUTH_BASIC                                         0
#define AUTH_DIGEST                                        1
#define AUTH_PROPRIETARY                                   2
#define AUTH_NONE                                          3
#define AUTH_NTLM                                          4
#define AUTH_NEGOTIATE                                     5
#define AUTH_OAUTH                                         6

//FirewallTypes
#define FW_NONE                                            0
#define FW_TUNNEL                                          1
#define FW_SOCKS4                                          2
#define FW_SOCKS5                                          3

//TFollowRedirects
#define FR_NEVER                                           0
#define FR_ALWAYS                                          1
#define FR_SAME_SCHEME                                     2

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


extern "C" void* INGOOGLE_CALL InGoogle_GoogleRequest_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GoogleRequest_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GoogleRequest_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GoogleRequest_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* Text;
  int lenText;
  int reserved;
} GoogleRequestCharactersEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GoogleRequestConnectedEventParams;

typedef struct {
  const char* ConnectionEvent;
  int StatusCode;
  const char* Description;
  int reserved;
} GoogleRequestConnectionStatusEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GoogleRequestDisconnectedEventParams;

typedef struct {
  const char* Element;
  int reserved;
} GoogleRequestEndElementEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GoogleRequestErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GoogleRequestHeaderEventParams;

typedef struct {
  const char* Text;
  int reserved;
} GoogleRequestIgnorableWhitespaceEventParams;

typedef struct {
  const char* Location;
  int Accept;
  int reserved;
} GoogleRequestRedirectEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GoogleRequestSetCookieEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GoogleRequestSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GoogleRequestSSLStatusEventParams;

typedef struct {
  const char* Element;
  int reserved;
} GoogleRequestStartElementEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GoogleRequestStatusEventParams;



class GoogleRequest {
  
  public: //events
  
    virtual int FireCharacters(GoogleRequestCharactersEventParams *e) {return 0;}
    virtual int FireConnected(GoogleRequestConnectedEventParams *e) {return 0;}
    virtual int FireConnectionStatus(GoogleRequestConnectionStatusEventParams *e) {return 0;}
    virtual int FireDisconnected(GoogleRequestDisconnectedEventParams *e) {return 0;}
    virtual int FireEndElement(GoogleRequestEndElementEventParams *e) {return 0;}
    virtual int FireError(GoogleRequestErrorEventParams *e) {return 0;}
    virtual int FireHeader(GoogleRequestHeaderEventParams *e) {return 0;}
    virtual int FireIgnorableWhitespace(GoogleRequestIgnorableWhitespaceEventParams *e) {return 0;}
    virtual int FireRedirect(GoogleRequestRedirectEventParams *e) {return 0;}
    virtual int FireSetCookie(GoogleRequestSetCookieEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GoogleRequestSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GoogleRequestSSLStatusEventParams *e) {return 0;}
    virtual int FireStartElement(GoogleRequestStartElementEventParams *e) {return 0;}
    virtual int FireStatus(GoogleRequestStatusEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GoogleRequestEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GoogleRequest*)lpObj)->GoogleRequestEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GoogleRequestCharactersEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireCharacters(&e);
            break;
         }
         case 2: {
            GoogleRequestConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireConnected(&e);
            break;
         }
         case 3: {
            GoogleRequestConnectionStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireConnectionStatus(&e);
            break;
         }
         case 4: {
            GoogleRequestDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 5: {
            GoogleRequestEndElementEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireEndElement(&e);
            break;
         }
         case 6: {
            GoogleRequestErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireError(&e);
            break;
         }
         case 7: {
            GoogleRequestHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireHeader(&e);
            break;
         }
         case 8: {
            GoogleRequestIgnorableWhitespaceEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireIgnorableWhitespace(&e);
            break;
         }
         case 9: {
            GoogleRequestRedirectEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireRedirect(&e);
            param[1] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 10: {
            GoogleRequestSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 11: {
            GoogleRequestSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 12: {
            GoogleRequestSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 13: {
            GoogleRequestStartElementEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireStartElement(&e);
            break;
         }
         case 14: {
            GoogleRequestStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GoogleRequest*)lpObj)->FireStatus(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GoogleRequestEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GoogleRequest(char *lpOemKey = (char*)INGOOGLE_OEMKEY_90) {
      m_pObj = InGoogle_GoogleRequest_Create(GoogleRequestEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GoogleRequest() {
      InGoogle_GoogleRequest_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GoogleRequest_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GoogleRequest_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GoogleRequest_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline char* GetAccept() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 1, 0, 0);
      return (char*)val;
    }

    inline int SetAccept(const char *lpAccept) {
      return InGoogle_GoogleRequest_Set(m_pObj, 1, 0, (void*)lpAccept, 0);
    }

    inline char* GetAuthorization() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GoogleRequest_Set(m_pObj, 2, 0, (void*)lpAuthorization, 0);
    }

    inline int GetAuthScheme() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 3, 0, 0);
      return (int)(long)val;
    }
    inline int SetAuthScheme(int iAuthScheme) {
      void* val = (void*)IBG64CAST(iAuthScheme);
      return InGoogle_GoogleRequest_Set(m_pObj, 3, 0, val, 0);
    }
    inline int GetBuildDOM() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 4, 0, 0);
      return (int)(long)val;
    }
    inline int SetBuildDOM(int bBuildDOM) {
      void* val = (void*)IBG64CAST(bBuildDOM);
      return InGoogle_GoogleRequest_Set(m_pObj, 4, 0, val, 0);
    }
    inline int GetConnected() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 5, 0, 0);
      return (int)(long)val;
    }
    inline int SetConnected(int bConnected) {
      void* val = (void*)IBG64CAST(bConnected);
      return InGoogle_GoogleRequest_Set(m_pObj, 5, 0, val, 0);
    }
    inline char* GetContentType() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 6, 0, 0);
      return (char*)val;
    }

    inline int SetContentType(const char *lpContentType) {
      return InGoogle_GoogleRequest_Set(m_pObj, 6, 0, (void*)lpContentType, 0);
    }

    inline int GetCookieCount() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 7, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GoogleRequest_Set(m_pObj, 7, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 8, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 9, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 10, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 11, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 12, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 13, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GoogleRequest_Set(m_pObj, 13, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 14, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GoogleRequest_Set(m_pObj, 14, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 15, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GoogleRequest_Set(m_pObj, 15, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 16, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GoogleRequest_Set(m_pObj, 16, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 17, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 17, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 18, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GoogleRequest_Set(m_pObj, 18, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 19, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 19, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetFollowRedirects() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 20, 0, 0);
      return (int)(long)val;
    }
    inline int SetFollowRedirects(int iFollowRedirects) {
      void* val = (void*)IBG64CAST(iFollowRedirects);
      return InGoogle_GoogleRequest_Set(m_pObj, 20, 0, val, 0);
    }
    inline char* GetFrom() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 21, 0, 0);
      return (char*)val;
    }

    inline int SetFrom(const char *lpFrom) {
      return InGoogle_GoogleRequest_Set(m_pObj, 21, 0, (void*)lpFrom, 0);
    }

    inline char* GetHTTPMethod() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 22, 0, 0);
      return (char*)val;
    }

    inline int SetHTTPMethod(const char *lpHTTPMethod) {
      return InGoogle_GoogleRequest_Set(m_pObj, 22, 0, (void*)lpHTTPMethod, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 23, 0, 0);
      return (int)(long)val;
    }

    inline char* GetIfModifiedSince() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }

    inline int SetIfModifiedSince(const char *lpIfModifiedSince) {
      return InGoogle_GoogleRequest_Set(m_pObj, 24, 0, (void*)lpIfModifiedSince, 0);
    }

    inline char* GetLocalFile() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }

    inline int SetLocalFile(const char *lpLocalFile) {
      return InGoogle_GoogleRequest_Set(m_pObj, 25, 0, (void*)lpLocalFile, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GoogleRequest_Set(m_pObj, 26, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 27, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GoogleRequest_Set(m_pObj, 27, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 28, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 29, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 30, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetPassword() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 31, 0, 0);
      return (char*)val;
    }

    inline int SetPassword(const char *lpPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 31, 0, (void*)lpPassword, 0);
    }

    inline int GetPostData(char *&lpPostData, int &lenPostData) {
      lpPostData = (char*)InGoogle_GoogleRequest_Get(m_pObj, 32, 0, &lenPostData);
      return lpPostData ? 0 : lenPostData;
    }

    inline int SetPostData(const char *lpPostData, int lenPostData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 32, 0, (void*)lpPostData, lenPostData);
    }

    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 33, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GoogleRequest_Set(m_pObj, 33, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 34, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GoogleRequest_Set(m_pObj, 34, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 35, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 36, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GoogleRequest_Set(m_pObj, 36, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 37, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GoogleRequest_Set(m_pObj, 37, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 38, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GoogleRequest_Set(m_pObj, 38, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 39, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 39, 0, (void*)lpProxyUser, 0);
    }

    inline char* GetReferer() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 40, 0, 0);
      return (char*)val;
    }

    inline int SetReferer(const char *lpReferer) {
      return InGoogle_GoogleRequest_Set(m_pObj, 40, 0, (void*)lpReferer, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 41, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 41, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 42, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 42, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GoogleRequest_Get(m_pObj, 43, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GoogleRequest_Set(m_pObj, 43, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 44, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 44, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 45, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GoogleRequest_Set(m_pObj, 45, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 46, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GoogleRequest_Set(m_pObj, 46, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 47, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline char* GetStatusLine() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 49, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GoogleRequest_Set(m_pObj, 49, 0, val, 0);
    }
    inline int GetTransferredData(char *&lpTransferredData, int &lenTransferredData) {
      lpTransferredData = (char*)InGoogle_GoogleRequest_Get(m_pObj, 50, 0, &lenTransferredData);
      return lpTransferredData ? 0 : lenTransferredData;
    }

    inline int SetTransferredData(const char *lpTransferredData, int lenTransferredData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 50, 0, (void*)lpTransferredData, lenTransferredData);
    }

    inline ns_int64 GetTransferredDataLimit() {
      ns_int64 *pval = (ns_int64*)InGoogle_GoogleRequest_Get(m_pObj, 51, 0, 0);
      return *pval;
    }

    inline int SetTransferredDataLimit(ns_int64 lTransferredDataLimit) {
      void* val = (void*)(&lTransferredDataLimit);
      return InGoogle_GoogleRequest_Set(m_pObj, 51, 0, val, 0);
    }

    inline char* GetTransferredHeaders() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 52, 0, 0);
      return (char*)val;
    }


    inline char* GetURL() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }

    inline int SetURL(const char *lpURL) {
      return InGoogle_GoogleRequest_Set(m_pObj, 53, 0, (void*)lpURL, 0);
    }

    inline char* GetUser() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 54, 0, 0);
      return (char*)val;
    }

    inline int SetUser(const char *lpUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 54, 0, (void*)lpUser, 0);
    }

    inline int GetXChildrenCount() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 55, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 56, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 57, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }


    inline char* GetXErrorPath() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 59, 0, 0);
      return (char*)val;
    }

    inline int SetXErrorPath(const char *lpXErrorPath) {
      return InGoogle_GoogleRequest_Set(m_pObj, 59, 0, (void*)lpXErrorPath, 0);
    }

    inline char* GetXParent() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 60, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 61, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GoogleRequest_Set(m_pObj, 61, 0, (void*)lpXPath, 0);
    }

    inline char* GetXSubTree() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 62, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GoogleRequest_Get(m_pObj, 63, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline int AddCookie(const char* lpszCookieName, const char* lpszCookieValue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszCookieName), (void*)IBG64CAST(lpszCookieValue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GoogleRequest_Do(m_pObj, 3, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int Delete(const char* lpszURL) {
      void *param[1+1] = {(void*)IBG64CAST(lpszURL), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 4, 1, param, cbparam);
      
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline int Get(const char* lpszURL) {
      void *param[1+1] = {(void*)IBG64CAST(lpszURL), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 6, 1, param, cbparam);
      
      
    }
    inline int HasXPath(const char* lpszXPath) {
      void *param[1+1] = {(void*)IBG64CAST(lpszXPath), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GoogleRequest_Do(m_pObj, 7, 1, param, cbparam);
      
      return (int)IBG64CAST(param[1]);
    }
    inline int Input(const char* lpszText) {
      void *param[1+1] = {(void*)IBG64CAST(lpszText), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 8, 1, param, cbparam);
      
      
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline int ParseFile(const char* lpszFileName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszFileName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10, 1, param, cbparam);
      
      
    }
    inline int Post(const char* lpszURL) {
      void *param[1+1] = {(void*)IBG64CAST(lpszURL), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 11, 1, param, cbparam);
      
      
    }
    inline int Put(const char* lpszURL) {
      void *param[1+1] = {(void*)IBG64CAST(lpszURL), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 12, 1, param, cbparam);
      
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 13, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR Text;
  int lenText;
  int reserved;
} GoogleRequestCharactersEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GoogleRequestConnectedEventParamsW;

typedef struct {
  LPWSTR ConnectionEvent;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GoogleRequestConnectionStatusEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GoogleRequestDisconnectedEventParamsW;

typedef struct {
  LPWSTR Element;
  int reserved;
} GoogleRequestEndElementEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GoogleRequestErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GoogleRequestHeaderEventParamsW;

typedef struct {
  LPWSTR Text;
  int reserved;
} GoogleRequestIgnorableWhitespaceEventParamsW;

typedef struct {
  LPWSTR Location;
  int Accept;
  int reserved;
} GoogleRequestRedirectEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GoogleRequestSetCookieEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GoogleRequestSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GoogleRequestSSLStatusEventParamsW;

typedef struct {
  LPWSTR Element;
  int reserved;
} GoogleRequestStartElementEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GoogleRequestStatusEventParamsW;



class GoogleRequestW : public GoogleRequest {

  public: //properties
  
    inline LPWSTR GetAccept() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+1, 0, 0);
    }

    inline int SetAccept(LPWSTR lpAccept) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+1, 0, (void*)lpAccept, 0);
    }

    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+2, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+2, 0, (void*)lpAuthorization, 0);
    }







    inline LPWSTR GetContentType() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+6, 0, 0);
    }

    inline int SetContentType(LPWSTR lpContentType) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+6, 0, (void*)lpContentType, 0);
    }



    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+8, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+9, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+10, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+10, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+11, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+13, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+13, iCookieIndex, (void*)lpCookieValue, 0);
    }





    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+16, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+16, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+17, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+17, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+19, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+19, 0, (void*)lpFirewallUser, 0);
    }



    inline LPWSTR GetFrom() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+21, 0, 0);
    }

    inline int SetFrom(LPWSTR lpFrom) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+21, 0, (void*)lpFrom, 0);
    }

    inline LPWSTR GetHTTPMethod() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+22, 0, 0);
    }

    inline int SetHTTPMethod(LPWSTR lpHTTPMethod) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+22, 0, (void*)lpHTTPMethod, 0);
    }



    inline LPWSTR GetIfModifiedSince() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+24, 0, 0);
    }

    inline int SetIfModifiedSince(LPWSTR lpIfModifiedSince) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+24, 0, (void*)lpIfModifiedSince, 0);
    }

    inline LPWSTR GetLocalFile() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+10000+25, 0, 0);
    }

    inline int SetLocalFile(LPWSTR lpLocalFile) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+10000+25, 0, (void*)lpLocalFile, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+26, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+26, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+27, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+27, 0, (void*)lpOtherHeaders, 0);
    }



    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+29, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+30, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetPassword() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+31, 0, 0);
    }

    inline int SetPassword(LPWSTR lpPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+31, 0, (void*)lpPassword, 0);
    }

    inline LPWSTR GetPostData() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+32, 0, 0);
    }

    inline int SetPostData(LPWSTR lpPostData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+32, 0, (void*)lpPostData, 0);
    }
    inline int GetPostDataB(char *&lpPostData, int &lenPostData) {
      lpPostData = (char*)InGoogle_GoogleRequest_Get(m_pObj, 32, 0, &lenPostData);
      return lpPostData ? 0 : lenPostData;
    }
    inline int SetPostDataB(const char *lpPostData, int lenPostData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 32, 0, (void*)lpPostData, lenPostData);
    }




    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+35, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+35, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+37, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+37, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+39, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+39, 0, (void*)lpProxyUser, 0);
    }

    inline LPWSTR GetReferer() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+40, 0, 0);
    }

    inline int SetReferer(LPWSTR lpReferer) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+40, 0, (void*)lpReferer, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+41, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+41, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 41, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 41, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+42, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+42, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 42, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GoogleRequest_Set(m_pObj, 42, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+43, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+43, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GoogleRequest_Get(m_pObj, 43, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GoogleRequest_Set(m_pObj, 43, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+44, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+44, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+46, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+46, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+47, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GoogleRequest_Get(m_pObj, 47, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }

    inline LPWSTR GetStatusLine() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+48, 0, 0);
    }





    inline LPWSTR GetTransferredData() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+50, 0, 0);
    }

    inline int SetTransferredData(LPWSTR lpTransferredData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+50, 0, (void*)lpTransferredData, 0);
    }
    inline int GetTransferredDataB(char *&lpTransferredData, int &lenTransferredData) {
      lpTransferredData = (char*)InGoogle_GoogleRequest_Get(m_pObj, 50, 0, &lenTransferredData);
      return lpTransferredData ? 0 : lenTransferredData;
    }
    inline int SetTransferredDataB(const char *lpTransferredData, int lenTransferredData) {
      return InGoogle_GoogleRequest_Set(m_pObj, 50, 0, (void*)lpTransferredData, lenTransferredData);
    }


    inline LPWSTR GetTransferredHeaders() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+52, 0, 0);
    }



    inline LPWSTR GetURL() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+53, 0, 0);
    }

    inline int SetURL(LPWSTR lpURL) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+53, 0, (void*)lpURL, 0);
    }

    inline LPWSTR GetUser() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+54, 0, 0);
    }

    inline int SetUser(LPWSTR lpUser) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+54, 0, (void*)lpUser, 0);
    }



    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+56, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+57, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+58, 0, 0);
    }



    inline LPWSTR GetXErrorPath() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+59, 0, 0);
    }

    inline int SetXErrorPath(LPWSTR lpXErrorPath) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+59, 0, (void*)lpXErrorPath, 0);
    }

    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+60, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+61, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GoogleRequest_Set(m_pObj, 10000+61, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+62, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GoogleRequest_Get(m_pObj, 10000+63, 0, 0);
    }





  public: //events
  
    virtual int FireCharacters(GoogleRequestCharactersEventParamsW *e) {return 0;}
    virtual int FireConnected(GoogleRequestConnectedEventParamsW *e) {return 0;}
    virtual int FireConnectionStatus(GoogleRequestConnectionStatusEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GoogleRequestDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndElement(GoogleRequestEndElementEventParamsW *e) {return 0;}
    virtual int FireError(GoogleRequestErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GoogleRequestHeaderEventParamsW *e) {return 0;}
    virtual int FireIgnorableWhitespace(GoogleRequestIgnorableWhitespaceEventParamsW *e) {return 0;}
    virtual int FireRedirect(GoogleRequestRedirectEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GoogleRequestSetCookieEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GoogleRequestSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GoogleRequestSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartElement(GoogleRequestStartElementEventParamsW *e) {return 0;}
    virtual int FireStatus(GoogleRequestStatusEventParamsW *e) {return 0;}


  protected:
  
    virtual int GoogleRequestEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GoogleRequestCharactersEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireCharacters(&e);
            break;
         }
         case 2: {
            GoogleRequestConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 3: {
            GoogleRequestConnectionStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireConnectionStatus(&e);
            break;
         }
         case 4: {
            GoogleRequestDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 5: {
            GoogleRequestEndElementEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireEndElement(&e);
            break;
         }
         case 6: {
            GoogleRequestErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 7: {
            GoogleRequestHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 8: {
            GoogleRequestIgnorableWhitespaceEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireIgnorableWhitespace(&e);
            break;
         }
         case 9: {
            GoogleRequestRedirectEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]),  0};
            ret_code = FireRedirect(&e);
            param[1] = (void*)(e.Accept);
            break;
         }
         case 10: {
            GoogleRequestSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 11: {
            GoogleRequestSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 12: {
            GoogleRequestSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 13: {
            GoogleRequestStartElementEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireStartElement(&e);
            break;
         }
         case 14: {
            GoogleRequestStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireCharacters(GoogleRequestCharactersEventParams *e) {return -10000;}
    virtual int FireConnected(GoogleRequestConnectedEventParams *e) {return -10000;}
    virtual int FireConnectionStatus(GoogleRequestConnectionStatusEventParams *e) {return -10000;}
    virtual int FireDisconnected(GoogleRequestDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndElement(GoogleRequestEndElementEventParams *e) {return -10000;}
    virtual int FireError(GoogleRequestErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GoogleRequestHeaderEventParams *e) {return -10000;}
    virtual int FireIgnorableWhitespace(GoogleRequestIgnorableWhitespaceEventParams *e) {return -10000;}
    virtual int FireRedirect(GoogleRequestRedirectEventParams *e) {return -10000;}
    virtual int FireSetCookie(GoogleRequestSetCookieEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GoogleRequestSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GoogleRequestSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartElement(GoogleRequestStartElementEventParams *e) {return -10000;}
    virtual int FireStatus(GoogleRequestStatusEventParams *e) {return -10000;}

  public: //methods

    inline int AddCookie(LPWSTR lpszCookieName, LPWSTR lpszCookieValue) {
      void *param[2+1] = {(void*)lpszCookieName, (void*)lpszCookieValue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GoogleRequest_Do(m_pObj, 10000+3, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int Delete(LPWSTR lpszURL) {
      void *param[1+1] = {(void*)lpszURL, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+4, 1, param, cbparam);
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline int Get(LPWSTR lpszURL) {
      void *param[1+1] = {(void*)lpszURL, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+6, 1, param, cbparam);
      
    }
    inline int HasXPath(LPWSTR lpszXPath) {
      void *param[1+1] = {(void*)lpszXPath, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GoogleRequest_Do(m_pObj, 10000+7, 1, param, cbparam);
      return (int)IBG64CAST(param[1]);
    }
    inline int Input(LPWSTR lpszText) {
      void *param[1+1] = {(void*)lpszText, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+8, 1, param, cbparam);
      
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline int ParseFile(LPWSTR lpszFileName) {
      void *param[1+1] = {(void*)lpszFileName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+10, 1, param, cbparam);
      
    }
    inline int Post(LPWSTR lpszURL) {
      void *param[1+1] = {(void*)lpszURL, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+11, 1, param, cbparam);
      
    }
    inline int Put(LPWSTR lpszURL) {
      void *param[1+1] = {(void*)lpszURL, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+12, 1, param, cbparam);
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GoogleRequest_Do(m_pObj, 10000+13, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GOOGLEREQUEST_H_




