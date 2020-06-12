#include "random_keyboard_display.h"

random_keyboard_display::random_keyboard_display(QWidget *parent) : QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog | Qt::Tool  /* | Qt::SplashScreen */ ) {
	setupUi(this);
	gs = new QGraphicsScene(this);
	gv->setScene(gs);
	// gv->setBackgroundBrush(QBrush(Qt::black));
	gv->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
	gv->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	gv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	gv->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// gv->setAlignment(Qt::AlignCenter);
	// gv->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
	qwKeyboard = new random_keyboard(this);
	mProxyWidget = gs->addWidget(qwKeyboard);
	connect(qwKeyboard, &random_keyboard::signalHide, this, &random_keyboard_display::slotHide);

	hide();
}

random_keyboard_display::~random_keyboard_display() {
	disconnect(qwKeyboard, &random_keyboard::signalHide, this, &random_keyboard_display::slotHide);
	gs->removeItem(mProxyWidget);
	delete mProxyWidget;
	gs->clear();
}

void random_keyboard_display::slotHide() {
	hide();
}

void random_keyboard_display::keyboard_init(uint8_t *pucBuffer, uint8_t size, uint8_t *keysPressed, uint8_t *pwdSize) {
	qwKeyboard->keyboard_init(pucBuffer, size, keysPressed, pwdSize);
}

void random_keyboard_display::changeEvent(QEvent *e) {
	QWidget::changeEvent(e);
	switch (e->type()) {
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

bool random_keyboard_display::event(QEvent *evento) {
	if (evento->type() == QEvent::Resize) {
		mudouTamanho();
	}
	return QWidget::event(evento);
}

void random_keyboard_display::mudouTamanho() {
	// gv->setGeometry(0, 0, size().width(), size().height());
	gs->setSceneRect(0, 0, size().width(), size().height());
	gv->ensureVisible(QRectF(0, 0, size().width(), size().height()));
	qwKeyboard->setGeometry(0, 0, size().width(), size().height());
	mProxyWidget->setGeometry(QRectF(0, 0, size().width(), size().height()));
}

void random_keyboard_display::setPortrait(void) {
	mProxyWidget->resetTransform();
	qwKeyboard->setGeometry(0,0,size().height(),size().width());
	mProxyWidget->setPos(0, size().height());
	mProxyWidget->setRotation(-90);
	// gv->setViewport(qwKeyboard);
	qApp->setOverrideCursor(Qt::CrossCursor);
	show();
}

void random_keyboard_display::setLandscape(void) {
	mProxyWidget->resetTransform();
	qwKeyboard->setGeometry(0, 0, size().width(), size().height());
	mProxyWidget->setPos(0, 0);
	mProxyWidget->setRotation(00);
	// gv->setViewport(qwKeyboard);
	qApp->setOverrideCursor(Qt::CrossCursor);
	show();
}
