#include "mylabclass.h"
#include <QDebug>
#include <QProperty>

struct Test {

    QProperty<int> width {100};
    QProperty<int> height {50};
    QProperty<int> area{};

     int calc() const  {
        return width * height;
    }

    void test() {



        auto const func = [&]() {return width * height;};

        area.setBinding( &Test::calc);
        Q_ASSERT(area == 5000);
        qDebug() << area;

        width = 20;
        Q_ASSERT(area == 100);
        qDebug() << area;
    }

};

int main() {

    return 0;
}
