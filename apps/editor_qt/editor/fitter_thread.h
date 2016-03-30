#ifndef FITTERTHREAD_H
#define FITTERTHREAD_H

#include <QtCore>
#include <fitting/fitting_workshop.h>


class FitterThread : public QThread
{
private:
    FittingWorkshop* fittingWorkshop;

public:
    int experimentIndex;

    FitterThread(FittingWorkshop* fittingWorkshop);

    void run();
};

#endif // FITTERTHREAD_H
