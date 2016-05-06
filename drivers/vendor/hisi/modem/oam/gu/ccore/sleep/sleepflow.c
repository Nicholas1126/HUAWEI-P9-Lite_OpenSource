/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : SleepFlow.c
  �� �� ��   : ����
  ��    ��   : zuowen
  ��������   : 2005��3��7��
  ����޸�   :
  ��������   : ʵ�� SLEEP ˯��/������������
  �����б�   :
  �޸���ʷ   :

  1.��    ��   : 2005��3��7��
    ��    ��   : zuowen
    �޸�����   : �����ļ�

  2.��    ��   : 2006��1��14��
    ��    ��   : wangqinghua
    �޸�����   : ���ɲ��Ժ�� SLEEP ģ������޸�
  3.
    ��    ��   : 2006��4��13��
    ��    ��   : w45442
    �޸�����   : �޸����ⵥA32D03034

******************************************************************************/

#include "vos.h"
#include "hpacomm.h"
#include "sleepflow.h"
#include "hpaoperatertt.h"
#include "bbp_wcdma_on_interface.h"
#include "bbp_wcdma_interface.h"
#include "bbp_gsm_on_interface.h"
#include "apminterface.h"
#include "OmApi.h"
#include "PamOamSpecTaskDef.h"
#include "TtfOamInterface.h"
#include "NVIM_Interface.h"
#include "DrvNvInterface.h"
#include "v_private.h"
#include "omprivate.h"
#include "PhyNvDefine.h"
#include "apmprocess.h"
#include "mlowpower.h"
#include "msp_diag_comm.h"
#include "psregrpt.h"

#include "product_config.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
    Э��ջ��ӡ��㷽ʽ�µ�.C�ļ��궨��
*****************************************************************************/
/*lint -e767 �޸��ˣ�h28225�������ˣ�l46160��ԭ������������־�ļ���ID����*/
#define    THIS_FILE_ID        PS_FILE_ID_SLEEP_FLOW_C
/*lint +e767 �޸��ˣ�h28225�������ˣ�l46160��*/

#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)
extern VOS_UINT32 PsRegGetDmaCaptureStatus(MODEM_ID_ENUM_UINT16 enModemId);
#endif

SLEEP_INFO_STATE_STRU*                  g_pstSleepInfoSlice;

/* ���GUģ��ǰϵͳ״̬ */
SLEEP_MODE_INFO_STRU                    g_astSleepModeInfo[SLEEP_GU_MODE_TYPE_BUTT];

/* ���Cģ��ǰϵͳ״̬ */
SLEEP_BBE16_MODE_INFO_STRU              g_astSleepBBE16ModeInfo[SLEEP_C_MODE_TYPE_BUTT];

T_MODEM_SR_STAMP_STRU                  *g_pstSleepWakeSliceAddr = VOS_NULL_PTR;

/* CģOAM��BBE16֮��SRAM��Ϣ */
CPHY_OAM_SHARE_INFO_STRU               *g_pstBBE16SleepInfo = VOS_NULL_PTR;

VOS_VOID SHPA_ActivateHw(VOS_VOID)
{
    return;
}

VOS_VOID SHPA_DeactivateHw(VOS_VOID)
{
    return;
}

VOS_VOID SLEEP_EnterLowPower(VOS_VOID)
{
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_EnableDspPll
 ��������  : ʹ��DSP PLL
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

*****************************************************************************/
VOS_VOID SLEEP_EnableDspPll(VOS_VOID)
{
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ExitLowPower
 ��������  : �˳������͹���
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_ExitLowPower(SLEEP_MODE_ENUM_UINT32 enMode)
{
    return;
}


/*****************************************************************************
 �� �� ��  : SLEEP_IsSleep
 ��������  : ����ϵͳ��״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2010��10��22��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_BOOL SLEEP_IsSleep(VOS_VOID)
{
    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : Sleep_ActiveDspPll
 ��������  : ʹ��DSP PLL,��HPA����
 �������  : ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

*****************************************************************************/
VOS_VOID Sleep_ActiveDspPll(VOS_VOID)
{
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_NotifySndMsg
 ��������  : ֪ͨSLEEPģ������Ϣ���͵�DSP
 �������  : pMsgBlock
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_NotifySndMsg(VOS_VOID)
{
    return;
}

/*****************************************************************************
 �� �� ��  : GUSLEEP_MasterAwakeSlave
 ��������  : ��ģ����GU��ģ�ӿ�
 �������  : ��
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID GUSLEEP_MasterAwakeSlave(VOS_VOID)
{
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_32KIsr
 ��������  : ���� 32K ʱ���ж�
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_32KIsr(SLEEP_MODE_ENUM_UINT32 enMode)
{
    if ((SLEEP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
        || (SLEEP_MASTER_TEMP_LP_STATE == g_astSleepModeInfo[enMode].enSystemState))
    {
        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_BBP_32K);

        SLEEP_WAKE_SLICE_RECORD(0);

        SLEEP_SleepIsrProc(BBP_SLEEP_32K_CLOCK_SWITCH_IND, enMode);
    }
}

/*****************************************************************************
 �� �� ��  : SLEEP_NormalClockIsr
 ��������  : ���� DRX���Ѻ�ʱ���л���61.44M�ж�
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_NormalClockIsr(SLEEP_MODE_ENUM_UINT32 enMode)
{
    SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_BBP_NORMAL);

    if ((SLEEP_TEMP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
        || (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[enMode].enSystemState))
    {
        SLEEP_AwakeIsrProc(BBP_SLEEP_NORMAL_CLOCK_SWITCH_IND, enMode);
    }
}

/*****************************************************************************
 �� �� ��  : SLEEP_AwakeIsr
 ��������  : ���������ж�
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_AwakeIsr(SLEEP_MODE_ENUM_UINT32 enMode)
{
    if (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_BBP_WAKE);

        SLEEP_WAKE_SLICE_RECORD(4);

        SLEEP_AwakeIsrProc(BBP_SLEEP_WAKE_IND, enMode);
    }
}

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/

/* PHY������Ϣ������ */
SLEEP_MSG_FUN_STRU g_astSleepPhyMsgFunTbl[] =
{
    {ID_UPHY_OAM_MASTER_SLEEP_IND,      SLEEP_MasterSleepMsgProc},
    {ID_UPHY_OAM_SLAVE_SLEEP_IND,       SLEEP_SlaveSleepMsgProc},
};

/* �ж���Ϣ������ */
SLEEP_MSG_FUN_STRU g_astSleepIsrMsgFunTbl[] =
{
    {BBP_SLEEP_32K_CLOCK_SWITCH_IND,    SLEEP_32KClkMsgProc},
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    {BBE16_SLEEP_SLEEP_IND,             SLEEP_BBE16HaltMsgProc},
#endif
};

/* AWAKE�ж���Ϣ������ */
SLEEP_MSG_FUN_STRU g_astAwakeIsrMsgFunTbl[] =
{
    {BBP_SLEEP_WAKE_IND,                SLEEP_WakeMasterMsgProc},
    {BBP_SLEEP_NORMAL_CLOCK_SWITCH_IND, SLEEP_NormalClkMsgProc},
    {SLEEP_WAKE_MASTER_GU_IND,          SLEEP_WakeMasterGUProc},
    {SLEEP_WAKE_SLAVE_GU_IND,           SLEEP_WakeSlaveGUProc},
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    {BBE16_SLEEP_AWAKE_IND,             SLEEP_BBE16AwakeMsgProc},
    {BBE16_SLEEP_RESUME_IND,            SLEEP_BBE16ResumeMsgProc},
    {BBE16_SLEEP_MASTER_WAKE_IND,       SLEEP_BBE16MasterForceWakeProc},
    {BBE16_SLEEP_SLAVE_WAKE_IND,        SLEEP_BBE16SlaveForceWakeProc},
#endif
};

/* SLEEP���̼�¼ */
SLEEP_TRACK_RECORD_STRU                *g_pstSleepTrackRecord   = VOS_NULL_PTR;
SLEEP_NORMAL_STATE_RECORD_STRU         *g_pstSleepNormalState   = VOS_NULL_PTR;

HIFI_STATE_STRU                        *g_pstHifiStateSlice     = VOS_NULL_PTR;
HPA_LOAD_PHY_STATE_STRU                *g_pstLoadPhyState       = VOS_NULL_PTR;

SLEEP_DEVICE_STATE_STRU                *g_pstSleepDeviceState   = VOS_NULL_PTR;

/* �����ź��� */
VOS_SEM                                 g_ulSleepSem;

/* TCXO�ȶ��ź��� */
VOS_SEM                                 g_ulSleepTcxoSem;

/* BBP�Ĵ������ݻָ����� */
VOS_UINT32                              g_ulSleepBBPPosValue    = 0;

VOS_UINT32                              g_ulSleepRusumeTime     = 0;

/* �����ָ�ʱ�� */
WG_DRX_RESUME_TIME_STRU                 g_stSleepDrxResumeTime;

VOS_BOOL                                g_bDrxResetFlag = VOS_FALSE;

/* ע���PID�����ڵ͹���״̬����֪ͨ��ע��PID */
SLEEP_NOTIFY_STATE_REG_PID_STRU         g_stSleepNotifyStateRegPidTbl;

#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)
VOS_UINT32                              g_ulIsWaitingDMACap = VOS_FALSE;

/* DMA�Ĵ��������ź��� */
VOS_SEM                                 g_ulSleepDMACapSem;
#endif

/* ��������������sleep���ٽ���Դ���� */
VOS_SPINLOCK                            g_stSleepSpinLock;

/* CDMAģʽ������Ϣ */
SLEEP_CDMA_STATE_STRU                   g_stSleepCDMAControl;

SLEEP_BBE16_NORMAL_STATE_RECORD_STRU   *g_pstSleepBBE16NormalState   = VOS_NULL_PTR;

SLEEP_BBE16_CPROC_CTRL_STRU             g_stSleepCprocCtrl[VOS_RATMODE_BUTT];

VOS_UINT32                              g_ulConnectFlag = VOS_FALSE;

UCOM_NV_TRI_MODE_FEM_PROFILE_ID_STRU    g_stChannelModeProfileId;

#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
UCOM_NV_FEM_CHAN_PROFILE_STRU           g_stChannelModeProfile;
#else
UCOM_NV_TRI_MODE_FEM_CHAN_PROFILE_STRU  g_stChannelModeProfile;
#endif

#ifndef SLEEP_BIT_N
#define SLEEP_BIT_N(num)                      (0x01 << (num))
#endif

VOS_UINT32                              g_ulSleepSlaveMsgTrackId = 0;

SLEEP_SLAVE_MSG_TRACK_STRU              g_astSleepSlaveMsgTrack[SLEEP_SLAVE_MSG_TRACK_NUM];

VOS_UINT32                              g_ulSleepNotifyMsgTrackId = 0;

SLEEP_NOTIFY_MSG_TRACK_STRU             g_astSleepNotifyMsgTrack[SLEEP_NOTIFY_MSG_TRACK_NUM];

/* modem0��modem2���Ᵽ���ź��� */
#if defined (INSTANCE_1) || defined (INSTANCE_2)
extern VOS_SEM                          g_ulSleepSlaveSem;
#else
VOS_SEM                                 g_ulSleepSlaveSem;
#endif

VOS_UINT32                              g_ulSleepSlaveSemFlag = VOS_FALSE;


/*****************************************************************************
  3 ��������
*****************************************************************************/

/*****************************************************************************
 �� �� ��  : SLEEP_NotifyStateRegPidTblInit
 ��������  : ע��PID���ĳ�ʼ��
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��14��
    ��    ��   : L00256032
    �޸�����   : V8R1 LowPower&NV_Expand��Ŀ����

*****************************************************************************/
VOS_VOID SLEEP_NotifyStateRegPidTblInit( VOS_VOID )
{
    VOS_UINT32      ulLoop;

    for (ulLoop = 0; ulLoop < SLEEP_NOTIFY_STATE_REG_PID_MAX; ulLoop++)
    {
        g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop] = SLEEP_INVALID_PID;
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_NotifyStateReg
 ��������  : �͹���״̬֪ͨע�ắ��������PID�ظ�ע����жϣ���ע�᷽���̱�֤
 �������  : ulRcvPid:����״ָ̬ʾ��PID
             VOS_RATMODE_ENUM_UINT32 enRatMode
 �������  : ��
 �� �� ֵ  : VOS_OK : ע��ɹ�
             VOS_ERR: ע��ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��14��
    ��    ��   : L00256032
    �޸�����   : V8R1 LowPower&NV_Expand��Ŀ����

*****************************************************************************/
VOS_UINT32 SLEEP_NotifyStateReg(VOS_UINT32 ulRcvPid, VOS_RATMODE_ENUM_UINT32 enRatMode)
{
    VOS_UINT32                          ulLoop;
    VOS_INT32                           lLockKey;
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enState;

    /* ע��PID�Ϸ��� */
    if ((ulRcvPid < VOS_PID_DOPRAEND) || (ulRcvPid >= VOS_PID_BUTT))
    {
        /* �쳣��ά�ɲ��ӡ */
        PS_LOG(WUEPS_PID_SLEEP, 0, PS_PRINT_WARNING, "SLEEP_NotifyStateReg: register invalid PID.");

        return VOS_ERR;
    }

    /* ���ж� */
    lLockKey = VOS_SplIMP();

    /* ��PID�ŵ�ע����� */
    for (ulLoop = 0; ulLoop < SLEEP_NOTIFY_STATE_REG_PID_MAX; ulLoop++)
    {
        if (ulRcvPid == g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop])
        {
            enState = g_astSleepModeInfo[enRatMode].enSystemState;

            /* ���ж� */
            VOS_Splx(lLockKey);

            SLEEP_NotifyStateToRegPid(enRatMode, enState);

            return VOS_OK;
        }
    }

    for (ulLoop = 0; ulLoop < SLEEP_NOTIFY_STATE_REG_PID_MAX; ulLoop++)
    {
        /* �ҵ��յ�PID���λ�� */
        if (SLEEP_INVALID_PID == g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop])
        {
            /* �洢ע���PID */
            g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop] = ulRcvPid;

            enState = g_astSleepModeInfo[enRatMode].enSystemState;

            /* ���ж� */
            VOS_Splx(lLockKey);

            SLEEP_NotifyStateToRegPid(enRatMode, enState);

            return VOS_OK;
        }
    }

    /* ���ж� */
    VOS_Splx(lLockKey);

    /* �Ҳ����յĴ��λ�ã���ӡ��ά�ɲ���Ϣ */
    PS_LOG1(WUEPS_PID_SLEEP, 0, PS_PRINT_WARNING, "SLEEP_NotifyStateReg: No empty entry.", (VOS_INT32)ulRcvPid);

    return VOS_ERR;
}

/*****************************************************************************
 �� �� ��  : SLEEP_NotifyStateUnreg
 ��������  : �͹���״̬֪ͨȥע�ắ��
 �������  : ulRcvPid:������״ָ̬ʾ��PID
 �������  : ��
 �� �� ֵ  : VOS_OK : ȥע��ɹ�
             VOS_ERR: ȥע��ʧ��(δ�ҵ�ƥ��PID)
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��14��
    ��    ��   : L00256032
    �޸�����   : V8R1 LowPower&NV_Expand��Ŀ����

*****************************************************************************/
VOS_UINT32 SLEEP_NotifyStateUnreg(VOS_UINT32 ulRcvPid)
{
    VOS_UINT32      ulLoop;
    VOS_INT32       lLockKey;

    /* ���ж� */
    lLockKey = VOS_SplIMP();

    /* �ж��Ƿ��Ѿ�ע�����PID */
    for (ulLoop = 0; ulLoop < SLEEP_NOTIFY_STATE_REG_PID_MAX; ulLoop++)
    {
        if (ulRcvPid == g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop])
        {
            /* ����PID�ӱ���ȥ�� */
            g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ulLoop] = SLEEP_INVALID_PID;

            /* ���ж� */
            VOS_Splx(lLockKey);

            return VOS_OK;
        }
    }

    /* ���ж� */
    VOS_Splx(lLockKey);

    /* δ�ҵ�ƥ��PID���쳣��ӡ�ͼ�¼ */
    PS_LOG1(WUEPS_PID_SLEEP, 0, PS_PRINT_WARNING, "SLEEP_NotifyStateUnreg: PID hasn't been found.", (VOS_INT32)ulRcvPid);

    return VOS_ERR;
}

/*****************************************************************************
 �� �� ��  : SLEEP_NotifyStateToRegPid
 ��������  : ֪ͨע��PID��Ӧ�͹���״̬
 �������  :
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��14��
    ��    ��   : L00256032
    �޸�����   : V8R1 LowPower&NV_Expand��Ŀ����

*****************************************************************************/
VOS_VOID SLEEP_NotifyStateToRegPid(
    VOS_RATMODE_ENUM_UINT32             enRatMode,
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enState)
{
    SLEEP_NOTIFY_STATUS_MSG_STRU       *pstMsg;
    VOS_UINT32                          ucLoop;
    VOS_UINT32                          ulMsgLen;

    for (ucLoop = 0; ucLoop < SLEEP_NOTIFY_STATE_REG_PID_MAX; ucLoop++)
    {
        if (SLEEP_INVALID_PID == g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ucLoop])
        {
            continue;
        }

        ulMsgLen = sizeof(SLEEP_NOTIFY_STATUS_MSG_STRU) - VOS_MSG_HEAD_LENGTH;

        pstMsg = (SLEEP_NOTIFY_STATUS_MSG_STRU *)VOS_AllocMsg(WUEPS_PID_SLEEP, ulMsgLen);
        if (VOS_NULL_PTR == pstMsg)
        {
            PS_LOG(WUEPS_PID_SLEEP, 0, PS_PRINT_ERROR, "SLEEP_NotifyStateToRegPid: Alloc msg fail.");
            return;
        }

        /* �����Ϣ���� */
        pstMsg->ulReceiverPid      = g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ucLoop];
        pstMsg->enMsgId            = ID_SLEEP_NOTIFY_STATUS_IND;
        pstMsg->enRatMode          = enRatMode;
        pstMsg->enState            = enState;
        if (VOS_TRUE == UPHY_DSDA_GetGsmSlaveDrxFlag(SLEEP_GetModemId()))
        {
            pstMsg->enLPState       = SLEEP_LOWPOWER_STATE_ON;
        }
        else
        {
            pstMsg->enLPState       = SLEEP_LOWPOWER_STATE_OFF;
        }

        g_astSleepNotifyMsgTrack[g_ulSleepNotifyMsgTrackId].ulRegPid    = g_stSleepNotifyStateRegPidTbl.aulRegPidTbl[ucLoop];
        g_astSleepNotifyMsgTrack[g_ulSleepNotifyMsgTrackId].enRatMode   = enRatMode;
        g_astSleepNotifyMsgTrack[g_ulSleepNotifyMsgTrackId].enState     = enState;
        g_astSleepNotifyMsgTrack[g_ulSleepNotifyMsgTrackId].enLPState   = UPHY_DSDA_GetGsmSlaveDrxFlag(SLEEP_GetModemId());
        g_astSleepNotifyMsgTrack[g_ulSleepNotifyMsgTrackId].ulSlice     = OM_GetSlice();

        g_ulSleepNotifyMsgTrackId++;

        if (SLEEP_NOTIFY_MSG_TRACK_NUM == g_ulSleepNotifyMsgTrackId)
        {
            g_ulSleepNotifyMsgTrackId   = 0;
        }

        if (VOS_OK != VOS_SendMsg(WUEPS_PID_SLEEP, pstMsg))
        {
            PS_LOG(WUEPS_PID_SLEEP, 0, PS_PRINT_ERROR, "SLEEP_NotifyStateToRegPid: send msg fail.");
        }
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_GetModemId
 ��������  : ��ȡ��ǰ���ڵ�Modem ID
 �������  : ��
 �������  : ��
 �� �� ֵ  : MODEM_ID_ENUM_UINT16
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��14��
    ��    ��   : L00256032
    �޸�����   : V8R1 LowPower&NV_Expand��Ŀ����

