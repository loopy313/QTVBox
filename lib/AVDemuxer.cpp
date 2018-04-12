#include "AVDemuxer.h"
#include<AVInfo.h>
#include<QAVPacket.h>
#include<AVPacketQueue.h>
extern "C"{
#include<libavformat/avformat.h>
#include<libavcodec/avcodec.h>
}

AVDemuxer::AVDemuxer(const AVInfo &_info):info(_info),
	pFmtCtx(nullptr),vIdx(-1),aIdx(-1),audQueue(nullptr),vidQueue(nullptr)
{
	init();
}

AVDemuxer::~AVDemuxer()
{

}

void AVDemuxer::init()
{
	pFmtCtx=info.getFormatContext();
	vIdx=info.getVideoIdx();
	aIdx=info.getAudioIdx();
	audQueue=info.getAudioQueue();
	vidQueue=info.getVideoQueue();
}

void AVDemuxer::readPacket()
{
	QAVPacket packet;
	AVPacket pkt;
	init();
	while(1){
		size_t ret=av_read_frame(pFmtCtx,&pkt);
		if(ret==AVERROR(EOF))
			break;
		packet.data=QByteArray(reinterpret_cast<const char*>(pkt.data),pkt.size);
		packet.dts=pkt.dts;
		packet.pts=pkt.pts;
		packet.duration=pkt.duration;
		packet.isreal=true;
		if(pkt.stream_index==aIdx)
			audQueue->enqueue(packet);
		else if(pkt.stream_index==vIdx)
			vidQueue->enqueue(packet);
	}
}

void AVDemuxer::dowork()
{
	readPacket();
}
