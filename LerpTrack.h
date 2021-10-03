#pragma once

#ifndef _LERP_TRACK_H_
#define _LERP_TRACK_H_

#include <glm\glm.hpp>

#include <vector>

class LerpTrack
{
// Attributes : --------------------------------------------------------------
protected:
    std::vector<glm::vec4>  mPoints;    // array of traectory points ( x, y, z, velocity )

    glm::vec4   mCurrPoint;             // current start point
    glm::vec4   mNextPoint;             // next point to finish

    glm::vec3   mDirection;             // direction of movement
    glm::vec3   mPosition;              // current position ( between start and finish )
    unsigned    mIndex;                 // index of next point in array
    bool        mRepeat;                // repeat traectory flag

// Methods :    --------------------------------------------------------------
public:
    // default contructor
    LerpTrack ();
    // constructor with parameters
    // @param   _points
    //          array of traectory points
    // @param   _repeat
    //          cycle flag
    LerpTrack ( std::vector<glm::vec4>& _points, bool _repeat = true );

    // set up traectory points
    void        setPoints ( std::vector<glm::vec4>& _points );
    // returns current position
    glm::vec3   getPosition ();
    // returns next position
    glm::vec3   getNextPosition ();
    // rewind traectory to it's start
    void        reset ();
    // set up repeat flag
    void        setRepeat ( bool _repeat );
    // traectory updating
    // @param   _deltaTime
    //          time elapsed from last update
    void        update ( double _deltaTime );

};

#endif  /*_LERP_TRACK_H_*/
