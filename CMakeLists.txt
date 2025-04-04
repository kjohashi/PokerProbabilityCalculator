cmake_minimum_required(VERSION 3.27)
project(Poker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Poker main.cpp
        BaseCard.cpp
        BaseCard.h
        CardHand.cpp
        CardHand.h
        CardHandScorer.cpp
        CardHandScorer.h
        CardVariables.h
        Deck.cpp
        Deck.h
        PokerScore.cpp
        PokerScore.h
        AnimatedSpriteSheet.cpp
        AnimatedSpriteSheet.h
        SFMLCard.cpp
        SFMLCard.h
        SFMLBackground.cpp
        SFMLBackground.h
        SFMLRank.cpp
        SFMLRank.h
        SFMLSuit.cpp
        SFMLSuit.h
        SFMLSuit.cpp)
target_link_libraries(Poker sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
