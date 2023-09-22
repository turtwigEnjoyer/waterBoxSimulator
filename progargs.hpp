#pragma once

namespace pargs{
	void checkParams(int argc, char** argv);
	void readInputFile();
}

enum helpers {
	NOT_AN_INTEGER = -1,
	INVALID_NUMBER_ARGS = -2,
	IN_FILE_UNREACHABLE = -3,
	OUT_FILE_UNREACHABLE = -4,
	INVALID_NUMBER_PARTICLES = -5
};

