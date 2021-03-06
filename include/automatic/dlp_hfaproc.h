// dLabPro class CHFAproc (HFAproc)
// - Header file
//
// AUTHOR : Rico Petrick, Mike Lorenz
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify hfaproc.def instead.
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
#include "dlp_config.h"
#include "dlp_object.h"
#include "dlp_fbaproc.h"
#include "dlp_data.h"
#include "dlp_math.h"
//}}CGEN_END

//{{CGEN_ERRORS
//}}CGEN_END

// C/C++ language abstraction layer
#undef hfaproc_par
#define hfaproc_par CHFAproc

// dLabPro/C++ language abstraction layer
#undef HFAproc
#define HFAproc CHFAproc

//{{CGEN_DEFINE
//}}CGEN_DEFINE

#ifndef __HFAPROC_H
#define __HFAPROC_H

//{{CGEN_HEADERCODE
/* ----- Limits ----- */

/*! @brief  maximum for unsigned 1 Byte data types */
#define U1_MAX          UCHAR_MAX
/*! @brief maximum for unsigned 2 Byte data types  */
#define U2_MAX          USHRT_MAX
/*! @brief maximum for unsigned 4 Byte data types  */
#define U4_MAX          ULONG_MAX
/*! @brief maximum for unsigned 8 Byte data types  */
#define U8_MAX          ULONG_MAX
/*! @brief minimum for unsigned 1 Byte data types  */
#define U1_MIN          0
/*! @brief minimum for unsigned 2 Byte data types   */
#define U2_MIN          0
/*! @brief minimum for unsigned 4 Byte data types  */
#define U4_MIN          0
/*! @brief minimum for unsigned 8 Byte data types  */
#define U8_MIN          0
/*! @brief maximum for signed 1 Byte data types  */
#define I1_MAX          CHAR_MAX
/*! @brief maximum for signed 2 Byte data types   */
#define I2_MAX          SHRT_MAX
/*! @brief maximum for signed 4 Byte data types  */
#define I4_MAX          LONG_MAX
/*! @brief maximum for signed 8 Byte data types */
#define I8_MAX          LONG_MAX
/*! @brief minimum for signed 1 Byte data types */
#define I1_MIN          CHAR_MIN
/*! @brief minimum for signed 2 Byte data types */
#define I2_MIN          SHRT_MIN
/*! @brief minimum for signed 4 Byte data types */
#define I4_MIN          LONG_MIN
/*! @brief minimum for signed 8 Byte data types */
#define I8_MIN          LONG_MIN
/*! @brief  maximum for float 4 Byte data types*/
#define R4_MAX          FLT_MAX
/*! @brief minimum for float 4 Byte data types  */
#define R4_MIN          (-FLT_MAX)
/*! @brief maximum for float 8 Byte data types */
#define R8_MAX          DBL_MAX
/*! @brief minimum for float 8 Byte data types  */
#define R8_MIN          (-DBL_MAX)
/*! @brief maximum for float 8 Byte data types (synonym) */
#define D8_MAX          R8_MAX
/*! @brief minimum for float 8 Byte data types (synonym) */
#define D8_MIN          R8_MIN


/*-------------------------------------------------------------------------
 *  Vectors
 * ------------------------------------------------------------------------*/
/*! @brief Vector is saved as one dimensional array*/
typedef struct str_i2arr {
        INT16 *pi2;
        UINT32  len;
} str_i2arr;

typedef struct str_r4arr {                                                        //
        FLOAT32 *pr4;
        UINT32  len;
} str_r4arr;

typedef struct str_r8arr {                                                        //
        FLOAT64 *pr8;
        UINT32  len;
} str_r8arr;

/*-------------------------------------------------------------------------
 *  Matrix
 * ------------------------------------------------------------------------*/
/*! @brief Matrix is saved as a one dimensional array
           the parameter width and length describe the matrix
           the length of the array is stored in the subarray*/

