#include <QLineEdit>
#include <wobjectimpl.h>

#include "qlift-QLineEdit.h"

/*
void* QLineEdit_new(const char *contents, void *parent);
void QLineEdit_delete(void *lineEdit);
void QLineEdit_setPlaceholderText(void *lineEdit, const char *text);
void QLineEdit_textEditedEvent_Override(void *lineEdit, void *context, void (*mousePressEvent_Functor)(void*, void*));
*/

void* QLineEdit_new(const char *contents, void *parent) {
    return static_cast<void*>(new QliftLineEdit { contents, static_cast<QWidget*>(parent) });
}

void QLineEdit_delete(void *lineEdit) {
    delete static_cast<QliftLineEdit*>(lineEdit);
}

void QLineEdit_setText(void *lineEdit, const char *text) {
    static_cast<QLineEdit*>(lineEdit)->setText(text);
}

void QLineEdit_textChanged_connect(void *lineEdit, void *receiver, void *context, void (*slot_ptr)(void*)) {
    QObject::connect(
        static_cast<QLineEdit*>(lineEdit),
        &QLineEdit::textChanged,
        static_cast<QObject*>(receiver),
        [context, slot_ptr]() {
            (*slot_ptr)(context);
        }
    );
}

W_OBJECT_IMPL(QliftLineEdit)

QliftLineEdit::~QliftLineEdit() {
}

