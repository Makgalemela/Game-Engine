#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Pong.h"

TEST_CASE("Left paddle outline thickness is 3")
{
    auto lp = makeLeftPaddle();
    CHECK(lp.getOutlineThickness() == 3);
}

