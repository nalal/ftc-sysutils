main: prep tcount fcount lsdir
	echo "Compiling complete."

tcount:
	g++ tcount.cpp -o bin/tcount

fcount:
	g++ fcount.cpp -lstdc++fs -o bin/fcount

lsdir:
	g++ lsdir.cpp -lstdc++fs -o bin/lsdir

prep:
	mkdir -p bin

clean:
	rm -rf bin
