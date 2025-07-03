#include "Module.h"
#include <iostream>

using namespace std;

//Module::Module(const char* name, short tasks, int units, long size)
//{
//	moduleName = name;
//	tasksCount = tasks;
//	unitsCount = units;
//	moduleSize = size;
//}

void Module::initModule(const char* name, short tasks, int units, long size) // Функция инициализации
{
    moduleName = name;
    tasksCount = tasks;
    unitsCount = units;
    moduleSize = size;
}

//Module::Module(const char* name, short tasks)
//{
//	moduleName = name;
//	tasksCount = tasks;
//}

//Module::Module(const char* name)
//{
//	moduleName = name;
//}
