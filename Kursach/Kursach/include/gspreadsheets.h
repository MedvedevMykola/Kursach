/******************************************************************
   Google Integrator V2 C++ Edition
   Copyright (c) 2016 /n software inc. - All rights reserved.
*******************************************************************/

#ifndef _INGOOGLE_GSPREADSHEETS_H_
#define _INGOOGLE_GSPREADSHEETS_H_

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


extern "C" void* INGOOGLE_CALL InGoogle_GSpreadsheets_Create(PINGOOGLE_CALLBACK lpSink, void *lpContext, char *lpOemKey);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_Destroy(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_CheckIndex(void *lpObj, int propid, int arridx);
extern "C" void* INGOOGLE_CALL InGoogle_GSpreadsheets_Get(void *lpObj, int propid, int arridx, int *lpcbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_Set(void *lpObj, int propid, int arridx, const void *val, int cbVal);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_Do(void *lpObj, int methid, int cparam, void *param[], int cbparam[]);
extern "C" char* INGOOGLE_CALL InGoogle_GSpreadsheets_GetLastError(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_GetLastErrorCode(void *lpObj);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_StaticInit(void *hInst);
extern "C" int   INGOOGLE_CALL InGoogle_GSpreadsheets_StaticDestroy();

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4311) 
#pragma warning(disable:4312) 
#endif

typedef struct {
  const char* Id;
  const char* ETag;
  const char* DateUpdated;
  int Row;
  int Column;
  const char* InputValue;
  const char* NumericValue;
  int reserved;
} GSpreadsheetsCellListEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GSpreadsheetsConnectedEventParams;

typedef struct {
  int StatusCode;
  const char* Description;
  int reserved;
} GSpreadsheetsDisconnectedEventParams;

typedef struct {
  int Direction;
  int reserved;
} GSpreadsheetsEndTransferEventParams;

typedef struct {
  int ErrorCode;
  const char* Description;
  int reserved;
} GSpreadsheetsErrorEventParams;

typedef struct {
  const char* Field;
  const char* Value;
  int reserved;
} GSpreadsheetsHeaderEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* DateUpdated;
  const char* RowDetails;
  int reserved;
} GSpreadsheetsRowListEventParams;

typedef struct {
  const char* Name;
  const char* Value;
  const char* Expires;
  const char* Domain;
  const char* Path;
  int Secure;
  int reserved;
} GSpreadsheetsSetCookieEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* DateUpdated;
  const char* Title;
  const char* Author;
  int reserved;
} GSpreadsheetsSpreadsheetListEventParams;

typedef struct {
  const char* CertEncoded;
  const char* CertSubject;
  const char* CertIssuer;
  const char* Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GSpreadsheetsSSLServerAuthenticationEventParams;

typedef struct {
  const char* Message;
  int reserved;
} GSpreadsheetsSSLStatusEventParams;

typedef struct {
  int Direction;
  int reserved;
} GSpreadsheetsStartTransferEventParams;

typedef struct {
  const char* HTTPVersion;
  int StatusCode;
  const char* Description;
  int reserved;
} GSpreadsheetsStatusEventParams;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  const char* Text;
  int lenText;
  int reserved;
} GSpreadsheetsTransferEventParams;

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
} GSpreadsheetsUpdateACLResponseEventParams;

typedef struct {
  const char* Id;
  const char* ETag;
  const char* DateUpdated;
  const char* Title;
  int RowCount;
  int ColumnCount;
  int reserved;
} GSpreadsheetsWorksheetListEventParams;



class GSpreadsheets {
  
  public: //events
  
    virtual int FireCellList(GSpreadsheetsCellListEventParams *e) {return 0;}
    virtual int FireConnected(GSpreadsheetsConnectedEventParams *e) {return 0;}
    virtual int FireDisconnected(GSpreadsheetsDisconnectedEventParams *e) {return 0;}
    virtual int FireEndTransfer(GSpreadsheetsEndTransferEventParams *e) {return 0;}
    virtual int FireError(GSpreadsheetsErrorEventParams *e) {return 0;}
    virtual int FireHeader(GSpreadsheetsHeaderEventParams *e) {return 0;}
    virtual int FireRowList(GSpreadsheetsRowListEventParams *e) {return 0;}
    virtual int FireSetCookie(GSpreadsheetsSetCookieEventParams *e) {return 0;}
    virtual int FireSpreadsheetList(GSpreadsheetsSpreadsheetListEventParams *e) {return 0;}
    virtual int FireSSLServerAuthentication(GSpreadsheetsSSLServerAuthenticationEventParams *e) {return 0;}
    virtual int FireSSLStatus(GSpreadsheetsSSLStatusEventParams *e) {return 0;}
    virtual int FireStartTransfer(GSpreadsheetsStartTransferEventParams *e) {return 0;}
    virtual int FireStatus(GSpreadsheetsStatusEventParams *e) {return 0;}
    virtual int FireTransfer(GSpreadsheetsTransferEventParams *e) {return 0;}
    virtual int FireUpdateACLResponse(GSpreadsheetsUpdateACLResponseEventParams *e) {return 0;}
    virtual int FireWorksheetList(GSpreadsheetsWorksheetListEventParams *e) {return 0;}


  protected:

    void *m_pObj;
    
