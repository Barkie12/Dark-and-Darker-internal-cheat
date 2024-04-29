#include "Protect.h"
#include <fstream>
#include <signal.h>
#include <thread>
int funcCount = 0;
ProtectedFunction functions[50];

void unsafe_unprotect(int index) {
	//((BYTE*)functions[index].address, functions[index].size, functions[index].last);
}

void nextLast(int index) {
	BYTE Byte = functions[index].last;
	if (Byte > 0xf3) {
		Byte = 0x5;
	}
	Byte += 0x01;
	functions[index].last = Byte;
}

void unsafe_protect(int index) {
	nextLast(index);
	unsafe_unprotect(index);
}

int GetFunctionIndex(void* FunctionAddress) {
	for (int i = 0; i < funcCount; i++) {
		if ((uintptr_t)functions[i].address <= (uintptr_t)FunctionAddress &&
			(uintptr_t)functions[i].address + functions[i].size >= (uintptr_t)FunctionAddress) {
			return i;
		}
	}
	return -1;
}

void Unprotect(void* FunctionAddress) {
	int function = GetFunctionIndex(FunctionAddress);

	if (function > -1 && functions[function].crypted == true) {
		unsafe_unprotect(function);
		functions[function].crypted = false;
	}
}

void Protect(void* FunctionAddress) {
	int function = GetFunctionIndex(FunctionAddress);
	if (function > -1 && functions[function].crypted == false) {
		unsafe_protect(function);
		functions[function].crypted = true;
	}
}

void ProtectedSleep(int ms) {
	Protect(_ReturnAddress());
	Sleep(ms);
	Unprotect(_ReturnAddress());
}

void addFunc(ProtectedFunction func) {
	functions[funcCount] = func;
	funcCount++;
}

void XOR(BYTE* data, size_t size, BYTE _KEY) {
	for (size_t i = 0; i < size; i++) {
		data[i] = data[i] ^ _KEY;
	}
}