*****************************************************************************/
MODEM_ID_ENUM_UINT16 SLEEP_GetModemId(VOS_VOID)
{
#if defined (INSTANCE_2)
    return MODEM_ID_2;
#elif defined (INSTANCE_1)
    return MODEM_ID_1;
#else
    return MODEM_ID_0;
#endif
}

/*****************************************************************************
 �� �� ��  : SLEEP_TaskDelay
 ��������  : �����ӳٽӿڣ�CPUѭ����ȡsliceֵ�������Խӿ�
 �������  : VOS_UINT32 ulSliceDelay
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��21��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_TaskDelay( VOS_UINT32 ulSliceDelay )
{
    VOS_UINT32                          ulSlice;

    ulSlice = OM_GetSlice();

    while((ulSliceDelay) > (OM_GetSlice() - ulSlice))
    {
        ;
    }

    return;
}


/*****************************************************************************
 �� �� ��  : SLEEP_IsAwake
 ��������  : �жϵ�ǰ�Ƿ�����
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_BOOL
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��26��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_BOOL SLEEP_IsAwake( SLEEP_MODE_ENUM_UINT32 enMode )
{
    if ((VOS_RATMODE_GSM == enMode) || (VOS_RATMODE_WCDMA == enMode))
    {
        if (SLEEP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
        {
            return VOS_TRUE;
        }
    }
    else if (VOS_RATMODE_1X == enMode)
    {
        if (SLEEP_BBE16_NORMAL_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        {
            return VOS_TRUE;
        }
    }
    else
    {
        /* error */
    }

    return VOS_FALSE;
}

/*****************************************************************************
 �� �� ��  : SLEEP_IsSlaveSleep
 ��������  : ��ȡ��ǰģʽ�Ƿ��ڴ�ģ�͹���״̬
 �������  : SLEEP_MODE_ENUM_UINT32 enMode  ��ǰģʽ
 �������  : ��
 �� �� ֵ  : VOS_BOOL   VOS_TRUE    ��ǰģʽ���ڴ�ģ�͹���̬
                        VOS_FALSE   ��ǰģʽû�д��ڴ�ģ�͹���״̬
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��11��30��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_BOOL SLEEP_IsSlaveSleep(SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_INT                             lLockLevel;
    VOS_BOOL                            ulRet   = VOS_FALSE;

    lLockLevel = VOS_SplIMP();

    if ((VOS_RATMODE_GSM == enMode) || (VOS_RATMODE_WCDMA == enMode))
    {
        if (SLEEP_SLAVE_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
        {
            ulRet = VOS_TRUE;
        }
    }
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    else if ((VOS_RATMODE_1X == enMode) || (VOS_RATMODE_HRPD == enMode))
    {
        if ((SLEEP_BBE16_MASTER_LP_STATE == g_astSleepBBE16ModeInfo[VOS_RATMODE_1X].enSystemState)
            ||(SLEEP_BBE16_SLAVE_LP_STATE == g_astSleepBBE16ModeInfo[VOS_RATMODE_1X].enSystemState))
        {
            ulRet = VOS_TRUE;
        }
    }
#endif
    else
    {
    }

    VOS_Splx(lLockLevel);

    return ulRet;
}

/*****************************************************************************
 �� �� ��  : SLEEP_AwakeInfoGet
 ��������  : ��ȡ�����ϵ�����
 �������  : SLEEP_MODE_ENUM_UINT32 enMode  ��ǰģʽ
             VOS_UINT32 uLen                ��������鳤��
 �������  : VOS_UINT32 *pstDrxInfo         �ϵ�����ʱ����Ϣ
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2014��3��11��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 SLEEP_AwakeInfoGet( SLEEP_MODE_ENUM_UINT32 enMode, VOS_UINT32 *pstAwakeHWInfo, VOS_UINT32 uLen )
{
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ( (VOS_NULL_PTR == pstAwakeHWInfo)
        || (enMode > VOS_RATMODE_WCDMA)
        || (uLen < UPHY_OAM_SLEEP_INFO_NUM) )
    {
        return VOS_ERR;
    }

    /*lint -e534*/
    VOS_MemSet(pstAwakeHWInfo, 0x0, sizeof(VOS_UINT32)*uLen);
    /*lint +e534*/

    pstAwakeHWInfo[0]
        = 0x887755AA;
    pstAwakeHWInfo[1]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_BBP_WAKE].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_BBP_WAKE].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[2]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_ACTIVATE_START].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_ACTIVATE_START].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[3]
        = g_pstSleepDeviceState->aulDeviceUpSlice[enModem][enMode][PWC_COMM_MODULE_ABB][PWC_COMM_CHANNEL_0];
    pstAwakeHWInfo[4]
        = g_pstSleepDeviceState->aulDeviceUpSlice[enModem][enMode][PWC_COMM_MODULE_BBP_DRX][PWC_COMM_CHANNEL_0];
    pstAwakeHWInfo[5]
        = g_pstSleepDeviceState->aulPLLUpSlice[enModem][enMode][PWC_COMM_MODULE_BBP_DRX][PWC_COMM_CHANNEL_0];
    pstAwakeHWInfo[6]
        = g_pstSleepDeviceState->aulPLLUpSlice[enModem][enMode][PWC_COMM_MODULE_ABB][PWC_COMM_CHANNEL_0];
    pstAwakeHWInfo[7]
        = g_pstSleepDeviceState->aulDeviceUpSlice[enModem][enMode][PWC_COMM_MODULE_RF][PWC_COMM_CHANNEL_0];
    pstAwakeHWInfo[8]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_ACTIVATE_END].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_ACTIVATE_END].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[9]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_BBP_NORMAL].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_BBP_NORMAL].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[10]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_WAKE_PHY_PRE].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_WAKE_PHY_PRE].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[11]
        = g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_WAKE_PHY].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][SLEEP_MASTER_WAKE_PHY].ulCount%SLEEP_RECORD_TRACK_NUM];
    pstAwakeHWInfo[12]
        = 0xAA557788;

    if ( SLEEP_INFO_RESET_ENABLE == g_bDrxResetFlag )
    {
        VOS_ProtectionReboot(DRX_ACTIVATEHW_ERROR, THIS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);
    }

    return VOS_OK;
}


/*****************************************************************************
 �� �� ��  : SLEEP_VoteLock
 ��������  : ����ͶƱ
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��3��30��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_VoteLock(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if defined (INSTANCE_2)
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_PS_G2);
        /*lint +e534*/
    }
#elif defined (INSTANCE_1)
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_PS_G1);
        /*lint +e534*/
    }
#else
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_PS_G0);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_WCDMA == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_PS_W0);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_1X == enMode)
    {
        /*ΪAustin xģ���Դ�׮������modem����͹��� */
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_1X);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        /*ΪAustin xģ���Դ�׮������modem����͹��� */
        /*lint -e534*/
        mdrv_pm_wake_lock(PWRCTRL_SLEEP_HRPD);
        /*lint +e534*/
    }
    else
    {
        /* for pclint */
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_VoteUnlock
 ��������  : ˯��ͶƱ
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��3��30��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_VoteUnlock(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if defined (INSTANCE_2)
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_PS_G2);
        /*lint +e534*/
    }
#elif defined (INSTANCE_1)
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_PS_G1);
        /*lint +e534*/
    }
#else
    if (VOS_RATMODE_GSM == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_PS_G0);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_WCDMA == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_PS_W0);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_1X == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_1X);
        /*lint +e534*/
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        /*lint -e534*/
        mdrv_pm_wake_unlock(PWRCTRL_SLEEP_HRPD);
        /*lint +e534*/
    }
    else
    {
        /* for pclint */
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_TimeCal
 ��������  : ��ȡDRX�����ָ��ȴ�ʱ��
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��3��30��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_TimeCal( VOS_VOID )
{
    g_ulSleepRusumeTime = g_stSleepDrxResumeTime.ulAbbPwrRsmTime;

    /* ��ȡ���ʱ�� */
    if (g_ulSleepRusumeTime < g_stSleepDrxResumeTime.ulBbpPllRsmTime)
    {
        g_ulSleepRusumeTime = g_stSleepDrxResumeTime.ulBbpPllRsmTime;
    }

    if (g_ulSleepRusumeTime < g_stSleepDrxResumeTime.ulRfPwrRsmTime)
    {
        g_ulSleepRusumeTime = g_stSleepDrxResumeTime.ulRfPwrRsmTime;
    }

    if (g_ulSleepRusumeTime < g_stSleepDrxResumeTime.ulPaPwrRsmTime)
    {
        g_ulSleepRusumeTime = g_stSleepDrxResumeTime.ulPaPwrRsmTime;
    }

    /* �����Slice��λ */
    g_ulSleepRusumeTime = g_ulSleepRusumeTime/32;

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_TCXOIsrProc
 ��������  : TCXO��ʱ�жϴ�������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��7��
    ��    ��   : S00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_TCXOIsrProc( VOS_VOID )
{
    /*lint -e534*/
    VOS_SmV(g_ulSleepTcxoSem);
    /*lint +e534*/
}

/*****************************************************************************
 �� �� ��  : SLEEP_TCXOEnable
 ��������  : TCXO�ϵ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_TCXOEnable(SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_UINT32                          ulTcxoResult;
    VOS_UINT32                          ulTcxoTime;
    VOS_UINT32                          ulTcxoSemTime;

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH <= SLEEP_TCXO_CHAN(enMode)))
    {
        return;
    }

    /*lint -e534*/
    mdrv_pm_enable_tcxo((PWC_COMM_MODEM_E)SLEEP_TCXO_CHAN(enMode), (PWC_COMM_MODE_E)enMode);
    /*lint +e534*/

    if (PWRCTRL_COMM_OFF == mdrv_pm_get_tcxo_status((PWC_COMM_MODEM_E)SLEEP_TCXO_CHAN(enMode)))
    {
        ulTcxoTime  = g_stSleepDrxResumeTime.ulTcxoRsmTime/1000;

        /* ����TCXO�ȶ��ȴ���ʱ�� */
        /*lint -e534*/
        mdrv_pm_start_tcxo_timer((PWC_COMM_MODEM_E)SLEEP_TCXO_CHAN(enMode), (PWC_COMM_MODE_E)enMode,
                                 (PWC_TCXO_FUNCPTR)SLEEP_TCXOIsrProc, VOS_NULL, ulTcxoTime);
        /*lint +e534*/

        /* �ȴ�TCXO�ȶ�,Take�ź�����Сʱ�䳤�ȱ���Ϊ1 tick */
        ulTcxoSemTime = (20 < ulTcxoTime) ?
            ulTcxoTime : 20;

        ulTcxoResult    = VOS_SmP(g_ulSleepTcxoSem, ulTcxoSemTime);

        if (VOS_OK != ulTcxoResult)
        {
            /* �쳣�������� */
            g_pstSleepDeviceState->stDeviceTcxoError.ulCount++;
            g_pstSleepDeviceState->stDeviceTcxoError.ulSlice    = OM_GetSlice();
        }
    }

    /*lint -e534*/
    mdrv_pm_enable_tcxo_rfclk((PWC_COMM_MODEM_E)SLEEP_GetModemId(), (PWC_COMM_MODE_E)enMode, (PWC_COMM_CHANNEL_E)SLEEP_TCXO_CHAN(enMode));
    /*lint +e534*/
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_TCXODisable
 ��������  : TCXO�µ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_TCXODisable(SLEEP_MODE_ENUM_UINT32 enMode)
{
    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH <= SLEEP_TCXO_CHAN(enMode)))
    {
        return;
    }

    /*lint -e534*/
    mdrv_pm_disable_tcxo_rfclk((PWC_COMM_MODEM_E)SLEEP_GetModemId(), (PWC_COMM_MODE_E)enMode, (PWC_COMM_CHANNEL_E)SLEEP_TCXO_CHAN(enMode));

    /* �ر�TCXO */
    mdrv_pm_disable_tcxo((PWC_COMM_MODEM_E)SLEEP_TCXO_CHAN(enMode), (PWC_COMM_MODE_E)enMode);
    /*lint +e534*/

    return;
}

/*lint -e662 -e661*/

