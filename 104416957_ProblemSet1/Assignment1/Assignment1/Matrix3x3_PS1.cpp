//COS30008 - 104416957 - Avery Flannery
//Problem 2 involves using additional matrix operations to extend the definition of class Matrix3x3

#include "Matrix3x3.h"

#include <cmath>
#include <cassert>
#include <sstream>
#include <iomanip>

using namespace std;

// Matrix Multiplication
Matrix3x3 Matrix3x3::operator*(const Matrix3x3& aOther) const noexcept {

	// Calculating each row of the Matrix
	Vector3D row1(row(0).dot(aOther.column(0)),
		row(0).dot(aOther.column(1)),
		row(0).dot(aOther.column(2)));

	Vector3D row2((row(1).dot(aOther.column(0))),
		(row(1).dot(aOther.column(1))),
		(row(1).dot(aOther.column(2))));

	Vector3D row3(row(2).dot(aOther.column(0)),
		row(2).dot(aOther.column(1)),
		row(2).dot(aOther.column(2)));

	return Matrix3x3(row1, row2, row3);
}

// Matrix Determinate
float Matrix3x3::det() const noexcept {

	return row(0)[0] * (row(1)[1] * row(2)[2] - row(1)[2] * row(2)[1])
		- row(0)[1] * (row(1)[0] * row(2)[2] - row(1)[2] * row(2)[0])
		+ row(0)[2] * (row(1)[0] * row(2)[1] - row(1)[1] * row(2)[0]);
}

// Matrix Transpose
Matrix3x3 Matrix3x3::transpose() const noexcept
{
	return Matrix3x3(column(0), column(1), column(2));
}

// Matrix Invertible 
bool Matrix3x3::hasInverse() const noexcept
{
	if (det() != 0)
	{
		return true; // if determinate !=0 the Matrix is invertible
	}
	else
	{
		return false; // if determinate ==0 the Matrix isn't invertible
	};

}

// Matrix Inverse
Matrix3x3 Matrix3x3::inverse() const noexcept {

	assert(det() != 0);

	Vector3D row1(
		row(1)[1] * row(2)[2] - row(1)[2] * row(2)[1],
		row(0)[2] * row(2)[1] - row(0)[1] * row(2)[2],
		row(0)[1] * row(1)[2] - row(0)[2] * row(1)[1]
	);

	Vector3D row2(
		row(1)[2] * row(2)[0] - row(1)[0] * row(2)[2],
		row(0)[0] * row(2)[2] - row(0)[2] * row(2)[0],
		row(0)[2] * row(1)[0] - row(0)[0] * row(1)[2]
	);

	Vector3D row3(
		row(1)[0] * row(2)[1] - row(1)[1] * row(2)[0],
		row(0)[1] * row(2)[0] - row(0)[0] * row(2)[1],
		row(0)[0] * row(1)[1] - row(0)[1] * row(1)[0]
	);


	return Matrix3x3(row1, row2, row3) * (1 / (det()));
}

// Output
ostream& operator<<(ostream& aOStream, const Matrix3x3& aMatrix) {
	return aOStream << "[" << aMatrix.row(0).toString() << "," 
		<< aMatrix.row(1).toString() << "," 
		<< aMatrix.row(2).toString() << "]";
}
