/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Vector2.inl
*/

//TODO: PAS this!!!

inline Vector2 Raylib::Vector2::operator=(const Vector2 &copy)//TODO: change name copyVector (hpp too et vector 3D et 4D)
{
    this->x = copy.x;
    this->y = copy.y;
    _vector.x = this->x;
    _vector.y = this->y;
    return Vector2(copy);
}

inline Vector2 Raylib::Vector2::operator=(const ::Vector2 &cvec)//TODO: change name copyVector(hpp too et vector 3D et 4D)
{
    this->x = cvec.x;
    this->y = cvec.y;
    _vector.x = this->x;
    _vector.y = this->y;
    return Vector2(cvec);
}

inline ::Vector2 Raylib::Vector2::getCStruct()
{
    _vector.x = this->x;
    _vector.y = this->y;
    return _vector;
}