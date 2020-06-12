#ifndef RANDOM_KEYBOARD_H
#define RANDOM_KEYBOARD_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif
#include <QEvent>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include "ui_random_keyboard.h"

#define RANDOMKEYBOARD_KEYBOARD_DIGIT_COUNT (5)
#define MAXIMUM_PASSWORD_LENGTH (20)

class random_keyboard : public QWidget, public Ui::random_keyboard
{
	Q_OBJECT
public:
	explicit random_keyboard(QWidget *parent = nullptr);
	~random_keyboard();
	void keyboard_init(uint8_t *pucBuffer, uint8_t size, uint8_t *keysPressed, uint8_t * pwdSize);

private:
	uint8_t	* mPassword;
	uint8_t	* mPasswdLength;

protected:
	void changeEvent(QEvent *e);

protected:
signals:
	void signalHide();

protected
slots:

	void on_pb1_clicked();
	void on_pb2_clicked();
	void on_pb3_clicked();
	void on_pb4_clicked();
	void on_pb5_clicked();
	void on_pbView_toggled(bool state);
	void on_pbEnter_clicked();

};

#endif // RANDOM_KEYBOARD_H

