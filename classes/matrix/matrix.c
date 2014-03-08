/* dLabPro class CMatrix (matrix)
 * - Matrix operations
 *
 * AUTHOR : Christian-M. Westendorf, Matthias Wolff
 * PACKAGE: dLabPro/classes
 *
 * This file was generated by dcg. DO NOT MODIFY! Modify matrix.def instead.
 * 
 * Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
 * - Chair of System Theory and Speech Technology, TU Dresden
 * - Chair of Communications Engineering, BTU Cottbus
 * 
 * This file is part of dLabPro.
 * 
 * dLabPro is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with dLabPro. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dlp_cscope.h" /* Indicate C scope */
/*{{CGEN_INCLUDE */
/*}}CGEN_END */
#include "dlp_matrix.h"

/* Class CMatrix */

void CMatrix_Constructor(CMatrix* _this, const char* lpInstanceName, BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CMatrix_Constructor; (bCallVirtual=%d)",(int)bCallVirtual,0,0);

#ifndef __cplusplus

	/* Register instance */
	dlp_xalloc_register_object('J',_this,1,sizeof(CMatrix),
		__FILE__,__LINE__,"matrix",lpInstanceName);

	/* Create base instance */
	_this->m_lpBaseInstance = calloc(1,sizeof(CDlpObject));
	CDlpObject_Constructor(_this->m_lpBaseInstance,lpInstanceName,FALSE);

	/* Override virtual member functions */
	_this->m_lpBaseInstance->AutoRegisterWords = CMatrix_AutoRegisterWords;
	_this->m_lpBaseInstance->Reset             = CMatrix_Reset;
	_this->m_lpBaseInstance->Init              = CMatrix_Init;
	_this->m_lpBaseInstance->Serialize         = CMatrix_Serialize;
	_this->m_lpBaseInstance->SerializeXml      = CMatrix_SerializeXml;
	_this->m_lpBaseInstance->Deserialize       = CMatrix_Deserialize;
	_this->m_lpBaseInstance->DeserializeXml    = CMatrix_DeserializeXml;
	_this->m_lpBaseInstance->Copy              = CMatrix_Copy;
	_this->m_lpBaseInstance->ClassProc         = CMatrix_ClassProc;
	_this->m_lpBaseInstance->GetInstanceInfo   = CMatrix_GetInstanceInfo;
	_this->m_lpBaseInstance->IsKindOf          = CMatrix_IsKindOf;
	_this->m_lpBaseInstance->Destructor        = CMatrix_Destructor;
	_this->m_lpBaseInstance->ResetAllOptions   = CMatrix_ResetAllOptions;

	/* Override pointer to derived instance */
	_this->m_lpBaseInstance->m_lpDerivedInstance = _this;

	#endif /* #ifndef __cplusplus */

	dlp_strcpy(BASEINST(_this)->m_lpClassName,"matrix");
	dlp_strcpy(BASEINST(_this)->m_lpObsoleteName,"");
	dlp_strcpy(BASEINST(_this)->m_lpProjectName,"matrix");
	dlp_strcpy(BASEINST(_this)->m_version.no,"1.1.0");
	dlp_strcpy(BASEINST(_this)->m_version.date,"");
	BASEINST(_this)->m_nClStyle = CS_SINGLETON;

	if (bCallVirtual)
	{
		DLPASSERT(OK(INVOKE_VIRTUAL_0(AutoRegisterWords)));
		INVOKE_VIRTUAL_1(Init,TRUE);
	}
}

void CMatrix_Destructor(CDlpObject* __this)
{
	GET_THIS_VIRTUAL(CMatrix);
	{
	/*{{CGEN_DONECODE */
  DONE;
	/*}}CGEN_DONECODE */
	}

#ifndef __cplusplus

	/* Destroy base instance */
	CDlpObject_Destructor(_this->m_lpBaseInstance);
	dlp_free(_this->m_lpBaseInstance);
	_this->m_lpBaseInstance = NULL;

#endif /* #ifndef __cplusplus */
}