/*****************************************************************************
 �� �� ��  : SLEEP_ABBPowerUp
 ��������  : ABB�ϵ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_ABBPowerUp(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_ABB_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_ABB, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_ABB_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_ABB_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_ABB, (PWC_COMM_CHANNEL_E)SLEEP_ABB_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ABBPowerDown
 ��������  : ABB�µ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_ABBPowerDown(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_ABB_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_ABB, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_ABB_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_ABB_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_ABB, (PWC_COMM_CHANNEL_E)SLEEP_ABB_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_RFPowerUp
 ��������  : RF�ϵ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_RFPowerUp(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_RF_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_FEM, i);
            SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_RF, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_RF_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_RF_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_RF, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_RF, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_RF, SLEEP_RF_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_RFPowerDown
 ��������  : RF�µ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_RFPowerDown(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_RFCLK_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICEPLL_POWDOWN((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_RF, i);
            /*lint +e534*/
        }

        if ((SLEEP_BIT_N(i) & SLEEP_RF_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_RF, i);
            SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_FEM, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_RF_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_RF_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_RF, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_RF, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_RF, (PWC_COMM_CHANNEL_E)SLEEP_RF_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_RFFECfgPowerUp
 ��������  : RF�ϵ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��6��17��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_RFFECfgPowerUp(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_RFCLK_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICEPLL_POWUP((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_RF, i);
            /*lint +e534*/
        }

        if ((SLEEP_BIT_N(i) & SLEEP_RF_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            mdrv_rffe_cfg_on_power_up((PWC_COMM_MODE_E)enMode, (PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else

#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_RFFECfgPowerDown
 ��������  : RF�µ纯��
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��6��17��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_RFFECfgPowerDown(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_RF_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            mdrv_rffe_cfg_on_power_down((PWC_COMM_MODE_E)enMode, (PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else

#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ABBPllEnable
 ��������  : ABBPLLʹ�ܺ���
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_ABBPllEnable(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_ABB_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICEPLL_POWUP(enModem, enMode, PWC_COMM_MODULE_ABB, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_ABB_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_ABB_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICEPLL_POWUP(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICEPLL_POWUP(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICEPLL_POWUP(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, (PWC_COMM_CHANNEL_E)SLEEP_ABB_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ABBPllDisable
 ��������  : ABBPLLȥʹ�ܺ���
 �������  : enMode     :ģʽ��W/G
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��27��
    ��    ��   : g47350
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_ABBPllDisable(SLEEP_MODE_ENUM_UINT32 enMode)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          i;

    enModem = SLEEP_GetModemId();

    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        return;
    }

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_ABB_CHAN(enMode)) != VOS_NULL)
        {
            /*lint -e534*/
            SLEEP_DEVICEPLL_POWDOWN(enModem, enMode, PWC_COMM_MODULE_ABB, i);
            /*lint +e534*/
        }
        /*lint +e701*/
    }
#else
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

    if ((SLEEP_GU_MODE_TYPE_BUTT <= enMode) || (SLEEP_CHANNEL_BOTH < SLEEP_ABB_CHAN(enMode)))
    {
        return;
    }

    if (SLEEP_CHANNEL_BOTH == SLEEP_ABB_CHAN(enMode))
    {
        /*lint -e534*/
        SLEEP_DEVICEPLL_POWDOWN(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_0);
        SLEEP_DEVICEPLL_POWDOWN(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, PWC_COMM_CHANNEL_1);
        /*lint +e534*/
    }
    else
    {
        /*lint -e534*/
        SLEEP_DEVICEPLL_POWDOWN(enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_ABB, (PWC_COMM_CHANNEL_E)SLEEP_ABB_CHAN(enMode));
        /*lint +e534*/
    }
#endif

    return;
}


VOS_UINT32 SLEEP_GBBPClkSrcSelect(VOS_VOID)
{
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          ulRet = 0;
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    VOS_UINT32                          i;
#endif

    enModem = SLEEP_GetModemId();

#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)

    for (i = 0; i < PWC_COMM_CHANNEL_BUTT; i++)
    {
        /*lint -e701*/
        if ((SLEEP_BIT_N(i) & SLEEP_ABB_CHAN(PWC_COMM_MODE_GSM)) != VOS_NULL)
        {
            ulRet |= mdrv_pm_gbbp_select_clksrc((PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)i);
        }
        /*lint +e701*/
    }
#else
    if (SLEEP_CHANNEL_BOTH == SLEEP_ABB_CHAN(PWC_COMM_MODE_GSM))
    {
        ulRet = mdrv_pm_gbbp_select_clksrc((PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)SLEEP_CHANNEL_ZERO);
        ulRet |= mdrv_pm_gbbp_select_clksrc((PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)SLEEP_CHANNEL_ONE);
    }
    else
    {
        ulRet = mdrv_pm_gbbp_select_clksrc((PWC_COMM_MODEM_E)enModem, (PWC_COMM_CHANNEL_E)SLEEP_ABB_CHAN(PWC_COMM_MODE_GSM));
    }
#endif

    return ulRet;
}

/*lint +e662 +e661*/

/*****************************************************************************
 �� �� ��  : SLEEP_PowerUp
 ��������  : �ϵ�RTT��ϵͳ.
 �������  : enMode     :ģʽ��W/G

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_PowerUp(SLEEP_MODE_ENUM_UINT32 enMode)
{
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          ulSlice;

    enModem = SLEEP_GetModemId();

    /* ��TXCO */
    SLEEP_TCXOEnable(enMode);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    /* ����BBE16 */
    SLEEP_BBE16PowerUp(enMode);
#endif

    /* �ϵ�RF */
    SLEEP_RFPowerUp(enMode);

    /* �ϵ�ABB */
    SLEEP_ABBPowerUp(enMode);

    /* ��ABB PLL */
    SLEEP_ABBPllEnable(enMode);

    /* V8R1��BBP CS������Դ�����迪�أ������ڽ⸴λBBP CS����ǰ����Ҫ�ȴ��ſغ�ʱ��*/
    /* ��BBP PLL */

    /*lint -e534*/
    SLEEP_DEVICEPLL_POWUP((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);

    /* ��BBP����ʱ�� */
    mdrv_pm_enable_bbpclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, (PWC_COMM_MODEM_E)enModem, PWC_COMM_CHANNEL_0);

    /* �ϵ�BBP */
    SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);
    /*lint +e534*/

    ulSlice = OM_GetSlice();

    /* �����Slice�ȴ������ȶ� */
    while((g_ulSleepRusumeTime) > (OM_GetSlice() - ulSlice))
    {
        ;
    }

    SLEEP_RFFECfgPowerUp(enMode);

    if (VOS_RATMODE_WCDMA == enMode)
    {
        HPA_Conncet3GISR();

#if (FEATURE_GUBBP_HANDSHAKE == FEATURE_ON)
        /* д����������ӳٵȴ�ʱ�� */
        HPA_Write32Reg(WBBP_SWITCH_DELAY_MAX_1CARD_ADDR, SLEEP_BBP_HANDSHAKE_MAX_DELAY);
#endif
    }
    else if (VOS_RATMODE_GSM == enMode)
    {
#if defined (INSTANCE_2)
        HPA_Conncet2GISR2();
#elif defined (INSTANCE_1)
        HPA_Conncet2GISR1();
#else
        HPA_Conncet2GISR0();
#endif

#if (FEATURE_GUDRX_NEWVERSION == FEATURE_ON)
        /* д����������ӳٵȴ�ʱ�� */
        HPA_Write32Reg(GBBP_WAIT_MAX_LEN_ADDR, SLEEP_BBP_HANDSHAKE_MAX_DELAY);
#endif
    }
    else if ((VOS_RATMODE_1X == enMode)||(VOS_RATMODE_HRPD == enMode))
    {
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
        if (VOS_FALSE == g_ulConnectFlag)
        {
            g_ulConnectFlag = VOS_TRUE;

            /* CDMAģʽʹ�� */
            HPA_ConnectCdmaISR();
        }
#endif
    }
    else
    {
        /* for pclint */
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ReadBaseCntSym
 ��������  : ��ȡ��ǰBase Cnt��Ϣ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��28��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 SLEEP_ReadBaseCntChip( VOS_VOID )
{
    VOS_UINT32                          ulBaseSlot;
    VOS_UINT32                          ulBaseChip;

    /* ��ȡBBP����ʱ�̼���������һ�ζ�������ȡָ��ڶ��ζ�Ϊ��ʱ�������λ�ȡ���ս�� */
    ulBaseSlot  = HPA_Read32Reg(WBBP_SYS_BASE_CNT_ADDR);
    ulBaseSlot  = HPA_Read32Reg(WBBP_SYS_BASE_CNT_ADDR);
    ulBaseSlot  = HPA_Read32Reg(WBBP_SYS_BASE_CNT_ADDR);

    /* ������ʱ�̻����CHIP��λ */
    ulBaseChip  = (ulBaseSlot>>16)&0xFFF;
    ulBaseSlot  = (ulBaseSlot>>28)&0xF;
    ulBaseChip  += ulBaseSlot*2560;

    return ulBaseChip;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ResumeReg
 ��������  : BBP�ϵ�󣬻ָ�WBBP�Ĵ�������
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��3��30��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���
  2.��    ��   : 2013��10��28��
    ��    ��   : s00207770
    �޸�����   : ���BBP SFN�Ӽ�1����

*****************************************************************************/
VOS_VOID SLEEP_ResumeReg( VOS_VOID )
{
#if (VOS_OS_VER != VOS_WIN32)
    SLEEP_NOR_STATE_TRACK(VOS_RATMODE_WCDMA, SLEEP_MASTER_BBP_RESUME_START);

    /*��WBBP�ڲ���ģ���ʱ�Ӻͽ⸴λ*/
    HPA_Write32Reg(WBBP_SYS_RST_CON_W1_ADDR, 0xffff0000);

    /*��WBBP��ʱ�л���CPICH̬*/
    HPA_Write32RegMask(WBBP_TIMING_MODE_ADDR, 0x01);
    HPA_Write32RegMask(WBBP_TIMING_CFG_READY_ADDR, 0x01);

    /*�ָ���ʱģ��ķ���С��CPICH���羶��Ϣ*/
    HPA_Write32Reg(WBBP_TRACE_CPI_FRM_POS_ADDR, g_ulSleepBBPPosValue);
    HPA_Write32Reg(WBBP_PATH_CFG_READY_ADDR, 1);

    SLEEP_NOR_STATE_TRACK(VOS_RATMODE_WCDMA, SLEEP_MASTER_BBP_RESUME_END);
#endif
}

#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)
/*****************************************************************************
 �� �� ��  : SLEEP_ForceWakeProtected
 ��������  : �ж�������������Ƿ���
 �������  : void
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_VOID SLEEP_DMACapRelease( VOS_VOID )
{
    if (VOS_TRUE == g_ulIsWaitingDMACap)
    {
        /*lint -e534*/
        VOS_SmV(g_ulSleepDMACapSem);
        /*lint +e534*/
    }
}
#endif

/*****************************************************************************
 �� �� ��  : SLEEP_ForceWakeProtected
 ��������  : �ж�������������Ƿ���
 �������  : void
 �������  : ��
 �� �� ֵ  : VOS_OK  - ���ᵽ����������������BPP
             VOS_ERR - �����������û���BPP
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 SLEEP_ForceWakeProtected(VOS_VOID)
{
    VOS_UINT32  ulWakeSfn;
    VOS_UINT32  ulWakeSlot;
    VOS_UINT32  ulSysSfn;
    VOS_UINT32  ulSysSlot;

    /*��ǰʱ��֡��[11:0]��ƫ��ʱ϶[31:28]*/
    ulSysSfn  = HPA_Read32Reg(WBBP_SYS_CNT_SLEEP_1CARD_ADDR);
    ulSysSlot  = ulSysSfn>>28;
    ulSysSfn  &= 0xfff;
    ulSysSlot  = (ulSysSfn*SLEEP_SLOT_LEN) + ulSysSlot;

    /*��������ʱ��֡��[11:0]*/
    ulWakeSfn = HPA_Read32Reg(WBBP_CK_WAKE_SFN_1CARD_ADDR)&0xfff;
    /*��������ʱ�̵�ƫ��ʱ϶[19:16]*/
    ulWakeSlot = HPA_Read32Reg(WBBP_CK_WAKE_CNT_1CARD_ADDR);
    ulWakeSlot = (ulWakeSlot>>16)&0xf;
    /*��ֹ��ִ�иú����ڼ䣬�����ж��Ѿ����ˣ��ʽ���������ʱ���Ӻ�2��ʱ϶*/
    ulWakeSlot = ((ulWakeSfn*SLEEP_SLOT_LEN) + ulWakeSlot) + SLEEP_WAKE_DELAY;

    /*����ulWakeCnt��ת�����*/
    if (ulWakeSlot < ulSysSlot)
    {
        ulWakeSlot += SLEEP_SFN_CYCLE_LEN;
    }

    /*�ж���4��ʱ϶���Ƿ�������WAKE�ж��ϱ�*/
    if ((ulSysSlot + (SLEEP_WAKE_DELAY + SLEEP_WAKE_INTERVAL))
        < ulWakeSlot)
    {
        return VOS_OK;
    }

    return VOS_ERR;
}

/*****************************************************************************
 �� �� ��  : SLEEP_DeactivateHw
 ��������  : �µ�RTT��ϵͳ.
 �������  : enMode     :ģʽ��W/G

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_DeactivateHw(SLEEP_MODE_ENUM_UINT32 enMode)
{
    MODEM_ID_ENUM_UINT16                enModem;
#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)
    VOS_INT                             lIntLevel;
#endif

    enModem = SLEEP_GetModemId();

#if (FEATURE_GUC_BBP_TRIG == FEATURE_ON)
    PsRegGUCBBPDbgDisable(enModem, enMode);
#endif

    if (VOS_RATMODE_WCDMA == enMode)
    {
        HPA_3GIsrDisable(enModem);
    }
    else
    {
        HPA_2GIsrDisable(enModem);
    }

#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)

    lIntLevel   = VOS_SplIMP();

    if (VOS_TRUE == PsRegGetDmaCaptureStatus(enModem))
    {
        g_ulIsWaitingDMACap = VOS_TRUE;
    }

    VOS_Splx(lIntLevel);

    if (VOS_TRUE == g_ulIsWaitingDMACap)
    {
        if(VOS_OK != VOS_SmP(g_ulSleepDMACapSem, 20))
        {
            g_pstSleepDeviceState->stDMACapError.ulCount++;
            g_pstSleepDeviceState->stDMACapError.ulSlice = OM_GetSlice();
        }

        g_ulIsWaitingDMACap = VOS_FALSE;
    }

#endif

    /* BBP�Ĵ������� */
    if (VOS_RATMODE_WCDMA == enMode)
    {
        g_ulSleepBBPPosValue  = HPA_Read32Reg(WBBP_TRACE_CPI_FRM_POS_ADDR);
    }

    /* �µ�BBP */
    /*lint -e534*/
    SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);

    /* �ر�BBP����ʱ�� */
    mdrv_pm_disable_bbpclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, (PWC_COMM_MODEM_E)enModem, PWC_COMM_CHANNEL_0);

    /* �ر�BBP PLL */
    SLEEP_DEVICEPLL_POWDOWN((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);
    /*lint +e534*/

    /* �ر�ABB PLL */
    SLEEP_ABBPllDisable(enMode);

    /* �µ�ABB */
    SLEEP_ABBPowerDown(enMode);

    /* �µ�RF */
    SLEEP_RFPowerDown(enMode);
    SLEEP_RFFECfgPowerDown(enMode);

    /* �ر�TCXO */
    SLEEP_TCXODisable(enMode);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ActivateHw
 ��������  : �ϵ�RTT��ϵͳ.
 �������  : enMode     :ģʽ��W/G

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_ActivateHw(SLEEP_MODE_ENUM_UINT32 enMode)
{
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          ulSlice;

    enModem = SLEEP_GetModemId();

    SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_ACTIVATE_START);

    /* ��TCXO */
    SLEEP_TCXOEnable(enMode);

    SLEEP_WAKE_SLICE_RECORD(5);

    /* �ϵ�RF */
    SLEEP_RFPowerUp(enMode);

    SLEEP_WAKE_SLICE_RECORD(6);

    /* �ϵ�ABB */
    SLEEP_ABBPowerUp(enMode);

    /* ��ABB PLL */
    SLEEP_ABBPllEnable(enMode);

    /* V8R1��BBP CS������Դ�����迪�أ������ڽ⸴λBBP CS����ǰ����Ҫ�ȴ��ſغ�ʱ��*/
    /* ��BBP PLL */
    /*lint -e534*/
    SLEEP_DEVICEPLL_POWUP((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);

    /* ��BBP����ʱ�� */
    mdrv_pm_enable_bbpclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, (PWC_COMM_MODEM_E)enModem, PWC_COMM_CHANNEL_0);

    /* �ϵ�BBP */
    SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);
    /*lint +e534*/

    ulSlice = OM_GetSlice();

    /* �����Slice�ȴ������ȶ� */
    while((g_ulSleepRusumeTime) > (OM_GetSlice() - ulSlice))
    {
        ;
    }

    SLEEP_RFFECfgPowerUp(enMode);

    /* BBP�Ĵ����ָ� */
    if (VOS_RATMODE_WCDMA == enMode)
    {
        SLEEP_ResumeReg();
    }

    if (VOS_RATMODE_WCDMA == enMode)
    {
        if (BBP_ERROR_VALUE == HPA_Read32Reg(WBBP_ARM_INT01_MASK_ADDR))
        {
            if (VOS_NULL_PTR != g_pstSleepDeviceState)
            {
                g_pstSleepDeviceState->astDevicePowerError[enMode].ulCount++;
                g_pstSleepDeviceState->astDevicePowerError[enMode].ulSlice  = OM_GetSlice();
            }
        }

        HPA_3GIsrEnable(enModem);
    }
    else
    {
        if (BBP_ERROR_VALUE == HPA_Read32Reg(g_aulGUCBBPRegAddr[INT_MASK][enModem][enMode]))
        {
            ulSlice = OM_GetSlice();

            if (VOS_NULL_PTR != g_pstSleepDeviceState)
            {
                g_pstSleepDeviceState->aulABBState[0]       = ulSlice;
            }

            while (SLEEP_BBP_ERROR_TIMEOUT > (OM_GetSlice() - ulSlice))
            {
                if (BBP_ERROR_VALUE != HPA_Read32Reg(g_aulGUCBBPRegAddr[INT_MASK][enModem][enMode]))
                {
                    break;
                }
            }

            if (VOS_NULL_PTR != g_pstSleepDeviceState)
            {
                g_pstSleepDeviceState->aulABBState[1]   = OM_GetSlice();

                g_pstSleepDeviceState->astDevicePowerError[enMode].ulCount++;
                g_pstSleepDeviceState->astDevicePowerError[enMode].ulSlice  = OM_GetSlice();

                VOS_ProtectionReboot(DRX_REPORT_BBP_READ_ERROR, (VOS_INT32)g_pstSleepDeviceState->aulABBState[0], (VOS_INT32)g_pstSleepDeviceState->aulABBState[1], VOS_NULL_PTR, VOS_NULL);
             }
        }

        HPA_2GIsrEnable(enModem);
    }

    SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_ACTIVATE_END);

#if (FEATURE_GUC_BBP_TRIG == FEATURE_ON)
    PsRegGUCBBPDbgEnable(enModem, enMode);
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_WakePhy
 ��������  : ͨ��������Ϣ����GUPHY.
 �������  : ulMsgId    :��ϢID��������ģ/��ģ����
             enMode     :���ѵ�ģʽ��W/G
             enWakeType :�������ͣ�ǿ�ƻ���/��������

 �������  : ��

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������
  2.��    ��   : 2014��07��25��
    ��    ��   : s00207770
    �޸�����   : V800R100���ӻ���ʱ���ά�ɲ���Ϣ�����͵�PC���߲�

*****************************************************************************/
VOS_UINT32 SLEEP_WakePhy(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode, UPHY_OAM_WAKE_TYPE_ENUM_UINT32 enWakeType)
{
    UPHY_OAM_WAKE_CMD_STRU               *pstPhyMsg;

    /* ������Ϣ�ڴ� */
    pstPhyMsg = (UPHY_OAM_WAKE_CMD_STRU*)VOS_AllocMsg(WUEPS_PID_AWAKE,
                    sizeof(UPHY_OAM_WAKE_CMD_STRU) + sizeof(SLEEP_NORMAL_STATE_RECORD_STRU) - VOS_MSG_HEAD_LENGTH);

    /* ����ʧ�� */
    if (VOS_NULL_PTR == pstPhyMsg)
    {
        return VOS_ERR;
    }

    pstPhyMsg->ulReceiverPid = DSP_PID_WAKE;

    pstPhyMsg->enMsgId       = (VOS_UINT16)ulMsgId;
    pstPhyMsg->enModem       = SLEEP_GetModemId();
    pstPhyMsg->enRatMode     = enMode;
    pstPhyMsg->enWakeType    = enWakeType;

    /*lint -e534 -e419*/
    VOS_MemCpy(&(pstPhyMsg->pRecordInfo[0]), (VOS_VOID *)g_pstSleepNormalState, sizeof(SLEEP_NORMAL_STATE_RECORD_STRU));
    /*lint +e534 +e419*/

    /* ������Ϣ */
    if (VOS_OK != VOS_SendMsg(WUEPS_PID_AWAKE, pstPhyMsg))
    {
        return VOS_ERR;
    }

    return VOS_OK;
}

/*****************************************************************************
 �� �� ��  : SLEEP_IsrProc
 ��������  : ��SLEEPģ���жϴ���ת��Ϊ��Ϣ����
 �������  : ulMsgId: ��ϢID��Ӧ��ͬ���ж�
             enMode : ģ��,W/G

 �������  : ��

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��03��09��
    ��    ��   : s00207770
    �޸�����   : �͹����������ȼ������Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_AwakeIsrProc(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_INT                             lLockLevel;
    SLEEP_ISR_MSG_STRU                 *pstIsrMsg;

    lLockLevel = VOS_SplIMP();

    /* ��ֹ��˯ͶƱ */
    SLEEP_VoteLock(enMode);

    /* �ж����м�¼ */
    SLEEP_ISR_RECORD(ulMsgId, enMode);

    /* ������Ϣ�ڴ� */
    pstIsrMsg = (SLEEP_ISR_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_AWAKE,
                    sizeof(SLEEP_ISR_MSG_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstIsrMsg)
    {
        VOS_Splx(lLockLevel);

        return;
    }

    pstIsrMsg->ulReceiverPid = WUEPS_PID_AWAKE;
    pstIsrMsg->usMsgId       = (VOS_UINT16)ulMsgId;
    pstIsrMsg->enRatMode     = enMode;
    pstIsrMsg->ulSlice       = OM_GetSlice();

    if (VOS_OK != VOS_SendMsg(WUEPS_PID_AWAKE, pstIsrMsg))
    {
        /*; */
    }

    VOS_Splx(lLockLevel);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_SleepIsrProc
 ��������  : ��SLEEPģ���жϴ���ת��Ϊ��Ϣ����
 �������  : ulMsgId: ��ϢID��Ӧ��ͬ���ж�
             enMode : ģ��,W/G

 �������  : ��

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������
  2.��    ��   : 2015��03��09��
    ��    ��   : s00207770
    �޸�����   : �͹����������ȼ������Ŀ�޸ĺ���

*****************************************************************************/
VOS_VOID SLEEP_SleepIsrProc(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_INT                             lLockLevel;
    SLEEP_ISR_MSG_STRU                 *pstIsrMsg;

    lLockLevel = VOS_SplIMP();

    /* ��ֹ��˯ͶƱ */
    SLEEP_VoteLock(enMode);

    /* �ж����м�¼ */
    SLEEP_ISR_RECORD(ulMsgId, enMode);

    /* ������Ϣ�ڴ� */
    pstIsrMsg = (SLEEP_ISR_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_SLEEP,
                    sizeof(SLEEP_ISR_MSG_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstIsrMsg)
    {
        VOS_Splx(lLockLevel);

        return;
    }

    pstIsrMsg->ulReceiverPid = WUEPS_PID_SLEEP;
    pstIsrMsg->usMsgId       = (VOS_UINT16)ulMsgId;
    pstIsrMsg->enRatMode     = enMode;
    pstIsrMsg->ulSlice       = OM_GetSlice();

    if (VOS_OK != VOS_SendMsg(WUEPS_PID_SLEEP, pstIsrMsg))
    {
        /*; */
    }

    VOS_Splx(lLockLevel);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_32KClkMsgProc
 ��������  : ���յ�32Kʱ���л��ж���Ϣ����.
 �������  : pstMsg ��Ϣ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_32KClkMsgProc(MsgBlock *pstMsg)
{
    UPHY_OAM_SLEEP_IND_STRU             *pstPhyReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
#ifdef FEATURE_DSP2ARM
    VOS_UINT32                          ulQueueSize = 0;
#endif
    MSG_CB                             *pMsg;
    VOS_ULONG                           ulLockLevel;

    pstPhyReq = (UPHY_OAM_SLEEP_IND_STRU*)pstMsg;

    enMode    = pstPhyReq->enRatMode;

    /* ������� */
    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        /* �쳣��ӡ�ͼ�¼ */
        PS_LOG1(WUEPS_PID_SLEEP, 0, PS_PRINT_ERROR, "SLEEP_32KClkMsgProc: Mode para is wrong.", (VOS_INT32)enMode);
        return;
    }

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    /* ���統ǰϵͳΪNORMAL̬���л�Ϊ��ģ˯����̬ */
    if (SLEEP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        g_astSleepModeInfo[enMode].enSystemState = SLEEP_MASTER_TEMP_LP_STATE;

        /*lint -e534*/
        VOS_SmV(g_ulSleepSem);
        /*lint +e534*/

        return;
    }

    /* ���統ǰϵͳΪ��ģ˯����̬���л�Ϊ��ģ˯��̬ */
    if (SLEEP_MASTER_TEMP_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        SLEEP_WAKE_SLICE_RECORD(2);

        /* �µ�RTT��ϵͳ */
        SLEEP_DeactivateHw(enMode);

        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_LP);

        g_astSleepModeInfo[enMode].enSystemState = SLEEP_MASTER_LP_STATE;

#ifdef FEATURE_DSP2ARM
        VOS_SpinLockIntLock(&g_stSleepSpinLock, ulLockLevel);

        /* ��ȡGUPHY��Ϣ��������Ϣ���� */
        if (VOS_RATMODE_WCDMA == enMode)
        {
            ulQueueSize = VOS_GetQueueSizeFromFid(DSP_FID_WPHY);
        }
        else
        {
            ulQueueSize = VOS_GetQueueSizeFromFid(DSP_FID_GPHY);
        }

        /* �����Ϣ����������Ϣ�������ǿ�ƻ������� */
        if (0 < ulQueueSize)
        {
            if (VOS_RATMODE_WCDMA == enMode)
            {
                pMsg   = (MSG_CB *)VOS_FixedQueueReadMsg(DSP_FID_WPHY);
            }
            else
            {
                pMsg   = (MSG_CB *)VOS_FixedQueueReadMsg(DSP_FID_GPHY);
            }

            if (VOS_NULL_PTR != pMsg)
            {
#if defined (INSTANCE_1)
                if ((DSP_PID_GPHY <= pMsg->ulSenderPid) && (DSP_PID_APM >= pMsg->ulSenderPid))
#else
                if ((DSP_PID_APM <= pMsg->ulSenderPid) && (DSP_PID_IDLE >= pMsg->ulSenderPid))
#endif
                {
                    /*VOS_ProtectionReboot(DRX_PHY_PROTECT_ERROR, VOS_FILE_ID, __LINE__, 0, 0);*/
                }
            }

            VOS_SpinUnlockIntUnlock(&g_stSleepSpinLock, ulLockLevel);

            SLEEP_MasterForceWake(enMode);
        }
        else
#endif
        {
            VOS_SpinUnlockIntUnlock(&g_stSleepSpinLock, ulLockLevel);

            SLEEP_WAKE_SLICE_RECORD(3);

            /* ������˯ͶƱ */
            SLEEP_VoteUnlock(enMode);
        }

        /*lint -e534*/
        VOS_SmV(g_ulSleepSem);
        /*lint +e534*/

        return;
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_MasterSleepMsgProc
 ��������  : ���յ�GUPHY������ģSLEEP̬��Ϣ����.
 �������  : pstMsg ��Ϣ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_MasterSleepMsgProc(MsgBlock *pstMsg)
{
    UPHY_OAM_SLEEP_IND_STRU                 *pstPhyReq;

    pstPhyReq = (UPHY_OAM_SLEEP_IND_STRU*)pstMsg;

    if (VOS_RATMODE_WCDMA == pstPhyReq->enRatMode)
    {
        /* ˯��ǰ���SFN��CFN�ĸ��� */
        HPA_ReadCfnSfn();

        /* ˯��ǰ֪ͨ��2�ж����������Ƿ���� */
        WTTF_MAC_R99MailBox_ReadForIpcHalt();
    }

    SLEEP_NOR_STATE_TRACK(pstPhyReq->enRatMode, SLEEP_MASTER_PHY_HALT);

    SLEEP_WAKE_SLICE_RECORD(1);

    /* ��32K�ж���ͬ�Ĵ������� */
    SLEEP_32KClkMsgProc(pstMsg);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_WakeMasterMsgProc
 ��������  : ���յ�WAKE�ж���Ϣ����.
 �������  : pstMsg ��Ϣ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_WakeMasterMsgProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
    VOS_INT32                           lIntLevel;
#if (FEATURE_GUDRX_NEWVERSION == FEATURE_ON)
    MODEM_ID_ENUM_UINT16                enModem;
#endif

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    /* ������� */
    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        /* �쳣��ӡ�ͼ�¼ */
        PS_LOG1(WUEPS_PID_AWAKE, 0, PS_PRINT_ERROR, "SLEEP_WakeMasterMsgProc: Mode para is wrong.", (VOS_INT32)enMode);
        return;
    }

#if (FEATURE_GUDRX_NEWVERSION == FEATURE_ON)
    enModem = SLEEP_GetModemId();
#endif

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    /* ֻ��ϵͳ����ģ�͹���״̬���ܽ��뵽NORMAL��̬ */
    if (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        /* �ϵ�RTT��ϵͳ */
        SLEEP_ActivateHw(enMode);

        lIntLevel = VOS_SplIMP();

#if (FEATURE_GUBBP_HANDSHAKE == FEATURE_ON)
        /* ����WBBP���ּĴ��� */
        if (VOS_RATMODE_WCDMA == enMode)
        {
            HPA_Write32Reg(WBBP_DSP_READY_IND_1CARD_ADDR, BBP_HANDSHAKE_BIT);

            /* ��¼���ô�����Sliceֵ */
            if (VOS_NULL_PTR != g_pstSleepDeviceState)
            {
                g_pstSleepDeviceState->stHandShakeRecord.ulCount++;
                g_pstSleepDeviceState->stHandShakeRecord.ulSlice = OM_GetSlice();
            }
        }

#if (FEATURE_GUDRX_NEWVERSION == FEATURE_ON)
        if (VOS_RATMODE_GSM == enMode)
        {
            /* ����GBBP���ּĴ��� */
            HPA_Write32Reg(GBBP_GDRX_RDY_IND_ADDR, BBP_HANDSHAKE_BIT);
        }
#endif
#endif

#if (FEATURE_GUDRX_NEWVERSION == FEATURE_OFF)
        if (VOS_RATMODE_GSM == enMode)
        {
            /* ǿ�ƻ���G BBP */
            HPA_Write32RegMask(GBBP_SLEEP_EN_ADDR, BIT_N(2));
        }
#endif

        g_astSleepModeInfo[enMode].enWakeType    = UPHY_OAM_NORMAL_WAKE;
        g_astSleepModeInfo[enMode].enSystemState = SLEEP_TEMP_NORMAL_STATE;

        VOS_Splx(lIntLevel);
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_NormalClkMsgProc
 ��������  : ���յ�ʱ���л��ж�(����ʱ��)��Ϣ����.
 �������  : pstMsg ��Ϣ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_NormalClkMsgProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
#if (FEATURE_GUBBP_HANDSHAKE == FEATURE_ON)
    VOS_UINT32                          ulDeltaSlice;
#endif

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    /* ������� */
    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        /* �쳣��ӡ�ͼ�¼ */
        PS_LOG1(WUEPS_PID_AWAKE, 0, PS_PRINT_ERROR, "SLEEP_NormalClkMsgProc: Mode para is wrong.", (VOS_INT32)enMode);
        return;
    }

    SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_WAKE_PHY_PRE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    /* ��¼��ǰϵͳ״̬��Sliceֵ */

    ;

    /* ֻ��ϵͳ��NORMAL��̬���ܽ��뵽NORMAL̬ */
    if (SLEEP_TEMP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        /* ������Ϣ��PHY_IDLE����PHY */
        /*lint -e534*/
        SLEEP_WakePhy(ID_OAM_UPHY_MASTER_WAKE_CMD, enMode, g_astSleepModeInfo[enMode].enWakeType);
        /*lint +e534*/

        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_WAKE_PHY);

        SLEEP_WAKE_SLICE_RECORD(7);

        SLEEP_MSG_RECORD(ID_OAM_UPHY_MASTER_WAKE_CMD, DSP_PID_WAKE, g_astSleepModeInfo[enMode].enWakeType);

        g_astSleepModeInfo[enMode].enSystemState = SLEEP_NORMAL_STATE;

#if (FEATURE_GUBBP_HANDSHAKE == FEATURE_ON)
        if (VOS_RATMODE_WCDMA == enMode)
        {
            /* BBP�Ĵ���switch_delay_cnt_1card(0x1CC8)��bit 0~31����ȡ��"���Ѻ�ʱ���л��жϱ�ԭ��Ԥ����ʱ�����˶���32kʱ������"����������Ӧ�Ĵ��� */
            ulDeltaSlice = HPA_Read32Reg(WBBP_SWITCH_DELAY_CNT_1CARD_ADDR);
            if ((ulDeltaSlice > 0) && (ulDeltaSlice < SLEEP_BBP_HANDSHAKE_MAX_DELAY))
            {
                /* ��¼��ά�ɲ⣬��������Լ���ִ�У�������λ */
                SLEEP_BBP_SWITCH_INT_DELAY_RECORD(ulDeltaSlice);
            }
            else if (ulDeltaSlice >= SLEEP_BBP_HANDSHAKE_MAX_DELAY)
            {
                /* ����������쳣(����δ�������֣��������쳣����һֱδ����)����¼��ά�ɲ⣬����λ */
                SLEEP_BBP_SWITCH_INT_DELAY_RECORD(ulDeltaSlice);

                VOS_ProtectionReboot(DRX_REPORT_HANDSHAKE_ABNORMAL, THIS_FILE_ID, __LINE__, VOS_NULL_PTR, 0);
            }
            else
            {
                /* ������������账�� */
            }
        }
#if (FEATURE_GUDRX_NEWVERSION == FEATURE_ON)
        else if (VOS_RATMODE_GSM == enMode)
        {
            ulDeltaSlice = HPA_Read32Reg(GBBP_DRX_SWITCH_MAX_RPT_ADDR);
            if ((ulDeltaSlice > 0) && (ulDeltaSlice < SLEEP_BBP_HANDSHAKE_MAX_DELAY))
            {
                /* ��¼��ά�ɲ⣬��������Լ���ִ�У�������λ */
            }
            else if (ulDeltaSlice >= SLEEP_BBP_HANDSHAKE_MAX_DELAY)
            {
                /* ����������쳣(����δ�������֣��������쳣����һֱδ����)����¼��ά�ɲ⣬����λ */
            }
            else
            {
                /* ������������账�� */
            }
        }
        else
        {
        }
#endif
#endif
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_SlaveSleepMsgProc
 ��������  : GUPHY֪ͨ�����ģ����Ϣ��������.
 �������  : pstMsg ��Ϣ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_SlaveSleepMsgProc(MsgBlock *pstMsg)
{
    UPHY_OAM_SLEEP_IND_STRU            *pstPhyReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
#if ((!defined(INSTANCE_1)) && (!defined(INSTANCE_2)))
    VOS_INT32                           lMeansFlag  = VOS_FALSE;
#endif
#ifdef FEATURE_DSP2ARM
    VOS_UINT32                          ulQueueSize = 0;
#endif

    pstPhyReq = (UPHY_OAM_SLEEP_IND_STRU*)pstMsg;

    enMode    = pstPhyReq->enRatMode;

    /* ������� */
    if (SLEEP_GU_MODE_TYPE_BUTT <= enMode)
    {
        /* �쳣��ӡ�ͼ�¼ */
        PS_LOG1(WUEPS_PID_SLEEP, 0, PS_PRINT_ERROR, "SLEEP_SlaveSleepMsgProc: Mode para is wrong.", (VOS_INT32)enMode);
        return;
    }

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_NOR_STATE_TRACK(enMode, SLEEP_SLAVE_PHY_HALT);

    /* ֻ��ϵͳ��NORMAL̬���ܽ��뵽��ģ�͹��� */
    if (SLEEP_NORMAL_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        /* �µ�RTT */
        SLEEP_DeactivateHw(enMode);

        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_SLAVE_LP);

        g_astSleepModeInfo[enMode].enSystemState = SLEEP_SLAVE_LP_STATE;

        /* �����ģ�͹���״̬��֪ͨע��PID */
        SLEEP_NotifyStateToRegPid(enMode, SLEEP_SLAVE_LP_STATE);

#ifdef FEATURE_DSP2ARM
        /* ��ȡGUPHY��Ϣ��������Ϣ���� */
        if (VOS_RATMODE_WCDMA == enMode)
        {
            ulQueueSize = VOS_GetQueueSizeFromFid(DSP_FID_WPHY);
        }
        else
        {
            ulQueueSize = VOS_GetQueueSizeFromFid(DSP_FID_GPHY);
        }
#endif

        /*��������Ҫ�ж��Ƿ��в�����־λ*/
#if defined(INSTANCE_1) || defined(INSTANCE_2)
    #ifdef FEATURE_DSP2ARM
        if (0 < ulQueueSize)
        {
            SLEEP_SlaveForceWake(enMode);
        }
        else
    #endif
        {
            /* ������˯ͶƱ */
            SLEEP_VoteUnlock(enMode);

        #if defined(INSTANCE_2)
            if (VOS_RATMODE_GSM == enMode)
            {
                if (VOS_TRUE == UPHY_DSDA_GetGsmSlaveDrxFlag(SLEEP_GetModemId()))
                {
                    if (VOS_TRUE == g_ulSleepSlaveSemFlag)
                    {
                        g_pstSleepDeviceState->ulSlaveSEMGiveTimes++;
                        g_pstSleepDeviceState->ulSlaveSEMGiveStartSlice   = OM_GetSlice();

                        g_ulSleepSlaveSemFlag   = VOS_FALSE;

                        /*lint -e534*/
                        VOS_SmV(g_ulSleepSlaveSem);
                        /*lint +e534*/

                        g_pstSleepDeviceState->ulSlaveSEMGiveEndSlice     = OM_GetSlice();
                    }
                }
            }
        #endif
        }
#else
        lMeansFlag = mdrv_bbp_get_measure_flag((PWC_COMM_MODE_E)enMode);

    #ifdef FEATURE_DSP2ARM
        if ((0 < ulQueueSize) || (VOS_TRUE == lMeansFlag))
    #else
        if (VOS_TRUE == lMeansFlag)
    #endif
        {
            SLEEP_SlaveForceWake(enMode);
        }
        else
        {
            /* ������˯ͶƱ */
            SLEEP_VoteUnlock(enMode);

            if (VOS_RATMODE_GSM == enMode)
            {
                if (VOS_TRUE == UPHY_DSDA_GetGsmSlaveDrxFlag(SLEEP_GetModemId()))
                {
                    if (VOS_TRUE == g_ulSleepSlaveSemFlag)
                    {
                        g_pstSleepDeviceState->ulSlaveSEMGiveTimes++;
                        g_pstSleepDeviceState->ulSlaveSEMGiveStartSlice   = OM_GetSlice();

                        g_ulSleepSlaveSemFlag   = VOS_FALSE;

                        /*lint -e534*/
                        VOS_SmV(g_ulSleepSlaveSem);
                        /*lint +e534*/

                        g_pstSleepDeviceState->ulSlaveSEMGiveEndSlice     = OM_GetSlice();
                    }
                }
            }
        }
#endif
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_WakeSlaveGUProc
 ��������  : ��ϵͳ������TL����GU����
 �������  : pstMsg ��Ϣ��


 �������  : ��

 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��11��13��
    ��    ��   : g47350
    �޸�����   : ��ģ�͹�������

*****************************************************************************/
VOS_VOID SLEEP_WakeSlaveGUProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
#if defined(INSTANCE_1)
#else
    VOS_INT32                           lLockLevel;
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enSleepState;
#endif

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    /* Austin Modem0 & Modem2����GBBP��GSM���µ�������Ҫͨ��Ӳ����������б��� */
#if defined(INSTANCE_1)
#else
    lLockLevel = VOS_SplIMP();

    enSleepState    = g_astSleepModeInfo[enMode].enSystemState;

    VOS_Splx(lLockLevel);

    /* �жϵ�ǰ�Ƿ��ڴ�ģ�͹���״̬ */
    if (SLEEP_SLAVE_LP_STATE == enSleepState)
    {
        if (VOS_RATMODE_GSM == enMode)
        {
            if (VOS_TRUE == UPHY_DSDA_GetGsmSlaveDrxFlag(SLEEP_GetModemId()))
            {
                g_pstSleepDeviceState->ulSlaveSEMTakeTimes++;
                g_pstSleepDeviceState->ulSlaveSEMTakeStartSlice   = OM_GetSlice();

                /* ��ȡIPCӲ���� */
                if (VOS_OK != VOS_SmP(g_ulSleepSlaveSem, SLEEP_IPC_TIMEOUT))
                {
                    if (0 != g_ulSleepSlaveMsgTrackId)
                    {
                        g_ulSleepSlaveMsgTrackId--;
                    }
                    else
                    {
                        g_ulSleepSlaveMsgTrackId    = SLEEP_SLAVE_MSG_TRACK_NUM-1;
                    }

                    VOS_ProtectionReboot(DRX_SLAVE_WAKE_IPC_ERROR, (VOS_INT)g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulSenderPid,
                        (VOS_INT)g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulMsgName, 0, 0);
                }

                g_pstSleepDeviceState->ulSlaveSEMTakeEndSlice     = OM_GetSlice();

                g_ulSleepSlaveSemFlag   = VOS_TRUE;
            }
        }
    }
#endif

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_SlaveForceWake(enMode);

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_WakeMasterGUProc
 ��������  : ǿ�ƻ���GU����
 �������  : pstMsg ��Ϣ��


 �������  : ��

 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��1��26��
    ��    ��   : s00207770
    �޸�����   : �����ӿ�

*****************************************************************************/
VOS_VOID SLEEP_WakeMasterGUProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_MasterForceWake(enMode);

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_MasterWakeSlave
 ��������  : GUPHY��Ϊ��ģ���Ѵ�ģ����.
 �������  : enRatMode ��Ҫ���ѵ�ģʽ

 �������  : ��

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_UINT32 SLEEP_MasterWakeSlave(SLEEP_MODE_ENUM_UINT32 enRatMode)
{
    VOS_INT32                           lLockLevel;

    switch (enRatMode)
    {
        case VOS_RATMODE_WCDMA:
        case VOS_RATMODE_GSM:
            lLockLevel = VOS_SplIMP();

            if (SLEEP_SLAVE_LP_STATE == g_astSleepModeInfo[enRatMode].enSystemState)
            {
                SLEEP_AwakeIsrProc(SLEEP_WAKE_SLAVE_GU_IND, enRatMode);
            }

            VOS_Splx(lLockLevel);

            break;

        case VOS_RATMODE_LTE:
        case VOS_RATMODE_TDS:
            TLSLEEP_MasterAwakeSlave();

            break;

/* L��ģ����C��ģ����Ʊ����ֻ��1Xģʽ */
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
        case VOS_RATMODE_1X:
        case VOS_RATMODE_HRPD:
            SLEEP_BBE16ForceWakeProc(VOS_RATMODE_1X);

            break;
#endif

        default:
            return VOS_ERR;
    }

    return VOS_OK;
}

/*****************************************************************************
 �� �� ��  : SLEEP_MasterForceWake
 ��������  : �ж��Ƿ�����ģ�͹����£��������ǿ�ƻ���GUPHY.
 �������  : enMode ģʽ

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_MasterForceWake(SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_INT32                           lIntLevel;

    if (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        /* ��ֹ��˯ͶƱ */
        SLEEP_VoteLock(enMode);

        /* �ϵ�RTT��ϵͳ */
        SLEEP_ActivateHw(enMode);

        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_MASTER_FORCE_WAKE);

        lIntLevel = VOS_SplIMP();

        /*�ж�����Ƿ�������WAKE�ж��ϱ�*/
        if (VOS_RATMODE_WCDMA == enMode)
        {
            if (VOS_OK != SLEEP_ForceWakeProtected())
            {
                VOS_Splx(lIntLevel);

                return;
            }

            /* ǿ�ƻ���W BBP */
            HPA_Write32RegMask(WBBP_SWITCH_UP_1CARD_ADDR, BBP_AWAKE_BIT);
        }
        else
        {
            /* ǿ�ƻ���G BBP */
            /*lint -e701*/
            HPA_Write32RegMask(GBBP_SLEEP_EN_ADDR, SLEEP_BIT_N(2));
            /*lint +e701*/
        }

        g_astSleepModeInfo[enMode].enWakeType    = UPHY_OAM_FORCE_WAKE;
        g_astSleepModeInfo[enMode].enSystemState = SLEEP_TEMP_NORMAL_STATE;

        VOS_Splx(lIntLevel);
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_SlaveForceWake
 ��������  : �ж��Ƿ��ڴ�ģ�͹����£��������ǿ�ƻ���GUPHY.
 �������  : enMode ģʽ

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_SlaveForceWake(SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_UINT32                          ulStartSlice;

    /* �жϵ�ǰ�Ƿ��ڴ�ģ�͹���״̬ */
    if (SLEEP_SLAVE_LP_STATE == g_astSleepModeInfo[enMode].enSystemState)
    {
        ulStartSlice    = OM_GetSlice();

        /* ��ֹ��˯ͶƱ */
        SLEEP_VoteLock(enMode);

        /* �ϵ�RTT */
        SLEEP_ActivateHw(enMode);

        SLEEP_MSG_RECORD(ID_OAM_UPHY_SLAVE_WAKE_CMD, DSP_PID_WAKE, ulStartSlice);

        /* ������Ϣ��PHY_IDLE����PHY */
        /*lint -e534*/
        SLEEP_WakePhy(ID_OAM_UPHY_SLAVE_WAKE_CMD, enMode, UPHY_OAM_FORCE_WAKE);
        /*lint +e534*/

        SLEEP_NOR_STATE_TRACK(enMode, SLEEP_SLAVE_FORCE_WAKE);

        g_astSleepModeInfo[enMode].enSystemState = SLEEP_NORMAL_STATE;
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_HookMsgProc
 ��������  : SLEEPע���OSA�ķ�����Ϣ���Ӻ�����������GUPHY����SLEEP̬��ǿ�ƻ���
             GUPHY
 �������  : ָ��OSA��Ϣ��ָ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_HookMsgProc(MsgBlock *pstMsg)
{
    VOS_INT                             lLockLevel;

    if (VOS_FALSE != VOS_CheckInterrupt())
    {
        return;
    }

    /* �ж��Ƿ�����Ϣ���͸�WPHY */
    if (DSP_PID_WPHY == pstMsg->ulReceiverPid)
    {
        lLockLevel = VOS_SplIMP();

        if (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[VOS_RATMODE_WCDMA].enSystemState)
        {
            SLEEP_AwakeIsrProc(SLEEP_WAKE_MASTER_GU_IND, VOS_RATMODE_WCDMA);
        }
        else if (SLEEP_SLAVE_LP_STATE == g_astSleepModeInfo[VOS_RATMODE_WCDMA].enSystemState)
        {
            SLEEP_AwakeIsrProc(SLEEP_WAKE_SLAVE_GU_IND, VOS_RATMODE_WCDMA);
        }
        else
        {
        }

        VOS_Splx(lLockLevel);

        return;
    }

    /* �ж��Ƿ�����Ϣ���͸�GPHY */
    if (DSP_PID_GPHY == pstMsg->ulReceiverPid)
    {
        lLockLevel = VOS_SplIMP();

        if (SLEEP_MASTER_LP_STATE == g_astSleepModeInfo[VOS_RATMODE_GSM].enSystemState)
        {
            SLEEP_AwakeIsrProc(SLEEP_WAKE_MASTER_GU_IND, VOS_RATMODE_GSM);
        }
        else if (SLEEP_SLAVE_LP_STATE == g_astSleepModeInfo[VOS_RATMODE_GSM].enSystemState)
        {
            SLEEP_AwakeIsrProc(SLEEP_WAKE_SLAVE_GU_IND, VOS_RATMODE_GSM);

            g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulMode      = VOS_RATMODE_GSM;
            g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulSenderPid = pstMsg->ulSenderPid;
            g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulMsgName   = *((VOS_UINT32 *)(pstMsg->aucValue));
            g_astSleepSlaveMsgTrack[g_ulSleepSlaveMsgTrackId].ulSlice     = OM_GetSlice();

            g_ulSleepSlaveMsgTrackId++;

            if (SLEEP_SLAVE_MSG_TRACK_NUM == g_ulSleepSlaveMsgTrackId)
            {
                g_ulSleepSlaveMsgTrackId = 0;
            }
        }
        else
        {
        }

        VOS_Splx(lLockLevel);

        return;
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_AwakeMsgProc
 ��������  : AWAKE��Ϣ��������
 �������  : ָ��OSA��Ϣ��ָ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��03��09��
    ��    ��   : s00207770
    �޸�����   : �͹����������ȼ������Ŀ�޸�

*****************************************************************************/
VOS_VOID SLEEP_AwakeMsgProc(MsgBlock* pstMsg)
{
    SLEEP_MSG_FUN_STRU                 *pstMsgFun;
    VOS_UINT32                          ulTlbSize;
    VOS_UINT32                          ulIndex;
    UPHY_OAM_SLEEP_IND_STRU            *pstPhyReq;
    VOS_UINT32                          ulStartSlice = 0;

    pstPhyReq = (UPHY_OAM_SLEEP_IND_STRU*)pstMsg;

    /* �ж���Ϣ���� */
    if (WUEPS_PID_AWAKE == pstPhyReq->ulSenderPid)
    {
        pstMsgFun = g_astAwakeIsrMsgFunTbl;
        ulTlbSize = sizeof(g_astAwakeIsrMsgFunTbl)/sizeof(SLEEP_MSG_FUN_STRU);
    }
    else
    {
        /* δ֪��Ϣֱ�ӷ��� */
        /*lint -e534*/
        LogPrint1("SLEEP_AwakeMsgProc: Unknown ulSenderPid:%d.\r\n",
                        (VOS_INT)pstMsg->ulSenderPid);
        /*lint +e534*/

        SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->ulSenderPid, ulStartSlice);

        return;
    }

    for (ulIndex = 0; ulIndex < ulTlbSize; ulIndex++)
    {
        /* ���ҵ���Ӧ��ϢID�Ĵ������� */
        if (pstPhyReq->enMsgId == (UPHY_OAM_MSG_ID_ENUM_UINT16)pstMsgFun[ulIndex].ulMsgId)
        {
            ulStartSlice = OM_GetSlice();

            pstMsgFun[ulIndex].pMsgFun(pstMsg);

            /* ��¼��������Ϣ */
            SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->enRatMode, ulStartSlice);

            return;
        }
    }

    SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->ulSenderPid, ulStartSlice);

    /* �쳣��ӡ�ͼ�¼ */
    /*lint -e534*/
    LogPrint2("SLEEP_AwakeMsgProc: Unknown Msg, ulSenderPid:%d, enMsgId:%d.\r\n",
                (VOS_INT)pstPhyReq->ulSenderPid, (VOS_INT)pstPhyReq->enMsgId);
    /*lint +e534*/
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_SleepMsgProc
 ��������  : SLEEP��Ϣ��������
 �������  : ָ��OSA��Ϣ��ָ��

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������
  2.��    ��   : 2015��03��09��
    ��    ��   : s00207770
    �޸�����   : �͹����������ȼ������Ŀ�޸�

*****************************************************************************/
VOS_VOID SLEEP_SleepMsgProc(MsgBlock* pstMsg)
{
    SLEEP_MSG_FUN_STRU                 *pstMsgFun;
    VOS_UINT32                          ulTlbSize;
    VOS_UINT32                          ulIndex;
    UPHY_OAM_SLEEP_IND_STRU             *pstPhyReq;
    VOS_UINT32                          ulStartSlice = 0;

    pstPhyReq = (UPHY_OAM_SLEEP_IND_STRU*)pstMsg;

    /* �ж���Ϣ���� */
    if (WUEPS_PID_SLEEP == pstPhyReq->ulSenderPid)
    {
        pstMsgFun = g_astSleepIsrMsgFunTbl;
        ulTlbSize = sizeof(g_astSleepIsrMsgFunTbl)/sizeof(SLEEP_MSG_FUN_STRU);
    }
    /* PHY������Ϣ����*/
    else if (DSP_PID_SLEEP == pstPhyReq->ulSenderPid)
    {
        pstMsgFun = g_astSleepPhyMsgFunTbl;
        ulTlbSize = sizeof(g_astSleepPhyMsgFunTbl)/sizeof(SLEEP_MSG_FUN_STRU);
    }
    else
    {
        /* δ֪��Ϣֱ�ӷ��� */
        /*lint -e534*/
        LogPrint1("SLEEP_MsgProc: Unknown ulSenderPid:%d.\r\n",
                        (VOS_INT)pstMsg->ulSenderPid);
        /*lint +e534*/

        SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->ulSenderPid, ulStartSlice);

        return;
    }

    for (ulIndex = 0; ulIndex < ulTlbSize; ulIndex++)
    {
        /* ���ҵ���Ӧ��ϢID�Ĵ������� */
        if (pstPhyReq->enMsgId == (UPHY_OAM_MSG_ID_ENUM_UINT16)pstMsgFun[ulIndex].ulMsgId)
        {
            ulStartSlice = OM_GetSlice();

            pstMsgFun[ulIndex].pMsgFun(pstMsg);

            /* ��¼��������Ϣ */
            SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->enRatMode, ulStartSlice);

            return;
        }
    }

    SLEEP_MSG_RECORD(pstPhyReq->enMsgId, pstPhyReq->ulSenderPid, ulStartSlice);

    /* �쳣��ӡ�ͼ�¼ */
    /*lint -e534*/
    LogPrint2("SLEEP_MsgProc: Unknown Msg, ulSenderPid:%d, enMsgId:%d.\r\n",
                (VOS_INT)pstPhyReq->ulSenderPid, (VOS_INT)pstPhyReq->enMsgId);
    /*lint +e534*/
    return;
}

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
/*****************************************************************************
 �� �� ��  : SLEEP_BBE16HaltIsr
 ��������  : BBE16˯���жϷ������
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16HaltIsr( SLEEP_MODE_ENUM_UINT32 enMode )
{
    CPHY_SLEEP_MODE_ENUM_UINT32               enHaltType;

    enHaltType                              = CPHY_SLEEP_MODE_BUTT;

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_INT_TRACE);

    if (SLEEP_BBE16_NORMAL_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {

    }
    else
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_INT_NOT_NORMAL_TRACE);
        return;
    }

    /* ָ��SRAM��ָ��Ϊ�� */
    if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
    {
        return;
    }

    /* ��ȡ�����ڴ�SRAM���жϵ�ǰģʽ˯���ж����ͣ�ȷ�Ͻ�����ģ˯�߻��ߴ�ģ˯������ */
    if (VOS_RATMODE_1X == enMode)
    {
        enHaltType = g_pstBBE16SleepInfo->en1xMode;
        g_astSleepBBE16ModeInfo[VOS_RATMODE_1X].enCdmaSleepType = g_pstBBE16SleepInfo->enSleepType;
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        enHaltType = g_pstBBE16SleepInfo->enHrpdMode;
        g_astSleepBBE16ModeInfo[VOS_RATMODE_HRPD].enCdmaSleepType = g_pstBBE16SleepInfo->enSleepType;
    }
    else
    {
        return;
    }

    if (CPHY_SLEEP_MODE_MASTER == enHaltType)
    {
        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_HALT_STATE;
    }
    else if (CPHY_SLEEP_MODE_SLAVE == enHaltType)
    {
        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_SLAVE_HALT_STATE;
    }
    else
    {
        return;
    }

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_INT_TO_MSG_TRACE);
    SLEEP_BBE16HaltIsrProc(BBE16_SLEEP_SLEEP_IND, enMode);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16AwakeIsr
 ��������  : Xģ�����жϷ������
             BBP��ʱ�жϣ�ֻ����ģ���У�ֻ�ڵ͹���̬�Ž��д���
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16AwakeIsr( SLEEP_MODE_ENUM_UINT32 enMode )
{
    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_INT_TRACE);

    /* ��ָ�뷵�� */
    if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
    {
        return;
    }

    if (VOS_RATMODE_1X == enMode)
    {
        g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_NORMAL_WAKE;
    }
    else
    {
        g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_NORMAL_WAKE;
    }

    if (SLEEP_BBE16_MASTER_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_WAKE_STATE;

        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_INT_TO_MSG_TRACE);
        SLEEP_BBE16AwakeIsrProc(BBE16_SLEEP_AWAKE_IND, enMode);
    }
    else
    {
        /*
           �����ж�ʱ��������HALT̬��
           �����WAKE��TEMP̬����ʾ�Ѿ���������;�����NORMAL̬����ʾ�Ѿ�������ɣ���ʱ������������
        */
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_WAKE_INT_NOT_LP_TRACE);
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16ResumeIsr
 ��������  : BBE16���ѻָ��жϷ������
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16ResumeIsr( SLEEP_MODE_ENUM_UINT32 enMode )
{
    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_INT_TRACE);

    SLEEP_BBE16ResumeIsrProc(BBE16_SLEEP_RESUME_IND, enMode);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16PowerUp
 ��������  : BBE16�ϵ����̽ӿ�
 �������  : SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��2��28��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16PowerUp( SLEEP_MODE_ENUM_UINT32 enMode )
{
    if ((VOS_RATMODE_1X == enMode) || (VOS_RATMODE_HRPD == enMode))
    {
        /* ����BBE16����,��ǰ�͹��Ľӿ�δ���忪������ʹ�õ��Խӿڣ��������͹���
           ����ʱ���޸�BBE16���ϵ����� */
        (VOS_VOID)mdrv_pm_enable_pllclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_CBBE16, (PWC_COMM_MODEM_E)SLEEP_GetModemId(), PWC_COMM_CHANNEL_0);
        /*lint -e534 -e746*/
        (VOS_VOID)mlp_dsp_pwrup(enMode, (PWC_COMM_MODEM_E)SLEEP_GetModemId());
        (VOS_VOID)mlp_dsp_enable_clock(enMode);
        (VOS_VOID)mlp_dsp_unreset(enMode);
        (VOS_VOID)mlp_dsp_load(enMode);
        (VOS_VOID)mlp_dsp_restore(enMode);
        (VOS_VOID)mlp_dsp_stop(enMode);
        (VOS_VOID)mlp_dsp_run(enMode);
        /*lint +e534 +e746*/
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_ReportEvent
 ��������  : ����OM�ṩ���ϱ�Event�ӿ�
 �������  : VOS_UINT16 usEventId
             SLEEP_MODE_ENUM_UINT32 enMode
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��2��28��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_ReportEvent(VOS_UINT16 usEventId, SLEEP_MODE_ENUM_UINT32 enMode)
{
    DIAG_EVENT_IND_STRU                 stEventInd;

    stEventInd.ulModule = DIAG_GEN_MODULE(DIAG_MODEM_0, DIAG_MODE_COMM);
    stEventInd.ulPid    = WUEPS_PID_AWAKE;
    stEventInd.ulEventId= usEventId;
    stEventInd.ulLength = SLEEP_BBE16_NORMAL_BUTT * sizeof(SLEEP_BBE16_RECORD_TRACK_STRU);
    stEventInd.pData    = g_pstSleepBBE16NormalState->astRecordItem[enMode];

    /*lint -e534*/
    (VOS_VOID)DIAG_EventReport(&stEventInd);
    /*lint +e534*/

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16DeactivateHw
 ��������  : �µ�RTT��ϵͳ.
 �������  : enMode     :ģʽ��W/G

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��07��31��
    ��    ��   : x00306642
    �޸�����   : xģ�͹�����������

*****************************************************************************/
VOS_VOID SLEEP_BBE16DeactivateHw(SLEEP_MODE_ENUM_UINT32 enMode)
{
    MODEM_ID_ENUM_UINT16                enModem;

    enModem = SLEEP_GetModemId();

#if (FEATURE_GUC_BBP_TRIG == FEATURE_ON)
    PsRegGUCBBPDbgDisable(enModem, enMode);
#endif

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_DEACTIVATE_START);

    /* BBE16���� */
    /* 1:stop BBE16 */
    (VOS_VOID)mlp_dsp_stop(enMode);

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 2:���ݹ���data */
        (VOS_VOID)mlp_dsp_backup(enMode);
    }

    /* �µ�BBP */
    /*lint -e534*/
    SLEEP_DEVICE_POWDOWN(enModem, enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);

    /* �ر�BBP����ʱ�� */
    mdrv_pm_disable_bbpclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, (PWC_COMM_MODEM_E)enModem, PWC_COMM_CHANNEL_0);

    /* �ر�BBP PLL */
    SLEEP_DEVICEPLL_POWDOWN((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);
    /*lint +e534*/

    /* �ر�ABB PLL */
    SLEEP_ABBPllDisable(enMode);

    /* �µ�ABB */
    SLEEP_ABBPowerDown(enMode);

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 2:�ȴ����ݹ���data��� */
        (VOS_VOID)mlp_dsp_wait_backup(enMode);
    }

    /* 3:��λBBE16 */
    (VOS_VOID)mlp_dsp_reset(enMode);

    /* 4:��BBE16�� */
    (VOS_VOID)mlp_dsp_disable_clock(enMode);

    /* 5:��DRX PLL��*/
    (VOS_VOID)mdrv_pm_disable_pllclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_CBBE16, (PWC_COMM_MODEM_E)SLEEP_GetModemId(), PWC_COMM_CHANNEL_0);

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 6:�µ�BBE16 */
        (VOS_VOID)mlp_dsp_pwrdown(enMode, (PWC_COMM_MODEM_E)SLEEP_GetModemId());
    }

    /* �µ�RF */
    SLEEP_RFPowerDown(enMode);
    SLEEP_RFFECfgPowerDown(enMode);

    /* �ر�TCXO */
    SLEEP_TCXODisable(enMode);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_DEACTIVATE_END);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16ActivateHw
 ��������  : �ϵ�RTT��ϵͳ.
 �������  : enMode     :ģʽ��W/G

 �������  : ��

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��07��31��
    ��    ��   : x00306642
    �޸�����   : xģ�͹�����������

*****************************************************************************/
VOS_VOID SLEEP_BBE16ActivateHw(SLEEP_MODE_ENUM_UINT32 enMode)
{
    MODEM_ID_ENUM_UINT16                enModem;
    VOS_UINT32                          ulSlice;

    enModem = SLEEP_GetModemId();

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_ACTIVATE_START);

    /* ��TCXO */
    SLEEP_TCXOEnable(enMode);

    /* �ϵ�RF */
    SLEEP_RFPowerUp(enMode);

    /* BBE16���� */
    /* 1��DRX PLL�� */
    (VOS_VOID)mdrv_pm_enable_pllclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_CBBE16, (PWC_COMM_MODEM_E)SLEEP_GetModemId(), PWC_COMM_CHANNEL_0);

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 2�ϵ�BBE16 */
        (VOS_VOID)mlp_dsp_pwrup(enMode, (PWC_COMM_MODEM_E)SLEEP_GetModemId());
    }

    /* 3��BBE16�� */
    (VOS_VOID)mlp_dsp_enable_clock(enMode);

    /* 4�⸴λBBE16 */
    (VOS_VOID)mlp_dsp_unreset(enMode);

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 5�ָ�����data */
        (VOS_VOID)mlp_dsp_restore(enMode);
    }

    /* �ϵ�ABB */
    SLEEP_ABBPowerUp(enMode);

    /* ��ABB PLL */
    SLEEP_ABBPllEnable(enMode);

    /* V8R1��BBP CS������Դ�����迪�أ������ڽ⸴λBBP CS����ǰ����Ҫ�ȴ��ſغ�ʱ��*/
    /* ��BBP PLL */
    /*lint -e534*/
    SLEEP_DEVICEPLL_POWUP((PWC_COMM_MODEM_E)enModem, (PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);

    /* ��BBP����ʱ�� */
    mdrv_pm_enable_bbpclk((PWC_COMM_MODE_E)enMode, PWC_COMM_MODULE_BBP_DRX, (PWC_COMM_MODEM_E)enModem, PWC_COMM_CHANNEL_0);

    /* �ϵ�BBP */
    SLEEP_DEVICE_POWUP(enModem, enMode, PWC_COMM_MODULE_BBP_DRX, PWC_COMM_CHANNEL_0);
    /*lint +e534*/

    ulSlice = OM_GetSlice();

    /* �����Slice�ȴ������ȶ� */
    while((g_ulSleepRusumeTime) > (OM_GetSlice() - ulSlice))
    {
        ;
    }

    if (CPHY_SLEEP_TYPE_DEEP == g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType)
    {
        /* 5�ȴ��ָ�����data��� */
        (VOS_VOID)mlp_dsp_wait_restore(enMode);
    }

    /* 6run BBE16 */
    (VOS_VOID)mlp_dsp_run(enMode);

    SLEEP_RFFECfgPowerUp(enMode);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_ACTIVATE_END);

