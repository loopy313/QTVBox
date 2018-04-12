#ifndef AVDEMUXER_H
#define AVDEMUXER_H
#include "lib_global.h"
#include<QObject>
#include "QAVWorker.h"

struct AVFormatContext;
class AVInfo;
class AVPacketQueue;
class LIBSHARED_EXPORT AVDemuxer: public QAVWorker
{
private:
	AVFormatContext* pFmtCtx;
	size_t vIdx,aIdx;
	AVPacketQueue* audQueue;
	AVPacketQueue* vidQueue;
	const AVInfo& info;
public:
	AVDemuxer(const AVInfo& _info);
	virtual ~AVDemuxer();
	void init();
	void readPacket();
	virtual void dowork() override;
};

#endif // AVDEMUXER_H