INT16 CMatrix_AutoRegisterWords(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	DEBUGMSG(-1,"CMatrix_AutoRegisterWords",0,0,0);

	/* Call base class implementation */
	IF_NOK(INVOKE_BASEINST_0(AutoRegisterWords)) return NOT_EXEC;

	/*{{CGEN_REGISTERWORDS */

	/* Register methods */
	REGISTER_METHOD("-eigen","",LPMF(CMatrix,OnEigenIam),"Eigenvector transform of square matrices.",0,"<data A> <data V> <data L> <matrix this>","")
	REGISTER_METHOD("-expand","",LPMF(CMatrix,OnExpand),"Expands a list representation of a sparse matrix",0,"<data idSrc> <int nIcR> <int nIcC> <int nIcV> <int nRecs> <int nComps> <string sOp> <data idDst> <matrix this>","")
	REGISTER_METHOD("-fact_ldl","",LPMF(CMatrix,OnFactLdl),"Factorisize matrix A to lower triangular matrix L and diagonal matrix D (A=LDL^T)",0,"<data A> <data L> <data D> <matrix this>","")
	REGISTER_METHOD("-invert","",LPMF(CMatrix,OnInvertIam),"Inverts square matrices and computes ranks or determinants.",0,"<data A> <data Z> <data Y> <matrix this>","")
	REGISTER_METHOD("-op","",LPMF(CMatrix,OnOp),"Matrix operation",0,"<par1> <par2> <data idDst> <string sOpname> <matrix this>","")
	REGISTER_METHOD("-submat","",LPMF(CMatrix,OnSubmatIam),"Get submatrices",0,"<data A> <int i> <int k> <int n> <int m> <data Z> <matrix this>","")

	/* Register options */
	REGISTER_OPTION("/inv","",LPMV(m_bInv),NULL,"Inverse operation",0)
	REGISTER_OPTION("/norm","",LPMV(m_bNorm),NULL,"Normalize",0)
	/*}}CGEN_REGISTERWORDS */

	return O_K;
}

INT16 CMatrix_Init(CDlpObject* __this, BOOL bCallVirtual)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	DEBUGMSG(-1,"CMatrix_Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	{
	/*{{CGEN_INITCODE */

  INIT;

  /* Register operators */
  INT16 i = 0;
  while(dlp_scalop_entry(i)->opc >= 0) {
    REGISTER_OPERATOR(dlp_scalop_entry(i)->sym,&CMatrix_Op,dlp_scalop_entry(i)->opc,dlp_scalop_entry(i)->res,dlp_scalop_entry(i)->ops,dlp_scalop_entry(i)->sig,dlp_scalop_entry(i)->nam);
    i++;
  }
  i = 0;
  while(dlm_matrop_entry(i)->opc >= 0) {
    REGISTER_OPERATOR(dlm_matrop_entry(i)->sym,&CMatrix_Op,dlm_matrop_entry(i)->opc,dlm_matrop_entry(i)->res,dlm_matrop_entry(i)->ops,dlm_matrop_entry(i)->sig,dlm_matrop_entry(i)->nam);
    i++;
  }

	/*}}CGEN_INITCODE */
	}

	/* If last derivation call reset (do not reset members; already done by Init()) */
#ifndef __NORTTI
	if (bCallVirtual) return INVOKE_VIRTUAL_1(Reset,FALSE); else
#endif
	                  return O_K;
}

INT16 CMatrix_Reset(CDlpObject* __this, BOOL bResetMembers)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	DEBUGMSG(-1,"CMatrix_Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	{
	/*{{CGEN_RESETCODE */
  return RESET;
	/*}}CGEN_RESETCODE */
	}

	return O_K;
}

INT16 CMatrix_ClassProc(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_CLASSCODE */
  return CLASSPROC;
	/*}}CGEN_CLASSCODE */
	}

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CMatrix_Serialize(CDlpObject* __this, CDN3Stream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_SAVECODE */
  return SAVE;
	/*}}CGEN_SAVECODE */
	}

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CMatrix_SerializeXml(CDlpObject* __this, CXmlStream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_SAVECODE */
  return SAVE;
	/*}}CGEN_SAVECODE */
	}

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CMatrix_Deserialize(CDlpObject* __this, CDN3Stream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_RESTORECODE */
  return RESTORE;
	/*}}CGEN_RESTORECODE */
	}

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CMatrix_DeserializeXml(CDlpObject* __this, CXmlStream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_RESTORECODE */
  return RESTORE;
	/*}}CGEN_RESTORECODE */
	}

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CMatrix_Copy(CDlpObject* __this, CDlpObject* __iSrc)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	{
	/*{{CGEN_COPYCODE */
  return COPY;
	/*}}CGEN_COPYCODE */
	}

	return O_K;
}

