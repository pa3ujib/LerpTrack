#include "LerpTrack.h"

#include <iostream>

// ---------------------------------------------------------------------------
//  public
// ---------------------------------------------------------------------------

LerpTrack::LerpTrack ( )
    : mIndex ( 0 )
    , mRepeat ( false )
{
    mPoints = std::vector<glm::vec4> ( );
    mPosition = glm::vec3 ( 0.0f );
    mDirection = glm::vec3 ( 0.0f );
    mCurrPoint = mNextPoint = glm::vec4 ( 0.0f );
}

LerpTrack::LerpTrack ( std::vector<glm::vec4>& _points, bool _repeat )
    : mRepeat ( _repeat )
{
    mPoints    = _points;
    reset ( );
}

void LerpTrack::setPoints ( std::vector<glm::vec4>& _points )
{
    mPoints = _points;
    reset ( );
}

glm::vec3 LerpTrack::getPosition ( )
{
    return mPosition;
}

void LerpTrack::reset ( )
{
    mIndex = 0;
    mCurrPoint = mPoints[mIndex++];
    mNextPoint = mPoints[mIndex];
    mDirection = glm::normalize ( mNextPoint - mCurrPoint );
    mPosition  = mCurrPoint;
}

void LerpTrack::setRepeat ( bool _repeat )
{
    mRepeat = _repeat;
}

void LerpTrack::update ( double _deltaTime )
{
    // calculate next shift vector
    glm::vec3 delta = ( float ) _deltaTime * mCurrPoint.w * mDirection;
    // get the delta position change
    glm::vec3 deltaPosition = mPosition + delta;
    // save machine cycles if no moving
    if ( mPosition == deltaPosition ) return;

    // find initial distance
    float distance1 = glm::distance ( glm::vec3 ( mNextPoint ), glm::vec3 ( mCurrPoint ) );
    // find distance from new position
    float distance2 = glm::distance ( glm::vec3 ( mCurrPoint ), deltaPosition );
        
    if ( distance1 > distance2 )
        // whether initial is bigger
        mPosition += delta;
    else
        // or not
    {
        // next point will be current
        mCurrPoint = mNextPoint;
        // translate position
        mPosition  = mCurrPoint;

        // get next point via index
        if ( mPoints.size ( ) > ( mIndex + 1 ) )
            mIndex += 1;
        else
            if ( mRepeat ) mIndex = 0;
        mNextPoint = mPoints[mIndex];
        
        // calculate new direction
        mDirection = glm::normalize ( mNextPoint - mCurrPoint );
    }
}
