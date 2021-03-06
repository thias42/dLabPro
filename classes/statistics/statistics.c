/* dLabPro class CStatistics (statistics)
 * - Multivariate multiclass statistics
 *
 * AUTHOR : Matthias Wolff, Christian-M. Westendorf
 * PACKAGE: dLabPro/classes
 *
 * This file was generated by dcg. DO NOT MODIFY! Modify statistics.def instead.
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
#include "dlp_statistics.h"

/* Class CStatistics */

void CStatistics_Constructor(CStatistics* _this, const char* lpInstanceName, BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CStatistics_Constructor; (bCallVirtual=%d)",(int)bCallVirtual,0,0);

#ifndef __cplusplus

	/* Register instance */
	dlp_xalloc_register_object('J',_this,1,sizeof(CStatistics),
		__FILE__,__LINE__,"statistics",lpInstanceName);

	/* Create base instance */
	_this->m_lpBaseInstance = calloc(1,sizeof(CDlpObject));
	CDlpObject_Constructor(_this->m_lpBaseInstance,lpInstanceName,FALSE);

	/* Override virtual member functions */
	_this->m_lpBaseInstance->AutoRegisterWords = CStatistics_AutoRegisterWords;
	_this->m_lpBaseInstance->Reset             = CStatistics_Reset;
	_this->m_lpBaseInstance->Init              = CStatistics_Init;
	_this->m_lpBaseInstance->Serialize         = CStatistics_Serialize;
	_this->m_lpBaseInstance->SerializeXml      = CStatistics_SerializeXml;
	_this->m_lpBaseInstance->Deserialize       = CStatistics_Deserialize;
	_this->m_lpBaseInstance->DeserializeXml    = CStatistics_DeserializeXml;
	_this->m_lpBaseInstance->Copy              = CStatistics_Copy;
	_this->m_lpBaseInstance->ClassProc         = CStatistics_ClassProc;
	_this->m_lpBaseInstance->GetInstanceInfo   = CStatistics_GetInstanceInfo;
	_this->m_lpBaseInstance->IsKindOf          = CStatistics_IsKindOf;
	_this->m_lpBaseInstance->Destructor        = CStatistics_Destructor;
	_this->m_lpBaseInstance->ResetAllOptions   = CStatistics_ResetAllOptions;

	/* Override pointer to derived instance */
	_this->m_lpBaseInstance->m_lpDerivedInstance = _this;

	#endif /* #ifndef __cplusplus */

	dlp_strcpy(BASEINST(_this)->m_lpClassName,"statistics");
	dlp_strcpy(BASEINST(_this)->m_lpObsoleteName,"");
	dlp_strcpy(BASEINST(_this)->m_lpProjectName,"statistics");
	dlp_strcpy(BASEINST(_this)->m_version.no,"1.0.0");
	dlp_strcpy(BASEINST(_this)->m_version.date,"");
	BASEINST(_this)->m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(INVOKE_VIRTUAL_0(AutoRegisterWords)));
		INVOKE_VIRTUAL_1(Init,TRUE);
	}
}