/* Runtime class type information and class factory */
INT16 CMatrix_InstallProc(void* lpItp)
{
	{
	/*{{CGEN_INSTALLCODE */
  return INSTALL;
	/*}}CGEN_INSTALLCODE */
	}

	return O_K;
}

CMatrix* CMatrix_CreateInstance(const char* lpName)
{
	CMatrix* lpNewInstance;
	ICREATEEX(CMatrix,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CMatrix_GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_SINGLETON;

#ifdef __cplusplus

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CMatrix::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CMatrix::InstallProc;

#else /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CMatrix_CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CMatrix_InstallProc;

#endif /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpProject   = "matrix";
	lpClassWord->ex.fct.lpBaseClass = "-";
	lpClassWord->lpComment          = "Matrix operations";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CMatrix";
	lpClassWord->ex.fct.lpAuthor    = "Christian-M. Westendorf, Matthias Wolff";

	dlp_strcpy(lpClassWord->lpName             ,"matrix");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"1.1.0");

	return O_K;
}

INT16 CMatrix_GetInstanceInfo(CDlpObject* __this, SWord* lpClassWord)
{
	return CMatrix_GetClassInfo(lpClassWord);
}

BOOL CMatrix_IsKindOf(CDlpObject* __this, const char* lpClassName)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);

  if (dlp_strncmp(lpClassName,"matrix",L_NAMES) == 0) return TRUE;
	else return INVOKE_BASEINST_1(IsKindOf,lpClassName);
}

INT16 CMatrix_ResetAllOptions(CDlpObject* __this, BOOL bInit)
{
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	DEBUGMSG(-1,"CMatrix_ResetAllOptions;",0,0,0);
	{
	/*{{CGEN_RESETALLOPTIONS*/
	_this->m_bInv = FALSE;
	_this->m_bNorm = FALSE;
	/*}}CGEN_RESETALLOPTIONS*/
	}

	return INVOKE_BASEINST_1(ResetAllOptions,bInit);
}

/* Generated primary method invocation functions */

#ifndef __NOITP
/*{{CGEN_CPMIC */
INT16 CMatrix_OnEigenIam(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* A;
	data* V;
	data* L;
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	L = MIC_GET_I_EX(L,data,1,1);
	V = MIC_GET_I_EX(V,data,2,2);
	A = MIC_GET_I_EX(A,data,3,3);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CMatrix_EigenIam(_this, A, V, L);
	return __nErr;
}

