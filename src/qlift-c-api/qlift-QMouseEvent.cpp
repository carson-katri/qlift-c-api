#include <QMouseEvent>

#define QLIFT_C_API_INTERNAL
#include "qlift-QMouseEvent.h"


void QMouseEvent_delete(void *mouseEvent) {
    delete static_cast<QMouseEvent*>(mouseEvent);
}

int QMouseEvent_button(void *mouseEvent) {
    return static_cast<QMouseEvent*>(mouseEvent)->button();
}

