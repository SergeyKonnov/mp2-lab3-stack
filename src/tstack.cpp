#include "tstack.h"
#include <iostream>

using namespace std;

TStack::TStack(int Size):TDataRoot(Size)
{
    top = -1;
}

void TStack::Put(const TData &Val)
{
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsEmpty())
        SetRetCode(DataEmpty);
    else if(IsFull())
        SetRetCode(DataFull);
    else
        pMem[++top] = Val;
}

TData TStack::Get()
{
    TData tmp = -1;
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsEmpty())
        SetRetCode(DataEmpty);
    else
        TData tmp = pMem[top--];
    return tmp;
}

TData TStack::TopElem()
{
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsEmpty())
        SetRetCode(DataEmpty);
    else
        return pMem[top];
}

int TStack::IsValid()
{
    return GetRetCode();
}

void TStack::Print()
{
    for(int i = 0; i <= top; i++)
        cout<<pMem[i]<<" ";
    cout<<"\n";
}