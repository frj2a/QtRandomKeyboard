#ifndef QTRANDOMKEYBOARD_H
#define QTRANDOMKEYBOARD_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif
#include "ui_QtRandomKeyboard.h"
#include "random_keyboard_display.h"

class QtRandomKeyboard : public QWidget, public Ui::QtRandomKeyboard {
	Q_OBJECT

public:
	explicit QtRandomKeyboard(QWidget *parent = nullptr);
	~QtRandomKeyboard();

private:
	random_keyboard_display	* mKeyboard;
	constexpr static const uint8_t	PrimesWithZero[RANDOMKEYBOARD_KEYBOARD_DIGIT_COUNT]		= {0, 2, 3, 5, 7};
	constexpr static const uint8_t	NonPrimesWithOne[RANDOMKEYBOARD_KEYBOARD_DIGIT_COUNT]	= {1, 4, 6, 8, 9};
	uint8_t	mKeysPressed[MAXIMUM_PASSWORD_LENGTH];
	uint8_t mKeysPressedSize;

	uint8_t	mKBDsize;

protected
slots:
	void on_pbLandscape_clicked();
	void on_pbPortrait_clicked();
};
#endif // QTRANDOMKEYBOARD_H
