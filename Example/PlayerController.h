#pragma once

#include "Base.h"

class PlayerController
{

public:
	float speed = 500, turnSpeed = 1;


	float shotTimer = 0.0f;
	bool shotRequest = false;

	void poll(base::Transform *T, base::Rigidbody *rb, float dt)
	{
		//if (sfw::getKey('W'))
		//	rb->addForce(T->getGlobalUp() * speed);

		if (sfw::getKey('D'))
			//rb->addTorque(turnSpeed);
			rb->addForce(T->getGlobalLeft() * speed);


		if (sfw::getKey('A'))
			//rb->addTorque(-turnSpeed);
			rb->addForce(-T->getGlobalLeft() * speed);

		
		shotTimer -= dt;
		if (sfw::getKey(' ') && shotTimer < 0)
		{
			shotRequest = true;
			shotTimer = 0.5f; //0.86 origenal
		}
		else shotRequest = false;
	}

};