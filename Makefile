
FORTH_SRC = Forth64S/promram.4 \
 ForthSrc/src_PRIMITIVES.4 \
 ForthSrc/src_HPROC.4 \
 ForthSrc/src_VARS.4 \
 ForthSrc/macroopt.4 \
 ForthSrc/NUMB_PARSE_IO.4 \
 ForthSrc/LITERAL.4 \
 ForthSrc/src_FIND_INTERP.4 \
 ForthSrc/TERM/INCLUDE.4 \
 ForthSrc/fstart.4 \
 Meta_x86_64/SRC/gasm64.4th \
 Meta_x86_64/SRC/disfasm.4 \
 Meta_x86_64/SRC/tc.f \
 ForthSrc/global.4 \
 Meta_x86_64/SRC/mlist.f \
 Meta_x86_64/SRC/lex.4th \
 Meta_x86_64/mhead0.f \
 Meta_x86_64/SRC/macroopt.4 

all:	forth64.exe

FORTH_INC: $(FORTH_SRC)
	chmod +x ./Forth64S/FComp.sh 
	./Forth64S/FComp.sh

forth64.exe: forth64.fasm FORTH_INC 
	chmod +x ./build.sh 
	./build.sh


clean:
	rm -f forth64.exe Forth64S/src/*.INC
	
