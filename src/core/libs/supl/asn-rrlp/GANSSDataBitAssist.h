/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 * 	found in "../rrlp-components.asn"
 */

#ifndef _GANSSDataBitAssist_H_
#define _GANSSDataBitAssist_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "SVID.h"
#include "SeqOf-GANSSDataBits.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GANSSDataBitAssist */
typedef struct GANSSDataBitAssist
{
    long ganssTOD;
    SVID_t svID;
    long ganssDataTypeID;
    SeqOf_GANSSDataBits_t ganssDataBits;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} GANSSDataBitAssist_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GANSSDataBitAssist;

#ifdef __cplusplus
}
#endif

#endif /* _GANSSDataBitAssist_H_ */
#include <asn_internal.h>
