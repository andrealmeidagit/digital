/*
 * identifica_ip02_private.h
 *
 * Real-Time Workshop code generation for Simulink model "identifica_ip02.mdl".
 *
 * Model Version              : 1.506
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Oct 31 09:47:59 2019
 */
#ifndef RTW_HEADER_identifica_ip02_private_h_
#define RTW_HEADER_identifica_ip02_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern t_reconfiguration _reconfiguration;

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];

/* private model entry point functions */
extern void identifica_ip02_derivatives(void);

#endif                                 /* RTW_HEADER_identifica_ip02_private_h_ */
