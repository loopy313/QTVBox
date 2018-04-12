#ifndef AVINFO_H
#define AVINFO_H
#include "lib_global.h"
#include<QString>

struct AVFormatContext;
struct AVCodecContext;
class AVPacketQueue;
class LIBSHARED_EXPORT AVInfo
{
public:
	AVInfo(const QString& filename);
	AVFormatContext* getFormatContext() const;
	AVCodecContext* getAudioContext() const;
	AVCodecContext* getVideoContext() const;
	size_t getVideoIdx() const;
	size_t getAudioIdx() const;
	AVPacketQueue* getVideoQueue() const;
	AVPacketQueue* getAudioQueue() const;
	~AVInfo();
private:
	void openContext(const QString& filename);
	AVFormatContext* pFmtCtx;
	AVCodecContext* pOrgACtx;
	AVCodecContext* pOrgVCtx;
	AVCodecContext* pACtx;
	AVCodecContext* pVCtx;
	AVPacketQueue* pVidQueue;
	AVPacketQueue* pAudQueue;
	size_t vIdx,aIdx;
	QByteArray decoded_aud;
	QByteArray decoded_vid;
};

#endif // AVINFO_H
