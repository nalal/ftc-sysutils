main: prep tcount fcount lsdir lsp yt-audio
	@echo  [Compiling complete.]

yt-audio:
	@echo [Building YT-Audio]
	@echo =Default output folder is '~/music', can be set in source
	g++ yt-audio.cpp -o bin/yt-audio

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
	@echo [Building LSP] 
	g++ droller.cpp -lpthread -o bin/droller

prep:
	@echo [Preparing build folders]
	mkdir -p bin

clean:
	@echo [Cleaning build folders]
	rm -rf bin
	
install:
	@echo [Installing utilities]
	mkdir -p ~/lbin
	cp bin/* ~/lbin
	@echo [Utilities installed to \~/lbin]
