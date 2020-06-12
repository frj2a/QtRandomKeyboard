#include "QtRandomKeyboard.h"
#include "random_keyboard_display.h"

QtRandomKeyboard::QtRandomKeyboard(QWidget *parent) : QWidget(parent) {
	setupUi(this);
	mKeyboard = new random_keyboard_display(this);
	show();
}

QtRandomKeyboard::~QtRandomKeyboard() {
	if (mKeyboard != nullptr) {
		if (mKeyboard->isVisible()) {
			mKeyboard->hide();
		}
		delete mKeyboard;
	}
}

void QtRandomKeyboard::on_pbLandscape_clicked() {
	if (mKeyboard->isHidden()) {
		mKeyboard->setGeometry(0, 0, 1024, 600);
		uint8_t	mKBDbuffer[RANDOMKEYBOARD_KEYBOARD_DIGIT_COUNT * 2] = {2, 9, 0, 4, 3, 6, 7, 1, 5, 8};
		mKBDsize = sizeof(mKBDbuffer);
		mKeyboard->keyboard_init(mKBDbuffer, mKBDsize, mKeysPressed, &mKeysPressedSize);
		mKeyboard->setLandscape();
	}
}

void QtRandomKeyboard::on_pbPortrait_clicked() {
	if (mKeyboard->isHidden()) {
		mKeyboard->setGeometry(0, 0, 1024, 600);
		uint8_t	mKBDbuffer[RANDOMKEYBOARD_KEYBOARD_DIGIT_COUNT * 2] = {2, 9, 0, 4, 3, 6, 7, 1, 5, 8};
		mKBDsize = sizeof(mKBDbuffer);
		mKeyboard->keyboard_init(mKBDbuffer, mKBDsize, mKeysPressed, &mKeysPressedSize);
		mKeyboard->setPortrait();
	}
}
