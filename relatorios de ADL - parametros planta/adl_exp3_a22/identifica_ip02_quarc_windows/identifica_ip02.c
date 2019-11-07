/*
 * identifica_ip02.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_ip02.mdl".
 *
 * Model Version              : 1.504
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Mon Oct 08 09:28:10 2018
 */

#include "identifica_ip02.h"
#include "identifica_ip02_private.h"
#include <stdio.h>
#include "identifica_ip02_dt.h"

/* Block signals (auto storage) */
BlockIO_identifica_ip02 identifica_ip02_B;

/* Continuous states */
ContinuousStates_identifica_ip0 identifica_ip02_X;

/* Block states (auto storage) */
D_Work_identifica_ip02 identifica_ip02_DWork;

/* Real-time model */
RT_MODEL_identifica_ip02 identifica_ip02_M_;
RT_MODEL_identifica_ip02 *identifica_ip02_M = &identifica_ip02_M_;

/* This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  identifica_ip02_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f0[i]);
  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  identifica_ip02_output(0);
  identifica_ip02_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f1[i]);
  rtsiSetdX(si, f2);
  identifica_ip02_output(0);
  identifica_ip02_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (h*f2[i]);
  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  identifica_ip02_output(0);
  identifica_ip02_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void identifica_ip02_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(identifica_ip02_M)) {
    identifica_ip02_M->Timing.t[0] = rtsiGetT(&identifica_ip02_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(identifica_ip02_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&identifica_ip02_M->solverInfo,
                          ((identifica_ip02_M->Timing.clockTick0+1)*
      identifica_ip02_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Reset subsysRan breadcrumbs */
  srClearBC(identifica_ip02_DWork.CartPositionWatchdog_SubsysRanB);

  {
    real_T deltaT;
    real_T riseValLimit;
    real_T rateLimiterRate;
    if (rtmIsMajorTimeStep(identifica_ip02_M) &&
        identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: identifica_ip02/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
      {
        t_error result;
        result = hil_task_read_encoder
          (identifica_ip02_DWork.EncoderInput0CartPositionEnco_m, 1,
           &identifica_ip02_DWork.EncoderInput0CartPositionEncode[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        } else {
          identifica_ip02_B.EncoderInput0CartPositionEncode =
            identifica_ip02_DWork.EncoderInput0CartPositionEncode[0];
          identifica_ip02_B.EncoderInput0CartPositionEnco_n =
            identifica_ip02_DWork.EncoderInput0CartPositionEncode[1];
        }
      }

      /* Gain: '<S1>/Conversion to m' */
      identifica_ip02_B.Conversiontom = identifica_ip02_P.Conversiontom_Gain *
        identifica_ip02_B.EncoderInput0CartPositionEncode;

      /* Outputs for enable SubSystem: '<S1>/Cart Position Watchdog' incorporates:
       *  Constant: '<S1>/Constant'
       *  EnablePort: '<S6>/Enable'
       */
      if (rtmIsMajorTimeStep(identifica_ip02_M) &&
          identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
        if (rtmIsMajorTimeStep(identifica_ip02_M)) {
          if (identifica_ip02_P.Constant_Value > 0.0) {
            if (identifica_ip02_DWork.CartPositionWatchdog_MODE ==
                SUBSYS_DISABLED) {
              identifica_ip02_DWork.CartPositionWatchdog_MODE = SUBSYS_ENABLED;
            }
          } else {
            if (identifica_ip02_DWork.CartPositionWatchdog_MODE ==
                SUBSYS_ENABLED) {
              identifica_ip02_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;
            }
          }
        }

        if (identifica_ip02_DWork.CartPositionWatchdog_MODE == SUBSYS_ENABLED) {
          /* RelationalOperator: '<S6>/Check Maximum Allowed Position' incorporates:
           *  Constant: '<S6>/X MAX'
           */
          identifica_ip02_B.CheckMaximumAllowedPosition = (real_T)
            (identifica_ip02_P.XMAX_Value < identifica_ip02_B.Conversiontom);

          /* RelationalOperator: '<S10>/Compare' */
          identifica_ip02_B.Compare =
            (identifica_ip02_B.CheckMaximumAllowedPosition != 0.0);

          /* Stop Block: '<S8>/Stop Simulation'
           */
          if (identifica_ip02_B.Compare) {
            rtmSetStopRequested(identifica_ip02_M, 1);
          }

          /* RelationalOperator: '<S6>/Check Minimum Allowed Position' incorporates:
           *  Constant: '<S6>/X IN'
           */
          identifica_ip02_B.CheckMinimumAllowedPosition = (real_T)
            (identifica_ip02_B.Conversiontom < identifica_ip02_P.XIN_Value);

          /* RelationalOperator: '<S11>/Compare' */
          identifica_ip02_B.Compare_m =
            (identifica_ip02_B.CheckMinimumAllowedPosition != 0.0);

          /* Stop Block: '<S9>/Stop Simulation'
           */
          if (identifica_ip02_B.Compare_m) {
            rtmSetStopRequested(identifica_ip02_M, 1);
          }

          if (rtmIsMajorTimeStep(identifica_ip02_M)) {
            srUpdateBC(identifica_ip02_DWork.CartPositionWatchdog_SubsysRanB);
          }
        }
      }

      /* end of Outputs for SubSystem: '<S1>/Cart Position Watchdog' */

      /* Gain: '<S1>/Conversion to rd' */
      identifica_ip02_B.Conversiontord = identifica_ip02_P.Conversiontord_Gain *
        identifica_ip02_B.EncoderInput0CartPositionEnco_n;

      /* Gain: '<S7>/Gain' */
      identifica_ip02_B.Gain = identifica_ip02_P.Gain_Gain *
        identifica_ip02_B.Conversiontord;

      /* Gain: '<S1>/m to mm' */
      identifica_ip02_B.mtomm = identifica_ip02_P.mtomm_Gain *
        identifica_ip02_B.Conversiontom;
    }

    /* SignalGenerator Block: '<Root>/Square Wave'
     */
    {
      real_T phase = identifica_ip02_P.SquareWave_Frequency*
        identifica_ip02_M->Timing.t[0];
      phase = phase-floor(phase);
      identifica_ip02_B.SquareWave = ( phase >= 0.5 ) ?
        identifica_ip02_P.SquareWave_Amplitude :
        -identifica_ip02_P.SquareWave_Amplitude;
    }

    /* Clock Block: '<S5>/Clock'
     */
    identifica_ip02_B.Clock = identifica_ip02_M->Timing.t[0];

    /* Fcn: '<S5>/Fcn1' */
    deltaT = identifica_ip02_B.Clock;
    riseValLimit = rt_rem_snf(deltaT, 10.0);
    identifica_ip02_B.Fcn1 = riseValLimit;

    /* Lookup: '<S5>/Look-Up Table' */
    identifica_ip02_B.LookUpTable = rt_Lookup((real_T *)
      (&identifica_ip02_P.LookUpTable_XData[0]), 6, identifica_ip02_B.Fcn1,
      (real_T *)(&identifica_ip02_P.LookUpTable_YData[0]));

    /* Gain: '<Root>/Amplitude' */
    identifica_ip02_B.Amplitude = identifica_ip02_P.Amplitude_Gain *
      identifica_ip02_B.LookUpTable;

    /* RateLimiter: '<Root>/Rate Limiter' */
    if (identifica_ip02_DWork.LastMajorTime == (rtInf)) {
      identifica_ip02_B.RateLimiter = identifica_ip02_B.Amplitude;
    } else {
      deltaT = identifica_ip02_M->Timing.t[0] -
        identifica_ip02_DWork.LastMajorTime;
      riseValLimit = deltaT * identifica_ip02_P.RateLimiter_RisingLim;
      rateLimiterRate = identifica_ip02_B.Amplitude -
        identifica_ip02_DWork.PrevY;
      if (rateLimiterRate > riseValLimit) {
        identifica_ip02_B.RateLimiter = identifica_ip02_DWork.PrevY +
          riseValLimit;
      } else {
        riseValLimit = deltaT * identifica_ip02_P.RateLimiter_FallingLim;
        if (rateLimiterRate < riseValLimit) {
          identifica_ip02_B.RateLimiter = identifica_ip02_DWork.PrevY +
            riseValLimit;
        } else {
          identifica_ip02_B.RateLimiter = identifica_ip02_B.Amplitude;
        }
      }
    }

    /* Step: '<Root>/Step' */
    riseValLimit = identifica_ip02_M->Timing.t[0];
    if (riseValLimit < identifica_ip02_P.Step_Time) {
      identifica_ip02_B.Step = identifica_ip02_P.Step_Y0;
    } else {
      identifica_ip02_B.Step = identifica_ip02_P.Step_YFinal;
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Define sinal de entrada'
     */
    switch ((int32_T)identifica_ip02_P.Definesinaldeentrada_Value) {
     case 1:
      /* Gain: '<Root>/Step Amplitude' */
      identifica_ip02_B.StepAmplitude = identifica_ip02_P.StepAmplitude_Gain_f *
        identifica_ip02_B.SquareWave;
      identifica_ip02_B.MultiportSwitch = identifica_ip02_B.StepAmplitude;
      break;

     case 2:
      identifica_ip02_B.MultiportSwitch = identifica_ip02_B.RateLimiter;
      break;

     default:
      /* Gain: '<Root>/Step Amplitude ' */
      identifica_ip02_B.StepAmplitude_d = identifica_ip02_P.StepAmplitude_Gain *
        identifica_ip02_B.Step;
      identifica_ip02_B.MultiportSwitch = identifica_ip02_B.StepAmplitude_d;
      break;
    }

    /* Gain: '<Root>/mm to m' */
    identifica_ip02_B.mmtom = identifica_ip02_P.mmtom_Gain *
      identifica_ip02_B.MultiportSwitch;

    /* Sum: '<Root>/Sum4' */
    identifica_ip02_B.Sum4 = identifica_ip02_B.mmtom -
      identifica_ip02_B.Conversiontom;

    /* Gain: '<Root>/Kp' */
    identifica_ip02_B.Kp = identifica_ip02_P.Kp_Gain * identifica_ip02_B.Sum4;

    /* Saturate: '<Root>/Amplifier Voltage Limit' */
    riseValLimit = identifica_ip02_B.Kp;
    identifica_ip02_B.AmplifierVoltageLimit = rt_SATURATE(riseValLimit,
      identifica_ip02_P.AmplifierVoltageLimit_LowerSat,
      identifica_ip02_P.AmplifierVoltageLimit_UpperSat);

    /* Gain: '<S1>/Cable Gain Pre-Compensation' */
    identifica_ip02_B.CableGainPreCompensation =
      identifica_ip02_P.CableGainPreCompensation_Gain *
      identifica_ip02_B.AmplifierVoltageLimit;

    /* Saturate: '<S1>/DAC Limit' */
    riseValLimit = identifica_ip02_B.CableGainPreCompensation;
    identifica_ip02_B.DACLimit = rt_SATURATE(riseValLimit,
      identifica_ip02_P.DACLimit_LowerSat, identifica_ip02_P.DACLimit_UpperSat);
    if (rtmIsMajorTimeStep(identifica_ip02_M) &&
        identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: identifica_ip02/IP02/Analog Output #0: To Amplifier Driving the Motor (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(identifica_ip02_DWork.HILInitialize_Card,
          &identifica_ip02_P.AnalogOutput0ToAmplifierDriving, 1,
          &identifica_ip02_B.DACLimit);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        }
      }
    }

    /* Gain: '<S1>/Cable Gain' */
    identifica_ip02_B.CableGain = identifica_ip02_P.CableGain_Gain *
      identifica_ip02_B.DACLimit;
    if (rtmIsMajorTimeStep(identifica_ip02_M) &&
        identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<Root>/m to mm' */
      identifica_ip02_B.mtomm_l = identifica_ip02_P.mtomm_Gain_h *
        identifica_ip02_B.Conversiontom;
    }

    /* Gain: '<Root>/m to mm ' */
    identifica_ip02_B.mtomm_k = identifica_ip02_P.mtomm_Gain_f *
      identifica_ip02_B.mmtom;

    /* Integrator: '<S2>/Velocidade  para Posição' */
    identifica_ip02_B.VelocidadeparaPosio =
      identifica_ip02_X.VelocidadeparaPosio_CSTATE;

    /* Gain: '<Root>/m to mm  ' */
    identifica_ip02_B.mtomm_m = identifica_ip02_P.mtomm_Gain_b *
      identifica_ip02_B.VelocidadeparaPosio;

    /* TransferFcn Block: '<Root>/IP02 Modelo Experimental' */
    identifica_ip02_B.IP02ModeloExperimental =
      identifica_ip02_P.IP02ModeloExperimental_C[0]*
      identifica_ip02_X.IP02ModeloExperimental_CSTATE[0]
      + identifica_ip02_P.IP02ModeloExperimental_C[1]*
      identifica_ip02_X.IP02ModeloExperimental_CSTATE[1];
    if (rtmIsMajorTimeStep(identifica_ip02_M) &&
        identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Switch: '<S4>/SwitchControl' incorporates:
     *  Constant: '<S4>/Constant'
     */
    if (identifica_ip02_P.Constant_Value_h >
        identifica_ip02_P.SwitchControl_Threshold) {
      identifica_ip02_B.SwitchControl = identifica_ip02_B.mmtom;
    } else {
      identifica_ip02_B.SwitchControl = 0.0;
    }

    /* Sum: '<Root>/Sum2' */
    identifica_ip02_B.Sum2 = identifica_ip02_B.SwitchControl -
      identifica_ip02_B.VelocidadeparaPosio;

    /* Gain: '<Root>/Kp1' */
    identifica_ip02_B.Kp1 = identifica_ip02_P.Kp1_Gain * identifica_ip02_B.Sum2;

    /* Saturate: '<Root>/Amplifier Voltage Saturation' */
    riseValLimit = identifica_ip02_B.Kp1;
    identifica_ip02_B.AmplifierVoltageSaturation = rt_SATURATE(riseValLimit,
      identifica_ip02_P.AmplifierVoltageSaturation_Lowe,
      identifica_ip02_P.AmplifierVoltageSaturation_Uppe);

    /* Switch: '<S3>/SwitchControl' incorporates:
     *  Constant: '<S3>/Constant'
     */
    if (identifica_ip02_P.Constant_Value_p >
        identifica_ip02_P.SwitchControl_Threshold_d) {
      identifica_ip02_B.SwitchControl_d = identifica_ip02_B.mmtom;
    } else {
      identifica_ip02_B.SwitchControl_d = 0.0;
    }

    /* Saturate: '<Root>/Amplifier Voltage Saturation1' */
    riseValLimit = identifica_ip02_B.SwitchControl_d;
    identifica_ip02_B.AmplifierVoltageSaturation1 = rt_SATURATE(riseValLimit,
      identifica_ip02_P.AmplifierVoltageSaturation1_Low,
      identifica_ip02_P.AmplifierVoltageSaturation1_Upp);

    /* Integrator: '<S2>/Aceleração para Velocidade' */
    identifica_ip02_B.AceleraoparaVelocidade =
      identifica_ip02_X.AceleraoparaVelocidade_CSTATE;

    /* Gain: '<S2>/Amortecimento viscoso' */
    identifica_ip02_B.Amortecimentoviscoso =
      identifica_ip02_P.Amortecimentoviscoso_Gain *
      identifica_ip02_B.AceleraoparaVelocidade;

    /* Gain: '<S2>/Back EMF1' */
    identifica_ip02_B.BackEMF1 = identifica_ip02_P.BackEMF1_Gain *
      identifica_ip02_B.AceleraoparaVelocidade;

    /* Gain: '<S2>/Força Contra-eletromotriz' */
    identifica_ip02_B.ForaContraeletromotriz =
      identifica_ip02_P.ForaContraeletromotriz_Gain * identifica_ip02_B.BackEMF1;

    /* Sum: '<S2>/Sum' */
    identifica_ip02_B.Sum = identifica_ip02_B.AmplifierVoltageSaturation -
      identifica_ip02_B.ForaContraeletromotriz;

    /* Gain: '<S2>/Tensão para Corrente' */
    identifica_ip02_B.TensoparaCorrente =
      identifica_ip02_P.TensoparaCorrente_Gain * identifica_ip02_B.Sum;

    /* Saturate: '<S2>/Saturação para Corrente' */
    riseValLimit = identifica_ip02_B.TensoparaCorrente;
    identifica_ip02_B.SaturaoparaCorrente = rt_SATURATE(riseValLimit,
      identifica_ip02_P.SaturaoparaCorrente_LowerSat,
      identifica_ip02_P.SaturaoparaCorrente_UpperSat);

    /* Gain: '<S2>/Corrente para Força' */
    identifica_ip02_B.CorrenteparaFora = identifica_ip02_P.CorrenteparaFora_Gain
      * identifica_ip02_B.SaturaoparaCorrente;

    /* Sum: '<S2>/Sum1' */
    identifica_ip02_B.Sum1 = identifica_ip02_B.CorrenteparaFora -
      identifica_ip02_B.Amortecimentoviscoso;

    /* Gain: '<S2>/Inercias' */
    identifica_ip02_B.Inercias = identifica_ip02_P.Inercias_Gain *
      identifica_ip02_B.Sum1;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void identifica_ip02_update(int_T tid)
{
  /* Update for RateLimiter: '<Root>/Rate Limiter' */
  identifica_ip02_DWork.PrevY = identifica_ip02_B.RateLimiter;
  identifica_ip02_DWork.LastMajorTime = identifica_ip02_M->Timing.t[0];
  if (rtmIsMajorTimeStep(identifica_ip02_M)) {
    rt_ertODEUpdateContinuousStates(&identifica_ip02_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++identifica_ip02_M->Timing.clockTick0))
    ++identifica_ip02_M->Timing.clockTickH0;
  identifica_ip02_M->Timing.t[0] = identifica_ip02_M->Timing.clockTick0 *
    identifica_ip02_M->Timing.stepSize0 + identifica_ip02_M->Timing.clockTickH0 *
    identifica_ip02_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(identifica_ip02_M) &&
      identifica_ip02_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++identifica_ip02_M->Timing.clockTick1))
      ++identifica_ip02_M->Timing.clockTickH1;
    identifica_ip02_M->Timing.t[1] = identifica_ip02_M->Timing.clockTick1 *
      identifica_ip02_M->Timing.stepSize1 +
      identifica_ip02_M->Timing.clockTickH1 *
      identifica_ip02_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void identifica_ip02_derivatives(void)
{
  /* Derivatives for Integrator: '<S2>/Velocidade  para Posição' */
  ((StateDerivatives_identifica_ip0 *) identifica_ip02_M->ModelData.derivs)
    ->VelocidadeparaPosio_CSTATE = identifica_ip02_B.AceleraoparaVelocidade;

  /* TransferFcn Block: '<Root>/IP02 Modelo Experimental' */
  {
    ((StateDerivatives_identifica_ip0 *) identifica_ip02_M->ModelData.derivs)
      ->IP02ModeloExperimental_CSTATE[0] =
      identifica_ip02_B.AmplifierVoltageSaturation1;
    ((StateDerivatives_identifica_ip0 *) identifica_ip02_M->ModelData.derivs)
      ->IP02ModeloExperimental_CSTATE[0] +=
      (identifica_ip02_P.IP02ModeloExperimental_A[0])*
      identifica_ip02_X.IP02ModeloExperimental_CSTATE[0]
      + (identifica_ip02_P.IP02ModeloExperimental_A[1])*
      identifica_ip02_X.IP02ModeloExperimental_CSTATE[1];
    ((StateDerivatives_identifica_ip0 *) identifica_ip02_M->ModelData.derivs)
      ->IP02ModeloExperimental_CSTATE[1]=
      identifica_ip02_X.IP02ModeloExperimental_CSTATE[0];
  }

  /* Derivatives for Integrator: '<S2>/Aceleração para Velocidade' */
  ((StateDerivatives_identifica_ip0 *) identifica_ip02_M->ModelData.derivs)
    ->AceleraoparaVelocidade_CSTATE = identifica_ip02_B.Inercias;
}

