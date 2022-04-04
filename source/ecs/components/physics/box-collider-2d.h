#ifndef LDGAME_PHYSICS_BOXCOLLIDER2D_H_
#define LDGAME_PHYSICS_BOXCOLLIDER2D_H_

#include <glm.hpp>

#include <component.h>

class BoxCollider2D : public Component
{
public:
    bool static_ = false;
    glm::vec3 speed_ = glm::vec3(0.0f);
    std::string tag = "";
};

#endif // LDGAME_PHYSICS_BOXCOLLIDER2D_H_