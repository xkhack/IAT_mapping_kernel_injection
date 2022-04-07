﻿#include "mmap.hpp"

int main(int argc, char **argv) { 
	mmap mapper(INJECTION_TYPE::KERNEL);

	if (!mapper.attach_to_process("notepad.exe"))
		return 1;

	if (!mapper.load_dll("example_dll.dll"))
		return 1;

	if (!mapper.inject())
		return 1;

	LOG("\n按任意键关闭.");
	std::getchar();
	 
	return 0;
}