#include "PhysicsWorld.h"

void PhysicsWorld::AddObject(Object* object)
{
	m_objects.push_back(object);
}

void PhysicsWorld::RemoveObject(Object* object)
{
	if (!object) return;
	auto itr = std::find(m_objects.begin(), m_objects.end(), object);
	if (itr == m_objects.end()) return;
	m_objects.erase(itr);
}

void PhysicsWorld::Step(double dtms)
{
	dtms /= 1000;
	Vec2d r;
	double distsqr;
	for (Object* obj : m_objects)
	{

		for (Object* _obj : m_objects)
		{
			if (obj == _obj) continue;

			r = _obj->Position - obj->Position;
			distsqr = lengthSquared(r);

			normalize(r);

			obj->Force += G * obj->mass * _obj->mass / distsqr * r;
		}
		//obj->Force += obj->mass * m_gravity - obj->Position;
		
		obj->Velocity += obj->Force / obj->mass * dtms;
		obj->Position += obj->Velocity * dtms;

		obj->Force = Vec2d(0, 0);
	}
}