    static int INGOOGLE_CALL GSpreadsheetsEventSink(void *lpObj, int event_id, int cparam, void *param[], int cbparam[]) {
      int ret_code = 0;
      if (event_id > 10000) return ((GSpreadsheets*)lpObj)->GSpreadsheetsEventSinkW(event_id - 10000, cparam, param, cbparam);
      switch (event_id) {
         case 1: {
            GSpreadsheetsCellListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (char*)IBG64CAST(param[6]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireCellList(&e);
            break;
         }
         case 2: {
            GSpreadsheetsConnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireConnected(&e);
            break;
         }
         case 3: {
            GSpreadsheetsDisconnectedEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireDisconnected(&e);
            break;
         }
         case 4: {
            GSpreadsheetsEndTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireEndTransfer(&e);
            break;
         }
         case 5: {
            GSpreadsheetsErrorEventParams e = {(int)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireError(&e);
            break;
         }
         case 6: {
            GSpreadsheetsHeaderEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireHeader(&e);
            break;
         }
         case 7: {
            GSpreadsheetsRowListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireRowList(&e);
            break;
         }
         case 8: {
            GSpreadsheetsSetCookieEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireSetCookie(&e);
            break;
         }
         case 9: {
            GSpreadsheetsSpreadsheetListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireSpreadsheetList(&e);
            break;
         }
         case 10: {
            GSpreadsheetsSSLServerAuthenticationEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireSSLServerAuthentication(&e);
            param[4] = (void*)IBG64CAST(e.Accept);
            break;
         }
         case 11: {
            GSpreadsheetsSSLStatusEventParams e = {(char*)IBG64CAST(param[0]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireSSLStatus(&e);
            break;
         }
         case 12: {
            GSpreadsheetsStartTransferEventParams e = {(int)IBG64CAST(param[0]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireStartTransfer(&e);
            break;
         }
         case 13: {
            GSpreadsheetsStatusEventParams e = {(char*)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireStatus(&e);
            break;
         }
         case 14: {
            GSpreadsheetsTransferEventParams e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireTransfer(&e);
            break;
         }
         case 15: {
            GSpreadsheetsUpdateACLResponseEventParams e = {(int)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (char*)IBG64CAST(param[4]), (char*)IBG64CAST(param[5]), (int)IBG64CAST(param[6]), (char*)IBG64CAST(param[7]), (char*)IBG64CAST(param[8]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireUpdateACLResponse(&e);
            break;
         }
         case 16: {
            GSpreadsheetsWorksheetListEventParams e = {(char*)IBG64CAST(param[0]), (char*)IBG64CAST(param[1]), (char*)IBG64CAST(param[2]), (char*)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = ((GSpreadsheets*)lpObj)->FireWorksheetList(&e);
            break;
         }

      }
      return ret_code;
    }

    virtual int GSpreadsheetsEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {return 0;}

  public:

    GSpreadsheets(char *lpOemKey = (char*)INGOOGLE_OEMKEY_60) {
      m_pObj = InGoogle_GSpreadsheets_Create(GSpreadsheetsEventSink, (void*)this, (char*)lpOemKey);
    }

    virtual ~GSpreadsheets() {
      InGoogle_GSpreadsheets_Destroy(m_pObj);
    }

  public:

    inline char *GetLastError() {
      return InGoogle_GSpreadsheets_GetLastError(m_pObj);
    }
    
    inline int GetLastErrorCode() {
      return InGoogle_GSpreadsheets_GetLastErrorCode(m_pObj);
    }

    inline char *VERSION() {
      return (char*)InGoogle_GSpreadsheets_Get(m_pObj, 0, 0, 0);
    }

  public: //properties

    inline char* GetAuthorization() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 1, 0, 0);
      return (char*)val;
    }

    inline int SetAuthorization(const char *lpAuthorization) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 1, 0, (void*)lpAuthorization, 0);
    }

    inline int GetCellCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 2, 0, 0);
      return (int)(long)val;
    }

    inline char* GetCellDateUpdated() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 3, 0, 0);
      return (char*)val;
    }

    inline int SetCellDateUpdated(const char *lpCellDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 3, 0, (void*)lpCellDateUpdated, 0);
    }

    inline int GetCellDetailColumn() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 4, 0, 0);
      return (int)(long)val;
    }
    inline int SetCellDetailColumn(int iCellDetailColumn) {
      void* val = (void*)IBG64CAST(iCellDetailColumn);
      return InGoogle_GSpreadsheets_Set(m_pObj, 4, 0, val, 0);
    }
    inline char* GetCellDetailInputValue() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 5, 0, 0);
      return (char*)val;
    }

    inline int SetCellDetailInputValue(const char *lpCellDetailInputValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 5, 0, (void*)lpCellDetailInputValue, 0);
    }

    inline char* GetCellDetailNumericValue() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 6, 0, 0);
      return (char*)val;
    }


    inline int GetCellDetailRow() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 7, 0, 0);
      return (int)(long)val;
    }
    inline int SetCellDetailRow(int iCellDetailRow) {
      void* val = (void*)IBG64CAST(iCellDetailRow);
      return InGoogle_GSpreadsheets_Set(m_pObj, 7, 0, val, 0);
    }
    inline char* GetCellETag() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 8, 0, 0);
      return (char*)val;
    }

    inline int SetCellETag(const char *lpCellETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 8, 0, (void*)lpCellETag, 0);
    }

    inline int GetCellIndex() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 9, 0, 0);
      return (int)(long)val;
    }
    inline int SetCellIndex(int iCellIndex) {
      void* val = (void*)IBG64CAST(iCellIndex);
      return InGoogle_GSpreadsheets_Set(m_pObj, 9, 0, val, 0);
    }
    inline int GetCellPropertiesCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 10, 0, 0);
      return (int)(long)val;
    }
    inline int SetCellPropertiesCount(int iCellPropertiesCount) {
      void* val = (void*)IBG64CAST(iCellPropertiesCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 10, 0, val, 0);
    }
    inline char* GetCellPropertiesAttributes(int iCellPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 11, iCellPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetCellPropertiesAttributes(int iCellPropertiesIndex, const char *lpCellPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 11, iCellPropertiesIndex, (void*)lpCellPropertiesAttributes, 0);
    }

    inline char* GetCellPropertiesName(int iCellPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 12, iCellPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetCellPropertiesName(int iCellPropertiesIndex, const char *lpCellPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 12, iCellPropertiesIndex, (void*)lpCellPropertiesName, 0);
    }

    inline char* GetCellPropertiesValue(int iCellPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 13, iCellPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetCellPropertiesValue(int iCellPropertiesIndex, const char *lpCellPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 13, iCellPropertiesIndex, (void*)lpCellPropertiesValue, 0);
    }

    inline int GetCellPropertiesValueFormat(int iCellPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 14, iCellPropertiesIndex, 0);
      return (int)(long)val;
    }
    inline int SetCellPropertiesValueFormat(int iCellPropertiesIndex, int iCellPropertiesValueFormat) {
      void* val = (void*)IBG64CAST(iCellPropertiesValueFormat);
      return InGoogle_GSpreadsheets_Set(m_pObj, 14, iCellPropertiesIndex, val, 0);
    }
    inline char* GetCellPropertiesXPath(int iCellPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 15, iCellPropertiesIndex, 0);
      return (char*)val;
    }


    inline int GetCookieCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 16, 0, 0);
      return (int)(long)val;
    }
    inline int SetCookieCount(int iCookieCount) {
      void* val = (void*)IBG64CAST(iCookieCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 16, 0, val, 0);
    }
    inline char* GetCookieDomain(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 17, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieExpiration(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 18, iCookieIndex, 0);
      return (char*)val;
    }


    inline char* GetCookieName(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 19, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieName(int iCookieIndex, const char *lpCookieName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 19, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline char* GetCookiePath(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 20, iCookieIndex, 0);
      return (char*)val;
    }


    inline int GetCookieSecure(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 21, iCookieIndex, 0);
      return (int)(long)val;
    }

    inline char* GetCookieValue(int iCookieIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 22, iCookieIndex, 0);
      return (char*)val;
    }

    inline int SetCookieValue(int iCookieIndex, const char *lpCookieValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 22, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline char* GetFeedAuthor() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 23, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedAuthorUri() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 24, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryLabel() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 25, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryScheme() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 26, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedCategoryTerm() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 27, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedEditURL() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 28, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedETag() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 29, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedGenerator() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 30, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedId() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 31, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedNextURL() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 32, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchItemsPerPage() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 33, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchStartIndex() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 34, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedOpenSearchTotalResults() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 35, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedPreviousURL() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 36, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedSelfURL() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 37, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedTitle() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 38, 0, 0);
      return (char*)val;
    }


    inline char* GetFeedUpdated() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 39, 0, 0);
      return (char*)val;
    }


    inline int GetFirewallAutoDetect() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 40, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallAutoDetect(int bFirewallAutoDetect) {
      void* val = (void*)IBG64CAST(bFirewallAutoDetect);
      return InGoogle_GSpreadsheets_Set(m_pObj, 40, 0, val, 0);
    }
    inline int GetFirewallType() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 41, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallType(int iFirewallType) {
      void* val = (void*)IBG64CAST(iFirewallType);
      return InGoogle_GSpreadsheets_Set(m_pObj, 41, 0, val, 0);
    }
    inline char* GetFirewallHost() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 42, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallHost(const char *lpFirewallHost) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 42, 0, (void*)lpFirewallHost, 0);
    }

    inline char* GetFirewallPassword() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 43, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallPassword(const char *lpFirewallPassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 43, 0, (void*)lpFirewallPassword, 0);
    }

    inline int GetFirewallPort() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 44, 0, 0);
      return (int)(long)val;
    }
    inline int SetFirewallPort(int lFirewallPort) {
      void* val = (void*)IBG64CAST(lFirewallPort);
      return InGoogle_GSpreadsheets_Set(m_pObj, 44, 0, val, 0);
    }
    inline char* GetFirewallUser() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 45, 0, 0);
      return (char*)val;
    }

    inline int SetFirewallUser(const char *lpFirewallUser) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 45, 0, (void*)lpFirewallUser, 0);
    }

    inline int GetIdle() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 46, 0, 0);
      return (int)(long)val;
    }

    inline char* GetLocalHost() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 47, 0, 0);
      return (char*)val;
    }

    inline int SetLocalHost(const char *lpLocalHost) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 47, 0, (void*)lpLocalHost, 0);
    }

    inline char* GetOtherHeaders() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 48, 0, 0);
      return (char*)val;
    }

    inline int SetOtherHeaders(const char *lpOtherHeaders) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 48, 0, (void*)lpOtherHeaders, 0);
    }

    inline int GetParsedHeaderCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 49, 0, 0);
      return (int)(long)val;
    }

    inline char* GetParsedHeaderField(int iParsedHeaderIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 50, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline char* GetParsedHeaderValue(int iParsedHeaderIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 51, iParsedHeaderIndex, 0);
      return (char*)val;
    }


    inline int GetProxyAuthScheme() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 52, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAuthScheme(int iProxyAuthScheme) {
      void* val = (void*)IBG64CAST(iProxyAuthScheme);
      return InGoogle_GSpreadsheets_Set(m_pObj, 52, 0, val, 0);
    }
    inline int GetProxyAutoDetect() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 53, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyAutoDetect(int bProxyAutoDetect) {
      void* val = (void*)IBG64CAST(bProxyAutoDetect);
      return InGoogle_GSpreadsheets_Set(m_pObj, 53, 0, val, 0);
    }
    inline char* GetProxyPassword() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 54, 0, 0);
      return (char*)val;
    }

    inline int SetProxyPassword(const char *lpProxyPassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 54, 0, (void*)lpProxyPassword, 0);
    }

    inline int GetProxyPort() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 55, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxyPort(int lProxyPort) {
      void* val = (void*)IBG64CAST(lProxyPort);
      return InGoogle_GSpreadsheets_Set(m_pObj, 55, 0, val, 0);
    }
    inline char* GetProxyServer() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 56, 0, 0);
      return (char*)val;
    }

    inline int SetProxyServer(const char *lpProxyServer) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 56, 0, (void*)lpProxyServer, 0);
    }

    inline int GetProxySSL() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 57, 0, 0);
      return (int)(long)val;
    }
    inline int SetProxySSL(int iProxySSL) {
      void* val = (void*)IBG64CAST(iProxySSL);
      return InGoogle_GSpreadsheets_Set(m_pObj, 57, 0, val, 0);
    }
    inline char* GetProxyUser() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 58, 0, 0);
      return (char*)val;
    }

    inline int SetProxyUser(const char *lpProxyUser) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 58, 0, (void*)lpProxyUser, 0);
    }

    inline int GetQueryParamsCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 59, 0, 0);
      return (int)(long)val;
    }
    inline int SetQueryParamsCount(int iQueryParamsCount) {
      void* val = (void*)IBG64CAST(iQueryParamsCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 59, 0, val, 0);
    }
    inline char* GetQueryParamsName(int iQueryParamsIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 60, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, const char *lpQueryParamsName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 60, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline char* GetQueryParamsValue(int iQueryParamsIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 61, iQueryParamsIndex, 0);
      return (char*)val;
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, const char *lpQueryParamsValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 61, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }

    inline int GetRowCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 62, 0, 0);
      return (int)(long)val;
    }

    inline char* GetRowDateUpdated() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 63, 0, 0);
      return (char*)val;
    }

    inline int SetRowDateUpdated(const char *lpRowDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 63, 0, (void*)lpRowDateUpdated, 0);
    }

    inline int GetRowDetailCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 64, 0, 0);
      return (int)(long)val;
    }
    inline int SetRowDetailCount(int iRowDetailCount) {
      void* val = (void*)IBG64CAST(iRowDetailCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 64, 0, val, 0);
    }
    inline char* GetRowDetailHeader(int iRowDetailIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 65, iRowDetailIndex, 0);
      return (char*)val;
    }

    inline int SetRowDetailHeader(int iRowDetailIndex, const char *lpRowDetailHeader) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 65, iRowDetailIndex, (void*)lpRowDetailHeader, 0);
    }

    inline char* GetRowDetailValue(int iRowDetailIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 66, iRowDetailIndex, 0);
      return (char*)val;
    }

    inline int SetRowDetailValue(int iRowDetailIndex, const char *lpRowDetailValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 66, iRowDetailIndex, (void*)lpRowDetailValue, 0);
    }

    inline char* GetRowETag() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 67, 0, 0);
      return (char*)val;
    }

    inline int SetRowETag(const char *lpRowETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 67, 0, (void*)lpRowETag, 0);
    }

    inline int GetRowIndex() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 68, 0, 0);
      return (int)(long)val;
    }
    inline int SetRowIndex(int iRowIndex) {
      void* val = (void*)IBG64CAST(iRowIndex);
      return InGoogle_GSpreadsheets_Set(m_pObj, 68, 0, val, 0);
    }
    inline int GetRowPropertiesCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 69, 0, 0);
      return (int)(long)val;
    }
    inline int SetRowPropertiesCount(int iRowPropertiesCount) {
      void* val = (void*)IBG64CAST(iRowPropertiesCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 69, 0, val, 0);
    }
    inline char* GetRowPropertiesAttributes(int iRowPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 70, iRowPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetRowPropertiesAttributes(int iRowPropertiesIndex, const char *lpRowPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 70, iRowPropertiesIndex, (void*)lpRowPropertiesAttributes, 0);
    }

    inline char* GetRowPropertiesName(int iRowPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 71, iRowPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetRowPropertiesName(int iRowPropertiesIndex, const char *lpRowPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 71, iRowPropertiesIndex, (void*)lpRowPropertiesName, 0);
    }

    inline char* GetRowPropertiesValue(int iRowPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 72, iRowPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetRowPropertiesValue(int iRowPropertiesIndex, const char *lpRowPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 72, iRowPropertiesIndex, (void*)lpRowPropertiesValue, 0);
    }

    inline int GetRowPropertiesValueFormat(int iRowPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 73, iRowPropertiesIndex, 0);
      return (int)(long)val;
    }
    inline int SetRowPropertiesValueFormat(int iRowPropertiesIndex, int iRowPropertiesValueFormat) {
      void* val = (void*)IBG64CAST(iRowPropertiesValueFormat);
      return InGoogle_GSpreadsheets_Set(m_pObj, 73, iRowPropertiesIndex, val, 0);
    }
    inline char* GetRowPropertiesXPath(int iRowPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 74, iRowPropertiesIndex, 0);
      return (char*)val;
    }


    inline char* GetSpreadsheetAuthor() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 75, 0, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetAuthor(const char *lpSpreadsheetAuthor) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 75, 0, (void*)lpSpreadsheetAuthor, 0);
    }

    inline int GetSpreadsheetCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 76, 0, 0);
      return (int)(long)val;
    }

    inline char* GetSpreadsheetDateUpdated() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 77, 0, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetDateUpdated(const char *lpSpreadsheetDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 77, 0, (void*)lpSpreadsheetDateUpdated, 0);
    }

    inline char* GetSpreadsheetETag() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 78, 0, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetETag(const char *lpSpreadsheetETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 78, 0, (void*)lpSpreadsheetETag, 0);
    }

    inline int GetSpreadsheetIndex() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 79, 0, 0);
      return (int)(long)val;
    }
    inline int SetSpreadsheetIndex(int iSpreadsheetIndex) {
      void* val = (void*)IBG64CAST(iSpreadsheetIndex);
      return InGoogle_GSpreadsheets_Set(m_pObj, 79, 0, val, 0);
    }
    inline int GetSpreadsheetPropertiesCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 80, 0, 0);
      return (int)(long)val;
    }
    inline int SetSpreadsheetPropertiesCount(int iSpreadsheetPropertiesCount) {
      void* val = (void*)IBG64CAST(iSpreadsheetPropertiesCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 80, 0, val, 0);
    }
    inline char* GetSpreadsheetPropertiesAttributes(int iSpreadsheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 81, iSpreadsheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetPropertiesAttributes(int iSpreadsheetPropertiesIndex, const char *lpSpreadsheetPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 81, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesAttributes, 0);
    }

    inline char* GetSpreadsheetPropertiesName(int iSpreadsheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 82, iSpreadsheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetPropertiesName(int iSpreadsheetPropertiesIndex, const char *lpSpreadsheetPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 82, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesName, 0);
    }

    inline char* GetSpreadsheetPropertiesValue(int iSpreadsheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 83, iSpreadsheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetPropertiesValue(int iSpreadsheetPropertiesIndex, const char *lpSpreadsheetPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 83, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesValue, 0);
    }

    inline int GetSpreadsheetPropertiesValueFormat(int iSpreadsheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 84, iSpreadsheetPropertiesIndex, 0);
      return (int)(long)val;
    }
    inline int SetSpreadsheetPropertiesValueFormat(int iSpreadsheetPropertiesIndex, int iSpreadsheetPropertiesValueFormat) {
      void* val = (void*)IBG64CAST(iSpreadsheetPropertiesValueFormat);
      return InGoogle_GSpreadsheets_Set(m_pObj, 84, iSpreadsheetPropertiesIndex, val, 0);
    }
    inline char* GetSpreadsheetPropertiesXPath(int iSpreadsheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 85, iSpreadsheetPropertiesIndex, 0);
      return (char*)val;
    }


    inline char* GetSpreadsheetTitle() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 86, 0, 0);
      return (char*)val;
    }

    inline int SetSpreadsheetTitle(const char *lpSpreadsheetTitle) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 86, 0, (void*)lpSpreadsheetTitle, 0);
    }

    inline int GetSSLAcceptServerCertEncoded(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 87, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }

    inline int SetSSLAcceptServerCertEncoded(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 87, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }

    inline int GetSSLCertEncoded(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 88, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }

    inline int SetSSLCertEncoded(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 88, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }

    inline int GetSSLCertStore(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 89, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }

    inline int SetSSLCertStore(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 89, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }

    inline char* GetSSLCertStorePassword() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 90, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertStorePassword(const char *lpSSLCertStorePassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 90, 0, (void*)lpSSLCertStorePassword, 0);
    }

    inline int GetSSLCertStoreType() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 91, 0, 0);
      return (int)(long)val;
    }
    inline int SetSSLCertStoreType(int iSSLCertStoreType) {
      void* val = (void*)IBG64CAST(iSSLCertStoreType);
      return InGoogle_GSpreadsheets_Set(m_pObj, 91, 0, val, 0);
    }
    inline char* GetSSLCertSubject() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 92, 0, 0);
      return (char*)val;
    }

    inline int SetSSLCertSubject(const char *lpSSLCertSubject) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 92, 0, (void*)lpSSLCertSubject, 0);
    }

    inline int GetSSLServerCertEncoded(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 93, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }


    inline int GetTimeout() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 94, 0, 0);
      return (int)(long)val;
    }
    inline int SetTimeout(int iTimeout) {
      void* val = (void*)IBG64CAST(iTimeout);
      return InGoogle_GSpreadsheets_Set(m_pObj, 94, 0, val, 0);
    }
    inline int GetWorksheetColumnCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 95, 0, 0);
      return (int)(long)val;
    }
    inline int SetWorksheetColumnCount(int iWorksheetColumnCount) {
      void* val = (void*)IBG64CAST(iWorksheetColumnCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 95, 0, val, 0);
    }
    inline int GetWorksheetCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 96, 0, 0);
      return (int)(long)val;
    }

    inline char* GetWorksheetDateUpdated() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 97, 0, 0);
      return (char*)val;
    }

    inline int SetWorksheetDateUpdated(const char *lpWorksheetDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 97, 0, (void*)lpWorksheetDateUpdated, 0);
    }

    inline char* GetWorksheetETag() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 98, 0, 0);
      return (char*)val;
    }

    inline int SetWorksheetETag(const char *lpWorksheetETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 98, 0, (void*)lpWorksheetETag, 0);
    }

    inline int GetWorksheetIndex() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 99, 0, 0);
      return (int)(long)val;
    }
    inline int SetWorksheetIndex(int iWorksheetIndex) {
      void* val = (void*)IBG64CAST(iWorksheetIndex);
      return InGoogle_GSpreadsheets_Set(m_pObj, 99, 0, val, 0);
    }
    inline int GetWorksheetPropertiesCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 100, 0, 0);
      return (int)(long)val;
    }
    inline int SetWorksheetPropertiesCount(int iWorksheetPropertiesCount) {
      void* val = (void*)IBG64CAST(iWorksheetPropertiesCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 100, 0, val, 0);
    }
    inline char* GetWorksheetPropertiesAttributes(int iWorksheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 101, iWorksheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetWorksheetPropertiesAttributes(int iWorksheetPropertiesIndex, const char *lpWorksheetPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 101, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesAttributes, 0);
    }

    inline char* GetWorksheetPropertiesName(int iWorksheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 102, iWorksheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetWorksheetPropertiesName(int iWorksheetPropertiesIndex, const char *lpWorksheetPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 102, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesName, 0);
    }

    inline char* GetWorksheetPropertiesValue(int iWorksheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 103, iWorksheetPropertiesIndex, 0);
      return (char*)val;
    }

    inline int SetWorksheetPropertiesValue(int iWorksheetPropertiesIndex, const char *lpWorksheetPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 103, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesValue, 0);
    }

    inline int GetWorksheetPropertiesValueFormat(int iWorksheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 104, iWorksheetPropertiesIndex, 0);
      return (int)(long)val;
    }
    inline int SetWorksheetPropertiesValueFormat(int iWorksheetPropertiesIndex, int iWorksheetPropertiesValueFormat) {
      void* val = (void*)IBG64CAST(iWorksheetPropertiesValueFormat);
      return InGoogle_GSpreadsheets_Set(m_pObj, 104, iWorksheetPropertiesIndex, val, 0);
    }
    inline char* GetWorksheetPropertiesXPath(int iWorksheetPropertiesIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 105, iWorksheetPropertiesIndex, 0);
      return (char*)val;
    }


    inline int GetWorksheetRowCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 106, 0, 0);
      return (int)(long)val;
    }
    inline int SetWorksheetRowCount(int iWorksheetRowCount) {
      void* val = (void*)IBG64CAST(iWorksheetRowCount);
      return InGoogle_GSpreadsheets_Set(m_pObj, 106, 0, val, 0);
    }
    inline char* GetWorksheetTitle() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 107, 0, 0);
      return (char*)val;
    }

    inline int SetWorksheetTitle(const char *lpWorksheetTitle) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 107, 0, (void*)lpWorksheetTitle, 0);
    }

    inline int GetAttrCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 108, 0, 0);
      return (int)(long)val;
    }

    inline char* GetAttrName(int iAttrIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 109, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrNamespace(int iAttrIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 110, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrPrefix(int iAttrIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 111, iAttrIndex, 0);
      return (char*)val;
    }


    inline char* GetAttrValue(int iAttrIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 112, iAttrIndex, 0);
      return (char*)val;
    }


    inline int GetXChildrenCount() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 113, 0, 0);
      return (int)(long)val;
    }

    inline char* GetXChildName(int iXChildIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 114, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildNamespace(int iXChildIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 115, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildPrefix(int iXChildIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 116, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXChildXText(int iXChildIndex) {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 117, iXChildIndex, 0);
      return (char*)val;
    }


    inline char* GetXElement() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 118, 0, 0);
      return (char*)val;
    }


    inline char* GetXNamespace() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 119, 0, 0);
      return (char*)val;
    }


    inline char* GetXParent() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 120, 0, 0);
      return (char*)val;
    }


    inline char* GetXPath() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 121, 0, 0);
      return (char*)val;
    }

    inline int SetXPath(const char *lpXPath) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 121, 0, (void*)lpXPath, 0);
    }

    inline char* GetXPrefix() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 122, 0, 0);
      return (char*)val;
    }


    inline char* GetXSubTree() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 123, 0, 0);
      return (char*)val;
    }


    inline char* GetXText() {
      void* val = InGoogle_GSpreadsheets_Get(m_pObj, 124, 0, 0);
      return (char*)val;
    }



  public: //methods

    inline int AddQueryParam(const char* lpszname, const char* lpszvalue) {
      void *param[2+1] = {(void*)IBG64CAST(lpszname), (void*)IBG64CAST(lpszvalue), 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 2, 2, param, cbparam);
      
      
    }
    inline char* Config(const char* lpszConfigurationString) {
      void *param[1+1] = {(void*)IBG64CAST(lpszConfigurationString), 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GSpreadsheets_Do(m_pObj, 3, 1, param, cbparam);
      
      return (char*)IBG64CAST(param[1]);
    }
    inline int CreateRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 4, 0, param, cbparam);
      
      
    }
    inline int CreateWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 5, 0, param, cbparam);
      
      
    }
    inline int DeleteRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 6, 0, param, cbparam);
      
      
    }
    inline int DeleteWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 7, 0, param, cbparam);
      
      
    }
    inline int QueryCells() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 8, 0, param, cbparam);
      
      
    }
    inline int QueryRows() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 9, 0, param, cbparam);
      
      
    }
    inline int QuerySpreadsheets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10, 0, param, cbparam);
      
      
    }
    inline int QueryWorksheets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 11, 0, param, cbparam);
      
      
    }
    inline int UpdateCell() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 12, 0, param, cbparam);
      
      
    }
    inline int UpdateRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 13, 0, param, cbparam);
      
      
    }
    inline int UpdateWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 14, 0, param, cbparam);
      
      
    }

};


