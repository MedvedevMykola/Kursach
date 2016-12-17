/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GSTORAGE_H_
#define _INGOOGLE_GSTORAGE_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//TAccessPolicy
#define PT_PRIVATE                                         0
#define PT_PUBLIC_READ                                     1
#define PT_PUBLIC_READ_WRITE                               2
#define PT_AUTHENTICATED_READ                              3
#define PT_BUCKET_OWNER_READ                               4
#define PT_BUCKET_OWNER_FULL_CONTROL                       5

//FirewallTypes
#define FW_NONE                                            0
#define FW_TUNNEL                                          1
#define FW_SOCKS4                                          2
#define FW_SOCKS5                                          3

//TFollowRedirects
#define FR_NEVER                                           0
#define FR_ALWAYS                                          1
#define FR_SAME_SCHEME                                     2

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


extern "C" void* INGOOGLE_CALL InGoogle_GStorage_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GStorage_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GStorage_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GStorage_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* BucketName;
  const char* CreationDate;
  const char* OwnerId;
  const char* OwnerName;
  const char* OtherData;
  int reserved;
} GStorageBucketListEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GStorageConnectedEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GStorageDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GStorageEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GStorageErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GStorageHeaderEventParams;

typedef struct {
  const char* ObjectName;
  const char* ObjectModifiedDate;
  ns_int64 *pObjectSize;
  const char* ETag;
  const char* OwnerId;
  const char* OwnerName;
  const char* UploadId;
  const char* OtherData;
  int reserved;
} GStorageObjectListEventParams;

typedef struct {
  const char* Prefix;
  const char* OtherData;
  int reserved;
} GStoragePrefixListEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GStorageSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GStorageSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GStorageStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GStorageStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GStorageTransferEventParams;



class GStorage {
  
  public: //events
  
