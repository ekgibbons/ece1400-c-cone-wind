#include "tests/utest.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

UTEST(conegeometry, usage)
{
    int ret = system("./conegeometry > tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tests/conegeometry_1.correct tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sub");
    (void)ret;
    
}

UTEST(conegeometry, area)
{
    time_t t;
    srand((unsigned int)time(&t));

    /* generate random numbers from 3 to 7 */
    double height = ((double)rand()/(double)(RAND_MAX)) * 7 + 3;
    double base = ((double)rand()/(double)(RAND_MAX)) * 7 + 3; 

    char command_py[100];
    char command_c[100];
    
    sprintf(command_py,"python tests/conegeometry.pyc %f %f area > tmp_sol",
            height, base);
    sprintf(command_c,"./conegeometry %f %f area > tmp_sub",
            height, base);

    int ret = system(command_py);
    ASSERT_TRUE(ret==0);
    ret = system(command_c);
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp_sol tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sol tmp_sub");
    (void)ret;
}

UTEST(conegeometry, volume)
{

    /* generate random numbers from 3 to 7 */
    double height = ((double)rand()/(double)(RAND_MAX)) * 7 + 3;
    double base = ((double)rand()/(double)(RAND_MAX)) * 7 + 3; 

    char command_py[100];
    char command_c[100];
    
    sprintf(command_py,"python tests/conegeometry.pyc %f %f volume > tmp_sol",
            height, base);
    sprintf(command_c,"./conegeometry %f %f volume > tmp_sub",
            height, base);
    
    int ret = system(command_py);
    ASSERT_TRUE(ret==0);
    ret = system(command_c);
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sol tmp_sub");
    (void)ret;
}

UTEST(conegeometry, option)
{
    int ret = system("./conegeometry 5.1 2.3 volum > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/conegeometry_4.correct");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp");
    (void)ret;

}


UTEST(wind_analysis, usage)
{
    int ret = system("./windanalysis > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/windanalysis_1.correct");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp");
    (void)ret;

}

UTEST(wind_analysis, output)
{
    int ret = system("./windanalysis KOGD.txt > tmp");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp tests/windanalysis_2.correct");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp");
    (void)ret;

}


UTEST_MAIN();