#if (FEATURE_GUC_BBP_TRIG == FEATURE_ON)
    PsRegGUCBBPDbgEnable(enModem, enMode);
#endif

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16GetTwinMode
 ��������  : �ж�1X/HRPD��Ӧģʽ
 �������  : ��
 �������  : ��
 �� �� ֵ  : SLEEP_MODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
SLEEP_MODE_ENUM_UINT32 SLEEP_BBE16GetTwinMode( SLEEP_MODE_ENUM_UINT32 enMode )
{
    SLEEP_MODE_ENUM_UINT32              enTwinMode;

    if (VOS_RATMODE_1X == enMode)
    {
        enTwinMode  = VOS_RATMODE_HRPD;
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        enTwinMode  = VOS_RATMODE_1X;
    }
    else
    {
        return VOS_RATMODE_BUTT;
    }

    return enTwinMode;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16GetTwinState
 ��������  : �ж�1X/HRPD��Ӧģʽ�ĵ͹���״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  : SLEEP_BBE16_SYSTEM_STATE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
SLEEP_BBE16_SYSTEM_STATE_ENUM_UINT32 SLEEP_BBE16GetTwinState( SLEEP_MODE_ENUM_UINT32 enMode )
{
    SLEEP_MODE_ENUM_UINT32              enTwinMode;

    if (VOS_RATMODE_1X == enMode)
    {
        enTwinMode  = VOS_RATMODE_HRPD;
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        enTwinMode  = VOS_RATMODE_1X;
    }
    else
    {
        return SLEEP_BBE16_STATE_BUTT;
    }

    return g_astSleepBBE16ModeInfo[enTwinMode].enSystemState;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16MailBoxResumeProc
 ��������  : ��װ�����ṩ��resume�ӿ�
 �������  : enMode     �����ģʽ
 �������  : ��
 �� �� ֵ  : enRatMode  ת�����VOSģʽ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16MailBoxResumeProc(SLEEP_MODE_ENUM_UINT32 enMode)
{
    XMBX_RATMODE_ENUM_U32               enXmbxMode;

    if (VOS_RATMODE_1X == enMode)
    {
        enXmbxMode = XMBX_MOD_1X;
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        /* ��Ʊ����������HRPD */
        enXmbxMode = XMBX_MOD_HRPD;
    }
    else
    {
        /* sleep�Լ����ã��Լ���֤ */
        enXmbxMode = XMBX_MOD_1X;
    }

    /* �����ӿ� */
    mdrv_MailBox_CdmaResumeProc(EN_MAILBOX_CALLBACK_DSP_RESUME, enXmbxMode);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16IsMailBoxAllowCBBE16Sleep
 ��������  : ��װ�����ṩ���ж������Ƿ�����Ϣ�ӿ�
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_FALSE  ��������Ϣ
             VOS_TRUE   ��������Ϣ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 SLEEP_BBE16IsMailBoxAllowCBBE16Sleep(SLEEP_MODE_ENUM_UINT32 enMode)
{
    XMBX_RATMODE_ENUM_U32               enXmbxMode;

    if (VOS_RATMODE_1X == enMode)
    {
        enXmbxMode = XMBX_MOD_1X;
    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        /* ��Ʊ����������HRPD */
        enXmbxMode = XMBX_MOD_HRPD;
    }
    else
    {
        /* sleep�Լ����ã��Լ���֤ */
        enXmbxMode = XMBX_MOD_1X;
    }

    /* �����ӿ� */
    if (VOS_FALSE == mdrv_Mailbox_IsAllowCdmaSleep(enXmbxMode))
    {
        return VOS_FALSE;
    }

    /* ������ */
    if (CPHY_WRITE_MBX_UNCOMPLETED == g_pstBBE16SleepInfo->enCprocWriteMbxState)
    {
        return VOS_FALSE;
    }

    return VOS_TRUE;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16MailBoxGetDspState
 ��������  : ��װ�������ж�DSP״̬��API
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_FALSE  ��������Ϣ
             VOS_TRUE   ��������Ϣ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 SLEEP_BBE16MailBoxGetDspState(XMBX_RATMODE_ENUM_U32 enMode)
{
    SLEEP_MODE_ENUM_UINT32              enRatMode;
    VOS_UINT32                          ulRet;

    if (XMBX_MOD_1X == enMode)
    {
        enRatMode = VOS_RATMODE_1X;
    }
    else if (XMBX_MOD_HRPD == enMode)
    {
        /* ��Ʊ����������HRPD */
        enRatMode = VOS_RATMODE_HRPD;
    }
    else
    {
        /* ����ͨ��ǿ��ת��1X */
        enRatMode = VOS_RATMODE_1X;
    }

    ulRet = SLEEP_BBE16GetLowPowerState(enRatMode);

    return ulRet;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16MailBoxForceWakeDsp
 ��������  : ��װ������ǿ�ƻ���DSP��API
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_FALSE  ��������Ϣ
             VOS_TRUE   ��������Ϣ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16MailBoxForceWakeDsp(XMBX_RATMODE_ENUM_U32 enMode)
{
    SLEEP_MODE_ENUM_UINT32              enRatMode;

    if (XMBX_MOD_1X == enMode)
    {
        enRatMode = VOS_RATMODE_1X;
    }
    else if (XMBX_MOD_HRPD == enMode)
    {
        /* ��Ʊ����������HRPD */
        enRatMode = VOS_RATMODE_HRPD;
    }
    else
    {
        /* ����ͨ��ǿ��ת��1X */
        enRatMode = VOS_RATMODE_1X;
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MBX_OTHER_CHANNEL_TRACE);
    }

    SLEEP_BBE16ForceWakeProc(enRatMode);
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16GetLowPowerState
 ��������  : �ṩ1X/HRPD�͹���״̬�ж�
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32 VOS_TRUE    ��ǰģʽ���ڵ͹���̬
                        VOS_FALSE   ��ǰģʽ��������״̬
                        VOS_ERROR   ����ģʽ����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32  SLEEP_BBE16GetLowPowerState(SLEEP_MODE_ENUM_UINT32 enMode)
{
    VOS_UINT32                          ulRet   = VOS_TRUE;

    /* ��ֹ��˯ͶƱ��ǿ�ƻ���������� */
    SLEEP_VoteLock(enMode);

    if (SLEEP_BBE16_NORMAL_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        ulRet   = VOS_FALSE;
    }

    return ulRet;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16CprocWakeupProc
 ��������  : OAM�ṩע�ắ����CPROCע��wakeup proc
 �������  : SLEEP_BBE16_CPROC_WAKEUP_FUNC pFun
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��15��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16CprocWakeupProc(SLEEP_BBE16_CPROC_WAKEUP_FUNC pFun, VOS_RATMODE_ENUM_UINT32 enMode, VOS_VOID* pulPara)
{
    if (VOS_NULL_PTR == pFun)
    {
        return;
    }

    g_stSleepCprocCtrl[enMode].pfnCprocWakeupProc   = pFun;
    g_stSleepCprocCtrl[enMode].pulCprocWakeupPara   = pulPara;
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16CprocSleepProc
 ��������  : OAM�ṩע�ắ����CPROCע��sleep proc
 �������  : SLEEP_BBE16_CPROC_SLEEP_FUNC pFun
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��15��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16CprocSleepProc(SLEEP_BBE16_CPROC_SLEEP_FUNC pFun, VOS_RATMODE_ENUM_UINT32 enMode, VOS_VOID* pulPara)
{
    if (VOS_NULL_PTR == pFun)
    {
        return;
    }

    g_stSleepCprocCtrl[enMode].pfnCprocSleepProc   = pFun;
    g_stSleepCprocCtrl[enMode].pulCprocSleepPara   = pulPara;

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16ForceWakeProc
 ��������  : ���䷢ǿ�ƻ�����Ϣ��OAM
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_UINT32 VOS_TRUE    ��ǰģʽ���ڵ͹���̬
                        VOS_FALSE   ��ǰģʽ��������״̬
                        VOS_ERROR   ����ģʽ����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��15��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID  SLEEP_BBE16ForceWakeProc( SLEEP_MODE_ENUM_UINT32 enMode )
{
    if (VOS_RATMODE_1X == enMode)
    {

    }
    else if (VOS_RATMODE_HRPD == enMode)
    {
        /* ��Ʊ������mode������HRPD�����modeΪHRPD���׮��1x���Ҽ�¼���� */
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_MODE_ERR_TRACE);
        enMode = VOS_RATMODE_1X;
    }
    else
    {
        return;
    }

    /* ȷ���Ƿ���Ҫ���ж� */

    /* �����������У��жϵ�ǰmode��״̬����NORMAL��Ҫ�ȴ�OAM��״̬�л���NORMAL���ܼ���ִ��ҵ��
       �����WAKE������TEMP��˵��OAM����ִ�л������̣����ﲻ��Ҫִ��ǿ�ƻ��ѣ�ֻҪ��resume������
       �����LOW_POWER������HALT��˵��OAM�Ѿ�˯�˻�������˯����ʱҪִ��ǿ�ƻ��ѣ�Ȼ���resume */
    if ((SLEEP_BBE16_MASTER_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        || (SLEEP_BBE16_MASTER_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState))
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_REQ_TRACE);
        SLEEP_AwakeIsrProc(BBE16_SLEEP_MASTER_WAKE_IND, enMode);
    }
    else if ((SLEEP_BBE16_SLAVE_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        || (SLEEP_BBE16_SLAVE_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState))
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_REQ_TRACE);
        SLEEP_AwakeIsrProc(BBE16_SLEEP_SLAVE_WAKE_IND, enMode);
    }
    else
    {

    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16MasterForceWakeProc
 ��������  : ���䷢ǿ�ƻ�����Ϣ��OAM
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_UINT32 VOS_TRUE    ��ǰģʽ���ڵ͹���̬
                        VOS_FALSE   ��ǰģʽ��������״̬
                        VOS_ERROR   ����ģʽ����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��15��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID  SLEEP_BBE16MasterForceWakeProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;
    enMode    = pstIsrReq->enRatMode;

    /* OAM�յ�ǿ�ƻ�����Ϣʱ���ڻ�ȡӲ����֮ǰ���ж�һ��״̬
       �����ʱ����LOW_POWER����HALT˵����MailBox����ǿ�ƻ���֮�󣬽����˻����жϴ�������ʱ�Ͳ�����������
       �����LOW_POWER̬�����ֱ�ӻ�ȡ��Ӳ�����������HALT̬���ȡӲ����ʱ��Pendingֱ��˯�����
       ���ﲻ��WAKE״̬��Ҫ���õ���֮����WAKE״̬
    */
    if ((SLEEP_BBE16_MASTER_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        || (SLEEP_BBE16_MASTER_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState))
    {
        SLEEP_BBE16MasterForceWake(enMode);
    }
    else
    {
        /* ����״̬�������� */
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16SlaveForceWakeProc
 ��������  : ���䷢ǿ�ƻ�����Ϣ��OAM
 �������  : enMode
 �������  : ��
 �� �� ֵ  : VOS_UINT32 VOS_TRUE    ��ǰģʽ���ڵ͹���̬
                        VOS_FALSE   ��ǰģʽ��������״̬
                        VOS_ERROR   ����ģʽ����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��9��15��
    ��    ��   : x00306642
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID  SLEEP_BBE16SlaveForceWakeProc(MsgBlock *pstMsg)
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;
    enMode    = pstIsrReq->enRatMode;

    if ((SLEEP_BBE16_SLAVE_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        || (SLEEP_BBE16_SLAVE_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState))
    {
        SLEEP_BBE16SlaveForceWake(enMode);
    }
    else
    {
        /* ����״̬�������� */
    }

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16MasterForceWake
 ��������  : �ж��Ƿ�����ģ�͹����£��������ǿ�ƻ���Xģ.
 �������  : enMode ģʽ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��08��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16MasterForceWake( SLEEP_MODE_ENUM_UINT32 enMode )
{
    VOS_INT                             lIntLevel;

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_START_TRACE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_SMP_TRACE);

    if (SLEEP_BBE16_MASTER_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        /* ��WAKE̬�������ǰ���ѱ���ͣ����ô��twinģ��resume�ж�������Ը���WAKE̬������ִ������Ļ��� */
        lIntLevel   = VOS_SplIMP();
        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_WAKE_STATE;
        VOS_Splx(lIntLevel);

        /* ��ָ�뷵�� */
        if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
        {
            /*lint -e534*/
            VOS_SmV(g_ulSleepSem);
            /*lint +e534*/
            return;
        }

        /* ���twinģ���ڻ������̵�resume�ж�ʱ������ͣ��ǰģʽ�Ļ������� */
        if (SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE == SLEEP_BBE16GetTwinState(enMode))
        {

        }
        else
        {
            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_PROC_TRACE);

            SLEEP_BBE16ActivateHw(enMode);

            lIntLevel   = VOS_SplIMP();
            g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE;
            VOS_Splx(lIntLevel);

            /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
            if (VOS_RATMODE_1X == enMode)
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;
                g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_FORCE_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
            }
            else
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_HRPD;
                g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_FORCE_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
            }

            /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
            SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);
        }
    }
    else
    {
        /* ��Ԥ�ڵ�״̬ */
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_MASTER_FORCE_WAKE_END_TRACE);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16SlaveForceWake
 ��������  : �ж��Ƿ��ڴ�ģ�͹����£��������ǿ�ƻ���Xģ.
 �������  : enMode ģʽ
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��08��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16SlaveForceWake( SLEEP_MODE_ENUM_UINT32 enMode )
{
    SLEEP_MODE_ENUM_UINT32                                  enTwinMode;
    SLEEP_BBE16_SYSTEM_STATE_ENUM_UINT32                    enTwinState;
    VOS_INT                                                 lIntLevel;

    enTwinMode = SLEEP_BBE16GetTwinMode(enMode);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_START_TRACE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_SMP_TRACE);

    if (SLEEP_BBE16_SLAVE_LP_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        /* ��WAKE̬�������ǰ���ѱ���ͣ����ô��twinģ��resume�ж�������Ը���WAKE̬������ִ������Ļ��� */
        lIntLevel   = VOS_SplIMP();
        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_SLAVE_WAKE_STATE;
        VOS_Splx(lIntLevel);

        /* ��ָ�뷵�� */
        if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
        {
            /*lint -e534*/
            VOS_SmV(g_ulSleepSem);
            /*lint +e534*/
            return;
        }

        /* ��ģǿ�ƻ�����Ҫ�ж���һ��ģ�ĵ͹���״̬��ȷ���Ƿ���Ҫ������ģ��������
           �����Ҫ������ģ���Ѵ������ݴ��ģ������Ϊ���ȴ���ģ���ѳɹ��󣬼�����ģ�������� */
        enTwinState = SLEEP_BBE16GetTwinState(enMode);
        if ((SLEEP_BBE16_MASTER_LP_STATE == enTwinState)
          || (SLEEP_BBE16_MASTER_HALT_STATE == enTwinState))
        {
            /* ������ģ���Ѵ���������ͨ������ģǿ�ƻ�����Ϣ��ʵ�� */
            SLEEP_AwakeIsrProc(BBE16_SLEEP_MASTER_WAKE_IND, enTwinMode);
        }
        /* ���twinģ���ڻ������̵�resume�ж�ʱ������ͣ��ǰģʽ�Ļ������� */
        else if ((SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE == enTwinState)
               ||(SLEEP_BBE16_SLAVE_TEMP_NORMAL_STATE == enTwinState))
        {

        }
        else
        {
            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_PROC_TRACE);

            SLEEP_BBE16ActivateHw(enMode);

            lIntLevel   = VOS_SplIMP();
            g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_SLAVE_TEMP_NORMAL_STATE;
            VOS_Splx(lIntLevel);

            /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
            if (VOS_RATMODE_1X == enMode)
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;
                g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_FORCE_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
            }
            else
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_HRPD;
                g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_FORCE_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
            }

            /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
            SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);

            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_END_TRACE);
        }
    }
    else
    {
        /* ��Ԥ�ڵ�״̬ */
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_SLAVE_FORCE_WAKE_END_TRACE);
    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16HaltIsrProc
 ��������  : ��SLEEPģ���жϴ���ת��Ϊ��Ϣ����
 �������  : ulMsgId: ��ϢID��Ӧ��ͬ���ж�
             enMode : ģ��,1X/HRPD
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16HaltIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode )
{
    VOS_INT                             lLockLevel;
    SLEEP_ISR_MSG_STRU                 *pstIsrMsg;

    lLockLevel = VOS_SplIMP();

    /* ��ֹ��˯ͶƱ */
    SLEEP_VoteLock(enMode);

    /* �ж����м�¼ */
    SLEEP_ISR_RECORD(ulMsgId, enMode);

    /* ������Ϣ�ڴ� */
    pstIsrMsg = (SLEEP_ISR_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_SLEEP,
                    sizeof(SLEEP_ISR_MSG_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstIsrMsg)
    {
        VOS_Splx(lLockLevel);

        return;
    }

    pstIsrMsg->ulReceiverPid = WUEPS_PID_SLEEP;
    pstIsrMsg->usMsgId       = (VOS_UINT16)ulMsgId;
    pstIsrMsg->enRatMode     = enMode;
    pstIsrMsg->ulSlice       = OM_GetSlice();

    if (VOS_OK != VOS_SendMsg(WUEPS_PID_SLEEP, pstIsrMsg))
    {
        /*; */
    }

    VOS_Splx(lLockLevel);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16AwakeIsrProc
 ��������  : ��SLEEPģ���жϴ���ת��Ϊ��Ϣ����
 �������  : ulMsgId: ��ϢID��Ӧ��ͬ���ж�
             enMode : ģ��,1X/HRPD
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16AwakeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode )
{
    VOS_INT                             lLockLevel;
    SLEEP_ISR_MSG_STRU                 *pstIsrMsg;

    lLockLevel = VOS_SplIMP();

    /* ��ֹ��˯ͶƱ */
    SLEEP_VoteLock(enMode);

    /* �ж����м�¼ */
    SLEEP_ISR_RECORD(ulMsgId, enMode);

    /* ������Ϣ�ڴ� */
    pstIsrMsg = (SLEEP_ISR_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_AWAKE,
                    sizeof(SLEEP_ISR_MSG_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstIsrMsg)
    {
        VOS_Splx(lLockLevel);

        return;
    }

    pstIsrMsg->ulReceiverPid = WUEPS_PID_AWAKE;
    pstIsrMsg->usMsgId       = (VOS_UINT16)ulMsgId;
    pstIsrMsg->enRatMode     = enMode;
    pstIsrMsg->ulSlice       = OM_GetSlice();

    if (VOS_OK != VOS_SendMsg(WUEPS_PID_AWAKE, pstIsrMsg))
    {
        /*; */
    }

    VOS_Splx(lLockLevel);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16ResumeIsrProc
 ��������  : ��SLEEPģ���жϴ���ת��Ϊ��Ϣ����
 �������  : ulMsgId: ��ϢID��Ӧ��ͬ���ж�
             enMode : ģ��,1X/HRPD
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16ResumeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode )
{
    VOS_INT                             lLockLevel;
    SLEEP_ISR_MSG_STRU                 *pstIsrMsg;

    lLockLevel = VOS_SplIMP();

    /* ��ֹ��˯ͶƱ */
    SLEEP_VoteLock(enMode);

    /* �ж����м�¼ */
    SLEEP_ISR_RECORD(ulMsgId, enMode);

    /* ������Ϣ�ڴ� */
    pstIsrMsg = (SLEEP_ISR_MSG_STRU*)VOS_AllocMsg(WUEPS_PID_AWAKE,
                    sizeof(SLEEP_ISR_MSG_STRU) - VOS_MSG_HEAD_LENGTH);

    if (VOS_NULL_PTR == pstIsrMsg)
    {
        VOS_Splx(lLockLevel);

        return;
    }

    pstIsrMsg->ulReceiverPid = WUEPS_PID_AWAKE;
    pstIsrMsg->usMsgId       = (VOS_UINT16)ulMsgId;
    pstIsrMsg->enRatMode     = enMode;
    pstIsrMsg->ulSlice       = OM_GetSlice();

    if (VOS_OK != VOS_SendMsg(WUEPS_PID_AWAKE, pstIsrMsg))
    {
        /*; */
    }

    VOS_Splx(lLockLevel);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16HaltMsgProc
 ��������  : BBE16˯���������ӿ�
 �������  : MsgBlock* pstMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16HaltMsgProc( MsgBlock* pstMsg )
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    if ((VOS_RATMODE_1X == enMode) || (VOS_RATMODE_HRPD == enMode))
    {

    }
    else
    {
        return;
    }

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_START_TRACE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_SMP_TRACE);

    /* ˯�ߴ���ǰ������״̬�жϣ���������ڻ��вд�ĵ�ǰmode����Ϣ��������ֱ�ӻ���BBE16 */
    if (VOS_FALSE == SLEEP_BBE16IsMailBoxAllowCBBE16Sleep(enMode))
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_WAKE_START_TRACE);

        /* ����CPROC�ص���������Ʊ����1X��HRPD��������ǰ�м���ģCPROC��ע�Ἰ��ģ */
        if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocSleepProc)
        {
            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_CPROC_1X_SLEEP_TRACE);
            g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocSleepProc(g_stSleepCprocCtrl[VOS_RATMODE_1X].pulCprocSleepPara);
        }

        if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocSleepProc)
        {
            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_CPROC_HRPD_SLEEP_TRACE);
            g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocSleepProc(g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pulCprocSleepPara);
        }

        /* ״̬�л���TEMP̬ */
        if (SLEEP_BBE16_MASTER_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
        {
            g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE;
        }
        else
        {
            g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_SLAVE_TEMP_NORMAL_STATE;
        }

        /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
        if (VOS_RATMODE_1X == enMode)
        {
            g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;
            g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_FORCE_WAKE;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
        }
        else
        {
            g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_HRPD;
            g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_FORCE_WAKE;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
        }

        /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
        SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);

        /*lint -e534*/
        VOS_SmV(g_ulSleepSem);
        /*lint +e534*/

        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_WAKE_END_TRACE);
        return;
    }

    /* ����CPROC�ص���������Ʊ����1X��HRPD��������ǰ�м���ģCPROC��ע�Ἰ��ģ */
    if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocSleepProc)
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_CPROC_1X_SLEEP_TRACE);
        g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocSleepProc(g_stSleepCprocCtrl[VOS_RATMODE_1X].pulCprocSleepPara);
    }

    if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocSleepProc)
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_CPROC_HRPD_SLEEP_TRACE);
        g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocSleepProc(g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pulCprocSleepPara);
    }

    /* ִ���µ紦�� */
    if (SLEEP_BBE16_MASTER_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        SLEEP_BBE16DeactivateHw(enMode);

        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_LP_STATE;
    }
    else if (SLEEP_BBE16_SLAVE_HALT_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        SLEEP_BBE16DeactivateHw(enMode);

        g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_SLAVE_LP_STATE;
    }
    else
    {
    }

    /*
       ��˯�߹����в������յ������жϣ�����Ҫ�����յ�ǿ�ƻ���(OAM�л���HALT̬������������Ҫ��������ǿ�ƻ���)
       �յ�ǿ�ƻ���ʱ����WAKE�����У��жϵ�ǰ��HALT̬��Ҫȥ�ȴ�˯������ִ�н������ͷ�Ӳ����֮����л��Ѳ���
       ��ȡ��Ӳ����֮���ٽ���״̬�л��Լ����Ѳ���
    */

    /* ������˯ͶƱ */
    SLEEP_VoteUnlock(enMode);

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_HALT_END_TRACE);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16AwakeMsgProc
 ��������  : BBP��ʱ�������ж�ת��Ϣ��Ĵ���
 �������  : MsgBlock* pstMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16AwakeMsgProc( MsgBlock* pstMsg )
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;

    pstIsrReq = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode    = pstIsrReq->enRatMode;

    if ((VOS_RATMODE_1X == enMode) || (VOS_RATMODE_HRPD == enMode))
    {

    }
    else
    {
        return;
    }

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_START_TRACE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_SMP_TRACE);

    /* �յ������ж�ʱ��������������˯�ߣ������ڻ����ж�������WAKE̬ */
    if (SLEEP_BBE16_MASTER_WAKE_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
    {
        /* ���twinģ���ڻ������̵�resume�ж�ʱ������ͣ��ǰģʽ�Ļ������� */
        if (SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE == SLEEP_BBE16GetTwinState(enMode))
        {

        }
        else
        {
            SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_PROC_TRACE);

            /* ��ָ�뷵�� */
            if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
            {
                /*lint -e534*/
                VOS_SmV(g_ulSleepSem);
                /*lint +e534*/
                return;
            }

            /* ִ���ϵ紦�� */
            SLEEP_BBE16ActivateHw(enMode);

            g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE;

            /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
            if (VOS_RATMODE_1X == enMode)
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;
                g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_NORMAL_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
            }
            else
            {
                g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_HRPD;
                g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_NORMAL_WAKE;

                (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
            }

            /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
            SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);
        }
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_NORMAL_WAKE_END_TRACE);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16ResumeMsgProc
 ��������  : BBE16˯���������ӿ�
 �������  : MsgBlock* pstMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16ResumeMsgProc( MsgBlock* pstMsg )
{
    SLEEP_ISR_MSG_STRU                 *pstIsrReq;
    SLEEP_MODE_ENUM_UINT32              enMode;
    SLEEP_MODE_ENUM_UINT32              enTwinMode;

    pstIsrReq  = (SLEEP_ISR_MSG_STRU*)pstMsg;

    enMode     = pstIsrReq->enRatMode;
    enTwinMode = SLEEP_BBE16GetTwinMode(enMode);

    if ((VOS_RATMODE_1X == enMode) || (VOS_RATMODE_HRPD == enMode))
    {

    }
    else
    {
        return;
    }

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_START_TRACE);

    (VOS_VOID)VOS_SmP(g_ulSleepSem, 0);

    /* Resume�жϲ���״̬�жϣ��ŵ��������� */
    if ((SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState)
     || (SLEEP_BBE16_SLAVE_TEMP_NORMAL_STATE == g_astSleepBBE16ModeInfo[enMode].enSystemState))
    {

    }
    else
    {
        /*lint -e534*/
        VOS_SmV(g_ulSleepSem);
        /*lint +e534*/

        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_INT_NOT_TEMP_TRACE);
        return;
    }

    g_astSleepBBE16ModeInfo[enMode].enSystemState = SLEEP_BBE16_NORMAL_STATE;

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_SMP_TRACE);

    /* ��������ӿڣ�֪ͨ����resume ind */
    SLEEP_BBE16MailBoxResumeProc(enMode);

    /* ����CPROC�ص���������Ʊ����1X��HRPD��������ǰ�м���ģCPROC��ע�Ἰ��ģ */
    if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocWakeupProc)
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_CPROC_1X_WAKEUP_TRACE);
        g_stSleepCprocCtrl[VOS_RATMODE_1X].pfnCprocWakeupProc(g_stSleepCprocCtrl[VOS_RATMODE_1X].pulCprocWakeupPara);
    }

    if (VOS_NULL_PTR != g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocWakeupProc)
    {
        SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_CPROC_HRPD_WAKEUP_TRACE);
        g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pfnCprocWakeupProc(g_stSleepCprocCtrl[VOS_RATMODE_HRPD].pulCprocWakeupPara);
    }

    /* ˯�߻������̽������ϱ���¼��Ϣ */
    SLEEP_ReportEvent((VOS_UINT16)BBE16_SLEEP_TRACE_STACK_IND, enMode);

    /* �ж�twinģ�Ƿ��ڻ���״̬������ڻ���״̬������Ҫ����twinģ�Ļ������̴��� */
    if (SLEEP_BBE16_MASTER_WAKE_STATE == SLEEP_BBE16GetTwinState(enMode))
    {
        /* ��ָ�뷵�� */
        if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
        {
            /*lint -e534*/
            VOS_SmV(g_ulSleepSem);
            /*lint +e534*/
            return;
        }

        SLEEP_BBE16ActivateHw(enTwinMode);

        g_astSleepBBE16ModeInfo[enTwinMode].enSystemState = SLEEP_BBE16_MASTER_TEMP_NORMAL_STATE;

        /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
        if (VOS_RATMODE_1X == enTwinMode)
        {
            g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;
            g_pstBBE16SleepInfo->en1xWakeUpType     = CPHY_OAM_FORCE_WAKE;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
        }
        else
        {
            g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_HRPD;
            g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_FORCE_WAKE;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
        }

        /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
        SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);
    }
    else if (SLEEP_BBE16_SLAVE_WAKE_STATE == SLEEP_BBE16GetTwinState(enMode))
    {
        SLEEP_BBE16ActivateHw(enTwinMode);

        g_astSleepBBE16ModeInfo[enTwinMode].enSystemState = SLEEP_BBE16_SLAVE_TEMP_NORMAL_STATE;

        /* ���û������ͱ�־λ,��csdr���ͻ����ж� */
        if (VOS_RATMODE_1X == enTwinMode)
        {
            g_pstBBE16SleepInfo->enWakeUpMode       = CPHY_WAKEUP_MODE_1X;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_1X_WAKE);
        }
        else
        {
            g_pstBBE16SleepInfo->enHrpdWakeUpType   = CPHY_OAM_NORMAL_WAKE;

            (VOS_VOID)mdrv_ipc_int_send(IPC_CORE_BBE, IPC_XDSP_INT_SRC_CCPU_HRPD_WAKE);
        }

        /* ��ʱ200us(��ȷ�Ͼ�����ʱʱ��) */
        SLEEP_TaskDelay(SLEEP_IPC_INT_DELAY_SLICE);
    }
    else
    {
        /* for pclint */
    }

    /*lint -e534*/
    VOS_SmV(g_ulSleepSem);
    /*lint +e534*/

    SLEEP_BBE16_NOR_STATE_TRACK(enMode, SLEEP_BBE16_RESUME_END_TRACE);

    return;
}

