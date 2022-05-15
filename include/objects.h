//
// Created by lorenz on 19.04.22.
//
#ifndef UNTITLED_OBJECTS_H
#define UNTITLED_OBJECTS_H
#include <string>

using namespace std;
class Object {
public:
    string m_name;
    int m_weight;
};

class Weapon : public Object {
public:
    int m_damage;
    string m_picture;
    Weapon(const string& name, const int& weight, const int& damage, const string& picture) {
        m_name = name;
        m_damage = damage;
        m_weight = weight;
        m_picture = picture;
    }
};
#endif //UNTITLED_OBJECTS_H
