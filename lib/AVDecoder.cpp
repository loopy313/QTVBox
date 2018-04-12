#include "AVDecoder.h"
#include<AVInfo.h>

AVDecoder::AVDecoder(const AVInfo &info):info(info),pAudQueue(nullptr),pVidQueue(nullptr)
  ,pACtx(nullptr),pVCtx(nullptr)
{
	init();
}

void AVDecoder::init()
{
	pACtx=info.getAudioContext();
	pVCtx=info.getVideoContext();
	pAudQueue=info.getAudioQueue();
	pVidQueue=info.getVideoQueue();
}

AVDecoder::~AVDecoder()
{

}
