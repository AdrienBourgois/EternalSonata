#ifndef __ENTITY_H__
#define __ENTITY_H__

class Entity: public CSceneNode 
{
    int life;

    public:
        Entity();
        ~Entity() = default;

        virtual void update() = 0;

        virtual int getLife() 
        { return this->life; }

        virtual void setLife(int life)
        { this->life = life; }
};

#endif // __ENTITY_H__
