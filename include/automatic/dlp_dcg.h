// dLabPro programm dcg (dLabPro code generator)
// - Header file
//
// AUTHOR : Matthias Wolff
// PACKAGE: dLabPro/programs
// 
// Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
// - Chair of System Theory and Speech Technology, TU Dresden
// - Chair of Communications Engineering, BTU Cottbus
// 
// This file is part of dLabPro.
// 
// dLabPro is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
// 
// dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with dLabPro. If not, see <http://www.gnu.org/licenses/>.


//{{CGEN_INCLUDE
#include "dlp_dgen.h"
#include "dlp_itp.h"
#include "dlp_clist.h"
//}}CGEN_END

//{{CGEN_ERRORS
#undef ERR_EXPECTAFTER     
#undef ERR_EXPECTIDAFTER   
#undef ERR_DDEF_LIST       
#undef ERR_CANNOTCREATE    
#undef ERR_INVALMETHOD     
#undef ERR_INVALKEY        
#undef ERR_INVALSUBKEY     
#undef ERR_EXPGLOBALKEY    
#undef ERR_EXPPROJECT      
#undef ERR_MANTEXT         
#undef ERR_EXPECTENDCODE   
#undef ERR_TOOMANYPARS     
#undef ERR_UNKNOWNTYPE     
#undef ERR_CREATEFILE      
#undef ERR_OPENFILE        
#undef ERR_MISSCOMMENT     
#undef ERR_MISSTYPE        
#undef ERR_MISSINIT        
#undef ERR_MISSSYNTAX      
#undef ERR_BADSYNTAX       
#undef ERR_BADRETTYPE      
#undef ERR_MISSNOTE        
#undef ERR_DATAUNDEFDW     
#undef ERR_DATAUNDEFD      
#undef ERR_VERIFYDATA      
#undef ERR_NOPLATFORM      
#undef ERR_NOMSVCFOUND     
#undef ERR_WRONGMSVCVERSION
#undef ERR_FILETYPE        
#undef ERR_POINTERINIT     
#undef ERR_UNKNOWNARGTYPE  
#undef ERR_THIS            
#undef ERR_OBSOLETE        
#undef ERR_OBSOLETE2       
#undef ERR_INFUNCTION      
#undef ERR_INFUNCTION2     
#undef ERR_INLINE          
#undef ERR_PARSEERR        
#undef ERR_PARSEERR2       
#undef ERR_PARSEERR_ARG    
#undef ERR_ELLIPSIS        
#undef ERR_CPROJECT        
#undef ERR_BADIDENTIFIER   
#undef ERR_INVALARRLEN     
#undef ERR_MULTIARRAY      
#undef ERR_EXPECT          
#undef ERR_TOOLEXEC        
#undef ERR_OBSOL_ATALL     
#undef ERR_BADIDCHAR       
#undef ERR_BADLEAD         
#undef ERR_APPEND          
#undef ERR_NOBASECALL      
#undef ERR_BADOPTION       
#undef ERR_UNEXPECTEDEOF   
#undef ERR_EXTRA_HTML      
#undef ERR_TOOLONG         
#undef ERR_UNKNOWN         
#undef ERR_RESJDLINK       
#define ERR_EXPECTAFTER      -1001
#define ERR_EXPECTIDAFTER    -1002
#define ERR_DDEF_LIST        -1003
#define ERR_CANNOTCREATE     -1004
#define ERR_INVALMETHOD      -1005
#define ERR_INVALKEY         -1006
#define ERR_INVALSUBKEY      -1007
#define ERR_EXPGLOBALKEY     -1008
#define ERR_EXPPROJECT       -1009
#define ERR_MANTEXT          -1010
#define ERR_EXPECTENDCODE    -1011
#define ERR_TOOMANYPARS      -1012
#define ERR_UNKNOWNTYPE      -1013
#define ERR_CREATEFILE       -1014
#define ERR_OPENFILE         -1015
#define ERR_MISSCOMMENT      -1016
#define ERR_MISSTYPE         -1017
#define ERR_MISSINIT         -1018
#define ERR_MISSSYNTAX       -1019
#define ERR_BADSYNTAX        -1020
#define ERR_BADRETTYPE       -1021
#define ERR_MISSNOTE         -1022
#define ERR_DATAUNDEFDW      -1023
#define ERR_DATAUNDEFD       -1024
#define ERR_VERIFYDATA       -1025
#define ERR_NOPLATFORM       -1026
#define ERR_NOMSVCFOUND      -1027
#define ERR_WRONGMSVCVERSION -1028
#define ERR_FILETYPE         -1029
#define ERR_POINTERINIT      -1030
#define ERR_UNKNOWNARGTYPE   -1031
#define ERR_THIS             -1032
#define ERR_OBSOLETE         -1033
#define ERR_OBSOLETE2        -1034
#define ERR_INFUNCTION       -1035
#define ERR_INFUNCTION2      -1036
#define ERR_INLINE           -1037
#define ERR_PARSEERR         -1038
#define ERR_PARSEERR2        -1039
#define ERR_PARSEERR_ARG     -1040
#define ERR_ELLIPSIS         -1041
#define ERR_CPROJECT         -1042
#define ERR_BADIDENTIFIER    -1043
#define ERR_INVALARRLEN      -1044
#define ERR_MULTIARRAY       -1045
#define ERR_EXPECT           -1046
#define ERR_TOOLEXEC         -1047
#define ERR_OBSOL_ATALL      -1048
#define ERR_BADIDCHAR        -1049
#define ERR_BADLEAD          -1050
#define ERR_APPEND           -1051
#define ERR_NOBASECALL       -1052
#define ERR_BADOPTION        -1053
#define ERR_UNEXPECTEDEOF    -1054
#define ERR_EXTRA_HTML       -1055
#define ERR_TOOLONG          -1056
#define ERR_UNKNOWN          -1057
#define ERR_RESJDLINK        -1058
//}}CGEN_END

