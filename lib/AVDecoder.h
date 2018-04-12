#ifndef AVDECODER_H
#define AVDECODER_H
#include "lib_global.h"
#include<AVInfo.h>
#include<QObject>
#include "QAVWorker.h"

struct AVCodecContext;
class AVInfo;
class AVPacketQueue;
class LIBSHARED_EXPORT AVDecoder : public QAVWorker
{
protected:
	AVPacketQueue* pAudQueue;
	AVPacketQueue* pVidQueue;
	AVCodecContext* pACtx;
	AVCodecContext* pVCtx;
	const AVInfo& info;

public:
	AVDecoder(const AVInfo& info);
	void init();
	virtual bool decode()=0;
	virtual ~AVDecoder();
};

#endif // AVDECODER_H
