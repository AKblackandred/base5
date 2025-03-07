#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "Maths.h"

namespace Maths
{

	class Quaternion
	{
	public:

		float		mX, mY, mZ, mW; 

		Quaternion() {
			mX = mY = mZ = 0.0f;
			mW = 1.0f;
		}

		Quaternion( float x, float y, float z, float w) :
			mX( x ),
			mY( y ),
			mZ( z ),
			mW( w ) 
		{}

		Quaternion(const Quaternion &orig) :
			mX(orig.mX),
			mY(orig.mY),
			mZ(orig.mZ),
			mW(orig.mW)
		{}

		// Note: this is const as it does not change the object it is called on
		bool operator==( const Quaternion& inRight ) const
		{
			if (FP_EQUAL(mX, inRight.mX))
				if (FP_EQUAL(mY, inRight.mY))
					if (FP_EQUAL(mZ, inRight.mZ))
						if (FP_EQUAL(mW, inRight.mW))
							return true;
						else
							return true;
					else
						return false;
				else
					return false;
			else
				return false;
		}

		static const Quaternion NoRotation;
	};

}

#endif
