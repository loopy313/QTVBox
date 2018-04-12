#include "QAVWorker.h"

QAVWorker::QAVWorker(QObject *parent) : QObject(parent)
{

}

QAVWorker::~QAVWorker()
{
	emit finished();
}
