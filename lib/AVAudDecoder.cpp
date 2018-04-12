#include "AVAudDecoder.h"
#include<AVPacketQueue.h>
#include<QAVPacket.h>
#include<QDebug>
extern "C"{
#include<libavcodec/avcodec.h>
}

AVAudDecoder::AVAudDecoder(const AVInfo &info):AVDecoder(info)
{

}

AVAudDecoder::~AVAudDecoder()
{

}

bool AVAudDecoder::decode()
{
	AVPacket pkt;
	AVFrame* frame;
	QByteArray decoded;
	int got_frame_ptr=0;
	frame=av_frame_alloc();
	while(1)
	{
		QAVPacket encoded=pAudQueue->dequeue();
		if(!encoded.isreal)
			return true;
		av_new_packet(&pkt,encoded.data.size());
		memcpy(pkt.data,encoded.data.data(),encoded.data.size());
		int ret=avcodec_decode_audio4(pACtx,frame,&got_frame_ptr,&pkt);
		av_free_packet(&pkt);
		if (ret < 0) {
			qDebug()<<"AVAudDecoder#30";
			return false;
		}
		if (!got_frame_ptr) {
			return false;
		}
		const int samples_with_channels = frame->nb_samples * pACtx->channels;
		decoded.resize(samples_with_channels*sizeof(float));
		float *decoded_data=reinterpret_cast<float*>(decoded.data());
		switch(pACtx->sample_fmt){
		case AV_SAMPLE_FMT_FLTP:
		{
			memcpy(decoded_data,frame->data,decoded.size());
			av_frame_free(&frame);
			break;
		}
		default:
			decoded.clear();
			break;
		}
	}

	return true;
}

void AVAudDecoder::dowork()
{
	decode();
}

