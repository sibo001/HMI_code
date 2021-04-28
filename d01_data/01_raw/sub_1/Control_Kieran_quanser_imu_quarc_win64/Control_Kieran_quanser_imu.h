/*
 * Control_Kieran_quanser_imu.h
 *
 * Code generation for model "Control_Kieran_quanser_imu".
 *
 * Model version              : 1.713
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Dec 11 15:26:36 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Control_Kieran_quanser_imu_h_
#define RTW_HEADER_Control_Kieran_quanser_imu_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef Control_Kieran_quanser_imu_COMMON_INCLUDES_
# define Control_Kieran_quanser_imu_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_string.h"
#include "quanser_host.h"
#include "extmode_support.h"
#include "quanser_timer.h"
#include "quanser_thread.h"
#include "quanser_memory.h"
#include "string_select_block.h"
#include "quanser_stream.h"
#include "quanser_utf.h"
#include "quanser_section.h"
#include "quanser_packing.h"
#include "quanser_host_text_to_speech.h"
#include "quanser_types.h"
#include "quanser_extern.h"
#endif                                 /* Control_Kieran_quanser_imu_COMMON_INCLUDES_ */

#include "Control_Kieran_quanser_imu_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>/If Action Subsystem2' */
typedef struct {
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<Root>/If Action Subsystem2' */
} DW_IfActionSubsystem2_Control_T;

/* Block states (auto storage) for system '<S29>/If Action Subsystem14' */
typedef struct {
  int8_T IfActionSubsystem14_SubsysRanBC;/* '<S29>/If Action Subsystem14' */
} DW_IfActionSubsystem14_Contro_T;

