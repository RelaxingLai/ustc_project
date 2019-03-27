#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MyConvertion/Rmb.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1CheckNum
{		
	TEST_CLASS(UnitTestCheckNum)
	{
	public:	
		TEST_METHOD(TestCheckNum1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "112a";
			Assert::IsFalse(m.checkNum(s));
		}
		TEST_METHOD(TestCheckNum2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "1.2354.4";
			Assert::IsFalse(m.checkNum(s));
		}
		TEST_METHOD(TestCheckNum3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "1.23544";
			Assert::IsTrue(m.checkNum(s));
		}
	};
}

namespace UnitTestTest2RoundString
{
	TEST_CLASS(UnitTestRoundString)
	{
	public:
		TEST_METHOD(TestRoundString1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "1234567890123456";
			string r = m.roundString(s);
			string ts = "";
			Assert::AreEqual(ts, r);
		}
		TEST_METHOD(TestRoundString2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "11111.34967";
			string r = m.roundString(s);
			string ts = "1111135";
			Assert::AreEqual(ts, r);
		}
		TEST_METHOD(TestRoundString3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "12345";
			string r = m.roundString(s);
			string ts = "1234500";
			Assert::AreEqual(ts, r);
		}
		TEST_METHOD(TestRoundString4)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "000345";
			string r = m.roundString(s);
			string ts = "34500";
			Assert::AreEqual(ts, r);
		}
	};
}

namespace UnitTest3Convert
{
	TEST_CLASS(UnitTestConvert)
	{
	public:
		TEST_METHOD(TestConvert1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "12";
			string ts = m.convert(1,s);
			string rs = "Ҽʰ��Ԫ";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestConvert2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "12";
			string ts = m.convert(2, s);
			string rs = "Ҽ�Ƿ���";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestConvert3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "1003";
			string ts = m.convert(1, s);
			string rs = "ҼǪ�����ʰ��Ԫ";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestConvert4)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "04";
			string ts = m.convert(2, s);
			string rs = "�������";
			Assert::AreEqual(ts, rs);
		}
	};
}

namespace UnitTest4SplitConvertedNum
{
	TEST_CLASS(UnitTestSplitConvertedNum)
	{
	public:
		TEST_METHOD(TestSplitConvertedNum1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "";
			string ts = m.splitConvertedNum(s);
			string shoulds = "";
			Assert::AreEqual(ts, shoulds);
		}
		TEST_METHOD(TestSplitConvertedNum2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "12345";
			string ts = m.splitConvertedNum(s);
			string shoulds = "Ҽ�۷�ʰ��Ԫ�������";
			Assert::AreEqual(ts, shoulds);
		}
		TEST_METHOD(TestSplitConvertedNum3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "123456";
			string ts = m.splitConvertedNum(s);
			string shoulds = "ҼǪ������ʰ��Ԫ���½��";
			Assert::AreEqual(ts, shoulds);
		}
		TEST_METHOD(TestSplitConvertedNum4)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "1004506";
			string ts = m.splitConvertedNum(s);
			string shoulds = "Ҽ����Ǫ�����ʰ��Ԫ���½��";
			Assert::AreEqual(ts, shoulds);
		}
		TEST_METHOD(TestSplitConvertedNum5)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "0000000000";
			string ts = m.splitConvertedNum(s);
			string shoulds = "��Ǫ�����ʰ������Ǫ�����ʰ��Ԫ������";
			Assert::AreEqual(ts, shoulds);
		}
	};
}

namespace UnitTest5ReplaceAll
{
	TEST_CLASS(UnitTestReplaceAll)
	{
	public:
		TEST_METHOD(TestReplaceAll_l)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "����������";
			string ts = m.replaceAll(s,"������", "��");
			string rs = "��";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestReplaceAll_2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "Ҽ����Ǫ�����ʰ��Ԫ���½��";
			string ts = m.replaceAll(s, "��Ǫ", "��");
			ts = m.replaceAll(ts, "���", "��");
			ts = m.replaceAll(ts, "���", "��");
			//ts = m.replaceAll(ts, "����", "��");
			string rs = "Ҽ��������ʰ��Ԫ��½��";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestReplaceAll_3)
		{
			Rmb m;
			string s = "Ҽ��������ʰ��Ԫ��½��";
			string ts = m.replaceAll(s, "����", "��");
			string rs = "Ҽ������ʰ��Ԫ��½��";
			Assert::AreEqual(ts, rs);
		}
	};
}

namespace UnitTest6ClearZero
{
	TEST_CLASS(UnitTestClearZero)
	{
	public:
		TEST_METHOD(TestClearZero1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "Ҽ����Ǫ�����ʰ��Ԫ���½��";
			string ts = m.clearZero(s);
			string rs = "Ҽ������ʰ��Ԫ��½��";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestClearZero2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "������ʰ��Ԫ������";
			string ts = m.clearZero(s);
			string rs = "����Ԫ";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestClearZero3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "ҼǪ������ʰ��Ԫ���½��";
			string ts = m.clearZero(s);
			string rs = "ҼǪ������ʰ��Ԫ���½��";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestClearZero4)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "Ҽ����Ǫ�����ʰ��Ԫ������";
			string ts = m.clearZero(s);
			string rs = "Ҽ��Ԫ";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestClearZero5)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "Ҽ����Ǫ�����ʰ��Ԫ������";
			string ts = m.clearZero(s);
			string rs = "Ҽ��Ԫ���";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestClearZero6)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "Ҽ����Ǫ�����ʰ��Ԫ������";
			string ts = m.clearZero(s);
			string rs = "Ҽ����ǪԪ���";
			Assert::AreEqual(ts, rs);
		}
	};
}


namespace UnitTest7add
{
	TEST_CLASS(UnitTestAdd)
	{
	public:
		TEST_METHOD(TestAdd1)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "����Ԫ";
			string ts = m.add(s);
			string rs = "����ҷ���Ԫ��";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestAdd2)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "����Ԫ����";
			string ts = m.add(s);
			string rs = "����ҷ���Ԫ����";
			Assert::AreEqual(ts, rs);
		}
		TEST_METHOD(TestAdd3)
		{
			// TODO: �ڴ�������Դ���
			Rmb m;
			string s = "�������";
			string ts = m.add(s);
			string rs = "������������";
			Assert::AreEqual(ts, rs);
		}
	};
}