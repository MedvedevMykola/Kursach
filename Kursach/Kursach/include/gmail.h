/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GMAIL_H_
#define _INGOOGLE_GMAIL_H_

#define INGOOGLE_ONLY_TYPES
#include "ingoogle.h"
#include "ingoogle.key"

//AuthMechanisms
#define AM_USER_PASSWORD                                   0
#define AM_CRAMMD5                                         1
#define AM_NTLM                                            2
#define AM_SASLPLAIN                                       4
#define AM_SASLDIGEST_MD5                                  5
#define AM_KERBEROS                                        6
#define AM_SASLXOAUTH_2                                    7

//FirewallTypes
#define FW_NONE                                            0
#define FW_TUNNEL                                          1
#define FW_SOCKS4                                          2
#define FW_SOCKS5                                          3

//EmailRecipientTypes
#define RT_TO                                              0
#define RT_CC                                              1
#define RT_BCC                                             2

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

//TSSLStartMode
#define SSL_AUTOMATIC                                      0
#define SSL_IMPLICIT                                       1
#define SSL_EXPLICIT                                       2
#define SSL_NONE                                           3


extern "C" void* INGOOGLE_CALL InGoogle_GMail_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GMail_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GMail_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GMail_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* ConnectionEvent;
  int StatusCode;
  const char* Description;
  int reserved;
} GMailConnectionStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GMailEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GMailErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GMailHeaderEventParams;

typedef struct {
  const char* Mailbox;
  const char* User;
  const char* Rights;
  int reserved;
} GMailMailboxACLEventParams;

typedef struct {
  const char* Mailbox;
  const char* Separator;
  const char* Flags;
  int reserved;
} GMailMailboxListEventParams;

typedef struct {
  const char* MessageId;
  const char* Subject;
  const char* MessageDate;
  const char* From;
  const char* Flags;
  ns_int64 *pSize;
  const char* GMailMessageId;
  const char* GMailMessageThreadId;
  const char* GMailMessageLabels;
  int reserved;
} GMailMessageInfoEventParams;

typedef struct {
  const char* PartId;
  ns_int64 *pSize;
  const char* ContentType;
  const char* Filename;
  const char* ContentEncoding;
  const char* Parameters;
  const char* MultipartMode;
  const char* ContentId;
  const char* ContentDisposition;
  int reserved;
} GMailMessagePartEventParams;

typedef struct {
  int Direction;
  const char* Message;
  int reserved;
} GMailPITrailEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GMailSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GMailSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GMailStartTransferEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int reserved;
} GMailTransferEventParams;



class GMail {
  
  public: //events
  
