#pragma once

#ifndef _LERP_TRACK_H_
#define _LERP_TRACK_H_

#include <glm\glm.hpp>

#include <vector>

class LerpTrack
{
// Attributes : --------------------------------------------------------------
protected:
    std::vector<glm::vec4>  mPoints;    // ������ ����� �������� � ������� (x, y, z, velocity)

    glm::vec4   mCurrPoint;             // ������� ��������� �����
    glm::vec4   mNextPoint;             // ������� �������� �����

    glm::vec3   mDirection;             // ��������� ������ ����������� ��������
    glm::vec3   mPosition;              // ������� ������� (���-�� ����� ��������� � ��������)
    unsigned    mIndex;                 // ������� ������ �������� ����� � �������
    bool        mRepeat;                // ���� ������� ����������

// Methods :    --------------------------------------------------------------
public:
    // ������ �����������
    LerpTrack ( );
    // ����������� �������� ������ ����� � ���� �������
    LerpTrack ( std::vector<glm::vec4>& _points, bool _repeat = true );

    // ����� ������ ����� ��� ����������
    void        setPoints ( std::vector<glm::vec4>& _points );
    // ���������� ������� ���������
    glm::vec3   getPosition ( );
    // ����� ���������� � ����� ������
    void        reset ( );
    // ��������� ����� �������
    void        setRepeat ( bool _repeat );
    // ����� ���������� ����������
    void        update ( double _deltaTime );

};

#endif  /*_LERP_TRACK_H_*/
