import QtQuick

Item {
    Component.onCompleted: {
        console.log("onCompleted called on OTHER component in LAB module.");
        backend.cppSlot();
    }
}