    virtual int FireConnectionStatus(GMailConnectionStatusEventParams *e) {return 0;}
    virtual int FireEndTransfer(GMailEndTransferEventParams *e) {return 0;}
    virtual int FireError(GMailErrorEventParams *e) {return 0;}
    virtual int FireHeader(GMailHeaderEventParams *e) {return 0;}
    virtual int FireMailboxACL(GMailMailboxACLEventParams *e) {return 0;}
    virtual int FireMailboxList(GMailMailboxListEventParams *e) {return 0;}
    virtual int FireMessageInfo(GMailMessageInfoEventParams *e) {return 0;}
    virtual int FireMessagePart(GMailMessagePartEventParams *e) {return 0;}
    virtual int FirePITrail(GMailPITrailEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GMailSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GMailSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GMailStartTransferEventParams *e) {return 0;}
    virtual int FireTransfer(GMailTransferEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GMailEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GMail*)lpObj)->GMailEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GMailConnectionStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GMail*)lpObj)->FireConnectionStatus(&e);
            break;
         }
         case 2: {
            GMailEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GMail*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 3: {
            GMailErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GMail*)lpObj)->FireError(&e);
            break;
         }
         case 4: {
            GMailHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GMail*)lpObj)->FireHeader(&e);
            break;
         }
         case 5: {
            GMailMailboxACLEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GMail*)lpObj)->FireMailboxACL(&e);
            break;
         }
         case 6: {
            GMailMailboxListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GMail*)lpObj)->FireMailboxList(&e);
            break;
         }
         case 7: {
            GMailMessageInfoEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (ns_int64*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]), (char*)IBG64CAST(param[7]), (char*)IBG64CAST(param[8]),  0};
            ret_code = ((GMail*)lpObj)->FireMessageInfo(&e);
            break;
         }
         case 8: {
            GMailMessagePartEventParams e = {(char*)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]), (char*)IBG64CAST(param[7]), (char*)IBG64CAST(param[8]),  0};
            ret_code = ((GMail*)lpObj)->FireMessagePart(&e);
            break;
         }
         case 9: {
            GMailPITrailEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GMail*)lpObj)->FirePITrail(&e);
            break;
         }
         case 10: {
            GMailSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GMail*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 11: {
            GMailSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GMail*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 12: {
            GMailStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GMail*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 13: {
            GMailTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]),  0};
            ret_code = ((GMail*)lpObj)->FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GMailEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GMail(char *lpOemKey = (char*)INGOOGLE_OEMKEY_70) {
      m_pObj = InGoogle_GMail_Create(GMailEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GMail() {
      InGoogle_GMail_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GMail_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GMail_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GMail_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline int GetAuthMechanism() {
      void* val = InGoogle_GMail_Get(m_pObj, 1, 0, 0);
      return (int)(long)val;
    }
    inline int SetAuthMechanism(int iAuthMechanism) {
      void* val = (void*)IBG64CAST(iAuthMechanism);
      return InGoogle_GMail_Set(m_pObj, 1, 0, val, 0);
    }
    inline char* GetAuthorization() {
      void* val = InGoogle_GMail_Get(m_pObj, 2, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GMail_Set(m_pObj, 2, 0, (void*)lpAuthorization, 0);
    }

    inline int GetAutoDecodeParts() {
      void* val = InGoogle_GMail_Get(m_pObj, 3, 0, 0);
      return (int)(long)val;
    }
    inline int SetAutoDecodeParts(int bAutoDecodeParts) {
      void* val = (void*)IBG64CAST(bAutoDecodeParts);
      return InGoogle_GMail_Set(m_pObj, 3, 0, val, 0);
    }

    inline int SetCommand(const char *lpCommand) {
      return InGoogle_GMail_Set(m_pObj, 4, 0, (void*)lpCommand, 0);
    }

    inline int GetConnected() {
      void* val = InGoogle_GMail_Get(m_pObj, 5, 0, 0);
      return (int)(long)val;
    }
    inline int SetConnected(int bConnected) {
      void* val = (void*)IBG64CAST(bConnected);
      return InGoogle_GMail_Set(m_pObj, 5, 0, val, 0);
    }
    inline ns_int64 GetEndByte() {
      ns_int64 *pval = (ns_int64*)InGoogle_GMail_Get(m_pObj, 6, 0, 0);
      return *pval;
    }

    inline int SetEndByte(ns_int64 lEndByte) {
      void* val = (void*)(&lEndByte);
      return InGoogle_GMail_Set(m_pObj, 6, 0, val, 0);
    }

    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GMail_Get(m_pObj, 7, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GMail_Set(m_pObj, 7, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GMail_Get(m_pObj, 8, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GMail_Set(m_pObj, 8, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GMail_Get(m_pObj, 9, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GMail_Set(m_pObj, 9, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GMail_Get(m_pObj, 10, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GMail_Set(m_pObj, 10, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GMail_Get(m_pObj, 11, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GMail_Set(m_pObj, 11, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GMail_Get(m_pObj, 12, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GMail_Set(m_pObj, 12, 0, (void*)lpFirewallUser, 0);
    }

    inline char* GetLastReply() {
      void* val = InGoogle_GMail_Get(m_pObj, 13, 0, 0);
      return (char*)val;
    }


    inline char* GetLocalFile() {
      void* val = InGoogle_GMail_Get(m_pObj, 14, 0, 0);
      return (char*)val;
    }

    inline int SetLocalFile(const char *lpLocalFile) {
      return InGoogle_GMail_Set(m_pObj, 14, 0, (void*)lpLocalFile, 0);
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GMail_Get(m_pObj, 15, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GMail_Set(m_pObj, 15, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetMailbox() {
      void* val = InGoogle_GMail_Get(m_pObj, 16, 0, 0);
      return (char*)val;
    }

    inline int SetMailbox(const char *lpMailbox) {
      return InGoogle_GMail_Set(m_pObj, 16, 0, (void*)lpMailbox, 0);
    }

    inline char* GetMailboxFlags() {
      void* val = InGoogle_GMail_Get(m_pObj, 17, 0, 0);
      return (char*)val;
    }


    inline int GetMailboxListCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 18, 0, 0);
      return (int)(long)val;
    }

    inline char* GetMailboxListFlags(int iMailboxListIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 19, iMailboxListIndex, 0);
      return (char*)val;
    }


    inline char* GetMailboxListName(int iMailboxListIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 20, iMailboxListIndex, 0);
      return (char*)val;
    }


    inline char* GetMailboxListSeparator(int iMailboxListIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 21, iMailboxListIndex, 0);
      return (char*)val;
    }


    inline int GetMailPort() {
      void* val = InGoogle_GMail_Get(m_pObj, 22, 0, 0);
      return (int)(long)val;
    }
    inline int SetMailPort(int lMailPort) {
      void* val = (void*)IBG64CAST(lMailPort);
      return InGoogle_GMail_Set(m_pObj, 22, 0, val, 0);
    }
    inline char* GetMailServer() {
      void* val = InGoogle_GMail_Get(m_pObj, 23, 0, 0);
      return (char*)val;
    }

    inline int SetMailServer(const char *lpMailServer) {
      return InGoogle_GMail_Set(m_pObj, 23, 0, (void*)lpMailServer, 0);
    }

    inline int GetMessage(char *&lpMessage, int &lenMessage) {
      lpMessage = (char*)InGoogle_GMail_Get(m_pObj, 24, 0, &lenMessage);
      return lpMessage ? 0 : lenMessage;
    }

    inline int SetMessage(const char *lpMessage, int lenMessage) {
      return InGoogle_GMail_Set(m_pObj, 24, 0, (void*)lpMessage, lenMessage);
    }

    inline char* GetMessageContentEncoding() {
      void* val = InGoogle_GMail_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageContentType() {
      void* val = InGoogle_GMail_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }


    inline int GetMessageCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 27, 0, 0);
      return (int)(long)val;
    }

    inline char* GetMessageDate() {
      void* val = InGoogle_GMail_Get(m_pObj, 28, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageDeliveryTime() {
      void* val = InGoogle_GMail_Get(m_pObj, 29, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageFlags() {
      void* val = InGoogle_GMail_Get(m_pObj, 30, 0, 0);
      return (char*)val;
    }

    inline int SetMessageFlags(const char *lpMessageFlags) {
      return InGoogle_GMail_Set(m_pObj, 30, 0, (void*)lpMessageFlags, 0);
    }

    inline char* GetMessageFrom() {
      void* val = InGoogle_GMail_Get(m_pObj, 31, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageGmailId() {
      void* val = InGoogle_GMail_Get(m_pObj, 32, 0, 0);
      return (char*)val;
    }

    inline int SetMessageGmailId(const char *lpMessageGmailId) {
      return InGoogle_GMail_Set(m_pObj, 32, 0, (void*)lpMessageGmailId, 0);
    }

    inline int GetMessageHeaderCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 33, 0, 0);
      return (int)(long)val;
    }
    inline int SetMessageHeaderCount(int iMessageHeaderCount) {
      void* val = (void*)IBG64CAST(iMessageHeaderCount);
      return InGoogle_GMail_Set(m_pObj, 33, 0, val, 0);
    }
    inline char* GetMessageHeaderField(int iMessageHeaderIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 34, iMessageHeaderIndex, 0);
      return (char*)val;
    }

    inline int SetMessageHeaderField(int iMessageHeaderIndex, const char *lpMessageHeaderField) {
      return InGoogle_GMail_Set(m_pObj, 34, iMessageHeaderIndex, (void*)lpMessageHeaderField, 0);
    }

    inline char* GetMessageHeaderValue(int iMessageHeaderIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 35, iMessageHeaderIndex, 0);
      return (char*)val;
    }

    inline int SetMessageHeaderValue(int iMessageHeaderIndex, const char *lpMessageHeaderValue) {
      return InGoogle_GMail_Set(m_pObj, 35, iMessageHeaderIndex, (void*)lpMessageHeaderValue, 0);
    }

    inline char* GetMessageHeadersString() {
      void* val = InGoogle_GMail_Get(m_pObj, 36, 0, 0);
      return (char*)val;
    }

    inline int SetMessageHeadersString(const char *lpMessageHeadersString) {
      return InGoogle_GMail_Set(m_pObj, 36, 0, (void*)lpMessageHeadersString, 0);
    }

    inline char* GetMessageId() {
      void* val = InGoogle_GMail_Get(m_pObj, 37, 0, 0);
      return (char*)val;
    }


    inline int GetMessageInfoCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 38, 0, 0);
      return (int)(long)val;
    }

    inline char* GetMessageInfoDate(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 39, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoFlags(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 40, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoFrom(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 41, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoGmailId(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 42, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoLabels(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 43, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoMessageId(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 44, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline ns_int64 GetMessageInfoSize(int iMessageInfoIndex) {
      ns_int64 *pval = (ns_int64*)InGoogle_GMail_Get(m_pObj, 45, iMessageInfoIndex, 0);
      return *pval;
    }


    inline char* GetMessageInfoSubject(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 46, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInfoThreadId(int iMessageInfoIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 47, iMessageInfoIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageInReplyTo() {
      void* val = InGoogle_GMail_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageLabels() {
      void* val = InGoogle_GMail_Get(m_pObj, 49, 0, 0);
      return (char*)val;
    }

    inline int SetMessageLabels(const char *lpMessageLabels) {
      return InGoogle_GMail_Set(m_pObj, 49, 0, (void*)lpMessageLabels, 0);
    }

    inline char* GetMessageNetId() {
      void* val = InGoogle_GMail_Get(m_pObj, 50, 0, 0);
      return (char*)val;
    }


    inline int GetMessagePartCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 51, 0, 0);
      return (int)(long)val;
    }

    inline char* GetMessagePartContentDisposition(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 52, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartContentEncoding(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 53, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartContentId(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 54, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartContentType(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 55, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartFilename(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 56, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartId(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 57, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartMultipartMode(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 58, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline char* GetMessagePartParameters(int iMessagePartIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 59, iMessagePartIndex, 0);
      return (char*)val;
    }


    inline ns_int64 GetMessagePartSize(int iMessagePartIndex) {
      ns_int64 *pval = (ns_int64*)InGoogle_GMail_Get(m_pObj, 60, iMessagePartIndex, 0);
      return *pval;
    }


    inline int GetMessageRecipientCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 61, 0, 0);
      return (int)(long)val;
    }

    inline char* GetMessageRecipientAddress(int iRecipientIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 62, iRecipientIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageRecipientName(int iRecipientIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 63, iRecipientIndex, 0);
      return (char*)val;
    }


    inline char* GetMessageRecipientOptions(int iRecipientIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 64, iRecipientIndex, 0);
      return (char*)val;
    }


    inline int GetMessageRecipientType(int iRecipientIndex) {
      void* val = InGoogle_GMail_Get(m_pObj, 65, iRecipientIndex, 0);
      return (int)(long)val;
    }

    inline char* GetMessageReplyTo() {
      void* val = InGoogle_GMail_Get(m_pObj, 66, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageSender() {
      void* val = InGoogle_GMail_Get(m_pObj, 67, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageSet() {
      void* val = InGoogle_GMail_Get(m_pObj, 68, 0, 0);
      return (char*)val;
    }

    inline int SetMessageSet(const char *lpMessageSet) {
      return InGoogle_GMail_Set(m_pObj, 68, 0, (void*)lpMessageSet, 0);
    }

    inline ns_int64 GetMessageSize() {
      ns_int64 *pval = (ns_int64*)InGoogle_GMail_Get(m_pObj, 69, 0, 0);
      return *pval;
    }


    inline char* GetMessageSubject() {
      void* val = InGoogle_GMail_Get(m_pObj, 70, 0, 0);
      return (char*)val;
    }


    inline char* GetMessageText() {
      void* val = InGoogle_GMail_Get(m_pObj, 71, 0, 0);
      return (char*)val;
    }

    inline int SetMessageText(const char *lpMessageText) {
      return InGoogle_GMail_Set(m_pObj, 71, 0, (void*)lpMessageText, 0);
    }

    inline char* GetMessageThreadId() {
      void* val = InGoogle_GMail_Get(m_pObj, 72, 0, 0);
      return (char*)val;
    }

    inline int SetMessageThreadId(const char *lpMessageThreadId) {
      return InGoogle_GMail_Set(m_pObj, 72, 0, (void*)lpMessageThreadId, 0);
    }

    inline int GetOverwrite() {
      void* val = InGoogle_GMail_Get(m_pObj, 73, 0, 0);
      return (int)(long)val;
    }
    inline int SetOverwrite(int bOverwrite) {
      void* val = (void*)IBG64CAST(bOverwrite);
      return InGoogle_GMail_Set(m_pObj, 73, 0, val, 0);
    }
    inline char* GetPassword() {
      void* val = InGoogle_GMail_Get(m_pObj, 74, 0, 0);
      return (char*)val;
    }

    inline int SetPassword(const char *lpPassword) {
      return InGoogle_GMail_Set(m_pObj, 74, 0, (void*)lpPassword, 0);
    }

    inline int GetPeekMode() {
      void* val = InGoogle_GMail_Get(m_pObj, 75, 0, 0);
      return (int)(long)val;
    }
    inline int SetPeekMode(int bPeekMode) {
      void* val = (void*)IBG64CAST(bPeekMode);
      return InGoogle_GMail_Set(m_pObj, 75, 0, val, 0);
    }
    inline int GetRecentMessageCount() {
      void* val = InGoogle_GMail_Get(m_pObj, 76, 0, 0);
      return (int)(long)val;
    }

    inline char* GetSearchCriteriaId() {
      void* val = InGoogle_GMail_Get(m_pObj, 77, 0, 0);
      return (char*)val;
    }

    inline int SetSearchCriteriaId(const char *lpSearchCriteriaId) {
      return InGoogle_GMail_Set(m_pObj, 77, 0, (void*)lpSearchCriteriaId, 0);
    }

    inline char* GetSearchCriteriaLabels() {
      void* val = InGoogle_GMail_Get(m_pObj, 78, 0, 0);
      return (char*)val;
    }

    inline int SetSearchCriteriaLabels(const char *lpSearchCriteriaLabels) {
      return InGoogle_GMail_Set(m_pObj, 78, 0, (void*)lpSearchCriteriaLabels, 0);
    }

    inline char* GetSearchCriteriaString() {
      void* val = InGoogle_GMail_Get(m_pObj, 79, 0, 0);
      return (char*)val;
    }

    inline int SetSearchCriteriaString(const char *lpSearchCriteriaString) {
      return InGoogle_GMail_Set(m_pObj, 79, 0, (void*)lpSearchCriteriaString, 0);
    }

    inline char* GetSearchCriteriaThreadId() {
      void* val = InGoogle_GMail_Get(m_pObj, 80, 0, 0);
      return (char*)val;
    }

    inline int SetSearchCriteriaThreadId(const char *lpSearchCriteriaThreadId) {
      return InGoogle_GMail_Set(m_pObj, 80, 0, (void*)lpSearchCriteriaThreadId, 0);
    }

    inline char* GetSortCriteria() {
      void* val = InGoogle_GMail_Get(m_pObj, 81, 0, 0);
      return (char*)val;
    }

    inline int SetSortCriteria(const char *lpSortCriteria) {
      return InGoogle_GMail_Set(m_pObj, 81, 0, (void*)lpSortCriteria, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 82, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 82, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 83, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 83, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GMail_Get(m_pObj, 84, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GMail_Set(m_pObj, 84, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GMail_Get(m_pObj, 85, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GMail_Set(m_pObj, 85, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GMail_Get(m_pObj, 86, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GMail_Set(m_pObj, 86, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GMail_Get(m_pObj, 87, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GMail_Set(m_pObj, 87, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 88, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetSSLStartMode() {
      void* val = InGoogle_GMail_Get(m_pObj, 89, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLStartMode(int iSSLStartMode) {
      void* val = (void*)IBG64CAST(iSSLStartMode);
      return InGoogle_GMail_Set(m_pObj, 89, 0, val, 0);
    }
    inline ns_int64 GetStartByte() {
      ns_int64 *pval = (ns_int64*)InGoogle_GMail_Get(m_pObj, 90, 0, 0);
      return *pval;
    }

    inline int SetStartByte(ns_int64 lStartByte) {
      void* val = (void*)(&lStartByte);
      return InGoogle_GMail_Set(m_pObj, 90, 0, val, 0);
    }

    inline int GetTimeout() {
      void* val = InGoogle_GMail_Get(m_pObj, 91, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GMail_Set(m_pObj, 91, 0, val, 0);
    }
    inline int GetUIDMode() {
      void* val = InGoogle_GMail_Get(m_pObj, 92, 0, 0);
      return (int)(long)val;
    }
    inline int SetUIDMode(int bUIDMode) {
      void* val = (void*)IBG64CAST(bUIDMode);
      return InGoogle_GMail_Set(m_pObj, 92, 0, val, 0);
    }
    inline char* GetUIDValidity() {
      void* val = InGoogle_GMail_Get(m_pObj, 93, 0, 0);
      return (char*)val;
    }


    inline char* GetUser() {
      void* val = InGoogle_GMail_Get(m_pObj, 94, 0, 0);
      return (char*)val;
    }

    inline int SetUser(const char *lpUser) {
      return InGoogle_GMail_Set(m_pObj, 94, 0, (void*)lpUser, 0);
    }


  public: //methods

    inline int AddMessageFlags(const char* lpszFlags) {
      void *param[1+1] = {(void*)IBG64CAST(lpszFlags), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 2, 1, param, cbparam);
      
      
    }
    inline int AddMessageLabels(const char* lpszLabels) {
      void *param[1+1] = {(void*)IBG64CAST(lpszLabels), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 3, 1, param, cbparam);
      
      
    }
    inline int AppendToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 4, 0, param, cbparam);
      
      
    }
    inline int CheckMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline int CloseMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 6, 0, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GMail_Do(m_pObj, 7, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int Connect() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 8, 0, param, cbparam);
      
      
    }
    inline int CopyToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline int CreateMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10, 0, param, cbparam);
      
      
    }
    inline int DeleteFromMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 11, 0, param, cbparam);
      
      
    }
    inline int DeleteMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 12, 0, param, cbparam);
      
      
    }
    inline int DeleteMailboxACL(const char* lpszUser) {
      void *param[1+1] = {(void*)IBG64CAST(lpszUser), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 13, 1, param, cbparam);
      
      
    }
    inline int Disconnect() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 14, 0, param, cbparam);
      
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 15, 0, param, cbparam);
      
      
    }
    inline int ExamineMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 16, 0, param, cbparam);
      
      
    }
    inline int ExpungeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 17, 0, param, cbparam);
      
      
    }
    inline int FetchMessageHeaders() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 18, 0, param, cbparam);
      
      
    }
    inline int FetchMessageInfo() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 19, 0, param, cbparam);
      
      
    }
    inline int FetchMessagePart(const char* lpszPartId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszPartId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 20, 1, param, cbparam);
      
      
    }
    inline int FetchMessagePartHeaders(const char* lpszPartId) {
      void *param[1+1] = {(void*)IBG64CAST(lpszPartId), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 21, 1, param, cbparam);
      
      
    }
    inline int FetchMessageText() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 22, 0, param, cbparam);
      
      
    }
    inline int GetMailboxACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 23, 0, param, cbparam);
      
      
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 24, 0, param, cbparam);
      
      
    }
    inline int ListMailboxes() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 25, 0, param, cbparam);
      
      
    }
    inline int ListSubscribedMailboxes() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 26, 0, param, cbparam);
      
      
    }
    inline char* LocalizeDate(const char* lpszDateTime) {
      void *param[1+1] = {(void*)IBG64CAST(lpszDateTime), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GMail_Do(m_pObj, 27, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int MoveToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 28, 0, param, cbparam);
      
      
    }
    inline int Noop() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 29, 0, param, cbparam);
      
      
    }
    inline int RenameMailbox(const char* lpszNewName) {
      void *param[1+1] = {(void*)IBG64CAST(lpszNewName), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 30, 1, param, cbparam);
      
      
    }
    inline int ResetMessageFlags() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 31, 0, param, cbparam);
      
      
    }
    inline int ResetMessageLabels() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 32, 0, param, cbparam);
      
      
    }
    inline int SearchMailbox(const char* lpszSearchCriteria) {
      void *param[1+1] = {(void*)IBG64CAST(lpszSearchCriteria), 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 33, 1, param, cbparam);
      
      
    }
    inline int SelectMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 34, 0, param, cbparam);
      
      
    }
    inline int SetMailboxACL(const char* lpszUser, const char* lpszRights) {
      void *param[2+1] = {(void*)IBG64CAST(lpszUser), (void*)IBG64CAST(lpszRights), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GMail_Do(m_pObj, 35, 2, param, cbparam);
      
      
    }
    inline int SubscribeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 37, 0, param, cbparam);
      
      
    }
    inline int UnsetMessageFlags() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 38, 0, param, cbparam);
      
      
    }
    inline int UnsetMessageLabels() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 39, 0, param, cbparam);
      
      
    }
    inline int UnsubscribeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 40, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR ConnectionEvent;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GMailConnectionStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GMailEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GMailErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GMailHeaderEventParamsW;

typedef struct {
  LPWSTR Mailbox;
  LPWSTR User;
  LPWSTR Rights;
  int reserved;
} GMailMailboxACLEventParamsW;

typedef struct {
  LPWSTR Mailbox;
  LPWSTR Separator;
  LPWSTR Flags;
  int reserved;
} GMailMailboxListEventParamsW;

typedef struct {
  LPWSTR MessageId;
  LPWSTR Subject;
  LPWSTR MessageDate;
  LPWSTR From;
  LPWSTR Flags;
  ns_int64 *pSize;
  LPWSTR GMailMessageId;
  LPWSTR GMailMessageThreadId;
  LPWSTR GMailMessageLabels;
  int reserved;
} GMailMessageInfoEventParamsW;

typedef struct {
  LPWSTR PartId;
  ns_int64 *pSize;
  LPWSTR ContentType;
  LPWSTR Filename;
  LPWSTR ContentEncoding;
  LPWSTR Parameters;
  LPWSTR MultipartMode;
  LPWSTR ContentId;
  LPWSTR ContentDisposition;
  int reserved;
} GMailMessagePartEventParamsW;

typedef struct {
  int Direction;
  LPWSTR Message;
  int reserved;
} GMailPITrailEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GMailSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GMailSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GMailStartTransferEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int reserved;
} GMailTransferEventParamsW;