/*****************************************************************************
 �� �� ��  : SLEEP_BBE16DbgInit
 ��������  : ά����Ϣ��ʼ��
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��27��
    ��    ��   : s00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_BBE16DbgInit(VOS_VOID)
{
    if (VOS_NULL_PTR == g_pstSleepBBE16NormalState)
    {
        return;
    }

    /* Main Track*/
    /* Halt */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_INT_TRACE].pucTrackId                    = "Halt Int";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_START_TRACE].pucTrackId                  = "Halt Msg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_END_TRACE].pucTrackId                    = "Halt End";

    /* Normal Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_INT_TRACE].pucTrackId             = "Wake Int";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_START_TRACE].pucTrackId           = "Wake Msg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_END_TRACE].pucTrackId             = "Wake End";

    /* Master Force Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_REQ_TRACE].pucTrackId       = "MasteReq";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_START_TRACE].pucTrackId     = "MasteMsg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_END_TRACE].pucTrackId       = "MasteEnd";

    /* Slave Force Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_SLAVE_FORCE_WAKE_REQ_TRACE].pucTrackId        = "SlaveReq";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_SLAVE_FORCE_WAKE_START_TRACE].pucTrackId      = "SlaveMsg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_SLAVE_FORCE_WAKE_END_TRACE].pucTrackId        = "SlaveEnd";

    /* Resume */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_INT_TRACE].pucTrackId                  = "Rsme Int";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_START_TRACE].pucTrackId                = "Rsme Msg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_END_TRACE].pucTrackId                  = "Rsme End";

    /* ACT */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_DEACTIVATE_START].pucTrackId                  = "DeactStr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_DEACTIVATE_END].pucTrackId                    = "DeactEnd";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_ACTIVATE_START].pucTrackId                    = "ActivStr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_ACTIVATE_END].pucTrackId                      = "ActivEnd";

    /* Assist Track */
    /* Halt */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_INT_TO_MSG_TRACE].pucTrackId             = "Halt IntToMsg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_SMP_TRACE].pucTrackId                    = "Halt  SmpSucc";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_WAKE_START_TRACE].pucTrackId             = "Halt  WakeStr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_WAKE_END_TRACE].pucTrackId               = "Halt  WakeEnd";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_CPROC_1X_SLEEP_TRACE].pucTrackId         = "Halt  1xSleep";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_CPROC_HRPD_SLEEP_TRACE].pucTrackId       = "Halt  DoSleep";

    /* Normal Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_INT_TO_MSG_TRACE].pucTrackId      = "Wake IntToMsg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_SMP_TRACE].pucTrackId             = "Wake  SmpSucc";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_NORMAL_WAKE_PROC_TRACE].pucTrackId            = "Wake     Proc";

    /* Master Force Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_SMP_TRACE].pucTrackId       = "MasterSmpSucc";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_PROC_TRACE].pucTrackId      = "Master   Proc";

    /* Slave Force Wake */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_SLAVE_FORCE_WAKE_SMP_TRACE].pucTrackId        = "Slave SmpSucc";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_SLAVE_FORCE_WAKE_PROC_TRACE].pucTrackId       = "Slave    Proc";

    /* Resume */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_INT_TO_MSG_TRACE].pucTrackId           = "Rsme IntToMsg";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_SMP_TRACE].pucTrackId                  = "Rsme  SmpSucc";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_CPROC_1X_WAKEUP_TRACE].pucTrackId      = "Rsme 1xWakeup";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_CPROC_HRPD_WAKEUP_TRACE].pucTrackId    = "Rsme DoWakeup";

    /* Abnormal Track */
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_HALT_INT_NOT_NORMAL_TRACE].pucTrackId         = "Halt StatuErr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_WAKE_INT_NOT_LP_TRACE].pucTrackId             = "Wake StatuErr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_RESUME_INT_NOT_TEMP_TRACE].pucTrackId         = "Rsme StatuErr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MASTER_FORCE_WAKE_MODE_ERR_TRACE].pucTrackId  = "Force ModeErr";
    g_pstSleepBBE16NormalState->astRecordItem[VOS_RATMODE_1X][SLEEP_BBE16_MBX_OTHER_CHANNEL_TRACE].pucTrackId           = "Xmbx  Channel";

    return;
}
#endif

