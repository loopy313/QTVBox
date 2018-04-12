#ifndef QAVWORKER_H
#define QAVWORKER_H
#include "lib_global.h"
#include <QObject>

class LIBSHARED_EXPORT QAVWorker : public QObject
{
	Q_OBJECT
public:
	explicit QAVWorker(QObject *parent = nullptr);
	virtual ~QAVWorker();
signals:
	void resultReady(int);
	void finished();
public slots:
	virtual void dowork()=0;
};

#endif // QAVWORKER_H
