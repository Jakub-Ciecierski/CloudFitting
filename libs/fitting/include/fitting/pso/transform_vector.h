//
// Created by jakub on 3/29/16.
//

#ifndef MG1_TRANSFORM_VECTOR_H
#define MG1_TRANSFORM_VECTOR_H


#include <pso/pso_object.h>
#include <gm/rigid_body.h>

class TransformVector : public pso::PSOObject{
private:
public:
    float x;
    float y;
    float z;

    float xAngle;
    float yAngle;
    float zAngle;

    TransformVector();
    TransformVector(float x, float y, float z,
                    float xAngle, float yAngle, float zAngle);

    ~TransformVector();

    void transform(RigidBody* rigidBody);

};


#endif //MG1_TRANSFORM_VECTOR_H