/*****************************************************************************
 �� �� ��  : SLEEP_Init
 ��������  : SLEEPģ���ʼ������
 �������  : VOS_VOID

 �������  :

 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_VOID SLEEP_Init(VOS_VOID)
{
    SLEEP_MODE_ENUM_UINT32              enMode;
    /*lint -e438 ����ulRecordAddrû��ʹ�õĴ���*/
    VOS_UINT32                          ulRecordAddr;
    UCOM_NV_TRI_MODE_ENABLE_STRU        stRfSwitchFlag;
    BSP_DDR_SECT_QUERY_S                stModemSrSectQuery;
    BSP_DDR_SECT_INFO_S                 stModemSrSectInfo = {BSP_DDR_SECT_TYPE_MODEM_SR_STAMP};

    /* ��ʼ����λ��Ϣ */
    ulRecordAddr = (VOS_UINT32)VOS_EXCH_MEM_MALLOC(VOS_DUMP_MEM_TOTAL_SIZE);

#if defined (INSTANCE_1)
    if (VOS_NULL_PTR != ulRecordAddr)
    {
        ulRecordAddr += sizeof(VOS_UINT32);

        ulRecordAddr += sizeof(SLEEP_TRACK_RECORD_STRU) + sizeof(SLEEP_NORMAL_STATE_RECORD_STRU)
                        + sizeof(SLEEP_DEVICE_STATE_STRU) + sizeof(SLEEP_INFO_STATE_STRU) + sizeof(SLEEP_BBE16_NORMAL_STATE_RECORD_STRU);
    }