// C/C++ language abstraction layer
#undef dcg_par
#define dcg_par CCgen

// dLabPro/C++ language abstraction layer
#undef CGen
#define CGen CCgen

//{{CGEN_DEFINE
#define S_PROT "__PROT"
#define S_CGENPUB "CGEN_PUBLIC"
#define S_CGENVPUB "CGEN_VPUBLIC"
#define S_CGENVPPUB "CGEN_VPPUBLIC"
#define S_CGENSPUB "CGEN_SPUBLIC"
#define S_CGENPROT "CGEN_PROTECTED"
#define S_CGENVPROT "CGEN_VPROTECTED"
#define S_CGENVPPROT "CGEN_VPPROTECTED"
#define S_CGENSPROT "CGEN_SPROTECTED"
#define S_CGENPRIV "CGEN_PRIVATE"
#define S_CGENSPRIV "CGEN_SPRIVATE"
#define S_CGENEXPORT "CGEN_EXPORT"
#define S_CGENIGNORE "CGEN_IGNORE"
#define S_DEFAULT "DEFAULT("
#define ERR_FIRST -1000
#define PF_GNUCXX 0x0001
#define PF_MSDEV4 0x0002
#define PF_MSDEV5 0x0003
#define PF_MSDEV6 0x0004
#define MAK_NOHFILE 0x0001
#define MAK_NOCPPFILE 0x0002
#define MAK_NOMAKFILE 0x0004
#define MAK_NOMANFILE 0x0008
#define MAK_NOHTMLMAN 0x0010
#define MAK_IFNOTEX 0x0020
#define NMS_RELEASE 0x0001
#define NMS_DEBUG 0x0002
#define FT_H 0x0001
#define FT_CPP 0x0002
#define FT_C 0x0003
#define CR_NOTHING 0
#define CR_PROJECT 1
#define CR_ERROR 2
#define CR_FIELD 3
#define CR_METHOD 4
#define CR_OPTION 5
#define CR_NOTE 6
#define CR_ICLS 7
#define CR_IGNORE 8
#define CR_CFUNC 9
#define AF_INOUT 0
#define AF_IN 1
#define AF_OUT 2
#define CSIG_CXXMEMBER 1
#define CSIG_CMEMBER 2
#define CSIG_FUNCTION 3
#define CSIG_CXXWRAPPER_HEAD 4
#define CSIG_CXXWRAPPER_CALL 5
#define FORBIDFLAG(A,B,C,D,E) if ((A&C) != (B&C)) ERRORMSG(ERR_INVALSUBKEY,D,E,0);
#define EXIT(A,B,C,D) {ERRORMSG(A,B,C,D); CDlpObject::ErrorLog(); exit(A);}
#define CGEN_LOGO "//\n// sigmaLab(R) Code Generator for dLabPro\n"
//}}CGEN_DEFINE

