//
// Created by jakub on 3/29/16.
//

#include <fitting/fitting_workshop.h>
#include <fitting/cloud_fitter.h>

//-----------------------//
//  CONSTRUCTORS
//-----------------------//

FittingWorkshop::FittingWorkshop(Scene* scene){
    this->scene = scene;

    createSphere();
    createClouds();
}

FittingWorkshop::~FittingWorkshop(){

}

//-----------------------//
//  PRIVATE
//-----------------------//

void FittingWorkshop::createSphere(){
    sphere = new Sphere(0.5, 50, 50);
    scene->addRenderObject(sphere);
}


void FittingWorkshop::createClouds(){
    Cloud* cloud1 = sphere->extractRandomCloud(100, 1, 1);
    Cloud* cloud2 = sphere->extractRandomCloud(100, 2, 1);
    Cloud* cloud3 = sphere->extractRandomCloud(100, 1, 2);
    Cloud* cloud4 = sphere->extractRandomCloud(100, 2, 2);

    cloud1->move(1.5, 0.0, 1.5);
    cloud2->move(1.5, 0.0, -1.5);
    cloud3->move(-1.5, 0.0, -1.5);
    cloud4->move(-1.5, 0.0, 1.5);

    scene->addRenderObject(cloud1);
    scene->addRenderObject(cloud2);
    scene->addRenderObject(cloud3);
    scene->addRenderObject(cloud4);

    clouds.push_back(cloud1);
    clouds.push_back(cloud2);
    clouds.push_back(cloud3);
    clouds.push_back(cloud4);
}

//-----------------------//
//  PUBLIC 
//-----------------------//

void FittingWorkshop::startExperiment(){
    CloudFitter cloudFitter(clouds[0], sphere);
    cloudFitter.startFitting();
}