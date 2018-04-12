#include "QAVThread.h"
#include "QAVWorker.h"
#include <QThread>

QAVThread::QAVThread(QAVWorker *w, QObject *parent):QObject(parent)
{
	QAVWorker *_w=w;
	_w->moveToThread(&workerThread);
	connect(&workerThread,SIGNAL(started()),_w,SLOT(dowork()));
	connect(&workerThread,SIGNAL(finished()),_w,SLOT(deleteLater()));
	connect(_w,SIGNAL(finished()),&workerThread,SLOT(deleteLater()));
	connect(_w,SIGNAL(finished()),&workerThread,SLOT(quit()));
	connect(_w,SIGNAL(resultReady(int)),this,SLOT(handleResult(int)));
	workerThread.start();
}

QAVThread::~QAVThread()
{
	workerThread.quit();
	workerThread.wait();
}

void QAVThread::handleResult(int result)
{
	Q_UNUSED(result);
}
