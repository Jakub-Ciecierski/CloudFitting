//
// Created by jakub on 2/28/16.
//

#ifndef MG1_RENDERABLE_H
#define MG1_RENDERABLE_H

#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <gm/edge.h>
#include <gm/color/color.h>
#include <gm/rigid_body.h>
#include <gm/rendering/ray_cast.h>

class RayCast;

/*
 * Renderable Interface.
 */
class RenderBody : public RigidBody {
private:
    Color color;

    //-----------------------------------------------------------//
    //  PRIVATE METHODS
    //-----------------------------------------------------------//

protected:
    GLenum drawingMode;

    bool grabable;
    float lineWidth;

    std::vector<glm::vec4> vertices;
    std::vector<Edge> edges;

    std::vector<glm::vec4> NDCVertices;
    glm::vec3 NDCPosition;

    //-----------------------------------------------------------//
    //  PROTECTED METHODS
    //-----------------------------------------------------------//

    void transformPosition(const glm::mat4 &VP);
    virtual void transform(const glm::mat4 &VP);

    void setSurfaceColor(const Color& color);

    const std::vector<glm::vec4>& getVertices();
    const std::vector<Edge>& getEdges();

    virtual void initVertices() = 0;
    virtual void initEdges() = 0;

    /*
     * Draws lines after transformation of vertices.
     * Drawing is based on the Edges created in the initialization process
     */
    virtual void drawLines(const std::vector<glm::vec4>& vertices,
                           bool costumColor);

    char ComputeOutcode(glm::vec4 p, int left, int right, int top, int bottom);

    bool CohenSutherland(glm::vec4& p1, glm::vec4& p2,
                         int left, int right,
                         int top, int bottom);
public:
    //-----------------------------------------------------------//
    //  CONSTRUCTORS
    //-----------------------------------------------------------//

    RenderBody();

    virtual ~RenderBody();

    //-----------------------------------------------------------//
    //  PUBLIC METHODS
    //-----------------------------------------------------------//

    void setDrawingMode(GLenum mode);

    bool isGrabable();

    void setColor(Color color);
    const Color* getColor();

    const glm::vec3& getProjectedPosition();

    virtual float intersect(const RayCast& ray) = 0;

    virtual glm::vec3 getClosestPoint(const glm::vec3 point) = 0;

    virtual void render(const glm::mat4& VP);
    virtual void render(const glm::mat4& VP, const Color& color);
};


#endif //MG1_RENDERABLE_H