#elif defined (INSTANCE_2)
    if (VOS_NULL_PTR != ulRecordAddr)
    {
        ulRecordAddr += 2*sizeof(VOS_UINT32);

        ulRecordAddr += 2*(sizeof(SLEEP_TRACK_RECORD_STRU) + sizeof(SLEEP_NORMAL_STATE_RECORD_STRU)
                        + sizeof(SLEEP_DEVICE_STATE_STRU) + sizeof(SLEEP_INFO_STATE_STRU) + sizeof(SLEEP_BBE16_NORMAL_STATE_RECORD_STRU));
    }
#endif

    if (VOS_NULL_PTR != ulRecordAddr)
    {
        *(VOS_UINT32*)ulRecordAddr = 0x5555aaaa;

        ulRecordAddr += sizeof(VOS_UINT32);

        g_pstSleepTrackRecord = (SLEEP_TRACK_RECORD_STRU*)ulRecordAddr;

        /*lint -e534*/
        VOS_MemSet(g_pstSleepTrackRecord, 0, sizeof(SLEEP_TRACK_RECORD_STRU));
        /*lint +e534*/

        ulRecordAddr += sizeof(SLEEP_TRACK_RECORD_STRU);

        g_pstSleepNormalState = (SLEEP_NORMAL_STATE_RECORD_STRU*)ulRecordAddr;

        /*lint -e534*/
        VOS_MemSet(g_pstSleepNormalState, 0, sizeof(SLEEP_NORMAL_STATE_RECORD_STRU));
        /*lint +e534*/

        ulRecordAddr += sizeof(SLEEP_NORMAL_STATE_RECORD_STRU);

        g_pstSleepDeviceState   = (SLEEP_DEVICE_STATE_STRU *)ulRecordAddr;

        /*lint -e534*/
        VOS_MemSet(g_pstSleepDeviceState,   0, sizeof(SLEEP_DEVICE_STATE_STRU));
        /*lint +e534*/

        ulRecordAddr += sizeof(SLEEP_DEVICE_STATE_STRU);

        g_pstSleepDeviceState->ulDeviceFlag = 0x5A5A5A5A;

        g_pstSleepInfoSlice      = (SLEEP_INFO_STATE_STRU *)ulRecordAddr;

        ulRecordAddr += sizeof(SLEEP_INFO_STATE_STRU);

        g_pstSleepInfoSlice->ulEndFlag   = 0x87878787;

        g_pstSleepBBE16NormalState = (SLEEP_BBE16_NORMAL_STATE_RECORD_STRU*)ulRecordAddr;

        /*lint -e534*/
        VOS_MemSet(g_pstSleepBBE16NormalState, 0, sizeof(SLEEP_BBE16_NORMAL_STATE_RECORD_STRU));
        /*lint +e534*/

        ulRecordAddr += sizeof(SLEEP_BBE16_NORMAL_STATE_RECORD_STRU);
    }

    /* ��ʼ��ϵͳ״̬ */
    for (enMode = 0; enMode < SLEEP_GU_MODE_TYPE_BUTT; enMode++)
    {
        g_astSleepModeInfo[enMode].enSystemState = SLEEP_NORMAL_STATE;
    }

    for (enMode = 0; enMode < SLEEP_C_MODE_TYPE_BUTT; enMode++)
    {
        g_astSleepBBE16ModeInfo[enMode].enSystemState   = SLEEP_BBE16_NORMAL_STATE;
        g_astSleepBBE16ModeInfo[enMode].enCdmaSleepType = CPHY_SLEEP_TYPE_NONE;
    }

    g_stSleepCDMAControl.ulInfoHeadFlag     = 0x5A5A5A5A;
    g_stSleepCDMAControl.ulBBE16PowerState  = VOS_FALSE;

    if(VOS_OK != VOS_SmMCreate("SLEEP", VOS_SEMA4_PRIOR | VOS_SEMA4_INVERSION_SAFE, &g_ulSleepSem))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Create SLEEP.\r\n");
        /*lint +e534*/
        return;
    }

    if(VOS_OK != VOS_SmCCreate("TCXO", 0, VOS_SEMA4_FIFO, &g_ulSleepTcxoSem))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Create TCXO.\r\n");
        /*lint +e534*/
        return;
    }

