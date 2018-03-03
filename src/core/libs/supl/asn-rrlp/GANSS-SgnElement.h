/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 * 	found in "../rrlp-components.asn"
 */

#ifndef _GANSS_SgnElement_H_
#define _GANSS_SgnElement_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SVID.h"
#include <NativeInteger.h>
#include "MpathIndic.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GANSS-SgnElement */
typedef struct GANSS_SgnElement
{
    SVID_t svID;
    long cNo;
    MpathIndic_t mpathDet;
    long *carrierQualityInd /* OPTIONAL */;
    long codePhase;
    long *integerCodePhase /* OPTIONAL */;
    long codePhaseRMSError;
    long *doppler /* OPTIONAL */;
    long *adr /* OPTIONAL */;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} GANSS_SgnElement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GANSS_SgnElement;

#ifdef __cplusplus
}
#endif

#endif /* _GANSS_SgnElement_H_ */
#include <asn_internal.h>