void CStatistics_Destructor(CDlpObject* __this)
{
	GET_THIS_VIRTUAL(CStatistics);
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

INT16 CStatistics_AutoRegisterWords(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	DEBUGMSG(-1,"CStatistics_AutoRegisterWords",0,0,0);

	/* Call base class implementation */
	IF_NOK(INVOKE_BASEINST_0(AutoRegisterWords)) return NOT_EXEC;

	/*{{CGEN_REGISTERWORDS */

	/* Register methods */
	REGISTER_METHOD("-corc","",LPMF(CStatistics,OnCorc),"Estimates correlation coefficient matrices.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-cov","",LPMF(CStatistics,OnCov),"Estimates covariance matrices.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-detc","",LPMF(CStatistics,OnDetc),"Estimates coefficient of determination matrices.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-excs","",LPMF(CStatistics,OnExcs),"Estimates excess vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-freq","",LPMF(CStatistics,OnFreq),"Get sample size for all classes.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-kmoment","",LPMF(CStatistics,OnKmoment),"Estimates k-th order (central) moment vectors.",0,"<short k> <data idDst> <statistics this>","")
	REGISTER_METHOD("-max","",LPMF(CStatistics,OnMax),"Get maximum vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-mean","",LPMF(CStatistics,OnMean),"Estimates mean vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-merge","",LPMF(CStatistics,OnMerge),"Merges two statistics",0,"<statistics iSrc> <statistics this>","")
	REGISTER_METHOD("-min","",LPMF(CStatistics,OnMin),"Get minimum vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-pool","",LPMF(CStatistics,OnPool),"Pools statistics classes.",0,"<statistics iSrc> <data idMap> <statistics this>","")
	REGISTER_METHOD("-prob","",LPMF(CStatistics,OnProb),"Estimate a-priori class probabilities.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-scat","",LPMF(CStatistics,OnScat),"Estimates scatter matrices.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-sdev","",LPMF(CStatistics,OnSdev),"Estimates standard deviation vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-setup","",LPMF(CStatistics,OnSetup),"Setup statistics.",0,"<int nOrder> <int nDim> <int nCls> <data idLtb> <int nIcLtb> <statistics this>","")
	REGISTER_METHOD("-skew","",LPMF(CStatistics,OnSkew),"Estimates skewness vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-span","",LPMF(CStatistics,OnSpan),"Get sample spanwidth vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-status","",LPMF(CStatistics,OnStatus),"Prints status information of the statistics.",0,"<statistics this>","")
	REGISTER_METHOD("-update","",LPMF(CStatistics,OnUpdate),"Update statistics with set of (labelled) vectors.",0,"<data idVec> <int nIcLab> <data idW> <statistics this>","")
	REGISTER_METHOD("-var","",LPMF(CStatistics,OnVar),"Estimates variance vectors.",0,"<data idDst> <statistics this>","")
	REGISTER_METHOD("-varc","",LPMF(CStatistics,OnVarc),"Estimates variation coefficient vectors.",0,"<data idDst> <statistics this>","")

	/* Register options */
	REGISTER_OPTION("/central","",LPMV(m_bCentral),NULL,"Estimate central moments.",0)
	REGISTER_OPTION("/label","",LPMV(m_bLabel),NULL,"Ignore label indices if there some.",0)
	REGISTER_OPTION("/sn","",LPMV(m_bSn),NULL,"For backward compatibility of (co)variance estimation.",0)

	/* Register fields */
	REGISTER_FIELD("dat","",LPMV(m_idDat),NULL,"Statistic data.",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("ltb","",LPMV(m_idLtb),NULL,"Symbolic label table.",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("min_var","",LPMV(m_nMinVar),NULL,"Minimum value for (co)variances.",0,3008,1,"double",(FLOAT64)0.)
	REGISTER_FIELD("weighted","",LPMV(m_bWeighted),NULL,"Weighted statistics",FF_NOSET,1000,1,"bool",(BOOL)FALSE)

	/* Register errors */
	REGISTER_ERROR("~e1_0_0__1",EL_ERROR,STA_NOTSETUP,"Model not properly set up%s.")
	REGISTER_ERROR("~e2_0_0__1",EL_ERROR,STA_VECIGNORED,"%ld update vector(s) ignored.")
	REGISTER_ERROR("~e3_0_0__1",EL_WARNING,STA_IGNORE,"Extra %s ignored.")
	REGISTER_ERROR("~e4_0_0__1",EL_WARNING,STA_DIM,"%s has a wrong number of %s (should be %ld).")
	REGISTER_ERROR("~e5_0_0__1",EL_ERROR,STA_BADCOMP,"%s component of %s not found or of bad type (should be %s).")
	REGISTER_ERROR("~e6_0_0__1",EL_WARNING,STA_SLAB,"Record %ld contains a bad label ('%s').")
	REGISTER_ERROR("~e7_0_0__1",EL_WARNING,STA_NLAB,"Record %ld contains a bad label (%ld).")
	REGISTER_ERROR("~e8_0_0__1",EL_ERROR,STA_INCOMPAT,"Incompatible statistics.")
	/*}}CGEN_REGISTERWORDS */

	return O_K;
}

INT16 CStatistics_Init(CDlpObject* __this, BOOL bCallVirtual)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	DEBUGMSG(-1,"CStatistics_Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	{
	/*{{CGEN_INITCODE */
  INIT;
	/*}}CGEN_INITCODE */
	}

	/* If last derivation call reset (do not reset members; already done by Init()) */
#ifndef __NORTTI
	if (bCallVirtual) return INVOKE_VIRTUAL_1(Reset,FALSE); else
#endif
	                  return O_K;
}

INT16 CStatistics_Reset(CDlpObject* __this, BOOL bResetMembers)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	DEBUGMSG(-1,"CStatistics_Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	{
	/*{{CGEN_RESETCODE */
  return RESET;
	/*}}CGEN_RESETCODE */
	}

	return O_K;
}

INT16 CStatistics_ClassProc(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	{
	/*{{CGEN_CLASSCODE */
  return CLASSPROC;
	/*}}CGEN_CLASSCODE */
	}

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CStatistics_Serialize(CDlpObject* __this, CDN3Stream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
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
INT16 CStatistics_SerializeXml(CDlpObject* __this, CXmlStream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
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
INT16 CStatistics_Deserialize(CDlpObject* __this, CDN3Stream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
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
INT16 CStatistics_DeserializeXml(CDlpObject* __this, CXmlStream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	{
	/*{{CGEN_RESTORECODE */
  return RESTORE;
	/*}}CGEN_RESTORECODE */
	}

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CStatistics_Copy(CDlpObject* __this, CDlpObject* __iSrc)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	{
	/*{{CGEN_COPYCODE */
  return COPY;
	/*}}CGEN_COPYCODE */
	}

	return O_K;
}

/* Runtime class type information and class factory */
INT16 CStatistics_InstallProc(void* lpItp)
{
	{
	/*{{CGEN_INSTALLCODE */
  return INSTALL;
	/*}}CGEN_INSTALLCODE */
	}

	return O_K;
}

CStatistics* CStatistics_CreateInstance(const char* lpName)
{
	CStatistics* lpNewInstance;
	ICREATEEX(CStatistics,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CStatistics_GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;

#ifdef __cplusplus

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CStatistics::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CStatistics::InstallProc;

#else /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CStatistics_CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CStatistics_InstallProc;

#endif /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpProject   = "statistics";
	lpClassWord->ex.fct.lpBaseClass = "-";
	lpClassWord->lpComment          = "Multivariate multiclass statistics";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CStatistics";
	lpClassWord->ex.fct.lpAuthor    = "Matthias Wolff, Christian-M. Westendorf";

	dlp_strcpy(lpClassWord->lpName             ,"statistics");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"1.0.0");

	return O_K;
}

INT16 CStatistics_GetInstanceInfo(CDlpObject* __this, SWord* lpClassWord)
{
	return CStatistics_GetClassInfo(lpClassWord);
}

BOOL CStatistics_IsKindOf(CDlpObject* __this, const char* lpClassName)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);

  if (dlp_strncmp(lpClassName,"statistics",L_NAMES) == 0) return TRUE;
	else return INVOKE_BASEINST_1(IsKindOf,lpClassName);
}

INT16 CStatistics_ResetAllOptions(CDlpObject* __this, BOOL bInit)
{
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	DEBUGMSG(-1,"CStatistics_ResetAllOptions;",0,0,0);
	{
	/*{{CGEN_RESETALLOPTIONS*/
	_this->m_bCentral = FALSE;
	_this->m_bLabel = FALSE;
	_this->m_bSn = FALSE;
	/*}}CGEN_RESETALLOPTIONS*/
	}

	return INVOKE_BASEINST_1(ResetAllOptions,bInit);
}

/* Generated primary method invocation functions */

#ifndef __NOITP
/*{{CGEN_CPMIC */
INT16 CStatistics_OnCorc(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Corc(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnCov(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Cov(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnDetc(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Detc(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnExcs(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Excs(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnFreq(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Freq(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnKmoment(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	INT16 k;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	k = (INT16)MIC_GET_N(2,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Kmoment(_this, k, idDst);
	return __nErr;
}

INT16 CStatistics_OnMax(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Max(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnMean(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Mean(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnMerge(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	statistics* iSrc;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	iSrc = MIC_GET_I_EX(iSrc,statistics,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Merge(_this, iSrc);
	return __nErr;
}

INT16 CStatistics_OnMin(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Min(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnPool(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	statistics* iSrc;
	data* idMap;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idMap = MIC_GET_I_EX(idMap,data,1,1);
	iSrc = MIC_GET_I_EX(iSrc,statistics,2,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Pool(_this, iSrc, idMap);
	return __nErr;
}

INT16 CStatistics_OnProb(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Prob(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnScat(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Scat(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnSdev(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Sdev(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnSetup(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	INT32 nOrder;
	INT32 nDim;
	INT32 nCls;
	data* idLtb;
	INT32 nIcLtb;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	nIcLtb = (INT32)MIC_GET_N(1,0);
	idLtb = MIC_GET_I_EX(idLtb,data,2,1);
	nCls = (INT32)MIC_GET_N(3,1);
	nDim = (INT32)MIC_GET_N(4,2);
	nOrder = (INT32)MIC_GET_N(5,3);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Setup(_this, nOrder, nDim, nCls, idLtb, nIcLtb);
	return __nErr;
}

INT16 CStatistics_OnSkew(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Skew(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnSpan(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Span(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnStatus(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Status(_this);
	return __nErr;
}

INT16 CStatistics_OnUpdate(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idVec;
	INT32 nIcLab;
	data* idW;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idW = MIC_GET_I_EX(idW,data,1,1);
	nIcLab = (INT32)MIC_GET_N(2,0);
	idVec = MIC_GET_I_EX(idVec,data,3,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Update(_this, idVec, nIcLab, idW);
	return __nErr;
}

INT16 CStatistics_OnVar(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Var(_this, idDst);
	return __nErr;
}

INT16 CStatistics_OnVarc(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* idDst;
	GET_THIS_VIRTUAL_RV(CStatistics,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	idDst = MIC_GET_I_EX(idDst,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CStatistics_Varc(_this, idDst);
	return __nErr;
}

/*}}CGEN_CPMIC */
#endif /* #ifndef __NOITP */


/* Generated secondary method invocation functions */

/*{{CGEN_CSMIC */
INT16 CStatistics_Corc(CStatistics* _this, data* idDst)
{
    return CStatistics_CorrelationEx(_this,idDst,STA_CMA_CORC);
	return O_K;
}

INT16 CStatistics_Cov(CStatistics* _this, data* idDst)
{
    return CStatistics_CorrelationEx(_this,idDst,STA_CMA_COV);
	return O_K;
}

INT16 CStatistics_Detc(CStatistics* _this, data* idDst)
{
    return CStatistics_CorrelationEx(_this,idDst,STA_CMA_DETC);
	return O_K;
}

INT16 CStatistics_Excs(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,4,STA_KMA_CENT|STA_KMA_EXCS);
	return O_K;
}

INT16 CStatistics_Freq(CStatistics* _this, data* idDst)
{
    return CStatistics_FreqEx(_this,idDst,FALSE);
	return O_K;
}

INT16 CStatistics_Kmoment(CStatistics* _this, INT16 k, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,k,_this->m_bCentral?STA_KMA_CENT:0);
	return O_K;
}

INT16 CStatistics_Max(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,0,STA_KMA_MAX);
	return O_K;
}

INT16 CStatistics_Mean(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,1,0);
	return O_K;
}

INT16 CStatistics_Min(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,0,STA_KMA_MIN);
	return O_K;
}

INT16 CStatistics_Prob(CStatistics* _this, data* idDst)
{
    return CStatistics_FreqEx(_this,idDst,TRUE);
	return O_K;
}

INT16 CStatistics_Scat(CStatistics* _this, data* idDst)
{
    return CStatistics_CorrelationEx(_this,idDst,STA_CMA_SCAT);
	return O_K;
}

INT16 CStatistics_Sdev(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,2,STA_KMA_CENT|STA_KMA_N1|STA_KMA_SDEV);
	return O_K;
}

INT16 CStatistics_Skew(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,3,STA_KMA_CENT|STA_KMA_SKEW);
	return O_K;
}

INT16 CStatistics_Span(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,0,STA_KMA_SPAN);
	return O_K;
}

INT16 CStatistics_Var(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,2,STA_KMA_CENT|STA_KMA_N1);
	return O_K;
}

INT16 CStatistics_Varc(CStatistics* _this, data* idDst)
{
    return CStatistics_MomentEx(_this,idDst,2,STA_KMA_CENT|STA_KMA_N1|STA_KMA_COEF);
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

CStatistics::CStatistics(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	CStatistics_Constructor(this,lpInstanceName,bCallVirtual);
}

CStatistics::~CStatistics()
{
	CStatistics_Destructor(this);
}

INT16 CStatistics::AutoRegisterWords()
{
	return CStatistics_AutoRegisterWords(this);
}

INT16 CStatistics::Init(BOOL bCallVirtual)
{
	return CStatistics_Init(this,bCallVirtual);
}

INT16 CStatistics::Reset(BOOL bResetMembers)
{
	return CStatistics_Reset(this,bResetMembers);
}

INT16 CStatistics::ClassProc()
{
	return CStatistics_ClassProc(this);
}

INT16 CStatistics::Serialize(CDN3Stream* lpDest)
{
	return CStatistics_Serialize(this,lpDest);
}

INT16 CStatistics::SerializeXml(CXmlStream* lpDest)
{
	return CStatistics_SerializeXml(this,lpDest);
}

INT16 CStatistics::Deserialize(CDN3Stream* lpSrc)
{
	return CStatistics_Deserialize(this,lpSrc);
}

INT16 CStatistics::DeserializeXml(CXmlStream* lpSrc)
{
	return CStatistics_DeserializeXml(this,lpSrc);
}

INT16 CStatistics::Copy(CDlpObject* __iSrc)
{
	return CStatistics_Copy(this,__iSrc);
}

INT16 CStatistics::InstallProc(void* lpItp)
{
	return CStatistics_InstallProc(lpItp);
}

CStatistics* CStatistics::CreateInstance(const char* lpName)
{
	return CStatistics_CreateInstance(lpName);
}

INT16 CStatistics::GetClassInfo(SWord* lpClassWord)
{
	return CStatistics_GetClassInfo(lpClassWord);
}

INT16 CStatistics::GetInstanceInfo(SWord* lpClassWord)
{
	return CStatistics_GetInstanceInfo(this,lpClassWord);
}

BOOL CStatistics::IsKindOf(const char* lpClassName)
{
	return CStatistics_IsKindOf(this,lpClassName);
}

INT16 CStatistics::ResetAllOptions(BOOL bInit)
{
	return CStatistics_ResetAllOptions(this,bInit);
}

#ifndef __NOITP
/*{{CGEN_PMIC */
INT16 CStatistics::OnCorc()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnCorc(this);
}

INT16 CStatistics::OnCov()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnCov(this);
}

INT16 CStatistics::OnDetc()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnDetc(this);
}

INT16 CStatistics::OnExcs()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnExcs(this);
}

INT16 CStatistics::OnFreq()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnFreq(this);
}

INT16 CStatistics::OnKmoment()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnKmoment(this);
}

INT16 CStatistics::OnMax()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnMax(this);
}

INT16 CStatistics::OnMean()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnMean(this);
}

INT16 CStatistics::OnMerge()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnMerge(this);
}

INT16 CStatistics::OnMin()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnMin(this);
}

INT16 CStatistics::OnPool()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnPool(this);
}

INT16 CStatistics::OnProb()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnProb(this);
}

INT16 CStatistics::OnScat()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnScat(this);
}

INT16 CStatistics::OnSdev()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnSdev(this);
}

INT16 CStatistics::OnSetup()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnSetup(this);
}

INT16 CStatistics::OnSkew()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnSkew(this);
}

INT16 CStatistics::OnSpan()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnSpan(this);
}

INT16 CStatistics::OnStatus()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnStatus(this);
}

INT16 CStatistics::OnUpdate()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnUpdate(this);
}

INT16 CStatistics::OnVar()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnVar(this);
}

INT16 CStatistics::OnVarc()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CStatistics_OnVarc(this);
}

/*}}CGEN_PMIC */
#endif /* #ifndef __NOITP */

/*{{CGEN_SMIC */
INT16 CStatistics::Corc(data* idDst)
{
	return CStatistics_Corc(this,idDst);
}

INT16 CStatistics::Cov(data* idDst)
{
	return CStatistics_Cov(this,idDst);
}

INT16 CStatistics::Detc(data* idDst)
{
	return CStatistics_Detc(this,idDst);
}

INT16 CStatistics::Excs(data* idDst)
{
	return CStatistics_Excs(this,idDst);
}

INT16 CStatistics::Freq(data* idDst)
{
	return CStatistics_Freq(this,idDst);
}

INT16 CStatistics::Kmoment(INT16 k, data* idDst)
{
	return CStatistics_Kmoment(this,k, idDst);
}

INT16 CStatistics::Max(data* idDst)
{
	return CStatistics_Max(this,idDst);
}

INT16 CStatistics::Mean(data* idDst)
{
	return CStatistics_Mean(this,idDst);
}

INT16 CStatistics::Min(data* idDst)
{
	return CStatistics_Min(this,idDst);
}

INT16 CStatistics::Prob(data* idDst)
{
	return CStatistics_Prob(this,idDst);
}

INT16 CStatistics::Scat(data* idDst)
{
	return CStatistics_Scat(this,idDst);
}

INT16 CStatistics::Sdev(data* idDst)
{
	return CStatistics_Sdev(this,idDst);
}

INT16 CStatistics::Skew(data* idDst)
{
	return CStatistics_Skew(this,idDst);
}

INT16 CStatistics::Span(data* idDst)
{
	return CStatistics_Span(this,idDst);
}

INT16 CStatistics::Var(data* idDst)
{
	return CStatistics_Var(this,idDst);
}

INT16 CStatistics::Varc(data* idDst)
{
	return CStatistics_Varc(this,idDst);
}

/*}}CGEN_SMIC */

/*{{CGEN_OCCF */
/*}}CGEN_OCCF */

/*{{CGEN_FCCF */
/*}}CGEN_FCCF */

/*{{CGEN_CXXWRAP */
INT32 CStatistics::GetDim()
{
	return CStatistics_GetDim(this);
}

INT32 CStatistics::GetNClasses()
{
	return CStatistics_GetNClasses(this);
}

INT32 CStatistics::GetOrder()
{
	return CStatistics_GetOrder(this);
}

INT32 CStatistics::GetNSamples()
{
	return CStatistics_GetNSamples(this);
}

FLOAT64* CStatistics::GetPtr(INT32 c, INT16 nData)
{
	return CStatistics_GetPtr(this, c, nData);
}

INT16 CStatistics::FreqEx(CData* idDst, BOOL bProb)
{
	return CStatistics_FreqEx(this, idDst, bProb);
}

INT16 CStatistics::CheckDat()
{
	return CStatistics_CheckDat(this);
}

INT16 CStatistics::CheckLtb()
{
	return CStatistics_CheckLtb(this);
}

INT16 CStatistics::Check()
{
	return CStatistics_Check(this);
}

INT16 CStatistics::Status()
{
	return CStatistics_Status(this);
}

FLOAT64 CStatistics::Cov(FLOAT64* lpMsum, FLOAT64* lpSum, INT32 N, FLOAT64 I, INT32 n, INT32 m)
{
	return CStatistics_Cov(this, lpMsum, lpSum, N, I, n, m);
}

INT16 CStatistics::CorrelationEx(CData* idDst, INT16 nMode)
{
	return CStatistics_CorrelationEx(this, idDst, nMode);
}

void CStatistics::Moment0(FLOAT64* lpY, INT32 c, INT32 N, INT16 nMode)
{
	CStatistics_Moment0(this, lpY, c, N, nMode);
}

void CStatistics::Moment1(FLOAT64* lpY, INT32 c, INT32 N, INT16 nMode)
{
	CStatistics_Moment1(this, lpY, c, N, nMode);
}

void CStatistics::Moment2(FLOAT64* lpY, INT32 c, INT32 N, INT16 nMode)
{
	CStatistics_Moment2(this, lpY, c, N, nMode);
}

void CStatistics::MomentK(FLOAT64* lpY, INT32 c, INT32 k, INT32 N, INT32 K, INT16 nMode)
{
	CStatistics_MomentK(this, lpY, c, k, N, K, nMode);
}

void CStatistics::Skewness(FLOAT64* lpY, INT32 c, INT32 N, INT32 K)
{
	CStatistics_Skewness(this, lpY, c, N, K);
}

void CStatistics::Excess(FLOAT64* lpY, INT32 c, INT32 N, INT32 K)
{
	CStatistics_Excess(this, lpY, c, N, K);
}

INT16 CStatistics::MomentEx(CData* idDst, INT16 k, INT16 nMode)
{
	return CStatistics_MomentEx(this, idDst, k, nMode);
}

void CStatistics::PoolInt(CData* idPool, CData* idSrc, INT32 nMode)
{
	CStatistics_PoolInt(idPool, idSrc, nMode);
}

INT16 CStatistics::Pool(CStatistics* iSrc, CData* idMap)
{
	return CStatistics_Pool(this, iSrc, idMap);
}

INT16 CStatistics::Merge(CStatistics* iSrc)
{
	return CStatistics_Merge(this, iSrc);
}

INT16 CStatistics::Setup(INT32 nOrder, INT32 nDim, INT32 nCls, CData* idLtb, INT32 nIcLtb)
{
	return CStatistics_Setup(this, nOrder, nDim, nCls, idLtb, nIcLtb);
}

INT16 CStatistics::UpdateVector(FLOAT64* lpX, INT32 c, FLOAT64 w)
{
	return CStatistics_UpdateVector(this, lpX, c, w);
}

INT16 CStatistics::Update(CData* idVec, INT32 nIcLab, CData* idW)
{
	return CStatistics_Update(this, idVec, nIcLab, idW);
}

/*}}CGEN_CXXWRAP */

#endif /* #ifdef __cplusplus */

/* EOF */
