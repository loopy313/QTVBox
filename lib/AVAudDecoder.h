#ifndef AVAUDDECODER_H
#define AVAUDDECODER_H
#include "lib_global.h"
#include<AVDecoder.h>

class LIBSHARED_EXPORT AVAudDecoder : public AVDecoder
{
public:
	AVAudDecoder(const AVInfo& info);
	virtual ~AVAudDecoder();
	virtual bool decode() override;
	virtual void dowork() override;
};

#endif // AVAUDDECODER_H
