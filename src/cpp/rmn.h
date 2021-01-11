//C includes
#include <stdio.h>
#include <sys/stat.h>

//C++ includes
#include <filesystem>

//Array of error codes
static char * err_code[] = {
	//No error
	"OK",
	//File was not located
	"FILE_NOT_FOUND",
	//File is directory and operation is not recursive 
	"FILE_IS_DIR",
	//File cannot be opened (often an issue with permissions)
	"FILE_CANNOT_OPEN"
};

//C++ namespace declarations
namespace fs = std::filesystem;
