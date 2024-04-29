#pragma once

#include <Windows.h>
#include <intrin.h>
#pragma intrinsic(_ReturnAddress)

#define SLog(text) 

struct ProtectedFunction {
	void* address;
	size_t size;
	BYTE last;
	bool crypted;
};
extern int funcCount;
extern ProtectedFunction functions[50];
void addFunc(ProtectedFunction func);
void unsafe_unprotect(int index);
void unsafe_protect(int index);
int GetFunctionIndex(void* FunctionAddress);
void Unprotect(void* FunctionAddress);
void Protect(void* FunctionAddress);
//void (BYTE* data, size_t size, BYTE _KEY = STRING__KEY);
void ProtectedSleep(int ms);