#ifndef _PARTICULE_H
#define _PARTICULE_H

#include <cstdlib>
#include <cmath>
#include "Vector4D.h"

static const float rebond=0.8;

class Particule {
 public:
  virtual ~Particule(){}
  virtual void move() =0;
  virtual Vector4D& getPosition() =0;
  virtual Vector4D getPosition() const =0;
};

class SpeedParticule:public Particule {
 public:
  SpeedParticule(const Vector4D& position = Vector4D(5, 20, 5, 1),
		 const Vector4D& speed = Vector4D(0.1, -0.2, 0.1, 0))
    :speed(speed),
    position(position),
    startSpeed(speed),
    startPosition(position)
    {}

  void move() {
    position+=speed;
    if (position[1]<0) {
      position[1]=0;
      speed[1]*=-rebond;
    }

    if (position[0]>10 || position[0]<-10 ||
	position[2]>10 || position[2]<-10 ) {
	speed = startSpeed;
	float alpha = 2.*M_PI*(float(rand())/float(RAND_MAX));
	speed = Vector4D ( 0.01 * cos(alpha), 0.1 ,
			   0.01 * sin(alpha), 0.);
	position = startPosition;
      }
  }
  virtual Vector4D& getPosition() {
    return position;
  }
  virtual Vector4D getPosition() const {
    return position;
  }
 protected:
  Vector4D speed,position;
  Vector4D startSpeed,startPosition;
};

class AccelerateParticule:public SpeedParticule {
 public:
  AccelerateParticule(const Vector4D& position = Vector4D(0, 10, 0, 1),
		      const Vector4D& speed = Vector4D(0.1, 0.2, 0.1, 0),
		      const Vector4D& acceleration = Vector4D(0, -0.000495, 0, 0))
    : SpeedParticule(position,speed), acceleration(acceleration)
    {}
  void move() {
    SpeedParticule::move();
    speed+=acceleration;
  }
 protected:
  Vector4D acceleration;
};

#endif
