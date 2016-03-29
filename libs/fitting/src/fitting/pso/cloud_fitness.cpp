//
// Created by jakub on 3/29/16.
//

#include <pso/particle_decoder.h>
#include <pso/entities/particle.h>
#include <fitting/pso/cloud_fitness.h>
#include <fitting/pso/transform_vector.h>
#include <gm/util/utils.h>

using namespace pso;
using namespace std;
using namespace glm;

//-----------------------//
//  CONSTRUCTORS
//-----------------------//

CloudFitness::CloudFitness(ParticleShPtr_ConstVectorShPtr particles,
                           const ParticleDecoder * particleDecoder,
                           Cloud* cloud, RigidBody* rigidBody) :
    FitnessUpdater(particles, particleDecoder),
    cloud(cloud), rigidBody(rigidBody){
    distancesWeight = 1;
    normalAnglesWeight = 1;
}

CloudFitness::~CloudFitness() {

}

//-----------------------//
//  PRIVATE
//-----------------------//

double CloudFitness::computeGoalFunction(Cloud* cloud, RigidBody* rigidBody){
    float sumOfDistances = 0;
    float sumOfNormals = 0;

    const vector<vec4>& worldVertices = cloud->getWorldVertices();
    for(auto worldVertex : worldVertices){
        vec3 vertex(worldVertex.x, worldVertex.y, worldVertex.z);
        vec3 clostestPoint = rigidBody->getClosestPoint(vertex);
/*
        std::cout << "Vertex: " << std::endl;
        printvec3(vertex);
        std::cout << "Closest Point: " << std::endl;
        printvec3(clostestPoint);
*/
        double distance = gm::euclideanDistance(clostestPoint, vertex);
        sumOfDistances += distance;

        //std::cout << "Distance: " << distance << std::endl << std::endl;

    }

    // TODO compute sumOfNormals

    double goalValue = (distancesWeight * sumOfDistances) +
            (normalAnglesWeight * sumOfNormals);
/*
    double fitness;
    double epsilon = 0.0001;
    if(goalValue < 1) {
        goalValue = 1;
    }

    fitness = 1.0f / goalValue;
*/
    //std::cout << "GoalValue:    " << goalValue << std::endl;
    //std::cout << "FitnessValue: " << fitness << std::endl << std::endl;

    return goalValue;
}

//-----------------------//
//  PROTECTED
//-----------------------//

double CloudFitness::fitnessValue(const pso::Particle &p) {
    TransformVector* tv =
            (TransformVector*)this->particleDecoder->decodeCurrent(p);

    Cloud tmpCloud = *(this->cloud);

    tmpCloud.moveTo(tv->x, tv->y, tv->z);
    tmpCloud.rotateTo(tv->xAngle, tv->yAngle, tv->zAngle);
    tmpCloud.update();

    double fitness = computeGoalFunction(&tmpCloud, rigidBody);

    delete tv;
    return fitness;
}