INT16 CMatrix_OnExpand(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idSrc;
	INT32 nIcR;
	INT32 nIcC;
	INT32 nIcV;
	INT32 nRecs;
	INT32 nComps;
	char* sOp;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	sOp = MIC_GET_S(2,0);
	nComps = (INT32)MIC_GET_N(3,0);
	nRecs = (INT32)MIC_GET_N(4,1);
	nIcV = (INT32)MIC_GET_N(5,2);
	nIcC = (INT32)MIC_GET_N(6,3);
	nIcR = (INT32)MIC_GET_N(7,4);
	idSrc = MIC_GET_I_EX(idSrc,data,8,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CMatrix_Expand(_this, idSrc, nIcR, nIcC, nIcV, nRecs, nComps, sOp, idDst);
	return __nErr;
}

INT16 CMatrix_OnFactLdl(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* A;
	data* L;
	data* D;
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	D = MIC_GET_I_EX(D,data,1,1);
	L = MIC_GET_I_EX(L,data,2,2);
	A = MIC_GET_I_EX(A,data,3,3);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CMatrix_FactLdl(_this, A, L, D);
	return __nErr;
}

INT16 CMatrix_OnInvertIam(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* A;
	data* Z;
	data* Y;
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	Y = MIC_GET_I_EX(Y,data,1,1);
	Z = MIC_GET_I_EX(Z,data,2,2);
	A = MIC_GET_I_EX(A,data,3,3);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CMatrix_InvertIam(_this, A, Z, Y);
	return __nErr;
}

INT16 CMatrix_OnOp(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
/* User defined code --> */
    GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
    MIC_CHECK;
    return CMatrix_OnOp_Impl(_this);
/* <-- User defined code */
}

INT16 CMatrix_OnSubmatIam(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* A;
	INT32 i;
	INT32 k;
	INT32 n;
	INT32 m;
	data* Z;
	GET_THIS_VIRTUAL_RV(CMatrix,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	Z = MIC_GET_I_EX(Z,data,1,1);
	m = (INT32)MIC_GET_N(2,0);
	n = (INT32)MIC_GET_N(3,1);
	k = (INT32)MIC_GET_N(4,2);
	i = (INT32)MIC_GET_N(5,3);
	A = MIC_GET_I_EX(A,data,6,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CMatrix_SubmatIam(_this, A, i, k, n, m, Z);
	return __nErr;
}

/*}}CGEN_CPMIC */
#endif /* #ifndef __NOITP */


/* Generated secondary method invocation functions */

/*{{CGEN_CSMIC */
INT16 CMatrix_EigenIam(CMatrix* _this, data* A, data* V, data* L)
{
    return CMatrix_Eigen(A,V,L,_this->m_bInv,_this->m_bNorm);
	return O_K;
}

INT16 CMatrix_FactLdl(CMatrix* _this, data* A, data* L, data* D)
{
    return CMatrix_FactLDL(A,L,D);
	return O_K;
}

INT16 CMatrix_InvertIam(CMatrix* _this, data* A, data* Z, data* Y)
{
    return CMatrix_Invert(A,Z,Y);
	return O_K;
}

INT16 CMatrix_SubmatIam(CMatrix* _this, data* A, INT32 i, INT32 k, INT32 n, INT32 m, data* Z)
{
    return CMatrix_Submat(A,i,k,n,m,Z);
	return O_K;
}

/*}}CGEN_CSMIC */


/* Generated option change callback functions */

/*{{CGEN_COCCF */
/*}}CGEN_COCCF */


/* Generated field change callback functions */

/*{{CGEN_CFCCF */
/*}}CGEN_CFCCF */


/* C++ wrapper functions */
#ifdef __cplusplus

#define _this this

CMatrix::CMatrix(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	CMatrix_Constructor(this,lpInstanceName,bCallVirtual);
}

CMatrix::~CMatrix()
{
	CMatrix_Destructor(this);
}

INT16 CMatrix::AutoRegisterWords()
{
	return CMatrix_AutoRegisterWords(this);
}

INT16 CMatrix::Init(BOOL bCallVirtual)
{
	return CMatrix_Init(this,bCallVirtual);
}

INT16 CMatrix::Reset(BOOL bResetMembers)
{
	return CMatrix_Reset(this,bResetMembers);
}

INT16 CMatrix::ClassProc()
{
	return CMatrix_ClassProc(this);
}

INT16 CMatrix::Serialize(CDN3Stream* lpDest)
{
	return CMatrix_Serialize(this,lpDest);
}

INT16 CMatrix::SerializeXml(CXmlStream* lpDest)
{
	return CMatrix_SerializeXml(this,lpDest);
}

INT16 CMatrix::Deserialize(CDN3Stream* lpSrc)
{
	return CMatrix_Deserialize(this,lpSrc);
}

INT16 CMatrix::DeserializeXml(CXmlStream* lpSrc)
{
	return CMatrix_DeserializeXml(this,lpSrc);
}

INT16 CMatrix::Copy(CDlpObject* __iSrc)
{
	return CMatrix_Copy(this,__iSrc);
}

INT16 CMatrix::InstallProc(void* lpItp)
{
	return CMatrix_InstallProc(lpItp);
}

CMatrix* CMatrix::CreateInstance(const char* lpName)
{
	return CMatrix_CreateInstance(lpName);
}

INT16 CMatrix::GetClassInfo(SWord* lpClassWord)
{
	return CMatrix_GetClassInfo(lpClassWord);
}

INT16 CMatrix::GetInstanceInfo(SWord* lpClassWord)
{
	return CMatrix_GetInstanceInfo(this,lpClassWord);
}

BOOL CMatrix::IsKindOf(const char* lpClassName)
{
	return CMatrix_IsKindOf(this,lpClassName);
}

INT16 CMatrix::ResetAllOptions(BOOL bInit)
{
	return CMatrix_ResetAllOptions(this,bInit);
}

#ifndef __NOITP
/*{{CGEN_PMIC */
INT16 CMatrix::OnEigenIam()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnEigenIam(this);
}

INT16 CMatrix::OnExpand()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnExpand(this);
}

INT16 CMatrix::OnFactLdl()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnFactLdl(this);
}

