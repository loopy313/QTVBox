#include "AVPacketQueue.h"
#include<QAVPacket.h>
AVPacketQueue::AVPacketQueue():mutex(QMutex::Recursive)
{

}

void AVPacketQueue::enqueue(const QAVPacket &packet)
{
	QMutexLocker lock(&mutex);
	queue.enqueue(packet);
	que_wait.wakeAll();
}

QAVPacket AVPacketQueue::dequeue()
{
	QMutexLocker lock(&mutex);
	if(queue.isEmpty()){
		que_wait.wait(&mutex,200);
		if(queue.isEmpty())
			return QAVPacket();
	}
	return queue.dequeue();
}

AVPacketQueue::~AVPacketQueue()
{
	queue.clear();
}
