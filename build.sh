#! /bin/bash
if [ -e Makefile ]
then
	make distclean -s && \
	rm -fR GeneratedFiles release debug *.qm
fi
QT_OTIMIZA="linux-g++"
MAQUINA=`uname -m`
if [ "$MAQUINA" = "x86_64" ]
then
	QT_OTIMIZA="linux-g++-64"
else
	QT_OTIMIZA="linux-g++"
fi
echo -e - - -Compilando o programa '\033[1;33m'QtRandomKeyboard'\033[0m', um teclado para entrada de senha em orientações diferentes, para a plataforma '\033[1;33m'$MAQUINA'\033[0m' ...

lrelease -qt=qt5 QtRandomKeyboard.pro 2> /dev/null

cat Doxyfile.linux | sed s/"PROJECT_NUMBER[\ ]*= "/"PROJECT_NUMBER         = "`qmake -qt=qt5 -r -spec $QT_OTIMIZA "CONFIG-=debug_and_release release debug" "CONFIG+=release" 2>&1 | grep "Project MESSAGE:" | cut -d\  -f5`/ > Doxyfile && /usr/bin/make qmake_all

make $MAKEOPTS -s && \
strip -s release/QtRandomKeyboard

rm -fR GeneratedFiles debug *.qm .qmake.stash
if [ -e /usr/bin/doxygen ]
then
	echo -e '\033[1;35m'Rodando doxygen em segundo plano.'\033[0m'
	{ \
	doxygen Doxyfile 2> /dev/null 1> /dev/null ; \
	if [ -d latex ] ; then \
		cd latex ; \
		make -s 2> /dev/null 1> /dev/null ; \
		mv refman.pdf .. ; \
		cd .. ; \
		rm -fR latex ; \
	fi ; \
	rm -f Doxyfile ; \
	echo -e '\033[1;35m'doxygen finalizado.\\n\\n'\033[0m'
	} &
fi
if [ -e /usr/bin/cloc ]
then
	cloc *.cpp *.h
fi
echo -e - - -Finalizada a compilação do programa '\033[1;33m'QtRandomKeyboard'\033[0m', um teclado para entrada de senha em orientações diferentes, para a plataforma '\033[1;33m'$MAQUINA'\033[0m' ...
