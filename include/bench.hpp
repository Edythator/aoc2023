namespace Bench
{
    struct Time
    {
        long first;
        long second;
    };
    struct Result
    {
        Time time;
        int first;
        int second;
    };

    Result Bench(int (*a)(), int (*b)());
}