#ifndef QLIFT_C_API_QLIFT_QLINEEDIT_H
#define QLIFT_C_API_QLIFT_QLINEEDIT_H

#ifdef __cplusplus
extern "C" {
#endif

void* QLineEdit_new(const char *contents, void *parent);
void QLineEdit_delete(void *lineEdit);
void QLineEdit_setPlaceholderText(void *lineEdit, const char *text);
void QLineEdit_textChanged_connect(void *lineEdit, void *receiver, void *context, void (*slot_ptr)(void*));

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <wobjectdefs.h>
class QliftLineEdit: public QLineEdit {
    W_OBJECT(QliftLineEdit)

    public:
        using QLineEdit::QLineEdit;
        virtual ~QliftLineEdit();
        void (*mousePressEvent_Functor)(void*, void*) = nullptr;
        void *context = nullptr;
};
#endif

#endif //QLIFT_C_API_QLIFT_QLINEEDIT_H

