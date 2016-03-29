#include "fitter_thread.h"
#include "editor_window.h"

FitterThread::FitterThread(FittingWorkshop* fittingWorkshop) :
    fittingWorkshop(fittingWorkshop){
    experimentIndex = 0;
}


void FitterThread::run(){
    this->fittingWorkshop->startExperiment(experimentIndex);
}
