#ifndef AVVIDDECODER_H
#define AVVIDDECODER_H
#include "lib_global.h"
#include<AVDecoder.h>
#include<AVInfo.h>
class LIBSHARED_EXPORT AVVidDecoder : public AVDecoder
{
public:
	AVVidDecoder(const AVInfo& info);
};

#endif // AVVIDDECODER_H
