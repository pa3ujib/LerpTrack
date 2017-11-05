#include "LerpTrack.h"

#include <iostream>

// ---------------------------------------------------------------------------
//  public
// ---------------------------------------------------------------------------

LerpTrack::LerpTrack ( )
    : mRepeat ( false )
{
    mPoints = std::vector<glm::vec4> ( );
    reset ( );
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
    if ( mPoints.size ( ) > 0 )
    {
        mCurrPoint = mPoints[mIndex];
        if ( mPoints.size ( ) > 1 )
            mNextPoint = mPoints[++mIndex];
        else
            mNextPoint = mCurrPoint;
    }
    else
    {
        mCurrPoint = glm::vec4 ( 0.0f );
        mNextPoint = glm::vec4 ( 0.0f );
    }
    mDirection = glm::normalize ( mNextPoint - mCurrPoint );
    mPosition = mCurrPoint;
}

void LerpTrack::setRepeat ( bool _repeat )
{
    mRepeat = _repeat;
}

void LerpTrack::update ( double _deltaTime )
{
    // get next delta position
    glm::vec3 deltaPosition = mPosition + ( float ) _deltaTime * mCurrPoint.w * mDirection;
    // nothing to do with no movement
    if ( mPosition == deltaPosition ) return;

    // find initial distance
    float distance1 = glm::distance ( glm::vec3 ( mNextPoint ), glm::vec3 ( mCurrPoint ) );
    // find distance from new position
    float distance2 = glm::distance ( glm::vec3 ( mCurrPoint ), deltaPosition );
        
    if ( distance1 > distance2 )
        // whether initial is bigger
        mPosition = deltaPosition;
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
