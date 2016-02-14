#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace {

using ::testing::Return;

class World {
public:
    virtual ~World() = default;
    virtual int GetRadius() const = 0;
};

class WorldMock : public World {
public:
    MOCK_CONST_METHOD0(GetRadius, int());
};

}  // namespace

TEST(WorldTest, MockWorks) {
    WorldMock world;
    ON_CALL(world, GetRadius()).WillByDefault(Return(42));
    EXPECT_CALL(world, GetRadius()).Times(2);
    EXPECT_EQ(42, world.GetRadius());
    EXPECT_EQ(42, world.GetRadius());
}
