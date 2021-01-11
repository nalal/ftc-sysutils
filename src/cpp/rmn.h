//C includes
#include <stdio.h>
#include <sys/stat.h>

//C++ includes
#include <filesystem>

static char * err_code[] = {
	"OK",
	"FILE_NOT_FOUND",
	"FILE_IS_DIR",
	"FILE_CANNOT_OPEN"
};

//C++ namespace declarations
namespace fs = std::filesystem;
