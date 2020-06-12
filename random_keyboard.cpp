#include "random_keyboard.h"
#include <QPainter>

random_keyboard::random_keyboard(QWidget *parent) :  QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog | Qt::Tool  /* | Qt::SplashScreen */ ) {
	setupUi(this);
	lePwd->setEchoMode(QLineEdit::Password);
}

random_keyboard::~random_keyboard() {

}

void random_keyboard::changeEvent(QEvent *e) {
	QWidget::changeEvent(e);
	switch (e->type()) {
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

void random_keyboard::keyboard_init(uint8_t *pucBuffer, uint8_t size, uint8_t *keysPressed, uint8_t *pwdSize) {
	mPassword = keysPressed;
	mPasswdLength = pwdSize;
	QStringList spb;
	qint8 numb1, numb2;
	for (int i = 0; i < size; i+=2) {
		numb1=pucBuffer[i];
		numb2=pucBuffer[i+1];
		if (numb1 < numb2) {
			spb.append(QString("%1 - %2").arg(numb1).arg(numb2));
		} else {
			spb.append(QString("%1 - %2").arg(numb2).arg(numb1));
		}
	}
	pb1->setText(spb.at(0));
	pb2->setText(spb.at(1));
	pb3->setText(spb.at(2));
	pb4->setText(spb.at(3));
	pb5->setText(spb.at(4));
}

void random_keyboard::on_pb1_clicked() {
	mPassword[*mPasswdLength] = 1;
	lePwd->setText(QString(lePwd->text()).append("1"));
	(*mPasswdLength)++;
}

void random_keyboard::on_pb2_clicked() {
	mPassword[*mPasswdLength] = 2;
	lePwd->setText(QString(lePwd->text()).append("2"));
	(*mPasswdLength)++;
}

void random_keyboard::on_pb3_clicked() {
	mPassword[*mPasswdLength] = 3;
	lePwd->setText(QString(lePwd->text()).append("3"));
	(*mPasswdLength)++;
}

void random_keyboard::on_pb4_clicked() {
	mPassword[*mPasswdLength] = 4;
	lePwd->setText(QString(lePwd->text()).append("4"));
	(*mPasswdLength)++;
}

void random_keyboard::on_pb5_clicked() {
	mPassword[*mPasswdLength] = 5;
	lePwd->setText(QString(lePwd->text()).append("5"));
	(*mPasswdLength)++;
}

void random_keyboard::on_pbView_toggled(bool state) {
	if (state) {
		lePwd->setEchoMode(QLineEdit::Normal);
	} else {
		lePwd->setEchoMode(QLineEdit::Password);
	}
}

void random_keyboard::on_pbEnter_clicked() {
	qApp->setOverrideCursor(Qt::ArrowCursor);
	emit signalHide();
}
