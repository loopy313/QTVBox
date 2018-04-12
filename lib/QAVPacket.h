#ifndef QAVPACKET_H
#define QAVPACKET_H
#include "lib_global.h"
#include<QByteArray>

class LIBSHARED_EXPORT QAVPacket
{
public:
	QAVPacket();
	QByteArray data;
	qreal pts,dts,duration;
	bool isreal;
};

#endif // QAVPACKET_H
