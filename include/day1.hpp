#define ARR_SIZE(x) sizeof(x)/sizeof(x[0])

class Day1 {
private:
    static char* file;
    static int first();
    static int second();
    static void run();

public:
    explicit Day1(const char* file_name);
    ~Day1();
};
