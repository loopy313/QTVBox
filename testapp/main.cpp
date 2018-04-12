#include "widget.h"
#include <QApplication>
#include<AVInfo.h>
#include<AVDemuxer.h>
#include<AVAudDecoder.h>
#include<QAVThread.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Widget w;
	w.show();
	AVInfo info(QStringLiteral("d:/pcm32.wav"));
	AVDemuxer demuxer(info);
	AVAudDecoder aud_decoder(info);
	QAVThread t_demux(&demuxer);
	QAVThread t_deAud(&aud_decoder);
	return a.exec();
}
