// dLabPro class CPMproc (PMproc)
// - Header file
//
// AUTHOR : Guntram Strecha
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify pmproc.def instead.
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
#include "kzl_list.h"
#include "dlp_data.h"
#include "dlp_math.h"
//}}CGEN_END

//{{CGEN_ERRORS
#undef PM_SIGLENGTH        
#undef PM_FFTSIZE          
#define PM_SIGLENGTH         -1001
#define PM_FFTSIZE           -1002
//}}CGEN_END

// C/C++ language abstraction layer
#undef pmproc_par
#define pmproc_par CPMproc

// dLabPro/C++ language abstraction layer
#undef PMproc
#define PMproc CPMproc

//{{CGEN_DEFINE
//}}CGEN_DEFINE

#ifndef __PMPROC_H
#define __PMPROC_H

//{{CGEN_HEADERCODE
//}}CGEN_HEADERCODE

// Class CPMproc

class CPMproc : public CDlpObject 
{

typedef CDlpObject inherited;
typedef CPMproc thisclass;

//{{CGEN_FRIENDS
//}}CGEN_FRIENDS
public:
	CPMproc(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CPMproc();

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
	static  CPMproc* CreateInstance(const char* lpName);
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
	INT16 OnAnalyze();
	INT16 OnCompressPm();
	INT16 OnExpandPm();
	INT16 OnF02pm();
	INT16 OnFill();
	INT16 OnPm2f0();
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
	INT16 OnMaxChanged();
	INT16 OnMinChanged();
//}}CGEN_FCCF

// Scanned member functions
//{{CGEN_EXPORT

// Taken from 'pm_work.cpp'
	protected: INT16 Analyze(data* dSignal, data* dPM);
	public: INT16 ExpandPm(CData* idSrc, CData* idDst, INT32 n);
	public: INT16 CompressPm(CData* idSrc, CData* idDst, INT32 n);
	public: INT16 Fill(CData* idSrc, CData* idDst, INT32 n, const char* method);
	public: INT16 Pm2f0(CData* idSrc, CData* idDst, INT32 n, INT32 srate);
	public: INT16 F02pm(CData* idSrc, CData* idDst, INT32 n, INT32 srate);

// Taken from 'pm_epochdetect.cpp'
	private: INT16 Epochdetect(data* dSignal, data* dPM);
	private: INT16 ChfaFilter(FLOAT64* b, INT32 nb, FLOAT64* a, INT32 na, FLOAT64* input, INT32 nInput, FLOAT64* output, INT32 have_mem);
	private: FLOAT64 ChfaGetEnergyVoiceless(FLOAT64* samples_filt_e, INT32 nSamples);
	private: INT16 ChfaAllocTables();
	private: INT16 ChfaFreeTables();

// Taken from 'pm_chfa.cpp'
	public: INT16 Chfa(data* dSignal, data* dPM);
	private: INT16 chfa(FLOAT64* samples, INT32 nSamples, struct PeriodPM** periods, INT32* nperiods);
	private: struct topt fopt2topt(struct fopt fopt);
	private: void setfreq(FLOAT64* times, INT32 nsam, INT32 tmean);
	private: void filthigh(FLOAT64* fsam, FLOAT64* sam, INT32 nsam, struct filt filt);
	private: struct filt butterworth(FLOAT64 dt);
	private: void initfilthigh(struct filt* filt, struct topt topt);
	private: void freefilthigh(struct filt* filt);
	private: FLOAT64 gfunc(FLOAT64 x);
	private: void initfilt(struct filt* filt_r, struct filt* filt_i, struct topt topt);
	private: void freefilt(struct filt* filt_r, struct filt* filt_i, struct topt topt);
	private: void initfiltfreq(struct filt* filt, struct topt topt);
	private: void freefiltfreq(struct filt* filt, struct topt topt);
	private: void filtersignal(FLOAT64* fsam_e, FLOAT64* fsam_p, FLOAT64* sam, FLOAT64* times, INT32 nsam, struct filt* filt_r, struct filt* filt_i, FLOAT64 phase, struct topt topt);
	private: void smoothabs(FLOAT64* fsam_e, INT32 nsam);
	private: INT32 filter(FLOAT64* b, INT32 nb, FLOAT64* a, INT32 na, FLOAT64* input, INT32 nInput, FLOAT64* output, INT32 have_mem);
	private: void getfreq_diff(FLOAT64* times, FLOAT64* sam_p, INT32 nsam, struct topt topt);
	private: void getfreq_filt(FLOAT64* times, FLOAT64* sam_p, INT32 nsam, struct filt* filt, struct topt topt);
	private: FLOAT64 getmeanfreq(struct PeriodPM* periods, INT32 nperiods);
	private: FLOAT64 getperiods2(struct PeriodPM** periods, INT32* nperiods, FLOAT64* sam, FLOAT64* sam_p, char* sam_vin, INT32 nsam, struct topt topt);
	private: void getabsvoiceless(FLOAT64* abs_voiceless, FLOAT64* sam_e, INT32 nsam, struct topt topt);
	private: void markvoiced2(char* sam_v, FLOAT64* sam_e, INT32 nsam, FLOAT64 abs_voiceless, struct topt topt);
	private: void smoothvoiced(char* sam_v, INT32 nsam, struct topt topt);

// Taken from 'pm_gcida.cpp'
	public: INT16 Gcida(data* dSignal, data* dPM);

// Taken from 'pm_hybrid.cpp'
	private: INT16 Hybrid(data* dSignal, data* dPM);
	private: FLOAT64 MaximumValue(FLOAT64* a, INT32 n);
	private: FLOAT64 MinimumValue(FLOAT64* a, INT32 n);
	private: INT16 SignalNorming(FLOAT64* a, INT32 n, FLOAT64* b);
	private: INT16 MovingAverage(FLOAT64* a, INT32 n, INT32 m, FLOAT64* b);
	private: INT16 ShortTimeEnergy(FLOAT64* a, INT32 n, INT32 m, FLOAT64* b);
	private: FLOAT64 MeanValue(FLOAT64* a, INT32 n);
	private: INT16 PMConvertSumSamples(INT16* a, INT32 m, INT32* b);
	private: INT32 ExtractVoicedPM(INT32* a, INT16* b, INT32 m, INT32* c);
	private: INT32 DeleteSmallEnergyPM(FLOAT64* a, INT32 k, INT32* b, INT32 m, FLOAT64 thr, INT32* c);
	private: INT32 ShiftPMnearestNegativePeak(FLOAT64* a, INT32 nSam, INT32* b, INT32 m, FLOAT64* ener, FLOAT64 thr, INT16 n, INT32* cc, INT16* dd);
	private: INT16 ConfidenceOccurancePM(INT32* a, INT32 m, INT32* b, INT32 n, FLOAT64* c, FLOAT64* d);
	private: INT32 PMSelectConfidenceOccurance(INT32* a, FLOAT64* b, INT32 m, INT32* c);
	private: INT16 ConfidenceDistanceMinPM(INT16* a, INT32 m, INT16 n, FLOAT64* b);
	private: INT32 PMSorting(INT32* a, INT32 m, INT32* b, INT32 n, INT32* c);
	private: INT16 StatesNumberPerUnit(INT32* a, INT32* b, INT32 m, INT32* c, INT32 n, INT32* p);
	private: INT16 TransitionNumberPerUnit(INT32* a, INT32 m, INT32* b, INT32 n, INT32* c, INT32* d, INT32 k, INT32 nsam, INT32* e, INT32* f);
	private: INT32 PostprocessingPM(FLOAT64* a, INT32 sr, FLOAT64 MEn, INT32* b, INT32 n, INT32* c);
	private: INT32 AddUnvoicedPM(INT32* a, INT32 m, INT32 n, INT32 sr, INT32* b);
//}}CGEN_EXPORT

// Member variables
public:

//{{CGEN_FIELDS
	FLOAT64**        m_lpFiltBI;
	FLOAT64**        m_lpFiltBR;
	FLOAT64          m_nLevel;
	INT16            m_nMax;
	INT16            m_nMean;
	INT16            m_nMin;
	INT32            m_nSrate;
//}}CGEN_FIELDS

//{{CGEN_OPTIONS
	BOOL m_bChfa;
	BOOL m_bEpochdetect;
	BOOL m_bGcida;
	BOOL m_bHybrid;
//}}CGEN_OPTIONS
}

;

// Scanned C (member) functions
//{{CGEN_CEXPORT

// Taken from 'pm_work.cpp'

// Taken from 'pm_epochdetect.cpp'

// Taken from 'pm_chfa.cpp'

// Taken from 'pm_gcida.cpp'

// Taken from 'pm_hybrid.cpp'
//}}CGEN_CEXPORT

#endif //#ifndef __PMPROC_H


// EOF
