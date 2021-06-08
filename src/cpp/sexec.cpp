#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

int main(int argc, char * argv[])
{
	const char * envvar = "SEXEC_DIR";
	string comm = "$SHELL ";
	if(!getenv(envvar)){
		fprintf(stderr, "The environment variable %s is not set\n", envvar);
		return 1;
	}
	const char * script_dir = getenv(envvar);
	comm = comm + script_dir + "/";
	for(int i = 1; i < argc; i++)
	{
		comm = comm + argv[i] + " ";
	}
	system(comm.c_str());
	return 0;
}
