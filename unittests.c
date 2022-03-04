#include "tests/utest.h"

UTEST(conegeometry, usage)
{
    int ret = system("./conegeometry > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/conegeometry_1.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}

UTEST(conegeometry, area)
{
    int ret = system("./conegeometry 3.2 1.1 area > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/conegeometry_2.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}

UTEST(conegeometry, volume)
{
    int ret = system("./conegeometry 5.1 2.3 volume > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/conegeometry_3.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}

UTEST(conegeometry, option)
{
    int ret = system("./conegeometry 5.1 2.3 volum > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/conegeometry_4.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}


UTEST(wind_analysis, usage)
{
    int ret = system("./windanalysis > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/windanalysis_1.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}

UTEST(wind_analysis, output)
{
    int ret = system("./windanalysis KOGD.txt > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/windanalysis_2.out");
    system("rm tmp");
    ASSERT_TRUE(ret==0);
}


UTEST_MAIN();