#ifndef __DCG_H
#define __DCG_H

//{{CGEN_HEADERCODE
    #define CGEN_WORDS(A,B,C,D,E) { C*      lpItem;                             \
                                    SCGStr* lpTmpl=A.m_items;                   \
                                    while(lpTmpl)                               \
                                    {                                           \
                                      if(strstr(lpTmpl->lpName,B))              \
                                      {                                         \
                                        lpItem=D.m_items;                       \
                                        while(lpItem)                           \
                                        {                                       \
                                          if (!lpItem->bInherited)              \
                                            E(lpItem,lpTmpl,lpItem==D.m_items); \
                                          lpItem=lpItem->next;                  \
                                        }                                       \
                                      }                                         \
                                      lpTmpl=lpTmpl->next;                      \
                                   } }
    #define CGEN_CODE(A,B,C)       { char _lpBuf[2048];                        \
                                     SCGStr *lpStr = C.m_items;                \
                                     while(lpStr)                              \
                                     {                                         \
                                       if (dlp_strlen(lpStr->lpName))          \
                                         sprintf(_lpBuf,"  %s",lpStr->lpName); \
                                       else                                    \
                                         strcpy(_lpBuf,"");                    \
                                       KillDollars(_lpBuf);                    \
                                       A.InsertItem(B,_lpBuf); B = B->next;    \
                                       lpStr = lpStr->next;                    \
                                   } }
    #define BEGIN_FLAGS(A)        { char* _lpFlags = A; strcpy(_lpFlags,"");
    #define END_FLAGS             if (!dlp_strlen(_lpFlags)) strcpy(_lpFlags,"0"); }
    #define APPEND_FLAG(A,B)      if (A&B)                                            \
                                  {                                                   \
                                    if (dlp_strlen(_lpFlags)) strcat(_lpFlags," | "); \
                                    strcat(_lpFlags,""#B"");                          \
                                  }
    typedef struct tagSCGStr
    {
      char       lpName[L_INPUTLINE];
      INT16      nId;
      tagSCGStr* next;
    } SCGStr;
    typedef struct tagSCGErr
    {
      char          lpName[100];
      INT16         nId;
      char          lpComment[255];
      char          lpErrorLevel[50];
      INT16         bInherited;
      char          lpFile[L_PATH];
      INT64          nLine;
      INT16         bHtmlMan;
      CList<SCGStr> lMan;
      CList<SCGStr> lCman;
      tagSCGErr*    next;
    } SCGErr;
    typedef struct tagSCGFile
    {
      char        lpName[255];
      INT16       nId;
      INT16       nFType;
      tagSCGFile* next;
    } SCGFile;
    typedef struct tagSCGSyn
    {
      char       lpName[100];
      INT16      nId;
      INT16      nArgFlags;
      char       lpType[100];
      char       lpMdfr[100];
      char       lpSupply[255];
      char       lpDefaultVal[100];
      tagSCGSyn* next;
    } SCGSyn;
    typedef struct tagSCGFld
    {
      char          lpName[100];
      char          lpObsolete[100];
      INT16         nId;
      char          lpCName[100];
      char          lpComment[255];
      INT16         nType;              // SLC type code
      char          lpCType[100];       // C/C++ type identifier
      char          lpType[100];        // C/C++ pointer type ID or SLC RTTI name
      INT64          nArrayLen;          // Length of simple variable array (std: 1)
      char          lpArraySpec[100];   // C/C++ array tag ([nn][nn]...)
      INT64          nFlags;
      INT16         bInherited;
      char          lpInit[100];
      char          lpFile[L_PATH];
      INT64          nLine;
      INT16         bHtmlMan;
      CList<SCGStr> lMan;
      CList<SCGStr> lCman;
      CList<SCGStr> lCode;
      tagSCGFld*    next;
    } SCGFld;
    typedef struct tagSCGOpt
    {
      char          lpName[100];
      char          lpObsolete[100];
      INT16         nId;
      char          lpCName[100];
    char          lpComment[255];
      INT64          nFlags;
      INT16         bInherited;
      char          lpFile[L_PATH];
      INT64          nLine;
      INT16         bHtmlMan;
      CList<SCGStr> lMan;
      CList<SCGStr> lCman;
      CList<SCGStr> lCode;
      tagSCGOpt*    next;
    } SCGOpt;
    typedef struct tagSCGMth
    {
      char          lpName[100];
      char          lpObsolete[100];
      INT16         nId;
      char          lpCName[100];
      char          lpComment[255];
      char          lpUPNSyntax[255];
      char          lpCSyntax[255];
      char          lpPostsyn[100];
      char          lpFile[L_PATH];
      INT64          nFlags;
      INT16         bInherited;
      INT16         bOverwritten;
      INT64          nLine;
      INT16         bHtmlMan;
      CList<SCGStr> lMan;
      CList<SCGStr> lCman;
      CList<SCGStr> lCode;
      CList<SCGStr> lPCode;
      CList<SCGSyn> lSyntax;
      SCGSyn        lpReturn;
      tagSCGMth*    next;
    } SCGMth;
    typedef struct tagSCGRnt
    {
      char          lpName[100];
      INT16         nId;
      char          lpComment[255];
      INT16         bInherited;
      char          lpFile[L_PATH];
      INT64          nLine;
      INT16         bHtmlMan;
      CList<SCGStr> lMan;
      CList<SCGStr> lCman;
      tagSCGRnt*    next;
    } SCGRnt;
    typedef struct tagSCGIcl
    {
      char       lpName[100];
      INT16      nId;
      char       lpFile[L_PATH];
      INT64       nLine;
      char       lpMPath[L_PATH];
      char       lpIPath[L_PATH];
      char       lpLPath[L_PATH];
      char       lpMFile[100];
      char       lpHFile[100];
      char       lpLFile[100];
      tagSCGIcl* next;
    } SCGIcl;
//}}CGEN_HEADERCODE

// Class CCgen

class CCgen : public CDlpObject 
{

typedef CDlpObject inherited;
typedef CCgen thisclass;

//{{CGEN_FRIENDS
//}}CGEN_FRIENDS
public:
	CCgen(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CCgen();

// Virtual and static function overrides
public:
	virtual INT16 AutoRegisterWords();
	virtual INT16 Init(BOOL bCallVirtual = 0);
	virtual INT16 Reset(BOOL bResetMembers = 1);
	virtual INT16 Serialize(CDN3Stream* lpDest);
	virtual INT16 SerializeXml(CXmlStream* lpDest);
	virtual INT16 Deserialize(CDN3Stream* lpSrc);
	virtual INT16 DeserializeXml(CXmlStream* lpSrc);
	virtual INT16 Copy(CDlpObject* iSrc);
	virtual INT16 ClassProc();
	static  INT16 InstallProc(void* lpItp);
	static  CCgen* CreateInstance(const char* lpName);
	static  INT16 GetClassInfo(SWord* lpClassWord);
	virtual INT16 GetInstanceInfo(SWord* lpClassWord);
	virtual BOOL  IsKindOf(const char* lpClassName);
	virtual INT16 ResetAllOptions(BOOL bInit = 0);

// Primary method invocation functions            
// DO NOT CALL THESE FUNCTIONS FROM C SCOPE.      
// THEY MAY INTERFERE WITH THE INTERPRETER SESSION
#ifndef __NOITP
public:
//{{CGEN_PMIC
//}}CGEN_PMIC
#endif // #ifndef __NOITP

// Secondary method invocation functions
public:
//{{CGEN_SMIC
	INT16 Listdef();
//}}CGEN_SMIC

// Option changed callback functions
public:
//{{CGEN_OCCF
//}}CGEN_OCCF

// Field changed callback functions
public:
//{{CGEN_FCCF
//}}CGEN_FCCF

// Scanned member functions
//{{CGEN_EXPORT

// Taken from 'dcg_cft.cpp'
	protected: void CreateDSPReleaseConfig(const char* lpCode);
	protected: void CreateDSPDebugConfig(const char* lpCode);
	protected: void CreateDSPTemplate();
	protected: void CreateDSWTemplate();
	protected: void CreateNMakeReleaseConfig(const char* lpCode);
	protected: void CreateNMakeDebugConfig(const char* lpCode);
	protected: INT16 CreateNMakeTemplate();
	protected: void CreateMakefileTemplate();
	protected: void CreateHTemplate();
	protected: void CreateCPPTemplate();
	protected: void CreateTemplates();

// Taken from 'dcg_cmd.cpp'
	protected: INT16 OnMain();
	protected: INT16 OnProject();
	protected: INT16 OnClass();
	protected: INT16 OnAutoinstance();
	protected: INT16 OnParent();
	protected: INT16 OnAuthor();
	protected: INT16 OnVersion();
	protected: INT16 OnPlatform();
	protected: INT16 OnCompiler();
	protected: INT16 OnAr();
	protected: INT16 OnGccFlags();
	protected: INT16 OnMsvcFlags();
	protected: INT16 OnLfile();
	protected: INT16 OnHfile();
	protected: INT16 OnFile();
	protected: INT16 OnInclude();
	protected: INT16 OnPinclude();
	protected: INT16 OnDefine();
	protected: INT16 OnFriend();
	protected: INT16 OnMpath();
	protected: INT16 OnIpath();
	protected: INT16 OnOpath();
	protected: INT16 OnLpath();
	protected: INT16 OnHeadercode();
	protected: INT16 OnInitcode();
	protected: INT16 OnDonecode();
	protected: INT16 OnResetcode();
	protected: INT16 OnSavecode();
	protected: INT16 OnRestorecode();
	protected: INT16 OnCopycode();
	protected: INT16 OnClasscode();
	protected: INT16 OnInstallcode();
	protected: INT16 OnError();
	protected: INT16 OnField();
	protected: INT16 OnOption();
	protected: INT16 OnMethod();
	protected: INT16 OnNote();
	protected: INT16 OnInstallClass();
	protected: INT16 OnObsolete();
	protected: INT16 OnComment();
	protected: INT16 OnCname();
	protected: INT16 OnCstructname();
	protected: INT16 OnType();
	protected: INT16 OnInit();
	protected: INT16 OnSyntax();
	protected: INT16 OnPostsyn();
	protected: INT16 OnLevel();
	protected: INT16 OnFlags();
	protected: INT16 OnCode();
	protected: INT16 OnMan();
	protected: INT16 Cgen();
	protected: INT16 OnHomedir();
	protected: INT16 LoadAncestor();
	protected: INT16 Quit();
	protected: INT16 Template();
	protected: INT16 Listwords();

// Taken from 'dcg_cpp.cpp'
	protected: void CppMakeDeclarator(INT16 nType, const char* lpsDspc, const char* lpsName, const char* lpsSnam, const char* lpsMdfr, const char* lpsPvrt, CData* idDom, INT64 nFdobA, char* lpsDst, INT16 nLen);
	protected: INT16 CppFhead(CDgen* iDG, INT64 nFdobF);
	protected: INT16 CppScanFunctions();
	protected: void GC_ErrUndef(SCGErr* lpErr, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_ErrDef(SCGErr* lpErr, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_ErrReg(SCGErr* lpErr, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_FldMemDec(SCGFld* lpFld, SCGStr*& lpTmpl, BOOL bFirst);
	protected: void GC_ICFldMemDec(SCGFld* lpFld, SCGStr*& lpTmpl, BOOL bFirst);
	protected: void GC_ICxxFldMemDec(SCGFld* lpFld, SCGStr*& lpTmpl, BOOL bFirst);
	protected: void __GC_FldMemDec(SCGFld* lpFld, SCGStr*& lpTmpl, BOOL bFirst, BOOL bForC);
	protected: void GC_FldFcfDec(SCGFld* lpFld, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CFldFcfDec(SCGFld* lpFld, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_FldReg(SCGFld* lpFld, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_FldFcfDef(SCGFld* lpFld, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CFldFcfDef(SCGFld* lpFld, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_OptMemDec(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_OptOcfDec(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_COptOcfDec(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_OptReg(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_OptOcfDef(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_COptOcfDef(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_OptReset(SCGOpt* lpOpt, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_MthPmiDec(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CMthPmiDec(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_MthSmiDec(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CMthSmiDec(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_MthReg(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_MthPmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CMthPmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void __GC_MthPmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst, BOOL bWrapper);
	protected: void GC_MthSmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void GC_CMthSmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst);
	protected: void __GC_MthSmiDef(SCGMth* lpMth, SCGStr*& lpTmpl, INT16 bFirst, BOOL bWrapper);
	protected: INT16 KillDollars(char* lpText);
	protected: INT16 RealizeCode(CList<SCGStr> &lTmpl, const char* lpKey, CList<SCGStr> &lCode);
	protected: INT16 CreateSourceFiles();

// Taken from 'dcg_htm.cpp'
	protected: INT16 ScanHtmlManual();
	protected: INT16 CreateHtmlManual();
	protected: void HtmlMemberOverview(CList<SCGStr>& htmFileTmpl, INT16 nMemberType);
	protected: void HtmlAllMembers(CList<SCGStr>& htmFileTmpl, INT16 nMemberType);
	protected: void HtmlMember(CList<SCGStr>& htmFileTmpl, void* lpSCGMember, INT16 nMemberType);
	protected: char* HtmlStrCnvt(char* lpDest, char* lpSrc);
	protected: char* HtmlGetDivId(char* lpStr, void* lpSCGMember, INT16 nMemberType);
	protected: char* HtmlGetUpnSignature(char* lpStr, void* lpSCGMember, INT16 nMemberType);
	protected: char* HtmlGetCSignature(char* lpStr, void* lpSCGMember, INT16 nMemberType);

// Taken from 'dcg_mak.cpp'
	protected: INT16 CreateMakeFile(INT16 bIfnotex);
	protected: INT16 RealizeObjectList(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeCDeps(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeDependencies(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeCompiles(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeDspCompiles(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeDspLibraries(CList<SCGStr> &tmpl, CList<SCGIcl> &icls);
	protected: INT16 RealizeCleanupList(CList<SCGStr> &tmpl, CList<SCGFile> &files);
	protected: INT16 RealizeLinks(CList<SCGStr> &tmpl, CList<SCGIcl> &icls);

// Taken from 'dcg_sid.cpp'
	protected: INT16 CreateSearchIndex();

// Taken from 'dcg_jvd.cpp'
	protected: void JdSee(CList<SCGStr>* lHtml);
	protected: void JdIndex(CList<SCGStr>* lHtml);
	protected: INT16 JavaDoc2Html(CList<SCGStr>* lHtml, char* lpsShortDescr, CList<SCGStr>* lJavaDoc, const char* lpsFilename, INT64 nLine);

// Taken from 'dcg_tpl.cpp'
	protected: INT16 QueryMSVCVersion(char* lpMSDPath);
	protected: INT16 CompleteProject();
	protected: INT16 CheckSysFunction(CList<SCGStr>& lCode, const char* lpKey1, const char* lpKey2);
	protected: INT16 CompleteSysFunctions();
	protected: INT16 CompleteError(SCGErr* lpErr);
	protected: INT16 CompleteField(SCGFld* lpFld);
	protected: INT16 CompleteOption(SCGOpt* lpOpt);
	protected: INT16 CompleteMethod(SCGMth* lpMth);
	protected: INT16 CompleteNote(SCGRnt* lpRnt);
	protected: INT16 CompleteIcls(SCGIcl* lpIcl);
	protected: INT16 SetCreating(INT16 nWhat, void* lpItem);
	protected: INT16 ReplaceAllKeys(CList<SCGStr> &tmpl);
	protected: INT16 ReplaceAllKeys2(CList<SCGStr> &tmpl);
	protected: INT16 RealizeStrList(CList<SCGStr> &tmpl, CList<SCGStr> &str, const char* lpKey, const char* lpPrefix, const char* lpSuffix);
	protected: INT16 WriteBackTemplate(CList<SCGStr> &tmpl, char* lpPath, char* lpFName, INT16 bPrint = 1);
	protected: INT16 AnalyzeSyntax(char* lpName, CList<SCGSyn>& lSyntax, char* lpSyntax, SCGSyn* lpReturn, char* lpSDescr, char* lpCDescr);
	protected: INT16 ReplaceKey(char* lpText, const char* lpKey, const char* lpReplace, INT16 nCnvt);
	protected: INT16 FillInCode(CList<SCGStr> &lList);
	protected: INT16 FillInManualText(CList<SCGStr> &lList);
//}}CGEN_EXPORT

// Member variables
public:

//{{CGEN_FIELDS
	INT16            m_nAncestor;
	char             m_lpsAuthor[100];
	char             m_lpsAutoname[100];
	char             m_lpsBPath[255];
	CList<SCGStr>    m_bsiFileTmpl;
	char             m_lpsCName[100];
	char             m_lpsCStructName[100];
	CList<SCGStr>    m_Cexports;
	CList<SCGMth>    m_cfns;
	CList<SCGStr>    m_clSiteMap;
	CList<SCGStr>    m_clToc;
	char             m_lpsClass[100];
	CList<SCGStr>    m_classCode;
	CList<SCGStr>    m_cmanual;
	char             m_lpsComment[255];
	CList<SCGStr>    m_copyCode;
	CList<SCGStr>    m_cppFileTmpl;
	INT16            m_nCreating;
	SCGErr*          m_lpCreatingErr;
	SCGFld*          m_lpCreatingFld;
	SCGIcl*          m_lpCreatingIcl;
	SCGMth*          m_lpCreatingMth;
	SCGOpt*          m_lpCreatingOpt;
	SCGRnt*          m_lpCreatingRnt;
	INT64            m_nCSXXX;
	char             m_lpsCxxMoreParents[100];
	char             m_lpsCxxParent[100];
	CList<SCGStr>    m_cxxWrappers;
	CList<SCGStr>    m_defList;
	CList<SCGStr>    m_defines;
	char             m_lpsDlcParent[100];
	CList<SCGStr>    m_doneCode;
	CList<SCGStr>    m_dspFileTmpl;
	CList<SCGStr>    m_dswFileTmpl;
	CList<SCGErr>    m_errors;
	CList<SCGStr>    m_exports;
	CList<SCGFile>   m_files;
	CList<SCGFld>    m_flds;
	CList<SCGStr>    m_friends;
	char             m_lpsGccFlags[255];
	CList<SCGStr>    m_headerCode;
	CList<SCGStr>    m_hFileTmpl;
	char             m_lpsHomePath[255];
	INT16            m_bHtmlMan;
	char             m_lpsIPath[255];
	CList<SCGIcl>    m_icls;
	CList<SCGStr>    m_includes;
	CList<SCGStr>    m_initCode;
	CList<SCGStr>    m_installCode;
	CItp*            m_iItp;
	CList<SCGStr>    m_lFiles;
	char             m_lpsLPath[255];
	char             m_lpsLibfile[64];
	char             m_lpsMPath[255];
	BOOL             m_bMainProject;
	CList<SCGStr>    m_makFileTmpl;
	CList<SCGStr>    m_manual;
	char             m_lpsMSDPath[255];
	char             m_lpsMsvcFlags[255];
	CList<SCGMth>    m_mths;
	INT16            m_nNMakeSection;
	CList<SCGStr>    m_nmakFileTmpl;
	char             m_lpsOPath[255];
	char             m_lpsObsolete[100];
	CList<SCGOpt>    m_opts;
	char             m_lpsParentProject[100];
	CList<SCGStr>    m_pincludes;
	INT16            m_nPlatform;
	char             m_lpsProject[100];
	CList<SCGStr>    m_resetCode;
	CList<SCGStr>    m_restoreCode;
	CList<SCGRnt>    m_rnts;
	CList<SCGStr>    m_saveCode;
	char             m_lpsVersion[20];
//}}CGEN_FIELDS

//{{CGEN_OPTIONS
	BOOL m_bAppend;
	BOOL m_bClib;
	BOOL m_bCProject;
	BOOL m_bCxxNconv;
	BOOL m_bHtml;
	BOOL m_bNoIdcheck;
	BOOL m_bNoStdincl;
	BOOL m_bPrimary;
	BOOL m_bXDoc;
//}}CGEN_OPTIONS
}

;

// Scanned C (member) functions
//{{CGEN_CEXPORT

// Taken from 'dcg_cft.cpp'

// Taken from 'dcg_cmd.cpp'

// Taken from 'dcg_cpp.cpp'

// Taken from 'dcg_htm.cpp'

// Taken from 'dcg_mak.cpp'

// Taken from 'dcg_sid.cpp'

// Taken from 'dcg_jvd.cpp'

// Taken from 'dcg_tpl.cpp'
//}}CGEN_CEXPORT

#endif //#ifndef __DCG_H


// EOF
