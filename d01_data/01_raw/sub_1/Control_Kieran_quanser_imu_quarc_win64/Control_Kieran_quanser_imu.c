/*
 * Control_Kieran_quanser_imu.c
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
#include "Control_Kieran_quanser_imu_dt.h"

/* Block signals (auto storage) */
B_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_B;

/* Continuous states */
X_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_X;

/* Block states (auto storage) */
DW_Control_Kieran_quanser_imu_T Control_Kieran_quanser_imu_DW;

/* Real-time model */
RT_MODEL_Control_Kieran_quans_T Control_Kieran_quanser_imu_M_;
RT_MODEL_Control_Kieran_quans_T *const Control_Kieran_quanser_imu_M =
  &Control_Kieran_quanser_imu_M_;

/*
 * Send data to the host peripheral (e.g. force feedback game controllers). The packet includes
 * the peripheral identifier so that the host knows to which peripheral to direct the data.
 */
t_error host_send_extmode_packet(void * context, const void * data, t_uint
  data_length)
{
  return extmode_svr_send_custom_action(EXT_MODE_ACTION_HOST_INTERFACE, data,
    data_length);
}

t_error host_extmode_svr_connected_callback(void * context)
{
  /* S-Function Block: Control_Kieran_quanser_imu/Host Speech Synthesis1 (host_speech_synthesis_block) */
  {
    if (Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Enabled) {

#pragma pack(push, 1)

      struct tag_speech_synthesis_configuration {
        t_host_command_header header;
        char driver[15];
        t_uint8 flags;                 /* see t_text_to_speech_flag enumeration */
        t_uint8 gender;                /* see t_text_to_speech_gender enumeration */
        t_uint8 age;                   /* see t_text_to_speech_age enumeration */
        t_uint8 volume;                /* volume: 0 to 100 */
        t_int8 rate;                   /* rate: -10 to 10 */
        t_int8 pitch;                  /* pitch: -10 to 10 */
        char voice[3];                 /* name of voice or language */
      } speech_synthesis_configuration = {
        { 0, HOST_COMMAND_LOAD },
        "text_to_speech",
        TEXT_TO_SPEECH_DONE | TEXT_TO_SPEECH_LANGUAGE,
        Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Gender - 1,
        Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Age - 1,
        Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Volume,
        (Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Rate),
        Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Pitch,
        "en"
      };

#pragma pack(pop)

      t_error result;
      result = host_send_extmode_packet(NULL, &speech_synthesis_configuration,
        sizeof(speech_synthesis_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
      }

      /* Store the send context (AFTER the command sent, so text to speech added BEFORE being modified in Outputs) */
      Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_SendContex = NULL;
    }
  }

  return 0;
}

t_error host_extmode_svr_disconnected_callback(void * context)
{
  return 0;
}

t_error host_extmode_svr_custom_action_callback(void * context, t_uint action,
  const void * data, t_uint data_length)
{
  if (action == EXT_MODE_ACTION_HOST_INTERFACE) {
    const t_uint16 * packet = (const t_uint16 *) data;
    t_uint16 peripheral_identifier = packet[0];
    t_uint16 buffer_size = packet[1];
    const void * buffer = &packet[2];
    switch (peripheral_identifier) {
     case 0:
      /* S-Function Block: Control_Kieran_quanser_imu/Host Speech Synthesis1 (host_speech_synthesis_block) */
      {
        t_text_to_speech_state * state = (t_text_to_speech_state *) (buffer);
        if (buffer_size >= sizeof(t_text_to_speech_state)) {
          t_error result = qthread_section_lock
            (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock);
          if (result == 0) {
            if ((state->flags & TEXT_TO_SPEECH_DONE) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_DONE;
            }

            if ((state->flags & TEXT_TO_SPEECH_BOOKMARK) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_BOOKMARK;
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.bookmark =
                state->bookmark;
            }

            if ((state->flags & TEXT_TO_SPEECH_SENTENCE) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_SENTENCE;
              memory_copy
                (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.sentence,
                 sizeof
                 (Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.sentence),
                 &state->sentence);
            }

            if ((state->flags & TEXT_TO_SPEECH_WORD) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_WORD;
              memory_copy
                (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.word,
                 sizeof
                 (Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.word),
                 &state->word);
            }

            if ((state->flags & TEXT_TO_SPEECH_PHONEME) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_PHONEME;
              memory_copy
                (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.phoneme,
                 sizeof
                 (Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.phoneme),
                 &state->phoneme);
            }

            if ((state->flags & TEXT_TO_SPEECH_VISEME) != 0) {
              Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags |=
                TEXT_TO_SPEECH_VISEME;
              memory_copy
                (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.viseme,
                 sizeof
                 (Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.viseme),
                 &state->viseme);
            }

            qthread_section_unlock
              (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock);
          }
        } else {
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M,
                            "A Host Speech Synthesis block has received an invalid packet from the host!");
        }
      }
      break;

     default:
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M,
                        "Invalid peripheral identifier received");
      break;
    }
  }

  return 0;
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 25;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Control_Kieran_quanser_imu_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<Root>/If Action Subsystem2'
 *    '<S22>/If Action Subsystem5'
 *    '<S22>/If Action Subsystem6'
 *    '<S23>/If Action Subsystem12'
 *    '<S28>/If Action Subsystem3'
 */
