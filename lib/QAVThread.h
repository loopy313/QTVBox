#ifndef QAVTHREAD_H
#define QAVTHREAD_H
#include "lib_global.h"
#include <QObject>
#include <QThread>

class QAVWorker;
class LIBSHARED_EXPORT QAVThread : public QObject
{
	Q_OBJECT
private:
	QThread workerThread;
public:
	explicit QAVThread(QAVWorker *w,QObject *parent = nullptr);
	virtual ~QAVThread();
signals:

public slots:
	void handleResult(int result);
};

#endif // QAVTHREAD_H
