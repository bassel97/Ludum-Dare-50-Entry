#ifndef LDGAME_ECS_PHYSICSSYSTEM_H_
#define LDGAME_ECS_PHYSICSSYSTEM_H_

#include <world.h>
#include <components/physics/box-collider-2d.h>
#include <components/physics/rigid-body-2d.h>

class PhysicsSystem
{
public:
    static void ApplyBoxAABB(World *world, float delta_time)
    {
        std::vector<Entity *> boxes = world->get_entities_with_component<BoxCollider2D>();

        for (Entity *box : boxes)
        {
            BoxCollider2D *box_collider = box->get_component<BoxCollider2D>();

            if (box_collider->static_)
                continue;

            for (Entity *box_to_collide : boxes)
            {
                if (box == box_to_collide)
                    continue;

                box->get_transform()->position_.x += box_collider->speed_.x * delta_time;
                if (box->get_transform()->position_.x < box_to_collide->get_transform()->position_.x + box_to_collide->get_transform()->scale_.x * 2.0f &&
                    box->get_transform()->position_.x + box->get_transform()->scale_.x * 2.0f > box_to_collide->get_transform()->position_.x &&
                    box->get_transform()->position_.y < box_to_collide->get_transform()->position_.y + box_to_collide->get_transform()->scale_.y * 2.0f &&
                    box->get_transform()->position_.y + box->get_transform()->scale_.y * 2.0f > box_to_collide->get_transform()->position_.y)
                {
                    box->get_transform()->position_.x -= box_collider->speed_.x * delta_time;
                }

                box->get_transform()->position_.y += box_collider->speed_.y * delta_time;
                if (box->get_transform()->position_.x < box_to_collide->get_transform()->position_.x + box_to_collide->get_transform()->scale_.x * 2.0f &&
                    box->get_transform()->position_.x + box->get_transform()->scale_.x * 2.0f > box_to_collide->get_transform()->position_.x &&
                    box->get_transform()->position_.y < box_to_collide->get_transform()->position_.y + box_to_collide->get_transform()->scale_.y * 2.0f &&
                    box->get_transform()->position_.y + box->get_transform()->scale_.y * 2.0f > box_to_collide->get_transform()->position_.y)
                {
                    box->get_transform()->position_.y -= box_collider->speed_.y * delta_time;
                }
            }
        }
    }
};

#endif // LDGAME_ECS_PHYSICSSYSTEM_H_