void Control_Kier_IfActionSubsystem2(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S15>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S29>/If Action Subsystem14'
 *    '<S29>/If Action Subsystem15'
 */
void Control_Kie_IfActionSubsystem14(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S56>/In1' */
  *rty_Out1 = rtu_In1;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

/* Model step function */
void Control_Kieran_quanser_imu_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge8;
  real_T rtb_Integrator1;
  real_T rtb_Clock;
  real_T rtb_Gain1;
  real_T rtb_Sum1_f;
  real_T rtb_HILReadAnalog;
  int32_T rtb_HostSpeechSynthesis1_o3;
  uint8_T rtb_StringSelect[21];
  if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    /* set solver stop time */
    if (!(Control_Kieran_quanser_imu_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Control_Kieran_quanser_imu_M->solverInfo,
                            ((Control_Kieran_quanser_imu_M->Timing.clockTickH0 +
        1) * Control_Kieran_quanser_imu_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Control_Kieran_quanser_imu_M->solverInfo,
                            ((Control_Kieran_quanser_imu_M->Timing.clockTick0 +
        1) * Control_Kieran_quanser_imu_M->Timing.stepSize0 +
        Control_Kieran_quanser_imu_M->Timing.clockTickH0 *
        Control_Kieran_quanser_imu_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_M->Timing.t[0] = rtsiGetT
      (&Control_Kieran_quanser_imu_M->solverInfo);
  }

  {
    real_T *lastU;
    int8_T rtAction;
    real_T rtb_TrigonometricFunction1;
    real_T rtb_Integrator2_g;
    real_T rtb_Gain_o;
    real_T rtb_Integrator2;
    int8_T rtPrevAction;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC_o);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.EnabledSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem5_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem6_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem3_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Control_Kieran_quanser_imu_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.Outputs1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.Outputs2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem13_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (Control_Kieran_quanser_imu_DW.IfActionSubsystem14.IfActionSubsystem14_SubsysRanBC);
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* S-Function (host_initialize_block): '<Root>/Host Initialize' */

      /* S-Function Block: Control_Kieran_quanser_imu/Host Initialize (host_initialize_block) */
      {
        Control_Kieran_quanser_imu_B.HostInitialize_o1 =
          (rtExtModeQuarcIsConnected() ? HOST_STATE_CONNECTED :
           HOST_STATE_NOT_CONNECTED);
      }

      /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
       *  Constant: '<Root>/Left'
       *  Constant: '<Root>/Right '
       */
      if (Control_Kieran_quanser_imu_P.ManualSwitch2_CurrentSetting == 1) {
        Control_Kieran_quanser_imu_B.ManualSwitch2 =
          Control_Kieran_quanser_imu_P.Left_Value;
      } else {
        Control_Kieran_quanser_imu_B.ManualSwitch2 =
          Control_Kieran_quanser_imu_P.Right_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch2' */

      /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
       *  Constant: '<Root>/Off'
       *  Constant: '<Root>/On'
       */
      if (Control_Kieran_quanser_imu_P.ManualSwitch3_CurrentSetting == 1) {
        Control_Kieran_quanser_imu_B.ManualSwitch3 =
          Control_Kieran_quanser_imu_P.Off_Value;
      } else {
        Control_Kieran_quanser_imu_B.ManualSwitch3 =
          Control_Kieran_quanser_imu_P.On_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch3' */

      /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog3' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Analog3 (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.HILReadAnalog3_channels, 1,
           &Control_Kieran_quanser_imu_DW.HILReadAnalog3_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }

        Control_Kieran_quanser_imu_B.HILReadAnalog3 =
          Control_Kieran_quanser_imu_DW.HILReadAnalog3_Buffer;
      }

      /* Sum: '<Root>/Subtract1' incorporates:
       *  Constant: '<Root>/Constant6'
       *  Gain: '<Root>/Gain'
       *  Rounding: '<Root>/Rounding Function'
       */
      Control_Kieran_quanser_imu_B.Subtract1 =
        Control_Kieran_quanser_imu_P.Constant6_Value - floor
        (Control_Kieran_quanser_imu_P.Gain_Gain_n *
         Control_Kieran_quanser_imu_B.HILReadAnalog3);

      /* Gain: '<Root>/Gain4' */
      Control_Kieran_quanser_imu_B.Gain4 =
        Control_Kieran_quanser_imu_P.Gain4_Gain *
        Control_Kieran_quanser_imu_B.Subtract1;

      /* Gain: '<Root>/Gain2' */
      Control_Kieran_quanser_imu_B.Gain2 =
        Control_Kieran_quanser_imu_P.Gain2_Gain *
        Control_Kieran_quanser_imu_B.Gain4;

      /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog1' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Analog1 (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.HILReadAnalog1_channels, 1,
           &Control_Kieran_quanser_imu_DW.HILReadAnalog1_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }

        Control_Kieran_quanser_imu_B.HILReadAnalog1 =
          Control_Kieran_quanser_imu_DW.HILReadAnalog1_Buffer;
      }

      /* Gain: '<Root>/Gain1' incorporates:
       *  Constant: '<Root>/Constant5'
       *  Sum: '<Root>/Subtract'
       */
      rtb_Gain1 = (Control_Kieran_quanser_imu_B.HILReadAnalog1 -
                   Control_Kieran_quanser_imu_P.Constant5_Value) *
        Control_Kieran_quanser_imu_P.Gain1_Gain;

      /* If: '<Root>/If1' incorporates:
       *  Constant: '<S16>/Constant'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        if ((-0.4 < rtb_Gain1) && (0.4 > rtb_Gain1)) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem = rtAction;
      } else {
        rtAction = Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        Control_Kieran_quanser_imu_B.Merge2 =
          Control_Kieran_quanser_imu_P.Constant_Value_a;
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC
            (Control_Kieran_quanser_imu_DW.IfActionSubsystem3_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<Root>/If Action Subsystem3' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S15>/Action Port'
         */
        Control_Kier_IfActionSubsystem2(rtb_Gain1,
          &Control_Kieran_quanser_imu_B.Merge2);
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC
            (Control_Kieran_quanser_imu_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
        break;
      }

      /* End of If: '<Root>/If1' */

      /* Gain: '<Root>/Wire on other side1' */
      Control_Kieran_quanser_imu_B.Wireonotherside1 =
        Control_Kieran_quanser_imu_P.Wireonotherside1_Gain *
        Control_Kieran_quanser_imu_B.Merge2;

      /* Constant: '<S41>/x0' */
      Control_Kieran_quanser_imu_B.x0 = Control_Kieran_quanser_imu_P.x0_Value;
    }

    /* Integrator: '<S41>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE =
        Control_Kieran_quanser_imu_B.x0;
    }

    Control_Kieran_quanser_imu_B.Integrator1 =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S44>/x0' */
      Control_Kieran_quanser_imu_B.x0_m =
        Control_Kieran_quanser_imu_P.x0_Value_h;
    }

    /* Integrator: '<S44>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_m.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_b =
        Control_Kieran_quanser_imu_B.x0_m;
    }

    Control_Kieran_quanser_imu_B.Integrator1_k =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_b;

    /* Trigonometry: '<S23>/Trigonometric Function1' incorporates:
     *  Gain: '<S23>/Gain3'
     */
    rtb_TrigonometricFunction1 = cos(Control_Kieran_quanser_imu_P.Gain3_Gain *
      Control_Kieran_quanser_imu_B.Integrator1_k);
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<Root>/Left3' */
      Control_Kieran_quanser_imu_B.Left3 =
        Control_Kieran_quanser_imu_P.Left3_Value;

      /* Constant: '<Root>/Left1' */
      Control_Kieran_quanser_imu_B.Left1 =
        Control_Kieran_quanser_imu_P.Left1_Value;

      /* Constant: '<Root>/Left2' */
      Control_Kieran_quanser_imu_B.Left2 =
        Control_Kieran_quanser_imu_P.Left2_Value;

      /* Gain: '<S6>/g' incorporates:
       *  Gain: '<S6>/Gain3'
       *  Gain: '<S6>/Gain4'
       *  Gain: '<S6>/forearmL'
       *  Gain: '<S6>/forearm_lc'
       *  Gain: '<S6>/forearm_m'
       *  Product: '<S6>/Product1'
       *  Product: '<S6>/Product2'
       *  Sum: '<S6>/Sum2'
       */
      Control_Kieran_quanser_imu_B.g =
        (Control_Kieran_quanser_imu_P.forearm_m_Gain *
         Control_Kieran_quanser_imu_B.Left1 *
         Control_Kieran_quanser_imu_P.forearm_lc_Gain *
         Control_Kieran_quanser_imu_B.Left3 *
         Control_Kieran_quanser_imu_P.Gain4_Gain_l +
         Control_Kieran_quanser_imu_P.forearmL_Gain *
         Control_Kieran_quanser_imu_B.Left2 * Control_Kieran_quanser_imu_B.Left3
         * Control_Kieran_quanser_imu_P.Gain3_Gain_p) *
        Control_Kieran_quanser_imu_P.g_Gain;

      /* Product: '<S6>/Product' */
      Control_Kieran_quanser_imu_B.Product = Control_Kieran_quanser_imu_B.Gain4 *
        Control_Kieran_quanser_imu_B.g;
    }

    /* Trigonometry: '<S29>/Trigonometric Function' incorporates:
     *  Gain: '<S29>/Gain2'
     */
    Control_Kieran_quanser_imu_B.TrigonometricFunction = cos
      (Control_Kieran_quanser_imu_P.Gain2_Gain_o *
       Control_Kieran_quanser_imu_B.Integrator1_k);
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S40>/x0' */
      Control_Kieran_quanser_imu_B.x0_k =
        Control_Kieran_quanser_imu_P.x0_Value_l;
    }

    /* Integrator: '<S40>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_j.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_j =
        Control_Kieran_quanser_imu_B.x0_k;
    }

    Control_Kieran_quanser_imu_B.Integrator1_l =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_j;

    /* If: '<S29>/If7' */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      if (Control_Kieran_quanser_imu_B.Integrator1_l >= 15.0) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      Control_Kieran_quanser_imu_DW.If7_ActiveSubsystem = rtAction;
    } else {
      rtAction = Control_Kieran_quanser_imu_DW.If7_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem14' incorporates:
       *  ActionPort: '<S56>/Action Port'
       */
      Control_Kie_IfActionSubsystem14(Control_Kieran_quanser_imu_B.Integrator1,
        &rtb_Merge8);
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC
          (Control_Kieran_quanser_imu_DW.IfActionSubsystem14.IfActionSubsystem14_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem14' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem15' incorporates:
       *  ActionPort: '<S57>/Action Port'
       */
      Control_Kie_IfActionSubsystem14(Control_Kieran_quanser_imu_B.Integrator1_l,
        &rtb_Merge8);
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC
          (Control_Kieran_quanser_imu_DW.IfActionSubsystem15.IfActionSubsystem14_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S29>/If Action Subsystem15' */
      break;
    }

    /* End of If: '<S29>/If7' */

    /* Product: '<S29>/Product' */
    Control_Kieran_quanser_imu_B.Product_a =
      Control_Kieran_quanser_imu_B.TrigonometricFunction * rtb_Merge8;

    /* Gain: '<S6>/deg2rad' */
    rtb_Integrator2_g = Control_Kieran_quanser_imu_P.deg2rad_Gain *
      Control_Kieran_quanser_imu_B.Product_a;

    /* Product: '<S6>/times' incorporates:
     *  Trigonometry: '<S6>/Trigonometric Function2'
     */
    Control_Kieran_quanser_imu_B.tau_g = Control_Kieran_quanser_imu_B.Product *
      sin(rtb_Integrator2_g);
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S24>/x0' */
      Control_Kieran_quanser_imu_B.x0_a =
        Control_Kieran_quanser_imu_P.x0_Value_c;
    }

    /* Integrator: '<S24>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_i.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_k =
        Control_Kieran_quanser_imu_B.x0_a;
    }

    Control_Kieran_quanser_imu_B.Integrator1_f =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_k;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S42>/x0' */
      Control_Kieran_quanser_imu_B.x0_f =
        Control_Kieran_quanser_imu_P.x0_Value_e;
    }

    /* Integrator: '<S42>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_k.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_n =
        Control_Kieran_quanser_imu_B.x0_f;
    }

    Control_Kieran_quanser_imu_B.Integrator1_lw =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_n;

    /* Gain: '<S34>/Gain' */
    rtb_Gain_o = Control_Kieran_quanser_imu_P.Gain_Gain_i *
      Control_Kieran_quanser_imu_B.Integrator1_lw;

    /* If: '<S34>/If2' incorporates:
     *  Constant: '<S36>/Constant'
     */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      if (Control_Kieran_quanser_imu_B.Integrator1_l < 5.0) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem = rtAction;
    } else {
      rtAction = Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Gain: '<S35>/Gain' */
      Control_Kieran_quanser_imu_B.Merge3 =
        Control_Kieran_quanser_imu_P.Gain_Gain *
        Control_Kieran_quanser_imu_B.Left1;
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem5_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem5' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem6' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        Control_Kieran_quanser_imu_B.Merge3 =
          Control_Kieran_quanser_imu_P.Constant_Value_c;
      }

      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem6_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S34>/If Action Subsystem6' */
      break;
    }

    /* End of If: '<S34>/If2' */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Trigonometry: '<S6>/Trigonometric Function1' incorporates:
       *  Constant: '<S6>/a = half_width'
       *  Constant: '<S6>/b =anchor_point_dis'
       *  Product: '<S6>/divide'
       */
      Control_Kieran_quanser_imu_B.TrigonometricFunction1 = atan
        (Control_Kieran_quanser_imu_P.ahalf_width_Value /
         (Control_Kieran_quanser_imu_P.GravityCompensationPositiveDeri * 0.273 *
          0.6 / 2.0));
    }

    /* Product: '<S6>/Divide' incorporates:
     *  Constant: '<S6>/half_width1'
     *  Gain: '<S6>/Gain1'
     *  Product: '<S34>/Product'
     *  Sum: '<S34>/Sum4'
     *  Sum: '<S6>/Sum1'
     *  Trigonometry: '<S34>/Trigonometric Function2'
     *  Trigonometry: '<S6>/Trigonometric Function'
     */
    Control_Kieran_quanser_imu_B.tau_a = (Control_Kieran_quanser_imu_B.Merge3 *
      sin(rtb_Gain_o) + Control_Kieran_quanser_imu_B.Integrator1_f) * sin
      (Control_Kieran_quanser_imu_P.Gain1_Gain_k * rtb_Integrator2_g +
       Control_Kieran_quanser_imu_B.TrigonometricFunction1) *
      Control_Kieran_quanser_imu_P.half_width1_Value;

    /* Sum: '<S6>/Sum' */
    Control_Kieran_quanser_imu_B.Sum = Control_Kieran_quanser_imu_B.tau_g -
      Control_Kieran_quanser_imu_B.tau_a;

    /* Integrator: '<S32>/Integrator2' */
    rtb_Integrator2_g = Control_Kieran_quanser_imu_X.Integrator2_CSTATE;

    /* Product: '<S32>/Product1' incorporates:
     *  Constant: '<S32>/wn'
     *  Integrator: '<S32>/Integrator2'
     */
    Control_Kieran_quanser_imu_B.Product1 =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_input_ *
      Control_Kieran_quanser_imu_X.Integrator2_CSTATE;

    /* Integrator: '<S33>/Integrator2' */
    rtb_Integrator2 = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_n;

    /* Product: '<S33>/Product1' incorporates:
     *  Constant: '<S33>/wn'
     *  Integrator: '<S33>/Integrator2'
     */
    Control_Kieran_quanser_imu_B.Product1_o =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_input *
      Control_Kieran_quanser_imu_X.Integrator2_CSTATE_n;

    /* Sum: '<S6>/Sum4' incorporates:
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain2'
     *  Gain: '<S6>/Gain5'
     *  Gain: '<S6>/Gain6'
     *  Integrator: '<S6>/Integrator'
     *  Sum: '<S6>/Sum3'
     */
    Control_Kieran_quanser_imu_B.Sum4 =
      ((Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_h *
        Control_Kieran_quanser_imu_B.Sum +
        Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_p *
        Control_Kieran_quanser_imu_X.Integrator_CSTATE) +
       Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_d *
       Control_Kieran_quanser_imu_B.Product1) +
      Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_a *
      Control_Kieran_quanser_imu_B.Product1_o;

    /* Switch: '<S51>/Switch2' incorporates:
     *  Constant: '<S25>/Constant'
     *  RelationalOperator: '<S51>/LowerRelop1'
     */
    if (Control_Kieran_quanser_imu_B.Sum4 >
        Control_Kieran_quanser_imu_P.Constant_Value_cp) {
      Control_Kieran_quanser_imu_B.Switch2 =
        Control_Kieran_quanser_imu_P.Constant_Value_cp;
    } else {
      /* Product: '<S25>/Product' incorporates:
       *  Constant: '<S25>/Constant1'
       *  Gain: '<S25>/Gain'
       *  Trigonometry: '<S25>/Trigonometric Function'
       */
      rtb_Gain_o = sin(Control_Kieran_quanser_imu_P.Gain_Gain_d *
                       Control_Kieran_quanser_imu_B.Integrator1_l) *
        Control_Kieran_quanser_imu_P.Constant1_Value_m;

      /* Switch: '<S51>/Switch' incorporates:
       *  RelationalOperator: '<S51>/UpperRelop'
       */
      if (Control_Kieran_quanser_imu_B.Sum4 < rtb_Gain_o) {
        Control_Kieran_quanser_imu_B.Switch2 = rtb_Gain_o;
      } else {
        Control_Kieran_quanser_imu_B.Switch2 = Control_Kieran_quanser_imu_B.Sum4;
      }

      /* End of Switch: '<S51>/Switch' */
    }

    /* End of Switch: '<S51>/Switch2' */

    /* If: '<S23>/If5' incorporates:
     *  Constant: '<S48>/Constant'
     */
    rtAction = -1;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      if ((rtb_TrigonometricFunction1 <= 0.6) &&
          (Control_Kieran_quanser_imu_B.Switch2 > 0.0)) {
        rtAction = 0;
      } else {
        if (((rtb_TrigonometricFunction1 <= 0.6) &&
             (Control_Kieran_quanser_imu_B.Switch2 < 0.0) &&
             (Control_Kieran_quanser_imu_B.Integrator1_f > 3.0)) ||
            (rtb_TrigonometricFunction1 > 0.6)) {
          rtAction = 1;
        }
      }

      Control_Kieran_quanser_imu_DW.If5_ActiveSubsystem = rtAction;
    } else {
      rtAction = Control_Kieran_quanser_imu_DW.If5_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem13' incorporates:
       *  ActionPort: '<S48>/Action Port'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        Control_Kieran_quanser_imu_B.Merge6 =
          Control_Kieran_quanser_imu_P.Constant_Value_g;
      }

      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem13_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem13' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem12' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      Control_Kier_IfActionSubsystem2(Control_Kieran_quanser_imu_B.Switch2,
        &Control_Kieran_quanser_imu_B.Merge6);
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC
          (Control_Kieran_quanser_imu_DW.IfActionSubsystem12.IfActionSubsystem2_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S23>/If Action Subsystem12' */
      break;
    }

    /* End of If: '<S23>/If5' */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* If: '<S22>/If2' */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        if (Control_Kieran_quanser_imu_B.ManualSwitch3 > 0.0) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem_c = rtAction;
      } else {
        rtAction = Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem_c;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem5' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        Control_Kier_IfActionSubsystem2
          (Control_Kieran_quanser_imu_B.Wireonotherside1,
           &Control_Kieran_quanser_imu_B.Merge3_e);
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC
            (Control_Kieran_quanser_imu_DW.IfActionSubsystem5_e.IfActionSubsystem2_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S22>/If Action Subsystem5' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem6' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        Control_Kier_IfActionSubsystem2(Control_Kieran_quanser_imu_B.Merge6,
          &Control_Kieran_quanser_imu_B.Merge3_e);
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC
            (Control_Kieran_quanser_imu_DW.IfActionSubsystem6_k.IfActionSubsystem2_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S22>/If Action Subsystem6' */
        break;
      }

      /* End of If: '<S22>/If2' */
    }

    /* If: '<S28>/If1' incorporates:
     *  Constant: '<S54>/Constant'
     */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      if ((Control_Kieran_quanser_imu_B.Integrator1 > 170.0) &&
          (Control_Kieran_quanser_imu_B.Merge3_e > 0.0)) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem_e = rtAction;
    } else {
      rtAction = Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem_e;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S54>/Action Port'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        Control_Kieran_quanser_imu_B.Merge1 =
          Control_Kieran_quanser_imu_P.Constant_Value_o;
      }

      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem2_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S28>/If Action Subsystem2' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S55>/Action Port'
       */
      Control_Kier_IfActionSubsystem2(Control_Kieran_quanser_imu_B.Merge3_e,
        &Control_Kieran_quanser_imu_B.Merge1);
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC
          (Control_Kieran_quanser_imu_DW.IfActionSubsystem3_p.IfActionSubsystem2_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S28>/If Action Subsystem3' */
      break;
    }

    /* End of If: '<S28>/If1' */

    /* Gain: '<Root>/Wire on other side' */
    Control_Kieran_quanser_imu_B.Wireonotherside =
      Control_Kieran_quanser_imu_P.Wireonotherside_Gain *
      Control_Kieran_quanser_imu_B.Merge1;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* S-Function (hil_write_analog_block): '<Root>/LowLvSpeedController' */

      /* S-Function Block: Control_Kieran_quanser_imu/LowLvSpeedController (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.LowLvSpeedController_channels, 1,
           &Control_Kieran_quanser_imu_B.Wireonotherside);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }
      }

      /* Constant: '<S43>/x0' */
      Control_Kieran_quanser_imu_B.x0_d =
        Control_Kieran_quanser_imu_P.x0_Value_g;
    }

    /* Integrator: '<S43>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_c.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nw =
        Control_Kieran_quanser_imu_B.x0_d;
    }

    Control_Kieran_quanser_imu_B.Integrator1_kv =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nw;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S37>/x0' */
      Control_Kieran_quanser_imu_B.x0_h =
        Control_Kieran_quanser_imu_P.x0_Value_b;
    }

    /* Integrator: '<S37>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_l.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_bp =
        Control_Kieran_quanser_imu_B.x0_h;
    }

    Control_Kieran_quanser_imu_B.Integrator1_e =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_bp;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S38>/x0' */
      Control_Kieran_quanser_imu_B.x0_i =
        Control_Kieran_quanser_imu_P.x0_Value_p;
    }

    /* Integrator: '<S38>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_ct.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_i =
        Control_Kieran_quanser_imu_B.x0_i;
    }

    Control_Kieran_quanser_imu_B.Integrator1_a =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_i;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S39>/x0' */
      Control_Kieran_quanser_imu_B.x0_hd =
        Control_Kieran_quanser_imu_P.x0_Value_a;
    }

    /* Integrator: '<S39>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_o.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_h =
        Control_Kieran_quanser_imu_B.x0_hd;
    }

    Control_Kieran_quanser_imu_B.Integrator1_i =
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_h;

    /* Sum: '<Root>/Subtract2' incorporates:
     *  Constant: '<Root>/Left4'
     */
    Control_Kieran_quanser_imu_B.Subtract2 =
      Control_Kieran_quanser_imu_B.Integrator1_i +
      Control_Kieran_quanser_imu_P.Left4_Value;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* S-Function (hil_read_digital_block): '<Root>/HIL Read Digital' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Digital (hil_read_digital_block) */
      {
        t_error result = hil_read_digital
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.HILReadDigital_channels, 1,
           &Control_Kieran_quanser_imu_DW.HILReadDigital_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        } else {
          rtb_HILReadAnalog =
            Control_Kieran_quanser_imu_DW.HILReadDigital_Buffer;
        }
      }

      /* RelationalOperator: '<S2>/Compare' incorporates:
       *  Constant: '<S2>/Constant'
       */
      Control_Kieran_quanser_imu_B.Compare = (rtb_HILReadAnalog <=
        Control_Kieran_quanser_imu_P.Constant_Value_n);

      /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S4>/Enable'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        if (Control_Kieran_quanser_imu_B.Compare) {
          if (!Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE) {
            /* InitializeConditions for Memory: '<S4>/Memory' */
            Control_Kieran_quanser_imu_DW.Memory_PreviousInput =
              Control_Kieran_quanser_imu_P.Memory_X0;
            Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE = true;
          }
        } else {
          if (Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE) {
            /* Disable for If: '<S4>/If' */
            if (Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m == 0) {
              /* Disable for Outport: '<S31>/Out1' */
              Control_Kieran_quanser_imu_B.In1 =
                Control_Kieran_quanser_imu_P.Out1_Y0;
            }

            Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m = -1;

            /* End of Disable for If: '<S4>/If' */

            /* Disable for Outport: '<S4>/Out2' */
            Control_Kieran_quanser_imu_B.OutportBufferForOut2 =
              Control_Kieran_quanser_imu_P.Out2_Y0;
            Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE = false;
          }
        }
      }

      if (Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE) {
        /* Sum: '<S4>/Sum' incorporates:
         *  Constant: '<S4>/Constant'
         *  Memory: '<S4>/Memory'
         */
        Control_Kieran_quanser_imu_B.Sum_f =
          Control_Kieran_quanser_imu_P.Constant_Value +
          Control_Kieran_quanser_imu_DW.Memory_PreviousInput;

        /* Product: '<S4>/Product' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        Control_Kieran_quanser_imu_B.Product_c =
          Control_Kieran_quanser_imu_P.Constant1_Value *
          Control_Kieran_quanser_imu_B.Sum_f;

        /* If: '<S4>/If' incorporates:
         *  Constant: '<S4>/Constant3'
         *  Constant: '<S4>/Constant4'
         *  Inport: '<S31>/In1'
         */
        rtPrevAction = Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m;
        if (Control_Kieran_quanser_imu_B.Product_c ==
            Control_Kieran_quanser_imu_P.Constant4_Value) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m = rtAction;
        if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
          /* Disable for Outport: '<S31>/Out1' */
          Control_Kieran_quanser_imu_B.In1 =
            Control_Kieran_quanser_imu_P.Out1_Y0;
        }

        if (rtAction == 0) {
          /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
           *  ActionPort: '<S31>/Action Port'
           */
          Control_Kieran_quanser_imu_B.In1 =
            Control_Kieran_quanser_imu_P.Constant3_Value;
          srUpdateBC
            (Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC_o);

          /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
        }

        /* End of If: '<S4>/If' */

        /* SignalConversion: '<S4>/OutportBufferForOut2' */
        Control_Kieran_quanser_imu_B.OutportBufferForOut2 =
          Control_Kieran_quanser_imu_B.In1;

        /* Update for Memory: '<S4>/Memory' */
        Control_Kieran_quanser_imu_DW.Memory_PreviousInput =
          Control_Kieran_quanser_imu_B.Sum_f;
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC(Control_Kieran_quanser_imu_DW.EnabledSubsystem_SubsysRanBC);
        }
      }

      /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

      /* Memory: '<Root>/Memory1' */
      rtb_HILReadAnalog = Control_Kieran_quanser_imu_DW.Memory1_PreviousInput;

      /* Sum: '<Root>/Sum1' */
      rtb_Sum1_f = Control_Kieran_quanser_imu_B.OutportBufferForOut2 +
        rtb_HILReadAnalog;

      /* Math: '<Root>/Math Function' incorporates:
       *  Constant: '<Root>/Constant7'
       */
      Control_Kieran_quanser_imu_B.MathFunction = rt_modd_snf(rtb_Sum1_f,
        Control_Kieran_quanser_imu_P.Constant7_Value);

      /* S-Function (string_select_block): '<Root>/String Select' */
      {
        const t_string_select_table * string_table = (const
          t_string_select_table *)
          Control_Kieran_quanser_imu_DW.StringSelect_PWORK.StringTable;
        const int_T selection_index = (int_T)
          Control_Kieran_quanser_imu_B.MathFunction;
        if (selection_index >= 0 && (size_t) selection_index <
            string_table->num_strings) {
          string_copy((t_utf8_char *) &rtb_StringSelect[0], 21,
                      string_table->strings[selection_index]);
        } else {
          string_copy((t_utf8_char *) &rtb_StringSelect[0], 21, (const
            t_utf8_char *)
                      Control_Kieran_quanser_imu_P.StringSelect_DefaultString);
        }
      }

      /* S-Function (host_speech_synthesis_block): '<Root>/Host Speech Synthesis1' */
      {

#pragma pack(push, 1)

        struct tag_speech_command {
          t_text_to_speech_speak_command command;
          char extra[80U];
        } speech_command;

#pragma pack(pop)

        t_error local_result = 0;
        t_error result;
        t_text_to_speech_state copy_of_state;
        t_boolean enabled = false;
        size_t length;
        length = string_length((const char *) &rtb_StringSelect[0], 21);
        if (length == 21) {
          local_result = -QERR_STRING_NOT_TERMINATED;
        }

        if (local_result >= 0) {
          result = string_print_utf8_chars(speech_command.command.data.text, 80U,
            &rtb_HostSpeechSynthesis1_o3, "%s"
            , &rtb_StringSelect[0]
            );
          if (result >= 0) {
            if (Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Enabled !=
                false && Control_Kieran_quanser_imu_B.OutportBufferForOut2 != 0 &&
                Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_PreviousSt ==
                false) {
              /* Send the command to the host to speak the text */
              speech_command.command.header.peripheral_id = 0;
              speech_command.command.header.command =
                TEXT_TO_SPEECH_PROPERTY_SPEAK;
              speech_command.command.data.flags =
                (Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_interrupt ?
                 TEXT_TO_SPEECH_FLAG_INTERRUPT : 0);
              result = host_send_extmode_packet
                (Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_SendContex,
                 &speech_command, sizeof(speech_command));
              enabled = (result >= 0);
            }

            Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_PreviousSt =
              (Control_Kieran_quanser_imu_B.OutportBufferForOut2 != 0);
          }
        }

        local_result = qthread_section_lock
          (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock);
        if (local_result == 0) {
          memory_copy(&copy_of_state, sizeof(copy_of_state),
                      &Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State);
          Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State.flags = 0;/* clear the flags since we have extracted the event information */
          qthread_section_unlock
            (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock);
        } else if (result >= 0) {
          result = local_result;
        }

        Control_Kieran_quanser_imu_B.HostSpeechSynthesis1_o1 =
          ((copy_of_state.flags & TEXT_TO_SPEECH_DONE) != 0);
        if (enabled) {
          string_copy(&Control_Kieran_quanser_imu_B.HostSpeechSynthesis1_o2[0],
                      80U, speech_command.command.data.text);
        }
      }
    }

    /* Gain: '<Root>/Amplitude3' */
    Control_Kieran_quanser_imu_B.Amplitude3 =
      Control_Kieran_quanser_imu_P.Amplitude3_Gain *
      Control_Kieran_quanser_imu_B.Integrator1_f;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    }

    /* Abs: '<Root>/Abs' */
    rtb_Gain_o = fabs(Control_Kieran_quanser_imu_B.Integrator1_f);
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S30>/x0' */
      Control_Kieran_quanser_imu_B.x0_fw =
        Control_Kieran_quanser_imu_P.x0_Value_cf;
    }

    /* Integrator: '<S30>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_n.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_a =
        Control_Kieran_quanser_imu_B.x0_fw;
    }

    rtb_Integrator1 = Control_Kieran_quanser_imu_X.Integrator1_CSTATE_a;

    /* If: '<Root>/If' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S14>/Constant'
     */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      if ((rtb_Gain_o > 150.0) || (rtb_Integrator1 > 350.0)) {
        rtAction = 0;
      } else {
        rtAction = 1;
      }

      Control_Kieran_quanser_imu_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = Control_Kieran_quanser_imu_DW.If_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        Control_Kieran_quanser_imu_B.Merge =
          Control_Kieran_quanser_imu_P.Constant_Value_d;
      }

      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        Control_Kieran_quanser_imu_B.Merge =
          Control_Kieran_quanser_imu_P.Constant_Value_k;
      }

      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        srUpdateBC(Control_Kieran_quanser_imu_DW.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
      break;
    }

    /* End of If: '<Root>/If' */
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Stop: '<S27>/Stop Simulation' incorporates:
       *  Constant: '<S53>/Constant'
       *  RelationalOperator: '<S53>/Compare'
       */
      if (Control_Kieran_quanser_imu_B.Merge !=
          Control_Kieran_quanser_imu_P.Constant_Value_m) {
        rtmSetStopRequested(Control_Kieran_quanser_imu_M, 1);
      }

      /* End of Stop: '<S27>/Stop Simulation' */

      /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Analog (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.HILReadAnalog_channels, 1,
           &Control_Kieran_quanser_imu_DW.HILReadAnalog_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }

        rtb_HILReadAnalog = Control_Kieran_quanser_imu_DW.HILReadAnalog_Buffer;
      }

      /* Sum: '<S1>/Sum6' incorporates:
       *  Constant: '<S1>/offset4'
       *  Constant: '<S1>/offset5'
       *  Gain: '<S1>/Gain5'
       *  Sum: '<S1>/Sum5'
       */
      Control_Kieran_quanser_imu_B.Sum6 = (rtb_HILReadAnalog +
        Control_Kieran_quanser_imu_P.offset4_Value) *
        Control_Kieran_quanser_imu_P.Gain5_Gain -
        Control_Kieran_quanser_imu_P.offset5_Value;
    }

    /* Derivative: '<S3>/Derivative' */
    if ((Control_Kieran_quanser_imu_DW.TimeStampA >=
         Control_Kieran_quanser_imu_M->Timing.t[0]) &&
        (Control_Kieran_quanser_imu_DW.TimeStampB >=
         Control_Kieran_quanser_imu_M->Timing.t[0])) {
      rtb_Gain_o = 0.0;
    } else {
      rtb_Gain_o = Control_Kieran_quanser_imu_DW.TimeStampA;
      lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeA;
      if (Control_Kieran_quanser_imu_DW.TimeStampA <
          Control_Kieran_quanser_imu_DW.TimeStampB) {
        if (Control_Kieran_quanser_imu_DW.TimeStampB <
            Control_Kieran_quanser_imu_M->Timing.t[0]) {
          rtb_Gain_o = Control_Kieran_quanser_imu_DW.TimeStampB;
          lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeB;
        }
      } else {
        if (Control_Kieran_quanser_imu_DW.TimeStampA >=
            Control_Kieran_quanser_imu_M->Timing.t[0]) {
          rtb_Gain_o = Control_Kieran_quanser_imu_DW.TimeStampB;
          lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeB;
        }
      }

      rtb_Gain_o = (Control_Kieran_quanser_imu_B.Product_a - *lastU) /
        (Control_Kieran_quanser_imu_M->Timing.t[0] - rtb_Gain_o);
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* Integrator: '<S30>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_e;

    /* Product: '<S30>/Product' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/wn'
     *  Constant: '<S30>/zt'
     *  Product: '<S30>/Product2'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_l = ((rtb_Gain_o - rtb_Integrator1) -
      rtb_Clock * Control_Kieran_quanser_imu_P.Constant_Value_e *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_e) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_input;

    /* Product: '<S30>/Product1' incorporates:
     *  Constant: '<S30>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_i =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_input * rtb_Clock;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S32>/x0' */
      Control_Kieran_quanser_imu_B.x0_me =
        Control_Kieran_quanser_imu_P.x0_Value_n;
    }

    /* Integrator: '<S32>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_g.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nf =
        Control_Kieran_quanser_imu_B.x0_me;
    }

    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nf;

    /* Product: '<S32>/Product' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S32>/wn'
     *  Constant: '<S32>/zt'
     *  Product: '<S32>/Product2'
     *  Sum: '<S32>/Sum'
     *  Sum: '<S32>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_a3 = ((Control_Kieran_quanser_imu_B.Sum
      - rtb_Clock) - rtb_Integrator2_g *
      Control_Kieran_quanser_imu_P.Constant_Value_p *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_e) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_input_;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Constant: '<S33>/x0' */
      Control_Kieran_quanser_imu_B.x0_fwo =
        Control_Kieran_quanser_imu_P.x0_Value_ec;
    }

    /* Integrator: '<S33>/Integrator1' */
    if (Control_Kieran_quanser_imu_DW.Integrator1_IWORK_b.IcNeedsLoading) {
      Control_Kieran_quanser_imu_X.Integrator1_CSTATE_l =
        Control_Kieran_quanser_imu_B.x0_fwo;
    }

    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator1_CSTATE_l;

    /* Product: '<S33>/Product' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/wn'
     *  Constant: '<S33>/zt'
     *  Gain: '<S6>/deg2rad1'
     *  Product: '<S33>/Product2'
     *  Sum: '<S33>/Sum'
     *  Sum: '<S33>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_aq =
      ((Control_Kieran_quanser_imu_P.deg2rad1_Gain *
        Control_Kieran_quanser_imu_B.Integrator1_l - rtb_Clock) -
       rtb_Integrator2 * Control_Kieran_quanser_imu_P.Constant_Value_ct *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_c) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_input;

    /* Integrator: '<S40>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_a;

    /* Product: '<S40>/Product' incorporates:
     *  Constant: '<Root>/val1'
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/wn'
     *  Constant: '<S40>/zt'
     *  Product: '<S40>/Product2'
     *  Sum: '<S40>/Sum'
     *  Sum: '<S40>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_m =
      ((Control_Kieran_quanser_imu_P.val1_Value -
        Control_Kieran_quanser_imu_B.Integrator1_l) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_mw *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter5_inp_k) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter5_input;

    /* Product: '<S40>/Product1' incorporates:
     *  Constant: '<S40>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_g =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter5_input * rtb_Clock;

    /* Integrator: '<S41>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_f;

    /* Product: '<S41>/Product' incorporates:
     *  Constant: '<Root>/val2'
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/wn'
     *  Constant: '<S41>/zt'
     *  Product: '<S41>/Product2'
     *  Sum: '<S41>/Sum'
     *  Sum: '<S41>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_g =
      ((Control_Kieran_quanser_imu_P.val2_Value -
        Control_Kieran_quanser_imu_B.Integrator1) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_l *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter6_inp_i) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter6_input;

    /* Product: '<S41>/Product1' incorporates:
     *  Constant: '<S41>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_j =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter6_input * rtb_Clock;

    /* Integrator: '<S42>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_fb;

    /* Product: '<S42>/Product' incorporates:
     *  Constant: '<Root>/val3'
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/wn'
     *  Constant: '<S42>/zt'
     *  Product: '<S42>/Product2'
     *  Sum: '<S42>/Sum'
     *  Sum: '<S42>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_d =
      ((Control_Kieran_quanser_imu_P.val3_Value -
        Control_Kieran_quanser_imu_B.Integrator1_lw) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_de *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter7_inp_n) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter7_input;

    /* Product: '<S42>/Product1' incorporates:
     *  Constant: '<S42>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_k =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter7_input * rtb_Clock;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    }

    /* Integrator: '<S43>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_b;

    /* Product: '<S43>/Product' incorporates:
     *  Constant: '<Root>/val4'
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/wn'
     *  Constant: '<S43>/zt'
     *  Product: '<S43>/Product2'
     *  Sum: '<S43>/Sum'
     *  Sum: '<S43>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_ac =
      ((Control_Kieran_quanser_imu_P.val4_Value -
        Control_Kieran_quanser_imu_B.Integrator1_kv) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_mg *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter8_inp_h) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter8_input;

    /* Product: '<S43>/Product1' incorporates:
     *  Constant: '<S43>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_l =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter8_input * rtb_Clock;

    /* Integrator: '<S44>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_i;

    /* Product: '<S44>/Product' incorporates:
     *  Constant: '<Root>/val5'
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/wn'
     *  Constant: '<S44>/zt'
     *  Product: '<S44>/Product2'
     *  Sum: '<S44>/Sum'
     *  Sum: '<S44>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_gt =
      ((Control_Kieran_quanser_imu_P.val5_Value -
        Control_Kieran_quanser_imu_B.Integrator1_k) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_b *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter9_inp_o) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter9_input;

    /* Product: '<S44>/Product1' incorporates:
     *  Constant: '<S44>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_lt =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter9_input * rtb_Clock;

    /* Integrator: '<S37>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_bl;

    /* Product: '<S37>/Product' incorporates:
     *  Constant: '<Root>/val6'
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/wn'
     *  Constant: '<S37>/zt'
     *  Product: '<S37>/Product2'
     *  Sum: '<S37>/Sum'
     *  Sum: '<S37>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_ll =
      ((Control_Kieran_quanser_imu_P.val6_Value -
        Control_Kieran_quanser_imu_B.Integrator1_e) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_h *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_f) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_h;

    /* Product: '<S37>/Product1' incorporates:
     *  Constant: '<S37>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_l0 =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_h * rtb_Clock;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    }

    /* Integrator: '<S38>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_o;

    /* Product: '<S38>/Product' incorporates:
     *  Constant: '<Root>/val7'
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/wn'
     *  Constant: '<S38>/zt'
     *  Product: '<S38>/Product2'
     *  Sum: '<S38>/Sum'
     *  Sum: '<S38>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_p =
      ((Control_Kieran_quanser_imu_P.val7_Value -
        Control_Kieran_quanser_imu_B.Integrator1_a) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_ht *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_o) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_n;

    /* Product: '<S38>/Product1' incorporates:
     *  Constant: '<S38>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_lk =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_n * rtb_Clock;

    /* Integrator: '<S39>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_d;

    /* Product: '<S39>/Product' incorporates:
     *  Constant: '<Root>/val8'
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/wn'
     *  Constant: '<S39>/zt'
     *  Product: '<S39>/Product2'
     *  Sum: '<S39>/Sum'
     *  Sum: '<S39>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_b =
      ((Control_Kieran_quanser_imu_P.val8_Value -
        Control_Kieran_quanser_imu_B.Integrator1_i) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_m4 *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter3_inp_m) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter3_input;

    /* Product: '<S39>/Product1' incorporates:
     *  Constant: '<S39>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_c =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter3_input * rtb_Clock;

    /* Integrator: '<S24>/Integrator2' */
    rtb_Clock = Control_Kieran_quanser_imu_X.Integrator2_CSTATE_n3;

    /* Product: '<S24>/Product' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S24>/wn'
     *  Constant: '<S24>/zt'
     *  Product: '<S24>/Product2'
     *  Sum: '<S24>/Sum'
     *  Sum: '<S24>/Sum1'
     */
    Control_Kieran_quanser_imu_B.Product_lj =
      ((Control_Kieran_quanser_imu_B.Sum6 -
        Control_Kieran_quanser_imu_B.Integrator1_f) - rtb_Clock *
       Control_Kieran_quanser_imu_P.Constant_Value_ar *
       Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_k) *
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_o;

    /* Product: '<S24>/Product1' incorporates:
     *  Constant: '<S24>/wn'
     */
    Control_Kieran_quanser_imu_B.Product1_oj =
      Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_o * rtb_Clock;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    }

    /* Clock: '<Root>/Clock' */
    rtb_Clock = Control_Kieran_quanser_imu_M->Timing.t[0];

    /* Sum: '<Root>/Add' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<Root>/tos'
     */
    Control_Kieran_quanser_imu_B.Add = Control_Kieran_quanser_imu_P.tos_Gain *
      rtb_Clock + Control_Kieran_quanser_imu_P.Constant_Value_o3;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog2' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Analog2 (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           Control_Kieran_quanser_imu_P.HILReadAnalog2_channels, 4,
           &Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }

        Control_Kieran_quanser_imu_B.Flexor =
          Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer[0];
        Control_Kieran_quanser_imu_B.Extensor =
          Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer[1];
        Control_Kieran_quanser_imu_B.HILReadAnalog2_o3 =
          Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer[2];
        Control_Kieran_quanser_imu_B.HILReadAnalog2_o4 =
          Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer[3];
      }

      /* Gain: '<Root>/Amplitude4' */
      Control_Kieran_quanser_imu_B.Amplitude4 =
        Control_Kieran_quanser_imu_P.Amplitude4_Gain *
        Control_Kieran_quanser_imu_B.Flexor;

      /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog4' */

      /* S-Function Block: Control_Kieran_quanser_imu/HIL Read Analog4 (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_P.HILReadAnalog4_channels, 1,
           &Control_Kieran_quanser_imu_DW.HILReadAnalog4_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }

        Control_Kieran_quanser_imu_B.HILReadAnalog4 =
          Control_Kieran_quanser_imu_DW.HILReadAnalog4_Buffer;
      }

      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<Root>/Constant2'
       */
      if (Control_Kieran_quanser_imu_P.ManualSwitch_CurrentSetting == 1) {
        Control_Kieran_quanser_imu_B.ManualSwitch =
          Control_Kieran_quanser_imu_P.Constant1_Value_g;
      } else {
        Control_Kieran_quanser_imu_B.ManualSwitch =
          Control_Kieran_quanser_imu_P.Constant2_Value;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch' */

      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  Constant: '<Root>/Constant3'
       *  Constant: '<Root>/Constant4'
       */
      if (Control_Kieran_quanser_imu_P.ManualSwitch1_CurrentSetting == 1) {
        Control_Kieran_quanser_imu_B.ManualSwitch1 =
          Control_Kieran_quanser_imu_P.Constant3_Value_n;
      } else {
        Control_Kieran_quanser_imu_B.ManualSwitch1 =
          Control_Kieran_quanser_imu_P.Constant4_Value_l;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch1' */

      /* If: '<Root>/If_end_signal' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S21>/Constant'
       */
      if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
        if (Control_Kieran_quanser_imu_B.ManualSwitch1 == 1.0) {
          rtAction = 0;
        } else {
          rtAction = 1;
        }

        Control_Kieran_quanser_imu_DW.If_end_signal_ActiveSubsystem = rtAction;
      } else {
        rtAction = Control_Kieran_quanser_imu_DW.If_end_signal_ActiveSubsystem;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<Root>/Outputs1' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        Control_Kieran_quanser_imu_B.Merge1_i =
          Control_Kieran_quanser_imu_P.Constant_Value_i;
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC(Control_Kieran_quanser_imu_DW.Outputs1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<Root>/Outputs1' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<Root>/Outputs2' incorporates:
         *  ActionPort: '<S21>/Action Port'
         */
        Control_Kieran_quanser_imu_B.Merge1_i =
          Control_Kieran_quanser_imu_P.Constant_Value_cw;
        if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
          srUpdateBC(Control_Kieran_quanser_imu_DW.Outputs2_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<Root>/Outputs2' */
        break;
      }

      /* End of If: '<Root>/If_end_signal' */

      /* Stop: '<S26>/Stop Simulation' incorporates:
       *  Constant: '<S52>/Constant'
       *  RelationalOperator: '<S52>/Compare'
       */
      if (Control_Kieran_quanser_imu_B.Merge1_i !=
          Control_Kieran_quanser_imu_P.Constant_Value_ld) {
        rtmSetStopRequested(Control_Kieran_quanser_imu_M, 1);
      }

      /* End of Stop: '<S26>/Stop Simulation' */
    }
  }

  if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    real_T *lastU;

    /* Update for Integrator: '<S41>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S44>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_m.IcNeedsLoading = 0;

    /* Update for Integrator: '<S40>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_j.IcNeedsLoading = 0;

    /* Update for Integrator: '<S24>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_i.IcNeedsLoading = 0;

    /* Update for Integrator: '<S42>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_k.IcNeedsLoading = 0;

    /* Update for Integrator: '<S43>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_c.IcNeedsLoading = 0;

    /* Update for Integrator: '<S37>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_l.IcNeedsLoading = 0;

    /* Update for Integrator: '<S38>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_ct.IcNeedsLoading = 0;

    /* Update for Integrator: '<S39>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_o.IcNeedsLoading = 0;
    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
      /* Update for Memory: '<Root>/Memory1' */
      Control_Kieran_quanser_imu_DW.Memory1_PreviousInput = rtb_Sum1_f;
    }

    /* Update for Integrator: '<S30>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_n.IcNeedsLoading = 0;

    /* Update for Derivative: '<S3>/Derivative' */
    if (Control_Kieran_quanser_imu_DW.TimeStampA == (rtInf)) {
      Control_Kieran_quanser_imu_DW.TimeStampA =
        Control_Kieran_quanser_imu_M->Timing.t[0];
      lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeA;
    } else if (Control_Kieran_quanser_imu_DW.TimeStampB == (rtInf)) {
      Control_Kieran_quanser_imu_DW.TimeStampB =
        Control_Kieran_quanser_imu_M->Timing.t[0];
      lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeB;
    } else if (Control_Kieran_quanser_imu_DW.TimeStampA <
               Control_Kieran_quanser_imu_DW.TimeStampB) {
      Control_Kieran_quanser_imu_DW.TimeStampA =
        Control_Kieran_quanser_imu_M->Timing.t[0];
      lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeA;
    } else {
      Control_Kieran_quanser_imu_DW.TimeStampB =
        Control_Kieran_quanser_imu_M->Timing.t[0];
      lastU = &Control_Kieran_quanser_imu_DW.LastUAtTimeB;
    }

    *lastU = Control_Kieran_quanser_imu_B.Product_a;

    /* End of Update for Derivative: '<S3>/Derivative' */
    /* Update for Integrator: '<S32>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_g.IcNeedsLoading = 0;

    /* Update for Integrator: '<S33>/Integrator1' */
    Control_Kieran_quanser_imu_DW.Integrator1_IWORK_b.IcNeedsLoading = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, Control_Kieran_quanser_imu_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {/* Sample time: [0.006s, 0.0s] */
      rtExtModeUpload(1, (((Control_Kieran_quanser_imu_M->Timing.clockTick1+
                            Control_Kieran_quanser_imu_M->Timing.clockTickH1*
                            4294967296.0)) * 0.006));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Control_Kieran_quanser_imu_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Control_Kieran_quanser_imu_M)!=-1) &&
          !((rtmGetTFinal(Control_Kieran_quanser_imu_M)-
             (((Control_Kieran_quanser_imu_M->Timing.clockTick1+
                Control_Kieran_quanser_imu_M->Timing.clockTickH1* 4294967296.0))
              * 0.006)) > (((Control_Kieran_quanser_imu_M->Timing.clockTick1+
                             Control_Kieran_quanser_imu_M->Timing.clockTickH1*
                             4294967296.0)) * 0.006) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Control_Kieran_quanser_imu_M)) {
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Control_Kieran_quanser_imu_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Control_Kieran_quanser_imu_M->Timing.clockTick0)) {
      ++Control_Kieran_quanser_imu_M->Timing.clockTickH0;
    }

    Control_Kieran_quanser_imu_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Control_Kieran_quanser_imu_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.006s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.006, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Control_Kieran_quanser_imu_M->Timing.clockTick1++;
      if (!Control_Kieran_quanser_imu_M->Timing.clockTick1) {
        Control_Kieran_quanser_imu_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Control_Kieran_quanser_imu_derivatives(void)
{
  XDot_Control_Kieran_quanser_i_T *_rtXdot;
  _rtXdot = ((XDot_Control_Kieran_quanser_i_T *)
             Control_Kieran_quanser_imu_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S41>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE =
      Control_Kieran_quanser_imu_B.Product1_j;
  }

  /* Derivatives for Integrator: '<S44>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_b =
      Control_Kieran_quanser_imu_B.Product1_lt;
  }

  /* Derivatives for Integrator: '<S40>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_j =
      Control_Kieran_quanser_imu_B.Product1_g;
  }

  /* Derivatives for Integrator: '<S24>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_k =
      Control_Kieran_quanser_imu_B.Product1_oj;
  }

  /* Derivatives for Integrator: '<S42>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_n =
      Control_Kieran_quanser_imu_B.Product1_k;
  }

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = Control_Kieran_quanser_imu_B.Sum;

  /* Derivatives for Integrator: '<S32>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Control_Kieran_quanser_imu_B.Product_a3;

  /* Derivatives for Integrator: '<S33>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_n = Control_Kieran_quanser_imu_B.Product_aq;

  /* Derivatives for Integrator: '<S43>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_nw =
      Control_Kieran_quanser_imu_B.Product1_l;
  }

  /* Derivatives for Integrator: '<S37>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_bp =
      Control_Kieran_quanser_imu_B.Product1_l0;
  }

  /* Derivatives for Integrator: '<S38>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_i =
      Control_Kieran_quanser_imu_B.Product1_lk;
  }

  /* Derivatives for Integrator: '<S39>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_h =
      Control_Kieran_quanser_imu_B.Product1_c;
  }

  /* Derivatives for Integrator: '<S30>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_a =
      Control_Kieran_quanser_imu_B.Product1_i;
  }

  /* Derivatives for Integrator: '<S30>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = Control_Kieran_quanser_imu_B.Product_l;

  /* Derivatives for Integrator: '<S32>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_nf =
      Control_Kieran_quanser_imu_B.Product1;
  }

  /* Derivatives for Integrator: '<S33>/Integrator1' */
  {
    ((XDot_Control_Kieran_quanser_i_T *)
      Control_Kieran_quanser_imu_M->ModelData.derivs)->Integrator1_CSTATE_l =
      Control_Kieran_quanser_imu_B.Product1_o;
  }

  /* Derivatives for Integrator: '<S40>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = Control_Kieran_quanser_imu_B.Product_m;

  /* Derivatives for Integrator: '<S41>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_f = Control_Kieran_quanser_imu_B.Product_g;

  /* Derivatives for Integrator: '<S42>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_fb = Control_Kieran_quanser_imu_B.Product_d;

  /* Derivatives for Integrator: '<S43>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_b = Control_Kieran_quanser_imu_B.Product_ac;

  /* Derivatives for Integrator: '<S44>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = Control_Kieran_quanser_imu_B.Product_gt;

  /* Derivatives for Integrator: '<S37>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_bl = Control_Kieran_quanser_imu_B.Product_ll;

  /* Derivatives for Integrator: '<S38>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = Control_Kieran_quanser_imu_B.Product_p;

  /* Derivatives for Integrator: '<S39>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_d = Control_Kieran_quanser_imu_B.Product_b;

  /* Derivatives for Integrator: '<S24>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_n3 = Control_Kieran_quanser_imu_B.Product_lj;
}

/* Model initialize function */
void Control_Kieran_quanser_imu_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Control_Kieran_quanser_imu_M, 0,
                sizeof(RT_MODEL_Control_Kieran_quans_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Control_Kieran_quanser_imu_M->solverInfo,
                          &Control_Kieran_quanser_imu_M->Timing.simTimeStep);
    rtsiSetTPtr(&Control_Kieran_quanser_imu_M->solverInfo, &rtmGetTPtr
                (Control_Kieran_quanser_imu_M));
    rtsiSetStepSizePtr(&Control_Kieran_quanser_imu_M->solverInfo,
                       &Control_Kieran_quanser_imu_M->Timing.stepSize0);
    rtsiSetdXPtr(&Control_Kieran_quanser_imu_M->solverInfo,
                 &Control_Kieran_quanser_imu_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Control_Kieran_quanser_imu_M->solverInfo, (real_T **)
                         &Control_Kieran_quanser_imu_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Control_Kieran_quanser_imu_M->solverInfo,
      &Control_Kieran_quanser_imu_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Control_Kieran_quanser_imu_M->solverInfo,
                          (&rtmGetErrorStatus(Control_Kieran_quanser_imu_M)));
    rtsiSetRTModelPtr(&Control_Kieran_quanser_imu_M->solverInfo,
                      Control_Kieran_quanser_imu_M);
  }

  rtsiSetSimTimeStep(&Control_Kieran_quanser_imu_M->solverInfo, MAJOR_TIME_STEP);
  Control_Kieran_quanser_imu_M->ModelData.intgData.f[0] =
    Control_Kieran_quanser_imu_M->ModelData.odeF[0];
  Control_Kieran_quanser_imu_M->ModelData.contStates =
    ((X_Control_Kieran_quanser_imu_T *) &Control_Kieran_quanser_imu_X);
  rtsiSetSolverData(&Control_Kieran_quanser_imu_M->solverInfo, (void *)
                    &Control_Kieran_quanser_imu_M->ModelData.intgData);
  rtsiSetSolverName(&Control_Kieran_quanser_imu_M->solverInfo,"ode1");
  rtmSetTPtr(Control_Kieran_quanser_imu_M,
             &Control_Kieran_quanser_imu_M->Timing.tArray[0]);
  rtmSetTFinal(Control_Kieran_quanser_imu_M, -1);
  Control_Kieran_quanser_imu_M->Timing.stepSize0 = 0.006;
  rtmSetFirstInitCond(Control_Kieran_quanser_imu_M, 1);

  /* External mode info */
  Control_Kieran_quanser_imu_M->Sizes.checksums[0] = (3316064542U);
  Control_Kieran_quanser_imu_M->Sizes.checksums[1] = (1339131345U);
  Control_Kieran_quanser_imu_M->Sizes.checksums[2] = (3388183172U);
  Control_Kieran_quanser_imu_M->Sizes.checksums[3] = (2815659602U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[20];
    Control_Kieran_quanser_imu_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC_o;
    systemRan[2] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem5_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem6_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.Outputs1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.Outputs2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem5_e.IfActionSubsystem2_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem6_k.IfActionSubsystem2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem12.IfActionSubsystem2_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem13_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem3_p.IfActionSubsystem2_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem14.IfActionSubsystem14_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &Control_Kieran_quanser_imu_DW.IfActionSubsystem15.IfActionSubsystem14_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Control_Kieran_quanser_imu_M->extModeInfo,
      &Control_Kieran_quanser_imu_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Control_Kieran_quanser_imu_M->extModeInfo,
                        Control_Kieran_quanser_imu_M->Sizes.checksums);
    rteiSetTPtr(Control_Kieran_quanser_imu_M->extModeInfo, rtmGetTPtr
                (Control_Kieran_quanser_imu_M));
  }

  /* block I/O */
  (void) memset(((void *) &Control_Kieran_quanser_imu_B), 0,
                sizeof(B_Control_Kieran_quanser_imu_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Control_Kieran_quanser_imu_X, 0,
                  sizeof(X_Control_Kieran_quanser_imu_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Control_Kieran_quanser_imu_DW, 0,
                sizeof(DW_Control_Kieran_quanser_imu_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Control_Kieran_quanser_imu_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 27;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Control_Kieran_quanser_imu/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qpid_e", "0",
                      &Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
       "enc0_dir=0;enc0_filter=1;enc0_a=1;enc0_b=1;enc0_z=0;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=1;enc1_b=1;enc1_z=0;enc1_reload=0;enc2_dir=0;enc2_filter=1;enc2_a=1;enc2_b=1;enc2_z=0;enc2_reload=0;enc3_dir=0;enc3_filter=1;enc3_a=1;enc3_b=1;enc3_z=0;enc3_reload=0;enc4_dir=0;enc4_filter=1;enc4_a=1;enc4_b=1;enc4_z=0;enc4_reload=0;enc5_dir=0;enc5_filter=1;enc5_a=1;enc5_b=1;enc5_z=0;enc5_reload=0;enc6_dir=0;enc6_filter=1;enc6_a=1;enc6_b=1;enc6_z=0;enc6_reload=0;enc7_dir=0;enc7_filter=1;enc7_a=1;enc7_b=1;enc7_z=0;enc7_reload=0;ext_int_polarity=0;fuse_polarity=0;convert_polarity=0;watchdog_polarity=0;ext_int_watchdog=0;fuse_watchdog=0;trig1_watchdog=0;watchdog_to_trig1=0;watchdog_to_trig2=0;counter_to_trig0=0;trigger_adcs=0;latch_on_adc=0;pwm_immediate=0;analog_min=-10;analog_max=10",
       788);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
      return;
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_analog_inpu_k &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_analog_input_chan, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_AIMinimums[0],
         &Control_Kieran_quanser_imu_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_f &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_AOMinimums[0],
         &Control_Kieran_quanser_imu_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_analog_out_fp &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_e &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Control_Kieran_quanser_imu_DW.HILInitialize_Card,
        Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha, 8U,
        &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if (Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_i) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
       Control_Kieran_quanser_imu_P.HILInitialize_digital_input_cha, 3U,
       Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
      return;
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_p &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_e &&
         is_switching)) {
      Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0] =
        Control_Kieran_quanser_imu_P.HILInitialize_initial_digital_o;
      Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[1] =
        Control_Kieran_quanser_imu_P.HILInitialize_initial_digital_o;
      result = hil_write_digital
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch, 2U,
         (t_boolean *) &Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if (Control_Kieran_quanser_imu_P.HILInitialize_set_digital_ou_lc) {
      Control_Kieran_quanser_imu_DW.HILInitialize_DOStates[0] =
        Control_Kieran_quanser_imu_P.HILInitialize_watchdog_digital_;
      Control_Kieran_quanser_imu_DW.HILInitialize_DOStates[1] =
        Control_Kieran_quanser_imu_P.HILInitialize_watchdog_digital_;
      result = hil_watchdog_set_digital_expiration_state
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch, 2U, (
          const t_digital_state *)
         &Control_Kieran_quanser_imu_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_par_a &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Control_Kieran_quanser_imu_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &Control_Kieran_quanser_imu_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_FilterFrequency =
          &Control_Kieran_quanser_imu_DW.HILInitialize_FilterFrequency[0];
        for (i1=0; i1 < 8; i1++) {
          dw_FilterFrequency[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_encoder_filter_fr;
        }
      }

      result = hil_set_encoder_filter_frequency
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_encoder_channels, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_cou_o &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Control_Kieran_quanser_imu_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_encoder_channels, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_params_at &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_params__h &&
         is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Control_Kieran_quanser_imu_DW.HILInitialize_Card,
        Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode
        *) &Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Control_Kieran_quanser_imu_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Control_Kieran_quanser_imu_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
           &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_configuration *)
         &Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &Control_Kieran_quanser_imu_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &Control_Kieran_quanser_imu_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs[0],
         &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_a &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_e &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Control_Kieran_quanser_imu_DW.HILInitialize_Card,
        Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels, 8U,
        &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }

    if (Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
         Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels, 8U,
         &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (host_initialize_block): '<Root>/Host Initialize' */
  /* S-Function Block: Control_Kieran_quanser_imu/Host Speech Synthesis1 (host_speech_synthesis_block) */
  {
    qthread_section_init
      (&Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock, NULL);
  }

  /* S-Function Block: Control_Kieran_quanser_imu/Host Initialize (host_initialize_block) */
  {
    t_error result;
    Control_Kieran_quanser_imu_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    result = extmode_svr_register_connected_callback
      (host_extmode_svr_connected_callback,
       host_extmode_svr_disconnected_callback, NULL,
       &Control_Kieran_quanser_imu_DW.HostInitialize_ConnectedHandle);
    if (result == 0) {
      result = extmode_svr_register_custom_action(EXT_MODE_ACTION_HOST_INTERFACE,
        host_extmode_svr_custom_action_callback, NULL);
    }

    Control_Kieran_quanser_imu_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
    }

    if (rtExtModeQuarcIsConnected()) {
      /* Invoke connected callbacks explicitly since Simulink was already connected when MdlStart called */
      host_extmode_svr_connected_callback(NULL);
    }
  }

  /* Start for If: '<Root>/If1' */
  Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem = -1;

  /* Start for Constant: '<S41>/x0' */
  Control_Kieran_quanser_imu_B.x0 = Control_Kieran_quanser_imu_P.x0_Value;

  /* Start for Constant: '<S44>/x0' */
  Control_Kieran_quanser_imu_B.x0_m = Control_Kieran_quanser_imu_P.x0_Value_h;

  /* Start for Constant: '<S40>/x0' */
  Control_Kieran_quanser_imu_B.x0_k = Control_Kieran_quanser_imu_P.x0_Value_l;

  /* Start for If: '<S29>/If7' */
  Control_Kieran_quanser_imu_DW.If7_ActiveSubsystem = -1;

  /* Start for Constant: '<S24>/x0' */
  Control_Kieran_quanser_imu_B.x0_a = Control_Kieran_quanser_imu_P.x0_Value_c;

  /* Start for Constant: '<S42>/x0' */
  Control_Kieran_quanser_imu_B.x0_f = Control_Kieran_quanser_imu_P.x0_Value_e;

  /* Start for If: '<S34>/If2' */
  Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem = -1;

  /* Start for If: '<S23>/If5' */
  Control_Kieran_quanser_imu_DW.If5_ActiveSubsystem = -1;

  /* Start for If: '<S22>/If2' */
  Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem_c = -1;

  /* Start for Merge: '<S23>/Merge6' */
  Control_Kieran_quanser_imu_B.Merge6 =
    Control_Kieran_quanser_imu_P.Merge6_InitialOutput;

  /* Start for If: '<S28>/If1' */
  Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem_e = -1;

  /* Start for Merge: '<S28>/Merge1' */
  Control_Kieran_quanser_imu_B.Merge1 =
    Control_Kieran_quanser_imu_P.Merge1_InitialOutput;

  /* Start for Constant: '<S43>/x0' */
  Control_Kieran_quanser_imu_B.x0_d = Control_Kieran_quanser_imu_P.x0_Value_g;

  /* Start for Constant: '<S37>/x0' */
  Control_Kieran_quanser_imu_B.x0_h = Control_Kieran_quanser_imu_P.x0_Value_b;

  /* Start for Constant: '<S38>/x0' */
  Control_Kieran_quanser_imu_B.x0_i = Control_Kieran_quanser_imu_P.x0_Value_p;

  /* Start for Constant: '<S39>/x0' */
  Control_Kieran_quanser_imu_B.x0_hd = Control_Kieran_quanser_imu_P.x0_Value_a;

  /* Start for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE = false;

  /* Start for If: '<S4>/If' */
  Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m = -1;

  /* Start for IfAction SubSystem: '<S4>/If Action Subsystem' */
  /* VirtualOutportStart for Outport: '<S31>/Out1' */
  Control_Kieran_quanser_imu_B.In1 = Control_Kieran_quanser_imu_P.Out1_Y0;

  /* End of Start for SubSystem: '<S4>/If Action Subsystem' */
  /* InitializeConditions for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* InitializeConditions for Memory: '<S4>/Memory' */
  Control_Kieran_quanser_imu_DW.Memory_PreviousInput =
    Control_Kieran_quanser_imu_P.Memory_X0;

  /* End of InitializeConditions for SubSystem: '<Root>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S4>/Out2' */
  Control_Kieran_quanser_imu_B.OutportBufferForOut2 =
    Control_Kieran_quanser_imu_P.Out2_Y0;

  /* End of Start for SubSystem: '<Root>/Enabled Subsystem' */
  /* Start for S-Function (string_select_block): '<Root>/String Select' */
  {
    size_t num_strings = 0;
    const t_utf8_char * cp = (const t_utf8_char *)
      Control_Kieran_quanser_imu_P.StringSelect_Strings;
    const t_utf8_char * ep = (const t_utf8_char *)
      &Control_Kieran_quanser_imu_P.StringSelect_Strings[14];
    t_string_select_table * string_table;
    size_t index;
    for (cp = (const t_utf8_char *)
         Control_Kieran_quanser_imu_P.StringSelect_Strings; cp <= ep; cp++) {
      num_strings += (*cp == '\0');
    }

    string_table = (t_string_select_table *) memory_allocate(sizeof(struct
      tag_string_select_table) + (num_strings - 1) * sizeof(t_utf8_char *));
    string_table->num_strings = num_strings;
    string_table->strings[0] = (const t_utf8_char *)
      Control_Kieran_quanser_imu_P.StringSelect_Strings;
    index = 1;
    for (cp = string_table->strings[0]; cp <= ep && index < num_strings; cp++) {
      if (*cp == '\0')
        string_table->strings[index++] = cp + 1;
    }

    if (*ep != '\0') {
      rtmSetErrorStatus(Control_Kieran_quanser_imu_M,
                        "String list is not null-terminated");
    }

    Control_Kieran_quanser_imu_DW.StringSelect_PWORK.StringTable = string_table;
  }

  /* Start for Constant: '<S30>/x0' */
  Control_Kieran_quanser_imu_B.x0_fw = Control_Kieran_quanser_imu_P.x0_Value_cf;

  /* Start for If: '<Root>/If' */
  Control_Kieran_quanser_imu_DW.If_ActiveSubsystem = -1;

  /* Start for Merge: '<Root>/Merge' */
  Control_Kieran_quanser_imu_B.Merge =
    Control_Kieran_quanser_imu_P.Merge_InitialOutput;

  /* Start for Constant: '<S32>/x0' */
  Control_Kieran_quanser_imu_B.x0_me = Control_Kieran_quanser_imu_P.x0_Value_n;

  /* Start for Constant: '<S33>/x0' */
  Control_Kieran_quanser_imu_B.x0_fwo = Control_Kieran_quanser_imu_P.x0_Value_ec;

  /* Start for If: '<Root>/If_end_signal' */
  Control_Kieran_quanser_imu_DW.If_end_signal_ActiveSubsystem = -1;

  /* InitializeConditions for Integrator: '<S41>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S44>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_b = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_m.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S40>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_j = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_j.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S24>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_k = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_i.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S42>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_n = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_k.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Control_Kieran_quanser_imu_X.Integrator_CSTATE =
    Control_Kieran_quanser_imu_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S32>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE =
    Control_Kieran_quanser_imu_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S33>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_n =
    Control_Kieran_quanser_imu_P.Integrator2_IC_m;

  /* InitializeConditions for Integrator: '<S43>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nw = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_c.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S37>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_bp = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_l.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S38>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_i = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_ct.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S39>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_h = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_o.IcNeedsLoading = 1;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  Control_Kieran_quanser_imu_DW.Memory1_PreviousInput =
    Control_Kieran_quanser_imu_P.Memory1_X0;

  /* InitializeConditions for Integrator: '<S30>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_a = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_n.IcNeedsLoading = 1;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Control_Kieran_quanser_imu_DW.TimeStampA = (rtInf);
  Control_Kieran_quanser_imu_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S30>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_e =
    Control_Kieran_quanser_imu_P.Integrator2_IC_p;

  /* InitializeConditions for Integrator: '<S32>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_nf = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_g.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S33>/Integrator1' */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    Control_Kieran_quanser_imu_X.Integrator1_CSTATE_l = 0.0;
  }

  Control_Kieran_quanser_imu_DW.Integrator1_IWORK_b.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S40>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_a =
    Control_Kieran_quanser_imu_P.Integrator2_IC_g;

  /* InitializeConditions for Integrator: '<S41>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_f =
    Control_Kieran_quanser_imu_P.Integrator2_IC_c;

  /* InitializeConditions for Integrator: '<S42>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_fb =
    Control_Kieran_quanser_imu_P.Integrator2_IC_f;

  /* InitializeConditions for Integrator: '<S43>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_b =
    Control_Kieran_quanser_imu_P.Integrator2_IC_l;

  /* InitializeConditions for Integrator: '<S44>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_i =
    Control_Kieran_quanser_imu_P.Integrator2_IC_i;

  /* InitializeConditions for Integrator: '<S37>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_bl =
    Control_Kieran_quanser_imu_P.Integrator2_IC_im;

  /* InitializeConditions for Integrator: '<S38>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_o =
    Control_Kieran_quanser_imu_P.Integrator2_IC_a;

  /* InitializeConditions for Integrator: '<S39>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_d =
    Control_Kieran_quanser_imu_P.Integrator2_IC_fa;

  /* InitializeConditions for Integrator: '<S24>/Integrator2' */
  Control_Kieran_quanser_imu_X.Integrator2_CSTATE_n3 =
    Control_Kieran_quanser_imu_P.Integrator2_IC_d;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Control_Kieran_quanser_imu_M)) {
    rtmSetFirstInitCond(Control_Kieran_quanser_imu_M, 0);
  }
}

