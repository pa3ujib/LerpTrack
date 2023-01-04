# LerpTrack
Linear interpolized traectory

simple C++ class to move along traectory which set up with array of four-elemented vectors - 
{ x, y, z, velocity }
 - x, y, z  : regular 3D coordinates
 - velocity : movement velocity on next line
 
# Usage :
  1. Create the class instance.
  2. Install the array of points. You may do it with two methods :
     - via constructor
     ```
     LerpTrack *camera_track = new LerpTrack ( points, false );
     ```
     - via separate methods
     ```
     camera_track->setPoints ( points );
     camera_track->setRepeat ( false );
     ```
  3. In main loop call update method
     ```
     camera_track->update ( elapsedTime );
     ```
  4. Any you may get current position
     ```
     camera_track->getPosition ();
     ```
   
# Dependencies:
     OpenGL Mathematics ( GLM )