#if (FEATURE_GUC_BBP_TRIG == FEATURE_OFF)
    if(VOS_OK != VOS_SmCCreate("DMA", 0, VOS_SEMA4_FIFO, &g_ulSleepDMACapSem))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Create DMA.\r\n");
        /*lint +e534*/
        return;
    }
#endif

#if defined (INSTANCE_1) || defined (INSTANCE_2)
#else
    if(VOS_OK != VOS_SmBCreate("Ssem", VOS_SEM_FULL, VOS_SEMA4_PRIOR | VOS_SEMA4_INVERSION_SAFE, &g_ulSleepSlaveSem))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Create Ssem.\r\n");
        /*lint +e534*/
        return;
    }
#endif

    /* ��ȡNV�����ȶ�ʱ�� */
    if(NV_OK != NV_Read(en_NV_Item_WG_DRX_RESUME_TIME, &g_stSleepDrxResumeTime, sizeof(WG_DRX_RESUME_TIME_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_WG_DRX_RESUME_TIME Fail.\r\n");
        /*lint +e534*/
        return;
    }

    /* ��ȡDRX�ϵ������쳣����ʹ�ܱ�־ */
    if(NV_OK != NV_Read(en_NV_Item_DRX_RESET_ENABLE_CFG, &g_bDrxResetFlag, sizeof(NV_SLEEP_DRX_RESET_ENABLE_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_DRX_RESET_ENABLE_CFG Fail.\r\n");
        /*lint +e534*/
        return;
    }

    /* ��ȡȫ��ͨProfile Index������ */
    if(NV_OK != NV_Read(en_NV_Item_TRI_MODE_FEM_PROFILE_ID, &g_stChannelModeProfileId, sizeof(UCOM_NV_TRI_MODE_FEM_PROFILE_ID_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_TRI_MODE_FEM_PROFILE_ID Fail.\r\n");
        /*lint +e534*/

        VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

        return;
    }

    if (g_stChannelModeProfileId.uwProfileId >= UCOM_NV_TRI_MODE_CHAN_PARA_PROFILE_NUM)
    {
        VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);
    }

#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    /* ��ȡģʽͨ�������� */
    if(NV_OK != NV_Read(en_NV_Item_FEM_CHAN_PROFILE, &g_stChannelModeProfile, sizeof(UCOM_NV_FEM_CHAN_PROFILE_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_FEM_CHAN_PROFILE Fail.\r\n");
        /*lint +e534*/

        VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

        return;
    }
#else
    /* ��ȡģʽͨ�������� */
    if(NV_OK != NV_Read(en_NV_Item_TRI_MODE_FEM_CHAN_PROFILE, &g_stChannelModeProfile, sizeof(UCOM_NV_TRI_MODE_FEM_CHAN_PROFILE_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_TRI_MODE_FEM_CHAN_PROFILE Fail.\r\n");
        /*lint +e534*/

        VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

        return;
    }
#endif

    /* ��ȡȫ��ͨProfile Index������ */
    if(NV_OK != NV_Read(en_NV_Item_TRI_MODE_ENABLE, &stRfSwitchFlag, sizeof(UCOM_NV_TRI_MODE_ENABLE_STRU)))
    {
        /*lint -e534*/
        LogPrint("SLEEP_Init: Read en_NV_Item_TRI_MODE_ENABLE Fail.\r\n");
        /*lint +e534*/

        return;
    }

#if defined (INSTANCE_1) || defined (INSTANCE_2)
#else
    if (VOS_TRUE == stRfSwitchFlag.uhwEnable)
    {
        if (VOS_TRUE == g_stChannelModeProfile.astPara[g_stChannelModeProfileId.uwProfileId].uwGpioCtrl)
        {
            /* ȫ��ͨ������Ҫ����ʱ������Ƶ�ܽ� */
            if ( VOS_OK != mdrv_fem_ioctrl(CFG_RFFE_GROUP_GPIO_MIPI, UPHY_OAM_NV_INDEX_FULL_NET, 0, VOS_NULL))
            {
                VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

                return;
            }
        }
        else
        {
            /* ȫ��ͨ������Ҫ����ʱ������Ƶ�ܽ� */
            if ( VOS_OK != mdrv_fem_ioctrl(CFG_RFFE_GROUP_GPIO_MIPI, UPHY_OAM_NV_INDEX_FULL_NET, 1, VOS_NULL))
            {
                VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

                return;
            }
        }
    }
#endif

    /* ����ʱ���õ������µ�ͨ�� */
    if ( VOS_OK != SLEEP_GBBPClkSrcSelect() )
    {
        VOS_ProtectionReboot(DRX_FULLNET_SET_ERROR, VOS_FILE_ID, __LINE__, VOS_NULL_PTR, VOS_NULL);

        return;
    }

    stModemSrSectQuery.enSectType   = BSP_DDR_SECT_TYPE_MODEM_SR_STAMP;

    if (VOS_OK == mdrv_get_fix_ddr_addr(&stModemSrSectQuery, &stModemSrSectInfo))
    {
        g_pstSleepWakeSliceAddr  = (T_MODEM_SR_STAMP_STRU *)((VOS_UINT32)stModemSrSectInfo.pSectVirtAddr);
    }

    SLEEP_TimeCal();

    /* ע��SLEEP���Ӻ�����OSA */
    /*lint -e534*/
    VOS_RegisterAwakeFun(SLEEP_GetModemId(), SLEEP_HookMsgProc);
    /*lint +e534*/

    SLEEP_NotifyStateRegPidTblInit();

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    /* ȫ�ֱ���ָ��SRAM */
    g_pstBBE16SleepInfo = (CPHY_OAM_SHARE_INFO_STRU *)CPHY_SRAM_ADDR;

    if (VOS_NULL_PTR == g_pstBBE16SleepInfo)
    {
        (VOS_VOID)vos_printf("SLEEP get SRAM fail!\r\n");

        return;
    }

    SLEEP_BBE16DbgInit();

    mlp_dsp_init();

    /* ��������ע��ӿ� ע���������� */
    mdrv_MailBox_GetCdmaStatusReg((BSP_xMBX_GET_STATUS_FUNC)SLEEP_BBE16MailBoxGetDspState);
    mdrv_MailBox_CdmaForceAwakeReg((BSP_xMBX_DSP_AWAKE_FUNC)SLEEP_BBE16MailBoxForceWakeDsp);
#endif

    return;
    /*lint +e438 ����ulRecordAddrû��ʹ�õĴ���*/
}

/*****************************************************************************
 �� �� ��  : WuepsAwakePidInit
 ��������  : Awake ģ�� PID �ĳ�ʼ������
 �������  : ip: ��ʼ������

 �������  :

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��03��09��
    ��    ��   : s00207770
    �޸�����   : �͹����������ȼ������Ŀ��������

*****************************************************************************/
VOS_UINT32 WuepsAwakePidInit(enum VOS_INIT_PHASE_DEFINE ip)
{
    switch( ip )
    {
        case VOS_IP_LOAD_CONFIG:
            break;

        default:
            break;
    }

    return VOS_OK;
}

VOS_UINT32 WuepsAwakeFidInit(enum VOS_INIT_PHASE_DEFINE ip)
{
    VOS_UINT32                          ulRslt;

    switch( ip )
    {
        case VOS_IP_LOAD_CONFIG:
        {
            ulRslt = VOS_RegisterPIDInfo(WUEPS_PID_AWAKE,
                                        (Init_Fun_Type)WuepsAwakePidInit,
                                        (Msg_Fun_Type)SLEEP_AwakeMsgProc);

            if( VOS_OK != ulRslt )
            {
                return VOS_ERR;
            }

            ulRslt = VOS_RegisterTaskPrio(WUEPS_FID_AWAKE, COMM_AWAKE_TASK_PRIO);

            if( VOS_OK != ulRslt )
            {
                return VOS_ERR;
            }

            break;
        }

        default:
            break;
    }

    return VOS_OK;
}

/*****************************************************************************
 �� �� ��  : WuepsSleepPidInit
 ��������  : SLEEP ģ�� PID �ĳ�ʼ������
 �������  : ip: ��ʼ������

 �������  :

 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��07��31��
    ��    ��   : g47350
    �޸�����   : V900R001��Ŀ��������

*****************************************************************************/
VOS_UINT32 WuepsSleepPidInit(enum VOS_INIT_PHASE_DEFINE ip)
{
    switch( ip )
    {
        case VOS_IP_LOAD_CONFIG:
            break;

        default:
            break;
    }

    return VOS_OK;
}

/*****************************************************************************
 �� �� ��  : WuepsSleepFidInit
 ��������  : SLEEP ģ�� FID �ĳ�ʼ������
 �������  : enum VOS_INIT_PHASE_DEFINE ip
 �������  : ��
 �� �� ֵ  : VOS_UINT32 FID ��ʼ�����
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 WuepsSleepFidInit(enum VOS_INIT_PHASE_DEFINE ip)
{
    VOS_UINT32                          ulRslt;

    switch( ip )
    {
        case VOS_IP_LOAD_CONFIG:
        {
            ulRslt = VOS_RegisterPIDInfo(WUEPS_PID_SLEEP,
                                        (Init_Fun_Type)WuepsSleepPidInit,
                                        (Msg_Fun_Type)SLEEP_SleepMsgProc);

            if( VOS_OK != ulRslt )
            {
                return VOS_ERR;
            }

            ulRslt = VOS_RegisterTaskPrio(WUEPS_FID_SLEEP, COMM_SLEEP_TASK_PRIO);

            if( VOS_OK != ulRslt )
            {
                return VOS_ERR;
            }

            SLEEP_Init();

            break;
        }

        default:
            break;
    }

    return VOS_OK;
}

VOS_VOID SLEEP_GUChannelShow(VOS_VOID)
{
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
    /*lint -e534*/
    vos_printf("\r\n FEATURE_MODE_FEM_CHAN_EXT ON Channel\r\n");

    vos_printf("GSM ABB   CHAN is %d\r\n", SLEEP_ABB_CHAN(VOS_RATMODE_GSM));
    vos_printf("GSM RF    CHAN is %d\r\n", SLEEP_RF_CHAN(VOS_RATMODE_GSM));
    vos_printf("GSM TCXO  CHAN is %d\r\n", SLEEP_TCXO_CHAN(VOS_RATMODE_GSM));
    vos_printf("GSM RFCLK CHAN is %d\r\n", SLEEP_RFCLK_CHAN(VOS_RATMODE_GSM));

    vos_printf("WCDMA ABB   CHAN is %d\r\n", SLEEP_ABB_CHAN(VOS_RATMODE_WCDMA));
    vos_printf("WCDMA RF    CHAN is %d\r\n", SLEEP_RF_CHAN(VOS_RATMODE_WCDMA));
    vos_printf("WCDMA TCXO  CHAN is %d\r\n", SLEEP_TCXO_CHAN(VOS_RATMODE_WCDMA));
    vos_printf("WCDMA RFCLK CHAN is %d\r\n", SLEEP_RFCLK_CHAN(VOS_RATMODE_WCDMA));
    /*lint +e534*/
#else
    /*lint -e534*/
    vos_printf("\r\n FEATURE_MODE_FEM_CHAN_EXT OFF Channel\r\n");

    vos_printf("GSM ABB   CHAN is %d\r\n", SLEEP_ABB_CHAN(VOS_RATMODE_GSM));
    vos_printf("GSM RF    CHAN is %d\r\n", SLEEP_RF_CHAN(VOS_RATMODE_GSM));
    vos_printf("GSM TCXO  CHAN is %d\r\n", SLEEP_TCXO_CHAN(VOS_RATMODE_GSM));

    vos_printf("WCDMA ABB   CHAN is %d\r\n", SLEEP_ABB_CHAN(VOS_RATMODE_WCDMA));
    vos_printf("WCDMA RF    CHAN is %d\r\n", SLEEP_RF_CHAN(VOS_RATMODE_WCDMA));
    vos_printf("WCDMA TCXO  CHAN is %d\r\n", SLEEP_TCXO_CHAN(VOS_RATMODE_WCDMA));
    /*lint +e534*/
#endif
}

/*****************************************************************************
 �� �� ��  : SLEEP_WakeSliceShow
 ��������  : ����ʱ�̴����ʾ
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2015��8��24��
    ��    ��   : S00207770
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID SLEEP_WakeSliceShow( VOS_VOID )
{
    VOS_UINT32                          i;

    if (VOS_NULL_PTR != g_pstSleepWakeSliceAddr)
    {
        for (i = 0; i < 8; i++)
        {
            /*lint -e534*/
            vos_printf("SLEEP Wake Slice[%d] is %x\r\n", i, g_pstSleepWakeSliceAddr->auwCommSRStamp[i]);
            /*lint +e534*/
        }
    }
}

#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif
