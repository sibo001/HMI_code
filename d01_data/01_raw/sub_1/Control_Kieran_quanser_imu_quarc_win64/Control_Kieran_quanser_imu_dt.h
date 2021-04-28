/*
 * Control_Kieran_quanser_imu_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_extmode_svr_connected_handle),
  sizeof(intmax_t),
  sizeof(ptrdiff_t),
  sizeof(size_t),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_wide_char),
  sizeof(qthread_section_t),
  sizeof(t_text_to_speech_state),
  sizeof(t_host_remote_interface),
  sizeof(t_timeout),
  sizeof(t_card),
  sizeof(t_boolean)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_extmode_svr_connected_handle",
  "intmax_t",
  "ptrdiff_t",
  "size_t",
  "t_int64",
  "t_uint64",
  "t_wide_char",
  "qthread_section_t",
  "t_text_to_speech_state",
  "t_host_remote_interface",
  "t_timeout",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Control_Kieran_quanser_imu_B.ManualSwitch2), 0, 0, 91 },

  { (char_T *)(&Control_Kieran_quanser_imu_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_B.HostInitialize_o1), 3, 0, 81 },

  { (char_T *)(&Control_Kieran_quanser_imu_B.Compare), 8, 0, 2 }
  ,

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock), 21, 0,
    1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State), 22, 0,
    1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.SystemTimebase_PreviousTime), 24,
    0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILInitialize_AIMinimums[0]), 0, 0,
    78 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HostInitialize_ConnectedHandle),
    14, 0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_SendContex),
    23, 0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILInitialize_Card), 25, 0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILReadAnalog3_PWORK), 11, 0, 46 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILInitialize_ClockModes[0]), 6, 0,
    59 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans[0]), 7,
    0, 8 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.Integrator1_IWORK.IcNeedsLoading),
    10, 0, 32 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem), 2, 0, 20 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0]), 8, 0, 3
  },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.HILReadDigital_Buffer), 26, 0, 1 },

  { (char_T *)(&Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE), 8, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem15.IfActionSubsystem14_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem14.IfActionSubsystem14_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem3_p.IfActionSubsystem2_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem12.IfActionSubsystem2_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem6_k.IfActionSubsystem2_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem5_e.IfActionSubsystem2_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Control_Kieran_quanser_imu_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  26U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Control_Kieran_quanser_imu_P.GravityCompensationPositiveDeri), 0,
    0, 47 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HILInitialize_hardware_clocks[0]),
    6, 0, 23 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HILInitialize_analog_input_chan[0]),
    7, 0, 48 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.StopwithMessage1_message_icon), 2,
    0, 2 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.Texttospeak1_alignment), 3, 0, 2 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HILInitialize_active), 8, 0, 36 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.Out1_Y0), 0, 0, 113 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HostInitialize_SendBufferSize), 6,
    0, 3 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.ToHostFile1_Decimation), 7, 0, 6 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Rate), 2, 0, 2
  },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HostInitialize_URI), 3, 0, 396 },

  { (char_T *)(&Control_Kieran_quanser_imu_P.HostInitialize_RunClient), 8, 0, 12
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

/* [EOF] Control_Kieran_quanser_imu_dt.h */