/* Model initialize function */
void identifica_ip02_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)identifica_ip02_M,0,
                sizeof(RT_MODEL_identifica_ip02));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&identifica_ip02_M->solverInfo,
                          &identifica_ip02_M->Timing.simTimeStep);
    rtsiSetTPtr(&identifica_ip02_M->solverInfo, &rtmGetTPtr(identifica_ip02_M));
    rtsiSetStepSizePtr(&identifica_ip02_M->solverInfo,
                       &identifica_ip02_M->Timing.stepSize0);
    rtsiSetdXPtr(&identifica_ip02_M->solverInfo,
                 &identifica_ip02_M->ModelData.derivs);
    rtsiSetContStatesPtr(&identifica_ip02_M->solverInfo,
                         &identifica_ip02_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&identifica_ip02_M->solverInfo,
      &identifica_ip02_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&identifica_ip02_M->solverInfo, (&rtmGetErrorStatus
      (identifica_ip02_M)));
    rtsiSetRTModelPtr(&identifica_ip02_M->solverInfo, identifica_ip02_M);
  }

  rtsiSetSimTimeStep(&identifica_ip02_M->solverInfo, MAJOR_TIME_STEP);
  identifica_ip02_M->ModelData.intgData.y = identifica_ip02_M->ModelData.odeY;
  identifica_ip02_M->ModelData.intgData.f[0] = identifica_ip02_M->
    ModelData.odeF[0];
  identifica_ip02_M->ModelData.intgData.f[1] = identifica_ip02_M->
    ModelData.odeF[1];
  identifica_ip02_M->ModelData.intgData.f[2] = identifica_ip02_M->
    ModelData.odeF[2];
  identifica_ip02_M->ModelData.intgData.f[3] = identifica_ip02_M->
    ModelData.odeF[3];
  identifica_ip02_M->ModelData.contStates = ((real_T *) &identifica_ip02_X);
  rtsiSetSolverData(&identifica_ip02_M->solverInfo, (void *)
                    &identifica_ip02_M->ModelData.intgData);
  rtsiSetSolverName(&identifica_ip02_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = identifica_ip02_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    identifica_ip02_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    identifica_ip02_M->Timing.sampleTimes =
      (&identifica_ip02_M->Timing.sampleTimesArray[0]);
    identifica_ip02_M->Timing.offsetTimes =
      (&identifica_ip02_M->Timing.offsetTimesArray[0]);

    /* task periods */
    identifica_ip02_M->Timing.sampleTimes[0] = (0.0);
    identifica_ip02_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    identifica_ip02_M->Timing.offsetTimes[0] = (0.0);
    identifica_ip02_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(identifica_ip02_M, &identifica_ip02_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = identifica_ip02_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    identifica_ip02_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(identifica_ip02_M, 5.0);
  identifica_ip02_M->Timing.stepSize0 = 0.001;
  identifica_ip02_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  identifica_ip02_M->Sizes.checksums[0] = (106978244U);
  identifica_ip02_M->Sizes.checksums[1] = (4086785444U);
  identifica_ip02_M->Sizes.checksums[2] = (2202432667U);
  identifica_ip02_M->Sizes.checksums[3] = (2367469696U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    identifica_ip02_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &identifica_ip02_DWork.CartPositionWatchdog_SubsysRanB;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &identifica_ip02_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, identifica_ip02_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(identifica_ip02_M));
  }

  identifica_ip02_M->solverInfoPtr = (&identifica_ip02_M->solverInfo);
  identifica_ip02_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&identifica_ip02_M->solverInfo, 0.001);
  rtsiSetSolverMode(&identifica_ip02_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  identifica_ip02_M->ModelData.blockIO = ((void *) &identifica_ip02_B);
  (void) memset(((void *) &identifica_ip02_B),0,
                sizeof(BlockIO_identifica_ip02));

  {
    identifica_ip02_B.EncoderInput0CartPositionEncode = 0.0;
    identifica_ip02_B.EncoderInput0CartPositionEnco_n = 0.0;
    identifica_ip02_B.Conversiontom = 0.0;
    identifica_ip02_B.Conversiontord = 0.0;
    identifica_ip02_B.Gain = 0.0;
    identifica_ip02_B.mtomm = 0.0;
    identifica_ip02_B.SquareWave = 0.0;
    identifica_ip02_B.Clock = 0.0;
    identifica_ip02_B.Fcn1 = 0.0;
    identifica_ip02_B.LookUpTable = 0.0;
    identifica_ip02_B.Amplitude = 0.0;
    identifica_ip02_B.RateLimiter = 0.0;
    identifica_ip02_B.Step = 0.0;
    identifica_ip02_B.MultiportSwitch = 0.0;
    identifica_ip02_B.mmtom = 0.0;
    identifica_ip02_B.Sum4 = 0.0;
    identifica_ip02_B.Kp = 0.0;
    identifica_ip02_B.AmplifierVoltageLimit = 0.0;
    identifica_ip02_B.CableGainPreCompensation = 0.0;
    identifica_ip02_B.DACLimit = 0.0;
    identifica_ip02_B.CableGain = 0.0;
    identifica_ip02_B.mtomm_l = 0.0;
    identifica_ip02_B.mtomm_k = 0.0;
    identifica_ip02_B.VelocidadeparaPosio = 0.0;
    identifica_ip02_B.mtomm_m = 0.0;
    identifica_ip02_B.IP02ModeloExperimental = 0.0;
    identifica_ip02_B.SwitchControl = 0.0;
    identifica_ip02_B.Sum2 = 0.0;
    identifica_ip02_B.Kp1 = 0.0;
    identifica_ip02_B.AmplifierVoltageSaturation = 0.0;
    identifica_ip02_B.SwitchControl_d = 0.0;
    identifica_ip02_B.AmplifierVoltageSaturation1 = 0.0;
    identifica_ip02_B.AceleraoparaVelocidade = 0.0;
    identifica_ip02_B.Amortecimentoviscoso = 0.0;
    identifica_ip02_B.BackEMF1 = 0.0;
    identifica_ip02_B.ForaContraeletromotriz = 0.0;
    identifica_ip02_B.Sum = 0.0;
    identifica_ip02_B.TensoparaCorrente = 0.0;
    identifica_ip02_B.SaturaoparaCorrente = 0.0;
    identifica_ip02_B.CorrenteparaFora = 0.0;
    identifica_ip02_B.Sum1 = 0.0;
    identifica_ip02_B.Inercias = 0.0;
    identifica_ip02_B.CheckMaximumAllowedPosition = 0.0;
    identifica_ip02_B.CheckMinimumAllowedPosition = 0.0;
    identifica_ip02_B.StepAmplitude = 0.0;
    identifica_ip02_B.StepAmplitude_d = 0.0;
  }

  /* parameters */
  identifica_ip02_M->ModelData.defaultParam = ((real_T *) &identifica_ip02_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &identifica_ip02_X;
    identifica_ip02_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_identifica_ip0));
  }

  /* states (dwork) */
  identifica_ip02_M->Work.dwork = ((void *) &identifica_ip02_DWork);
  (void) memset((void *)&identifica_ip02_DWork, 0,
                sizeof(D_Work_identifica_ip02));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_ip02_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  identifica_ip02_DWork.PrevY = 0.0;
  identifica_ip02_DWork.LastMajorTime = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    identifica_ip02_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void identifica_ip02_terminate(void)
{
  /* S-Function Block: identifica_ip02/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(identifica_ip02_DWork.HILInitialize_Card);
    hil_task_delete_all(identifica_ip02_DWork.HILInitialize_Card);
    hil_monitor_stop_all(identifica_ip02_DWork.HILInitialize_Card);
    hil_monitor_delete_all(identifica_ip02_DWork.HILInitialize_Card);
    is_switching = reconfiguration_is_switching_out(_reconfiguration);
    if ((identifica_ip02_P.HILInitialize_AOTerminate && !is_switching) ||
        (identifica_ip02_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &identifica_ip02_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_ip02_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_AOChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      }
    }

    if ((identifica_ip02_P.HILInitialize_DOTerminate && !is_switching) ||
        (identifica_ip02_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &identifica_ip02_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_ip02_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &identifica_ip02_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      }
    }

    if ((identifica_ip02_P.HILInitialize_POTerminate && !is_switching) ||
        (identifica_ip02_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_ip02_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_ip02_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_POChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      }
    }

    hil_close(identifica_ip02_DWork.HILInitialize_Card);
    identifica_ip02_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  identifica_ip02_output(tid);
}

void MdlUpdate(int_T tid)
{
  identifica_ip02_update(tid);
}

void MdlInitializeSizes(void)
{
  identifica_ip02_M->Sizes.numContStates = (4);/* Number of continuous states */
  identifica_ip02_M->Sizes.numY = (0); /* Number of model outputs */
  identifica_ip02_M->Sizes.numU = (0); /* Number of model inputs */
  identifica_ip02_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  identifica_ip02_M->Sizes.numSampTimes = (2);/* Number of sample times */
  identifica_ip02_M->Sizes.numBlocks = (69);/* Number of blocks */
  identifica_ip02_M->Sizes.numBlockIO = (48);/* Number of block outputs */
  identifica_ip02_M->Sizes.numBlockPrms = (173);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
  identifica_ip02_DWork.LastMajorTime = (rtInf);

  /* InitializeConditions for Integrator: '<S2>/Velocidade  para Posição' */
  identifica_ip02_X.VelocidadeparaPosio_CSTATE =
    identifica_ip02_P.VelocidadeparaPosio_IC;

  /* TransferFcn Block: '<Root>/IP02 Modelo Experimental' */
  identifica_ip02_X.IP02ModeloExperimental_CSTATE[0] = 0.0;
  identifica_ip02_X.IP02ModeloExperimental_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/Aceleração para Velocidade' */
  identifica_ip02_X.AceleraoparaVelocidade_CSTATE =
    identifica_ip02_P.AceleraoparaVelocidade_IC;
}

void MdlStart(void)
{
  /* S-Function Block: identifica_ip02/IP02/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &identifica_ip02_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      return;
    }

    is_switching = reconfiguration_is_switching_in(_reconfiguration);
    result = hil_set_card_specific_options
      (identifica_ip02_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(identifica_ip02_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      return;
    }

    if ((identifica_ip02_P.HILInitialize_AIPStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &identifica_ip02_DWork.HILInitialize_AIMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = identifica_ip02_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &identifica_ip02_DWork.HILInitialize_AIMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = identifica_ip02_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_AIChannels[0], 8U,
         &identifica_ip02_DWork.HILInitialize_AIMinimums[0],
         &identifica_ip02_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_AOPStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &identifica_ip02_DWork.HILInitialize_AOMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = identifica_ip02_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &identifica_ip02_DWork.HILInitialize_AOMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = identifica_ip02_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_AOChannels[0], 8U,
         &identifica_ip02_DWork.HILInitialize_AOMinimums[0],
         &identifica_ip02_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_AOStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &identifica_ip02_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_ip02_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_AOChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if (identifica_ip02_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &identifica_ip02_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_ip02_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_AOChannels[0], 8U,
         &identifica_ip02_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(identifica_ip02_DWork.HILInitialize_Card,
      NULL, 0U, &identifica_ip02_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
      return;
    }

    if ((identifica_ip02_P.HILInitialize_DOStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &identifica_ip02_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_ip02_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &identifica_ip02_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if (identifica_ip02_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &identifica_ip02_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = identifica_ip02_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &identifica_ip02_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_EIPStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &identifica_ip02_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = identifica_ip02_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &identifica_ip02_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_EIStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &identifica_ip02_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = identifica_ip02_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_EIChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_POPStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_ip02_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = identifica_ip02_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &identifica_ip02_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &identifica_ip02_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &identifica_ip02_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            identifica_ip02_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            identifica_ip02_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = identifica_ip02_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            identifica_ip02_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            identifica_ip02_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = identifica_ip02_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(identifica_ip02_DWork.HILInitialize_Card,
          &identifica_ip02_DWork.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &identifica_ip02_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(identifica_ip02_DWork.HILInitialize_Card,
          &identifica_ip02_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &identifica_ip02_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_ip02_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = identifica_ip02_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &identifica_ip02_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = identifica_ip02_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &identifica_ip02_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = identifica_ip02_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &identifica_ip02_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *) &identifica_ip02_DWork.HILInitialize_POAlignValues
         [0],
         (t_pwm_polarity *) &identifica_ip02_DWork.HILInitialize_POPolarityVals
         [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &identifica_ip02_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = identifica_ip02_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &identifica_ip02_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_ip02_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_POChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_POSortedFreqs[0],
        &identifica_ip02_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_ip02_P.HILInitialize_POStart && !is_switching) ||
        (identifica_ip02_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_ip02_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_ip02_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(identifica_ip02_DWork.HILInitialize_Card,
        &identifica_ip02_P.HILInitialize_POChannels[0], 8U,
        &identifica_ip02_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }

    if (identifica_ip02_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_ip02_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_ip02_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (identifica_ip02_DWork.HILInitialize_Card,
         &identifica_ip02_P.HILInitialize_POChannels[0], 8U,
         &identifica_ip02_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: identifica_ip02/IP02/Encoder Input #0: Cart Position Encoder Input #1: Pendulum Angle (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (identifica_ip02_DWork.HILInitialize_Card,
       identifica_ip02_P.EncoderInput0CartPositionEnco_a,
       identifica_ip02_P.EncoderInput0CartPositionEnco_l, 2,
       &identifica_ip02_DWork.EncoderInput0CartPositionEnco_m);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_ip02_M, _rt_error_message);
    }
  }

  /* Start for enable SubSystem: '<S1>/Cart Position Watchdog' */
  identifica_ip02_DWork.CartPositionWatchdog_MODE = SUBSYS_DISABLED;

  /* end of Start for SubSystem: '<S1>/Cart Position Watchdog' */
  MdlInitialize();
}

RT_MODEL_identifica_ip02 *identifica_ip02(void)
{
  identifica_ip02_initialize(1);
  return identifica_ip02_M;
}

void MdlTerminate(void)
{
  identifica_ip02_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
