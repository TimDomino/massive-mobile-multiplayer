#include "PhysicalObject.hpp"

PhysicalObject::PhysicalObject(float mass, int posX, int posY, float radius) : 
	mass_(mass), posX_(posX), posY_(posY), velX_(0.0), velY_(0.0), radius_(radius) {}

/* virtual */ PhysicalObject::~PhysicalObject() {}

/* virtual */ void PhysicalObject::render(sf::RenderWindow* window) const 
{
	window->draw(shape_);
}

/* virtual */ void PhysicalObject::frameFrictionUpdate()
{
	double frictionDecrement(0.25);

	double currentSpeed = computeCurrentSpeed();

	if (currentSpeed > 0.0)
	{
		double targetSpeed;
		if (currentSpeed - frictionDecrement > 0.0)
			targetSpeed = currentSpeed-frictionDecrement;
		else
			targetSpeed = 0.0;

		velX_ = velX_ / currentSpeed;
		velY_ = velY_ / currentSpeed;
		velX_ *= targetSpeed;
		velY_ *= targetSpeed;
	}

	clampPosition();
}

/* virtual */ void PhysicalObject::frameUpdate()
{
	frameFrictionUpdate();
	setPosition(posX_ + velX_, posY_ + velY_);
}

/* virtual */ void PhysicalObject::setPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
	shape_.setPosition(posX_, posY_);
}

sf::CircleShape const PhysicalObject::getShape() const
{
	return shape_;
}

int PhysicalObject::getPosX() const
{
	return posX_;
}

int PhysicalObject::getPosY() const
{
	return posY_;
}

double PhysicalObject::getVelX() const
{
	return velX_;
}

double PhysicalObject::getVelY() const
{
	return velY_;
}

float PhysicalObject::getMass() const
{
	return mass_;
}

float PhysicalObject::getRadius() const
{
	return radius_;
}

void PhysicalObject::setVelocity(double x, double y)
{
	velX_ = x;
	velY_ = y;
}

void PhysicalObject::addVelocityOffset(double x, double y)
{
	velX_ += x;
	velY_ += y;

	double newSpeed = computeCurrentSpeed();

	if (newSpeed > MAX_SPEED)
	{
		velX_ = velX_ / newSpeed;
		velY_ = velY_ / newSpeed;
		velX_ *= MAX_SPEED;
		velY_ *= MAX_SPEED;
	}

}

double PhysicalObject::computeCurrentSpeed() const
{
	return std::sqrt(velX_*velX_ + velY_*velY_);
}