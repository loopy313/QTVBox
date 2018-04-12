#include <QString>
#include <QtTest>
#include<AVInfo.h>

class UnittestTest : public QObject
{
	Q_OBJECT
private:
	QString str;
	//AVInfo info;
public:

	UnittestTest();

private Q_SLOTS:
	void myTestFunction();
};

UnittestTest::UnittestTest()//:info("d:/aac.m4a")
{

}

void UnittestTest::myTestFunction()
{
	/*
	QVERIFY2(info.getAudioContext(),"actx error");
	QVERIFY2(info.getAudioIdx(),"aidx error");
	QVERIFY2(info.getAudioQueue(),"aqueue error");
	QVERIFY2(info.getFormatContext(),"fmtctx error");
	QVERIFY2(info.getVideoContext(),"vctx error");
	QVERIFY2(info.getVideoQueue(),"vqueue error");
	QVERIFY2(info.getVideoIdx(),"vidx error");
*/
}

QTEST_APPLESS_MAIN(UnittestTest)

#include "tst_UnittestTest.moc"
