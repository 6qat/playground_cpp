//
// Created by cesch on 1/18/2022.
//

#ifndef LAB_H
#define LAB_H

#include <QObject>
#include <QQmlApplicationEngine>

class Lab: public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    Lab();

    static auto sum(int a, int b) -> int {
        return a + b;
    }


};


#endif //LAB_H