/* Block signals (auto storage) */
typedef struct {
  real_T ManualSwitch2;                /* '<Root>/Manual Switch2' */
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  real_T HILReadAnalog3;               /* '<Root>/HIL Read Analog3' */
  real_T Subtract1;                    /* '<Root>/Subtract1' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T HILReadAnalog1;               /* '<Root>/HIL Read Analog1' */
  real_T Merge2;                       /* '<Root>/Merge2' */
  real_T Wireonotherside1;             /* '<Root>/Wire on other side1' */
  real_T x0;                           /* '<S41>/x0' */
  real_T Integrator1;                  /* '<S41>/Integrator1' */
  real_T x0_m;                         /* '<S44>/x0' */
  real_T Integrator1_k;                /* '<S44>/Integrator1' */
  real_T Left3;                        /* '<Root>/Left3' */
  real_T Left1;                        /* '<Root>/Left1' */
  real_T Left2;                        /* '<Root>/Left2' */
  real_T g;                            /* '<S6>/g' */
  real_T Product;                      /* '<S6>/Product' */
  real_T TrigonometricFunction;        /* '<S29>/Trigonometric Function' */
  real_T x0_k;                         /* '<S40>/x0' */
  real_T Integrator1_l;                /* '<S40>/Integrator1' */
  real_T Product_a;                    /* '<S29>/Product' */
  real_T tau_g;                        /* '<S6>/times' */
  real_T x0_a;                         /* '<S24>/x0' */
  real_T Integrator1_f;                /* '<S24>/Integrator1' */
  real_T x0_f;                         /* '<S42>/x0' */
  real_T Integrator1_lw;               /* '<S42>/Integrator1' */
  real_T Merge3;                       /* '<S34>/Merge3' */
  real_T TrigonometricFunction1;       /* '<S6>/Trigonometric Function1' */
  real_T tau_a;                        /* '<S6>/Divide' */
  real_T Sum;                          /* '<S6>/Sum' */
  real_T Product1;                     /* '<S32>/Product1' */
  real_T Product1_o;                   /* '<S33>/Product1' */
  real_T Sum4;                         /* '<S6>/Sum4' */
  real_T Switch2;                      /* '<S51>/Switch2' */
  real_T Merge6;                       /* '<S23>/Merge6' */
  real_T Merge3_e;                     /* '<S22>/Merge3' */
  real_T Merge1;                       /* '<S28>/Merge1' */
  real_T Wireonotherside;              /* '<Root>/Wire on other side' */
  real_T x0_d;                         /* '<S43>/x0' */
  real_T Integrator1_kv;               /* '<S43>/Integrator1' */
  real_T x0_h;                         /* '<S37>/x0' */
  real_T Integrator1_e;                /* '<S37>/Integrator1' */
  real_T x0_i;                         /* '<S38>/x0' */
  real_T Integrator1_a;                /* '<S38>/Integrator1' */
  real_T x0_hd;                        /* '<S39>/x0' */
  real_T Integrator1_i;                /* '<S39>/Integrator1' */
  real_T Subtract2;                    /* '<Root>/Subtract2' */
  real_T MathFunction;                 /* '<Root>/Math Function' */
  real_T Amplitude3;                   /* '<Root>/Amplitude3' */
  real_T x0_fw;                        /* '<S30>/x0' */
  real_T Merge;                        /* '<Root>/Merge' */
  real_T Sum6;                         /* '<S1>/Sum6' */
  real_T Product_l;                    /* '<S30>/Product' */
  real_T Product1_i;                   /* '<S30>/Product1' */
  real_T x0_me;                        /* '<S32>/x0' */
  real_T Product_a3;                   /* '<S32>/Product' */
  real_T x0_fwo;                       /* '<S33>/x0' */
  real_T Product_aq;                   /* '<S33>/Product' */
  real_T Product_m;                    /* '<S40>/Product' */
  real_T Product1_g;                   /* '<S40>/Product1' */
  real_T Product_g;                    /* '<S41>/Product' */
  real_T Product1_j;                   /* '<S41>/Product1' */
  real_T Product_d;                    /* '<S42>/Product' */
  real_T Product1_k;                   /* '<S42>/Product1' */
  real_T Product_ac;                   /* '<S43>/Product' */
  real_T Product1_l;                   /* '<S43>/Product1' */
  real_T Product_gt;                   /* '<S44>/Product' */
  real_T Product1_lt;                  /* '<S44>/Product1' */
  real_T Product_ll;                   /* '<S37>/Product' */
  real_T Product1_l0;                  /* '<S37>/Product1' */
  real_T Product_p;                    /* '<S38>/Product' */
  real_T Product1_lk;                  /* '<S38>/Product1' */
  real_T Product_b;                    /* '<S39>/Product' */
  real_T Product1_c;                   /* '<S39>/Product1' */
  real_T Product_lj;                   /* '<S24>/Product' */
  real_T Product1_oj;                  /* '<S24>/Product1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Flexor;                       /* '<Root>/HIL Read Analog2' */
  real_T Extensor;                     /* '<Root>/HIL Read Analog2' */
  real_T HILReadAnalog2_o3;            /* '<Root>/HIL Read Analog2' */
  real_T HILReadAnalog2_o4;            /* '<Root>/HIL Read Analog2' */
  real_T Amplitude4;                   /* '<Root>/Amplitude4' */
  real_T HILReadAnalog4;               /* '<Root>/HIL Read Analog4' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T ManualSwitch1;                /* '<Root>/Manual Switch1' */
  real_T Merge1_i;                     /* '<Root>/Merge1' */
  real_T Sum_f;                        /* '<S4>/Sum' */
  real_T Product_c;                    /* '<S4>/Product' */
  real_T OutportBufferForOut2;         /* '<S4>/If Action Subsystem' */
  real_T In1;                          /* '<S31>/In1' */
  int32_T HostInitialize_o2;           /* '<Root>/Host Initialize' */
  uint8_T HostInitialize_o1;           /* '<Root>/Host Initialize' */
  uint8_T HostSpeechSynthesis1_o2[80]; /* '<Root>/Host Speech Synthesis1' */
  boolean_T Compare;                   /* '<S2>/Compare' */
  boolean_T HostSpeechSynthesis1_o1;   /* '<Root>/Host Speech Synthesis1' */
} B_Control_Kieran_quanser_imu_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  qthread_section_t HostSpeechSynthesis1_Lock;/* '<Root>/Host Speech Synthesis1' */
  t_text_to_speech_state HostSpeechSynthesis1_State;/* '<Root>/Host Speech Synthesis1' */
  t_timeout SystemTimebase_PreviousTime;/* '<Root>/System Timebase' */
  real_T HILInitialize_AIMinimums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[8];  /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[8];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[8];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POValues[8];    /* '<Root>/HIL Initialize' */
  real_T HILReadAnalog3_Buffer;        /* '<Root>/HIL Read Analog3' */
  real_T HILReadAnalog1_Buffer;        /* '<Root>/HIL Read Analog1' */
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  real_T HILReadAnalog_Buffer;         /* '<Root>/HIL Read Analog' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative' */
  real_T HILReadAnalog2_Buffer[4];     /* '<Root>/HIL Read Analog2' */
  real_T HILReadAnalog4_Buffer;        /* '<Root>/HIL Read Analog4' */
  real_T Memory_PreviousInput;         /* '<S4>/Memory' */
  t_extmode_svr_connected_handle HostInitialize_ConnectedHandle;/* '<Root>/Host Initialize' */
  t_host_remote_interface HostSpeechSynthesis1_SendContex;/* '<Root>/Host Speech Synthesis1' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILReadAnalog3_PWORK;          /* '<Root>/HIL Read Analog3' */
  void *HILReadAnalog1_PWORK;          /* '<Root>/HIL Read Analog1' */
  void *LowLvSpeedController_PWORK;    /* '<Root>/LowLvSpeedController' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<Root>/Scope12' */

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     /* '<Root>/Scope13' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<Root>/Scope14' */

  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<Root>/Scope15' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<Root>/Scope17' */

  void *HILReadDigital_PWORK;          /* '<Root>/HIL Read Digital' */
  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<Root>/Scope18' */

  struct {
    void *StringTable;
  } StringSelect_PWORK;                /* '<Root>/String Select' */

  struct {
    void *LoggedData;
  } Scope20_PWORK;                     /* '<Root>/Scope20' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<Root>/Scope8' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  void *ToHostFile1_PWORK;             /* '<Root>/To Host File1' */
  void *ToHostFile2_PWORK;             /* '<Root>/To Host File2' */
  void *ToHostFile5_PWORK;             /* '<Root>/To Host File5' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  void *HILReadAnalog_PWORK;           /* '<Root>/HIL Read Analog' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_k;                    /* '<S6>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_i;                    /* '<S6>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S12>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;                    /* '<S12>/Scope1' */

  struct {
    void *LoggedData;
  } Scope14_PWORK_i;                   /* '<S29>/Scope14' */

  void *ToHostFile3_PWORK;             /* '<Root>/To Host File3' */
  void *HILReadAnalog2_PWORK;          /* '<Root>/HIL Read Analog2' */
  void *HILReadAnalog4_PWORK;          /* '<Root>/HIL Read Analog4' */
  struct {
    void *LoggedData;
  } Scope2_PWORK_d;                    /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope21_PWORK;                     /* '<Root>/Scope21' */

  struct {
    void *LoggedData;
  } Scope22_PWORK;                     /* '<Root>/Scope22' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  void *ToHostFile4_PWORK;             /* '<Root>/To Host File4' */
  void *ToHostFile6_PWORK;             /* '<Root>/To Host File6' */
  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_mi;                   /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_dt;                   /* '<S4>/Scope2' */

  int32_T HILInitialize_ClockModes[17];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_DOStates[2];   /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[8];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[8];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[8];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[8];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[8];/* '<Root>/HIL Initialize' */
  uint32_T HILInitialize_POSortedChans[8];/* '<Root>/HIL Initialize' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S41>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_m;               /* '<S44>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_j;               /* '<S40>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_i;               /* '<S24>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_k;               /* '<S42>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_c;               /* '<S43>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_l;               /* '<S37>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_ct;              /* '<S38>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_o;               /* '<S39>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_n;               /* '<S30>/Integrator1' */

  int_T Texttospeak1_IWORK[2];         /* '<Root>/Text to speak1' */
  int_T ToHostFile1_IWORK[3];          /* '<Root>/To Host File1' */
  int_T ToHostFile2_IWORK[3];          /* '<Root>/To Host File2' */
  int_T ToHostFile5_IWORK[3];          /* '<Root>/To Host File5' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_g;               /* '<S32>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_b;               /* '<S33>/Integrator1' */

  int_T ToHostFile3_IWORK[3];          /* '<Root>/To Host File3' */
  int_T ToHostFile4_IWORK[3];          /* '<Root>/To Host File4' */
  int_T ToHostFile6_IWORK[3];          /* '<Root>/To Host File6' */
  int8_T If1_ActiveSubsystem;          /* '<Root>/If1' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<Root>/If Action Subsystem3' */
  int8_T If7_ActiveSubsystem;          /* '<S29>/If7' */
  int8_T If2_ActiveSubsystem;          /* '<S34>/If2' */
  int8_T IfActionSubsystem5_SubsysRanBC;/* '<S34>/If Action Subsystem5' */
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S34>/If Action Subsystem6' */
  int8_T If5_ActiveSubsystem;          /* '<S23>/If5' */
  int8_T IfActionSubsystem13_SubsysRanBC;/* '<S23>/If Action Subsystem13' */
  int8_T If2_ActiveSubsystem_c;        /* '<S22>/If2' */
  int8_T If1_ActiveSubsystem_e;        /* '<S28>/If1' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S28>/If Action Subsystem2' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<Root>/Enabled Subsystem' */
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T If_end_signal_ActiveSubsystem;/* '<Root>/If_end_signal' */
  int8_T Outputs1_SubsysRanBC;         /* '<Root>/Outputs1' */
  int8_T Outputs2_SubsysRanBC;         /* '<Root>/Outputs2' */
  int8_T If_ActiveSubsystem_m;         /* '<S4>/If' */
  int8_T IfActionSubsystem_SubsysRanBC_o;/* '<S4>/If Action Subsystem' */
  boolean_T HILInitialize_DOBits[2];   /* '<Root>/HIL Initialize' */
  boolean_T HostSpeechSynthesis1_PreviousSt;/* '<Root>/Host Speech Synthesis1' */
  t_boolean HILReadDigital_Buffer;     /* '<Root>/HIL Read Digital' */
  boolean_T EnabledSubsystem_MODE;     /* '<Root>/Enabled Subsystem' */
  DW_IfActionSubsystem14_Contro_T IfActionSubsystem15;/* '<S29>/If Action Subsystem15' */
  DW_IfActionSubsystem14_Contro_T IfActionSubsystem14;/* '<S29>/If Action Subsystem14' */
  DW_IfActionSubsystem2_Control_T IfActionSubsystem3_p;/* '<S28>/If Action Subsystem3' */
  DW_IfActionSubsystem2_Control_T IfActionSubsystem12;/* '<S23>/If Action Subsystem12' */
  DW_IfActionSubsystem2_Control_T IfActionSubsystem6_k;/* '<S22>/If Action Subsystem6' */
  DW_IfActionSubsystem2_Control_T IfActionSubsystem5_e;/* '<S22>/If Action Subsystem5' */
  DW_IfActionSubsystem2_Control_T IfActionSubsystem2;/* '<Root>/If Action Subsystem2' */
} DW_Control_Kieran_quanser_imu_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S41>/Integrator1' */
  real_T Integrator1_CSTATE_b;         /* '<S44>/Integrator1' */
  real_T Integrator1_CSTATE_j;         /* '<S40>/Integrator1' */
  real_T Integrator1_CSTATE_k;         /* '<S24>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S42>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S32>/Integrator2' */
  real_T Integrator2_CSTATE_n;         /* '<S33>/Integrator2' */
  real_T Integrator1_CSTATE_nw;        /* '<S43>/Integrator1' */
  real_T Integrator1_CSTATE_bp;        /* '<S37>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S38>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S39>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S30>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S30>/Integrator2' */
  real_T Integrator1_CSTATE_nf;        /* '<S32>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S33>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S40>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S41>/Integrator2' */
  real_T Integrator2_CSTATE_fb;        /* '<S42>/Integrator2' */
  real_T Integrator2_CSTATE_b;         /* '<S43>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S44>/Integrator2' */
  real_T Integrator2_CSTATE_bl;        /* '<S37>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S38>/Integrator2' */
  real_T Integrator2_CSTATE_d;         /* '<S39>/Integrator2' */
  real_T Integrator2_CSTATE_n3;        /* '<S24>/Integrator2' */
} X_Control_Kieran_quanser_imu_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S41>/Integrator1' */
  real_T Integrator1_CSTATE_b;         /* '<S44>/Integrator1' */
  real_T Integrator1_CSTATE_j;         /* '<S40>/Integrator1' */
  real_T Integrator1_CSTATE_k;         /* '<S24>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S42>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S32>/Integrator2' */
  real_T Integrator2_CSTATE_n;         /* '<S33>/Integrator2' */
  real_T Integrator1_CSTATE_nw;        /* '<S43>/Integrator1' */
  real_T Integrator1_CSTATE_bp;        /* '<S37>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S38>/Integrator1' */
  real_T Integrator1_CSTATE_h;         /* '<S39>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S30>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S30>/Integrator2' */
  real_T Integrator1_CSTATE_nf;        /* '<S32>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S33>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S40>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S41>/Integrator2' */
  real_T Integrator2_CSTATE_fb;        /* '<S42>/Integrator2' */
  real_T Integrator2_CSTATE_b;         /* '<S43>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S44>/Integrator2' */
  real_T Integrator2_CSTATE_bl;        /* '<S37>/Integrator2' */
  real_T Integrator2_CSTATE_o;         /* '<S38>/Integrator2' */
  real_T Integrator2_CSTATE_d;         /* '<S39>/Integrator2' */
  real_T Integrator2_CSTATE_n3;        /* '<S24>/Integrator2' */
} XDot_Control_Kieran_quanser_i_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S41>/Integrator1' */
  boolean_T Integrator1_CSTATE_b;      /* '<S44>/Integrator1' */
  boolean_T Integrator1_CSTATE_j;      /* '<S40>/Integrator1' */
  boolean_T Integrator1_CSTATE_k;      /* '<S24>/Integrator1' */
  boolean_T Integrator1_CSTATE_n;      /* '<S42>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S32>/Integrator2' */
  boolean_T Integrator2_CSTATE_n;      /* '<S33>/Integrator2' */
  boolean_T Integrator1_CSTATE_nw;     /* '<S43>/Integrator1' */
  boolean_T Integrator1_CSTATE_bp;     /* '<S37>/Integrator1' */
  boolean_T Integrator1_CSTATE_i;      /* '<S38>/Integrator1' */
  boolean_T Integrator1_CSTATE_h;      /* '<S39>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S30>/Integrator1' */
  boolean_T Integrator2_CSTATE_e;      /* '<S30>/Integrator2' */
  boolean_T Integrator1_CSTATE_nf;     /* '<S32>/Integrator1' */
  boolean_T Integrator1_CSTATE_l;      /* '<S33>/Integrator1' */
  boolean_T Integrator2_CSTATE_a;      /* '<S40>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S41>/Integrator2' */
  boolean_T Integrator2_CSTATE_fb;     /* '<S42>/Integrator2' */
  boolean_T Integrator2_CSTATE_b;      /* '<S43>/Integrator2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S44>/Integrator2' */
  boolean_T Integrator2_CSTATE_bl;     /* '<S37>/Integrator2' */
  boolean_T Integrator2_CSTATE_o;      /* '<S38>/Integrator2' */
  boolean_T Integrator2_CSTATE_d;      /* '<S39>/Integrator2' */
  boolean_T Integrator2_CSTATE_n3;     /* '<S24>/Integrator2' */
} XDis_Control_Kieran_quanser_i_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_Control_Kieran_quanser_imu_T_ {
  real_T GravityCompensationPositiveDeri;/* Mask Parameter: GravityCompensationPositiveDeri
                                          * Referenced by: '<S6>/b =anchor_point_dis'
                                          */
  real_T HILInitialize_analog_input_maxi;/* Mask Parameter: HILInitialize_analog_input_maxi
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_input_mini;/* Mask Parameter: HILInitialize_analog_input_mini
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_max;/* Mask Parameter: HILInitialize_analog_output_max
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_min;/* Mask Parameter: HILInitialize_analog_output_min
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_encoder_filter_fr;/* Mask Parameter: HILInitialize_encoder_filter_fr
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_analog_ou;/* Mask Parameter: HILInitialize_initial_analog_ou
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T SecondOrderLowPassFilter_input_;/* Mask Parameter: SecondOrderLowPassFilter_input_
                                          * Referenced by: '<S32>/wn'
                                          */
  real_T SecondOrderLowPassFilter1_input;/* Mask Parameter: SecondOrderLowPassFilter1_input
                                          * Referenced by: '<S33>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_input;/* Mask Parameter: SecondOrderLowPassFilter2_input
                                          * Referenced by: '<S30>/wn'
                                          */
  real_T SecondOrderLowPassFilter5_input;/* Mask Parameter: SecondOrderLowPassFilter5_input
                                          * Referenced by: '<S40>/wn'
                                          */
  real_T SecondOrderLowPassFilter6_input;/* Mask Parameter: SecondOrderLowPassFilter6_input
                                          * Referenced by: '<S41>/wn'
                                          */
  real_T SecondOrderLowPassFilter7_input;/* Mask Parameter: SecondOrderLowPassFilter7_input
                                          * Referenced by: '<S42>/wn'
                                          */
  real_T SecondOrderLowPassFilter8_input;/* Mask Parameter: SecondOrderLowPassFilter8_input
                                          * Referenced by: '<S43>/wn'
                                          */
  real_T SecondOrderLowPassFilter9_input;/* Mask Parameter: SecondOrderLowPassFilter9_input
                                          * Referenced by: '<S44>/wn'
                                          */
  real_T SecondOrderLowPassFilter1_inp_h;/* Mask Parameter: SecondOrderLowPassFilter1_inp_h
                                          * Referenced by: '<S37>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_n;/* Mask Parameter: SecondOrderLowPassFilter2_inp_n
                                          * Referenced by: '<S38>/wn'
                                          */
  real_T SecondOrderLowPassFilter3_input;/* Mask Parameter: SecondOrderLowPassFilter3_input
                                          * Referenced by: '<S39>/wn'
                                          */
  real_T SecondOrderLowPassFilter_inpu_o;/* Mask Parameter: SecondOrderLowPassFilter_inpu_o
                                          * Referenced by: '<S24>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_e;/* Mask Parameter: SecondOrderLowPassFilter2_inp_e
                                          * Referenced by: '<S30>/zt'
                                          */
  real_T SecondOrderLowPassFilter_inpu_e;/* Mask Parameter: SecondOrderLowPassFilter_inpu_e
                                          * Referenced by: '<S32>/zt'
                                          */
  real_T SecondOrderLowPassFilter1_inp_c;/* Mask Parameter: SecondOrderLowPassFilter1_inp_c
                                          * Referenced by: '<S33>/zt'
                                          */
  real_T SecondOrderLowPassFilter5_inp_k;/* Mask Parameter: SecondOrderLowPassFilter5_inp_k
                                          * Referenced by: '<S40>/zt'
                                          */
  real_T SecondOrderLowPassFilter6_inp_i;/* Mask Parameter: SecondOrderLowPassFilter6_inp_i
                                          * Referenced by: '<S41>/zt'
                                          */
  real_T SecondOrderLowPassFilter7_inp_n;/* Mask Parameter: SecondOrderLowPassFilter7_inp_n
                                          * Referenced by: '<S42>/zt'
                                          */
  real_T SecondOrderLowPassFilter8_inp_h;/* Mask Parameter: SecondOrderLowPassFilter8_inp_h
                                          * Referenced by: '<S43>/zt'
                                          */
  real_T SecondOrderLowPassFilter9_inp_o;/* Mask Parameter: SecondOrderLowPassFilter9_inp_o
                                          * Referenced by: '<S44>/zt'
                                          */
  real_T SecondOrderLowPassFilter1_inp_f;/* Mask Parameter: SecondOrderLowPassFilter1_inp_f
                                          * Referenced by: '<S37>/zt'
                                          */
  real_T SecondOrderLowPassFilter2_inp_o;/* Mask Parameter: SecondOrderLowPassFilter2_inp_o
                                          * Referenced by: '<S38>/zt'
                                          */
  real_T SecondOrderLowPassFilter3_inp_m;/* Mask Parameter: SecondOrderLowPassFilter3_inp_m
                                          * Referenced by: '<S39>/zt'
                                          */
  real_T SecondOrderLowPassFilter_inpu_k;/* Mask Parameter: SecondOrderLowPassFilter_inpu_k
                                          * Referenced by: '<S24>/zt'
                                          */
  real_T GravityCompensationPositiveDe_d;/* Mask Parameter: GravityCompensationPositiveDe_d
                                          * Referenced by: '<S6>/Gain5'
                                          */
  real_T GravityCompensationPositiveDe_p;/* Mask Parameter: GravityCompensationPositiveDe_p
                                          * Referenced by: '<S6>/Gain6'
                                          */
  real_T GravityCompensationPositiveDe_h;/* Mask Parameter: GravityCompensationPositiveDe_h
                                          * Referenced by: '<S6>/Gain2'
                                          */
  real_T GravityCompensationPositiveDe_a;/* Mask Parameter: GravityCompensationPositiveDe_a
                                          * Referenced by: '<S6>/Gain'
                                          */
  real_T HILInitialize_pwm_frequency;  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_pwm_leading_deadb;/* Mask Parameter: HILInitialize_pwm_leading_deadb
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_pwm_trailing_dead;/* Mask Parameter: HILInitialize_pwm_trailing_dead
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_i;/* Mask Parameter: HILInitialize_set_other_outpu_i
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_o;/* Mask Parameter: HILInitialize_set_other_outpu_o
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outp_if;/* Mask Parameter: HILInitialize_set_other_outp_if
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_analog_o;/* Mask Parameter: HILInitialize_watchdog_analog_o
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_pwm_outp;/* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILInitialize_hardware_clocks[17];/* Mask Parameter: HILInitialize_hardware_clocks
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  int32_T HILInitialize_initial_encoder_c;/* Mask Parameter: HILInitialize_initial_encoder_c
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_alignment; /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_configuration;/* Mask Parameter: HILInitialize_pwm_configuration
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_modes;     /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_polarity;  /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  uint32_T HILInitialize_analog_input_chan[8];/* Mask Parameter: HILInitialize_analog_input_chan
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_analog_output_cha[8];/* Mask Parameter: HILInitialize_analog_output_cha
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILReadAnalog3_channels;    /* Mask Parameter: HILReadAnalog3_channels
                                        * Referenced by: '<Root>/HIL Read Analog3'
                                        */
  uint32_T HILReadAnalog1_channels;    /* Mask Parameter: HILReadAnalog1_channels
                                        * Referenced by: '<Root>/HIL Read Analog1'
                                        */
  uint32_T LowLvSpeedController_channels;/* Mask Parameter: LowLvSpeedController_channels
                                          * Referenced by: '<Root>/LowLvSpeedController'
                                          */
  uint32_T HILReadDigital_channels;    /* Mask Parameter: HILReadDigital_channels
                                        * Referenced by: '<Root>/HIL Read Digital'
                                        */
  uint32_T HILReadAnalog_channels;     /* Mask Parameter: HILReadAnalog_channels
                                        * Referenced by: '<Root>/HIL Read Analog'
                                        */
  uint32_T HILReadAnalog2_channels[4]; /* Mask Parameter: HILReadAnalog2_channels
                                        * Referenced by: '<Root>/HIL Read Analog2'
                                        */
  uint32_T HILReadAnalog4_channels;    /* Mask Parameter: HILReadAnalog4_channels
                                        * Referenced by: '<Root>/HIL Read Analog4'
                                        */
  uint32_T HILInitialize_digital_input_cha[3];/* Mask Parameter: HILInitialize_digital_input_cha
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_digital_output_ch[2];/* Mask Parameter: HILInitialize_digital_output_ch
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_encoder_channels[8];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<Root>/HIL Initialize'
                                              */
  uint32_T HILInitialize_pwm_channels[8];/* Mask Parameter: HILInitialize_pwm_channels
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int8_T StopwithMessage1_message_icon;/* Mask Parameter: StopwithMessage1_message_icon
                                        * Referenced by: '<S27>/Show Message on Host'
                                        */
  int8_T StopwithMessage_message_icon; /* Mask Parameter: StopwithMessage_message_icon
                                        * Referenced by: '<S26>/Show Message on Host'
                                        */
  uint8_T Texttospeak1_alignment;      /* Mask Parameter: Texttospeak1_alignment
                                        * Referenced by: '<Root>/Text to speak1'
                                        */
  uint8_T Texttospeak1_display_mode;   /* Mask Parameter: Texttospeak1_display_mode
                                        * Referenced by: '<Root>/Text to speak1'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out;/* Mask Parameter: HILInitialize_final_digital_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_initial_digital_o;/* Mask Parameter: HILInitialize_initial_digital_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HostSpeechSynthesis1_interrupt;/* Mask Parameter: HostSpeechSynthesis1_interrupt
                                            * Referenced by: '<Root>/Host Speech Synthesis1'
                                            */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_k;/* Mask Parameter: HILInitialize_set_analog_inpu_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_f;/* Mask Parameter: HILInitialize_set_analog_outp_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_fp;/* Mask Parameter: HILInitialize_set_analog_out_fp
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_e;/* Mask Parameter: HILInitialize_set_analog_outp_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_d;/* Mask Parameter: HILInitialize_set_analog_outp_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_k;/* Mask Parameter: HILInitialize_set_analog_outp_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_i;/* Mask Parameter: HILInitialize_set_analog_outp_i
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_k;/* Mask Parameter: HILInitialize_set_clock_frequ_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_a;/* Mask Parameter: HILInitialize_set_clock_param_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_c;/* Mask Parameter: HILInitialize_set_digital_out_c
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_p;/* Mask Parameter: HILInitialize_set_digital_out_p
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_e;/* Mask Parameter: HILInitialize_set_digital_out_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_l;/* Mask Parameter: HILInitialize_set_digital_out_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_a;/* Mask Parameter: HILInitialize_set_digital_out_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_lc;/* Mask Parameter: HILInitialize_set_digital_ou_lc
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_o;/* Mask Parameter: HILInitialize_set_encoder_cou_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_a;/* Mask Parameter: HILInitialize_set_encoder_par_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_h;/* Mask Parameter: HILInitialize_set_other_outpu_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_e;/* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_j;/* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_b;/* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__h;/* Mask Parameter: HILInitialize_set_pwm_params__h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S31>/Out1'
                                        */
  real_T Out2_Y0;                      /* Expression: 0
                                        * Referenced by: '<S4>/Out2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Constant1_Value;              /* Expression: 0.006
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 0.42
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: -0.01
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant_Value_cw;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Gain_Gain_d;                  /* Expression: pi/180
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Left_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Left'
                                        */
  real_T Right_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Right '
                                        */
  real_T Off_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/Off'
                                        */
  real_T On_Value;                     /* Expression: 1
                                        * Referenced by: '<Root>/On'
                                        */
  real_T Constant6_Value;              /* Expression: 250
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 50
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.01
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant5_Value;              /* Expression: 2.6
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Wireonotherside1_Gain;        /* Expression: -1
                                        * Referenced by: '<Root>/Wire on other side1'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S41>/x0'
                                        */
  real_T x0_Value_h;                   /* Expression: input_init
                                        * Referenced by: '<S44>/x0'
                                        */
  real_T Gain3_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S23>/Gain3'
                                        */
  real_T Constant_Value_cp;            /* Expression: 8.75
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Left3_Value;                  /* Expression: 1.6
                                        * Referenced by: '<Root>/Left3'
                                        */
  real_T Left1_Value;                  /* Expression: 45.5
                                        * Referenced by: '<Root>/Left1'
                                        */
  real_T forearm_m_Gain;               /* Expression: 0.036
                                        * Referenced by: '<S6>/forearm_m'
                                        */
  real_T forearm_lc_Gain;              /* Expression: 0.273*0.4
                                        * Referenced by: '<S6>/forearm_lc'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 0.6
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T Left2_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/Left2'
                                        */
  real_T forearmL_Gain;                /* Expression: 0.273
                                        * Referenced by: '<S6>/forearmL'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: .6
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T g_Gain;                       /* Expression: 9.81
                                        * Referenced by: '<S6>/g'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: pi/180
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T x0_Value_l;                   /* Expression: input_init
                                        * Referenced by: '<S40>/x0'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad'
                                        */
  real_T x0_Value_c;                   /* Expression: input_init
                                        * Referenced by: '<S24>/x0'
                                        */
  real_T x0_Value_e;                   /* Expression: input_init
                                        * Referenced by: '<S42>/x0'
                                        */
  real_T Gain_Gain_i;                  /* Expression: pi/180
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T ahalf_width_Value;            /* Expression: 0.042
                                        * Referenced by: '<S6>/a = half_width'
                                        */
  real_T half_width1_Value;            /* Expression: sqrt(0.042^2+((H*0.273*0.6)/2)^2)
                                        * Referenced by: '<S6>/half_width1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S32>/Integrator2'
                                        */
  real_T Integrator2_IC_m;             /* Expression: 0
                                        * Referenced by: '<S33>/Integrator2'
                                        */
  real_T Constant1_Value_m;            /* Expression: -10
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Merge6_InitialOutput;         /* Computed Parameter: Merge6_InitialOutput
                                        * Referenced by: '<S23>/Merge6'
                                        */
  real_T Merge1_InitialOutput;         /* Expression: [0]
                                        * Referenced by: '<S28>/Merge1'
                                        */
  real_T Wireonotherside_Gain;         /* Expression: -1
                                        * Referenced by: '<Root>/Wire on other side'
                                        */
  real_T x0_Value_g;                   /* Expression: input_init
                                        * Referenced by: '<S43>/x0'
                                        */
  real_T x0_Value_b;                   /* Expression: input_init
                                        * Referenced by: '<S37>/x0'
                                        */
  real_T x0_Value_p;                   /* Expression: input_init
                                        * Referenced by: '<S38>/x0'
                                        */
  real_T x0_Value_a;                   /* Expression: input_init
                                        * Referenced by: '<S39>/x0'
                                        */
  real_T Left4_Value;                  /* Expression: 180
                                        * Referenced by: '<Root>/Left4'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Amplitude3_Gain;              /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude3'
                                        */
  real_T x0_Value_cf;                  /* Expression: input_init
                                        * Referenced by: '<S30>/x0'
                                        */
  real_T Merge_InitialOutput;          /* Expression: [0]
                                        * Referenced by: '<Root>/Merge'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T offset4_Value;                /* Expression: 0.05
                                        * Referenced by: '<S1>/offset4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 78.8
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T offset5_Value;                /* Expression: 12
                                        * Referenced by: '<S1>/offset5'
                                        */
  real_T Constant_Value_e;             /* Expression: 2
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S30>/Integrator2'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T x0_Value_n;                   /* Expression: input_init
                                        * Referenced by: '<S32>/x0'
                                        */
  real_T Constant_Value_ct;            /* Expression: 2
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T x0_Value_ec;                  /* Expression: input_init
                                        * Referenced by: '<S33>/x0'
                                        */
  real_T deg2rad1_Gain;                /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad1'
                                        */
  real_T Constant_Value_mw;            /* Expression: 2
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S40>/Integrator2'
                                        */
  real_T val1_Value;                   /* Expression: 12.2938
                                        * Referenced by: '<Root>/val1'
                                        */
  real_T Constant_Value_l;             /* Expression: 2
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Integrator2_IC_c;             /* Expression: 0
                                        * Referenced by: '<S41>/Integrator2'
                                        */
  real_T val2_Value;                   /* Expression: 54.3367
                                        * Referenced by: '<Root>/val2'
                                        */
  real_T Constant_Value_de;            /* Expression: 2
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S42>/Integrator2'
                                        */
  real_T val3_Value;                   /* Expression: 70.344
                                        * Referenced by: '<Root>/val3'
                                        */
  real_T Constant_Value_mg;            /* Expression: 2
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Integrator2_IC_l;             /* Expression: 0
                                        * Referenced by: '<S43>/Integrator2'
                                        */
  real_T val4_Value;                   /* Expression: 251.505
                                        * Referenced by: '<Root>/val4'
                                        */
  real_T Constant_Value_b;             /* Expression: 2
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Integrator2_IC_i;             /* Expression: 0
                                        * Referenced by: '<S44>/Integrator2'
                                        */
  real_T val5_Value;                   /* Expression: 50.3286
                                        * Referenced by: '<Root>/val5'
                                        */
  real_T Constant_Value_h;             /* Expression: 2
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Integrator2_IC_im;            /* Expression: 0
                                        * Referenced by: '<S37>/Integrator2'
                                        */
  real_T val6_Value;                   /* Expression: -32.4027
                                        * Referenced by: '<Root>/val6'
                                        */
  real_T Constant_Value_ht;            /* Expression: 2
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Integrator2_IC_a;             /* Expression: 0
                                        * Referenced by: '<S38>/Integrator2'
                                        */
  real_T val7_Value;                   /* Expression: -1.4943
                                        * Referenced by: '<Root>/val7'
                                        */
  real_T Constant_Value_m4;            /* Expression: 2
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator2_IC_fa;            /* Expression: 0
                                        * Referenced by: '<S39>/Integrator2'
                                        */
  real_T val8_Value;                   /* Expression: -252.5156
                                        * Referenced by: '<Root>/val8'
                                        */
  real_T Constant_Value_ar;            /* Expression: 2
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Integrator2_IC_d;             /* Expression: 0
                                        * Referenced by: '<S24>/Integrator2'
                                        */
  real_T Constant_Value_o3;            /* Expression: now
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T tos_Gain;                     /* Expression: 1/86400
                                        * Referenced by: '<Root>/tos'
                                        */
  real_T Amplitude4_Gain;              /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude4'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value_l;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant_Value_ld;            /* Expression: 0
                                        * Referenced by: '<S52>/Constant'
                                        */
  int32_T HostInitialize_SendBufferSize;/* Computed Parameter: HostInitialize_SendBufferSize
                                         * Referenced by: '<Root>/Host Initialize'
                                         */
  int32_T HostInitialize_ReceiveBufferSiz;/* Computed Parameter: HostInitialize_ReceiveBufferSiz
                                           * Referenced by: '<Root>/Host Initialize'
                                           */
  int32_T HostInitialize_ThreadPriority;/* Computed Parameter: HostInitialize_ThreadPriority
                                         * Referenced by: '<Root>/Host Initialize'
                                         */
  uint32_T ToHostFile1_Decimation;     /* Computed Parameter: ToHostFile1_Decimation
                                        * Referenced by: '<Root>/To Host File1'
                                        */
  uint32_T ToHostFile2_Decimation;     /* Computed Parameter: ToHostFile2_Decimation
                                        * Referenced by: '<Root>/To Host File2'
                                        */
  uint32_T ToHostFile5_Decimation;     /* Computed Parameter: ToHostFile5_Decimation
                                        * Referenced by: '<Root>/To Host File5'
                                        */
  uint32_T ToHostFile3_Decimation;     /* Computed Parameter: ToHostFile3_Decimation
                                        * Referenced by: '<Root>/To Host File3'
                                        */
  uint32_T ToHostFile4_Decimation;     /* Computed Parameter: ToHostFile4_Decimation
                                        * Referenced by: '<Root>/To Host File4'
                                        */
  uint32_T ToHostFile6_Decimation;     /* Computed Parameter: ToHostFile6_Decimation
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  int8_T HostSpeechSynthesis1_Rate;    /* Computed Parameter: HostSpeechSynthesis1_Rate
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  int8_T HostSpeechSynthesis1_Pitch;   /* Computed Parameter: HostSpeechSynthesis1_Pitch
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  uint8_T HostInitialize_URI;          /* Expression: uri_argument
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */
  uint8_T StringSelect_Strings[15];    /* Expression: string_list_arg
                                        * Referenced by: '<Root>/String Select'
                                        */
  uint8_T StringSelect_DefaultString[21];/* Expression: default_string_arg
                                          * Referenced by: '<Root>/String Select'
                                          */
  uint8_T HostSpeechSynthesis1_Gender; /* Computed Parameter: HostSpeechSynthesis1_Gender
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  uint8_T HostSpeechSynthesis1_Age;    /* Computed Parameter: HostSpeechSynthesis1_Age
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  uint8_T HostSpeechSynthesis1_Volume; /* Computed Parameter: HostSpeechSynthesis1_Volume
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  uint8_T HostSpeechSynthesis1_OutputMode;/* Computed Parameter: HostSpeechSynthesis1_OutputMode
                                           * Referenced by: '<Root>/Host Speech Synthesis1'
                                           */
  uint8_T ToHostFile1_file_name[61];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File1'
                                        */
  uint8_T ToHostFile1_VarName[11];     /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File1'
                                        */
  uint8_T ToHostFile1_FileFormat;      /* Computed Parameter: ToHostFile1_FileFormat
                                        * Referenced by: '<Root>/To Host File1'
                                        */
  uint8_T ToHostFile2_file_name[47];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File2'
                                        */
  uint8_T ToHostFile2_VarName[5];      /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File2'
                                        */
  uint8_T ToHostFile2_FileFormat;      /* Computed Parameter: ToHostFile2_FileFormat
                                        * Referenced by: '<Root>/To Host File2'
                                        */
  uint8_T ToHostFile5_file_name[45];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File5'
                                        */
  uint8_T ToHostFile5_VarName[14];     /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File5'
                                        */
  uint8_T ToHostFile5_FileFormat;      /* Computed Parameter: ToHostFile5_FileFormat
                                        * Referenced by: '<Root>/To Host File5'
                                        */
  uint8_T ToHostFile3_file_name[49];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File3'
                                        */
  uint8_T ToHostFile3_VarName[10];     /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File3'
                                        */
  uint8_T ToHostFile3_FileFormat;      /* Computed Parameter: ToHostFile3_FileFormat
                                        * Referenced by: '<Root>/To Host File3'
                                        */
  uint8_T ToHostFile4_file_name[47];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File4'
                                        */
  uint8_T ToHostFile4_VarName[5];      /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File4'
                                        */
  uint8_T ToHostFile4_FileFormat;      /* Computed Parameter: ToHostFile4_FileFormat
                                        * Referenced by: '<Root>/To Host File4'
                                        */
  uint8_T ToHostFile6_file_name[47];   /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  uint8_T ToHostFile6_VarName[4];      /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  uint8_T ToHostFile6_FileFormat;      /* Computed Parameter: ToHostFile6_FileFormat
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  boolean_T HostInitialize_RunClient;  /* Computed Parameter: HostInitialize_RunClient
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  boolean_T HostInitialize_UseWindow;  /* Computed Parameter: HostInitialize_UseWindow
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  boolean_T HostInitialize_Active;     /* Computed Parameter: HostInitialize_Active
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  boolean_T SystemTimebase_StopOnOverrun;/* Computed Parameter: SystemTimebase_StopOnOverrun
                                          * Referenced by: '<Root>/System Timebase'
                                          */
  boolean_T HILReadAnalog3_Active;     /* Computed Parameter: HILReadAnalog3_Active
                                        * Referenced by: '<Root>/HIL Read Analog3'
                                        */
  boolean_T HILReadAnalog1_Active;     /* Computed Parameter: HILReadAnalog1_Active
                                        * Referenced by: '<Root>/HIL Read Analog1'
                                        */
  boolean_T LowLvSpeedController_Active;/* Computed Parameter: LowLvSpeedController_Active
                                         * Referenced by: '<Root>/LowLvSpeedController'
                                         */
  boolean_T HILReadDigital_Active;     /* Computed Parameter: HILReadDigital_Active
                                        * Referenced by: '<Root>/HIL Read Digital'
                                        */
  boolean_T HostSpeechSynthesis1_Enabled;/* Computed Parameter: HostSpeechSynthesis1_Enabled
                                          * Referenced by: '<Root>/Host Speech Synthesis1'
                                          */
  boolean_T HILReadAnalog_Active;      /* Computed Parameter: HILReadAnalog_Active
                                        * Referenced by: '<Root>/HIL Read Analog'
                                        */
  boolean_T HILReadAnalog2_Active;     /* Computed Parameter: HILReadAnalog2_Active
                                        * Referenced by: '<Root>/HIL Read Analog2'
                                        */
  boolean_T HILReadAnalog4_Active;     /* Computed Parameter: HILReadAnalog4_Active
                                        * Referenced by: '<Root>/HIL Read Analog4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_Kieran_quanse_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Control_Kieran_quanser_imu_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][25];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_P;

/* Block signals (auto storage) */
extern B_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_B;

/* Continuous states (auto storage) */
extern X_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_X;

/* Block states (auto storage) */
extern DW_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_DW;

/* Model entry point functions */
extern void Control_Kieran_quanser_imu_initialize(void);
extern void Control_Kieran_quanser_imu_step(void);
extern void Control_Kieran_quanser_imu_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_Kieran_quans_T *const Control_Kieran_quanser_imu_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Control_Kieran_quanser_imu'
 * '<S1>'   : 'Control_Kieran_quanser_imu/Calibration'
 * '<S2>'   : 'Control_Kieran_quanser_imu/Compare To Zero'
 * '<S3>'   : 'Control_Kieran_quanser_imu/Derivative block1'
 * '<S4>'   : 'Control_Kieran_quanser_imu/Enabled Subsystem'
 * '<S5>'   : 'Control_Kieran_quanser_imu/FromQcToRadiants'
 * '<S6>'   : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative'
 * '<S7>'   : 'Control_Kieran_quanser_imu/Highpass Filter'
 * '<S8>'   : 'Control_Kieran_quanser_imu/Highpass Filter1'
 * '<S9>'   : 'Control_Kieran_quanser_imu/Highpass Filter2'
 * '<S10>'  : 'Control_Kieran_quanser_imu/Highpass Filter3'
 * '<S11>'  : 'Control_Kieran_quanser_imu/Highpass Filter4'
 * '<S12>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1'
 * '<S13>'  : 'Control_Kieran_quanser_imu/If Action Subsystem'
 * '<S14>'  : 'Control_Kieran_quanser_imu/If Action Subsystem1'
 * '<S15>'  : 'Control_Kieran_quanser_imu/If Action Subsystem2'
 * '<S16>'  : 'Control_Kieran_quanser_imu/If Action Subsystem3'
 * '<S17>'  : 'Control_Kieran_quanser_imu/If Action Subsystem4'
 * '<S18>'  : 'Control_Kieran_quanser_imu/If Action Subsystem5'
 * '<S19>'  : 'Control_Kieran_quanser_imu/MATLAB Function'
 * '<S20>'  : 'Control_Kieran_quanser_imu/Outputs1'
 * '<S21>'  : 'Control_Kieran_quanser_imu/Outputs2'
 * '<S22>'  : 'Control_Kieran_quanser_imu/Override Joystick '
 * '<S23>'  : 'Control_Kieran_quanser_imu/Override Non Sagittal'
 * '<S24>'  : 'Control_Kieran_quanser_imu/Second-Order Low-Pass Filter'
 * '<S25>'  : 'Control_Kieran_quanser_imu/SlackPrevention '
 * '<S26>'  : 'Control_Kieran_quanser_imu/Stop with Message'
 * '<S27>'  : 'Control_Kieran_quanser_imu/Stop with Message1'
 * '<S28>'  : 'Control_Kieran_quanser_imu/angleLimit'
 * '<S29>'  : 'Control_Kieran_quanser_imu/convertsagittal'
 * '<S30>'  : 'Control_Kieran_quanser_imu/Derivative block1/Second-Order Low-Pass Filter2'
 * '<S31>'  : 'Control_Kieran_quanser_imu/Enabled Subsystem/If Action Subsystem'
 * '<S32>'  : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative/Second-Order Low-Pass Filter'
 * '<S33>'  : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative/Second-Order Low-Pass Filter1'
 * '<S34>'  : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative/Slack Prevention 2'
 * '<S35>'  : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative/Slack Prevention 2/If Action Subsystem5'
 * '<S36>'  : 'Control_Kieran_quanser_imu/Gravity Compensation + Positive Derivative/Slack Prevention 2/If Action Subsystem6'
 * '<S37>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter1'
 * '<S38>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter2'
 * '<S39>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter3'
 * '<S40>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter5'
 * '<S41>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter6'
 * '<S42>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter7'
 * '<S43>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter8'
 * '<S44>'  : 'Control_Kieran_quanser_imu/IMU Filtering 1/Second-Order Low-Pass Filter9'
 * '<S45>'  : 'Control_Kieran_quanser_imu/Override Joystick /If Action Subsystem5'
 * '<S46>'  : 'Control_Kieran_quanser_imu/Override Joystick /If Action Subsystem6'
 * '<S47>'  : 'Control_Kieran_quanser_imu/Override Non Sagittal/If Action Subsystem12'
 * '<S48>'  : 'Control_Kieran_quanser_imu/Override Non Sagittal/If Action Subsystem13'
 * '<S49>'  : 'Control_Kieran_quanser_imu/SlackPrevention /If Action Subsystem16'
 * '<S50>'  : 'Control_Kieran_quanser_imu/SlackPrevention /If Action Subsystem17'
 * '<S51>'  : 'Control_Kieran_quanser_imu/SlackPrevention /Saturation Dynamic'
 * '<S52>'  : 'Control_Kieran_quanser_imu/Stop with Message/Compare'
 * '<S53>'  : 'Control_Kieran_quanser_imu/Stop with Message1/Compare'
 * '<S54>'  : 'Control_Kieran_quanser_imu/angleLimit/If Action Subsystem2'
 * '<S55>'  : 'Control_Kieran_quanser_imu/angleLimit/If Action Subsystem3'
 * '<S56>'  : 'Control_Kieran_quanser_imu/convertsagittal/If Action Subsystem14'
 * '<S57>'  : 'Control_Kieran_quanser_imu/convertsagittal/If Action Subsystem15'
 */
#endif                                 /* RTW_HEADER_Control_Kieran_quanser_imu_h_ */