    virtual int FireBucketList(GStorageBucketListEventParams *e) {return 0;}
    virtual int FireConnected(GStorageConnectedEventParams *e) {return 0;}
    virtual int FireDisconnected(GStorageDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GStorageEndTransferEventParams *e) {return 0;}
    virtual int FireError(GStorageErrorEventParams *e) {return 0;}
    virtual int FireHeader(GStorageHeaderEventParams *e) {return 0;}
    virtual int FireObjectList(GStorageObjectListEventParams *e) {return 0;}
    virtual int FirePrefixList(GStoragePrefixListEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GStorageSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GStorageSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GStorageStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GStorageStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GStorageTransferEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GStorageEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GStorage*)lpObj)->GStorageEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GStorageBucketListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]),  0};
            ret_code = ((GStorage*)lpObj)->FireBucketList(&e);
            break;
         }
         case 2: {
            GStorageConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GStorage*)lpObj)->FireConnected(&e);
            break;
         }
         case 3: {
            GStorageDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GStorage*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 4: {
            GStorageEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GStorage*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 5: {
            GStorageErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GStorage*)lpObj)->FireError(&e);
            break;
         }
         case 6: {
            GStorageHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GStorage*)lpObj)->FireHeader(&e);
            break;
         }
         case 7: {
            GStorageObjectListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (ns_int64*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]), (char*)IBG64CAST(param[7]),  0};
            ret_code = ((GStorage*)lpObj)->FireObjectList(&e);
            break;
         }
         case 8: {
            GStoragePrefixListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GStorage*)lpObj)->FirePrefixList(&e);
            break;
         }
         case 9: {
            GStorageSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GStorage*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 10: {
            GStorageSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GStorage*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 11: {
            GStorageStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GStorage*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 12: {
            GStorageStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GStorage*)lpObj)->FireStatus(&e);
            break;
         }
         case 13: {
            GStorageTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GStorage*)lpObj)->FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GStorageEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GStorage(char *lpOemKey = (char*)INGOOGLE_OEMKEY_50) {
      m_pObj = InGoogle_GStorage_Create(GStorageEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GStorage() {
      InGoogle_GStorage_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GStorage_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GStorage_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GStorage_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline int GetAccessPolicy() {
      void* val = InGoogle_GStorage_Get(m_pObj, 1, 0, 0);
      return (int)(long)val;
    }
    inline int SetAccessPolicy(int iAccessPolicy) {
      void* val = (void*)IBG64CAST(iAccessPolicy);
      return InGoogle_GStorage_Set(m_pObj, 1, 0, val, 0);
    }
    inline char* GetAuthorization() {
      void* val = InGoogle_GStorage_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GStorage_Set(m_pObj, 2, 0, (void*)lpAuthorization, 0);
    }

    inline char* GetBucket() {
      void* val = InGoogle_GStorage_Get(m_pObj, 3, 0, 0);
      return (char*)val;
    }

    inline int SetBucket(const char *lpBucket) {
      return InGoogle_GStorage_Set(m_pObj, 3, 0, (void*)lpBucket, 0);
    }

    inline int GetBucketsCount() {
      void* val = InGoogle_GStorage_Get(m_pObj, 4, 0, 0);
      return (int)(long)val;
    }

    inline char* GetBucketsCreationDate(int iBucketsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 5, iBucketsIndex, 0);
      return (char*)val;
    }


    inline char* GetBucketsName(int iBucketsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 6, iBucketsIndex, 0);
      return (char*)val;
    }


    inline char* GetBucketsOwnerDisplayName(int iBucketsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 7, iBucketsIndex, 0);
      return (char*)val;
    }


    inline char* GetBucketsOwnerId(int iBucketsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 8, iBucketsIndex, 0);
      return (char*)val;
    }


    inline int GetConnected() {
      void* val = InGoogle_GStorage_Get(m_pObj, 9, 0, 0);
      return (int)(long)val;
    }
    inline int SetConnected(int bConnected) {
      void* val = (void*)IBG64CAST(bConnected);
      return InGoogle_GStorage_Set(m_pObj, 9, 0, val, 0);
    }
    inline char* GetContentDisposition() {
      void* val = InGoogle_GStorage_Get(m_pObj, 10, 0, 0);
      return (char*)val;
    }

    inline int SetContentDisposition(const char *lpContentDisposition) {
      return InGoogle_GStorage_Set(m_pObj, 10, 0, (void*)lpContentDisposition, 0);
    }

    inline char* GetContentType() {
      void* val = InGoogle_GStorage_Get(m_pObj, 11, 0, 0);
      return (char*)val;
    }

    inline int SetContentType(const char *lpContentType) {
      return InGoogle_GStorage_Set(m_pObj, 11, 0, (void*)lpContentType, 0);
    }

    inline char* GetEncryptionPassword() {
      void* val = InGoogle_GStorage_Get(m_pObj, 12, 0, 0);
      return (char*)val;
    }

    inline int SetEncryptionPassword(const char *lpEncryptionPassword) {
      return InGoogle_GStorage_Set(m_pObj, 12, 0, (void*)lpEncryptionPassword, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GStorage_Get(m_pObj, 13, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GStorage_Set(m_pObj, 13, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GStorage_Get(m_pObj, 14, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GStorage_Set(m_pObj, 14, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GStorage_Get(m_pObj, 15, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GStorage_Set(m_pObj, 15, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GStorage_Get(m_pObj, 16, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GStorage_Set(m_pObj, 16, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GStorage_Get(m_pObj, 17, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GStorage_Set(m_pObj, 17, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GStorage_Get(m_pObj, 18, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GStorage_Set(m_pObj, 18, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetFollowRedirects() {
      void* val = InGoogle_GStorage_Get(m_pObj, 19, 0, 0);
      return (int)(long)val;
    }
    inline int SetFollowRedirects(int iFollowRedirects) {
      void* val = (void*)IBG64CAST(iFollowRedirects);
      return InGoogle_GStorage_Set(m_pObj, 19, 0, val, 0);
    }
    inline int GetIdle() {
      void* val = InGoogle_GStorage_Get(m_pObj, 20, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLocalFile() {
      void* val = InGoogle_GStorage_Get(m_pObj, 21, 0, 0);
      return (char*)val;
    }

    inline int SetLocalFile(const char *lpLocalFile) {
      return InGoogle_GStorage_Set(m_pObj, 21, 0, (void*)lpLocalFile, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GStorage_Get(m_pObj, 22, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GStorage_Set(m_pObj, 22, 0, (void*)lpLocalHost, 0);
    }

    inline int GetObjectData(char *&lpObjectData, int &lenObjectData) {
      lpObjectData = (char*)InGoogle_GStorage_Get(m_pObj, 23, 0, &lenObjectData);
      return lpObjectData ? 0 : lenObjectData;
    }

    inline int SetObjectData(const char *lpObjectData, int lenObjectData) {
      return InGoogle_GStorage_Set(m_pObj, 23, 0, (void*)lpObjectData, lenObjectData);
    }

    inline char* GetObjectDelimiter() {
      void* val = InGoogle_GStorage_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }

    inline int SetObjectDelimiter(const char *lpObjectDelimiter) {
      return InGoogle_GStorage_Set(m_pObj, 24, 0, (void*)lpObjectDelimiter, 0);
    }

    inline char* GetObjectMarker() {
      void* val = InGoogle_GStorage_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }

    inline int SetObjectMarker(const char *lpObjectMarker) {
      return InGoogle_GStorage_Set(m_pObj, 25, 0, (void*)lpObjectMarker, 0);
    }

    inline char* GetObjectPrefix() {
      void* val = InGoogle_GStorage_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }

    inline int SetObjectPrefix(const char *lpObjectPrefix) {
      return InGoogle_GStorage_Set(m_pObj, 26, 0, (void*)lpObjectPrefix, 0);
    }

    inline int GetObjectsCount() {
      void* val = InGoogle_GStorage_Get(m_pObj, 27, 0, 0);
      return (int)(long)val;
    }

    inline char* GetObjectsETag(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 28, iObjectsIndex, 0);
      return (char*)val;
    }


    inline char* GetObjectsName(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 29, iObjectsIndex, 0);
      return (char*)val;
    }


    inline char* GetObjectsLastModified(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 30, iObjectsIndex, 0);
      return (char*)val;
    }


    inline char* GetObjectsOwnerDisplayName(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 31, iObjectsIndex, 0);
      return (char*)val;
    }


    inline char* GetObjectsOwnerId(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 32, iObjectsIndex, 0);
      return (char*)val;
    }


    inline ns_int64 GetObjectsSize(int iObjectsIndex) {
      ns_int64 *pval = (ns_int64*)InGoogle_GStorage_Get(m_pObj, 33, iObjectsIndex, 0);
      return *pval;
    }


    inline char* GetObjectsStorageClass(int iObjectsIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 34, iObjectsIndex, 0);
      return (char*)val;
    }


    inline char* GetOtherHeaders() {
      void* val = InGoogle_GStorage_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GStorage_Set(m_pObj, 35, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetOverwrite() {
      void* val = InGoogle_GStorage_Get(m_pObj, 36, 0, 0);
      return (int)(long)val;
    }
    inline int SetOverwrite(int bOverwrite) {
      void* val = (void*)IBG64CAST(bOverwrite);
      return InGoogle_GStorage_Set(m_pObj, 36, 0, val, 0);
    }
    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GStorage_Get(m_pObj, 37, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 38, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GStorage_Get(m_pObj, 39, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetProjectId() {
      void* val = InGoogle_GStorage_Get(m_pObj, 40, 0, 0);
      return (char*)val;
    }

    inline int SetProjectId(const char *lpProjectId) {
      return InGoogle_GStorage_Set(m_pObj, 40, 0, (void*)lpProjectId, 0);
    }

    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GStorage_Get(m_pObj, 41, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GStorage_Set(m_pObj, 41, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GStorage_Get(m_pObj, 42, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GStorage_Set(m_pObj, 42, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GStorage_Get(m_pObj, 43, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GStorage_Set(m_pObj, 43, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GStorage_Get(m_pObj, 44, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GStorage_Set(m_pObj, 44, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GStorage_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GStorage_Set(m_pObj, 45, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GStorage_Get(m_pObj, 46, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GStorage_Set(m_pObj, 46, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GStorage_Get(m_pObj, 47, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GStorage_Set(m_pObj, 47, 0, (void*)lpProxyUser, 0);
    }

    inline char* GetRange() {
      void* val = InGoogle_GStorage_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }

    inline int SetRange(const char *lpRange) {
      return InGoogle_GStorage_Set(m_pObj, 48, 0, (void*)lpRange, 0);
    }

    inline char* GetReferer() {
      void* val = InGoogle_GStorage_Get(m_pObj, 49, 0, 0);
      return (char*)val;
    }

    inline int SetReferer(const char *lpReferer) {
      return InGoogle_GStorage_Set(m_pObj, 49, 0, (void*)lpReferer, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 50, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 50, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 51, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 51, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GStorage_Get(m_pObj, 52, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GStorage_Set(m_pObj, 52, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GStorage_Get(m_pObj, 53, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GStorage_Set(m_pObj, 53, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GStorage_Get(m_pObj, 54, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GStorage_Set(m_pObj, 54, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GStorage_Get(m_pObj, 55, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GStorage_Set(m_pObj, 55, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 56, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline char* GetStatusLine() {
      void* val = InGoogle_GStorage_Get(m_pObj, 57, 0, 0);
      return (char*)val;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GStorage_Get(m_pObj, 58, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GStorage_Set(m_pObj, 58, 0, val, 0);
    }
    inline int GetUseSSL() {
      void* val = InGoogle_GStorage_Get(m_pObj, 59, 0, 0);
      return (int)(long)val;
    }
    inline int SetUseSSL(int bUseSSL) {
      void* val = (void*)IBG64CAST(bUseSSL);
      return InGoogle_GStorage_Set(m_pObj, 59, 0, val, 0);
    }
    inline int GetUseVirtualHosting() {
      void* val = InGoogle_GStorage_Get(m_pObj, 60, 0, 0);
      return (int)(long)val;
    }
    inline int SetUseVirtualHosting(int bUseVirtualHosting) {
      void* val = (void*)IBG64CAST(bUseVirtualHosting);
      return InGoogle_GStorage_Set(m_pObj, 60, 0, val, 0);
    }

  public: //methods

    inline int AddUserMetaData(const char* lpszKey, const char* lpszValue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszKey), (void*)IBG64CAST(lpszValue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GStorage_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GStorage_Do(m_pObj, 3, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int CopyObject(const char* lpszSrcObjectName, const char* lpszDestBucket, const char* lpszDestObjectName) {
      void *param[3+1] = {(void*)IBG64CAST(lpszSrcObjectName), (void*)IBG64CAST(lpszDestBucket), (void*)IBG64CAST(lpszDestObjectName), 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      return InGoogle_GStorage_Do(m_pObj, 4, 3, param, cbparam);
      
      
    }
    inline int CreateBucket() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline int CreateObject(const char* lpszObjectName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszObjectName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 6, 1, param, cbparam);
      
      
    }
    inline int DeleteBucket() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 7, 0, param, cbparam);
      
      
    }
    inline int DeleteObject(const char* lpszObjectName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszObjectName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 8, 1, param, cbparam);
      
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline char* GetBucketLocation() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GStorage_Do(m_pObj, 10, 0, param, cbparam);
      
      return (char*)IBG64CAST(param[0]);
    }
    inline int GetObject(const char* lpszObjectName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszObjectName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 11, 1, param, cbparam);
      
      
    }
    inline int GetObjectInfo(const char* lpszObjectName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszObjectName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 12, 1, param, cbparam);
      
      
    }
    inline char* GetXValue(const char* lpszXPath) {
      void *param[1+1] = {(void*)IBG64CAST(lpszXPath), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GStorage_Do(m_pObj, 13, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 14, 0, param, cbparam);
      
      
    }
    inline int ListBuckets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 15, 0, param, cbparam);
      
      
    }
    inline int ListObjects() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 16, 0, param, cbparam);
      
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 17, 0, param, cbparam);
      
      
    }
    inline int ResetHeaders() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 18, 0, param, cbparam);
      
      
    }
    inline char* SendCustomRequest(const char* lpszUrl, const char* lpszRequestData, const char* lpszOtherHeaders) {
      void *param[3+1] = {(void*)IBG64CAST(lpszUrl), (void*)IBG64CAST(lpszRequestData), (void*)IBG64CAST(lpszOtherHeaders), 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      InGoogle_GStorage_Do(m_pObj, 19, 3, param, cbparam);
      
      return (char*)IBG64CAST(param[3]);
    }
    inline int UpdateBucketACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 22, 0, param, cbparam);
      
      
    }
    inline int UpdateObjectACL(const char* lpszObjectName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszObjectName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 23, 1, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR BucketName;
  LPWSTR CreationDate;
  LPWSTR OwnerId;
  LPWSTR OwnerName;
  LPWSTR OtherData;
  int reserved;
} GStorageBucketListEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GStorageConnectedEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GStorageDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GStorageEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GStorageErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GStorageHeaderEventParamsW;

typedef struct {
  LPWSTR ObjectName;
  LPWSTR ObjectModifiedDate;
  ns_int64 *pObjectSize;
  LPWSTR ETag;
  LPWSTR OwnerId;
  LPWSTR OwnerName;
  LPWSTR UploadId;
  LPWSTR OtherData;
  int reserved;
} GStorageObjectListEventParamsW;

typedef struct {
  LPWSTR Prefix;
  LPWSTR OtherData;
  int reserved;
} GStoragePrefixListEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GStorageSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GStorageSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GStorageStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GStorageStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GStorageTransferEventParamsW;



class GStorageW : public GStorage {

  public: //properties
  


    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+2, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GStorage_Set(m_pObj, 10000+2, 0, (void*)lpAuthorization, 0);
    }

    inline LPWSTR GetBucket() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+3, 0, 0);
    }

    inline int SetBucket(LPWSTR lpBucket) {
      return InGoogle_GStorage_Set(m_pObj, 10000+3, 0, (void*)lpBucket, 0);
    }



    inline LPWSTR GetBucketsCreationDate(int iBucketsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+5, iBucketsIndex, 0);
    }



    inline LPWSTR GetBucketsName(int iBucketsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+6, iBucketsIndex, 0);
    }



    inline LPWSTR GetBucketsOwnerDisplayName(int iBucketsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+7, iBucketsIndex, 0);
    }



    inline LPWSTR GetBucketsOwnerId(int iBucketsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+8, iBucketsIndex, 0);
    }





    inline LPWSTR GetContentDisposition() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+10, 0, 0);
    }

    inline int SetContentDisposition(LPWSTR lpContentDisposition) {
      return InGoogle_GStorage_Set(m_pObj, 10000+10, 0, (void*)lpContentDisposition, 0);
    }

    inline LPWSTR GetContentType() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+11, 0, 0);
    }

    inline int SetContentType(LPWSTR lpContentType) {
      return InGoogle_GStorage_Set(m_pObj, 10000+11, 0, (void*)lpContentType, 0);
    }

    inline LPWSTR GetEncryptionPassword() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+12, 0, 0);
    }

    inline int SetEncryptionPassword(LPWSTR lpEncryptionPassword) {
      return InGoogle_GStorage_Set(m_pObj, 10000+12, 0, (void*)lpEncryptionPassword, 0);
    }





    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+15, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GStorage_Set(m_pObj, 10000+15, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+16, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GStorage_Set(m_pObj, 10000+16, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+18, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GStorage_Set(m_pObj, 10000+18, 0, (void*)lpFirewallUser, 0);
    }





    inline LPWSTR GetLocalFile() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+10000+21, 0, 0);
    }

    inline int SetLocalFile(LPWSTR lpLocalFile) {
      return InGoogle_GStorage_Set(m_pObj, 10000+10000+21, 0, (void*)lpLocalFile, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+22, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GStorage_Set(m_pObj, 10000+22, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetObjectData() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+23, 0, 0);
    }

    inline int SetObjectData(LPWSTR lpObjectData) {
      return InGoogle_GStorage_Set(m_pObj, 10000+23, 0, (void*)lpObjectData, 0);
    }
    inline int GetObjectDataB(char *&lpObjectData, int &lenObjectData) {
      lpObjectData = (char*)InGoogle_GStorage_Get(m_pObj, 23, 0, &lenObjectData);
      return lpObjectData ? 0 : lenObjectData;
    }
    inline int SetObjectDataB(const char *lpObjectData, int lenObjectData) {
      return InGoogle_GStorage_Set(m_pObj, 23, 0, (void*)lpObjectData, lenObjectData);
    }
    inline LPWSTR GetObjectDelimiter() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+24, 0, 0);
    }

    inline int SetObjectDelimiter(LPWSTR lpObjectDelimiter) {
      return InGoogle_GStorage_Set(m_pObj, 10000+24, 0, (void*)lpObjectDelimiter, 0);
    }

    inline LPWSTR GetObjectMarker() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+25, 0, 0);
    }

    inline int SetObjectMarker(LPWSTR lpObjectMarker) {
      return InGoogle_GStorage_Set(m_pObj, 10000+25, 0, (void*)lpObjectMarker, 0);
    }

    inline LPWSTR GetObjectPrefix() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+26, 0, 0);
    }

    inline int SetObjectPrefix(LPWSTR lpObjectPrefix) {
      return InGoogle_GStorage_Set(m_pObj, 10000+26, 0, (void*)lpObjectPrefix, 0);
    }



    inline LPWSTR GetObjectsETag(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+28, iObjectsIndex, 0);
    }



    inline LPWSTR GetObjectsName(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+29, iObjectsIndex, 0);
    }



    inline LPWSTR GetObjectsLastModified(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+30, iObjectsIndex, 0);
    }



    inline LPWSTR GetObjectsOwnerDisplayName(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+31, iObjectsIndex, 0);
    }



    inline LPWSTR GetObjectsOwnerId(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+32, iObjectsIndex, 0);
    }





    inline LPWSTR GetObjectsStorageClass(int iObjectsIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+34, iObjectsIndex, 0);
    }



    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+35, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GStorage_Set(m_pObj, 10000+35, 0, (void*)lpOtherHeaders, 0);
    }





    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+38, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+39, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetProjectId() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+40, 0, 0);
    }

    inline int SetProjectId(LPWSTR lpProjectId) {
      return InGoogle_GStorage_Set(m_pObj, 10000+40, 0, (void*)lpProjectId, 0);
    }





    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+43, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GStorage_Set(m_pObj, 10000+43, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+45, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GStorage_Set(m_pObj, 10000+45, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+47, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GStorage_Set(m_pObj, 10000+47, 0, (void*)lpProxyUser, 0);
    }

    inline LPWSTR GetRange() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+48, 0, 0);
    }

    inline int SetRange(LPWSTR lpRange) {
      return InGoogle_GStorage_Set(m_pObj, 10000+48, 0, (void*)lpRange, 0);
    }

    inline LPWSTR GetReferer() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+49, 0, 0);
    }

    inline int SetReferer(LPWSTR lpReferer) {
      return InGoogle_GStorage_Set(m_pObj, 10000+49, 0, (void*)lpReferer, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+50, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 10000+50, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 50, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 50, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+51, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 10000+51, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 51, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GStorage_Set(m_pObj, 51, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+52, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GStorage_Set(m_pObj, 10000+52, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GStorage_Get(m_pObj, 52, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GStorage_Set(m_pObj, 52, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+53, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GStorage_Set(m_pObj, 10000+53, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+55, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GStorage_Set(m_pObj, 10000+55, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+56, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GStorage_Get(m_pObj, 56, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }

    inline LPWSTR GetStatusLine() {
      return (LPWSTR)InGoogle_GStorage_Get(m_pObj, 10000+57, 0, 0);
    }











  public: //events
  
    virtual int FireBucketList(GStorageBucketListEventParamsW *e) {return 0;}
    virtual int FireConnected(GStorageConnectedEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GStorageDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GStorageEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GStorageErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GStorageHeaderEventParamsW *e) {return 0;}
    virtual int FireObjectList(GStorageObjectListEventParamsW *e) {return 0;}
    virtual int FirePrefixList(GStoragePrefixListEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GStorageSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GStorageSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GStorageStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GStorageStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GStorageTransferEventParamsW *e) {return 0;}


  protected:
  
    virtual int GStorageEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GStorageBucketListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]),  0};
            ret_code = FireBucketList(&e);
            break;
         }
         case 2: {
            GStorageConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 3: {
            GStorageDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 4: {
            GStorageEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 5: {
            GStorageErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 6: {
            GStorageHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 7: {
            GStorageObjectListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (ns_int64*)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]), (LPWSTR)IBG64CAST(param[7]),  0};
            ret_code = FireObjectList(&e);
            break;
         }
         case 8: {
            GStoragePrefixListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FirePrefixList(&e);
            break;
         }
         case 9: {
            GStorageSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 10: {
            GStorageSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 11: {
            GStorageStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 12: {
            GStorageStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 13: {
            GStorageTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireBucketList(GStorageBucketListEventParams *e) {return -10000;}
    virtual int FireConnected(GStorageConnectedEventParams *e) {return -10000;}
    virtual int FireDisconnected(GStorageDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GStorageEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GStorageErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GStorageHeaderEventParams *e) {return -10000;}
    virtual int FireObjectList(GStorageObjectListEventParams *e) {return -10000;}
    virtual int FirePrefixList(GStoragePrefixListEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GStorageSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GStorageSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GStorageStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GStorageStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GStorageTransferEventParams *e) {return -10000;}

  public: //methods

    inline int AddUserMetaData(LPWSTR lpszKey, LPWSTR lpszValue) {
      void *param[2+1] = {(void*)lpszKey, (void*)lpszValue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GStorage_Do(m_pObj, 10000+3, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int CopyObject(LPWSTR lpszSrcObjectName, LPWSTR lpszDestBucket, LPWSTR lpszDestObjectName) {
      void *param[3+1] = {(void*)lpszSrcObjectName, (void*)lpszDestBucket, (void*)lpszDestObjectName, 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+4, 3, param, cbparam);
      
    }
    inline int CreateBucket() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline int CreateObject(LPWSTR lpszObjectName) {
      void *param[1+1] = {(void*)lpszObjectName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+6, 1, param, cbparam);
      
    }
    inline int DeleteBucket() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+7, 0, param, cbparam);
      
    }
    inline int DeleteObject(LPWSTR lpszObjectName) {
      void *param[1+1] = {(void*)lpszObjectName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+8, 1, param, cbparam);
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline LPWSTR GetBucketLocation() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      InGoogle_GStorage_Do(m_pObj, 10000+10, 0, param, cbparam);
      return (LPWSTR)IBG64CAST(param[0]);
    }
    inline int GetObject(LPWSTR lpszObjectName) {
      void *param[1+1] = {(void*)lpszObjectName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+11, 1, param, cbparam);
      
    }
    inline int GetObjectInfo(LPWSTR lpszObjectName) {
      void *param[1+1] = {(void*)lpszObjectName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+12, 1, param, cbparam);
      
    }
    inline LPWSTR GetXValue(LPWSTR lpszXPath) {
      void *param[1+1] = {(void*)lpszXPath, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GStorage_Do(m_pObj, 10000+13, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+14, 0, param, cbparam);
      
    }
    inline int ListBuckets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+15, 0, param, cbparam);
      
    }
    inline int ListObjects() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+16, 0, param, cbparam);
      
    }
    inline int Reset() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+17, 0, param, cbparam);
      
    }
    inline int ResetHeaders() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+18, 0, param, cbparam);
      
    }
    inline LPWSTR SendCustomRequest(LPWSTR lpszUrl, LPWSTR lpszRequestData, LPWSTR lpszOtherHeaders) {
      void *param[3+1] = {(void*)lpszUrl, (void*)lpszRequestData, (void*)lpszOtherHeaders, 0};
      int cbparam[3+1] = {0, 0, 0, 0};
      InGoogle_GStorage_Do(m_pObj, 10000+19, 3, param, cbparam);
      return (LPWSTR)IBG64CAST(param[3]);
    }
    inline int UpdateBucketACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GStorage_Do(m_pObj, 10000+22, 0, param, cbparam);
      
    }
    inline int UpdateObjectACL(LPWSTR lpszObjectName) {
      void *param[1+1] = {(void*)lpszObjectName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GStorage_Do(m_pObj, 10000+23, 1, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GSTORAGE_H_