typedef struct tMXr {
    INT16        u2MxLen;           /*!< length of Featurematrix;*/
    INT16        u2MxHig;           /*!< hight of Featurematrix;*/
    str_r4arr   strMx;             /*!< Matrix of feature-vectors */
} tMXr;

typedef struct tMXi {
    INT16        u2MxLen;           /*!< length of Featurematrix;*/
    INT16        u2MxHig;           /*!< hight of Featurematrix;*/
    str_i2arr   strMx;             /*!< Matrix of feature-vectors */
} tMXi;


/*! @brief defines error rejection for can not exec app. */
#define NOT_EXEC     -1

/*! @brief defines error rejection for can exec app. */
#define OKAY          0

/*! @brief defines a FALSE, if not available */
#define FALSE                     0
/*! @brief defines TRUE the complement of FALSE */
// #define TRUE                      !FALSE



/*! @brief Definition of max Makro */
// #define MAX(a,b) (((a)>(b))?(a):(b))

/*! @brief Definition of min Makro  */
// #define MIN(a,b) (((a)<(b))?(a):(b))


/*! @brief VAD-states (VOIced UNVoiced) */
#define VOICE   1
#define UNVOI   0

/*! @brief SPD-states (SPEECH PAUSE) */
#define SPEECH   1
#define PAUSE    0

#define N_FFT_MAX (16*512)


/* -----------------------------------------------------------------------
 *  HFA
 * -----------------------------------------------------------------------*/

/*!
 * @brief structure for noise reduction unit
 */

/*! @brief structure with*/
typedef struct tGPAR {

  UINT32   u4f_s;               /*!< Sampling frequency in Herz*/
  FLOAT32  r4T_s;               /*!< Sampling frequency in Herz*/
  UINT16   u2F_rate;            /*!< frame rate / continue rate in samples */
  UINT16   u2F_width;           /*!< frame width in samples */
  UINT16   u2fft_length;        /*!< fft width in samples */
  FLOAT32  r4win_fft[N_FFT_MAX];/*!< window for fft in samples */
  BYTE     u1wtypefft;        /*!< window type for fft */

} tGPAR;


typedef struct tCPAR {

   UINT16 exp;
   UINT16 v_offset;
   UINT16 v_width;
   UINT16 p_offset;
   UINT16 p_width;
   FLOAT32  r4F0_max;
   FLOAT32  r4F0_min;
   FLOAT32  r4VADmean_fac;
   FLOAT32  r4Thresh;
   UINT16 hfaswitch;
   UINT16 dctswitch;
   BYTE  atype;
   UINT16 idftswitch;

} tCPAR;


typedef struct tF0E {

  FLOAT32      r4akf[N_FFT_MAX];
  UINT16       u2akf_len;
  UINT16       u2T0_max;
  UINT16       u2T0_min;
  FLOAT32      r4F0_max;
  FLOAT32      r4F0_min;
  FLOAT32      r4Thresh;

} tF0E;


typedef struct tHAR {

  UINT16       N_HarmMax;
  FLOAT32      r4CutFreq;

} tHAR;


typedef struct tVAD {

    FLOAT32 r4MeanFaktor;

} tVAD;



typedef struct tFade {

  UINT16  u2wBinSta;
  UINT16  u2wBinSto;
  UINT16  u2wlen;
  FLOAT32 *pr4win;

} tFade;



#define MAX_WIDTH 20


typedef struct tSYN {

  INT16  exp;
  FLOAT32  r4win[MAX_WIDTH][2*MAX_WIDTH -   1];
  tFade strFad[2];

} tSYN;


typedef struct tHFA {

  UINT16 u4A;

  FLOAT64     r4x_in[N_FFT_MAX];
  tCPAR       strCPAR;
  tGPAR       strGPAR;
  tF0E        strF0E;
  tHAR        strHAR;
  tVAD        strVAD;
  tSYN        strSYN;
  MLP_CNVC_TYPE strMF;
} tHFA;

//}}CGEN_HEADERCODE

// Class CHFAproc

