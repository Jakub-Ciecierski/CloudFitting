//
// Created by jakub on 3/29/16.
//

#ifndef MG1_FITTING_WORKSHOP_H
#define MG1_FITTING_WORKSHOP_H


#include <gm/scene/scene.h>
#include <gm/rendering/render_bodies/cloud.h>
#include <gm/rendering/render_bodies/primitivies/sphere.h>

class FittingWorkshop {
private:
    Scene* scene;

    Sphere* sphere;
    std::vector<Cloud*> clouds;

    void createSphere();
    void createClouds();

public:

    FittingWorkshop(Scene* scene);

    ~FittingWorkshop();

    void startExperiment(unsigned int i);
};


#endif //MG1_FITTING_WORKSHOP_H
