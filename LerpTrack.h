#pragma once

#ifndef _LERP_TRACK_H_
#define _LERP_TRACK_H_

#include <glm\glm.hpp>

#include <vector>

class LerpTrack
{
// Attributes : --------------------------------------------------------------
protected:
    std::vector<glm::vec4>  mPoints;    // массив точек движения в формате (x, y, z, velocity)

    glm::vec4   mCurrPoint;             // текущая начальная точка
    glm::vec4   mNextPoint;             // текущая конечная точка

    glm::vec3   mDirection;             // единичный вектор направления движения
    glm::vec3   mPosition;              // текущая позиция (где-то между начальной и конечной)
    unsigned    mIndex;                 // текущий индекс конечной точки в массиве
    bool        mRepeat;                // флаг повтора траектории

// Methods :    --------------------------------------------------------------
public:
    // пустой конструктор
    LerpTrack ( );
    // конструктор задающий массив точек и флаг повтора
    LerpTrack ( std::vector<glm::vec4>& _points, bool _repeat = true );

    // задаёт массив точек для траектории
    void        setPoints ( std::vector<glm::vec4>& _points );
    // возвращает текущее положение
    glm::vec3   getPosition ( );
    // сброс траектории в самое начало
    void        reset ( );
    // установка флага повтора
    void        setRepeat ( bool _repeat );
    // метод обновления траектории
    void        update ( double _deltaTime );

};

#endif  /*_LERP_TRACK_H_*/
