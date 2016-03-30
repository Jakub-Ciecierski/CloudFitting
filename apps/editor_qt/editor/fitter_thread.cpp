#include "fitter_thread.h"

#include <QMessageBox>

FitterThread::FitterThread(FittingWorkshop* fittingWorkshop) :
    fittingWorkshop(fittingWorkshop){
    experimentIndex = 0;
}


void FitterThread::run(){
    this->fittingWorkshop->startExperiment(experimentIndex);
}
