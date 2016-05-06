#include "gtest/gtest.h"
#include "llt_mockcpp.h"

#include "uttest_AtParseExtendCmd.h"


//�����������ã����������ùؼ���ʱ��Ҫ��ǰ׺ testing::
using namespace testing;

//˵��������������gtest+�������׺Ͳ����������ֲ�����Ϊ��
//      ������ú�gtest��ͬ�Ĺؼ��֣����ⲻ��Ҫ���鷳
//      gtest�ṩ EXPECT �� ASSERT ����,���庬����Կ���Ƭ�����׺궼��һһ��Ӧ�ģ�������EXPECTΪ��

//1���ȶԲ������� EXPECT_TRUE��EXPECT_FALSE/ASSERT_TRUE
//2���Ƚ����� EXPECT_EQ EXPECT_NE
//3���Ƚ��ַ��� EXPECT_STREQ
//4������ʧ�������Ϣ ADD_FAILUREd
//5�����óɹ���ʧ�� SUCCEED FAIL
//6���Զ����ʽ EXPECT_PRED_FORMAT3
//7�����������������TRUE EXPECT_PRED1
//8�������ͱȽ� EXPECT_FLOAT_EQ EXPECT_PRED_FORMAT2 ASSERT_PRED_FORMAT2
//9�����ͼ�� StaticAssertTypeEq
//10������3�ֲ��Լ����¼�
//11����ȡ������������ test_case_name()
//12���Ƚ��쳣 EXPECT_THROW
//13���ṹ�����ͱȽ�ASSERT_SAME_DATA ASSERT_SAME_MEMORY

#if(FEATURE_ON == FEATURE_E5)
/******************************************************************************
����     : Test_AT_ParseSetApMacCmd
�������� : AT_ParseSetApMacCmd UT������
�޸���ʷ :
 1.��   ��  : 2014-05-28
   ��   ��  : Y00213812
   �޸����� : 64bit ut�޸�
******************************************************************************/
class Test_AT_ParseSetApMacCmd: public ::testing::Test
{
public:

    void SetUp()
    {
		UT_STUB_INIT();
    }

    void TearDown()
    {
    }

};
/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC������������ַ�������Ϊ0
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_01 )
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 0;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;


	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC������������ڴ�ʧ��
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_02)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMAC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 26;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
/* Modified by f62575 for V9R1 STK����, 2013-6-26, begin */
    MOCKER(V_MemAlloc)
		.will(returnValue(VOS_NULL_PTR));
/* Modified by f62575 for V9R1 STK����, 2013-6-26, end */

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC�������ȥ���ַ����е��˸������
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_03)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMAC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 26;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_FAILURE));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC�������ȥ���ַ����еĿ��Ʒ�����
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_04)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMAC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 26;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanCtlChar)
		.will(returnValue(AT_FAILURE));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}


/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC�������ȥ���ַ����еĿո����
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_05)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMAC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 26;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanCtlChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanBlankChar)
		.will(returnValue(AT_FAILURE));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC��������ַ�������С��9
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_06)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMA=";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 8;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanCtlChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanBlankChar)
		.will(returnValue(AT_SUCCESS));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC��������ַ���ͷ��ΪAT^APMAC=
*Ԥ�ڽ����       ����AT_FAILURE
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_07)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[30]="AT^APMCC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 26;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanCtlChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanBlankChar)
		.will(returnValue(AT_SUCCESS));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_FAILURE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}

/*******************************************************************
*������:          �����Ƿ���APMAC��������������ȡ���ƺͳ���
*���⺯����������:�����Ƿ���APMAC������������ɹ�
*Ԥ�ڽ����       ����AT_SUCCESS
************************* �޸ļ�¼ *************************
#  1.��    ��: 2010��9��13��
#    ��    ��: z00161729
#    �޸�����: �½�CASE
*******************************************************************/
TEST_F(Test_AT_ParseSetApMacCmd,Test_AT_ParseSetApMacCmd_08)
{
    // ��������
	VOS_UINT8                          *pucData;
	VOS_UINT16                          usLen;
	VOS_UINT8                           auData[40]="AT^WIFIGLOBALMAC=00:1E:10:12:F6:16";
	VOS_UINT32                          ulRst;

    // ������ʼ��
    pucData = auData;
	usLen = 34;

    // ���ȫ�ֱ�����ʼ��

    // MOCKER����;
    MOCKER(At_ScanDelChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanCtlChar)
		.will(returnValue(AT_SUCCESS));

	MOCKER(At_ScanBlankChar)
		.will(returnValue(AT_SUCCESS));

	// ���ñ��⺯��
    ulRst = AT_ParseSetApMacCmd(pucData,usLen);

    // ִ�м��
    EXPECT_EQ(ulRst,AT_SUCCESS);
	EXPECT_EQ(gstATCmdName.usCmdNameLen,strlen("^WIFIGLOBALMAC"));
	EXPECT_EQ(strcmp((const char*)gstATCmdName.aucCmdName,"^WIFIGLOBALMAC"),0);
	EXPECT_EQ(gastAtParaList[0].usParaLen,17);
	EXPECT_EQ(strcmp((const char*)gastAtParaList[0].aucPara,"00:1E:10:12:F6:16"),0);
	EXPECT_EQ(gucAtParaIndex,1);
	EXPECT_EQ(gucAtCmdOptType ,AT_CMD_OPT_SET_PARA_CMD);
	EXPECT_EQ(gucAtCmdFmtType ,AT_EXTEND_CMD_TYPE);

    //������ʱ����Ҫ����������λ�ü������
    GlobalMockObject::verify();

}
#endif