#ifdef WIN32 //UNICODE

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR DateUpdated;
  int Row;
  int Column;
  LPWSTR InputValue;
  LPWSTR NumericValue;
  int reserved;
} GSpreadsheetsCellListEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GSpreadsheetsConnectedEventParamsW;

typedef struct {
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GSpreadsheetsDisconnectedEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GSpreadsheetsEndTransferEventParamsW;

typedef struct {
  int ErrorCode;
  LPWSTR Description;
  int reserved;
} GSpreadsheetsErrorEventParamsW;

typedef struct {
  LPWSTR Field;
  LPWSTR Value;
  int reserved;
} GSpreadsheetsHeaderEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR DateUpdated;
  LPWSTR RowDetails;
  int reserved;
} GSpreadsheetsRowListEventParamsW;

typedef struct {
  LPWSTR Name;
  LPWSTR Value;
  LPWSTR Expires;
  LPWSTR Domain;
  LPWSTR Path;
  int Secure;
  int reserved;
} GSpreadsheetsSetCookieEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR DateUpdated;
  LPWSTR Title;
  LPWSTR Author;
  int reserved;
} GSpreadsheetsSpreadsheetListEventParamsW;

typedef struct {
  LPWSTR CertEncoded;
  LPWSTR CertSubject;
  LPWSTR CertIssuer;
  LPWSTR Status;
  int Accept;
  int lenCertEncoded;
  int reserved;
} GSpreadsheetsSSLServerAuthenticationEventParamsW;

