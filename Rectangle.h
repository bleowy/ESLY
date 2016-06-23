#pragma once

#include "Shape.h"

class Rectangle : public Shape{
public:
	using Shape::Shape;
	virtual void render();
};