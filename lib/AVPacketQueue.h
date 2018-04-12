#ifndef AVPACKETQUEUE_H
#define AVPACKETQUEUE_H
#include "lib_global.h"
#include<QQueue>
#include<QWaitCondition>
#include<QMutexLocker>

class QAVPacket;
class LIBSHARED_EXPORT AVPacketQueue
{
private:
	QQueue<QAVPacket> queue;
	QMutex mutex;
	QWaitCondition que_wait;
public:
	AVPacketQueue();
	void enqueue(const QAVPacket& packet);
	QAVPacket dequeue();
	~AVPacketQueue();
};

#endif // QAVPACKETQUEUE_H
