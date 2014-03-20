#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

int enterA( int *A, int);
void Repair( int *A, int, int);
void Build ( int *A, int);
void Sort( int *A, int);
int OutFront( int *A, int);
int OutBack( int *A, int);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *A;
    cout << "Enter array from "<<n<<" numbers: \n";
    A=new int [n];
    enterA( A, n);
    cout << endl;
    Sort( A, n);

    OutFront( A, n);
    cout << endl << endl;
    OutBack( A, n);

    system ( "pause");
    return 0;
}

int enterA( int *A, int n)
{
    for( int i = 0; i < n; i++)
    {
        cout << "A[" << i+1 << "]: ";
        cin >> A[i];
    }
    return *A;
}


void Repair(int *A, int i, int n)
{
    int help;
    int l = 2*i+1;
    int r = 2*i+2;
    int larg = i;

    if( l <= n && A[l] > A[i])
    {
        larg = l;
    }
    if( r <= n && A[i] > A[l] && A[i] < A[r])
    {
        larg = r;
    }

    if( larg != i)
    {
        help = A[larg];
        A[larg] = A[i];
        A[i] = help;
        Repair ( A, larg, n);
    }

}

void Build (int *A, int n)
{
    for( int i = n/2; i >= 0; --i)
    {
        Repair( A, i, n);
    }
}

void Sort( int *A, int n)
{
    for( int i = n-1; i >= 1; --i)
    {
        Build( A, n);
        int l = 2*i+1;
        int r = 2*i+2;
        int larg = i;
        if(l <= n && A[l] > A[i])
        {
            larg = l;
        }
        if(r <= n && A[larg] > A[l])
        {
            larg = r;
        }
        int help = A[larg];
        A[larg] = A[i];
        A[i] = help;
        --n;
        Repair( A, larg, n);
    }
}

int OutFront( int *A, int n)
 {
        for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    return *A;
 }

 int OutBack( int *A, int n)
    {
        for (int i = n-1; i >= 0; --i)
    {
        cout << A[i] << "  ";
    }
    return *A;
    }
