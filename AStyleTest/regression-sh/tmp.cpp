#include "stdafx.h"
#include <emmintrin.h>
#include <iostream>

// a badly formatted file used for CI regression tests

#ifdef TEST

#endif

using namespace std;

// Function declaration
int add(int a, int b);

// Class definition
class MyClass {
public:
    MyClass   (int         value) : myValue         (value       ) {}
    void        display() {
        cout << "MyValue: "       << myValue      << endl;
    }
private:
    int        myValue;
};

int main() {
    // Variables and data types
int a, b, c, x, someVal, someVal2, someVal3, someVal4 = 5;
double y, foo, bar = 3.14;
char ch = 'A';
bool isTrue = true;

	struct {             // Structure declaration
  int myNum;         // Member (int variable)
  string myString;   // Member (string variable)
} myStructure;       // Structure variable

    // Arithmetic operations
    int result = x + 2 * (int)y;
    cout << "Result: " << result << endl;

    // Conditional statement
    if (x > 0) {
        cout << "x is positive" << endl;
    } else {
        cout << "x is non-positive" << endl;
    }

    // Loop
for (int i = 0; i < 5; i++) {
cout << "Iteration " << i + 1 << endl;
}

    // Function call
    int sum = add(3, 4);
    cout << "Sum: " << sum << endl;

    // Object creation and method call
    MyClass obj(42);
    obj.display();

	goto label;

label:

    MyClass.setA1234( 1 )
         .setB12dsadasdasdsa( 2 )
.setB12dsadasdasdsa()
.setB12dsadasdasdsa( 2 )
         .setB12dsadasdasdsa( 2 )
         .setC12dsdsds( 3 );

   if (a=b=c) {
        func(a==b==c);
        someVal = someVal2 =
        someVal3 = someVal4 = 0;

if (x) {
someVal = someVal2 =
someVal3 = someVal4 = 0;
}
    }

					int x2;

    do
	    {
x2 = 1;
    } while (func(foo,
    bar));

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}


// Pointer alignment

if (anotherMethod((uint8_t *)param1, (uint8_t *)param2)) {
        int x = 1 * 2;
        return;
    }

    int fdfd(int* t) {
    return 1;
}

if (*f(xss) < mx) {
    return 1;
}

if (**f(xss) < mx) {
    return 1;
}
if (t * f(xss) < mx) {
    return 1;
}


int* p = (int*)& _mem;

void foo(int a, int c)
{
    int* p = (int*)& _mem;
}

void win_ui_flush (bool validate)
{
    FOR_ALL_TAB_WINDOWS (tp, wp) {
        if (wp->w_pos_changed && wp->w_grid_alloc.chars != NULL) {
            if (tp == curtab) {
                ui_ext_win_position (wp, validate);
            } else {
                ui_call_win_hide (wp->w_grid_alloc.handle);
                wp->w_pos_changed = false;
            }
        }

        if (tp == curtab) {
            ui_ext_win_viewport (wp);
        }
    }
}

win_T* lastwin_nofloating (void)
{
    win_T* res = lastwin;

    while (res->w_floating) {
        res = res->w_prev;
    }

    return res;
}



CPPageFileMediaInfo::CPPageFileMediaInfo(CString path, IFileSourceFilter *pFSF)
    : CPropertyPage(CPPageFileMediaInfo::IDD, CPPageFileMediaInfo::IDD)
    , m_fn(path)
    , m_path(path)
{   m_futureMIText = std::async(std::launch::async, [ = ]()
    {
#if USE_STATIC_MEDIAINFO
        MediaInfoLib::String filename = m_path;
        MediaInfoLib::MediaInfo MI;
#else
        MediaInfoDLL::String filename = m_path;
        MediaInfo MI;
#endif

        return MI.Inform().c_str();
    }).share();
}




Test::Test() : member1(argument)
    , member2([this] {
                  some_code(argument);
              })
    , member3(42)
    , member4("test")
{
}


struct xxxx {
    int a, b, c;
};

(struct xxxxx *p);

int main(int * p, int *q)
{
    return;
}

int main(void)
{

    switch (foo) {
    case 1:
        a += 1;
        break;
    case 2: {
        a += 2;
        break;
    }
    }

    struct xxxx *p;
    printf("sizeof p: %d\n", sizeof p);

    int * p, *q;

    return 0;
}



mapping someData = ([
    "key": "value",
]);

void fn() {
    some_fn(([
        "key1": "/path/to/file1.c",
        "key2": "/path/to/file2.c",
    ]));
}


int main() {
    while (true) {
        new int *[5]; // Remove this and everything works fine
        if (5 > 2) {
            abc();

            for (int i = 0; i < 6; i++) {
                def();
            }
        } else {
            xyz();

            for (int i = 0; i < 8; i++) {
                xyz();
            }
        }
    }
    return 0;
}

struct s {
    public:
        inline s() :
            size(x),
            ia {new int [y]},
            ia {new int [y]}
        {}
}



#define MY_BITFIELD_WIDTH

typedef struct {
    uint32_t member_1 :    MY_BITFIELD_WIDTH;
    uint32_t member_1 : MY_BITFIELD_WIDTH;
    uint32_t member_2 : MY_BITFIELD_WIDTH;
    bool (*func) (void);
}

struct {
    uint32_t member_1 :    MY_BITFIELD_WIDTH;
    uint32_t member_1 : MY_BITFIELD_WIDTH;
    uint32_t member_2 : MY_BITFIELD_WIDTH;
    bool (*func) (void);
}


typedef struct {
    uint32_t member_1 : 8;
    uint32_t member_1 : 2;
    uint32_t member_2 : 3;
    bool (*func) (void);
}