#include "AVInfo.h"
#include<QThread>
#include<AVPacketQueue.h>
extern "C"{
#include<libavformat/avformat.h>
}
AVInfo::AVInfo(const QString& filename):
	pFmtCtx(nullptr),pOrgACtx(nullptr),pOrgVCtx(nullptr)
  ,pVidQueue(new AVPacketQueue),pAudQueue(new AVPacketQueue)
  ,vIdx(-1),aIdx(-1),pACtx(nullptr),pVCtx(nullptr)
  ,decoded_aud(QByteArray()),decoded_vid(QByteArray())
{
	av_register_all();
	if(!filename.isEmpty())
		openContext(filename);
}

AVInfo::~AVInfo()
{
	avcodec_close(pACtx);
	avcodec_close(pVCtx);
	avcodec_close(pOrgACtx);
	avcodec_close(pOrgACtx);
	avformat_close_input(&pFmtCtx);
}

size_t AVInfo::getVideoIdx() const
{
	return vIdx;
}

size_t AVInfo::getAudioIdx() const
{
	return aIdx;
}

AVPacketQueue *AVInfo::getVideoQueue() const
{
	return pVidQueue;
}

AVPacketQueue *AVInfo::getAudioQueue() const
{
	return pAudQueue;
}

AVFormatContext *AVInfo::getFormatContext() const
{
	return pFmtCtx;
}

AVCodecContext *AVInfo::getAudioContext() const
{
	return pACtx;
}

AVCodecContext *AVInfo::getVideoContext() const
{
	return pVCtx;
}

void AVInfo::openContext(const QString &filename)
{
	AVCodec *vCodec=nullptr,*aCodec=nullptr;
	if(avformat_open_input(&pFmtCtx,qPrintable(filename),nullptr,nullptr)){
		qDebug("AVinfo#open format error");
		return;
	}
	if(avformat_find_stream_info(pFmtCtx,nullptr)<0){
		qDebug("AVinfo#find stream error");
		return;
	}
	for(size_t i=0;i<pFmtCtx->nb_streams;++i){
		if(pFmtCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO){
			aIdx=i;
			pOrgACtx=pFmtCtx->streams[aIdx]->codec;
		}
		if(pFmtCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO){
			vIdx=i;
			pOrgVCtx=pFmtCtx->streams[vIdx]->codec;
			if(pOrgVCtx->codec_id==AV_CODEC_ID_H264){
				pOrgVCtx->thread_type=FF_THREAD_FRAME;
				pOrgVCtx->thread_count=QThread::idealThreadCount();
			}
		}
	}
	aCodec=avcodec_find_decoder(pOrgACtx->codec_id);
	if(!aCodec){
		qDebug("AVinfo#find aud_decoder error");
		return;
	}
	vCodec=avcodec_find_decoder(pOrgVCtx->codec_id);
	if(!vCodec){
		qDebug("AVinfo#find vid_decoder error");
		return;
	}
	pACtx = avcodec_alloc_context3(aCodec);
	if(avcodec_copy_context(pACtx, pOrgACtx) != 0) {
		qDebug("AVinfo#copy aud_ctx error");
		return;
	}
	pVCtx = avcodec_alloc_context3(vCodec);
	if(avcodec_copy_context(pVCtx, pOrgVCtx) != 0) {
		qDebug("AVinfo#copy vid_ctx error");
		return;
	}
	if(avcodec_open2(pACtx,aCodec,nullptr)<0){
		qDebug("AVinfo#aud_open error");
		return;
	}
	if(avcodec_open2(pVCtx,vCodec,nullptr)<0){
		qDebug("AVinfo#vid_open error");
		return;
	}
}