typedef struct {
  LPWSTR Message;
  int reserved;
} GSpreadsheetsSSLStatusEventParamsW;

typedef struct {
  int Direction;
  int reserved;
} GSpreadsheetsStartTransferEventParamsW;

typedef struct {
  LPWSTR HTTPVersion;
  int StatusCode;
  LPWSTR Description;
  int reserved;
} GSpreadsheetsStatusEventParamsW;

typedef struct {
  int Direction;
  ns_int64 *pBytesTransferred;
  int PercentDone;
  LPWSTR Text;
  int lenText;
  int reserved;
} GSpreadsheetsTransferEventParamsW;

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
} GSpreadsheetsUpdateACLResponseEventParamsW;

typedef struct {
  LPWSTR Id;
  LPWSTR ETag;
  LPWSTR DateUpdated;
  LPWSTR Title;
  int RowCount;
  int ColumnCount;
  int reserved;
} GSpreadsheetsWorksheetListEventParamsW;



class GSpreadsheetsW : public GSpreadsheets {

  public: //properties
  
    inline LPWSTR GetAuthorization() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+1, 0, 0);
    }

    inline int SetAuthorization(LPWSTR lpAuthorization) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+1, 0, (void*)lpAuthorization, 0);
    }



    inline LPWSTR GetCellDateUpdated() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+3, 0, 0);
    }

    inline int SetCellDateUpdated(LPWSTR lpCellDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+3, 0, (void*)lpCellDateUpdated, 0);
    }



    inline LPWSTR GetCellDetailInputValue() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+5, 0, 0);
    }

    inline int SetCellDetailInputValue(LPWSTR lpCellDetailInputValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+5, 0, (void*)lpCellDetailInputValue, 0);
    }

    inline LPWSTR GetCellDetailNumericValue() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+6, 0, 0);
    }





    inline LPWSTR GetCellETag() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+8, 0, 0);
    }

    inline int SetCellETag(LPWSTR lpCellETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+8, 0, (void*)lpCellETag, 0);
    }





    inline LPWSTR GetCellPropertiesAttributes(int iCellPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+11, iCellPropertiesIndex, 0);
    }

    inline int SetCellPropertiesAttributes(int iCellPropertiesIndex, LPWSTR lpCellPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+11, iCellPropertiesIndex, (void*)lpCellPropertiesAttributes, 0);
    }

    inline LPWSTR GetCellPropertiesName(int iCellPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+12, iCellPropertiesIndex, 0);
    }

    inline int SetCellPropertiesName(int iCellPropertiesIndex, LPWSTR lpCellPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+12, iCellPropertiesIndex, (void*)lpCellPropertiesName, 0);
    }

    inline LPWSTR GetCellPropertiesValue(int iCellPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+13, iCellPropertiesIndex, 0);
    }

    inline int SetCellPropertiesValue(int iCellPropertiesIndex, LPWSTR lpCellPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+13, iCellPropertiesIndex, (void*)lpCellPropertiesValue, 0);
    }



    inline LPWSTR GetCellPropertiesXPath(int iCellPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+15, iCellPropertiesIndex, 0);
    }





    inline LPWSTR GetCookieDomain(int iCookieIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+17, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieExpiration(int iCookieIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+18, iCookieIndex, 0);
    }



    inline LPWSTR GetCookieName(int iCookieIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+19, iCookieIndex, 0);
    }

    inline int SetCookieName(int iCookieIndex, LPWSTR lpCookieName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+19, iCookieIndex, (void*)lpCookieName, 0);
    }

    inline LPWSTR GetCookiePath(int iCookieIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+20, iCookieIndex, 0);
    }





    inline LPWSTR GetCookieValue(int iCookieIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+22, iCookieIndex, 0);
    }

    inline int SetCookieValue(int iCookieIndex, LPWSTR lpCookieValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+22, iCookieIndex, (void*)lpCookieValue, 0);
    }

    inline LPWSTR GetFeedAuthor() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+23, 0, 0);
    }



    inline LPWSTR GetFeedAuthorUri() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+24, 0, 0);
    }



    inline LPWSTR GetFeedCategoryLabel() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+25, 0, 0);
    }



    inline LPWSTR GetFeedCategoryScheme() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+26, 0, 0);
    }



    inline LPWSTR GetFeedCategoryTerm() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+27, 0, 0);
    }



    inline LPWSTR GetFeedEditURL() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+28, 0, 0);
    }



    inline LPWSTR GetFeedETag() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+29, 0, 0);
    }



    inline LPWSTR GetFeedGenerator() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+30, 0, 0);
    }



    inline LPWSTR GetFeedId() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+31, 0, 0);
    }



    inline LPWSTR GetFeedNextURL() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+32, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchItemsPerPage() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+33, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchStartIndex() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+34, 0, 0);
    }



    inline LPWSTR GetFeedOpenSearchTotalResults() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+35, 0, 0);
    }



    inline LPWSTR GetFeedPreviousURL() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+36, 0, 0);
    }



    inline LPWSTR GetFeedSelfURL() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+37, 0, 0);
    }



    inline LPWSTR GetFeedTitle() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+38, 0, 0);
    }



    inline LPWSTR GetFeedUpdated() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+39, 0, 0);
    }







    inline LPWSTR GetFirewallHost() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+42, 0, 0);
    }

    inline int SetFirewallHost(LPWSTR lpFirewallHost) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+42, 0, (void*)lpFirewallHost, 0);
    }

    inline LPWSTR GetFirewallPassword() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+43, 0, 0);
    }

    inline int SetFirewallPassword(LPWSTR lpFirewallPassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+43, 0, (void*)lpFirewallPassword, 0);
    }



    inline LPWSTR GetFirewallUser() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+45, 0, 0);
    }

    inline int SetFirewallUser(LPWSTR lpFirewallUser) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+45, 0, (void*)lpFirewallUser, 0);
    }



    inline LPWSTR GetLocalHost() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+47, 0, 0);
    }

    inline int SetLocalHost(LPWSTR lpLocalHost) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+47, 0, (void*)lpLocalHost, 0);
    }

    inline LPWSTR GetOtherHeaders() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+48, 0, 0);
    }

    inline int SetOtherHeaders(LPWSTR lpOtherHeaders) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+48, 0, (void*)lpOtherHeaders, 0);
    }



    inline LPWSTR GetParsedHeaderField(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+50, iParsedHeaderIndex, 0);
    }



    inline LPWSTR GetParsedHeaderValue(int iParsedHeaderIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+51, iParsedHeaderIndex, 0);
    }







    inline LPWSTR GetProxyPassword() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+54, 0, 0);
    }

    inline int SetProxyPassword(LPWSTR lpProxyPassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+54, 0, (void*)lpProxyPassword, 0);
    }



    inline LPWSTR GetProxyServer() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+56, 0, 0);
    }

    inline int SetProxyServer(LPWSTR lpProxyServer) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+56, 0, (void*)lpProxyServer, 0);
    }



    inline LPWSTR GetProxyUser() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+58, 0, 0);
    }

    inline int SetProxyUser(LPWSTR lpProxyUser) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+58, 0, (void*)lpProxyUser, 0);
    }



    inline LPWSTR GetQueryParamsName(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+60, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsName(int iQueryParamsIndex, LPWSTR lpQueryParamsName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+60, iQueryParamsIndex, (void*)lpQueryParamsName, 0);
    }

    inline LPWSTR GetQueryParamsValue(int iQueryParamsIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+61, iQueryParamsIndex, 0);
    }

    inline int SetQueryParamsValue(int iQueryParamsIndex, LPWSTR lpQueryParamsValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+61, iQueryParamsIndex, (void*)lpQueryParamsValue, 0);
    }



    inline LPWSTR GetRowDateUpdated() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+63, 0, 0);
    }

    inline int SetRowDateUpdated(LPWSTR lpRowDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+63, 0, (void*)lpRowDateUpdated, 0);
    }



    inline LPWSTR GetRowDetailHeader(int iRowDetailIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+65, iRowDetailIndex, 0);
    }

    inline int SetRowDetailHeader(int iRowDetailIndex, LPWSTR lpRowDetailHeader) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+65, iRowDetailIndex, (void*)lpRowDetailHeader, 0);
    }

    inline LPWSTR GetRowDetailValue(int iRowDetailIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+66, iRowDetailIndex, 0);
    }

    inline int SetRowDetailValue(int iRowDetailIndex, LPWSTR lpRowDetailValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+66, iRowDetailIndex, (void*)lpRowDetailValue, 0);
    }

    inline LPWSTR GetRowETag() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+67, 0, 0);
    }

    inline int SetRowETag(LPWSTR lpRowETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+67, 0, (void*)lpRowETag, 0);
    }





    inline LPWSTR GetRowPropertiesAttributes(int iRowPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+70, iRowPropertiesIndex, 0);
    }

    inline int SetRowPropertiesAttributes(int iRowPropertiesIndex, LPWSTR lpRowPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+70, iRowPropertiesIndex, (void*)lpRowPropertiesAttributes, 0);
    }

    inline LPWSTR GetRowPropertiesName(int iRowPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+71, iRowPropertiesIndex, 0);
    }

    inline int SetRowPropertiesName(int iRowPropertiesIndex, LPWSTR lpRowPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+71, iRowPropertiesIndex, (void*)lpRowPropertiesName, 0);
    }

    inline LPWSTR GetRowPropertiesValue(int iRowPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+72, iRowPropertiesIndex, 0);
    }

    inline int SetRowPropertiesValue(int iRowPropertiesIndex, LPWSTR lpRowPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+72, iRowPropertiesIndex, (void*)lpRowPropertiesValue, 0);
    }



    inline LPWSTR GetRowPropertiesXPath(int iRowPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+74, iRowPropertiesIndex, 0);
    }



    inline LPWSTR GetSpreadsheetAuthor() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+75, 0, 0);
    }

    inline int SetSpreadsheetAuthor(LPWSTR lpSpreadsheetAuthor) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+75, 0, (void*)lpSpreadsheetAuthor, 0);
    }



    inline LPWSTR GetSpreadsheetDateUpdated() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+77, 0, 0);
    }

    inline int SetSpreadsheetDateUpdated(LPWSTR lpSpreadsheetDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+77, 0, (void*)lpSpreadsheetDateUpdated, 0);
    }

    inline LPWSTR GetSpreadsheetETag() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+78, 0, 0);
    }

    inline int SetSpreadsheetETag(LPWSTR lpSpreadsheetETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+78, 0, (void*)lpSpreadsheetETag, 0);
    }





    inline LPWSTR GetSpreadsheetPropertiesAttributes(int iSpreadsheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+81, iSpreadsheetPropertiesIndex, 0);
    }

    inline int SetSpreadsheetPropertiesAttributes(int iSpreadsheetPropertiesIndex, LPWSTR lpSpreadsheetPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+81, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesAttributes, 0);
    }

    inline LPWSTR GetSpreadsheetPropertiesName(int iSpreadsheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+82, iSpreadsheetPropertiesIndex, 0);
    }

    inline int SetSpreadsheetPropertiesName(int iSpreadsheetPropertiesIndex, LPWSTR lpSpreadsheetPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+82, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesName, 0);
    }

    inline LPWSTR GetSpreadsheetPropertiesValue(int iSpreadsheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+83, iSpreadsheetPropertiesIndex, 0);
    }

    inline int SetSpreadsheetPropertiesValue(int iSpreadsheetPropertiesIndex, LPWSTR lpSpreadsheetPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+83, iSpreadsheetPropertiesIndex, (void*)lpSpreadsheetPropertiesValue, 0);
    }



    inline LPWSTR GetSpreadsheetPropertiesXPath(int iSpreadsheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+85, iSpreadsheetPropertiesIndex, 0);
    }



    inline LPWSTR GetSpreadsheetTitle() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+86, 0, 0);
    }

    inline int SetSpreadsheetTitle(LPWSTR lpSpreadsheetTitle) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+86, 0, (void*)lpSpreadsheetTitle, 0);
    }

    inline LPWSTR GetSSLAcceptServerCertEncoded() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+87, 0, 0);
    }

    inline int SetSSLAcceptServerCertEncoded(LPWSTR lpSSLAcceptServerCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+87, 0, (void*)lpSSLAcceptServerCertEncoded, 0);
    }
    inline int GetSSLAcceptServerCertEncodedB(char *&lpSSLAcceptServerCertEncoded, int &lenSSLAcceptServerCertEncoded) {
      lpSSLAcceptServerCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 87, 0, &lenSSLAcceptServerCertEncoded);
      return lpSSLAcceptServerCertEncoded ? 0 : lenSSLAcceptServerCertEncoded;
    }
    inline int SetSSLAcceptServerCertEncodedB(const char *lpSSLAcceptServerCertEncoded, int lenSSLAcceptServerCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 87, 0, (void*)lpSSLAcceptServerCertEncoded, lenSSLAcceptServerCertEncoded);
    }
    inline LPWSTR GetSSLCertEncoded() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+88, 0, 0);
    }

    inline int SetSSLCertEncoded(LPWSTR lpSSLCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+88, 0, (void*)lpSSLCertEncoded, 0);
    }
    inline int GetSSLCertEncodedB(char *&lpSSLCertEncoded, int &lenSSLCertEncoded) {
      lpSSLCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 88, 0, &lenSSLCertEncoded);
      return lpSSLCertEncoded ? 0 : lenSSLCertEncoded;
    }
    inline int SetSSLCertEncodedB(const char *lpSSLCertEncoded, int lenSSLCertEncoded) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 88, 0, (void*)lpSSLCertEncoded, lenSSLCertEncoded);
    }
    inline LPWSTR GetSSLCertStore() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+89, 0, 0);
    }

    inline int SetSSLCertStore(LPWSTR lpSSLCertStore) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+89, 0, (void*)lpSSLCertStore, 0);
    }
    inline int GetSSLCertStoreB(char *&lpSSLCertStore, int &lenSSLCertStore) {
      lpSSLCertStore = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 89, 0, &lenSSLCertStore);
      return lpSSLCertStore ? 0 : lenSSLCertStore;
    }
    inline int SetSSLCertStoreB(const char *lpSSLCertStore, int lenSSLCertStore) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 89, 0, (void*)lpSSLCertStore, lenSSLCertStore);
    }
    inline LPWSTR GetSSLCertStorePassword() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+90, 0, 0);
    }

    inline int SetSSLCertStorePassword(LPWSTR lpSSLCertStorePassword) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+90, 0, (void*)lpSSLCertStorePassword, 0);
    }



    inline LPWSTR GetSSLCertSubject() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+92, 0, 0);
    }

    inline int SetSSLCertSubject(LPWSTR lpSSLCertSubject) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+92, 0, (void*)lpSSLCertSubject, 0);
    }

    inline LPWSTR GetSSLServerCertEncoded() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+93, 0, 0);
    }


    inline int GetSSLServerCertEncodedB(char *&lpSSLServerCertEncoded, int &lenSSLServerCertEncoded) {
      lpSSLServerCertEncoded = (char*)InGoogle_GSpreadsheets_Get(m_pObj, 93, 0, &lenSSLServerCertEncoded);
      return lpSSLServerCertEncoded ? 0 : lenSSLServerCertEncoded;
    }







    inline LPWSTR GetWorksheetDateUpdated() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+97, 0, 0);
    }

    inline int SetWorksheetDateUpdated(LPWSTR lpWorksheetDateUpdated) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+97, 0, (void*)lpWorksheetDateUpdated, 0);
    }

    inline LPWSTR GetWorksheetETag() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+98, 0, 0);
    }

    inline int SetWorksheetETag(LPWSTR lpWorksheetETag) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+98, 0, (void*)lpWorksheetETag, 0);
    }





    inline LPWSTR GetWorksheetPropertiesAttributes(int iWorksheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+101, iWorksheetPropertiesIndex, 0);
    }

    inline int SetWorksheetPropertiesAttributes(int iWorksheetPropertiesIndex, LPWSTR lpWorksheetPropertiesAttributes) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+101, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesAttributes, 0);
    }

    inline LPWSTR GetWorksheetPropertiesName(int iWorksheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+102, iWorksheetPropertiesIndex, 0);
    }

    inline int SetWorksheetPropertiesName(int iWorksheetPropertiesIndex, LPWSTR lpWorksheetPropertiesName) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+102, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesName, 0);
    }

    inline LPWSTR GetWorksheetPropertiesValue(int iWorksheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+103, iWorksheetPropertiesIndex, 0);
    }

    inline int SetWorksheetPropertiesValue(int iWorksheetPropertiesIndex, LPWSTR lpWorksheetPropertiesValue) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+103, iWorksheetPropertiesIndex, (void*)lpWorksheetPropertiesValue, 0);
    }



    inline LPWSTR GetWorksheetPropertiesXPath(int iWorksheetPropertiesIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+105, iWorksheetPropertiesIndex, 0);
    }





    inline LPWSTR GetWorksheetTitle() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+107, 0, 0);
    }

    inline int SetWorksheetTitle(LPWSTR lpWorksheetTitle) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+107, 0, (void*)lpWorksheetTitle, 0);
    }



    inline LPWSTR GetAttrName(int iAttrIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+109, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrNamespace(int iAttrIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+110, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrPrefix(int iAttrIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+111, iAttrIndex, 0);
    }



    inline LPWSTR GetAttrValue(int iAttrIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+112, iAttrIndex, 0);
    }





    inline LPWSTR GetXChildName(int iXChildIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+114, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildNamespace(int iXChildIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+115, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildPrefix(int iXChildIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+116, iXChildIndex, 0);
    }



    inline LPWSTR GetXChildXText(int iXChildIndex) {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+117, iXChildIndex, 0);
    }



    inline LPWSTR GetXElement() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+118, 0, 0);
    }



    inline LPWSTR GetXNamespace() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+119, 0, 0);
    }



    inline LPWSTR GetXParent() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+120, 0, 0);
    }



    inline LPWSTR GetXPath() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+121, 0, 0);
    }

    inline int SetXPath(LPWSTR lpXPath) {
      return InGoogle_GSpreadsheets_Set(m_pObj, 10000+121, 0, (void*)lpXPath, 0);
    }

    inline LPWSTR GetXPrefix() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+122, 0, 0);
    }



    inline LPWSTR GetXSubTree() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+123, 0, 0);
    }



    inline LPWSTR GetXText() {
      return (LPWSTR)InGoogle_GSpreadsheets_Get(m_pObj, 10000+124, 0, 0);
    }





  public: //events
  
    virtual int FireCellList(GSpreadsheetsCellListEventParamsW *e) {return 0;}
    virtual int FireConnected(GSpreadsheetsConnectedEventParamsW *e) {return 0;}
    virtual int FireDisconnected(GSpreadsheetsDisconnectedEventParamsW *e) {return 0;}
    virtual int FireEndTransfer(GSpreadsheetsEndTransferEventParamsW *e) {return 0;}
    virtual int FireError(GSpreadsheetsErrorEventParamsW *e) {return 0;}
    virtual int FireHeader(GSpreadsheetsHeaderEventParamsW *e) {return 0;}
    virtual int FireRowList(GSpreadsheetsRowListEventParamsW *e) {return 0;}
    virtual int FireSetCookie(GSpreadsheetsSetCookieEventParamsW *e) {return 0;}
    virtual int FireSpreadsheetList(GSpreadsheetsSpreadsheetListEventParamsW *e) {return 0;}
    virtual int FireSSLServerAuthentication(GSpreadsheetsSSLServerAuthenticationEventParamsW *e) {return 0;}
    virtual int FireSSLStatus(GSpreadsheetsSSLStatusEventParamsW *e) {return 0;}
    virtual int FireStartTransfer(GSpreadsheetsStartTransferEventParamsW *e) {return 0;}
    virtual int FireStatus(GSpreadsheetsStatusEventParamsW *e) {return 0;}
    virtual int FireTransfer(GSpreadsheetsTransferEventParamsW *e) {return 0;}
    virtual int FireUpdateACLResponse(GSpreadsheetsUpdateACLResponseEventParamsW *e) {return 0;}
    virtual int FireWorksheetList(GSpreadsheetsWorksheetListEventParamsW *e) {return 0;}


  protected:
  
    virtual int GSpreadsheetsEventSinkW(int event_id, int cparam, void *param[], int cbparam[]) {
    	int ret_code = 0;
      switch (event_id) {
         case 1: {
            GSpreadsheetsCellListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (LPWSTR)IBG64CAST(param[6]),  0};
            ret_code = FireCellList(&e);
            break;
         }
         case 2: {
            GSpreadsheetsConnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireConnected(&e);
            break;
         }
         case 3: {
            GSpreadsheetsDisconnectedEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireDisconnected(&e);
            break;
         }
         case 4: {
            GSpreadsheetsEndTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireEndTransfer(&e);
            break;
         }
         case 5: {
            GSpreadsheetsErrorEventParamsW e = {(int)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireError(&e);
            break;
         }
         case 6: {
            GSpreadsheetsHeaderEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]),  0};
            ret_code = FireHeader(&e);
            break;
         }
         case 7: {
            GSpreadsheetsRowListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]),  0};
            ret_code = FireRowList(&e);
            break;
         }
         case 8: {
            GSpreadsheetsSetCookieEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireSetCookie(&e);
            break;
         }
         case 9: {
            GSpreadsheetsSpreadsheetListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]),  0};
            ret_code = FireSpreadsheetList(&e);
            break;
         }
         case 10: {
            GSpreadsheetsSSLServerAuthenticationEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(cbparam[0]),  0};
            ret_code = FireSSLServerAuthentication(&e);
            param[4] = (void*)(e.Accept);
            break;
         }
         case 11: {
            GSpreadsheetsSSLStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]),  0};
            ret_code = FireSSLStatus(&e);
            break;
         }
         case 12: {
            GSpreadsheetsStartTransferEventParamsW e = {(int)IBG64CAST(param[0]),  0};
            ret_code = FireStartTransfer(&e);
            break;
         }
         case 13: {
            GSpreadsheetsStatusEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]),  0};
            ret_code = FireStatus(&e);
            break;
         }
         case 14: {
            GSpreadsheetsTransferEventParamsW e = {(int)IBG64CAST(param[0]), (ns_int64*)IBG64CAST(param[1]), (int)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(cbparam[3]),  0};
            ret_code = FireTransfer(&e);
            break;
         }
         case 15: {
            GSpreadsheetsUpdateACLResponseEventParamsW e = {(int)IBG64CAST(param[0]), (int)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (int)IBG64CAST(param[3]), (LPWSTR)IBG64CAST(param[4]), (LPWSTR)IBG64CAST(param[5]), (int)IBG64CAST(param[6]), (LPWSTR)IBG64CAST(param[7]), (LPWSTR)IBG64CAST(param[8]),  0};
            ret_code = FireUpdateACLResponse(&e);
            break;
         }
         case 16: {
            GSpreadsheetsWorksheetListEventParamsW e = {(LPWSTR)IBG64CAST(param[0]), (LPWSTR)IBG64CAST(param[1]), (LPWSTR)IBG64CAST(param[2]), (LPWSTR)IBG64CAST(param[3]), (int)IBG64CAST(param[4]), (int)IBG64CAST(param[5]),  0};
            ret_code = FireWorksheetList(&e);
            break;
         }

      }
      return ret_code;
    }
  
  public: //event overrides

    virtual int FireCellList(GSpreadsheetsCellListEventParams *e) {return -10000;}
    virtual int FireConnected(GSpreadsheetsConnectedEventParams *e) {return -10000;}
    virtual int FireDisconnected(GSpreadsheetsDisconnectedEventParams *e) {return -10000;}
    virtual int FireEndTransfer(GSpreadsheetsEndTransferEventParams *e) {return -10000;}
    virtual int FireError(GSpreadsheetsErrorEventParams *e) {return -10000;}
    virtual int FireHeader(GSpreadsheetsHeaderEventParams *e) {return -10000;}
    virtual int FireRowList(GSpreadsheetsRowListEventParams *e) {return -10000;}
    virtual int FireSetCookie(GSpreadsheetsSetCookieEventParams *e) {return -10000;}
    virtual int FireSpreadsheetList(GSpreadsheetsSpreadsheetListEventParams *e) {return -10000;}
    virtual int FireSSLServerAuthentication(GSpreadsheetsSSLServerAuthenticationEventParams *e) {return -10000;}
    virtual int FireSSLStatus(GSpreadsheetsSSLStatusEventParams *e) {return -10000;}
    virtual int FireStartTransfer(GSpreadsheetsStartTransferEventParams *e) {return -10000;}
    virtual int FireStatus(GSpreadsheetsStatusEventParams *e) {return -10000;}
    virtual int FireTransfer(GSpreadsheetsTransferEventParams *e) {return -10000;}
    virtual int FireUpdateACLResponse(GSpreadsheetsUpdateACLResponseEventParams *e) {return -10000;}
    virtual int FireWorksheetList(GSpreadsheetsWorksheetListEventParams *e) {return -10000;}

  public: //methods

    inline int AddQueryParam(LPWSTR lpszname, LPWSTR lpszvalue) {
      void *param[2+1] = {(void*)lpszname, (void*)lpszvalue, 0};
      int cbparam[2+1] = {0, 0, 0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+2, 2, param, cbparam);
      
    }
    inline LPWSTR Config(LPWSTR lpszConfigurationString) {
      void *param[1+1] = {(void*)lpszConfigurationString, 0};
      int cbparam[1+1] = {0, 0};
      InGoogle_GSpreadsheets_Do(m_pObj, 10000+3, 1, param, cbparam);
      return (LPWSTR)IBG64CAST(param[1]);
    }
    inline int CreateRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+4, 0, param, cbparam);
      
    }
    inline int CreateWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+5, 0, param, cbparam);
      
    }
    inline int DeleteRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+6, 0, param, cbparam);
      
    }
    inline int DeleteWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+7, 0, param, cbparam);
      
    }
    inline int QueryCells() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+8, 0, param, cbparam);
      
    }
    inline int QueryRows() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+9, 0, param, cbparam);
      
    }
    inline int QuerySpreadsheets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+10, 0, param, cbparam);
      
    }
    inline int QueryWorksheets() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+11, 0, param, cbparam);
      
    }
    inline int UpdateCell() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+12, 0, param, cbparam);
      
    }
    inline int UpdateRow() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+13, 0, param, cbparam);
      
    }
    inline int UpdateWorksheet() {
      void *param[0+1] = {0};
      int cbparam[0+1] = {0};
      return InGoogle_GSpreadsheets_Do(m_pObj, 10000+14, 0, param, cbparam);
      
    }

};

#endif //WIN32

#endif //_INGOOGLE_GSPREADSHEETS_H_




