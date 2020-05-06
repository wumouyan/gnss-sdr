/*
 * SPDX-FileCopyrightText: (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * SPDX-License-Identifier: BSD-1-Clause
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "RRLP-Components"
 *     found in "../rrlp-components.asn"
 */

#include "GANSSGenericAssistDataElement.h"

static int memb_ganssID_constraint_1(asn_TYPE_descriptor_t *td,
    const void *sptr,
    asn_app_constraint_failed_f *ctfailcb,
    void *app_key)
{
    long value;

    if (!sptr)
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: value not given (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }

    value = *(const long *)sptr;

    if ((value >= 0 && value <= 7))
        {
            /* Constraint check succeeded */
            return 0;
        }
    else
        {
            _ASN_CTFAIL(app_key, td, sptr, "%s: constraint failed (%s:%d)",
                td->name, __FILE__, __LINE__);
            return -1;
        }
}

static asn_per_constraints_t ASN_PER_MEMB_GANSS_ID_CONSTR_2 = {
    {APC_CONSTRAINED, 3, 3, 0, 7} /* (0..7) */,
    {APC_UNCONSTRAINED, -1, -1, 0, 0},
    0,
    0 /* No PER value map */
};
static asn_TYPE_member_t asn_MBR_GANSSGenericAssistDataElement_1[] = {
    {ATF_POINTER, 9, offsetof(struct GANSSGenericAssistDataElement, ganssID),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_NativeInteger, memb_ganssID_constraint_1,
        &ASN_PER_MEMB_GANSS_ID_CONSTR_2, 0, "ganssID"},
    {ATF_POINTER, 8,
        offsetof(struct GANSSGenericAssistDataElement, ganssTimeModel),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_SeqOfGANSSTimeModel,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssTimeModel"},
    {ATF_POINTER, 7,
        offsetof(struct GANSSGenericAssistDataElement, ganssDiffCorrections),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSDiffCorrections,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssDiffCorrections"},
    {ATF_POINTER, 6,
        offsetof(struct GANSSGenericAssistDataElement, ganssNavigationModel),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSNavModel,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssNavigationModel"},
    {ATF_POINTER, 5,
        offsetof(struct GANSSGenericAssistDataElement, ganssRealTimeIntegrity),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSRealTimeIntegrity,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssRealTimeIntegrity"},
    {ATF_POINTER, 4,
        offsetof(struct GANSSGenericAssistDataElement, ganssDataBitAssist),
        (ASN_TAG_CLASS_CONTEXT | (5 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSDataBitAssist,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssDataBitAssist"},
    {ATF_POINTER, 3,
        offsetof(struct GANSSGenericAssistDataElement, ganssRefMeasurementAssist),
        (ASN_TAG_CLASS_CONTEXT | (6 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSRefMeasurementAssist,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssRefMeasurementAssist"},
    {ATF_POINTER, 2,
        offsetof(struct GANSSGenericAssistDataElement, ganssAlmanacModel),
        (ASN_TAG_CLASS_CONTEXT | (7 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSAlmanacModel,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssAlmanacModel"},
    {ATF_POINTER, 1,
        offsetof(struct GANSSGenericAssistDataElement, ganssUTCModel),
        (ASN_TAG_CLASS_CONTEXT | (8 << 2)), -1, /* IMPLICIT tag at current level */
        &asn_DEF_GANSSUTCModel,
        0, /* Defer constraints checking to the member type */
        0, /* No PER visible constraints */
        0, "ganssUTCModel"},
};
static int asn_MAP_GANSSGenericAssistDataElement_oms_1[] = {0, 1, 2, 3, 4,
    5, 6, 7, 8};
static ber_tlv_tag_t asn_DEF_GANSSGenericAssistDataElement_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))};
static asn_TYPE_tag2member_t asn_MAP_GANSSGenericAssistDataElement_tag2el_1[] =
    {
        {(ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0}, /* ganssID at 1082 */
        {(ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0,
            0}, /* ganssTimeModel at 1083 */
        {(ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0,
            0}, /* ganssDiffCorrections at 1084 */
        {(ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0,
            0}, /* ganssNavigationModel at 1085 */
        {(ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0,
            0}, /* ganssRealTimeIntegrity at 1086 */
        {(ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0,
            0}, /* ganssDataBitAssist at 1087 */
        {(ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0,
            0}, /* ganssRefMeasurementAssist at 1088 */
        {(ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0,
            0}, /* ganssAlmanacModel at 1089 */
        {(ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0,
            0} /* ganssUTCModel at 1090 */
};
static asn_SEQUENCE_specifics_t asn_SPC_GANSSGenericAssistDataElement_specs_1 =
    {
        sizeof(struct GANSSGenericAssistDataElement),
        offsetof(struct GANSSGenericAssistDataElement, _asn_ctx),
        asn_MAP_GANSSGenericAssistDataElement_tag2el_1,
        9,                                           /* Count of tags in the map */
        asn_MAP_GANSSGenericAssistDataElement_oms_1, /* Optional members */
        9,
        0, /* Root/Additions */
        8, /* Start extensions */
        10 /* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_GANSSGenericAssistDataElement = {
    "GANSSGenericAssistDataElement",
    "GANSSGenericAssistDataElement",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
    0, /* Use generic outmost tag fetcher */
    asn_DEF_GANSSGenericAssistDataElement_tags_1,
    sizeof(asn_DEF_GANSSGenericAssistDataElement_tags_1) /
        sizeof(asn_DEF_GANSSGenericAssistDataElement_tags_1[0]), /* 1 */
    asn_DEF_GANSSGenericAssistDataElement_tags_1,                /* Same as above */
    sizeof(asn_DEF_GANSSGenericAssistDataElement_tags_1) /
        sizeof(asn_DEF_GANSSGenericAssistDataElement_tags_1[0]), /* 1 */
    0,                                                           /* No PER visible constraints */
    asn_MBR_GANSSGenericAssistDataElement_1,
    9,                                             /* Elements count */
    &asn_SPC_GANSSGenericAssistDataElement_specs_1 /* Additional specs */
};