class GMailW : public GMail {

  public: //properties
  


    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+2, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GMail_Set(m_pObj, 10000+2, 0, (void*)lpAuthorization, 0);
    }





    inline int SetCommand(LPWSTR lpCommand) {
      return InGoogle_GMail_Set(m_pObj, 10000+4, 0, (void*)lpCommand, 0);
    }









    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+9, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GMail_Set(m_pObj, 10000+9, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+10, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GMail_Set(m_pObj, 10000+10, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+12, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GMail_Set(m_pObj, 10000+12, 0, (void*)lpFirewallUser, 0);
    }

    inline LPWSTR GetLastReply() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+13, 0, 0);
    }



    inline LPWSTR GetLocalFile() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+10000+14, 0, 0);
    }

    inline int SetLocalFile(LPWSTR lpLocalFile) {
      return InGoogle_GMail_Set(m_pObj, 10000+10000+14, 0, (void*)lpLocalFile, 0);
    }

    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+15, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GMail_Set(m_pObj, 10000+15, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetMailbox() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+16, 0, 0);
    }

    inline int SetMailbox(LPWSTR lpMailbox) {
      return InGoogle_GMail_Set(m_pObj, 10000+16, 0, (void*)lpMailbox, 0);
    }

    inline LPWSTR GetMailboxFlags() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+17, 0, 0);
    }





    inline LPWSTR GetMailboxListFlags(int iMailboxListIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+19, iMailboxListIndex, 0);
    }



    inline LPWSTR GetMailboxListName(int iMailboxListIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+20, iMailboxListIndex, 0);
    }



    inline LPWSTR GetMailboxListSeparator(int iMailboxListIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+21, iMailboxListIndex, 0);
    }





    inline LPWSTR GetMailServer() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+23, 0, 0);
    }

    inline int SetMailServer(LPWSTR lpMailServer) {
      return InGoogle_GMail_Set(m_pObj, 10000+23, 0, (void*)lpMailServer, 0);
    }

    inline LPWSTR GetMessage() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+24, 0, 0);
    }

    inline int SetMessage(LPWSTR lpMessage) {
      return InGoogle_GMail_Set(m_pObj, 10000+24, 0, (void*)lpMessage, 0);
    }
    inline int GetMessageB(char *&lpMessage, int &lenMessage) {
      lpMessage = (char*)InGoogle_GMail_Get(m_pObj, 24, 0, &lenMessage);
      return lpMessage ? 0 : lenMessage;
    }
    inline int SetMessageB(const char *lpMessage, int lenMessage) {
      return InGoogle_GMail_Set(m_pObj, 24, 0, (void*)lpMessage, lenMessage);
    }
    inline LPWSTR GetMessageContentEncoding() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+25, 0, 0);
    }



    inline LPWSTR GetMessageContentType() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+26, 0, 0);
    }





    inline LPWSTR GetMessageDate() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+28, 0, 0);
    }



    inline LPWSTR GetMessageDeliveryTime() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+29, 0, 0);
    }



    inline LPWSTR GetMessageFlags() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+30, 0, 0);
    }

    inline int SetMessageFlags(LPWSTR lpMessageFlags) {
      return InGoogle_GMail_Set(m_pObj, 10000+30, 0, (void*)lpMessageFlags, 0);
    }

    inline LPWSTR GetMessageFrom() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+31, 0, 0);
    }



    inline LPWSTR GetMessageGmailId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+32, 0, 0);
    }

    inline int SetMessageGmailId(LPWSTR lpMessageGmailId) {
      return InGoogle_GMail_Set(m_pObj, 10000+32, 0, (void*)lpMessageGmailId, 0);
    }



    inline LPWSTR GetMessageHeaderField(int iMessageHeaderIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+34, iMessageHeaderIndex, 0);
    }

    inline int SetMessageHeaderField(int iMessageHeaderIndex, LPWSTR lpMessageHeaderField) {
      return InGoogle_GMail_Set(m_pObj, 10000+34, iMessageHeaderIndex, (void*)lpMessageHeaderField, 0);
    }

    inline LPWSTR GetMessageHeaderValue(int iMessageHeaderIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+35, iMessageHeaderIndex, 0);
    }

    inline int SetMessageHeaderValue(int iMessageHeaderIndex, LPWSTR lpMessageHeaderValue) {
      return InGoogle_GMail_Set(m_pObj, 10000+35, iMessageHeaderIndex, (void*)lpMessageHeaderValue, 0);
    }

    inline LPWSTR GetMessageHeadersString() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+36, 0, 0);
    }

    inline int SetMessageHeadersString(LPWSTR lpMessageHeadersString) {
      return InGoogle_GMail_Set(m_pObj, 10000+36, 0, (void*)lpMessageHeadersString, 0);
    }

    inline LPWSTR GetMessageId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+37, 0, 0);
    }





    inline LPWSTR GetMessageInfoDate(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+39, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoFlags(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+40, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoFrom(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+41, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoGmailId(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+42, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoLabels(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+43, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoMessageId(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+44, iMessageInfoIndex, 0);
    }





    inline LPWSTR GetMessageInfoSubject(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+46, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInfoThreadId(int iMessageInfoIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+47, iMessageInfoIndex, 0);
    }



    inline LPWSTR GetMessageInReplyTo() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+48, 0, 0);
    }



    inline LPWSTR GetMessageLabels() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+49, 0, 0);
    }

    inline int SetMessageLabels(LPWSTR lpMessageLabels) {
      return InGoogle_GMail_Set(m_pObj, 10000+49, 0, (void*)lpMessageLabels, 0);
    }

    inline LPWSTR GetMessageNetId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+50, 0, 0);
    }





    inline LPWSTR GetMessagePartContentDisposition(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+52, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartContentEncoding(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+53, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartContentId(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+54, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartContentType(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+55, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartFilename(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+56, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartId(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+57, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartMultipartMode(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+58, iMessagePartIndex, 0);
    }



    inline LPWSTR GetMessagePartParameters(int iMessagePartIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+59, iMessagePartIndex, 0);
    }







    inline LPWSTR GetMessageRecipientAddress(int iRecipientIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+62, iRecipientIndex, 0);
    }



    inline LPWSTR GetMessageRecipientName(int iRecipientIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+63, iRecipientIndex, 0);
    }



    inline LPWSTR GetMessageRecipientOptions(int iRecipientIndex) {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+64, iRecipientIndex, 0);
    }





    inline LPWSTR GetMessageReplyTo() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+66, 0, 0);
    }



    inline LPWSTR GetMessageSender() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+67, 0, 0);
    }



    inline LPWSTR GetMessageSet() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+68, 0, 0);
    }

    inline int SetMessageSet(LPWSTR lpMessageSet) {
      return InGoogle_GMail_Set(m_pObj, 10000+68, 0, (void*)lpMessageSet, 0);
    }



    inline LPWSTR GetMessageSubject() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+70, 0, 0);
    }



    inline LPWSTR GetMessageText() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+71, 0, 0);
    }

    inline int SetMessageText(LPWSTR lpMessageText) {
      return InGoogle_GMail_Set(m_pObj, 10000+71, 0, (void*)lpMessageText, 0);
    }

    inline LPWSTR GetMessageThreadId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+72, 0, 0);
    }

    inline int SetMessageThreadId(LPWSTR lpMessageThreadId) {
      return InGoogle_GMail_Set(m_pObj, 10000+72, 0, (void*)lpMessageThreadId, 0);
    }



    inline LPWSTR GetPassword() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+74, 0, 0);
    }

    inline int SetPassword(LPWSTR lpPassword) {
      return InGoogle_GMail_Set(m_pObj, 10000+74, 0, (void*)lpPassword, 0);
    }





    inline LPWSTR GetSearchCriteriaId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+77, 0, 0);
    }

    inline int SetSearchCriteriaId(LPWSTR lpSearchCriteriaId) {
      return InGoogle_GMail_Set(m_pObj, 10000+77, 0, (void*)lpSearchCriteriaId, 0);
    }

    inline LPWSTR GetSearchCriteriaLabels() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+78, 0, 0);
    }

    inline int SetSearchCriteriaLabels(LPWSTR lpSearchCriteriaLabels) {
      return InGoogle_GMail_Set(m_pObj, 10000+78, 0, (void*)lpSearchCriteriaLabels, 0);
    }

    inline LPWSTR GetSearchCriteriaString() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+79, 0, 0);
    }

    inline int SetSearchCriteriaString(LPWSTR lpSearchCriteriaString) {
      return InGoogle_GMail_Set(m_pObj, 10000+79, 0, (void*)lpSearchCriteriaString, 0);
    }

    inline LPWSTR GetSearchCriteriaThreadId() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+80, 0, 0);
    }

    inline int SetSearchCriteriaThreadId(LPWSTR lpSearchCriteriaThreadId) {
      return InGoogle_GMail_Set(m_pObj, 10000+80, 0, (void*)lpSearchCriteriaThreadId, 0);
    }

    inline LPWSTR GetSortCriteria() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+81, 0, 0);
    }

    inline int SetSortCriteria(LPWSTR lpSortCriteria) {
      return InGoogle_GMail_Set(m_pObj, 10000+81, 0, (void*)lpSortCriteria, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+82, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 10000+82, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 82, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 82, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+83, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 10000+83, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 83, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GMail_Set(m_pObj, 83, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+84, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GMail_Set(m_pObj, 10000+84, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GMail_Get(m_pObj, 84, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GMail_Set(m_pObj, 84, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+85, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GMail_Set(m_pObj, 10000+85, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+87, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GMail_Set(m_pObj, 10000+87, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+88, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GMail_Get(m_pObj, 88, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }









    inline LPWSTR GetUIDValidity() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+93, 0, 0);
    }



    inline LPWSTR GetUser() {
      return (LPWSTR)InGoogle_GMail_Get(m_pObj, 10000+94, 0, 0);
    }

    inline int SetUser(LPWSTR lpUser) {
      return InGoogle_GMail_Set(m_pObj, 10000+94, 0, (void*)lpUser, 0);
    }



  public: //events
  
    virtual int FireConnectionStatus(GMailConnectionStatusEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GMailEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GMailErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GMailHeaderEventParamsW *e) {return 0;}
    virtual int FireMailboxACL(GMailMailboxACLEventParamsW *e) {return 0;}
    virtual int FireMailboxList(GMailMailboxListEventParamsW *e) {return 0;}
    virtual int FireMessageInfo(GMailMessageInfoEventParamsW *e) {return 0;}
    virtual int FireMessagePart(GMailMessagePartEventParamsW *e) {return 0;}
    virtual int FirePITrail(GMailPITrailEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GMailSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GMailSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GMailStartTransferEventParamsW *e) {return 0;}
    virtual int FireTransfer(GMailTransferEventParamsW *e) {return 0;}


  protected:
  
    virtual int GMailEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GMailConnectionStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireConnectionStatus(&e);
            break;
         }
         case 2: {
            GMailEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 3: {
            GMailErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 4: {
            GMailHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 5: {
            GMailMailboxACLEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireMailboxACL(&e);
            break;
         }
         case 6: {
            GMailMailboxListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireMailboxList(&e);
            break;
         }
         case 7: {
            GMailMessageInfoEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (ns_int64*)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]), (LPWSTR)IBG64CAST(param[7]), (LPWSTR)IBG64CAST(param[8]),  0};
            ret_code = FireMessageInfo(&e);
            break;
         }
         case 8: {
            GMailMessagePartEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]), (LPWSTR)IBG64CAST(param[7]), (LPWSTR)IBG64CAST(param[8]),  0};
            ret_code = FireMessagePart(&e);
            break;
         }
         case 9: {
            GMailPITrailEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FirePITrail(&e);
            break;
         }
         case 10: {
            GMailSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 11: {
            GMailSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 12: {
            GMailStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 13: {
            GMailTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireConnectionStatus(GMailConnectionStatusEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GMailEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GMailErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GMailHeaderEventParams *e) {return -10000;}
    virtual int FireMailboxACL(GMailMailboxACLEventParams *e) {return -10000;}
    virtual int FireMailboxList(GMailMailboxListEventParams *e) {return -10000;}
    virtual int FireMessageInfo(GMailMessageInfoEventParams *e) {return -10000;}
    virtual int FireMessagePart(GMailMessagePartEventParams *e) {return -10000;}
    virtual int FirePITrail(GMailPITrailEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GMailSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GMailSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GMailStartTransferEventParams *e) {return -10000;}
    virtual int FireTransfer(GMailTransferEventParams *e) {return -10000;}

  public: //methods

    inline int AddMessageFlags(LPWSTR lpszFlags) {
      void *param[1+1] = {(void*)lpszFlags, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+2, 1, param, cbparam);
      
    }
    inline int AddMessageLabels(LPWSTR lpszLabels) {
      void *param[1+1] = {(void*)lpszLabels, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+3, 1, param, cbparam);
      
    }
    inline int AppendToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+4, 0, param, cbparam);
      
    }
    inline int CheckMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline int CloseMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+6, 0, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GMail_Do(m_pObj, 10000+7, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int Connect() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+8, 0, param, cbparam);
      
    }
    inline int CopyToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline int CreateMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+10, 0, param, cbparam);
      
    }
    inline int DeleteFromMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+11, 0, param, cbparam);
      
    }
    inline int DeleteMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+12, 0, param, cbparam);
      
    }
    inline int DeleteMailboxACL(LPWSTR lpszUser) {
      void *param[1+1] = {(void*)lpszUser, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+13, 1, param, cbparam);
      
    }
    inline int Disconnect() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+14, 0, param, cbparam);
      
    }
    inline int DoEvents() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+15, 0, param, cbparam);
      
    }
    inline int ExamineMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+16, 0, param, cbparam);
      
    }
    inline int ExpungeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+17, 0, param, cbparam);
      
    }
    inline int FetchMessageHeaders() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+18, 0, param, cbparam);
      
    }
    inline int FetchMessageInfo() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+19, 0, param, cbparam);
      
    }
    inline int FetchMessagePart(LPWSTR lpszPartId) {
      void *param[1+1] = {(void*)lpszPartId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+20, 1, param, cbparam);
      
    }
    inline int FetchMessagePartHeaders(LPWSTR lpszPartId) {
      void *param[1+1] = {(void*)lpszPartId, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+21, 1, param, cbparam);
      
    }
    inline int FetchMessageText() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+22, 0, param, cbparam);
      
    }
    inline int GetMailboxACL() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+23, 0, param, cbparam);
      
    }
    inline int Interrupt() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+24, 0, param, cbparam);
      
    }
    inline int ListMailboxes() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+25, 0, param, cbparam);
      
    }
    inline int ListSubscribedMailboxes() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+26, 0, param, cbparam);
      
    }
    inline LPWSTR LocalizeDate(LPWSTR lpszDateTime) {
      void *param[1+1] = {(void*)lpszDateTime, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GMail_Do(m_pObj, 10000+27, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int MoveToMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+28, 0, param, cbparam);
      
    }
    inline int Noop() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+29, 0, param, cbparam);
      
    }
    inline int RenameMailbox(LPWSTR lpszNewName) {
      void *param[1+1] = {(void*)lpszNewName, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+30, 1, param, cbparam);
      
    }
    inline int ResetMessageFlags() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+31, 0, param, cbparam);
      
    }
    inline int ResetMessageLabels() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+32, 0, param, cbparam);
      
    }
    inline int SearchMailbox(LPWSTR lpszSearchCriteria) {
      void *param[1+1] = {(void*)lpszSearchCriteria, 0};
      int cbparam[1+1] = {0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+33, 1, param, cbparam);
      
    }
    inline int SelectMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+34, 0, param, cbparam);
      
    }
    inline int SetMailboxACL(LPWSTR lpszUser, LPWSTR lpszRights) {
      void *param[2+1] = {(void*)lpszUser, (void*)lpszRights, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GMail_Do(m_pObj, 10000+35, 2, param, cbparam);
      
    }
    inline int SubscribeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+37, 0, param, cbparam);
      
    }
    inline int UnsetMessageFlags() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+38, 0, param, cbparam);
      
    }
    inline int UnsetMessageLabels() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+39, 0, param, cbparam);
      
    }
    inline int UnsubscribeMailbox() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GMail_Do(m_pObj, 10000+40, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GMAIL_H_




