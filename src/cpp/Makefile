main: prep tcount fcount lsdir lsp
	@echo  [Compiling complete.]

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
