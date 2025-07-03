#pragma once
class Module
{
public:
    void initModule(const char* name, short tasks, int units, long size);
//    void setName(const char* name);
//    void setSize(long size);
//    void displayModule();
private:
    const char* moduleName;
    short tasksCount;
    int   unitsCount;
    long  moduleSize;
};
