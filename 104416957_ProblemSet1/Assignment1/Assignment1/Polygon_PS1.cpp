//COS30008 - 104416957 - Avery Flannery
//Problem 3 involves the Trapezoid Formula to calculate the area based on clockwise and counter-clockwise order
//Tested with Parallelogram.txt and Data.txt

#include "Polygon.h"

using namespace std;

// Calculating the area
float Polygon::getSignedArea() const noexcept
{
	float Result = 0.0;

	for (size_t i = 0; i < fNumberOfVertices; i++)
	{
		int j = (i + 1) % fNumberOfVertices;
		Result += (fVertices[i].x() * fVertices[j].y()) - (fVertices[j].x() * fVertices[i].y());
	}
	return (Result / 2.0); // returns the signed area
}

// Transforming the polygon using the transformation Matrix
Polygon Polygon::transform(const Matrix3x3& aMatrix) const noexcept
{
	Polygon Result = *this;
	for (size_t i = 0; i < fNumberOfVertices; i++)
	{
		Vector3D fVertice3D = Vector3D(Result.fVertices[i]);
		Vector3D Result3D = aMatrix * (fVertice3D);
		Result.fVertices[i] = Result3D.operator Vector2D();
	}
	return Result; // returns the signed area of the rotated polygon
}