#include "../List.h"
#include "gtest/gtest.h"
#include <memory>
#include <string>

class ListTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }

protected:
    List<int> list;

};
// test add stream function for hdf5 file format with wrong file path
TEST_F( ListTest, testInit )
{
    std::vector<int> temp({1,2,3,4,5});
    List<int> list2({1,2,3,4,5});
    int i = 0;
    for( auto& it: list2 )
    {
        EXPECT_EQ( it,temp[i++]);
    }

}




int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}