class CHFAproc : public CFBAproc 
{

typedef CFBAproc inherited;
typedef CHFAproc thisclass;

//{{CGEN_FRIENDS
//}}CGEN_FRIENDS
public:
	CHFAproc(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CHFAproc();

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
	static  CHFAproc* CreateInstance(const char* lpName);
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

// Taken from 'hfa_work.cpp'
	public: INT16 AnalyzeMatrix(CData* idFrames, CData* idReal);
	public: virtual void PrepareOutput(CData* dResult);
	protected: INT16 hfa_done(tHFA* pstrHFA);
	protected: void hfa_init(tHFA* pstrHFA);

// Taken from 'hfa_alg.c'
	private: void _hfa_structHFAinit(tHFA* pstrHFA);
	private: void _hfa_structHFAdeinit(tHFA* pstrHFA);
	private: INT16 hfa_analyze_matrix(CData* idFrames, tHFA* pstrHFA, CData* idReal, FLOAT64 nMinLog, FLOAT64 nLimit);
	private: void hfa_destroy(tHFA* pstrHFA);
	private: void hfa(tHFA* pstrHFA, tMXr* pstrSIGt, tMXr* pstrSIGf, tMXr* pstrOUT);
	private: void _hfa_F0E(tHFA* pstrHFA, tMXr* pstrSIGt, str_r4arr* pstrF0);
	private: void _hfa_F0E_postProc(str_r4arr* pstrIN, FLOAT32 r4Thresh);
	private: void akf_positiv(FLOAT32* pr4x, FLOAT32* pr4akf, UINT16 u2len);
	private: void _hfa_HAR(tHFA* pstrHFA, tMXi* pstrHIdx, str_r4arr* pstrF0);
	private: void _hfa_VAD(tHFA* pstrHFA, tMXi* pstrHIdx, tMXr* pstrSIGf, str_i2arr* pstrVP);
	private: void _hfa_SYN(tHFA* pstrHFA, tMXi* pstrHIdx, tMXr* pstrSIGf, str_i2arr* pstrVP, tMXr* pstrOUT);
	private: void _hfa_makeWindowTable(UINT32 length_window, BYTE type_of_window, FLOAT32* pr4window_table);
	private: INT32 _hfa_window(UINT32 length_window, BYTE type_of_window, FLOAT32* px_in, FLOAT64* px_out, FLOAT32* pr4window_table);
	private: BYTE _hfa_get_win_type(char * pi1Wtype);
	private: void dct_ii(FLOAT64* pr8_out);
	private: void idft(FLOAT64* pr8_out);
//}}CGEN_EXPORT

// Member variables
public:

//{{CGEN_FIELDS
	char             m_lpsAtype[50];
	INT16            m_nCoeff;
	INT16            m_nDCTswitch;
	INT16            m_nExp;
	INT16            m_nF0max;
	INT16            m_nF0min;
	INT16            m_nHFAswitch;
	FLOAT32          m_nLimit;
	INT16            m_nPOffset;
	INT16            m_nPWidth;
	FLOAT32          m_nPar1;
	FLOAT32          m_nPar10;
	FLOAT32          m_nPar2;
	FLOAT32          m_nPar3;
	FLOAT32          m_nPar4;
	FLOAT32          m_nPar5;
	FLOAT32          m_nPar6;
	FLOAT32          m_nPar7;
	FLOAT32          m_nPar8;
	FLOAT32          m_nPar9;
	tHFA*            m_lpStrHFA;
	INT16            m_nVOffset;
	INT16            m_nVWidth;
	INT16            m_nVAD;
	FLOAT32          m_nVADmeanFac;
	INT16            m_nVADthresh;
	char             m_lpsVADtype[50];
	char             m_lpsWtypefft[50];
//}}CGEN_FIELDS

//{{CGEN_OPTIONS
//}}CGEN_OPTIONS
}

;

// Scanned C (member) functions
//{{CGEN_CEXPORT

// Taken from 'hfa_work.cpp'

// Taken from 'hfa_alg.c'
//}}CGEN_CEXPORT

#endif //#ifndef __HFAPROC_H


// EOF
