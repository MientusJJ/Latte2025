CC = g++
CCFLAGS = -g -W -Wall -std=gnu++20
CCLIBS = -lstdc++fs


FLEX = flex
FLEX_OPTS = -PLatte

BISON = bison
BISON_OPTS = -t -pLatte

OBJS = Absyn.o Lexer.o Parser.o FileSaver.o InformationSaver.o FunctionsAndClasses.o Analyser.o ControlFlow.o ControlOffset.o AnalyserSem.o CreateOutput.o ClearCode.o


.PHONY: clean distclean

all: latc_x86

clean:
	rm -f latc_x86
	cd src/
	rm -f *.o TestLatte Latte.aux Latte.log Latte.pdf Latte.dvi Latte.ps Latte
	cd ..


distclean: clean
	rm -f Makefile
	cd src/
	rm -f Absyn.cpp Absyn.h  Parser.cpp Parser.h Lexer.cpp Analyser.cpp Analyser.h Makefile Latte.l Latte.y

latc_x86: ${OBJS} latc_x86.o
	@echo "Linking latc..."
	${CC} ${CCFLAGS} ${OBJS} latc_x86.o -o latc_x86


Absyn.o: src/Absyn.cpp src/Absyn.h
	${CC} ${CCFLAGS} -c -Wno-unused-parameter src/Absyn.cpp

Lexer.cpp: src/Latte.l
	${FLEX} -o -Wno-unused-parameter src/Lexer.C  src/Latte.l

Parser.cpp: src/Latte.y
	${BISON} src/Latte.y -o -Wno-unused-parameter src/Parser.cpp

Lexer.o: src/Lexer.cpp src/Parser.h
	${CC} ${CCFLAGS} -c  -Wno-unused-parameter src/Lexer.cpp

Parser.o: src/Parser.cpp src/Absyn.h
	${CC} ${CCFLAGS} -c -Wno-unused-parameter src/Parser.cpp



latc_x86.o:  src/Parser.h  src/Absyn.h
	${CC} ${CCFLAGS} -c -Wno-unused-parameter src/latc_x86.cpp

FileSaver.o: src/FileSaver.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/FileSaver.cpp

InformationSaver.o: src/InformationSaver.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/InformationSaver.cpp
FunctionsAndClasses.o: src/FunctionsAndClasses.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/FunctionsAndClasses.cpp
Analyser.o: src/Analyser.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/Analyser.cpp
ControlFlow.o: src/ControlFlow.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/ControlFlow.cpp
AnalyserSem.o: src/AnalyserSem.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/AnalyserSem.cpp

ControlOffset.o: src/ControlOffset.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/ControlOffset.cpp

CreateOutput.o: src/CreateOutput.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/CreateOutput.cpp

ClearCode.o: src/ClearCode.cpp
	${CC} ${CCFLAGS}  -c -Wno-unused-parameter src/ClearCode.cpp