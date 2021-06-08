main: prep tcount fcount lsdir lsp yt-audio droller rname strgen namefix rmn sexec
	@echo  [Compiling complete.]

yt-audio:
	@echo [Building YT-Audio]
	@echo =Default output folder is '~/music', can be set in source
	g++ --static yt-audio.cpp -o bin/yt-audio

strgen:
	@echo [Building STRGEN]
	g++ -march=znver2 -mtune=znver2 -lpthread strgen.cpp -o bin/strgen

tcount:
	@echo [Building TCOUNT]
	g++ tcount.cpp -o bin/tcount

fcount:
	@echo [Building FCOUNT]
	g++ fcount.cpp -lstdc++fs -o bin/fcount

lsdir:
	@echo [Building LSDIR]
	g++ lsdir.cpp -lstdc++fs -o bin/lsdir

lsp:
	@echo [Building LSP]
	g++ lsp.cpp -lstdc++fs -o bin/lsp

droller:
	@echo [Building DROLLER]
	g++ droller.cpp -lpthread -o bin/droller

rname:
	@echo [Building RNAME]
	g++ rname.cpp -lstdc++fs -o bin/rname

namefix:
	@echo [Building NAMEFIX]
	g++ namefix.cpp -std=gnu++17 -lpthread -o bin/namefix

rmn:
	@echo [Building RMN]
	g++ rmn.cpp -o bin/rmn -std=gnu++17

sexec:
	@echo [Building SEXEC]
	g++ sexec.cpp -o bin/sexec
	@echo =REMEMBER TO SET YOUR SEXEC_DIR VARIABLE IN YOUR RC DOTFILE

prep:
	@echo [Preparing build folders]
	mkdir -p bin

clean:
	@echo [Cleaning build folders]
	rm -rf bin

install: main
	@echo [Installing utilities]
	cp bin/* /bin
	@echo [Utilities installed to /bin]