INT16 CMatrix::OnInvertIam()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnInvertIam(this);
}

INT16 CMatrix::OnOp()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnOp(this);
}

INT16 CMatrix::OnSubmatIam()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CMatrix_OnSubmatIam(this);
}

/*}}CGEN_PMIC */
#endif /* #ifndef __NOITP */

/*{{CGEN_SMIC */
INT16 CMatrix::EigenIam(data* A, data* V, data* L)
{
	return CMatrix_EigenIam(this,A, V, L);
}

INT16 CMatrix::FactLdl(data* A, data* L, data* D)
{
	return CMatrix_FactLdl(this,A, L, D);
}

INT16 CMatrix::InvertIam(data* A, data* Z, data* Y)
{
	return CMatrix_InvertIam(this,A, Z, Y);
}

INT16 CMatrix::SubmatIam(data* A, INT32 i, INT32 k, INT32 n, INT32 m, data* Z)
{
	return CMatrix_SubmatIam(this,A, i, k, n, m, Z);
}

/*}}CGEN_SMIC */

/*{{CGEN_OCCF */
/*}}CGEN_OCCF */

/*{{CGEN_FCCF */
/*}}CGEN_FCCF */

/*{{CGEN_CXXWRAP */
INT16 CMatrix::OnOp_Impl()
{
	return CMatrix_OnOp_Impl(this);
}

INT16 CMatrix::Op(CData* idDst, void* lpPar1, INT16 nType1, void* lpPar2, INT16 nType2, INT16 nOpcode)
{
	return CMatrix_Op(idDst, lpPar1, nType1, lpPar2, nType2, nOpcode);
}

INT16 CMatrix::Invert(CData* A, CData* Z, CData* Y)
{
	return CMatrix_Invert(A, Z, Y);
}

INT16 CMatrix::Eigen(CData* A, CData* V, CData* L, BOOL bInv, BOOL bNorm)
{
	return CMatrix_Eigen(A, V, L, bInv, bNorm);
}

INT16 CMatrix::Submat(CData* A, INT32 i, INT32 k, INT32 n, INT32 m, CData* Z)
{
	return CMatrix_Submat(A, i, k, n, m, Z);
}

INT16 CMatrix::FactLDL(CData* A, CData* L, CData* D)
{
	return CMatrix_FactLDL(A, L, D);
}

INT16 CMatrix::Expand(CData* idSrc, INT32 nIcR, INT32 nIcC, INT32 nIcV, INT32 nRecs, INT32 nComps, const char* sOp, CData* idDst)
{
	return CMatrix_Expand(this, idSrc, nIcR, nIcC, nIcV, nRecs, nComps, sOp, idDst);
}

INT16 CMatrix::CopyLabels(CData* idDst, CData* idSrc)
{
	return CMatrix_CopyLabels(idDst, idSrc);
}

INT16 CMatrix::EigenInt(CData* A, CData* V, CData* L, BOOL bNorm)
{
	return CMatrix_EigenInt(A, V, L, bNorm);
}

INT16 CMatrix::IeigenInt(CData* A, CData* V, CData* L, BOOL bNorm)
{
	return CMatrix_IeigenInt(A, V, L, bNorm);
}

/*}}CGEN_CXXWRAP */

#endif /* #ifdef __cplusplus */

/* EOF */