/* Model terminate function */
void Control_Kieran_quanser_imu_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Control_Kieran_quanser_imu/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    hil_monitor_stop_all(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    is_switching = false;
    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_k &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_d &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_a &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_l &&
         is_switching)) {
      Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0] =
        Control_Kieran_quanser_imu_P.HILInitialize_final_digital_out;
      Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[1] =
        Control_Kieran_quanser_imu_P.HILInitialize_final_digital_out;
      num_final_digital_outputs = 2U;
    }

    if ((Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_b &&
         !is_switching) ||
        (Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_j &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Control_Kieran_quanser_imu_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Control_Kieran_quanser_imu_DW.HILInitialize_Card
                         ,
                         Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         ,
                         Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         ,
                         Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         , NULL, 0
                         ,
                         &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[
                         0]
                         ,
                         &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
             Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
             Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &Control_Kieran_quanser_imu_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Control_Kieran_quanser_imu_DW.HILInitialize_Card,
             Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch,
             num_final_digital_outputs, (t_boolean *)
             &Control_Kieran_quanser_imu_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Control_Kieran_quanser_imu_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    hil_monitor_delete_all(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    hil_close(Control_Kieran_quanser_imu_DW.HILInitialize_Card);
    Control_Kieran_quanser_imu_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (host_initialize_block): '<Root>/Host Initialize' */

  /* S-Function Block: Control_Kieran_quanser_imu/Host Initialize (host_initialize_block) */
  {
    extmode_svr_unregister_custom_action(EXT_MODE_ACTION_HOST_INTERFACE);
    extmode_svr_unregister_connected_callback
      (Control_Kieran_quanser_imu_DW.HostInitialize_ConnectedHandle);
  }

  /* Terminate for S-Function (string_select_block): '<Root>/String Select' */
  memory_free(Control_Kieran_quanser_imu_DW.StringSelect_PWORK.StringTable);
}
