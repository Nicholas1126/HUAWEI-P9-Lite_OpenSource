/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : NasCcMmccProc.h
  �� �� ��   : ����
  ��    ��   : ���� 49431
  ��������   : 2007��8��31��
  ����޸�   : 2007��8��31��
  ��������   : ���պʹ�������MM��MMCCԭ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2007��8��31��
    ��    ��   : ���� 49431
    �޸�����   : �����ļ�

  2.��    ��   : 2010��3��2��
    ��    ��   : zhoujun /z40661
    �޸�����   : NAS R7Э������
******************************************************************************/
#ifndef  NAS_CC_MMCC_PROC_H
#define  NAS_CC_MMCC_PROC_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include  "NasOmInterface.h"
#include "NasOmTrans.h"

/*****************************************************************************
  3 ���Ͷ���
*****************************************************************************/
typedef struct
{
    NAS_CC_MSG_TYPE_ENUM_U8       enCcMsgId;
    NAS_OTA_MSG_ID_ENUM_UINT16    enOtaMsgId;
} NAS_CC_OTA_MSG_ID_STRU;

/*****************************************************************************
  4 ��������
*****************************************************************************/
/*****************************************************************************
 �� �� ��  : NAS_CC_ProcMmccPrimitive
 ��������  : ���պʹ�������MM��MMCCԭ��
 �������  : pMsg - MM����CC����Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��1��16��
    ��    ��   : ���� 49431
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID  NAS_CC_ProcMmccPrimitive(
    const VOS_VOID                      *pMsg
);

/*****************************************************************************
 �� �� ��  : NAS_CC_LocalAbortDtmf
 ��������  : ֪ͨMN DTMF�������
 �������  : pMsg - MM����CC����Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2008��07��02��
    ��    ��   : ���� 49431
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_VOID NAS_CC_LocalAbortDtmf(
    NAS_CC_ENTITY_ID_T                  entityId
);

/*****************************************************************************
 �� �� ��  : NAS_CC_ProcMmccRrcConnRelInd
 ��������  : ���պʹ�������MM����buffԭ��
 �������  : pMsg - MM����CC����Ϣ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��12��12��
    ��    ��   : j00174725
    �޸�����   : DTS2015121001913
*****************************************************************************/
VOS_VOID  NAS_CC_ProcMmccRrcConnRelInd(
    const VOS_VOID                      *pMsg
);



#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* NAS_CC_MMCC_PROC_H */
