#ifndef AVPLAY_H
#define AVPLAY_H

#include "lib_global.h"
#include <QObject>

class LIBSHARED_EXPORT AVPlay : public QObject
{
	Q_OBJECT
public:
	explicit AVPlay(QObject *parent = nullptr);

signals:

public slots:
};

#endif // AVPLAY_H
