#ifndef RANDOM_KEYBOARD_DISPLAY_H
#define RANDOM_KEYBOARD_DISPLAY_H

#include "ui_random_keyboard_display.h"
#include "random_keyboard.h"

class random_keyboard_display : public QWidget, private Ui::random_keyboard_display
{
	Q_OBJECT

public:
	explicit random_keyboard_display(QWidget *parent = nullptr);
	~random_keyboard_display();

	void setPortrait(void);
	void setLandscape(void);

	void keyboard_init(uint8_t *pucBuffer, uint8_t size, uint8_t *keysPressed, uint8_t * pwdSize);

protected:
	bool event(QEvent *evento);
	void mudouTamanho(void);

protected
slots:
	void slotHide();

private:
	QGraphicsScene			* gs;
	QGraphicsProxyWidget	* mProxyWidget;
	random_keyboard			* qwKeyboard;
protected:
	void changeEvent(QEvent *e);
};

#endif // RANDOM_KEYBOARD_DISPLAY_H
