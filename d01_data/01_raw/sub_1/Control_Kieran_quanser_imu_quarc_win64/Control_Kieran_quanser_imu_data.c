/*
 * Control_Kieran_quanser_imu_data.c
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
#include "Control_Kieran_quanser_imu.h"
#include "Control_Kieran_quanser_imu_private.h"

/* Block parameters (auto storage) */
P_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_P = {
  1.79,                                /* Mask Parameter: GravityCompensationPositiveDeri
                                        * Referenced by: '<S6>/b =anchor_point_dis'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  4.0E+7,                              /* Mask Parameter: HILInitialize_encoder_filter_fr
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  8.0,                                 /* Mask Parameter: SecondOrderLowPassFilter_input_
                                        * Referenced by: '<S32>/wn'
                                        */
  8.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_input
                                        * Referenced by: '<S33>/wn'
                                        */
  8.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_input
                                        * Referenced by: '<S30>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter5_input
                                        * Referenced by: '<S40>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter6_input
                                        * Referenced by: '<S41>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter7_input
                                        * Referenced by: '<S42>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter8_input
                                        * Referenced by: '<S43>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter9_input
                                        * Referenced by: '<S44>/wn'
                                        */
  100.0,                               /* Mask Parameter: SecondOrderLowPassFilter1_inp_h
                                        * Referenced by: '<S37>/wn'
                                        */
  80.0,                                /* Mask Parameter: SecondOrderLowPassFilter2_inp_n
                                        * Referenced by: '<S38>/wn'
                                        */
  35.0,                                /* Mask Parameter: SecondOrderLowPassFilter3_input
                                        * Referenced by: '<S39>/wn'
                                        */
  15.0,                                /* Mask Parameter: SecondOrderLowPassFilter_inpu_o
                                        * Referenced by: '<S24>/wn'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_e
                                        * Referenced by: '<S30>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter_inpu_e
                                        * Referenced by: '<S32>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_inp_c
                                        * Referenced by: '<S33>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter5_inp_k
                                        * Referenced by: '<S40>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter6_inp_i
                                        * Referenced by: '<S41>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter7_inp_n
                                        * Referenced by: '<S42>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter8_inp_h
                                        * Referenced by: '<S43>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter9_inp_o
                                        * Referenced by: '<S44>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_inp_f
                                        * Referenced by: '<S37>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_o
                                        * Referenced by: '<S38>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter3_inp_m
                                        * Referenced by: '<S39>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter_inpu_k
                                        * Referenced by: '<S24>/zt'
                                        */
  0.2,                                 /* Mask Parameter: GravityCompensationPositiveDe_d
                                        * Referenced by: '<S6>/Gain5'
                                        */
  0.0,                                 /* Mask Parameter: GravityCompensationPositiveDe_p
                                        * Referenced by: '<S6>/Gain6'
                                        */
  4.2,                                 /* Mask Parameter: GravityCompensationPositiveDe_h
                                        * Referenced by: '<S6>/Gain2'
                                        */
  3.0,                                 /* Mask Parameter: GravityCompensationPositiveDe_a
                                        * Referenced by: '<S6>/Gain'
                                        */
  9765.625,                            /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_i
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outp_if
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  2,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  5U,                                  /* Mask Parameter: HILReadAnalog3_channels
                                        * Referenced by: '<Root>/HIL Read Analog3'
                                        */
  6U,                                  /* Mask Parameter: HILReadAnalog1_channels
                                        * Referenced by: '<Root>/HIL Read Analog1'
                                        */
  3U,                                  /* Mask Parameter: LowLvSpeedController_channels
                                        * Referenced by: '<Root>/LowLvSpeedController'
                                        */
  8U,                                  /* Mask Parameter: HILReadDigital_channels
                                        * Referenced by: '<Root>/HIL Read Digital'
                                        */
  7U,                                  /* Mask Parameter: HILReadAnalog_channels
                                        * Referenced by: '<Root>/HIL Read Analog'
                                        */

  /*  Mask Parameter: HILReadAnalog2_channels
   * Referenced by: '<Root>/HIL Read Analog2'
   */
  { 2U, 3U, 5U, 6U },
  0U,                                  /* Mask Parameter: HILReadAnalog4_channels
                                        * Referenced by: '<Root>/HIL Read Analog4'
                                        */

  /*  Mask Parameter: HILInitialize_digital_input_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 2U, 8U },

  /*  Mask Parameter: HILInitialize_digital_output_ch
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 48U, 1U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: StopwithMessage1_message_icon
                                        * Referenced by: '<S27>/Show Message on Host'
                                        */
  3,                                   /* Mask Parameter: StopwithMessage_message_icon
                                        * Referenced by: '<S26>/Show Message on Host'
                                        */
  2U,                                  /* Mask Parameter: Texttospeak1_alignment
                                        * Referenced by: '<Root>/Text to speak1'
                                        */
  1U,                                  /* Mask Parameter: Texttospeak1_display_mode
                                        * Referenced by: '<Root>/Text to speak1'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HostSpeechSynthesis1_interrupt
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_out_fp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_i
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_lc
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Out2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  0.006,                               /* Expression: 0.006
                                        * Referenced by: '<S4>/Constant1'
                                        */
  0.42,                                /* Expression: 0.42
                                        * Referenced by: '<S4>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Constant3'
                                        */
  -0.01,                               /* Expression: -0.01
                                        * Referenced by: '<S35>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Constant'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S25>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Left'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Right '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Off'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/On'
                                        */
  250.0,                               /* Expression: 250
                                        * Referenced by: '<Root>/Constant6'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/Gain4'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Gain2'
                                        */
  2.6,                                 /* Expression: 2.6
                                        * Referenced by: '<Root>/Constant5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Wire on other side1'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S41>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S44>/x0'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S23>/Gain3'
                                        */
  8.75,                                /* Expression: 8.75
                                        * Referenced by: '<S25>/Constant'
                                        */
  1.6,                                 /* Expression: 1.6
                                        * Referenced by: '<Root>/Left3'
                                        */
  45.5,                                /* Expression: 45.5
                                        * Referenced by: '<Root>/Left1'
                                        */
  0.036,                               /* Expression: 0.036
                                        * Referenced by: '<S6>/forearm_m'
                                        */
  0.10920000000000002,                 /* Expression: 0.273*0.4
                                        * Referenced by: '<S6>/forearm_lc'
                                        */
  0.6,                                 /* Expression: 0.6
                                        * Referenced by: '<S6>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Left2'
                                        */
  0.273,                               /* Expression: 0.273
                                        * Referenced by: '<S6>/forearmL'
                                        */
  0.6,                                 /* Expression: .6
                                        * Referenced by: '<S6>/Gain3'
                                        */
  9.81,                                /* Expression: 9.81
                                        * Referenced by: '<S6>/g'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S29>/Gain2'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S40>/x0'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S24>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S42>/x0'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S34>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain1'
                                        */
  0.042,                               /* Expression: 0.042
                                        * Referenced by: '<S6>/a = half_width'
                                        */
  0.15249869901412275,                 /* Expression: sqrt(0.042^2+((H*0.273*0.6)/2)^2)
                                        * Referenced by: '<S6>/half_width1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Integrator2'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S25>/Constant1'
                                        */
  0.0,                                 /* Computed Parameter: Merge6_InitialOutput
                                        * Referenced by: '<S23>/Merge6'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S28>/Merge1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Wire on other side'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S43>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S37>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S38>/x0'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S39>/x0'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<Root>/Left4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude3'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S30>/x0'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<Root>/Merge'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Constant'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S1>/offset4'
                                        */
  78.8,                                /* Expression: 78.8
                                        * Referenced by: '<S1>/Gain5'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<S1>/offset5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S30>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/Integrator2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S32>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S32>/x0'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S33>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S33>/x0'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S40>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Integrator2'
                                        */
  12.2938,                             /* Expression: 12.2938
                                        * Referenced by: '<Root>/val1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S41>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S41>/Integrator2'
                                        */
  54.3367,                             /* Expression: 54.3367
                                        * Referenced by: '<Root>/val2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S42>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Integrator2'
                                        */
  70.344,                              /* Expression: 70.344
                                        * Referenced by: '<Root>/val3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S43>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Integrator2'
                                        */
  251.505,                             /* Expression: 251.505
                                        * Referenced by: '<Root>/val4'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S44>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Integrator2'
                                        */
  50.3286,                             /* Expression: 50.3286
                                        * Referenced by: '<Root>/val5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S37>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Integrator2'
                                        */
  -32.4027,                            /* Expression: -32.4027
                                        * Referenced by: '<Root>/val6'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S38>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Integrator2'
                                        */
  -1.4943,                             /* Expression: -1.4943
                                        * Referenced by: '<Root>/val7'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S39>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Integrator2'
                                        */
  -252.5156,                           /* Expression: -252.5156
                                        * Referenced by: '<Root>/val8'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S24>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Integrator2'
                                        */
  738136.64345092594,                  /* Expression: now
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.1574074074074073E-5,               /* Expression: 1/86400
                                        * Referenced by: '<Root>/tos'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Amplitude4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S52>/Constant'
                                        */
  1000,                                /* Computed Parameter: HostInitialize_SendBufferSize
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  1000,                                /* Computed Parameter: HostInitialize_ReceiveBufferSiz
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  0,                                   /* Computed Parameter: HostInitialize_ThreadPriority
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile1_Decimation
                                        * Referenced by: '<Root>/To Host File1'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile2_Decimation
                                        * Referenced by: '<Root>/To Host File2'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile5_Decimation
                                        * Referenced by: '<Root>/To Host File5'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile3_Decimation
                                        * Referenced by: '<Root>/To Host File3'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile4_Decimation
                                        * Referenced by: '<Root>/To Host File4'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile6_Decimation
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  -5,                                  /* Computed Parameter: HostSpeechSynthesis1_Rate
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  8,                                   /* Computed Parameter: HostSpeechSynthesis1_Pitch
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  0U,                                  /* Expression: uri_argument
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */

  /*  Expression: string_list_arg
   * Referenced by: '<Root>/String Select'
   */
  { 32U, 115U, 116U, 111U, 112U, 33U, 0U, 32U, 115U, 116U, 97U, 114U, 116U, 33U,
    0U },

  /*  Expression: default_string_arg
   * Referenced by: '<Root>/String Select'
   */
  { 85U, 110U, 114U, 101U, 99U, 111U, 103U, 110U, 105U, 122U, 101U, 100U, 32U,
    99U, 111U, 109U, 109U, 97U, 110U, 100U, 0U },
  2U,                                  /* Computed Parameter: HostSpeechSynthesis1_Gender
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  4U,                                  /* Computed Parameter: HostSpeechSynthesis1_Age
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  100U,                                /* Computed Parameter: HostSpeechSynthesis1_Volume
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  3U,                                  /* Computed Parameter: HostSpeechSynthesis1_OutputMode
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File1'
   */
  { 100U, 97U, 116U, 97U, 47U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    112U, 97U, 114U, 97U, 109U, 101U, 116U, 101U, 114U, 115U, 92U, 112U, 97U,
    114U, 97U, 109U, 101U, 116U, 101U, 114U, 115U, 45U, 49U, 49U, 45U, 68U, 101U,
    99U, 45U, 50U, 48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U, 52U,
    46U, 109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File1'
   */
  { 112U, 97U, 114U, 97U, 109U, 101U, 116U, 101U, 114U, 115U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile1_FileFormat
                                        * Referenced by: '<Root>/To Host File1'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File2'
   */
  { 100U, 97U, 116U, 97U, 92U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    105U, 109U, 117U, 92U, 105U, 109U, 117U, 45U, 49U, 49U, 45U, 68U, 101U, 99U,
    45U, 50U, 48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U, 52U, 46U,
    109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File2'
   */
  { 105U, 109U, 117U, 115U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile2_FileFormat
                                        * Referenced by: '<Root>/To Host File2'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File5'
   */
  { 100U, 97U, 116U, 97U, 92U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    104U, 119U, 92U, 104U, 119U, 45U, 49U, 49U, 45U, 68U, 101U, 99U, 45U, 50U,
    48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U, 52U, 46U, 109U, 97U,
    116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File5'
   */
  { 104U, 101U, 105U, 103U, 104U, 116U, 95U, 119U, 101U, 105U, 103U, 104U, 116U,
    0U },
  1U,                                  /* Computed Parameter: ToHostFile5_FileFormat
                                        * Referenced by: '<Root>/To Host File5'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File3'
   */
  { 100U, 97U, 116U, 97U, 92U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    116U, 105U, 109U, 101U, 92U, 116U, 105U, 109U, 101U, 45U, 49U, 49U, 45U, 68U,
    101U, 99U, 45U, 50U, 48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U,
    52U, 46U, 109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File3'
   */
  { 100U, 97U, 116U, 97U, 95U, 116U, 105U, 109U, 101U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile3_FileFormat
                                        * Referenced by: '<Root>/To Host File3'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File4'
   */
  { 100U, 97U, 116U, 97U, 92U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    101U, 109U, 103U, 92U, 101U, 109U, 103U, 45U, 49U, 49U, 45U, 68U, 101U, 99U,
    45U, 50U, 48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U, 52U, 46U,
    109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File4'
   */
  { 101U, 109U, 103U, 115U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile4_FileFormat
                                        * Referenced by: '<Root>/To Host File4'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<Root>/To Host File6'
   */
  { 100U, 97U, 116U, 97U, 92U, 115U, 117U, 98U, 106U, 101U, 99U, 116U, 49U, 92U,
    109U, 109U, 114U, 92U, 109U, 109U, 114U, 45U, 49U, 49U, 45U, 68U, 101U, 99U,
    45U, 50U, 48U, 50U, 48U, 45U, 49U, 53U, 45U, 50U, 54U, 45U, 51U, 52U, 46U,
    109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File6'
   */
  { 109U, 109U, 114U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile6_FileFormat
                                        * Referenced by: '<Root>/To Host File6'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  1,                                   /* Computed Parameter: HostInitialize_RunClient
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  0,                                   /* Computed Parameter: HostInitialize_UseWindow
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  1,                                   /* Computed Parameter: HostInitialize_Active
                                        * Referenced by: '<Root>/Host Initialize'
                                        */
  0,                                   /* Computed Parameter: SystemTimebase_StopOnOverrun
                                        * Referenced by: '<Root>/System Timebase'
                                        */
  1,                                   /* Computed Parameter: HILReadAnalog3_Active
                                        * Referenced by: '<Root>/HIL Read Analog3'
                                        */
  1,                                   /* Computed Parameter: HILReadAnalog1_Active
                                        * Referenced by: '<Root>/HIL Read Analog1'
                                        */
  0,                                   /* Computed Parameter: LowLvSpeedController_Active
                                        * Referenced by: '<Root>/LowLvSpeedController'
                                        */
  1,                                   /* Computed Parameter: HILReadDigital_Active
                                        * Referenced by: '<Root>/HIL Read Digital'
                                        */
  1,                                   /* Computed Parameter: HostSpeechSynthesis1_Enabled
                                        * Referenced by: '<Root>/Host Speech Synthesis1'
                                        */
  1,                                   /* Computed Parameter: HILReadAnalog_Active
                                        * Referenced by: '<Root>/HIL Read Analog'
                                        */
  1,                                   /* Computed Parameter: HILReadAnalog2_Active
                                        * Referenced by: '<Root>/HIL Read Analog2'
                                        */
  1                                    /* Computed Parameter: HILReadAnalog4_Active
                                        * Referenced by: '<Root>/HIL Read Analog4'
                                        */
};
